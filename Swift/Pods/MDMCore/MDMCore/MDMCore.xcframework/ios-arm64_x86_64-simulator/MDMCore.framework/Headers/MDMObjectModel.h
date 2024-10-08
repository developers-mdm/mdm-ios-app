//
//  MDMObjectModel.h
//  HandsMDM
//
//  Created by Robson Moreira on 26/04/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol MDMObjectDictionary

- (NSDictionary *_Nonnull)toDictionary;

- (nonnull instancetype)initWithDictionary:(NSDictionary *_Nonnull)dictionary;

@end

@interface MDMObjectModel : NSObject

- (NSDictionary *_Nonnull)toDictionary;

- (nonnull instancetype)initWithDictionary:(NSDictionary *_Nonnull)dictionary;

- (NSString *_Nonnull)toStringJson;

@end
