//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "SDAutoUnlockAuthSession.h"

@class NSArray, NSData, NSDate, NSObject, NSString, NSUUID, SDUnlockSessionAuthToken, SFAutoUnlockDevice;
@protocol OS_dispatch_source;

__attribute__((visibility("hidden")))
@interface SDAutoUnlockLockSession : SDAutoUnlockAuthSession
{
    _Bool _useProxy;	// 8 = 0x8
    _Bool _wifiState;	// 9 = 0x9
    _Bool _otherSessionCancel;	// 10 = 0xa
    _Bool _otherProviderCancel;	// 11 = 0xb
    _Bool _attemptTimedOut;	// 12 = 0xc
    _Bool _canceled;	// 13 = 0xd
    _Bool _oldWatch;	// 14 = 0xe
    _Bool _onlyRanging;	// 15 = 0xf
    _Bool _foundPeer;	// 16 = 0x10
    _Bool _connected;	// 17 = 0x11
    _Bool _lockedKeyBag;	// 18 = 0x12
    _Bool _unlockSucceeded;	// 19 = 0x13
    _Bool _deviceWasLocked;	// 20 = 0x14
    _Bool _receivedAWDLInfo;	// 21 = 0x15
    _Bool _sendingConfirmation;	// 22 = 0x16
    _Bool _sentExchangeResponse;	// 23 = 0x17
    _Bool _receivedExchangeRequest;	// 24 = 0x18
    _Bool _supportsConfirmationACK;	// 25 = 0x19
    _Bool _waitingForDisplayOrClamshell;	// 26 = 0x1a
    _Bool _awdlUp;	// 27 = 0x1b
    int _proxyRSSI;	// 28 = 0x1c
    int _watchRSSI;	// 32 = 0x20
    NSUUID *_bluetoothID;	// 40 = 0x28
    NSDate *_startDate;	// 48 = 0x30
    double _discoveryTime;	// 56 = 0x38
    double _proxyDiscoveryTime;	// 64 = 0x40
    NSString *_proxyDeviceModel;	// 72 = 0x48
    double _proxyConnectionTime;	// 80 = 0x50
    unsigned long long _connectedBluetoothDevices;	// 88 = 0x58
    long long _timeSinceLastMachineWake;	// 96 = 0x60
    long long _lastSleepType;	// 104 = 0x68
    SFAutoUnlockDevice *_autoUnlockDevice;	// 112 = 0x70
    NSData *_externalACMContext;	// 120 = 0x78
    NSArray *_peerList;	// 128 = 0x80
    NSData *_peerMacAddress;	// 136 = 0x88
    SDUnlockSessionAuthToken *_sessionAuthToken;	// 144 = 0x90
    long long _displayCount;	// 152 = 0x98
    long long _configChangeType;	// 160 = 0xa0
    NSObject<OS_dispatch_source> *_displayTimer;	// 168 = 0xa8
    NSObject<OS_dispatch_source> *_confirmationTimer;	// 176 = 0xb0
    NSString *_watchModelID;	// 184 = 0xb8
    NSString *_watchBuildVersion;	// 192 = 0xc0
    NSString *_watchOSVersion;	// 200 = 0xc8
    NSDate *_discoveryDate;	// 208 = 0xd0
    NSDate *_connectionDate;	// 216 = 0xd8
    NSDate *_firstSend;	// 224 = 0xe0
    NSDate *_exchageResponseDate;	// 232 = 0xe8
    NSDate *_displayOrClamshellWaitingDate;	// 240 = 0xf0
    NSDate *_confirmationSendDate;	// 248 = 0xf8
    double _btOverall;	// 256 = 0x100
    double _btBootstrap;	// 264 = 0x108
    double _awdlInfoExchange;	// 272 = 0x110
    double _keyRequestExchange;	// 280 = 0x118
    double _tokenExchange;	// 288 = 0x120
    double _confirmation;	// 296 = 0x128
    double _peerFoundInterval;	// 304 = 0x130
    double _awdlTotal;	// 312 = 0x138
    double _completeExchange;	// 320 = 0x140
    double _connectionTime;	// 328 = 0x148
    double _connectionWaitTime;	// 336 = 0x150
    double _displayClamshellWaitTime;	// 344 = 0x158
}

@property(nonatomic) double displayClamshellWaitTime; // @synthesize displayClamshellWaitTime=_displayClamshellWaitTime;
@property(nonatomic) double connectionWaitTime; // @synthesize connectionWaitTime=_connectionWaitTime;
@property(nonatomic) double connectionTime; // @synthesize connectionTime=_connectionTime;
@property(nonatomic) double completeExchange; // @synthesize completeExchange=_completeExchange;
@property(nonatomic) double awdlTotal; // @synthesize awdlTotal=_awdlTotal;
@property(nonatomic) double peerFoundInterval; // @synthesize peerFoundInterval=_peerFoundInterval;
@property(nonatomic) double confirmation; // @synthesize confirmation=_confirmation;
@property(nonatomic) double tokenExchange; // @synthesize tokenExchange=_tokenExchange;
@property(nonatomic) double keyRequestExchange; // @synthesize keyRequestExchange=_keyRequestExchange;
@property(nonatomic) double awdlInfoExchange; // @synthesize awdlInfoExchange=_awdlInfoExchange;
@property(nonatomic) double btBootstrap; // @synthesize btBootstrap=_btBootstrap;
@property(nonatomic) double btOverall; // @synthesize btOverall=_btOverall;
@property(retain, nonatomic) NSDate *confirmationSendDate; // @synthesize confirmationSendDate=_confirmationSendDate;
@property(retain, nonatomic) NSDate *displayOrClamshellWaitingDate; // @synthesize displayOrClamshellWaitingDate=_displayOrClamshellWaitingDate;
@property(retain, nonatomic) NSDate *exchageResponseDate; // @synthesize exchageResponseDate=_exchageResponseDate;
@property(retain, nonatomic) NSDate *firstSend; // @synthesize firstSend=_firstSend;
@property(retain, nonatomic) NSDate *connectionDate; // @synthesize connectionDate=_connectionDate;
@property(retain, nonatomic) NSDate *discoveryDate; // @synthesize discoveryDate=_discoveryDate;
@property(retain, nonatomic) NSString *watchOSVersion; // @synthesize watchOSVersion=_watchOSVersion;
@property(retain, nonatomic) NSString *watchBuildVersion; // @synthesize watchBuildVersion=_watchBuildVersion;
@property(retain, nonatomic) NSString *watchModelID; // @synthesize watchModelID=_watchModelID;
@property(nonatomic) _Bool awdlUp; // @synthesize awdlUp=_awdlUp;
@property(retain) NSObject<OS_dispatch_source> *confirmationTimer; // @synthesize confirmationTimer=_confirmationTimer;
@property(retain) NSObject<OS_dispatch_source> *displayTimer; // @synthesize displayTimer=_displayTimer;
@property(nonatomic) long long configChangeType; // @synthesize configChangeType=_configChangeType;
@property(nonatomic) long long displayCount; // @synthesize displayCount=_displayCount;
@property(nonatomic) int watchRSSI; // @synthesize watchRSSI=_watchRSSI;
@property(retain, nonatomic) SDUnlockSessionAuthToken *sessionAuthToken; // @synthesize sessionAuthToken=_sessionAuthToken;
@property(copy, nonatomic) NSData *peerMacAddress; // @synthesize peerMacAddress=_peerMacAddress;
@property(copy, nonatomic) NSArray *peerList; // @synthesize peerList=_peerList;
@property(nonatomic) _Bool waitingForDisplayOrClamshell; // @synthesize waitingForDisplayOrClamshell=_waitingForDisplayOrClamshell;
@property(nonatomic) _Bool supportsConfirmationACK; // @synthesize supportsConfirmationACK=_supportsConfirmationACK;
@property(nonatomic) _Bool receivedExchangeRequest; // @synthesize receivedExchangeRequest=_receivedExchangeRequest;
@property(nonatomic) _Bool sentExchangeResponse; // @synthesize sentExchangeResponse=_sentExchangeResponse;
@property(nonatomic) _Bool sendingConfirmation; // @synthesize sendingConfirmation=_sendingConfirmation;
@property(nonatomic) _Bool receivedAWDLInfo; // @synthesize receivedAWDLInfo=_receivedAWDLInfo;
@property(nonatomic) _Bool deviceWasLocked; // @synthesize deviceWasLocked=_deviceWasLocked;
@property(nonatomic) _Bool unlockSucceeded; // @synthesize unlockSucceeded=_unlockSucceeded;
@property(nonatomic) _Bool lockedKeyBag; // @synthesize lockedKeyBag=_lockedKeyBag;
@property(nonatomic) _Bool connected; // @synthesize connected=_connected;
@property(nonatomic) _Bool foundPeer; // @synthesize foundPeer=_foundPeer;
@property(nonatomic) _Bool onlyRanging; // @synthesize onlyRanging=_onlyRanging;
@property(nonatomic) _Bool oldWatch; // @synthesize oldWatch=_oldWatch;
@property(nonatomic) _Bool canceled; // @synthesize canceled=_canceled;
@property(retain, nonatomic) NSData *externalACMContext; // @synthesize externalACMContext=_externalACMContext;
@property(retain, nonatomic) SFAutoUnlockDevice *autoUnlockDevice; // @synthesize autoUnlockDevice=_autoUnlockDevice;
@property(nonatomic) long long lastSleepType; // @synthesize lastSleepType=_lastSleepType;
@property(nonatomic) long long timeSinceLastMachineWake; // @synthesize timeSinceLastMachineWake=_timeSinceLastMachineWake;
@property(nonatomic) unsigned long long connectedBluetoothDevices; // @synthesize connectedBluetoothDevices=_connectedBluetoothDevices;
@property(nonatomic) double proxyConnectionTime; // @synthesize proxyConnectionTime=_proxyConnectionTime;
@property(nonatomic) int proxyRSSI; // @synthesize proxyRSSI=_proxyRSSI;
@property(retain, nonatomic) NSString *proxyDeviceModel; // @synthesize proxyDeviceModel=_proxyDeviceModel;
@property(nonatomic) double proxyDiscoveryTime; // @synthesize proxyDiscoveryTime=_proxyDiscoveryTime;
@property(nonatomic) double discoveryTime; // @synthesize discoveryTime=_discoveryTime;
@property(retain, nonatomic) NSDate *startDate; // @synthesize startDate=_startDate;
@property(nonatomic) _Bool attemptTimedOut; // @synthesize attemptTimedOut=_attemptTimedOut;
@property(nonatomic) _Bool otherProviderCancel; // @synthesize otherProviderCancel=_otherProviderCancel;
@property(nonatomic) _Bool otherSessionCancel; // @synthesize otherSessionCancel=_otherSessionCancel;
@property(nonatomic) _Bool wifiState; // @synthesize wifiState=_wifiState;
@property(nonatomic) _Bool useProxy; // @synthesize useProxy=_useProxy;
@property(retain, nonatomic) NSUUID *bluetoothID; // @synthesize bluetoothID=_bluetoothID;
- (void).cxx_destruct;	// IMP=0x0000000100128408
- (void)sendUnlockConfirmation:(_Bool)arg1 withError:(id)arg2;	// IMP=0x00000001001276d0
- (void)sendKeyExchangeResponseWithData:(id)arg1;	// IMP=0x00000001001273c0
- (void)sendUnlockRequest;	// IMP=0x000000010012717c
- (void)sendAWDLInfoData:(id)arg1 type:(unsigned short)arg2 completionHandler:(CDUnknownBlockType)arg3;	// IMP=0x0000000100126df8
- (void)consumeAuthTokenIfReady;	// IMP=0x0000000100126894
- (void)startAWDL;	// IMP=0x0000000100125c80
- (void)handleConfirmationACK;	// IMP=0x0000000100125af0
- (void)handleSessionAuthToken:(id)arg1;	// IMP=0x0000000100125680
- (void)handleSessionKeyExchangeRequest:(id)arg1;	// IMP=0x0000000100124e10
- (void)handleAWDLInfo:(id)arg1;	// IMP=0x00000001001246f4
- (void)handleMessageWithWrapper:(id)arg1;	// IMP=0x00000001001242c8
- (void)notifyDelegateWithError:(id)arg1;	// IMP=0x0000000100124070
- (void)handleWiFiRequestInvalidated;	// IMP=0x0000000100124004
- (void)handleRangingStarted;	// IMP=0x0000000100123f64
- (void)handlePeerFound:(_Bool)arg1;	// IMP=0x0000000100123e94
- (void)handleAWDLUp;	// IMP=0x0000000100123cc0
- (void)handlePeerOutOfRange;	// IMP=0x00000001001239c4
- (void)handlePeerInRange;	// IMP=0x0000000100123864
- (void)invalidateConfirmationTimer;	// IMP=0x000000010012378c
- (void)restartConfirmationTimer:(unsigned long long)arg1 error:(id)arg2;	// IMP=0x0000000100123508
- (void)handleTimerFired;	// IMP=0x0000000100122f58
- (void)invalidateTimerIfReady;	// IMP=0x0000000100122f00
- (id)aksPeerAvailable;	// IMP=0x0000000100122cf8
- (void)deviceConnected:(id)arg1;	// IMP=0x00000001001229a0
- (_Bool)handleFoundBLEDevice:(id)arg1 available:(_Bool)arg2 lockedOnWrist:(_Bool)arg3;	// IMP=0x00000001001226a0
- (_Bool)handleFoundBLEDevice:(id)arg1;	// IMP=0x0000000100122634
- (void)connectionActivated;	// IMP=0x0000000100122368
@property(readonly, nonatomic) _Bool usingProxy;
- (id)hintToken;	// IMP=0x0000000100122234
- (_Bool)isAcceptor;	// IMP=0x000000010012222c
- (id)attemptResults;	// IMP=0x0000000100121618
- (void)logResults;	// IMP=0x00000001001207f4
- (void)displayConfigChanged:(id)arg1;	// IMP=0x0000000100120750
- (void)clamshellStateChanged:(id)arg1;	// IMP=0x00000001001206ac
- (void)removeObservers;	// IMP=0x000000010012065c
- (void)addObservers;	// IMP=0x0000000100120554
- (void)handleDecryptionFailure:(long long)arg1;	// IMP=0x00000001001203dc
- (void)_handleCanceledAfterSuccess;	// IMP=0x00000001001202d4
- (void)handleCanceledAfterSuccess;	// IMP=0x0000000100120248
- (void)lockKeyBagIfNeeded;	// IMP=0x0000000100120164
- (void)_cancel;	// IMP=0x000000010011fde4
- (void)cancel;	// IMP=0x000000010011fd58
- (void)invalidateNoDisconnect;	// IMP=0x000000010011fd24
- (void)invalidate;	// IMP=0x000000010011fb80
- (id)initWithAutoUnlockDevice:(id)arg1 sessionID:(id)arg2 bleDevice:(id)arg3;	// IMP=0x000000010011f78c

@end

