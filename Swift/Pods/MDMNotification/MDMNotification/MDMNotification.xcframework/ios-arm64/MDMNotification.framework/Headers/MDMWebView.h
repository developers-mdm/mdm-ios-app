//
//  MDMWebView.h
//  HandsMDM
//
//  Created by Robson Moreira on 23/07/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <MDMCore/MDMObjectModel.h>

@interface MDMWebView : MDMObjectModel<NSCoding, MDMObjectDictionary>

@property (nonatomic, retain) NSString *title;
@property (nonatomic, retain) NSString *url;

@end
