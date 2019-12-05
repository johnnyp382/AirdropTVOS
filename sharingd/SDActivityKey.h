//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <objc/NSObject.h>

@class NSDate, NSDictionary, NSMutableData, NSUUID;

__attribute__((visibility("hidden")))
@interface SDActivityKey : NSObject
{
    _Bool _validKey;	// 8 = 0x8
    unsigned short _lastUsedCounter;	// 10 = 0xa
    NSUUID *_keyIdentifier;	// 16 = 0x10
    NSDate *_dateCreated;	// 24 = 0x18
    NSMutableData *_keyData;	// 32 = 0x20
}

@property(nonatomic, getter=isValidKey) _Bool validKey; // @synthesize validKey=_validKey;
@property(retain, nonatomic) NSMutableData *keyData; // @synthesize keyData=_keyData;
@property(nonatomic) unsigned short lastUsedCounter; // @synthesize lastUsedCounter=_lastUsedCounter;
@property(retain, nonatomic) NSDate *dateCreated; // @synthesize dateCreated=_dateCreated;
@property(retain, nonatomic) NSUUID *keyIdentifier; // @synthesize keyIdentifier=_keyIdentifier;
- (void).cxx_destruct;	// IMP=0x0000000100151ea8
@property(readonly, nonatomic) NSDictionary *dictRepresentation;
- (unsigned long long)hash;	// IMP=0x0000000100151c54
- (_Bool)isEqual:(id)arg1;	// IMP=0x0000000100151b6c
- (id)description;	// IMP=0x0000000100151a60
- (void)dealloc;	// IMP=0x00000001001519a8
- (id)initWithDictRepresentation:(id)arg1;	// IMP=0x0000000100151738

@end

