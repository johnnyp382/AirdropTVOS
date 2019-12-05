/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:49:32 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/Frameworks/CoreServices.framework/CoreServices
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import <CoreServices/_LSBundleQuery.h>

@class NSString;

@interface _LSApplicationProxyForIdentifierQuery : _LSBundleQuery {

	NSString* _identifier;

}

@property (nonatomic,copy,readonly) NSString * identifier;              //@synthesize identifier=_identifier - In the implementation block
+(id)queryWithIdentifier:(id)arg1 ;
+(id)alwaysAllowedBundleIdentifiers;
+(BOOL)supportsSecureCoding;
-(void)_enumerateWithXPCConnection:(id)arg1 block:(/*^block*/id)arg2 ;
-(BOOL)_requiresDatabaseMappingEntitlement;
-(void)dealloc;
-(NSString *)identifier;
-(BOOL)isEqual:(id)arg1 ;
-(void)encodeWithCoder:(id)arg1 ;
-(id)initWithCoder:(id)arg1 ;
-(unsigned long long)hash;
@end

