/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:47:03 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/PrivateFrameworks/Sharing.framework/Sharing
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <Sharing/Sharing-Structs.h>
#import <libobjc.A.dylib/CBCentralManagerDelegate.h>
#import <libobjc.A.dylib/WPAWDLDelegate.h>
#import <libobjc.A.dylib/WPNearbyDelegate.h>

@protocol OS_dispatch_source, OS_dispatch_queue;
@class CBCentralManager, NSObject, CURetrier, NSSet, WPAWDL, WPNearby, WPPairing, NSArray, NSData, NSString;

@interface SFBLEScanner : NSObject <CBCentralManagerDelegate, WPAWDLDelegate, WPNearbyDelegate> {

	BOOL _activateCalled;
	BOOL _activated;
	BOOL _activeScan;
	BTSessionImplRef _btSession;
	BOOL _btStarted;
	CBCentralManager* _centralManager;
	NSMutableDictionary* _devices;
	BOOL _invalidateCalled;
	BOOL _needDups;
	long long _payloadType;
	BOOL _poweredOffSleep;
	NSObject*<OS_dispatch_source> _rescanTimer;
	_sFILE* _rssiEventLogFile;
	BOOL _scanStarted;
	CURetrier* _startRetrier;
	BOOL _timeoutFired;
	NSObject*<OS_dispatch_source> _timeoutTimer;
	NSSet* _trackedPeersApplied;
	BOOL _updating;
	WPAWDL* _wpAirDrop;
	WPNearby* _wpNearby;
	long long _wpNearbyType;
	WPPairing* _wpPairing;
	LogCategory* _ucat;
	BOOL _rssiLog;
	BOOL _rssiLogStdOut;
	BOOL _scanCache;
	unsigned _changeFlags;
	/*^block*/id _bluetoothStateChangedHandler;
	NSArray* _deviceFilter;
	/*^block*/id _deviceFoundHandler;
	/*^block*/id _deviceLostHandler;
	/*^block*/id _deviceChangedHandler;
	NSObject*<OS_dispatch_queue> _dispatchQueue;
	/*^block*/id _invalidationHandler;
	NSData* _payloadFilterData;
	NSData* _payloadFilterMask;
	double _rescanInterval;
	long long _rssiThreshold;
	long long _scanInterval;
	long long _scanRate;
	long long _scanState;
	/*^block*/id _scanStateChangedHandler;
	long long _scanWindow;
	double _timeout;
	/*^block*/id _timeoutHandler;
	NSSet* _trackedPeers;

}

@property (nonatomic,copy) id bluetoothStateChangedHandler;                           //@synthesize bluetoothStateChangedHandler=_bluetoothStateChangedHandler - In the implementation block
@property (assign,nonatomic) unsigned changeFlags;                                    //@synthesize changeFlags=_changeFlags - In the implementation block
@property (nonatomic,copy) NSArray * deviceFilter;                                    //@synthesize deviceFilter=_deviceFilter - In the implementation block
@property (nonatomic,copy) id deviceFoundHandler;                                     //@synthesize deviceFoundHandler=_deviceFoundHandler - In the implementation block
@property (nonatomic,copy) id deviceLostHandler;                                      //@synthesize deviceLostHandler=_deviceLostHandler - In the implementation block
@property (nonatomic,copy) id deviceChangedHandler;                                   //@synthesize deviceChangedHandler=_deviceChangedHandler - In the implementation block
@property (nonatomic,retain) NSObject*<OS_dispatch_queue> dispatchQueue;              //@synthesize dispatchQueue=_dispatchQueue - In the implementation block
@property (nonatomic,copy) id invalidationHandler;                                    //@synthesize invalidationHandler=_invalidationHandler - In the implementation block
@property (nonatomic,copy,readonly) NSData * payloadFilterData;                       //@synthesize payloadFilterData=_payloadFilterData - In the implementation block
@property (nonatomic,copy,readonly) NSData * payloadFilterMask;                       //@synthesize payloadFilterMask=_payloadFilterMask - In the implementation block
@property (assign,nonatomic) double rescanInterval;                                   //@synthesize rescanInterval=_rescanInterval - In the implementation block
@property (assign,nonatomic) BOOL rssiLog;                                            //@synthesize rssiLog=_rssiLog - In the implementation block
@property (assign,nonatomic) BOOL rssiLogStdOut;                                      //@synthesize rssiLogStdOut=_rssiLogStdOut - In the implementation block
@property (assign,nonatomic) long long rssiThreshold;                                 //@synthesize rssiThreshold=_rssiThreshold - In the implementation block
@property (assign,nonatomic) BOOL scanCache;                                          //@synthesize scanCache=_scanCache - In the implementation block
@property (assign,nonatomic) long long scanInterval;                                  //@synthesize scanInterval=_scanInterval - In the implementation block
@property (assign,nonatomic) long long scanRate;                                      //@synthesize scanRate=_scanRate - In the implementation block
@property (nonatomic,readonly) long long scanState;                                   //@synthesize scanState=_scanState - In the implementation block
@property (nonatomic,copy) id scanStateChangedHandler;                                //@synthesize scanStateChangedHandler=_scanStateChangedHandler - In the implementation block
@property (assign,nonatomic) long long scanWindow;                                    //@synthesize scanWindow=_scanWindow - In the implementation block
@property (assign,nonatomic) double timeout;                                          //@synthesize timeout=_timeout - In the implementation block
@property (nonatomic,copy) id timeoutHandler;                                         //@synthesize timeoutHandler=_timeoutHandler - In the implementation block
@property (nonatomic,copy) NSSet * trackedPeers;                                      //@synthesize trackedPeers=_trackedPeers - In the implementation block
@property (readonly) unsigned long long hash; 
@property (readonly) Class superclass; 
@property (copy,readonly) NSString * description; 
@property (copy,readonly) NSString * debugDescription; 
-(void)setTimeout:(double)arg1 ;
-(double)timeout;
-(void)centralManagerDidUpdateState:(id)arg1 ;
-(void)centralManager:(id)arg1 didDiscoverPeripheral:(id)arg2 advertisementData:(id)arg3 RSSI:(id)arg4 ;
-(void)setDeviceFilter:(NSArray *)arg1 ;
-(void)setScanRate:(long long)arg1 ;
-(long long)scanState;
-(void)setRssiThreshold:(long long)arg1 ;
-(unsigned)changeFlags;
-(void)nearbyDidUpdateState:(id)arg1 ;
-(void)nearby:(id)arg1 didStartScanningForType:(long long)arg2 ;
-(void)nearby:(id)arg1 didDiscoverType:(long long)arg2 withData:(id)arg3 fromPeer:(id)arg4 peerInfo:(id)arg5 ;
-(void)nearby:(id)arg1 didLosePeer:(id)arg2 type:(long long)arg3 ;
-(id)bluetoothStateChangedHandler;
-(void)setBluetoothStateChangedHandler:(id)arg1 ;
-(void)awdlDidUpdateState:(id)arg1 ;
-(void)awdlStartedScanning:(id)arg1 ;
-(void)awdl:(id)arg1 failedToStartScanningWithError:(id)arg2 ;
-(void)awdl:(id)arg1 foundDevice:(id)arg2 rssi:(id)arg3 ;
-(void)nearby:(id)arg1 didFailToStartScanningForType:(long long)arg2 WithError:(id)arg3 ;
-(void)pairingDidUpdateState:(id)arg1 ;
-(void)pairingStartedScanning:(id)arg1 ;
-(void)pairing:(id)arg1 failedToStartScanningWithError:(id)arg2 ;
-(void)pairing:(id)arg1 foundDevice:(id)arg2 payload:(id)arg3 rssi:(id)arg4 peerInfo:(id)arg5 ;
-(void)_rssiLogClose;
-(void)_invokeBlockActivateSafe:(/*^block*/id)arg1 ;
-(int)_btSessionEnsureStarted;
-(void)_rssiLogOpen;
-(void)_restartIfNeeded;
-(void)_updateTrackedPeers;
-(void)_btSessionEnsureStopped;
-(BOOL)_updateCounterpart:(id)arg1 ;
-(BOOL)_needActiveScan;
-(BOOL)_needDups;
-(void)_updateRescanTimer;
-(void)_removeAllDevicesWithReason:(id)arg1 ;
-(void)_startTimeoutIfNeeded;
-(void)_timeoutTimerFired;
-(void)_rescanTimerFired;
-(void)_poweredOn;
-(void)_poweredOff;
-(void)_watchSetupParseName:(id)arg1 fields:(id)arg2 ;
-(void)_foundDevice:(id)arg1 advertisementData:(id)arg2 rssi:(long long)arg3 fields:(id)arg4 ;
-(void)_nearbyParseManufacturerData:(id)arg1 fields:(id)arg2 ;
-(void)_nearbyParseNearbyActionPtr:(const char*)arg1 end:(const char*)arg2 fields:(id)arg3 ;
-(void)_nearbyParseNearbyInfoPtr:(const char*)arg1 end:(const char*)arg2 fields:(id)arg3 ;
-(id)pairingParsePayload:(id)arg1 identifier:(id)arg2 bleDevice:(id)arg3 ;
-(unsigned)statusToHeadsetStatus:(unsigned char)arg1 ;
-(id)modelWithProductID:(unsigned short)arg1 ;
-(BOOL)pairingUpdatePairedInfo:(id)arg1 fields:(id)arg2 bleDevice:(id)arg3 ;
-(void)setPayloadFilterData:(id)arg1 mask:(id)arg2 ;
-(void)setScanCache:(BOOL)arg1 ;
-(void)setTrackedPeers:(NSSet *)arg1 ;
-(void)performUpdate:(/*^block*/id)arg1 ;
-(NSArray *)deviceFilter;
-(NSData *)payloadFilterData;
-(NSData *)payloadFilterMask;
-(double)rescanInterval;
-(void)setRescanInterval:(double)arg1 ;
-(BOOL)rssiLog;
-(void)setRssiLog:(BOOL)arg1 ;
-(BOOL)rssiLogStdOut;
-(void)setRssiLogStdOut:(BOOL)arg1 ;
-(long long)rssiThreshold;
-(BOOL)scanCache;
-(long long)scanInterval;
-(void)setScanInterval:(long long)arg1 ;
-(id)scanStateChangedHandler;
-(void)setScanStateChangedHandler:(id)arg1 ;
-(long long)scanWindow;
-(void)setScanWindow:(long long)arg1 ;
-(id)timeoutHandler;
-(void)setTimeoutHandler:(id)arg1 ;
-(NSSet *)trackedPeers;
-(void)_activateWithCompletion:(/*^block*/id)arg1 ;
-(void)activateWithCompletion:(/*^block*/id)arg1 ;
-(void)setChangeFlags:(unsigned)arg1 ;
-(void)setDeviceFoundHandler:(id)arg1 ;
-(id)deviceFoundHandler;
-(id)deviceChangedHandler;
-(void)setDeviceChangedHandler:(id)arg1 ;
-(id)deviceLostHandler;
-(void)setDeviceLostHandler:(id)arg1 ;
-(void)setDispatchQueue:(NSObject*<OS_dispatch_queue>)arg1 ;
-(NSObject*<OS_dispatch_queue>)dispatchQueue;
-(long long)scanRate;
-(id)init;
-(void)dealloc;
-(NSString *)description;
-(void)invalidate;
-(id)initWithType:(long long)arg1 ;
-(void)_invalidate;
-(id)invalidationHandler;
-(void)setInvalidationHandler:(id)arg1 ;
@end

