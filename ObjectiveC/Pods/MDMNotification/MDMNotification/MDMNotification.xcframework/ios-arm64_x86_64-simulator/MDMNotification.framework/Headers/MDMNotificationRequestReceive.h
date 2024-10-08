//
//  MDMNotificationRequestReceived.h
//  MDMNotification
//
//  Created by Phelipe Lopes on 08/08/23.
//  Copyright © 2023 Hands. All rights reserved.
//

#import <MDMCore/MDMObjectModel.h>
#import "MDMNAlert.h"
#import "MDMNData.h"
#import "MDMNAps.h"

@interface MDMNotificationRequestReceive : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, retain) MDMNData *data;
@property (nonatomic, retain) MDMNAps *aps;

@end
