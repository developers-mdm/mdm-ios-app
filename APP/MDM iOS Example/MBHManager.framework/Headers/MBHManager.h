//
//  MBHManager.h
//  MBH
//
//  Copyright © All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <MBHManager/HandsMDM.h>

FOUNDATION_EXPORT double MBHVersionNumber;

FOUNDATION_EXPORT const unsigned char MBHVersionString[];

#define IS_OS_8_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)

@interface MBHManager : NSObject {
    
}

@property (nonatomic) BOOL debugMode;

+ (id)sharedManager;


/*! 
    @brief Inicia a monitoração de visitas do usuário.
 
    @discussion Deve ser chamado nos métodos didFinishLaunchingWithOptions e applicationWillResignActive do seu delegate de acordo com as instruções enviadas
    @return void.
 */
- (void)startMonitoringVisits;

/*! 
    @brief Reinicia a monitoração visitas do usuário.
    @discussion Deve ser chamado nos métodos applicationDidBecomeActive e applicationWillTerminate do seu delegate de acordo com as instruções enviadas
    
    @return void.
 
 */
- (void)restartMonitoringVisits;

/*! 
    @brief Define um identificador único a ser relacionado a todos os dados de localização do usuário
 
    @discussion Este identificador pode ser usado para permite acessar os dados com base nele
 
    @param  exid Uma string contendo o identificador único daquel usuário que será armazenado
 
    @return void Armazena o dado imediatamente sem necessidade de retorno.
 */
- (void)setExternalID:(NSString *)exid;

/*!
 @brief Verifica se o usuário desativou o acesso aos serviços de localização
 
 @discussion É boa prática utilizar este método e requisitar de forma amigável que o usuário reative os serviços de localização
 
 @param  alertMessage Uma string contendo a mensagem que você deseja apresentar caso o usuário tenha os serviços desabilitados
 
 @return void Ao clicar no botão "Ajustes" o usuário é levado para a tela onde pode ativar o serviço novamente
 */
- (void)checkLocationAuthorization:(NSString *)alertMessage;

/*!
 @brief Registra o Token de Push Notification com o serviço do MBH para uso futuro
 
 @discussion Você poderá utilizar a interface do sistema para enviar notificações segmentadas aos seus usuários
 
 @param  devicePushToken Uma string contendo o token que o OS gerou. Este é único por app. É necessário seguir a documentação de implementação para registro de notificações e repassar o token gerado para o SDK usando este método
 
 @return void
 */
-(void)registerTokenForPushNotification:(NSString *)devicePushToken;

/*!
 @brief Registra o Token de Push Notification com o serviço do MBH para uso futuro
 
 @discussion Você poderá utilizar a interface do sistema para enviar notificações segmentadas aos seus usuários
 
 @param  devicePushToken Uma NSdata contendo o token que o OS gerou. Este é único por app. É necessário seguir a documentação de implementação para registro de notificações e repassar o token gerado para o SDK usando este método
 
 @return void
 */
-(void) registerTokenForPushNotificationWithNSData:(NSData *)devicePushToken;

/*!
 @brief Remove o registro de Token de Push Notification
 
 @discussion Se o usuário desativar o recurso de push notifications, você precisa informar o sistema de que o usuário não deseja mais receber notificações, basta então chamar este método para remover o usuário da lista de push
 
 @param  none
 
 @return void
 */
-(void) unregisterTokenForPushNotification;

@end
