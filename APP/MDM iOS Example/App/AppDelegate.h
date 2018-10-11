//
//  AppDelegate.h

//  Copyright ©. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UserNotifications/UserNotifications.h>
#import <UserNotificationsUI/UserNotificationsUI.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate, UNUserNotificationCenterDelegate>

@property (strong, nonatomic) UIWindow *window;

@end



