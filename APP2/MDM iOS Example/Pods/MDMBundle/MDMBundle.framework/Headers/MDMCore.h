//
//  MDMCore.h
//  MDMCore
//
//  Created by Robson Moreira on 15/02/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "MDMCoreDelegate.h"

//! Project version number for MDMCore.
FOUNDATION_EXPORT double MDMCoreVersionNumber;

//! Project version string for MDMCore.
FOUNDATION_EXPORT const unsigned char MDMCoreVersionString[];

@interface MDMCore : NSObject

+ (NSOperationQueue *)getOperationQueue;

+ (void)setDebugMode:(BOOL)debugMode;

+ (BOOL)isInDebugMode;

+ (BOOL)isUser;

+ (void)askBackendPermissionToStartService:(id<MDMCoreDelegate>)delegate;

+ (void)setData:(NSString *)key value:(NSString *)value encrypted:(BOOL)encrypted;

+ (void)setPUC:(NSString *)cpf;

+ (void)setPUE:(NSString *)email;

+ (void)setPUT:(NSString *)phone;

+ (void)setExternalID:(NSString *)externalId;

+ (void)track:(void (^)(NSMutableArray *mdmAudience))trackFinishesHandler;

+ (NSString *)getAdvertiserId;

@end
