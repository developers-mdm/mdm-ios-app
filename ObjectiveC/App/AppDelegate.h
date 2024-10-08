//
//  AppDelegate.h

//  Copyright ©. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <AppTrackingTransparency/AppTrackingTransparency.h>

// Hands MDM imports
#import <MDMCore/MDMCore.h>
#import <MDMBundle/MDMBundle.h>
#import <MDMGeoBehavior/MDMGeoBehavior.h>
#import <MDMAppBehavior/MDMAppBehavior.h>
#import <MDMNotification/MDMNotification.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;
@property (strong, nonatomic) CLLocationManager *locationManager;
@property (strong, nonatomic) UNUserNotificationCenter *notificationCenter;

@end



