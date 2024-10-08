//
//  MDMGallery.h
//  HandsMDM
//
//  Created by Robson Moreira on 23/07/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import "MDMNotification.h"

@interface MDMGallery : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, retain) NSNumber *_id;
@property (nonatomic, retain) NSString *picture;
@property (nonatomic, retain) NSString *caption;
@property (nonatomic, retain) NSString *url;
@property (nonatomic, retain) NSData *data;

- (void)downloadImage;

@end
