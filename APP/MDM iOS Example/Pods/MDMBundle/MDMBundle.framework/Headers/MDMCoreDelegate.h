//
//  MDMCoreDelegate.h
//  HandsMDM
//
//  Created by Robson Moreira on 27/02/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

@protocol MDMCoreDelegate<NSObject>

@optional

- (void)mdmCoreCalling:(NSString *)calling didBackendPermission:(BOOL)canRun;

+ (void)mdmCoreCalling:(NSString *)calling didBackendPermission:(BOOL)canRun;

@end

