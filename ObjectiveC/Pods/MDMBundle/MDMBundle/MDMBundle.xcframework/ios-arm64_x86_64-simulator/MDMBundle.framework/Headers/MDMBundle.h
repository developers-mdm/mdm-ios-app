//
//  MDMBundle.h
//  MDMBundle
//
//  Created by Robson Moreira on 11/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <MDMCore/MDMCore.h>
#import <CoreLocation/CoreLocation.h>

//! Project version number for MDMBundle.
FOUNDATION_EXPORT double MDMBundleVersionNumber;

//! Project version string for MDMBundle.
FOUNDATION_EXPORT const unsigned char MDMBundleVersionString[];

@interface MDMBundle : MDMCoreModule

+ (void)start;

+ (void)start:(void (^)(void))startHandler;

@end
