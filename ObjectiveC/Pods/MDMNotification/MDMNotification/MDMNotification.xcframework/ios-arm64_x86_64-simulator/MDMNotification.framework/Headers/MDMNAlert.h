//
//  MDMNAlert.h
//  MDMNotification
//
//  Created by Robson Moreira on 30/10/19.
//  Copyright © 2019 Hands. All rights reserved.
//

#import <MDMCore/MDMObjectModel.h>

@interface MDMNAlert : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, retain) NSString *title;
@property (nonatomic, retain) NSString *body;

@end
