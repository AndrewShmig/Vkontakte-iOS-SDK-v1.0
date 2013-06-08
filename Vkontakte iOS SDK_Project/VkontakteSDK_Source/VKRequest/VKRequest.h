//
//  VKRequest.h
//  Vkontakte iOS SDK_Project
//
//  Created by AndrewShmig on 6/8/13.
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
//

/** Класс VKRequest предназначен для осуществления запросов к социальной сети ВКонтакте.
 */

#import <Foundation/Foundation.h>


typedef void (^VKCompletionBlock)(SEL selector, id response, NSError *error);

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
