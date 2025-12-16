//
//  MDMInboxConfig.h
//  MDMNotification
//
//  Created by Robson Moreira on 30/10/19.
//  Copyright © 2019 Hands. All rights reserved.
//

#import <MDMCore/MDMObjectModel.h>
#import "MDMInboxTab.h"

@interface MDMInboxConfig : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, retain) NSArray<MDMInboxTab> *activeTabs;
@property (nonatomic, assign) MDMInboxTab selectedTab;

@end
