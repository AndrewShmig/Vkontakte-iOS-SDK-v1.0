//
//  VKConnector.h
//
//  Created by Andrew Shmig on 18.12.12.
//

#import <Foundation/Foundation.h>


@class VKAccessToken;

/*!
 @interface
 @brief Класс предназначен для получения приложением доступа к пользовательской учетной
 записи и осуществления запросов к API сервиса методами GET/POST.
 @code
 - (void)applicationDidFinishLaunching:(UIApplication *)application
 {
 [[VKConnector sharedInstance] startWithAppID:@"YOUR_APP_ID" 
 permissons:@[@"friends",@"wall"]];
 }
 @endcode
 */
@interface VKConnector : NSObject <UIWebViewDelegate>

@property (nonatomic, strong, readonly) NSArray *permissions;
@property (nonatomic, strong) UIView *parentView;

/*
 Метод класса для получения экземпляра сиглтона. Если объект отсутствует, то он будет создан. Не может быть равен nil или NULL.
*/

+ (id) sharedInstance;

/**
 @name Методы инициализации
 */

/*!
 @method
 
 @abstract Инициализирует запуск коннектора с заданными параметрами
 
 @param appID Идентификатор приложения полученный при регистрации.
 @param permissions Массив доступов (разрешений), которые необходимо получить приложению.
 */
- (void)startWithAppID:(NSString*)appID permissons:(NSArray*)permissions;

/** Основной метод инициализации.
 
 @param webView UIWebView с которым будет происходить взаимодействие пользователя 
 и в котором будет отображаться страница запроса доступа приложения к пользовательской учетной записи.
 @param appID Идентификатор приложения полученный при регистрации.
 @param permissions Массив доступов (разрешений), которые необходимо получить приложению.
 
 */
- (id)initWithWebView:(UIWebView *)webView
                appID:(NSString *)appID
          permissions:(NSArray *)permissions __attribute__((deprecated));

/**
 @name Публичные методы
 */

/** Метод инициирующий процесс получения доступа к пользовательской учетной записи.
 
 @param cancelBlock Блок, который выполнится в случае, если пользователь откажется авторизовывать приложение.
 @param acceptedBlock Блок, который выполнится в случае, если пользователь успешно авторизовал наше приложение. 
        Переданный параметр переменная типа VKAccessToken.
 */
- (void)startOnCancelBlock:(void (^)(void))cancelBlock
            onSuccessBlock:(void (^)(VKAccessToken *))acceptedBlock __attribute__((deprecated));

@end
