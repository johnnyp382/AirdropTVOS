/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:47:04 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/PrivateFrameworks/Sharing.framework/Sharing
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/


@protocol OS_dispatch_queue;
@class SFClient, SFService, SFSession, SFDeviceOperationHandlerCDPSetup, HMDeviceSetupOperationHandler, SFDeviceOperationHandlerWiFiSetup, NSObject;

@interface SFDeviceSetupAppleTVService : NSObject {

	BOOL _activateCalled;
	BOOL _advertiseFast;
	BOOL _invalidateCalled;
	SFClient* _preventExitForLocaleClient;
	SFService* _sfService;
	SFSession* _sfSession;
	SFDeviceOperationHandlerCDPSetup* _cdpSetupHandler;
	HMDeviceSetupOperationHandler* _homeKitSetupHandler;
	SFDeviceOperationHandlerWiFiSetup* _wifiSetupHandler;
	BOOL _prefCDPEnabled;
	NSObject*<OS_dispatch_queue> _dispatchQueue;
	/*^block*/id _progressHandler;

}

@property (nonatomic,retain) NSObject*<OS_dispatch_queue> dispatchQueue;              //@synthesize dispatchQueue=_dispatchQueue - In the implementation block
@property (nonatomic,copy) id progressHandler;                                        //@synthesize progressHandler=_progressHandler - In the implementation block
-(id)progressHandler;
-(void)_activate;
-(void)_sfServiceStart;
-(void)_handleSessionEnded:(id)arg1 ;
-(void)_handleSessionStarted:(id)arg1 ;
-(void)_handleFinishRequest:(id)arg1 responseHandler:(/*^block*/id)arg2 ;
-(void)_handlePreAuthRequest:(id)arg1 responseHandler:(/*^block*/id)arg2 ;
-(void)_handleBasicConfigRequest:(id)arg1 responseHandler:(/*^block*/id)arg2 ;
-(void)setDispatchQueue:(NSObject*<OS_dispatch_queue>)arg1 ;
-(NSObject*<OS_dispatch_queue>)dispatchQueue;
-(id)init;
-(void)dealloc;
-(void)invalidate;
-(void)_invalidate;
-(void)_cleanup;
-(void)activate;
-(void)setProgressHandler:(id)arg1 ;
@end

