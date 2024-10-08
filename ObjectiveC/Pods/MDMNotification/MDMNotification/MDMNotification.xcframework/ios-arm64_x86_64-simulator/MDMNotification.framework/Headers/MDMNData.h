//
//  MDMNData.h
//  HandsMDM
//
//  Created by Robson Moreira on 23/07/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <MDMCore/MDMObjectModel.h>
#import "MDMNContent.h"

@interface MDMNData : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, retain) NSString *_id;
@property (nonatomic, retain) NSString *pushIdentifier;
@property (nonatomic, retain) NSDate *dateTime;
@property (nonatomic, assign) BOOL avoidAutoOpen;
@property (nonatomic, retain) NSString *sender;
@property (nonatomic, retain) NSString *campaign;
@property (nonatomic, retain) NSString *pushset;
@property (nonatomic, retain) NSString *attachement;
@property (nonatomic, retain) NSDate *dateStart;
@property (nonatomic, retain) NSDate *dateEnd;
@property (nonatomic, retain) NSArray<NSString *> *features;
@property (nonatomic, retain) MDMNContent *content;
@property (nonatomic, retain) NSArray<NSString *> * conversionTrackingURL;

@end
