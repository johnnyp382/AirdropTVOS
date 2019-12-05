//
//     Generated by class-dump 3.5 (64 bit) (Debug version compiled Sep  9 2019 14:18:44).
//
//     class-dump is Copyright (C) 1997-1998, 2000-2001, 2004-2015 by Steve Nygard.
//

#import "NSObject-Protocol.h"

@class NSString, NSURL, TVPlayer, TVViewElement, UIImage, UIView, UIViewController;

@protocol TVInterfaceCreating <NSObject>

@optional
- (UIViewController *)playerViewControllerForPlayer:(TVPlayer *)arg1;
- (Class)collectionViewCellClassForElement:(TVViewElement *)arg1;
- (UIImage *)imageForResource:(NSString *)arg1;
- (NSURL *)URLForResource:(NSString *)arg1;
- (UIViewController *)viewControllerForElement:(TVViewElement *)arg1 existingViewController:(UIViewController *)arg2;
- (UIView *)viewForElement:(TVViewElement *)arg1 existingView:(UIView *)arg2;
@end

