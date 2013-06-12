//
// Created by AndrewShmig on 5/28/13.
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
//

#import <Foundation/Foundation.h>

/** Класс предназначен для работы со статусами пользователя/группы.
 Детальная информация находится по этой ссылке: https://vk.com/dev/status
 */
@interface VKStatus : NSObject

/**
 @name Чтение статуса
 */

/** Получает текст статуса текущего пользователя
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)status;

/** Получает текст статуса пользователя c указанным идентификатором
 
 @param userID идентификатор пользователя статус которого необходимо получить
 @return ответ на запрос в виде Foundation объекта
 */
- (id)statusUserID:(NSUInteger)userID;

/** Получает текст статуса сообщества c указанным идентификатором
 
 @param groupID идентификатор сообщества, информацию о статусе которого необходимо получить
 @return ответ на запрос в виде Foundation объекта
 */
- (id)statusGroupID:(NSUInteger)groupID;

/**
 @name Изменение статуса
 */

/** Устанавливает новый статус текущему пользователю
 
 @param newStatusText текст нового статуса
 @return ответ на запрос в виде Foundation объекта
 */
- (id)setStatus:(NSString *)newStatusText;

@end