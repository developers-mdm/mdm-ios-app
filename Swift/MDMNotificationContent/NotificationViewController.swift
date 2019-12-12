//
//  NotificationViewController.swift
//  MDMNotificationContent
//
//  Created by Robson Moreira on 12/12/19.
//  Copyright © 2019 Hands. All rights reserved.
//

import MDMNotification

class NotificationViewController: MDMNotificationViewController {

    @IBOutlet var label: UILabel?
    
    private var isHandsPush: Bool!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any required interface initialization here.
    }
    
    override func didReceive(_ notification: UNNotification) {
        self.isHandsPush = MDMNotification.isMDMNotification(notification.request.content.userInfo)

        if self.isHandsPush {
            super.didReceive(notification)
        } else {
            // Your code here
        }
    }
    
    override func didReceive(_ response: UNNotificationResponse, completionHandler completion: @escaping (UNNotificationContentExtensionResponseOption) -> Void) {
        
        if self.isHandsPush {
            super.didReceive(response, completionHandler: completion)
        } else {
            // Your code here
        }
        
    }

}
