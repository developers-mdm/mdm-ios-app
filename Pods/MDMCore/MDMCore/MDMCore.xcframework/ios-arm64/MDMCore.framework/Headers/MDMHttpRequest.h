//
//  MDMHttpRequest.h
//  MDMCore
//
//  Created by Robson Moreira on 16/02/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>

#define METHOD_GET                      @"GET"
#define METHOD_POST                     @"POST"
#define METHOD_PUT                      @"PUT"
#define METHOD_DELETE                   @"DELETE"

#define STATUS_CODE_OK                  200
#define STATUS_CODE_ACCEPTED            202
#define STATUS_CODE_BAD_REQUEST         400
#define STATUS_CODE_NOT_AUTHORIZED      401
#define STATUS_CODE_FORBIDDEN           403
#define STATUS_NOT_FOUND                404

struct MDMHttpResult {
    __unsafe_unretained NSData *result;
    int statusCode;
};

@interface MDMHttpRequest : NSObject

+ (NSError *)errorWithRequest:(struct MDMHttpResult)request;

+ (void)dataTaskWithUrl:(NSString *)url method:(NSString *)method data:(NSData *)data success:(void (^)(struct MDMHttpResult httpResult))success error:(void (^)(NSError *error))error;

+ (void)downloadWithUrl:(NSString *)url success:(void (^)(NSString *response, NSURL *location))success error:(void (^)(NSError *error))error;

+ (void)getAbsoluteUrl:(NSURL *)url success:(void (^)(NSURL *url))success error:(void (^)(NSError *error))error;

+ (void)extractResponse:(struct MDMHttpResult)result success:(void (^)(void))success error:(void (^)(int))error completion:(void (^)(void))completion;

+ (void)sendLogError:(NSError *)error;

@end
