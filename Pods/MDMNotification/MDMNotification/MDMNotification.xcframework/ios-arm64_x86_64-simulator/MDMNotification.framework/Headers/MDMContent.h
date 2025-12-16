//
//  MDMContent.h
//  MDMNotification
//
//  Created by Robson Moreira on 02/10/19.
//  Copyright © 2019 Hands. All rights reserved.
//

#import <MDMCore/MDMObjectModel.h>
#import "MDMNHighlight.h"
#import "MDMWebView.h"
#import "MDMInboxConfig.h"
#import "MDMGallery.h"

@interface MDMContent : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, retain) MDMNHighlight *highlight;
@property (nonatomic, retain) MDMInboxConfig *inbox;
@property (nonatomic, retain) MDMWebView *webview;
@property (nonatomic, retain) NSArray<MDMGallery *> *gallery;

@end
