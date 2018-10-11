//
//  NotificationService.m
//  MDMNotificationService
//
//  Created by Jorge Silveira on 06/09/18.
//  Copyright © 2018 Rogerio. All rights reserved.
//

#import "NotificationService.h"

@interface NotificationService ()

@property (nonatomic, strong) void (^contentHandler)(UNNotificationContent *contentToDeliver);
@property (nonatomic, strong) UNMutableNotificationContent *bestAttemptContent;

@end

@implementation NotificationService

- (void)didReceiveNotificationRequest:(UNNotificationRequest *)request withContentHandler:(void (^)(UNNotificationContent * _Nonnull))contentHandler {
    self.contentHandler = contentHandler;
    self.bestAttemptContent = [request.content mutableCopy];
    
    if ([MDMNotification isMDMNotification:self.bestAttemptContent.userInfo]) {
        [super didReceiveNotificationRequest:request withContentHandler:contentHandler];
    } else {
        // Modify the notification content here...
        
        self.contentHandler(self.bestAttemptContent);
    }
}

- (void)serviceExtensionTimeWillExpire {
    if ([MDMNotification isMDMNotification:self.bestAttemptContent.userInfo]) {
        [super serviceExtensionTimeWillExpire];
    } else {
        self.contentHandler(self.bestAttemptContent);
    }
}

@end
