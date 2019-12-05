//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "IDSContinuityDelegate-Protocol.h"
#import "IDSServiceDelegate-Protocol.h"
#import "SDHotspotManagerDelegate-Protocol.h"
#import "SFRemoteHotspotProtocol-Protocol.h"

@class IDSContinuity, IDSService, NSDate, NSMutableDictionary, NSString, NSTimer, PCPersistentTimer, SDHotspotManager, SDStatusMonitor;
@protocol OS_dispatch_queue, OS_dispatch_source, SFRemoteHotspotClient;

__attribute__((visibility("hidden")))
@interface SDHotspotBrowser : NSObject <IDSContinuityDelegate, IDSServiceDelegate, SDHotspotManagerDelegate, SFRemoteHotspotProtocol>
{
    _Bool _hasAppleID;	// 8 = 0x8
    _Bool _shouldBeConsumerScanning;	// 9 = 0x9
    _Bool _shouldBeAdvertisingRequest;	// 10 = 0xa
    _Bool _pausedForWiFiPasswordSharing;	// 11 = 0xb
    _Bool _shouldBeAdvertisingResponse;	// 12 = 0xc
    _Bool _targetAdvertising;	// 13 = 0xd
    _Bool _targetScanning;	// 14 = 0xe
    _Bool _sourceAdvertising;	// 15 = 0xf
    _Bool _sourceScanning;	// 16 = 0x10
    unsigned int _IDHash;	// 20 = 0x14
    unsigned int _powerAssertionID;	// 24 = 0x18
    id <SFRemoteHotspotClient> _clientProxy;	// 32 = 0x20
    NSObject<OS_dispatch_queue> *_workQueue;	// 40 = 0x28
    SDStatusMonitor *_monitor;	// 48 = 0x30
    IDSContinuity *_tetheringManager;	// 56 = 0x38
    IDSService *_tetheringService;	// 64 = 0x40
    NSString *_altDSID;	// 72 = 0x48
    NSString *_timeString;	// 80 = 0x50
    PCPersistentTimer *_nextCrossoverPersistentTimer;	// 88 = 0x58
    unsigned long long _nextDayTimeOffset;	// 96 = 0x60
    NSMutableDictionary *_handlers;	// 104 = 0x68
    NSMutableDictionary *_retrieveTimers;	// 112 = 0x70
    NSTimer *_advertiseResponseTimer;	// 120 = 0x78
    NSMutableDictionary *_discoveredDevices;	// 128 = 0x80
    NSString *_targetIdentifier;	// 136 = 0x88
    NSObject<OS_dispatch_source> *_scanResetTimer;	// 144 = 0x90
    NSObject<OS_dispatch_source> *_scanAssertionTimer;	// 152 = 0x98
    SDHotspotManager *_hotspotManager;	// 160 = 0xa0
    NSString *_modelCode;	// 168 = 0xa8
    NSDate *_browseStartTime;	// 176 = 0xb0
    NSMutableDictionary *_outstandingRequests;	// 184 = 0xb8
}

+ (id)sharedBrowser;	// IMP=0x0000000100096cdc
@property(retain) NSMutableDictionary *outstandingRequests; // @synthesize outstandingRequests=_outstandingRequests;
@property(retain) NSDate *browseStartTime; // @synthesize browseStartTime=_browseStartTime;
@property(retain) NSString *modelCode; // @synthesize modelCode=_modelCode;
@property _Bool sourceScanning; // @synthesize sourceScanning=_sourceScanning;
@property _Bool sourceAdvertising; // @synthesize sourceAdvertising=_sourceAdvertising;
@property _Bool targetScanning; // @synthesize targetScanning=_targetScanning;
@property _Bool targetAdvertising; // @synthesize targetAdvertising=_targetAdvertising;
@property(retain) SDHotspotManager *hotspotManager; // @synthesize hotspotManager=_hotspotManager;
@property(retain) NSObject<OS_dispatch_source> *scanAssertionTimer; // @synthesize scanAssertionTimer=_scanAssertionTimer;
@property(retain) NSObject<OS_dispatch_source> *scanResetTimer; // @synthesize scanResetTimer=_scanResetTimer;
@property(retain) NSString *targetIdentifier; // @synthesize targetIdentifier=_targetIdentifier;
@property(retain) NSMutableDictionary *discoveredDevices; // @synthesize discoveredDevices=_discoveredDevices;
@property(retain) NSTimer *advertiseResponseTimer; // @synthesize advertiseResponseTimer=_advertiseResponseTimer;
@property _Bool shouldBeAdvertisingResponse; // @synthesize shouldBeAdvertisingResponse=_shouldBeAdvertisingResponse;
@property unsigned int powerAssertionID; // @synthesize powerAssertionID=_powerAssertionID;
@property(retain) NSMutableDictionary *retrieveTimers; // @synthesize retrieveTimers=_retrieveTimers;
@property(retain) NSMutableDictionary *handlers; // @synthesize handlers=_handlers;
@property _Bool pausedForWiFiPasswordSharing; // @synthesize pausedForWiFiPasswordSharing=_pausedForWiFiPasswordSharing;
@property _Bool shouldBeAdvertisingRequest; // @synthesize shouldBeAdvertisingRequest=_shouldBeAdvertisingRequest;
@property _Bool shouldBeConsumerScanning; // @synthesize shouldBeConsumerScanning=_shouldBeConsumerScanning;
@property unsigned long long nextDayTimeOffset; // @synthesize nextDayTimeOffset=_nextDayTimeOffset;
@property(retain) PCPersistentTimer *nextCrossoverPersistentTimer; // @synthesize nextCrossoverPersistentTimer=_nextCrossoverPersistentTimer;
@property(retain) NSString *timeString; // @synthesize timeString=_timeString;
@property(retain) NSString *altDSID; // @synthesize altDSID=_altDSID;
@property(retain) IDSService *tetheringService; // @synthesize tetheringService=_tetheringService;
@property _Bool hasAppleID; // @synthesize hasAppleID=_hasAppleID;
@property unsigned int IDHash; // @synthesize IDHash=_IDHash;
@property(retain) IDSContinuity *tetheringManager; // @synthesize tetheringManager=_tetheringManager;
@property(retain) SDStatusMonitor *monitor; // @synthesize monitor=_monitor;
@property(retain) NSObject<OS_dispatch_queue> *workQueue; // @synthesize workQueue=_workQueue;
@property(retain) id <SFRemoteHotspotClient> clientProxy; // @synthesize clientProxy=_clientProxy;
- (void).cxx_destruct;	// IMP=0x00000001000a056c
- (void)continuity:(id)arg1 didFailToStartScanningForType:(long long)arg2 withError:(id)arg3;	// IMP=0x00000001000a0044
- (void)continuity:(id)arg1 didStopScanningForType:(long long)arg2;	// IMP=0x000000010009ff50
- (void)continuity:(id)arg1 didStartScanningForType:(long long)arg2;	// IMP=0x000000010009fd68
- (void)continuity:(id)arg1 didFailToStartAdvertisingOfType:(long long)arg2 withError:(id)arg3;	// IMP=0x000000010009fbd0
- (void)continuity:(id)arg1 didStopAdvertisingOfType:(long long)arg2;	// IMP=0x000000010009fac8
- (void)continuity:(id)arg1 didStartAdvertisingOfType:(long long)arg2;	// IMP=0x000000010009f8a4
- (void)continuityDidUpdateState:(id)arg1;	// IMP=0x000000010009f6c4
- (void)tetheringDidRetrieveCredentials:(id)arg1 credentials:(id)arg2 requestRecord:(id)arg3 error:(id)arg4;	// IMP=0x000000010009ec3c
- (void)credentialsWithCompletionHandler:(CDUnknownBlockType)arg1;	// IMP=0x000000010009e6a8
- (void)continuity:(id)arg1 didDiscoverType:(long long)arg2 withData:(id)arg3 fromPeer:(id)arg4;	// IMP=0x000000010009e494
- (void)releaseIdleSleepAssertion;	// IMP=0x000000010009e400
- (void)preventIdleSleepAssertion;	// IMP=0x000000010009e260
- (void)handleScanAssertionTimerFired;	// IMP=0x000000010009e1b4
- (void)invalidateScanAssertionTimer;	// IMP=0x000000010009e0dc
- (void)restartScanAssertionTimer;	// IMP=0x000000010009dee0
- (void)handleScanResetTimerFired;	// IMP=0x000000010009de40
- (void)invalidateScanResetTimer;	// IMP=0x000000010009dd68
- (void)restartScanResetTimer;	// IMP=0x000000010009db7c
- (void)service:(id)arg1 devicesChanged:(id)arg2;	// IMP=0x000000010009da80
- (void)service:(id)arg1 account:(id)arg2 identifier:(id)arg3 didSendWithSuccess:(_Bool)arg4 error:(id)arg5;	// IMP=0x000000010009d7c0
- (void)service:(id)arg1 account:(id)arg2 incomingMessage:(id)arg3 fromID:(id)arg4 context:(id)arg5;	// IMP=0x000000010009cde4
- (void)handleIncomingResponse:(id)arg1 identifier:(id)arg2;	// IMP=0x000000010009c7b8
- (void)stopConsumerScanning;	// IMP=0x000000010009c79c
- (void)restartConsumerScanning;	// IMP=0x000000010009c610
- (void)stopProducerScanning;	// IMP=0x000000010009c584
- (void)restartProducerScanning;	// IMP=0x000000010009c344
- (void)stopAdvertisingResponse;	// IMP=0x000000010009c260
- (void)restartAdvertisingTetheringResponse;	// IMP=0x000000010009be58
- (void)stopAdvertisingTetheringRequest;	// IMP=0x000000010009bdd0
- (void)restartAdvertisingTetheringRequest;	// IMP=0x000000010009bb24
- (void)invalidateTimerWithIdentifier:(id)arg1;	// IMP=0x000000010009ba98
- (void)retrieveTimerFired:(id)arg1;	// IMP=0x000000010009b69c
- (void)addRetrieveTimer:(id)arg1;	// IMP=0x000000010009b5a4
- (void)enableHotspotForDevice:(id)arg1 withCompletionHandler:(CDUnknownBlockType)arg2;	// IMP=0x000000010009ad9c
- (void)stopBrowsing;	// IMP=0x000000010009ac4c
- (void)startBrowsing;	// IMP=0x000000010009ab14
- (_Bool)sendMessage:(id)arg1 toDeviceWithID:(id)arg2 isRequest:(_Bool)arg3 messageID:(id)arg4 error:(id *)arg5 identifier:(id *)arg6;	// IMP=0x000000010009a6dc
- (_Bool)sendMessage:(id)arg1 toPeer:(id)arg2 isRequest:(_Bool)arg3 messageID:(id)arg4 error:(id *)arg5 identifier:(id *)arg6;	// IMP=0x000000010009a250
- (void)hotspotManagerTetheringSupportChanged:(id)arg1;	// IMP=0x000000010009a0ac
- (id)formattedDate:(id)arg1;	// IMP=0x0000000100099f14
- (id)nextDateForDayInterval:(int)arg1;	// IMP=0x0000000100099da8
- (void)nextDayTimerFired:(id)arg1;	// IMP=0x0000000100099cc4
- (void)clearNextDayTimer;	// IMP=0x0000000100099c30
- (void)updateCrossoverTimer;	// IMP=0x00000001000997b0
- (void)generateNextDayTimeOffset;	// IMP=0x00000001000995a0
- (void)wifiPasswordSharingChanged:(id)arg1;	// IMP=0x000000010009935c
- (void)appleIDChanged:(id)arg1;	// IMP=0x000000010009927c
- (void)screenStateChanged:(id)arg1;	// IMP=0x00000001000991c8
- (void)debugInfoRequested:(id)arg1;	// IMP=0x0000000100098c50
- (void)altDSIDUpdated:(id)arg1;	// IMP=0x0000000100098b70
- (void)removeObservers;	// IMP=0x0000000100098b20
- (void)addObservers;	// IMP=0x00000001000989e4
- (void)credentialLog:(id)arg1;	// IMP=0x00000001000988e8
- (_Bool)serviceHasDuplicateForBTUUID:(id)arg1;	// IMP=0x000000010009864c
- (_Bool)outstandingRequestsHasHotspotDeviceForID:(id)arg1;	// IMP=0x0000000100098470
- (id)tetheringPeers;	// IMP=0x00000001000982b4
- (_Bool)accountHasTetheringSources;	// IMP=0x000000010009810c
- (_Bool)accountHasPairedPeers;	// IMP=0x0000000100097f94
- (id)pairedPeers;	// IMP=0x0000000100097df4
- (id)deviceForIdentifier:(id)arg1;	// IMP=0x0000000100097c2c
- (id)modelCodeForIdentifier:(id)arg1;	// IMP=0x0000000100097ba0
- (id)appendHashToData:(id)arg1 withType:(unsigned char)arg2;	// IMP=0x000000010009797c
- (id)HMACWithDSID:(id)arg1 timeString:(id)arg2;	// IMP=0x0000000100097850
- (_Bool)updateTimeString;	// IMP=0x000000010009765c
- (_Bool)updateIDHash;	// IMP=0x0000000100097214
- (void)updateIDHashAndRestart;	// IMP=0x0000000100097174
@property(readonly) NSString *hotspotPassword;
@property(readonly) NSString *hotspotName;
- (void)disableTethering;	// IMP=0x000000010009712c
@property(readonly, getter=isTetheringInUse) _Bool tetheringInUse;
- (id)init;	// IMP=0x0000000100096d6c

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

