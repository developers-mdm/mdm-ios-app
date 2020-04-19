//
//  MDMAppBehavior.h
//  MDMAppBehavior
//
//  Created by Robson Moreira on 08/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <MDMCore/MDMCore.h>

//! Project version number for MDMAppBehavior.
FOUNDATION_EXPORT double MDMAppBehaviorVersionNumber;

//! Project version string for MDMAppBehavior.
FOUNDATION_EXPORT const unsigned char MDMAppBehaviorVersionString[];

typedef NS_ENUM(NSInteger, MDMAppInitStatus) {
    MDMStarted,
    MDMNotStarted,
    MDMAppNotAuthorized,
    MDMUserNotAuthorized
};

@interface MDMAppBehavior : MDMCoreModule

+ (void)start;

@end
