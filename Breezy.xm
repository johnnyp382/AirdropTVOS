#import "FindProcess.h"
#import <UIKit/UIKit.h>
#import <objc/runtime.h>
#import "FBSystemServiceOpenApplicationRequest.h"
#import "breezy.h"
#import "CTBlockDescription.h"
#include <CoreFoundation/CoreFoundation.h>

@class BindingEvaluator, LSContext, LSBundleData;

//start actual code
%group Sharingd
%hook SharingDaemon

- (_Bool)canAccessAirDropSettings:(id)arg1 {
    
    %log;
    //description of item looks like this <OS_xpc_connection: <connection: 0x133dc3790> { name = com.apple.sharingd.peer.0x133dc3790, listener = false, pid = 3731, euid = 501, egid = 501, asid = 0 }>
    //find the related pid by trimming it out of the description
    int pid = [FindProcess pidFromItemDescription:[arg1 description]];
    HBLogDebug(@"PID %i", pid);
    //exempting TVSettings from AirDrop entitlement checks so we can toggle it on and off there easier.
    boolean_t matches = [FindProcess process:pid matches:"TVSettings"];
    if (matches){
        return true;
    }
    //return true;
    return %orig;
}

%end

%hook SFAirDropTransfer

//all of this code is thoroughly documented in the README if you are having trouble understanding it.

-(void)updateWithInformation:(id)arg {
    %log;
    NSProgress *prog = [self transferProgress];
    //HBLogDebug(@"progress: %@", prog);
    NSArray <NSURL *> *items = arg[@"Items"];
    if (items.count > 0 && [prog isFinished]){
        HBLogDebug(@"info: %@", arg);
        NSMutableArray *paths = [NSMutableArray new];
        NSMutableArray *URLS = [NSMutableArray new];
        [items enumerateObjectsUsingBlock:^(NSURL * _Nonnull obj, NSUInteger idx, BOOL * _Nonnull stop) {
            if ([obj respondsToSelector:(@selector(isFileURL))]){
                if ([obj isFileURL]){
                    [paths addObject:[obj path]];
                } else {
                    HBLogDebug(@"obj isnt a file path: %@", obj);
                    [URLS addObject:[obj absoluteString]];
                }
            } else {
                HBLogDebug(@"doesnt respond to isFileURL: %@", obj);
                [paths addObject:[obj path]];
            }
        }];
        if (paths.count > 0 || URLS.count > 0){
            
            NSMutableDictionary *sent = [NSMutableDictionary new];
            sent[@"Files"] = arg[@"Files"];
            sent[@"LocalFiles"] = paths;
            sent[@"URLS"] = URLS;
            sent[@"SenderCompositeName"] = arg[@"SenderCompositeName"];
            sent[@"SenderComputerName"] = arg[@"SenderComputerName"];
            HBLogDebug(@"Breezy: sending user info: %@", sent);
            [[NSDistributedNotificationCenter defaultCenter] postNotificationName:@"com.breezy.kludgeh4x" object:nil userInfo:sent];
        }
    }
    %orig;
}
%end

%hook SDAirDropTransferManager

- (id)determineHandlerForTransfer:(id)transfer { 
    %log;
    id  r = %orig;
    //  if (!r){
    //For now, force all transfers to be acceptable.
    id meta = [transfer metaData];
    [meta setValue:[NSNumber numberWithBool:TRUE] forKey:@"_verifiableIdentity"];
    [meta setValue:[NSNumber numberWithBool:TRUE] forKey:@"_canAutoAccept"];
    id genericHandler = [[%c(SDAirDropHandlerGenericFiles) alloc] initWithTransfer:transfer bundleIdentifier:@"com.nito.nitoTV4"];
    [genericHandler activate];
    return genericHandler;
    //} else {
    //  HBLogDebug(@"Breezy: %@ created for transfer: %@", r, transfer);
    //}
    return r;
}
%end

%end //Sharingd Group

%group PineBoard

%hook PBAppDelegate

%new - (void)showSystemAlertFromAlert:(id)alert {
    %log;
    BOOL thirteenPlus = (kCFCoreFoundationVersionNumber > 1585.17); //12.4 is 1575.17, not sure what 12.4.1 is but this should be safe enough bump up
    __block id dialogManager; //13+ only
    if (thirteenPlus){
        dialogManager = [%c(PBDialogManager) sharedInstance]; //get this out of the way
    }
    NSLog(@"[Breezy] CFVersion %.2f\n", kCFCoreFoundationVersionNumber);
    NSLog(@"[Breezy] showSystemAlertFromAlert: %@", alert);
    id windowManager = [%c(PBWindowManager) sharedInstance];
    LSApplicationWorkspace *ws = [LSApplicationWorkspace defaultWorkspace];
    __block id context; //13+ only
    NSDictionary *userInfo = [alert userInfo];
    NSArray <NSDictionary *> *files = userInfo[@"Files"];
    NSArray <NSString *> *localFiles = userInfo[@"LocalFiles"];
    NSArray <NSString *> *URLS = userInfo[@"URLS"];
    __block NSMutableString *names = [NSMutableString new];
    __block id doxy = nil;
    //TODO: this could smarter, its possible the files selected dont all work in one app, need to accomodate that
    __block BOOL hasIPA = FALSE; //kinda of a hacky check to make sure IPA's go through ReProvision if its avail.
    [files enumerateObjectsUsingBlock:^(NSDictionary  * adFile, NSUInteger idx, BOOL * _Nonnull stop) {
        NSString *fileName = adFile[@"FileName"];
        NSString *fileType = adFile[@"FileType"];
        if ([[[fileType pathExtension] lowercaseString] isEqualToString:@"ipa"] || [[[fileName pathExtension] lowercaseString] isEqualToString:@"ipa"]){
            hasIPA = TRUE;
        }
        //h4x, we are only creating doxy if it doesnt already exist, so that means we are only taking into account the file type of the first file in the list.
        if (!doxy) {
            doxy = [LSDocumentProxy documentProxyForName:fileName type:fileType MIMEType:nil];
        }
        [names appendFormat:@"%@, ", fileName];
    }];
   
    NSString *appList = names;
    if (names.length > 400){
        appList = [NSString stringWithFormat:@"%@...", [names substringToIndex:400]];
    }
    NSArray  *applications = [ws applicationsAvailableForOpeningDocument:doxy];
    //NSPredicate *pred = [NSPredicate predicateWithFormat:@"bundleIdentifier != 'com.nito.nitoTV4'"];
    //applications = [applications filteredArrayUsingPredicate: pred];
    if (URLS.count > 0){ //we take a different path here
        NSString *firstURL = URLS[0];
        [names appendString:firstURL];
        NSString *scheme = [[NSURL URLWithString:firstURL] scheme];
        NSLog(@"[Breezy] scheme: %@", scheme);
        applications = [ws applicationsAvailableForHandlingURLScheme:[[NSURL URLWithString:firstURL] scheme]];
        //PBLinkHandler is useless and we dont want to list it as an option.
        NSPredicate *pred = [NSPredicate predicateWithFormat:@"bundleIdentifier != 'com.apple.PBLinkHandler'"];
        applications = [applications filteredArrayUsingPredicate: pred];
    }

    //create the alert, we may not end up using it if theres only one application
    id applicationAlert = [[%c(PBUserNotificationViewControllerAlert) alloc] initWithTitle:@"AirDrop" text:[NSString stringWithFormat:@"Open '%@' with...", appList]];
    NSLog(@"[Breezy] available applications: %@", applications);
    NSString *cancelButtonTitle = @"Cancel";
    /*
     Temporary VLC hack, & will require Ethereal to work.
     
     This temporary implementation is a precursor to the future plan of how this will be implemented.
     
     There will be a preference file maintained (or it will be added to the current one)
     that will have a series of keys corresponding to target apps and the app they want to use
     as a template.
     
     org.videolan.vlc-ios {
        "mimic": "com.nito.Ethereal";
     }

     This will mean any time we find ethereal as a potential target application, we will also add the
     target ID app as an option to use to open the file as well.
     
     This will only be part of the equation, you will still need to write your own tweak similar to 'vlcscience' or 'provscience' examples included as part of this project. that will
     handle the rest of the process (opening the URL and moving it to where it needs to be)
     
     */
    
    //create predicate to see if ethereal is included in our 'applications' query
    NSPredicate *hasEthPred = [NSPredicate predicateWithFormat:@"bundleIdentifier == 'com.nito.Ethereal'"];
    if ([applications filteredArrayUsingPredicate: hasEthPred].count > 0){ //see if our results are found
        id vlcCheck = [LSApplicationProxy applicationProxyForIdentifier:@"org.videolan.vlc-ios"];
        if (vlcCheck != nil){
            //found VLC, so at this point we have VLC AND ethereal installed
            NSMutableArray *_tempApps = [applications mutableCopy]; //mutable copy of apps
            [_tempApps addObject:vlcCheck]; //add VLC
            applications = _tempApps; //update apps.
        }
    }
    
    //this is to work around old bug that may or may not still be present for ReProvision not registering
    //for IPA support properly.
    
    if (applications.count == 0){
        if (hasIPA){
            NSLog(@"[Breezy] no applications and its an IPA file, check for ReProvision!");
            id reproCheck = [LSApplicationProxy applicationProxyForIdentifier:@"com.matchstic.reprovision.tvos"];
            if (reproCheck){
                NSLog(@"[Breezy] found ReProvision: %@", reproCheck );
                applications = @[reproCheck];
            }
        }
    }
    if (applications.count == 1){ //Theres only one application, just open it automatically
        id launchApp = applications[0];
            if (URLS.count > 0){
                //process URLs
                [self openItems:URLS ofType:KBBreezyFileTypeLink withApplication:launchApp];
            } else {
                //process files
                [self openItems:localFiles ofType:KBBreezyFileTypeLocal withApplication:launchApp];
            }
        return; //returning here because we dont want to show a dialog, we are done.
    } else if (applications.count > 1){  //multiple applications available, build up the menu
        __weak typeof(applicationAlert) weakAlert = applicationAlert;
        [applications enumerateObjectsUsingBlock:^(id  _Nonnull currentApp, NSUInteger idx, BOOL * _Nonnull stop) {
            [applicationAlert addButtonWithTitle:[currentApp localizedName] type:0 handler:^{
                if (thirteenPlus) {
                    [dialogManager dismissDialogWithContext:context options:nil completion:nil];
                } else {
                    [windowManager dismissDialogViewController:weakAlert];
                }
                if (URLS.count > 0){
                    //process URLs
                    [self openItems:URLS ofType:KBBreezyFileTypeLink withApplication:currentApp];
                } else {
                    //process files
                    [self openItems:localFiles ofType:KBBreezyFileTypeLocal withApplication:currentApp];
                }
                dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0), ^{
                    //leaving this here in case any of our processing actually needs to be in here..
                });
            }];
        }];
    } else { //no applications found
        cancelButtonTitle = @"OK";
        NSLog(@"no applications found to open these file(s)");
        NSString *newMessage = [NSString stringWithFormat:@"Failed to find any applications to open '%@' with", names];
        [applicationAlert setText:newMessage];
    }
    __weak typeof(applicationAlert) weakAlert = applicationAlert;
    [applicationAlert addButtonWithTitle:cancelButtonTitle type:0 handler:^{
        if (thirteenPlus) {
            [dialogManager dismissDialogWithContext:context options:nil completion:nil];
        } else {
            [windowManager dismissDialogViewController:weakAlert];
        }
    }];
    
    //done all our processing, time to show the alert!
    dispatch_async(dispatch_get_main_queue(), ^{
        if (thirteenPlus){
            context = [%c(PBDialogContext) contextWithViewController:applicationAlert];
            dispatch_async(dispatch_get_main_queue(), ^{
                [dialogManager presentDialogWithContext:context options:@{@"PBDialogOptionPresentForcedKey": @1, @"PBDialogOptionPresentWhileScreenSaverActiveKey": @1} completion:nil];
            });
        } else {
            [windowManager presentDialogViewController:applicationAlert];
        }
    });
    //HBLogDebug(@"file: %@ of type: %@ can open in the following applications: %@",fileName, fileType, applications);
}

//eyesore! one of the last remaining hacky things i'd like to do better - this is the
//communication channel between sharingd and PineBoard - listen for a notification to show alert / finish process
- (_Bool)application:(id)arg1 didFinishLaunchingWithOptions:(id)arg2 {
    
    _Bool orig = %orig;
    %log;
    id notificationCenter = [NSDistributedNotificationCenter defaultCenter];
    [notificationCenter addObserver:self  selector:@selector(showSystemAlertFromAlert:) name:@"com.breezy.kludgeh4x" object:nil]; //still need to get rid of this ugly eyesore
    return orig;
    
}

//this never ended up being needed but im leaving it in as an example of how to hook a private C function
%new - (NSURL *)inboxForIdentifier:(NSString *)identifier {
    //dlopen("/System/Library/Frameworks/CoreServices.framework/CoreServices", RTLD_LAZY);
    MSImageRef cs = MSGetImageByName("/System/Library/Frameworks/CoreServices.framework/CoreServices");
    void *(*LSGetInboxURLForAppIdentifier)(id identifier);
    LSGetInboxURLForAppIdentifier = (void *(*)(id identifier)) MSFindSymbol(cs, "__LSGetInboxURLForAppIdentifier");
    NSLog(@"[Breezy] %p", LSGetInboxURLForAppIdentifier);
    if (LSGetInboxURLForAppIdentifier){
        NSURL *inbox = (__bridge NSURL *)(*LSGetInboxURLForAppIdentifier)(identifier);
        return inbox;
    }
    return nil;
}

/*
 
 Added this to make sure files are in a folder they can be accessed from.
 
 */

%new - (NSString *)importFile:(NSString *)inputFile withApp:(id)proxy {
    
    NSFileManager *man = [NSFileManager defaultManager];
    NSString *onePath = [[proxy dataContainerURL] path];
    if (onePath == nil){
        onePath = @"/";
    }
    NSString *cachePath = [[onePath stringByAppendingPathComponent:@"Library/Caches"] stringByAppendingPathComponent:[proxy bundleIdentifier]];
    if (![man fileExistsAtPath:cachePath]){
        NSDictionary *folderAttrs = @{NSFileGroupOwnerAccountName: @"admin",NSFileOwnerAccountName: @"mobile", NSFilePosixPermissions: @755};
        NSError *error = nil;
        [man createDirectoryAtPath:cachePath withIntermediateDirectories:YES attributes:folderAttrs error:&error];
        if (error){
            HBLogDebug(@"creating %@ had error: %@", cachePath, error);
        }
    }
    NSString *newPath = [cachePath stringByAppendingPathComponent:[inputFile lastPathComponent]];
    NSError *copyError = nil;
    if ([man fileExistsAtPath:newPath]){
        [man removeItemAtPath:inputFile error:nil];
        return newPath;
    } else {
        HBLogDebug(@"attempting to copy %@ to %@", inputFile, newPath);
        if ([man copyItemAtPath:inputFile toPath:newPath error:&copyError]) {
            [man removeItemAtPath:inputFile error:nil];
            return newPath;
        } else {
            HBLogDebug(@"failed to copy %@ to %@ with error: %@", inputFile, newPath, copyError);
            return inputFile;
        }
    }
    return inputFile;
}

/*
 
 Meat and potatoes of opening the applications on our own, this works better than their
 operations provided in LSApplicationWorkspace to open files.
 
 Use FrontBoardServices framework in conjunction with FBProcessManager, CoreServices and Launchservices
 to create an application launch request and process it.
 
 */

%new - (void)openItems:(NSArray *)items ofType:(KBBreezyFileType)fileType withApplication:(id)proxy {
    
    Class FBSOpenApplicationOptions = %c(FBSOpenApplicationOptions);
    Class FBSystemServiceOpenApplicationRequest = %c(FBSystemServiceOpenApplicationRequest);
    id pbProcMan = [%c(PBProcessManager) sharedInstance];
    id _fbProcMan = [%c(FBProcessManager) sharedInstance];
    NSString *bundleID = [proxy bundleIdentifier];
    __block id pbProcess = [_fbProcMan systemApplicationProcess]; //Our process reference to PineBoard
    [items enumerateObjectsUsingBlock:^(NSString * _Nonnull item, NSUInteger idx, BOOL * _Nonnull stop) {
        NSMutableDictionary *_options = [NSMutableDictionary new];
        _options[FBSOpenApplicationOptionKeyActivateSuspended] = @0;
        _options[FBSOpenApplicationOptionKeyDocumentOpen4LS] = @1;
        _options[@"LSBlockUntilComplete"] = @1; //13.0+ shouldnt hurt anything
        _options[FBSOpenApplicationOptionKeyPayloadAnnotation] = @{@"LSMoveDocumentOnOpen": @0, @"LSDocumentDropCount": [NSNumber numberWithInteger:items.count], @"LSDocumentDropIndex": [NSNumber numberWithInteger:idx]};
        _options[FBSOpenApplicationOptionKeyPayloadOptions] = @{@"UIApplicationLaunchOptionsSourceApplicationKey": @"com.apple.PineBoard"};
        if (fileType == KBBreezyFileTypeLink){
            _options[FBSOpenApplicationOptionKeyPayloadURL] = [NSURL URLWithString:item];
        } else {
            NSLog(@"[Breezy] og item: %@", item);
            //NSString *importedItem = [inbox stringByAppendingPathComponent:item.lastPathComponent];
            NSString *importedItem = [self importFile:item withApp:proxy];
            NSLog(@"[Breezy] imported item: %@", importedItem);
            _options[FBSOpenApplicationOptionKeyPayloadURL] = [NSURL fileURLWithPath:importedItem];
        }
        
        id options = [FBSOpenApplicationOptions optionsWithDictionary:_options];
        id openAppRequest = [FBSystemServiceOpenApplicationRequest request];
        [openAppRequest setTrusted:TRUE];
        [openAppRequest setBundleIdentifier:bundleID];
        [openAppRequest setOptions:options];
        [openAppRequest setClientProcess:pbProcess];
        CGFloat multiplier = 0.5;
        if ([_fbProcMan processesForBundleIdentifier:bundleID].count == 0){
            multiplier = 1;
            HBLogDebug(@"App isnt running yet, bumping up the multiplier so stuff gets processed successfully");
        }
        CGFloat offset = idx*multiplier;
        
        // staggers each open by 'offset' seconds
        dispatch_after(dispatch_time(DISPATCH_TIME_NOW, offset * NSEC_PER_SEC), dispatch_get_main_queue(), ^{
            
            if ([pbProcMan respondsToSelector:@selector(_handleOpenApplicationRequest:bundleID:options:withResult:)]){
                [pbProcMan _handleOpenApplicationRequest:openAppRequest bundleID:bundleID options:_options withResult:^(NSError *error) {
                    HBLogDebug(@"open app finished with error: %@", error);
                    if (error != nil){
                        [pbProcMan activateApplication:bundleID openURL:_options[FBSOpenApplicationOptionKeyPayloadURL] options:_options suspended:FALSE completion:nil];
                    }
                }];
                
            } else if ([pbProcMan respondsToSelector:@selector(_openAppFromRequest:bundleIdentifier:URL:withResult:)]){ //13.0 -> ?
                [pbProcMan _openAppFromRequest:openAppRequest bundleIdentifier:bundleID URL:[NSURL fileURLWithPath:item] withResult:^(NSError *error) {
                    HBLogDebug(@"open app finished with error: %@", error);
                }];
            } else {
                [pbProcMan _openAppFromRequest:openAppRequest bundleIdentifier:bundleID URL:[NSURL fileURLWithPath:item] completion:^(NSError *error) {
                    HBLogDebug(@"open app finished with error: %@", error);
                }];
            }
        });
    }];
}

%end
%end //PineBoard Group
id (*__OG_UTTypeAddWithDeclarationDictionary13)(id lsdatabase, NSDictionary *utiDict, NSDictionary *unknownDict, int unk);
id (*__OG_UTTypeAddWithDeclarationDictionary12)(id lsdatabase, NSDictionary *utiDict, int arg2, int arg3);
//default    20:57:42.827081 -0700    lsd    [Breezy] __UTTypeAddWithDeclarationDictionary() called with 0: _LSDatabase 1: __NSDictionaryM 3: __NSFrozenDictionaryM 4: 116

/*
 
 [Breezy] __UTTypeAddWithDeclarationDictionary() called with 0: <LSDatabase 0x101817200> { path = '/private/var/containers/Data/System/7212BC67-20CD-4982-99E0-711EB95AB895/Library/Caches/com.apple.LaunchServices-231-v2.csstore' } 1: {
 UTTypeConformsTo = "public.movie";
 UTTypeDescription = RealMedia;
 UTTypeIdentifier = "com.real.realmedia";
 UTTypeTagSpecification =     {
 "com.apple.ostype" = PNRM;
 "public.filename-extension" = rm;
 "public.mime-type" = "application/vnd.rn-realmedia";
 };
 } 2: 100 3: 4
 
 */

id ___UTTypeAddWithDeclarationDictionary13(id lsdatabase, NSDictionary *utiDict, NSDictionary *targetDict, int arg3)
{
    NSLog(@"[Breezy] __UTTypeAddWithDeclarationDictionary() called with 0: %@ 1: %@ 2: %i 3: %i", lsdatabase, utiDict, targetDict, arg3);
    //int retv = __OG_UTTypeAddWithDeclarationDictionary13(lsdatabase, utiDict, targetDict, arg3);
    return nil;
}

//id (*__OG_UTTypeAddWithDeclarationDictionary)(id arg0, id arg1, int arg2, int arg3);
id ___UTTypeAddWithDeclarationDictionary12(id lsdatabase, NSDictionary *utiDict, int arg2, int arg3)
{
    NSLog(@"[Breezy] __UTTypeAddWithDeclarationDictionary() called with 0: %@ 1: %@ 2: %i 3: %i", lsdatabase, utiDict, arg2, arg3);
    //int retv = __OG_UTTypeAddWithDeclarationDictionary12(arg0, arg1, arg2, arg3);
    return nil;
}

%ctor {
    
    NSString *processName = [[[[NSProcessInfo processInfo] arguments] lastObject] lastPathComponent];
    //HBLogDebug(@"Process name: %@", processName);
    if ([processName isEqualToString:@"lsd"]){
        HBLogDebug(@"[Breezy] tripping bro");
        //int __UTTypeAddWithDeclarationDictionary(int arg0, int arg1, int arg2, int arg3)
        MSImageRef cs = MSGetImageByName("/System/Library/Frameworks/CoreServices.framework/CoreServices");
        void* weouthere = MSFindSymbol(cs, "__UTTypeAddWithDeclarationDictionary");
        NSLog(@"[Breezy] hooking %p", weouthere);
        
        if (weouthere){
            //MSHookFunction((void*)weouthere, (void*)___UTTypeAddWithDeclarationDictionary12, (void**)&__OG_UTTypeAddWithDeclarationDictionary12);
        }
      
    }
    if ([processName isEqualToString:@"PineBoard"]){
        %init(PineBoard);

    } else if ([processName isEqualToString:@"sharingd"]){
        %init(Sharingd);
    }
}
