//
//  MDMGeoBehavior.h
//  MDMGeoBehavior
//
//  Created by Robson Moreira on 15/02/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <MDMCore/MDMCore.h>
#import <CoreLocation/CoreLocation.h>

//! Project version number for MDMGeoBehavior.
FOUNDATION_EXPORT double MDMGeoBehaviorVersionNumber;

//! Project version string for MDMGeoBehavior.
FOUNDATION_EXPORT const unsigned char MDMGeoBehaviorVersionString[];

typedef NS_ENUM(NSInteger, MDMGeoInitStatus) {
    MDMStarted,
    MDMNotStarted,
    MDMAppNotAuthorized,
    MDMUserNotAuthorized
};

@interface MDMGeoBehavior : MDMCoreModule

+ (void)start;

+ (void)start:(void (^)(MDMGeoInitStatus))startHandler;

@end
