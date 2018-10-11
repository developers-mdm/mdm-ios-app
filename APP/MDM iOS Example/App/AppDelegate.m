//
//  AppDelegate.m

//  Copyright ©. All rights reserved.
//

#import "AppDelegate.h"
#import <sys/utsname.h>
#import <MDMBundle/MDMBundle.h>
#import <MDMCore/MDMCore.h>
@import UserNotifications;

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // Debug Mode
    [MDMCore setDebugMode:YES];
    
    // Start do Bundle com todos os módulos
    [MDMBundle start];
    
    //
    // OU
    //
    
    // Start de cada módulo separadamente
    // [MDMGeoBehavior start];
    // [MDMAppBehavior start];
    // [MDMAd start];
    // [MDMNotification start];
    
    
    if (@available(iOS 10.0, *)) {
        UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
        [center requestAuthorizationWithOptions:(UNAuthorizationOptionAlert + UNAuthorizationOptionBadge + UNAuthorizationOptionSound) completionHandler:^(BOOL granted, NSError * _Nullable error) {
            if (granted) {
                [[NSOperationQueue mainQueue] addOperationWithBlock:^{
                    if (![application isRegisteredForRemoteNotifications]) {
                        [application registerForRemoteNotifications];
                        [MDMNotification start];
                    }
                }];
            }
        }];
    } else {
        if ([application respondsToSelector:@selector(registerUserNotificationSettings:)]) {
            UIUserNotificationSettings *settings = [UIUserNotificationSettings settingsForTypes:UIUserNotificationTypeAlert | UIUserNotificationTypeBadge | UIUserNotificationTypeSound categories:nil];
            [application registerUserNotificationSettings:settings];
            if (![application isRegisteredForRemoteNotifications]) {
                [application registerForRemoteNotifications];
                [MDMNotification start];
            }
        }
    }
    
    return YES;
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken {
    [MDMNotification registerToken:deviceToken];
}

- (void)application:(UIApplication *)app didFailToRegisterForRemoteNotificationsWithError:(NSError *)err {
    [MDMNotification unregisterToken];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    if ([MDMNotification isMDMNotification:userInfo]) {
        [MDMNotification processNotification:userInfo];
    } else {
        // Process your notification here
    }
    completionHandler(UIBackgroundFetchResultNewData);
}

@end
