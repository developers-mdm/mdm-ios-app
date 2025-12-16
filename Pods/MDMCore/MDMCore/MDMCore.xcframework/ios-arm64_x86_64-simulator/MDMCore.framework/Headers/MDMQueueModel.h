//
//  MDMQueueModel.h
//  MDMCore
//
//  Created by Robson Moreira on 28/02/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import "MDMObjectModel.h"
#import "MDMQueueDataModel.h"

@interface MDMQueueModel : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, retain) NSArray<MDMQueueDataModel *> *data;

- (void)addData:(MDMQueueDataModel *)item;

- (void)removeData:(MDMQueueDataModel *)item;

@end
