//
//  MDMQueueDataModel.h
//  MDMCore
//
//  Created by Robson Moreira on 28/02/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import "MDMObjectModel.h"

@interface MDMQueueDataModel : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, retain) NSString *qId;
@property (nonatomic, retain) NSDate *date;
@property (nonatomic, retain) NSData *data;
@property (nonatomic, retain) NSString *url;
@property (nonatomic, retain) NSString *method;
@property (nonatomic, assign) BOOL priority;

- (instancetype)init:(NSDate *)date _:(NSData *)data _:(NSString *)url _:(NSString *)method _:(BOOL)priority;

@end
