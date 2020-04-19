//
//  MDMNotification.h
//  MDMNotification
//
//  Created by Robson Moreira on 10/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <MDMCore/MDMCore.h>
#import <UserNotifications/UserNotifications.h>

#import "MDMNotificationService.h"
#import "MDMNotificationViewController.h"
#import "MDMInbox.h"

//! Project version number for MDMNotification.
FOUNDATION_EXPORT double MDMNotificationVersionNumber;

//! Project version string for MDMNotification.
FOUNDATION_EXPORT const unsigned char MDMNotificationVersionString[];

@interface MDMNotification : MDMCoreModule

+ (void)start;

+ (void)registerToken:(NSData *)token;

+ (void)unregisterToken;

+ (BOOL)isMDMNotification:(NSDictionary *)userInfo;

+ (void)processNotification:(NSDictionary *)userInfo;

@end
