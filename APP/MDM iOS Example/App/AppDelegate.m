//
//  AppDelegate.m

//  Copyright ©. All rights reserved.
//

#import "AppDelegate.h"
#import <sys/utsname.h>
#import <MDMBundle/MDMBundle.h>

@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
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
    
    
    UNUserNotificationCenter *center = [UNUserNotificationCenter currentNotificationCenter];
    [center requestAuthorizationWithOptions:(UNAuthorizationOptionAlert + UNAuthorizationOptionSound) completionHandler:^(BOOL granted, NSError * _Nullable error) {
        // Enable or disable features based on authorization.
    }];
    [application registerForRemoteNotifications];

    
    return YES;
}

- (void)application:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData*)deviceToken {
    NSString *token = [[[[deviceToken description] stringByReplacingOccurrencesOfString: @"<" withString: @""] stringByReplacingOccurrencesOfString: @">" withString: @""] stringByReplacingOccurrencesOfString: @" " withString: @""] ;
    [MDMNotification registerTokenForPushNotification:token];
}

- (void)application:(UIApplication *)app didFailToRegisterForRemoteNotificationsWithError:(NSError *)err {
    [MDMNotification unregisterTokenForPushNotification];
}

- (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler {
    [MDMNotification processNotification:userInfo];
    completionHandler(UIBackgroundFetchResultNewData);
}

- (void)applicationWillResignActive:(UIApplication *)application {
}

- (void)applicationDidEnterBackground:(UIApplication *)application {
}

- (void)applicationWillEnterForeground:(UIApplication *)application {
}

- (void)applicationDidBecomeActive:(UIApplication *)application {
}

- (void)applicationWillTerminate:(UIApplication *)application {
//    [self.MBHSharedManager restartMonitoringVisits];
}

@end
