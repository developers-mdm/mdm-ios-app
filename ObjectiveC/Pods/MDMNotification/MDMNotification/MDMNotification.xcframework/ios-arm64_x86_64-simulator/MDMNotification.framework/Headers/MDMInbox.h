//
//  MDMInbox.h
//  MDMNotification
//
//  Created by Robson Moreira on 21/10/19.
//  Copyright © 2019 Hands. All rights reserved.
//

#import <MDMCore/MDMCore.h>

@interface MDMInbox : NSObject

+ (NSString *)getTitle;

+ (void)setTitle:(NSString *)title;

+ (UIColor *)getNavigationBarColor;

+ (void)setNavigationBarColor:(NSString *)navigationBarColor;

+ (UIColor *)getBackgroundColor;

+ (void)setBackgroundColor:(NSString *)backgroundColor;

+ (UIColor *)getTabBarColor;

+ (void)setTabBarColor:(NSString *)tabBarColor;

+ (UIColor *)getTintColor;

+ (void)setTintColor:(NSString *)tintColor;

@end
