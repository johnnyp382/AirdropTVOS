//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

#import "SDBonjourBrowserDelegate-Protocol.h"

@class NSArray, NSSet, NSString, SDBonjourBrowser;

__attribute__((visibility("hidden")))
@interface SDWorkgroupBrowser : NSObject <SDBonjourBrowserDelegate>
{
    int _clientCount;	// 8 = 0x8
    SDBonjourBrowser *_browser;	// 16 = 0x10
}

+ (id)sharedBrowser;	// IMP=0x00000001000f61a8
- (void).cxx_destruct;	// IMP=0x00000001000f6630
- (void)stop;	// IMP=0x00000001000f65c4
- (void)start;	// IMP=0x00000001000f649c
- (void)bonjourNodesDidChange:(id)arg1;	// IMP=0x00000001000f6444
@property(readonly, copy) NSSet *workgroups;
@property(readonly, copy) NSArray *nodes;
- (id)init;	// IMP=0x00000001000f6228

// Remaining properties
@property(readonly, copy) NSString *debugDescription;
@property(readonly, copy) NSString *description;
@property(readonly) unsigned long long hash;
@property(readonly) Class superclass;

@end

