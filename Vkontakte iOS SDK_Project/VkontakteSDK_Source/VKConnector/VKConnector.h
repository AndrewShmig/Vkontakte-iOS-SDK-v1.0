//
//  VKConnector.h
//
//  Created by Andrew Shmig on 18.12.12.
//

#import <Foundation/Foundation.h>


@class VKAccessToken;

/** Класс предназначен для получения приложением доступа к пользовательской учетной записи.
 */
@interface VKConnector : NSObject <UIWebViewDelegate>

/**
 @name Методы инициализации
 */

/** Основной метод инициализации.
 
 @param webView UIWebView с которым будет происходить взаимодействие пользователя 
 и в котором будет отображаться страница запроса доступа приложения к пользовательской учетной записи.
 @param appID Идентификатор приложения полученный при регистрации.
 @param permissions Массив доступов (разрешений), которые необходимо получить приложению.
 
 */
- (id)initWithWebView:(UIWebView *)webView
                appID:(NSString *)appID
          permissions:(NSArray *)permissions;

/**
 @name Публичные методы
 */

/** Метод инициирующий процесс получения доступа к пользовательской учетной записи.
 
 @param cancelBlock Блок, который выполнится в случае, если пользователь откажется авторизовывать приложение.
 @param acceptedBlock Блок, который выполнится в случае, если пользователь успешно авторизовал наше приложение. 
        Переданный параметр переменная типа VKAccessToken.
 */
- (void)startOnCancelBlock:(void (^)(void))cancelBlock
            onSuccessBlock:(void (^)(VKAccessToken *))acceptedBlock;

@end
