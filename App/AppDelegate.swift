//
//  AppDelegate.swift
//  MDM iOS Example
//
//  Created by Robson Moreira on 12/12/19.
//  Copyright © 2019 Hands. All rights reserved.
//

import UIKit
import CoreLocation
import AppTrackingTransparency

// Hands MDM imports
import MDMCore
import MDMBundle
import MDMGeoBehavior
import MDMAppBehavior
import MDMNotification

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    private var notificationCenter = UNUserNotificationCenter.current()
    private var locationManager = CLLocationManager()

    var window: UIWindow?
    
    private let appId = "YOU_APP_ID"

    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        notificationCenter.delegate = self
        locationManager.delegate = self
        
        // Debug Mode
        MDMCore.setDebugMode(true)
        
        return true
    }
    
    func applicationDidBecomeActive(_ application: UIApplication) {
        Task {
            if await ATTrackingManager.requestTrackingAuthorization() == .authorized {
                // Start do Bundle com todos os módulos
                MDMCore.start(withAppId: appId, kitModules: [MDMBundle.self()])
                
                //
                // OU
                //
                
                // Start dos módulos separadamente
//                MDMCore.start(withAppId: appId, kitModules: [
//                    MDMGeoBehavior.self(),
//                    MDMAppBehavior.self(),
//                    MDMNotification.self()
//                ])
                
                // MDM Notification
                do {
                    let granted = try await notificationCenter.requestAuthorization(options: [.alert, .badge, .sound])
                    if granted {
                        // Defini o título para NavigarionBarTitle no Inbox (Default Inbox)
                        MDMInbox.setTitle("Hands Inbox")
                        
                        // Defini quais abas vão ficar disponíveis para o Inbox
                        MDMInbox.setActiveTabs([
                            .notifications,
                            .coupons,
                            .appInstall,
                            .marketplace
                        ])
                        
                        // Define o theme para o Inbox
//                        MDMInbox.setNavigationBarColor(color: UIColor.blue)
//                        MDMInbox.setNavigationItemColor(color: UIColor.lightGray)
//                        MDMInbox.setBackgroundColor(color: UIColor.white)
//                        MDMInbox.setTextColor(color: UIColor.black)
//                        MDMInbox.setTintColor(color: UIColor.lightGray)
                        
                        // Inicializar o módulo de notificações
                        MDMNotification.start()
                        
                        DispatchQueue.main.async {
                            application.registerForRemoteNotifications()
                        }
                    }
                } catch { }
                
                // MDM Geo
                switch self.locationManager.authorizationStatus {
                case .notDetermined, .denied, .restricted:
                    self.locationManager.requestAlwaysAuthorization()
                    break
                case .authorizedAlways, .authorizedWhenInUse:
                    break
                default:
                    break
                }
            }
        }
    }
    
    func applicationDidEnterBackground(_ application: UIApplication) {
        // MDM Init
        MDMCore.start(withAppId: appId, kitModules: [MDMBundle.self()])
        
        //
        // OU
        //
        
        // Start dos módulos separadamente
//        MDMCore.start(withAppId: appId, kitModules: [
//            MDMGeoBehavior.self(),
//            MDMAppBehavior.self(),
//            MDMNotification.self()
//        ])
    }
    
    func applicationWillTerminate(_ application: UIApplication) {
        // MDM Init
        MDMCore.start(withAppId: appId, kitModules: [MDMBundle.self()])
        
        //
        // OU
        //
        
        // Start dos módulos separadamente
//        MDMCore.start(withAppId: appId, kitModules: [
//            MDMGeoBehavior.self(),
//            MDMAppBehavior.self(),
//            MDMNotification.self()
//        ])
    }
    
    func application(_ application: UIApplication, didRegisterForRemoteNotificationsWithDeviceToken deviceToken: Data) {
        print(deviceToken.map { String(format: "%02.2hhx", $0) }.joined())
    }
    
    func application(_ application: UIApplication, didFailToRegisterForRemoteNotificationsWithError error: Error) {
        MDMNotification.unregisterToken()
    }
}

extension AppDelegate: UNUserNotificationCenterDelegate {
    func userNotificationCenter(_ center: UNUserNotificationCenter,
                                didReceive response: UNNotificationResponse,
                                withCompletionHandler completionHandler: @escaping () -> Void) {
        let userInfo = response.notification.request.content.userInfo
        if MDMNotification.isMDMNotification(userInfo) {
            MDMNotification.receive(userInfo)
        } else {
            // Process your notification here
        }
        completionHandler();
    }
    
    func userNotificationCenter(_ center: UNUserNotificationCenter,
                                willPresent notification: UNNotification,
                                withCompletionHandler completionHandler: @escaping (UNNotificationPresentationOptions) -> Void) {
        let userInfo = notification.request.content.userInfo
        if MDMNotification.isMDMNotification(userInfo) {
            MDMNotification.processNotification(userInfo, completionBlock: completionHandler)
        } else {
            // Open your notification here
        }
    }
}

extension AppDelegate: CLLocationManagerDelegate {
    func locationManagerDidChangeAuthorization(_ manager: CLLocationManager) {
        if manager.authorizationStatus == .authorizedAlways || manager.authorizationStatus == .authorizedWhenInUse {
            MDMGeoBehavior.start()
        }
    }
}
