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
+ (void)setNavigationBarColorWithHex:(NSString *)hexColor NS_SWIFT_NAME(setNavigationBarColor(hex:));
+ (void)setNavigationBarColorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue NS_SWIFT_NAME(setNavigationBarColor(red:green:blue:));
+ (void)setNavigationBarColorWithColor:(UIColor *)color NS_SWIFT_NAME(setNavigationBarColor(color:));

+ (UIColor *)getNavigationItemColor;
+ (void)setNavigationItemColorWithHex:(NSString *)hexColor NS_SWIFT_NAME(setNavigationItemColor(hex:));
+ (void)setNavigationItemColorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue NS_SWIFT_NAME(setNavigationItemColor(red:green:blue:));
+ (void)setNavigationItemColorWithColor:(UIColor *)color NS_SWIFT_NAME(setNavigationItemColor(color:));

+ (UIColor *)getBackgroundColor;
+ (void)setBackgroundColorWithHex:(NSString *)hexColor NS_SWIFT_NAME(setBackgroundColor(hex:));
+ (void)setBackgroundColorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue NS_SWIFT_NAME(setBackgroundColor(red:green:blue:));
+ (void)setBackgroundColorWithColor:(UIColor *)color NS_SWIFT_NAME(setBackgroundColor(color:));

//+ (UIColor *)getSegmentedControlColor;
//+ (void)setSegmentedControlColorColorWithHex:(NSString *)hexColor;
//+ (void)setSegmentedControlColorColorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue;
//+ (void)setSegmentedControlColorColorWithColor:(UIColor *)color;
//
//+ (UIColor *)getTabBarColor;
//+ (void)setTabBarColorWithHex:(NSString *)hexColor NS_SWIFT_NAME(setTabBarColor(hex:));
//+ (void)setTabBarColorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue NS_SWIFT_NAME(setTabBarColor(red:green:blue:));
//+ (void)setTabBarColorWithColor:(UIColor *)color NS_SWIFT_NAME(setTabBarColor(color:));

+ (UIColor *)getTextColor;
+ (void)setTextColorWithHex:(NSString *)hexColor NS_SWIFT_NAME(setTextColor(hex:));
+ (void)setTextColorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue NS_SWIFT_NAME(setTextColor(red:green:blue:));
+ (void)setTextColorWithColor:(UIColor *)color NS_SWIFT_NAME(setTextColor(color:));

+ (UIColor *)getTintColor;
+ (void)setTintColorWithHex:(NSString *)hexColor NS_SWIFT_NAME(setTintColor(hex:));
+ (void)setTintColorWithRed:(CGFloat)red green:(CGFloat)green blue:(CGFloat)blue NS_SWIFT_NAME(setTintColor(red:green:blue:));
+ (void)setTintColorWithColor:(UIColor *)color NS_SWIFT_NAME(setTintColor(color:));

+ (void)setActiveTabs:(NSArray<MDMInboxTab> *)activeTabs;
+ (NSArray<MDMInboxTab> *)getActiveTabs;

// Remover após lançar a versão e corrigir
+ (void)setInboxConfig:(MDMInboxConfig *)inboxConfig;
+ (MDMInboxConfig *)geInboxConfig;

@end
