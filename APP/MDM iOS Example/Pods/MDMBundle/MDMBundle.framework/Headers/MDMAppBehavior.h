//
//  MDMAppBehavior.h
//  MDMAppBehavior
//
//  Created by Robson Moreira on 08/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>

//! Project version number for MDMAppBehavior.
FOUNDATION_EXPORT double MDMAppBehaviorVersionNumber;

//! Project version string for MDMAppBehavior.
FOUNDATION_EXPORT const unsigned char MDMAppBehaviorVersionString[];

#define MODULE_APP @"mdm-appbehavior"

@interface MDMAppBehavior : NSObject

+ (void)start;

@end
