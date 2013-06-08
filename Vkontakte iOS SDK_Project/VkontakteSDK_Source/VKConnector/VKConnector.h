//
//  VKConnector.h
//
//  Created by Andrew Shmig on 18.12.12.
//
//
// Copyright (c) 2013 Andrew Shmig
//
// Permission is hereby granted, free of charge, to any person
// obtaining a copy of this software and associated documentation
// files (the "Software"), to deal in the Software without
// restriction, including without limitation the rights to use,
// copy, modify, merge, publish, distribute, sublicense, and/or
// sell copies of the Software, and to permit persons to whom the
// Software is furnished to do so, subject to the following
// conditions:
//
// The above copyright notice and this permission notice shall be
// included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
// EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
// OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE
// FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
// OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
// CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
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
- (void)startWithAppID:(NSString*)appID
            permissons:(NSArray*)permissions;

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
