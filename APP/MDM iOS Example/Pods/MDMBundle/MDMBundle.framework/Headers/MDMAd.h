//
//  MDMAd.h
//  MDMAd
//
//  Created by Robson Moreira on 27/02/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#import "MDMAdDelegate.h"

//! Project version number for MDMAd.
FOUNDATION_EXPORT double MDMAdVersionNumber;

//! Project version string for MDMAd.
FOUNDATION_EXPORT const unsigned char MDMAdVersionString[];

#define MODULE_AD @"mdm-ad"

@interface MDMAd : NSObject

typedef NS_ENUM(NSInteger, MDMAdType) {
    MDMAdBannerView,
    MDMAdInterstitialView
};

typedef NS_ENUM(NSInteger, MDMAdLoading) {
    MDMNone,
    MDMStyleBlack,
    MDMStyleWhite,
    MDMStyleTransparent
};

+ (void)start;

+ (NSMutableArray *)getAudiences;

+ (void)loadAd:(CGRect)frame type:(MDMAdType)type loader:(MDMAdLoading)loader format:(NSString*)format screen:(NSString*)screen delegate:(id<MDMAdDelegate>)delegate parent:(UIViewController *)parent;

+ (void)removeAd:(MDMAdType)type;

@end
