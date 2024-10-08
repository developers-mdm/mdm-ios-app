//
//  MDMInboxTableViewCell.h
//  MDMNotification
//
//  Created by Robson Moreira on 07/11/19.
//  Copyright © 2019 Hands. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "MDMIInboxItem.h"
#import "MDMInboxTableViewDelegate.h"

@interface MDMInboxTableViewCell : UITableViewCell
    
@property(nonatomic, retain) id<MDMInboxTableViewDelegate> delegate;

- (void)setupViewCell:(MDMIInboxItem *)inboxItem;

@end
