//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Aug  6 2017 21:40:27).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import <ProtocolBuffer/PBRequest.h>

#import "NSCopying-Protocol.h"

@interface SDAutoUnlockAuthSessionRequest : PBRequest <NSCopying>
{
    unsigned int _version;	// 8 = 0x8
    CDStruct_f20694ce _has;	// 12 = 0xc
}

@property(nonatomic) unsigned int version; // @synthesize version=_version;
- (void)mergeFrom:(id)arg1;	// IMP=0x00000001000dbe88
- (unsigned long long)hash;	// IMP=0x00000001000dbe4c
- (_Bool)isEqual:(id)arg1;	// IMP=0x00000001000dbd98
- (id)copyWithZone:(struct _NSZone *)arg1;	// IMP=0x00000001000dbd24
- (void)copyTo:(id)arg1;	// IMP=0x00000001000dbcf4
- (void)writeTo:(id)arg1;	// IMP=0x00000001000dbcc4
- (_Bool)readFrom:(id)arg1;	// IMP=0x00000001000dbcbc
- (id)dictionaryRepresentation;	// IMP=0x00000001000db9e4
- (id)description;	// IMP=0x00000001000db930
@property(nonatomic) _Bool hasVersion;

@end

