//
//  MDMNotification.h
//  MDMNotification
//
//  Created by Robson Moreira on 10/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <MDMCore/MDMCore.h>
#import <UserNotifications/UserNotifications.h>
#import "MDMInboxTableViewCell.h"
#import "MDMNotificationService.h"
#import "MDMNotificationViewController.h"
#import "MDMInbox.h"
#import "MDMInboxItemTableViewCell.h"
#import "MDMImageCache.h"
#import "MDMNotificationRequest.h"
#import "MDMNContent.h"
#import <NotificationCenter/NotificationCenter.h>

//! Project version number for MDMNotification.
FOUNDATION_EXPORT double MDMNotificationVersionNumber;

//! Project version string for MDMNotification.
FOUNDATION_EXPORT const unsigned char MDMNotificationVersionString[];

@interface MDMNotification : MDMCoreModule

+ (void)start;

+ (void)start:(void (^)(void))startHandler;

+ (BOOL)isOptOut;

+ (void)setOptOut:(BOOL)isOptOut;

+ (void)registerToken:(NSData *)token;

+ (NSString*)getToken;

+ (void)unregisterToken;

+ (BOOL)isMDMNotification:(NSDictionary *)userInfo;

+ (void)processNotification:(NSDictionary *)userInfo completionBlock:(void (^)(UNNotificationPresentationOptions))completionBlock;

+ (void)receiveNotification:(NSDictionary *)userInfo;

@end
