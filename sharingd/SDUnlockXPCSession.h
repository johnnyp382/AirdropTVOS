//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "SDAutoUnlockSessionManagerObserver-Protocol.h"
#import "SFUnlockProtocol-Protocol.h"

@class NSString, SFAutoUnlockDevice;
@protocol SDUnlockXPCSesssionDelegate, SFUnlockClientProtocol;

__attribute__((visibility("hidden")))
@interface SDUnlockXPCSession : NSObject <SFUnlockProtocol, SDAutoUnlockSessionManagerObserver>
{
    id <SDUnlockXPCSesssionDelegate> _delegate;	// 8 = 0x8
    NSString *_bundleID;	// 16 = 0x10
    id <SFUnlockClientProtocol> _clientProxy;	// 24 = 0x18
    SFAutoUnlockDevice *_enableDevice;	// 32 = 0x20
}

@property(retain, nonatomic) SFAutoUnlockDevice *enableDevice; // @synthesize enableDevice=_enableDevice;
@property(retain, nonatomic) id <SFUnlockClientProtocol> clientProxy; // @synthesize clientProxy=_clientProxy;
@property(copy, nonatomic) NSString *bundleID; // @synthesize bundleID=_bundleID;
@property(retain) id <SDUnlockXPCSesssionDelegate> delegate; // @synthesize delegate=_delegate;
- (void).cxx_destruct;	// IMP=0x000000010000d5c0
- (_Bool)checkEntitlementWithHandler:(CDUnknownBlockType)arg1;	// IMP=0x000000010000d18c
- (void)session:(id)arg1 didFailUnlockWithResults:(id)arg2 error:(id)arg3 incrementedAttempt:(_Bool)arg4;	// IMP=0x000000010000d0d8
- (void)session:(id)arg1 didCompleteUnlockWithDevice:(id)arg2;	// IMP=0x000000010000cf6c
- (void)session:(id)arg1 didBeginAttemptWithDevice:(id)arg2;	// IMP=0x000000010000ce48
- (void)session:(id)arg1 didFailToEnableDevice:(id)arg2 error:(id)arg3;	// IMP=0x000000010000cce8
- (void)session:(id)arg1 didEnableWithDevice:(id)arg2;	// IMP=0x000000010000cbac
- (void)session:(id)arg1 didReceiveKeyDeviceLocked:(id)arg2;	// IMP=0x000000010000cb40
- (void)notifyDelegate;	// IMP=0x000000010000cad8
- (void)authPromptInfoWithCompletionHandler:(CDUnknownBlockType)arg1;	// IMP=0x000000010000c918
- (void)autoUnlockStateWithCompletionHandler:(CDUnknownBlockType)arg1;	// IMP=0x000000010000c758
- (void)cancelAutoUnlock:(_Bool)arg1;	// IMP=0x000000010000c6dc
- (void)cancelAutoUnlock;	// IMP=0x000000010000c628
- (void)attemptAutoUnlockWithClientProxy:(id)arg1;	// IMP=0x000000010000c468
- (void)disableAutoUnlockForDevice:(id)arg1 completionHandler:(CDUnknownBlockType)arg2;	// IMP=0x000000010000c2e0
- (void)cancelEnablingAutoUnlockForDevice:(id)arg1;	// IMP=0x000000010000c264
- (void)enableAutoUnlockWithDevice:(id)arg1 passcode:(id)arg2 clientProxy:(id)arg3;	// IMP=0x000000010000bff8
- (void)eligibleAutoUnlockDevicesWithCompletionHandler:(CDUnknownBlockType)arg1;	// IMP=0x000000010000bd18
- (void)repairCloudPairing;	// IMP=0x000000010000bcd0
- (void)invalidate;	// IMP=0x000000010000bc40

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

