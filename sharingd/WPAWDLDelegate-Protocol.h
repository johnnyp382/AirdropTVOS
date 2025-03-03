//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "NSObject-Protocol.h"

@class NSData, NSError, NSNumber, WPAWDL;

@protocol WPAWDLDelegate <NSObject>
- (void)awdlDidUpdateState:(WPAWDL *)arg1;

@optional
- (void)awdl:(WPAWDL *)arg1 failedToStartScanningWithError:(NSError *)arg2;
- (void)awdlStoppedScanning:(WPAWDL *)arg1;
- (void)awdlStartedScanning:(WPAWDL *)arg1;
- (void)awdl:(WPAWDL *)arg1 failedToStartAdvertisingWithError:(NSError *)arg2;
- (void)awdlAdvertisingPending:(WPAWDL *)arg1;
- (void)awdlStoppedAdvertising:(WPAWDL *)arg1;
- (void)awdlStartedAdvertising:(WPAWDL *)arg1;
- (void)awdl:(WPAWDL *)arg1 foundDevice:(NSData *)arg2 rssi:(NSNumber *)arg3;
- (_Bool)awdl:(WPAWDL *)arg1 foundDevice:(NSData *)arg2;
@end

