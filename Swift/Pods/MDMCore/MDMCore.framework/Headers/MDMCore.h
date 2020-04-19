//
//  MDMCore.h
//  MDMCore
//
//  Created by Robson Moreira on 15/02/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "MDMCoreModule.h"

//! Project version number for MDMCore.
FOUNDATION_EXPORT double MDMCoreVersionNumber;

//! Project version string for MDMCore.
FOUNDATION_EXPORT const unsigned char MDMCoreVersionString[];

@interface MDMCore : NSObject

+ (void)setDebugMode:(BOOL)debugMode;

+ (BOOL)isInDebugMode;

+ (BOOL)isStarted;

+ (void)startWithAppId:(NSString *)appId kitModules:(NSArray<MDMCoreModule *> *)kitModules;

+ (void)restart;

+ (NSString *)getIOSAdvertisingId;

@end
