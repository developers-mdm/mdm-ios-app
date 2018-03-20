//
//  ViewController.m

//  Copyright ©. All rights reserved.
//

#import "ViewController.h"
#import <CoreLocation/CoreLocation.h>
#import <MDMBundle/MDMGeoBehavior.h>
#import <MDMBundle/MDMAd.h>

@interface ViewController ()

@end

@implementation ViewController

CLLocationManager *locationManager;

- (void)viewDidLoad {
    [super viewDidLoad];
    
    locationManager = [CLLocationManager new];
    locationManager.delegate = self;
    
    // Verifica permissão de geolocalização
    if ([CLLocationManager authorizationStatus] == kCLAuthorizationStatusNotDetermined || [CLLocationManager authorizationStatus] == kCLAuthorizationStatusDenied) {
        // Requisitar permissão de geolocalização
        [locationManager requestAlwaysAuthorization];
    }
    
    
    // Apresenta os banners dos IDs de formato e página do arquivo de configuração MDMAdServerConfig.plist
    CGRect frame = CGRectMake(0, 0, CGRectGetWidth(self.view.frame), 53);
    [MDMAd loadAd:frame type:MDMAdBannerView loader:MDMStyleBlack format:@"ARROBA" screen:@"MAIN" delegate:self parent:self];
    
    CGRect frameFull = CGRectMake(0, 0, CGRectGetWidth(self.view.frame), CGRectGetHeight(self.view.frame));
    [MDMAd loadAd:frameFull type:MDMAdInterstitialView loader:MDMStyleBlack format:@"INTERSTITIAL" screen:@"MAIN" delegate:self parent:self];

}

- (void)locationManager:(CLLocationManager *)manager didChangeAuthorizationStatus:(CLAuthorizationStatus)status {
    if (status == kCLAuthorizationStatusAuthorizedAlways || status == kCLAuthorizationStatusAuthorizedWhenInUse) {
        //Permissão concedida, inicializar geolocalização
        [MDMGeoBehavior start];
    } else {
        // Permissão não concedida
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)dealloc {
}

@end
