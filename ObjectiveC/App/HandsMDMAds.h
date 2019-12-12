//
//  HandsMDMAds.h
//  HandsMDM
//  Copyright © Hands. All rights reserved.
//

#import <MBHManager/HandsMDM.h>
#import <sys/utsname.h>
#import "SASAdView.h"
#import "SASBannerView.h"
#import "SASInterstitialView.h"

@interface HandsMDM (HandsMDMAds) {

}
- (NSString*) loadAudiencesForTargetAds;

/*!
 @brief Faz chamada ao Adserver para entrega da publicidade segmentada.
 @discussion Exemplo: [self.HandsMDM targetAdToAudience:bannerView format:\@"INTERSTITIAL" screen:\@"MAIN"];
 
 Recebe a view configurada para carregamento da publicidade de acordo com documentação. Parâmetros: format é um NSString que corresponde ao nome do formato desejado configurado no arquivo MDMAdServerConfig.plist , screen é um NSString que corresponde ao nome da tela do aplicativo que vai apresentar a publicidade, conforme configurado no MDMAdServerConfig.plist, a relação format + tela identifica o banner ideal para entrega.
 
 Devolve a view do banner configurada para ser inserida na tela via o método addSubview Ex.: [self.view addSubview:[self.HandsMDM targetAdToAudience:_banner format:\@"INTERSTITIAL" screen:\@"MAIN"]];
 Se você chamar o método múltiplas vezes para um mesmo key, apena so último valor será salvo para ele.
 
 @return view.
 
 */
- (id) targetAdToAudience:(SASAdView*)bannerView format:(NSString*)format screen:(NSString*)screen;

/*!
 @brief Inicia o módulo de Adserver para servir publicidade segmentada com base nas audiências do Hands MDM.
 @discussion Exemplo: [self.HandsMDM startAdServerModule]
 
 Deve ser invocado idealmente no seu método didFinishLaunchingWithOptions logo após a instância Hands MDM. Sem a chamada deste método não será possível o carregamento da publicidade.
 
 @return void.
 */
- (void) startAdServerModule;
+ (void) readAdserverPreferences;
+ (NSInteger) getAdPusblisherID;
+ (NSString*) getAdBaseURL;
+ (NSInteger) getAdFormat:(NSString*)format;
+ (NSString*) getAdScreen:(NSString*)screen;


@end
