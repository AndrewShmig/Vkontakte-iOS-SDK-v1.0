//
// Created by AndrewShmig on 5/28/13.
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

/** Класс предназначен для работы с лайками пользователя
 */
@interface VKLikes : NSObject

/** Добавляет указанный объект в список "Мне нравится" текущего пользователя.
 
 @param objectID идентификатор объекта
 @param type тип объекта ( со списком возможных типов объекта можно ознакомиться по
 этой ссылке https://vk.com/dev/likes.add )
 @param ownerID идентификатор владельца объекта
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)likeObjectWithID:(NSUInteger)objectID type:(NSString *)type ownerID:(NSUInteger)ownerID;

/** Удаляет указанный объект из списка "Мне нравится" текущего пользователя
 
 @param objectID идентификатор объекта
 @param type тип объекта ( со списком возможных типов объекта можно ознакомиться по
 этой ссылке https://vk.com/dev/likes.add )
 @param ownerID идентификатор владельца объекта
 @return ответ на запрос в виде Foundation объекта
 */
- (id)unlikeObjectWithID:(NSUInteger)objectID type:(NSString *)type ownerID:(NSUInteger)ownerID;

/** Проверяет, находится ли объект в списке "Мне нравится" текущего пользователя
 
 @param objectID идентификатор объекта
 @param type тип объекта ( со списком возможных типов объекта можно ознакомиться по
 этой ссылке https://vk.com/dev/likes.add )
 @return ответ на запрос в виде Foundation объекта
 
 @see isLikedObjectWithID:type:ownerID:
 
 @warning вызывается метод isLikedObjectWithID:type:ownerID: с последним параметром
 равным идентификатору текущего пользователя.
 */
- (id)isLikedObjectWithID:(NSUInteger)objectID type:(NSString *)type;

/** Проверяет, находится ли объект в списке "Мне нравится" текущего пользователя
 
 @param objectID идентификатор объекта
 @param type тип объекта ( со списком возможных типов объекта можно ознакомиться по
 этой ссылке https://vk.com/dev/likes.add )
 @param ownerID идентификатор владельца Like-объекта
 @return ответ на запрос в виде Foundation объекта
 
 @see isLikedObjectWithID:type:ownerID:
 */
- (id)isLikedObjectWithID:(NSUInteger)objectID type:(NSString *)type ownerID:(NSUInteger)ownerID;

/** Получает список идентификаторов пользователей, которые добавили заданный 
 объект в свой список "Мне нравится"
 
 @param options описания списка опций можно найти на этой странице https://vk.com/dev/likes.getList
 
 Опции представляют собой список ключ-значение:
 
     @{@"type": @"comment", @"filter": @"copies"}
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)obtainListWithOptions:(NSDictionary *)options;

@end