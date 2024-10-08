//
//  MDMNotificationViewController.h
//  HandsMDM
//
//  Created by Robson Moreira on 19/07/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>

@interface MDMNotificationViewController : UIViewController <UNNotificationContentExtension, UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>

@property (nonatomic, strong) UICollectionView *collectionView;
@property (nonatomic, assign) NSInteger currentIndex;
@property (nonatomic, assign) BOOL isHandsPush;

@end
