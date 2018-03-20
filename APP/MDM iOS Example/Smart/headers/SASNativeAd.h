//
//  SASNativeAd.h
//  SmartAdServer
//
//  Created by Loïc GIRON DIT METAZ on 18/08/2015.
//
//

#import <UIKit/UIKit.h>
#import "SASNativeAdDelegate.h"

#define SASRatingUndefined -1
#define SASLikesUndefined -1
#define SASDownloadsUndefined -1


/**
 A SASNativeAd represents an ad that will be displayed by the native code of the application.
 
 Contrary to the SASAd object, the SASNativeAd only contains information that needs to be displayed but
 does not create any view for the actual display.
 Since the application is reponsible of the ad display
 */

@class SASNativeAdImage;

@interface SASNativeAd : NSObject <NSCopying, NSCoding>

/**
 The title of the ad (required).
 */
@property (nonatomic, readonly, nullable, strong) NSString *title;

/**
 The subtitle of the ad.
 
 Can be used as a short description.
 */
@property (nonatomic, readonly, nullable, strong) NSString *subtitle;

/**
 The body of the ad.
 
 Can be used as a long description.
 */
@property (nonatomic, readonly, nullable, strong) NSString *body;

/**
 The call to action text of the ad.
 
 This text represents the action that will be made when the ad is clicked: for instance 'Open' or 'Download'.
 */
@property (nonatomic, readonly, nullable, strong) NSString *callToAction;

/**
 The icon of the ad (required).
 */
@property (nonatomic, readonly, nullable, strong) SASNativeAdImage *icon;

/**
 The cover image of the ad.
 
 A cover image is an image that is generally larger that the icon and that will generally be used as a background image.
 */
@property (nonatomic, readonly, nullable, strong) SASNativeAdImage *coverImage;

/**
 The 'sponsored by' message of the ad.
 Generally contains the brand name of the sponsor.
 */
@property (nonatomic, readonly, nullable, strong) NSString *sponsored;

/**
 The rating between 0-5 of the advertised app / product or SASRatingUndefined if not set.
 */
@property (nonatomic) float rating;

/**
 Number of social likes of the advertised app / product or SASLikesUndefined if not set.
 */
@property (nonatomic) long likes;

/**
 Number of downloads / installs of the advertised app or SASDownloadsUndefined if not set.
 */
@property (nonatomic) long downloads;

/**
 A dictionary of custom parameters that have been sent by the ad.
 
 This dictionary can be used to carry additional resources or information. You need a compatible Smart AdServer template to use this feature.
 */
@property (nonatomic, readonly, nullable, strong) NSDictionary *extraParameters;

/** 
 The object that acts as the delegate of the receiving native ad.
 
 The delegate must adopt the SASNativeAdDelegate protocol.
 
 @warning *Important* : The delegate is not retained by the SASNativeAd, so you need to set the ad's delegate to nil before the delegate is released.
 
 */

@property (nonatomic, nullable, weak) id <SASNativeAdDelegate> delegate;



/**
 Register the view that will be used for viewability tracking and tappable views that will be used as click target in your native ad.
 
 You MUST register at least one view for each displayed native ad otherwise the impression will not be registered.
 
 @param view A view that will be registered as main view and used for viewability tracking.
 @param views An array of views that will be registered as click target.
 @param modalParentViewController The view controller that will be used if the ad needs to open a modal view or a store controller.
 */
- (void)registerView:(nonnull UIView *)view tappableViews:(nonnull NSArray *)views modalParentViewController:(nonnull UIViewController *)modalParentViewController;


/**
 Convenient method to register only one view as click target and viewability tracking.
 
 You MUST register at least one view for each displayed native ad otherwise the impression will not be registered.
 
 @param view A view that will be registered as click target and used for viewability tracking.
 @param modalParentViewController The view controller that will be used if the ad needs to open a modal view or a store controller.
 */
- (void)registerView:(nonnull UIView *)view modalParentViewController:(nonnull UIViewController *)modalParentViewController;


/**
 Unregister all views that are currently being used as click target.
 */
- (void)unregisterViews;

@end
