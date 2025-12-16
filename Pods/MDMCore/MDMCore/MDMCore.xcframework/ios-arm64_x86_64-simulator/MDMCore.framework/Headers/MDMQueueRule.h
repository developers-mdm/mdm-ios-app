//
//  MDMQueueModel.h
//  MDMCore
//
//  Created by Robson Moreira on 03/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import "MDMQueueModel.h"

@interface MDMQueueRule : NSObject

+ (instancetype)sharedInstance;

- (void)enqueue:(NSString *)url
           data:(NSData *)data
         method:(NSString *)method
           date:(NSDate *)date
       priority:(BOOL)priority;

- (void)enqueue:(NSString *)url
           data:(NSData *)data
         method:(NSString *)method
           date:(NSDate *)date
       priority:(BOOL)priority
     completion:(void (^ __nullable)(void))completion;

- (MDMQueueModel *)getQueue;

- (void)removeData:(MDMQueueDataModel *)mdmQueueDataModel;
    
- (void)refreshQueue:(MDMQueueModel *)renewedQueue;

- (void)startQueue;

@end
