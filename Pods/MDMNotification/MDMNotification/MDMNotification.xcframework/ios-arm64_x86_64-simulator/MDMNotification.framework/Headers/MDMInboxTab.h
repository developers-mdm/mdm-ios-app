//
//  MDMInboxTab.h
//  MDMNotification
//
//  Created by Robson Moreira on 01/04/25.
//  Copyright © 2025 Hands. All rights reserved.
//

#ifndef MDMInboxTab_h
#define MDMInboxTab_h

typedef NSString * MDMInboxTab NS_TYPED_ENUM;
static MDMInboxTab const MDMInboxTabNotifications NS_SWIFT_NAME(notifications) = @"notifications";
static MDMInboxTab const MDMInboxTabCoupons NS_SWIFT_NAME(coupons) = @"coupons";
static MDMInboxTab const MDMInboxTabAppInstall NS_SWIFT_NAME(appInstall) = @"appinstall";
static MDMInboxTab const MDMInboxTabMarketplace NS_SWIFT_NAME(marketplace) = @"marketplace";

#endif /* MDMInboxTab_h */
