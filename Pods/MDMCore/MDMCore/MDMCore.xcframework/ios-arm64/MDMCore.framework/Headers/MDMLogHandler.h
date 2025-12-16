//
//  MDMLogHandler.h
//  AppTestLog
//
//  Created by Robson Moreira on 20/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>

#define LEVEL_CRITICAL  2
#define LEVEL_ERROR     3
#define LEVEL_WARNING   4
#define LEVEL_NOTICE    5

@interface MDMLogHandler : NSObject

+ (void)logToDebugWithText:(NSString *)logText;

+ (void)logToFile:(NSString *)fileName text:(NSString *)logText;

+ (void)logHttpRequestToFile:(NSString *)url request:(NSMutableURLRequest *)request response:(NSHTTPURLResponse *)response data:(NSData *)data time:(NSTimeInterval)time error:(NSError *)error;

+ (void)logError:(NSError *)error moduleName:(NSString *)moduleName logLevel:(int)logLevel;

+ (void)logException:(NSException *)exception moduleName:(NSString *)moduleName logLevel:(int)logLevel;

@end
