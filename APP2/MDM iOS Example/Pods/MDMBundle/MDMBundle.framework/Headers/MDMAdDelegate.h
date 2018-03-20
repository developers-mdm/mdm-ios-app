
//
//  Header.h
//  MDMAd
//
//  Created by Robson Moreira on 07/03/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <CoreLocation/CoreLocation.h>

@protocol MDMAdDelegate<NSObject>

- (void)adViewDidDisappear;

- (void)adViewWillExpand;

- (void)adViewDidFailToLoadWithError:(NSError *)error;

- (void)adViewDidCloseExpandWithFrame:(CGRect)frame;

@end
