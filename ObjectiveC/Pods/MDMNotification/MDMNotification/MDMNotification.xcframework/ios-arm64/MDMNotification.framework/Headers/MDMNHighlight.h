//
//  MDMNHighlight.h
//  MDMNotification
//
//  Created by Robson Moreira on 30/10/19.
//  Copyright © 2019 Hands. All rights reserved.
//

#import <MDMCore/MDMObjectModel.h>

@interface MDMNHighlight : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, assign) BOOL inbox;

@end
