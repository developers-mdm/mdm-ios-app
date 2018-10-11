//
//  MDMBundle.h
//  MDMBundle
//
//  Created by Robson Moreira on 11/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDMAd.h"
#import "MDMAdDelegate.h"
#import "MDMAppBehavior.h"
#import "MDMGeoBehavior.h"
#import "MDMNotification.h"
#import "MDMNotificationService.h"
#import "MDMNotificationViewController.h"

//! Project version number for MDMBundle.
FOUNDATION_EXPORT double MDMBundleVersionNumber;

//! Project version string for MDMBundle.
FOUNDATION_EXPORT const unsigned char MDMBundleVersionString[];

@interface MDMBundle : NSObject

+ (void)ignoreNotificationModule;

+ (void)doNotIgnoreNotificationModule;

+ (void)ignoreAppBehaviorModule;

+ (void)doNotIgnoreAppBehaviorModule;

+ (void)ignoreGeoBehaviorModule;

+ (void)doNotIgnoreGeoBehaviorModule;

+ (void)ignoreAdModule;

+ (void)doNotIgnoreAdModule;

+ (void)start;

+ (void)start:(void (^)(void))completionHandler;

@end
