//
//  AppDelegate.m

//  Copyright ©. All rights reserved.
//

#import "AppDelegate.h"

#define kAppId @"ZF4ab16J6tT77b28OvH2AAwoqmlKQQRuz204O3maL/4j/9fO9DGzP71goK/BNNGh8DlqvN/k3sgsNaSzEPFGbbfUMjnLVjR9783dbyeuS+pzRL8LLXyTnrkY9ZfiVWmkupHiR2iMzBqQwhVidugTKu7xW7OJNJck1ZLawu+1cEvGz4YxwCOmkhp9Y2ygOQRqGIpuzA/TqyLc4+/PET9wGkrl8RbjHYgtJto+hVLwj3KuKEoLxyzpKcxWaDSiu1lhbJQSgWMMdiQ9zIYiE4BXBj1vKWh8YsB9P034oOWJk6LZ/hiXbEu+ZxbuNo3jHyu4VYRHqTocfyglF13RWj2bFA=="

@interface AppDelegate () <CLLocationManagerDelegate, UNUserNotificationCenterDelegate>

@end

@implementation AppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    
    // Debug Mode
    [MDMCore setDebugMode:YES];
    
    // Start do Bundle com todos os módulos
    [MDMCore startWithAppId:kAppId kitModules:@[[MDMBundle self]]];
    
    //
    // OU
    //
    
    // Start de cada módulo separadamente
//    [MDMCore startWithAppId:kAppId kitModules:@[
//        [MDMGeoBehavior self],
//        [MDMAppBehavior self],
//        [MDMNotification self]
//    ]];
    
//    self.locationManager = [[CLLocationManager alloc] init];
//    self.locationManager.delegate = self;
//    switch ([CLLocationManager authorizationStatus]) {
//        case kCLAuthorizationStatusNotDetermined:
//        case kCLAuthorizationStatusRestricted:
//        case kCLAuthorizationStatusDenied:
//            [self.locationManager requestAlwaysAuthorization];
//            break;
//        default:
//            break;
//    }
    
    self.notificationCenter = [UNUserNotificationCenter currentNotificationCenter];
    self.notificationCenter.delegate = self;
    [self.notificationCenter requestAuthorizationWithOptions:(UNAuthorizationOptionAlert + UNAuthorizationOptionSound) completionHandler:^(BOOL granted, NSError * _Nullable error) {
        if (granted) {
            [[NSOperationQueue mainQueue] addOperationWithBlock:^{
         //       if (![application isRegisteredForRemoteNotifications]) {
                    [application registerForRemoteNotifications];
           //     }
            }];
        }
    }];
   
    // Customização do Inbox
    [MDMInbox setTitle:@"My Inbox"];
    [MDMInbox setNavigationBarColor:@"#312683"];
    [MDMInbox setTabBarColor:@"#312683"];
    [MDMInbox setTintColor:@"#C8D400"];
    [MDMInbox setBackgroundColor:@"#312683"];
    
    return YES;
}

//- (void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status {
//    if (status == kCLAuthorizationStatusAuthorizedAlways || status == kCLAuthorizationStatusAuthorizedWhenInUse) {
//        [MDMGeoBehavior start];
//    }
//}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken {
    [MDMNotification registerToken:deviceToken];
}

- (void)application:(UIApplication *)app didFailToRegisterForRemoteNotificationsWithError:(NSError *)err {
    [MDMNotification unregisterToken];
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center didReceiveNotificationResponse:(UNNotificationResponse *)response withCompletionHandler:(void (^)(void))completionHandler {
    
    NSDictionary *userInfo = response.notification.request.content.userInfo;
    if ([MDMNotification isMDMNotification:userInfo]) {
        [MDMNotification processNotification:userInfo];
    } else {
        // Process your notification here
    }
    
    
}

- (void)userNotificationCenter:(UNUserNotificationCenter *)center willPresentNotification:(UNNotification *)notification withCompletionHandler:(void (^)(UNNotificationPresentationOptions))completionHandler {
    
    NSDictionary *userInfo = notification.request.content.userInfo;
    if ([MDMNotification isMDMNotification:userInfo]) {
        [MDMNotification processNotification:userInfo];
    } else {
        // Open your notification here
    }
    
}

@end
