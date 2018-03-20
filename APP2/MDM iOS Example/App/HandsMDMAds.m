//
//  HandsMDMAds.m
//  HandsMDM
//  Modulo de Publicidade Segmentada do Hands MDM
//  Copyright © Hands. All rights reserved.
//

#import <MBHManager/HandsMDM.h>
#import "HandsMDMAds.h"


@implementation HandsMDM (HandsMDMAds)


- (id) targetAdToAudience:(SASAdView*)bannerView format:(NSString*)format screen:(NSString*)screen
{
    NSInteger *formatId = [HandsMDM getAdFormat:format];
    NSString *screenId = [HandsMDM getAdScreen:screen];
    
    if(formatId == nil || screenId == nil)
    {
        NSLog(@"Unable to set the Ad. Missing format or screen setup on the MDMAdServerConfig.plist.");
        return nil;
    }
    
    [bannerView loadFormatId:formatId pageId:screenId master:YES target:[self loadAudiencesForTargetAds]];
    
    return bannerView;
}

- (void) startAdServerModule
{
    NSInteger *publisherId =[HandsMDM getAdPusblisherID];
    NSString *baseURL = [HandsMDM getAdBaseURL];
    
    if(publisherId == nil || baseURL == nil)
    {
        NSLog(@"Unable to load the Adserver module. Missing configuration.");
        return;
    }
    
    [SASAdView setSiteID:[HandsMDM getAdPusblisherID] baseURL:[HandsMDM getAdBaseURL]];
}

@end
