/*
* This header is generated by classdump-dyld 1.0
* on Saturday, August 24, 2019 at 9:49:30 PM Mountain Standard Time
* Operating System: Version 12.4 (Build 16M568)
* Image Source: /System/Library/Frameworks/CoreServices.framework/CoreServices
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/


@protocol OS_dispatch_queue;
@class NSObject;

@interface LSDatabaseBuilder : NSObject {

	NSObject*<OS_dispatch_queue> _ioQueue;

}
-(void)setSeedingComplete:(BOOL)arg1 ;
-(id)initWithIOQueue:(id)arg1 ;
-(void)createAndSeedLocalDatabase:(BOOL*)arg1 ;
-(void)dealloc;
@end

