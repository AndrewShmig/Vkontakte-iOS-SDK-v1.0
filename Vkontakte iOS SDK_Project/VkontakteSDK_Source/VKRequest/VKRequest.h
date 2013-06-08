//
//  VKRequest.h
//  Vkontakte iOS SDK_Project
//
//  Created by AndrewShmig on 6/8/13.
//  Copyright (c) 2013 AndrewShmig. All rights reserved.
//

/** Класс VKRequest предназначен для осуществления запросов к социальной сети ВКонтакте.
 */

#import <Foundation/Foundation.h>


static NSString *const kVkontakteAPIURL = @"https://api.vk.com/method/";


@class VKAccessToken;


@interface VKRequest : NSObject

/** Токен доступа, который будет использоваться при осуществлении запросов.
 */
@property (nonatomic, readonly) VKAccessToken *accessToken;

/** Основной метод инициализации
 
 @param accessToken Токен доступа, который будет использоваться при осуществлении запросов.
 @return Объект типа VKRequest
 */
- (id)initWithAccessToken:(VKAccessToken *)accessToken;

/** Основной метод осуществления GET запросов.
 
 @param methodName Наименование метода к которому необходимо осуществить запрос.
 Со списком методов можно ознакомиться в документации по ссылке: https://vk.com/dev/methods
 либо в заголовочном файле VKMethods.h
 
 _Возможные значения:_ kVKUsersGet, @"users.get" и тд
 
 @param options Словарь ключей-значений требуемых для корректного осуществления запроса и получения информации.
 С каждым списком параметров можно ознакомиться в документации соответствующего метода.
 
 @param error В случае возникновения ошибки она будет передана в данной переменной. Ошибки могут быть двух типов:
 ошибка запроса (прервалось соединение и тд) и ошибки парсинга ответа сервера.
 Возвращаемые ошибки сервером в запросе не подвергаются обработке.
 */
- (id)performVKMethod:(NSString *)methodName
              options:(NSDictionary *)options
                error:(NSError **)error;

@end
