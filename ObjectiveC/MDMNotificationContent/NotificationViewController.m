//
//  NotificationViewController.m
//  MDMNotificationContent
//
//  Created by Jorge Silveira on 06/09/18.
//  Copyright © 2018 Rogerio. All rights reserved.
//

#import "NotificationViewController.h"

@implementation NotificationViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any required interface initialization here.
}

- (void)didReceiveNotification:(UNNotification *)notification {
    self.isHandsPush = [MDMNotification isMDMNotification:notification.request.content.userInfo];

    if (self.isHandsPush) {
        [super didReceiveNotification:notification];
    } else {
        // Your code here
    }
}

- (void)didReceiveNotificationResponse:(UNNotificationResponse *)response completionHandler:(void (^)(UNNotificationContentExtensionResponseOption))completion {
    
    if (self.isHandsPush) {
        [super didReceiveNotificationResponse:response completionHandler:completion];
    } else {
        // Your code here
    }
    
}

@end
