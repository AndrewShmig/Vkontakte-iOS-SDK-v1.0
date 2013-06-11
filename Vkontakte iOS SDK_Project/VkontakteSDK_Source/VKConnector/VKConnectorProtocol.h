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
@class VKConnector;

/** Протокол объявляет методы отслеживания изменения статуса токена доступа 
 хранимого классом VKConnector.
 */
@protocol VKConnectorProtocol <NSObject>

@optional
/** Метод, вызов которого сигнализирует о том, что токен стал недействительным,
 срок его действия истёк.
 
 @param connector объект класса VKConnector отправляющий сообщение.
 @param accessToken токен доступа, срок действия которого истёк.
 */
- (void)VKConnector:(VKConnector *)connector
accessTokenInvalidated:(VKAccessToken *)accessToken;

/** Метод, вызов которого сигнализирует о том, что токен доступа успешно обновлён.
 
 @param connector объект класса VKConnector отправляющий сообщение.
 @param accessToken новый токен доступа, который был получен.
 */
- (void)VKConnector:(VKConnector *)connector
 accessTokenRenewed:(VKAccessToken *)accessToken;

/** Метод, вызов которого сигнализирует о том, что обновление токена доступа не
 удалось.
 Причиной ошибки может быть прерывание связи, либо пользователь отказался авторизовывать
 приложение.
 
 @param connector объект класса VKConnector отправляющего сообщение.
 @param accessToken токен доступа (равен nil)
 */
- (void)VKConnector:(VKConnector *)connector
accessTokenRenewalFailed:(VKAccessToken *)accessToken;

@end
