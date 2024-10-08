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

@interface MDMGeoBehavior : MDMCoreModule

+ (void)start;

+ (NSObject*)getGeo;

+ (void)start:(void (^)(void))startHandler;

+ (BOOL)isOptOut;

+ (void)setOptOut:(BOOL)isOptOut;

@end
