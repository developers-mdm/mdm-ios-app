//
//  MDMEndPoint.h
//  HandsMDM
//
//  Created by Robson Moreira on 27/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDMEndPoint : NSObject

// EndPoint for Ad Module
+ (NSString *)adClusters;

// EndPoint for AppBehavior Module
+ (NSString *)appInit;

+ (NSString *)appInstalled;

+ (NSString *)appOptIn;

// EndPoint for Config Module
+ (NSString *)config;

// EndPoint for Core Module
+ (NSString *)coreInit;

// EndPoint for DataBehavior Module
+ (NSString *)dataBehavior;

// EndPoint for DeviceBehavior Module
+ (NSString *)deviceInit;

+ (NSString *)deviceBehavior;

// EndPoint for GeoBehavior Module
+ (NSString *)geoInit;

+ (NSString *)geoLive;

+ (NSString *)geoBehavior;

+ (NSString *)geoOptIn;

// EndPoint for Notification Module
+ (NSString *)notificationToken;

+ (NSString *)notificationOptIn;

+ (NSString *)reportOpen;

+ (NSString *)reportDeliver;

+ (NSString *)reportInteraction;

// EndPoint for Inbox Module
+ (NSString *)reportInboxStatus;

+ (NSString *)reportInboxShare;
+ (NSString *)reportCoupon;

+ (NSString *)reportInboxDelete;

// EndPoint Others
+ (NSString *)graylogGelf;



@end
