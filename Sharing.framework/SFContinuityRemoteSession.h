/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:47:03 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/PrivateFrameworks/Sharing.framework/Sharing
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/


@protocol OS_dispatch_queue;
@class NSMutableArray, SFSession, NSObject, SFDevice;

@interface SFContinuityRemoteSession : NSObject {

	BOOL _activateCalled;
	/*^block*/id _activateHandler;
	BOOL _invalidateCalled;
	NSMutableArray* _messageQueue;
	BOOL _pairVerifyDone;
	BOOL _pairVerifyRunning;
	SFSession* _sfSession;
	BOOL _sfSessionActivated;
	BOOL _started;
	NSObject*<OS_dispatch_queue> _dispatchQueue;
	/*^block*/id _interruptionHandler;
	/*^block*/id _invalidationHandler;
	SFDevice* _peerDevice;

}

@property (nonatomic,retain) NSObject*<OS_dispatch_queue> dispatchQueue;              //@synthesize dispatchQueue=_dispatchQueue - In the implementation block
@property (nonatomic,copy) id interruptionHandler;                                    //@synthesize interruptionHandler=_interruptionHandler - In the implementation block
@property (nonatomic,copy) id invalidationHandler;                                    //@synthesize invalidationHandler=_invalidationHandler - In the implementation block
@property (nonatomic,retain) SFDevice * peerDevice;                                   //@synthesize peerDevice=_peerDevice - In the implementation block
-(void)_sfSessionStart;
-(void)_sendQueuedMesssages;
-(void)_sendCommand:(int)arg1 options:(id)arg2 ;
-(void)sendCommand:(int)arg1 ;
-(void)sendCommand:(int)arg1 options:(id)arg2 ;
-(void)activateWithCompletion:(/*^block*/id)arg1 ;
-(SFDevice *)peerDevice;
-(void)setDispatchQueue:(NSObject*<OS_dispatch_queue>)arg1 ;
-(NSObject*<OS_dispatch_queue>)dispatchQueue;
-(void)setPeerDevice:(SFDevice *)arg1 ;
-(id)init;
-(void)dealloc;
-(void)invalidate;
-(void)_cleanup;
-(id)interruptionHandler;
-(void)setInterruptionHandler:(id)arg1 ;
-(id)invalidationHandler;
-(void)setInvalidationHandler:(id)arg1 ;
-(void)_run;
@end

