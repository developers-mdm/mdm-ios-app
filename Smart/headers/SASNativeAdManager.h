//
//  SASNativeAdManager.h
//  SmartAdServer
//
//  Created by Loïc GIRON DIT METAZ on 02/09/2015.
//
//

#import <Foundation/Foundation.h>
#import "SASNativeAdPlacement.h"
#import "SASNativeAd.h"


/**
 The completion block that will be called when the native ad request is finished.
 
 To use this block, you should test if the 'ad' object is not nil and use it. If the ad object is nil,
 you can optionally check the 'error' object to get the description of the issue.
 
 @param ad A valid SASNativeAd if the call was successful, nil otherwise.
 @param error A valid NSError if the call failed, nil otherwise.
 */
typedef void(^SASNativeRequestCompletionBlock)(SASNativeAd * _Nullable ad, NSError * _Nullable error);


/**
 A SASNativeAdManager instance can be used to request a native ad object from Smart AdServer delivery.
 
 Each SASNativeAdManager instance corresponds to a placement, represented by a configuration.
 */
@interface SASNativeAdManager : NSObject

/**
 Initializes a SASNativeAdManager object.
 
 @param placement Represents the placement's configuration that will be used by the SASNativeAdManager.
 
 @return An initialized instance of SASNativeAdManager.
 */
- (nonnull instancetype)initWithPlacement:(nonnull SASNativeAdPlacement *)placement;

/**
 Request a native ad from Smart AdServer.
 
 @param completionBlock The block that will be called when the ad request is finished.
 */
- (void)requestAd:(nonnull SASNativeRequestCompletionBlock)completionBlock;

/**
 Returns an initialized SASNativeAdManager object.
 
 @param placement Represents the placement's configuration that will be used by the SASNativeAdManager.
 
 @return An initialized instance of SASNativeAdManager.
 */
+ (nonnull instancetype)nativeAdManagerWithPlacement:(nonnull SASNativeAdPlacement *)placement;

@end
