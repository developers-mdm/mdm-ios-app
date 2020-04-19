//
//  AppDelegate.swift
//  MDM iOS Example
//
//  Created by Robson Moreira on 12/12/19.
//  Copyright © 2019 Hands. All rights reserved.
//

import UIKit
import MDMCore
import MDMBundle
import MDMGeoBehavior
import MDMAppBehavior
import MDMNotification

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, CLLocationManagerDelegate, UNUserNotificationCenterDelegate {

    var window: UIWindow?
    
    private var locationManager: CLLocationManager!
    private var notificationCenter: UNUserNotificationCenter!
    
    private let appId = "ZF4ab16J6tT77b28OvH2AAwoqmlKQQRuz204O3maL/4j/9fO9DGzP71goK/BNNGh8DlqvN/k3sgsNaSzEPFGbbfUMjnLVjR9783dbyeuS+pzRL8LLXyTnrkY9ZfiVWmkupHiR2iMzBqQwhVidugTKu7xW7OJNJck1ZLawu+1cEvGz4YxwCOmkhp9Y2ygOQRqGIpuzA/TqyLc4+/PET9wGkrl8RbjHYgtJto+hVLwj3KuKEoLxyzpKcxWaDSiu1lhbJQSgWMMdiQ9zIYiE4BXBj1vKWh8YsB9P034oOWJk6LZ/hiXbEu+ZxbuNo3jHyu4VYRHqTocfyglF13RWj2bFA=="

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        // Debug Mode
        MDMCore.setDebugMode(true)
        
        // Start do Bundle com todos os módulos
        MDMCore.start(withAppId: appId, kitModules: [MDMBundle.self()])
        
        //
        // OU
        //
        
        // Start de cada módulo separadamente
//        MDMCore.start(withAppId: appId, kitModules: [
//            MDMGeoBehavior.self(),
//            MDMAppBehavior.self(),
//            MDMNotification.self()
//        ])
        
        self.locationManager = CLLocationManager()
        self.locationManager.delegate = self
        switch CLLocationManager.authorizationStatus() {
        case .notDetermined, .denied, .restricted:
            self.locationManager.requestAlwaysAuthorization()
            break
        case .authorizedAlways, .authorizedWhenInUse:
            break
        default:
            break
        }
        
        self.notificationCenter = UNUserNotificationCenter.current()
        self.notificationCenter.delegate = self
        self.notificationCenter.requestAuthorization(options: [.alert, .sound]) { (granted, error) in
            if granted {
                OperationQueue.main.addOperation({
                    if !UIApplication.shared.isRegisteredForRemoteNotifications {
                        UIApplication.shared.registerForRemoteNotifications()
                    }
                })
            }
        }
        
        // Customização do Inbox
        MDMInbox.setTitle("My Inbox")
        MDMInbox.setNavigationBarColor("#312683")
        MDMInbox.setTabBarColor("#312683")
        MDMInbox.setTintColor("#C8D400")
        MDMInbox.setBackgroundColor("#312683")
        
        return true
    }
    
    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
        if status == .authorizedAlways || status == .authorizedWhenInUse {
            MDMGeoBehavior.start()
        }
    }
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        MDMNotification.registerToken(deviceToken)
    }
    
    func application(_ application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error: Error) {
        MDMNotification.unregisterToken()
    }
    
    func userNotificationCenter(_ center: UNUserNotificationCenter, didReceive response: UNNotificationResponse, withCompletionHandler completionHandler: @escaping () -> Void) {
        
        let userInfo = response.notification.request.content.userInfo
        if MDMNotification.isMDMNotification(userInfo) {
            MDMNotification.processNotification(userInfo)
        } else {
            // Process your notification here
        }
        completionHandler();
        
    }
    
    func userNotificationCenter(_ center: UNUserNotificationCenter, willPresent notification: UNNotification, withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
        
        let userInfo = notification.request.content.userInfo
        if MDMNotification.isMDMNotification(userInfo) {
            MDMNotification.processNotification(userInfo)
        } else {
            // Open your notification here
        }
        
    }
    
}

