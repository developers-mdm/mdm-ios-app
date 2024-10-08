//
//  MDMNAps.h
//  MDMNotification
//
//  Created by Robson Moreira on 30/10/19.
//  Copyright © 2019 Hands. All rights reserved.
//

#import <MDMCore/MDMObjectModel.h>
#import "MDMNAlert.h"
#import "MDMNData.h"

@interface MDMNAps : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, retain) MDMNAlert *alert;
@property (nonatomic, retain) NSString *category;

@end
