//
//  MDMNotificationRequest.h
//  MDMNotification
//
//  Created by Robson Moreira on 11/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDMNotificationRequest: NSObject

+ (void)sendOptInInDictionary:(NSDictionary *)dictionary success:(void (^)(void))success error:(void (^)(int))error completion:(void (^)(void))completion;

+ (void)sendTokenInDictionary:(NSDictionary *)dictionary success:(void (^)(void))success error:(void (^)(int))error completion:(void (^)(void))completion;

+ (void)removeTokenWithSuccess:(void (^)(void))success error:(void (^)(int))error completion:(void (^)(void))completion;

+ (void)sendDeliverInDictionary:(NSDictionary *)dictionary success:(void (^)(void))success error:(void (^)(int))error completion:(void (^)(void))completion;

+ (void)sendOpenInDictionary:(NSDictionary *)dictionary success:(void (^)(void))success error:(void (^)(int))error completion:(void (^)(void))completion;

+ (void)sendInteractionInDictionary:(NSDictionary *)dictionary success:(void (^)(void))success error:(void (^)(int))error completion:(void (^)(void))completion;

+ (void)downloadImage:(NSString *)url completionHandler:(void (^)(NSData *data, NSError *error))completionHandler;

+ (void)downloadAttachement:(NSString *)url completionHandler:(void (^)(UNNotificationAttachment *attachment, NSError *error))completionHandler;

+ (void)resolveUrl:(NSURL *)url completionHandler:(void (^)(NSURL *url, NSError *error))completionHandler;

+ (void)getCoupons:(void (^)(NSData *, NSError *))completionHandler;
@end
