//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSNumber, NSString;
@protocol SDNetworkEjecterDelegate;

__attribute__((visibility("hidden")))
@interface SDNetworkEjecter : NSObject
{
    struct __SFNode *_node;	// 8 = 0x8
    int _mountedCount;	// 16 = 0x10
    int _ejectedCount;	// 20 = 0x14
    NSNumber *_flags;	// 24 = 0x18
    NSString *_protocol;	// 32 = 0x20
    id <SDNetworkEjecterDelegate> _delegate;	// 40 = 0x28
}

@property __weak id <SDNetworkEjecterDelegate> delegate; // @synthesize delegate=_delegate;
@property(copy) NSString *protocol; // @synthesize protocol=_protocol;
@property(copy) NSNumber *flags; // @synthesize flags=_flags;
- (void).cxx_destruct;	// IMP=0x0000000100092a4c
- (void)stop;	// IMP=0x0000000100092974
- (int)start;	// IMP=0x00000001000928b4
- (void)eject;	// IMP=0x000000010009265c
- (void)ejectMountPoints:(id)arg1 useAssistant:(_Bool)arg2;	// IMP=0x0000000100092658
- (void)notifyClientAboutEject:(int)arg1;	// IMP=0x0000000100092494
- (void)dealloc;	// IMP=0x0000000100092444
- (id)initWithNode:(struct __SFNode *)arg1;	// IMP=0x00000001000923a4

@end

