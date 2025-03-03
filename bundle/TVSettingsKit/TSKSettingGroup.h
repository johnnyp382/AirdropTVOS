/*
* This header is generated by classdump-dyld 1.0
* on Sunday, July 22, 2018 at 11:13:54 PM Mountain Standard Time
* Operating System: Version 11.3 (Build 15L211)
* Image Source: /System/Library/PrivateFrameworks/TVSettingKit.framework/TVSettingKit
* classdump-dyld is licensed under GPLv3, Copyright © 2013-2016 by Elias Limneos.
*/

#import "TSKSettingItem.h"
#import "TSKSettingGroupDelegate.h"

@protocol TSKSettingGroupDelegate;
@class NSArray;

@interface TSKSettingGroup : TSKSettingItem {

	BOOL _autoHide;
	BOOL _shouldAutoHide;
	BOOL _headerIsDirty;
	NSArray* _settingItems;
	NSArray* _visibleItems;
	id<TSKSettingGroupDelegate> _delegate;

}

@property (weak,nonatomic) id<TSKSettingGroupDelegate> delegate;              //@synthesize delegate=_delegate - In the implementation block
@property (nonatomic,copy) NSArray * visibleItems;                                     //@synthesize visibleItems=_visibleItems - In the implementation block
@property (nonatomic,copy,readonly) NSArray * observableSettingItems; 
@property (assign,nonatomic) BOOL shouldAutoHide;                                      //@synthesize shouldAutoHide=_shouldAutoHide - In the implementation block
@property (assign,nonatomic) BOOL headerIsDirty;                                       //@synthesize headerIsDirty=_headerIsDirty - In the implementation block
@property (nonatomic,copy) NSArray * settingItems;                                     //@synthesize settingItems=_settingItems - In the implementation block
@property (assign,nonatomic) BOOL autoHide;                                            //@synthesize autoHide=_autoHide - In the implementation block
+(id)groupWithTitle:(id)arg1 settingItems:(id)arg2 ;
-(id<TSKSettingGroupDelegate>)delegate;
-(void)setDelegate:(id<TSKSettingGroupDelegate>)arg1 ;
-(BOOL)isHidden;
-(id)initWithTitle:(id)arg1 ;
-(id)_metadata;
-(NSArray *)settingItems;
-(void)setSettingItems:(NSArray *)arg1 ;
-(id)initWithTitle:(id)arg1 description:(id)arg2 representedObject:(id)arg3 keyPath:(id)arg4 readOnly:(BOOL)arg5 accessoryTypes:(unsigned long long)arg6 childControllerClass:(Class)arg7 ;
-(void)_performUpdateTransactionWithBlock:(/*^block*/id)arg1 ;
-(void)_prepareSettingItems;
-(void)_removeSettingItems:(id)arg1 ;
-(void)_insertSettingItems:(id)arg1 afterItem:(id)arg2 ;
-(void)_updateSettingItemsWithValue:(id)arg1 ;
-(NSArray *)observableSettingItems;
-(NSArray *)visibleItems;
-(void)setHeaderIsDirty:(BOOL)arg1 ;
-(BOOL)headerIsDirty;
-(void)_pruneDeletedItems;
-(BOOL)shouldAutoHide;
-(void)_applyUpdates:(BOOL)arg1 ;
-(id)_headerMetadata;
-(void)setVisibleItems:(NSArray *)arg1 ;
-(void)setShouldAutoHide:(BOOL)arg1 ;
-(BOOL)autoHide;
-(void)setAutoHide:(BOOL)arg1 ;
@end

