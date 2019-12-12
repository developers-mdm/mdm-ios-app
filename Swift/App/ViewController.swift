//
//  ViewController.swift
//  MDM iOS Example
//
//  Created by Robson Moreira on 12/12/19.
//  Copyright © 2019 Hands. All rights reserved.
//

import UIKit

class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
    }

    @IBAction func openInbox(_ sender: UIButton) {
        let bundle = Bundle(identifier: "br.com.hands.mdm.libs.ios.notification")
        let storyboard = UIStoryboard(name: "MDMInBox", bundle: bundle)

        if let navigationController = storyboard.instantiateViewController(withIdentifier: "MDMInboxNavigationController") as? UINavigationController {
            navigationController.modalPresentationStyle = .fullScreen
            self.present(navigationController, animated: true, completion: nil)
        }
    }
    
}

