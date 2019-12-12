//
//  HandsMDM.h
//  HandsMDM
//
//  Copyright © Hands. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>

//! Project version number for HandsMDM.
FOUNDATION_EXPORT double HandsMDMVersionNumber;

//! Project version string for HandsMDM.
FOUNDATION_EXPORT const unsigned char HandsMDMVersionString[];

#define IS_OS_8_OR_LATER ([[[UIDevice currentDevice] systemVersion] floatValue] >= 8.0)

@interface HandsMDM : NSObject {
    
}

@property (nonatomic) BOOL debugMode;
@property (nonatomic) NSString* HandsID;
@property (copy)void (^doCallback)(void);

/*!
 @brief Inicia o SDK do MDM.
 
 @discussion Deve ser chamado idealmente assim que o aplicativo inicia no método didFinishLaunchingWithOptions do seu delegate de acordo com as instruções enviadas ou na inicialização das suas classes que terão interação com o SDK. 
 
 Exemplo: self.HandsMDM = [HandsMDM sharedManager];
 @return void.
 */
+ (id)sharedManager;

/*!
 @brief Define um campo e valor para associar ao usuário.
 @discussion Exemplo: [self.HandsMDM setData:@"estado" value:@"rio de janeiro"];
 
        O parâmetro key deve ser uma NSString sem caracteres especiais, no lugar de espaços, use '_' e idealmente em letras minúsculas. O parâmetro value é uma NSString sem as restrições do campo key.
 
 Cada chamada armazena o dado para envio assim que o método track for chamado. 
 Se você chamar o método múltiplas vezes para um mesmo key, apena so último valor será salvo para ele.
 
 @return void.
 
 */
- (void)setData:(NSString *)key value:(NSString *)value;

/*!
 @brief Define um campo e valor para associar ao usuário como o setData mas com a diferença de que esta informação é criptografada antes do envio.
 @discussion O método irá criptografar automaticamente o valor do seu campo para garantir a privacidade do dado desejado Exemplo: [self.HandsMDM setData:@"informacao_sigilosa" value:@"valor que deve ser criptografado" encrypted:YES];
 
    O parâmetro key deve ser uma string sem caracteres especiais ou espaços e idealmente em letras minúsculas, o parâmetro value é uma string sem as restrições do campo key
 
 @return void.
 
 */
- (void)setData:(NSString *)key value:(NSString *)value encrypted:(BOOL)encrypted;

/*!
 @brief Método para enviar o CPF do usuário para o SDK de forma anônima
 @discussion O método irá criptografar automaticamente o CPF para garantir a privacidade do dado desejado.
 
    Exemplo: [self.HandsMDM setPUC:@"123.456.789-44"]; - O parâmetro pode ser no formato xxx.xxx.xxx-xx ou somente números.
 
 @return void.
 
 */
- (void)setPUC:(NSString *)cpf;

/*!
 @brief Método para enviar o e-mail do usuário para o SDK de forma anônima
 @discussion O método irá criptografar automaticamente o e-mail para garantir a privacidade do dado desejado.
 
    Exemplo: [self.HandsMDM setPUE:@"email@provedor.com"];
 
 @return void.
 
 */
- (void)setPUE:(NSString *)email;

/*!
 @brief Método para enviar o telefone do usuário para o SDK de forma anônima
 @discussion O método irá criptografar automaticamente o telefone para garantir a privacidade do dado desejado.
 
    Exemplo: [self.HandsMDM setPUT:@"(11)9999-9999"];
 
 @return void.
 
 */
- (void)setPUT:(NSString *)phone;

/*!
 @brief Envia todos os dados do usuário que foram configurados usando o método setData e atualiza a lista de audiências encontradas para o usuário
 @discussion O envio é assíncrono e sem retorno. Se não houver conexão, os dados são mantidos em cache até que se possa enviar eles.
 
    Exemplo: [self.HandsMDM track];
 
 @return void.
 
 */
- (void)track;

/*!
 @brief Envia todos os dados do usuário que foram configurados usando o método setData e atualiza a lista de audiências encontradas para o usuário com a diferença que você pode executar um callback ao final
 @discussion O callback é um block com todo so código que você deseja que seja executado assim que o envio dos dados for concluído. 
 
 Para mais informações sobre block consulte https://developer.apple.com/library/ios/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/WorkingwithBlocks/WorkingwithBlocks.html
 
    Exemplo: [self.HandsMDM trackWithCallback:^{
 NSDictionary* audiencesData = [self.HandsMDM getAudiences];
 if(audiencesData != nil)
 {
    NSMutableString *audiencesListForDisplay = [NSMutableString stringWithString:@""];
    for (id key in audiencesData)
    {
       [audiencesListForDisplay appendString:[NSString stringWithFormat:@"%@ (%@)", key, audiencesData[key] ] ];
    }
    NSLog(@"Audiências: %@",audiencesListForDisplay);
 
  }
}];

 @return void.

 */
- (void)trackWithCallback:(void(^)(void))callBack;

/*!
 @brief Retorna um dicionário contento todas as audiências que o usuário faz parte, onde cada chave do dicionário é o nome da audiência e o valor é o identificador único relacionada a audiência
 
 @discussion Esse método pode ser chamado a qualquer momento depois de inicializar o SDK, e você pode usar ele no método trackWithCallback para poder acessar os dados atualizados de audiências do usuário.
 
    Exemplo: [self.HandsMDM getAudiences];
 
 @return void.
 
 */
- (NSDictionary*)getAudiences;

/*!
 @brief Processa uma notificação enviada pela Hands MDM para apresentar publicidade quando a aplicação está ativa ou em foreground
 
 @discussion Esse método deve ser chamado no delegate em didReceiveRemoteNotification de acordo com a documentação da HandsMDM.
 
 Exemplo: [self.HandsMDM didReceiveRemoteNotification:userInfo];
 
 @return void.
 
 */
-(BOOL) didReceiveRemoteNotification:(NSDictionary *)notificationData;

/*!
 @brief Processa uma notificação enviada pela Hands MDM para apresentar publicidade quando a aplicação está em background
 
 @discussion Esse método deve ser chamado no delegate em didReceiveRemoteNotification quando application.applicationState == UIApplicationStateBackground de acordo com a documentação da HandsMDM.
 
 Exemplo: [self.HandsMDM processNotification:userInfo];
 
 @return void.
 
 */
-(BOOL) processNotification:(NSDictionary *)notificationData;

- (void) trackWithVisit;

@end

