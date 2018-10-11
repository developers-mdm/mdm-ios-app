//
//  MDMNotification.h
//  MDMNotification
//
//  Created by Robson Moreira on 10/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <UIKit/UIKit.h>

#import "MDMNotificationService.h"
#import "MDMNotificationViewController.h"

//! Project version number for MDMNotification.
FOUNDATION_EXPORT double MDMNotificationVersionNumber;

//! Project version string for MDMNotification.
FOUNDATION_EXPORT const unsigned char MDMNotificationVersionString[];

#define MODULE_NOTIFICATION @"mdm-notification"

@interface MDMNotification : NSObject

+ (void)start;

+ (BOOL)isMDMNotification:(NSDictionary *)userInfo;

+ (void)registerToken:(NSData *)tokenData;

+ (void)unregisterToken;

+ (void)processNotification:(NSDictionary *)userInfo;

@end
