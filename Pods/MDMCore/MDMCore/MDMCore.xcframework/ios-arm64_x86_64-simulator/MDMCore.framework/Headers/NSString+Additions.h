//
//  NSString+Additions.h
//  MDMCore
//
//  Created by Robson Moreira on 15/02/19.
//  Copyright © 2019 Hands. All rights reserved.
//

@import Foundation.NSString;

#define STRING_EMPTY @""

@interface NSString (Additions)

- (BOOL)isEmpty;

- (BOOL)isNotEmpty;

- (BOOL)isNil;

- (BOOL)isNotNil;

- (BOOL)isNull;

- (BOOL)isNotNull;

- (NSString *)MD5Hash;

@end
