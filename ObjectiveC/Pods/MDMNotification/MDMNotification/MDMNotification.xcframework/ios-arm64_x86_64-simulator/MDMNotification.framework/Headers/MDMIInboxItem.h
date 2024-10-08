//
//  MDMIInboxItem.h
//  MDMNotification
//
//  Created by Robson Moreira on 30/10/19.
//  Copyright © 2019 Hands. All rights reserved.
//

#import <MDMCore/MDMObjectModel.h>
#import "MDMNotificationRequestReceive.h"

typedef NS_ENUM(NSInteger, MDMIInboxStatus) {
    MDMINew,
    MDMIBookmark,
    MDMIArchived
};

extern NSString * const MDMIInboxStatus_toString[];

@interface MDMIInboxItem : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, retain) MDMNotificationRequestReceive *notificationReceive;
@property (nonatomic, assign) BOOL unread;
@property (nonatomic, assign) MDMIInboxStatus status;

- (instancetype)initWithAps:(MDMNotificationRequestReceive *)aps;

@end
