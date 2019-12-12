//
//  NotificationService.swift
//  MDMNotificationService
//
//  Created by Robson Moreira on 12/12/19.
//  Copyright © 2019 Hands. All rights reserved.
//

import MDMNotification

class NotificationService: MDMNotificationService {

    var contentHandler: ((UNNotificationContent) -> Void)?
    var bestAttemptContent: UNMutableNotificationContent?

    override func didReceive(_ request: UNNotificationRequest, withContentHandler contentHandler: @escaping (UNNotificationContent) -> Void) {
        self.contentHandler = contentHandler
        self.bestAttemptContent = (request.content.mutableCopy() as? UNMutableNotificationContent)

        if let bestAttemptContent = self.bestAttemptContent {
            if MDMNotification.isMDMNotification(bestAttemptContent.userInfo) {
                super.didReceive(request, withContentHandler: contentHandler)
            } else {
                // Your code here
                contentHandler(bestAttemptContent)
            }
        }
    }
    
    override func serviceExtensionTimeWillExpire() {
        if let contentHandler = self.contentHandler, let bestAttemptContent = self.bestAttemptContent {
            if MDMNotification.isMDMNotification(bestAttemptContent.userInfo) {
                super.serviceExtensionTimeWillExpire()
            } else {
                // Your code here
                contentHandler(bestAttemptContent)
            }
        }
    }

}
