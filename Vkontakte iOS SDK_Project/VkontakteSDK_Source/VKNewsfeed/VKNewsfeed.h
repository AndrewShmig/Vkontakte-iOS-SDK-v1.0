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


/** Класс предназначен для работы с новостями пользователя.
 */
@interface VKNewsfeed : NSObject

/**
 @name newsfeed.get
 */
/** Возвращает данные, необходимые для показа списка новостей для текущего пользователя
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/newsfeed.get
 @return ответ на запрос в виде Foundation объекта
 */
- (id)filterCustomOptions:(NSDictionary *)options;

/**
 @name newsfeed.getRecommended
 */
/** Получает список новостей, рекомендованных пользователю
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/newsfeed.getRecommended
 @return ответ на запрос в виде Foundation объекта
 */
- (id)recommendedCustomOptions:(NSDictionary *)options;

/**
 @name newsfeed.getComments
 */
/** Возвращает данные, необходимые для показа раздела комментариев в новостях пользователя
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/newsfeed.getComments
 @return ответ на запрос в виде Foundation объекта
 */
- (id)commentsCustomOptions:(NSDictionary *)options;

/**
 @name newsfeed.getMentions
 */
/** Возвращает список записей пользователей на своих стенах, в которых упоминается указанный пользователь.
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/newsfeed.getMentions
 @return ответ на запрос в виде Foundation объекта
 */
- (id)mentionsCustomOptions:(NSDictionary *)options;

/**
 @name newsfeed.getBanned
 */
/** Возвращает список пользователей и групп, которые текущий пользователь скрыл из ленты новостей
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)banned;

/** Возвращает список пользователей и групп, которые текущий пользователь скрыл из ленты новостей
 
 Возвращается дополнительная информация о пользователях и группах
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)bannedExtended;

/** Возвращает список пользователей и групп, которые текущий пользователь скрыл из ленты новосте
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/newsfeed.getBanned
 @return ответ на запрос в виде Foundation объекта
 */
- (id)bannedCustomOptions:(NSDictionary *)options;

/**
 @name newsfeed.addBan
 */
/** Запрещает показывать новости от заданных пользователей и групп в ленте новостей текущего пользователя
 
 @param usersIDs перечисленные через запятую идентификаторы друзей пользователя, новости от которых необходимо скрыть из ленты новостей текущего пользователя
 @return ответ на запрос в виде Foundation объекта
 */
- (id)banUsers:(NSArray *)usersIDs;

/** Запрещает показывать новости от заданных пользователей и групп в ленте новостей текущего пользователя
 
 @param groupsIDs перечисленные через запятую идентификаторы групп пользователя, новости от которых необходимо скрыть из ленты новостей текущего пользователя
 @return ответ на запрос в виде Foundation объекта
 */
- (id)banGroups:(NSArray *)groupsIDs;

/**
 @name newsfeed.deleteBan
 */
/** Разрешает показывать новости от заданных пользователей и групп в ленте новостей текущего пользователя
 
 @param usersIDs идентификаторы пользователей, новости от которых необходимо вернуть в ленту.
 @return ответ на запрос в виде Foundation объекта
 */
- (id)unbanUsers:(NSArray *)usersIDs;

/** Разрешает показывать новости от заданных пользователей и групп в ленте новостей текущего пользователя
 
 @param groupsIDs идентификаторы сообществ, новости от которых необходимо вернуть в ленту
 @return ответ на запрос в виде Foundation объекта
 */
- (id)unbanGroups:(NSArray *)groupsIDs;

/**
 @name newsfeed.search
 */
/** Возвращает результаты поиска по статусам
 
 @param options ключи-значени, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/newsfeed.search
 @return ответ на запрос в виде Foundation объекта
 */
- (id)searchCustomOptions:(NSDictionary *)options;

/**
 @name newsfeed.getLists
 */
/** Возвращает пользовательские списки новостей
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)lists;

/**
 @name newsfeed.unsibscribe
 */
/** Отписывает текущего пользователя от комментариев к заданному объекту
 
 @param type тип объекта, от комментариев к которому необходимо отписаться (детально : https://vk.com/dev/newsfeed.unsubscribe)
 @param ownerID идентификатор владельца объекта
 @param objectID идентификатор объекта
 @return ответ на запрос в виде Foundation объекта
 */
- (id)unsibscribeType:(NSString *)type ownerID:(NSUInteger)ownerID objectID:(NSUInteger)objectID;

@end