//
//  MDMInboxViewDelegate.h
//  HandsMDM
//
//  Created by Robson Moreira on 24/10/19.
//  Copyright © 2019 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>

@class MDMInboxTabBarController;
@class MDMInboxTableViewCell;

@protocol MDMInboxTableViewDelegate<NSObject>

@required
@property(nonatomic, assign) BOOL isEditing;
@property(nonatomic, assign) BOOL allRead;

- (void)inboxTabBar:(MDMInboxTabBarController *)inboxTabBar setTableViewEditing:(BOOL)editing;

- (void)inboxTabBar:(MDMInboxTabBarController *)inboxTabBar setTableViewAllSelected:(BOOL)allSelected;

- (void)inboxTabBar:(MDMInboxTabBarController *)inboxTabBar readAction:(UIBarButtonItem *)sender;

- (void)inboxTabBar:(MDMInboxTabBarController *)inboxTabBar favoriteAction:(UIBarButtonItem *)sender isFavorite:(BOOL)favorite;

- (void)inboxTabBar:(MDMInboxTabBarController *)inboxTabBar deleteAction:(UIBarButtonItem *)sender;

- (void)inboxTabBar:(MDMInboxTabBarController *)inboxTabBar searchText:(NSString *)text;

- (void)openMenuSharedWithItens:(NSArray *)items;

- (void)showWebViewWithInboxItem:(MDMIInboxItem *)inboxItem gallery:(MDMGallery *)gallery;

@end
