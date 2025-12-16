//
//  MDMImageCache.h
//  MDMNotification
//
//  Created by Robson Moreira on 21/01/20.
//  Copyright © 2020 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDMImageCache : NSObject

+ (void)resetCache;

+ (void)removeObjectForKey:(NSString *)key;

+ (void)setObject:(NSData *)data forKey:(NSString *)key;

+ (id)objectForKey:(NSString *)key;

@end
