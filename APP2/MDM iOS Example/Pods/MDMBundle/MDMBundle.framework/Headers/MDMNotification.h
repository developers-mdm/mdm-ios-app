//
//  MDMNotification.h
//  MDMNotification
//
//  Created by Robson Moreira on 10/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for MDMNotification.
FOUNDATION_EXPORT double MDMNotificationVersionNumber;

//! Project version string for MDMNotification.
FOUNDATION_EXPORT const unsigned char MDMNotificationVersionString[];

@interface MDMNotification : NSObject

+ (void)start;

+ (BOOL)processNotification:(NSDictionary *)dictionaryData;

+ (void)registerTokenForPushNotification:(NSString *)token;

+ (void)unregisterTokenForPushNotification;

@end
