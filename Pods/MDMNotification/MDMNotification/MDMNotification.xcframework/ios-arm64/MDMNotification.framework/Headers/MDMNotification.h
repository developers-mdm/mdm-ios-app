//
//  MDMNotification.h
//  MDMNotification
//
//  Created by Robson Moreira on 10/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <MDMCore/MDMCore.h>
#import <UserNotifications/UserNotifications.h>
#import <NotificationCenter/NotificationCenter.h>

#import "MDMNotificationService.h"
#import "MDMNotificationViewController.h"
#import "MDMImageCache.h"
#import "MDMNotificationRequest.h"
#import "MDMContent.h"

#import "MDMInbox.h"
#import "MDMInboxItem.h"

//! Project version number for MDMNotification.
FOUNDATION_EXPORT double MDMNotificationVersionNumber;

//! Project version string for MDMNotification.
FOUNDATION_EXPORT const unsigned char MDMNotificationVersionString[];

@interface MDMNotification : MDMCoreModule

+ (void)start;
+ (void)registerToken:(NSString *)token;
+ (void)unregisterToken;
+ (BOOL)isAutoUpdateToken;
+ (void)setAutoUpdateToken:(BOOL)isAutoUpdateToken;
+ (BOOL)isOptOut;
+ (void)setOptOut:(BOOL)isOptOut;
+ (BOOL)isMDMNotification:(NSDictionary *)userInfo;
+ (void)processNotification:(NSDictionary *)userInfo completionBlock:(void (^)(UNNotificationPresentationOptions))completionBlock;
+ (void)receiveNotification:(NSDictionary *)userInfo;

@end
