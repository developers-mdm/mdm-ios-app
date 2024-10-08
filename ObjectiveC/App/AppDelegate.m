//
//  AppDelegate.m

//  Copyright ©. All rights reserved.
//

#import "AppDelegate.h"

#define kAppId @"YOU_APP_ID"

@interface AppDelegate () <CLLocationManagerDelegate, UNUserNotificationCenterDelegate>

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    _locationManager = [[CLLocationManager alloc] init];
    _locationManager.delegate = self;
    
    _notificationCenter = [UNUserNotificationCenter currentNotificationCenter];
    _notificationCenter.delegate = self;
    
    // Debug Mode
    [MDMCore setDebugMode:YES];
    
    return YES;
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
    [ATTrackingManager requestTrackingAuthorizationWithCompletionHandler:^(ATTrackingManagerAuthorizationStatus status) {
        if (status == ATTrackingManagerAuthorizationStatusAuthorized) {
            // Iniciar o Bundle com todos os módulos
            [MDMCore startWithAppId:kAppId kitModules:@[[MDMBundle self]]];

            //
            // OU
            //

            // Iniciar dos módulos separadamente
//            [MDMCore startWithAppId:kAppId kitModules:@[
//                [MDMGeoBehavior self],
//                [MDMAppBehavior self],
//                [MDMNotification self]
//            ]];

            // MDM Notification
            [self.notificationCenter requestAuthorizationWithOptions:(UNAuthorizationOptionAlert + UNAuthorizationOptionSound) completionHandler:^(BOOL granted, NSError * _Nullable error) {
                // Customização do Inbox
                [MDMInbox setTitle:@"My Inbox"];
                [MDMInbox setNavigationBarColor:@"#312683"];
                [MDMInbox setTabBarColor:@"#312683"];
                [MDMInbox setTintColor:@"#C8D400"];
                [MDMInbox setBackgroundColor:@"#312683"];
                
                if (granted) {
                    [[NSOperationQueue mainQueue] addOperationWithBlock:^{
                        [application registerForRemoteNotifications];
                    }];
                }
            }];
            
            // MDM Geo
            switch (self.locationManager.authorizationStatus) {
                case kCLAuthorizationStatusNotDetermined:
                case kCLAuthorizationStatusDenied:
                case kCLAuthorizationStatusRestricted:
                    [self.locationManager requestAlwaysAuthorization];
                    break;
                case kCLAuthorizationStatusAuthorizedAlways:
                case kCLAuthorizationStatusAuthorizedWhenInUse:
                    break;
                default:
                    break;
            }
        }
    }];
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Iniciar o Bundle com todos os módulos
    [MDMCore startWithAppId:kAppId kitModules:@[[MDMBundle self]]];

    //
    // OU
    //

    // Iniciar dos módulos separadamente
//    [MDMCore startWithAppId:kAppId kitModules:@[
//        [MDMGeoBehavior self],
//        [MDMAppBehavior self],
//        [MDMNotification self]
//    ]];
}

- (void)applicationWillTerminate:(UIApplication *)application {
    // Iniciar o Bundle com todos os módulos
    [MDMCore startWithAppId:kAppId kitModules:@[[MDMBundle self]]];

    //
    // OU
    //

    // Iniciar dos módulos separadamente
//    [MDMCore startWithAppId:kAppId kitModules:@[
//        [MDMGeoBehavior self],
//        [MDMAppBehavior self],
//        [MDMNotification self]
//    ]];
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken {
    [MDMNotification registerToken:deviceToken];
}

- (void)application:(UIApplication *)app didFailToRegisterForRemoteNotificationsWithError:(NSError *)err {
    [MDMNotification unregisterToken];
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)(void))completionHandler {
    NSDictionary *userInfo = response.notification.request.content.userInfo;
    if ([MDMNotification isMDMNotification:userInfo]) {
        [MDMNotification receiveNotification:userInfo];
    } else {
        // Process your notification here
    }
    completionHandler();
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler {
    NSDictionary *userInfo = notification.request.content.userInfo;
    if ([MDMNotification isMDMNotification:userInfo]) {
        [MDMNotification processNotification:userInfo completionBlock:completionHandler];
    } else {
        // Open your notification here
    }
}

- (void)locationManagerDidChangeAuthorization:(CLLocationManager *)manager {
    if ([manager authorizationStatus] == kCLAuthorizationStatusAuthorizedAlways || [manager authorizationStatus] == kCLAuthorizationStatusAuthorizedWhenInUse) {
        [MDMGeoBehavior start];
    }
}

@end
