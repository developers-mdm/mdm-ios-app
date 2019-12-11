//
//  AppDelegate.m

//  Copyright ©. All rights reserved.
//

#import "AppDelegate.h"

@interface AppDelegate () <CLLocationManagerDelegate, UNUserNotificationCenterDelegate>

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
    // [MDMNotification start];
    
    self.locationManager = [[CLLocationManager alloc] init];
    self.locationManager.delegate = self;
    switch ([CLLocationManager authorizationStatus]) {
        case kCLAuthorizationStatusNotDetermined:
        case kCLAuthorizationStatusRestricted:
        case kCLAuthorizationStatusDenied:
            [self.locationManager requestAlwaysAuthorization];
            break;
        default:
            break;
    }
    
    self.notificationCenter = [UNUserNotificationCenter currentNotificationCenter];
    self.notificationCenter.delegate = self;
    [self.notificationCenter requestAuthorizationWithOptions:(UNAuthorizationOptionAlert + UNAuthorizationOptionSound) completionHandler:^(BOOL granted, NSError * _Nullable error) {
        if (granted) {
            [[NSOperationQueue mainQueue] addOperationWithBlock:^{
                if (![application isRegisteredForRemoteNotifications]) {
                    [application registerForRemoteNotifications];
                }
            }];
        }
    }];
    
    return YES;
}

- (void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status {
    if (status == kCLAuthorizationStatusAuthorizedAlways || status == kCLAuthorizationStatusAuthorizedWhenInUse) {
        [MDMGeoBehavior start];
    }
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
        [MDMNotification processNotification:userInfo];
    } else {
        // Process your notification here
    }
    completionHandler();
    
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
