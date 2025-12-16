//
//  ViewController.swift
//  MDM iOS Example
//
//  Created by Robson Moreira on 12/12/19.
//  Copyright © 2019 Hands. All rights reserved.
//

import UIKit
import MDMNotification

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func openInbox(_ sender: UIButton) {
        let inboxConfig = MDMInboxConfig()
        
        // Define quais abas vão estar disponíveis
//        inboxConfig.activeTabs = [.notifications, .appInstall]
        
        // Define qual aba inicializa selecionada
//        inboxConfig.selectedTab = MDMInboxTab.coupons as NSString
        
        MDMInbox.setInboxConfig(inboxConfig)
        
        let inboxTabBarController = InboxMainTabBarController()
        inboxTabBarController.modalPresentationStyle = .fullScreen
        present(inboxTabBarController, animated: true)
    }
    
}

