//
//  MDMDatabase.h
//  MDMCore
//
//  Created by Robson Moreira on 19/02/18.
//  Copyright © 2018 Hands. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface MDMDatabase<__covariant ObjectType> : NSObject

+ (BOOL)saveObject:(ObjectType)object type:(Class)type;

+ (ObjectType)readObject:(Class)type;

+ (void)remove:(Class)type;

@end
