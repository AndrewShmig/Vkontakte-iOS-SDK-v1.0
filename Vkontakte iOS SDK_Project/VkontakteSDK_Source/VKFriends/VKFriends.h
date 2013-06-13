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

/** Класс предназначен для работы с друзьями пользователя, списками друзей,
 запросами в друзья и тд.
 */
@interface VKFriends : NSObject

/**
 @name friends.get
 */

/** Возвращает список идентификаторов друзей пользователя
 
 @param count количество друзей, которое нужно вернуть
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsCount:(NSUInteger)count;

/** Возвращает список идентификаторов друзей пользователя и расширенную информацию о друзьях пользователя
 
 @param count количество друзей, которое нужно вернуть
 @param fields перечисленные через запятую поля анкет, необходимые для получения
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsCount:(NSUInteger)count fields:(NSString *)fields;

/** Возвращает список идентификаторов друзей пользователя
 
 @param count количество друзей, которое нужно вернуть
 @param offset смещение, необходимое для выборки определенного подмножества друзей
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsCount:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список идентификаторов друзей пользователя или расширенную информацию о друзьях пользователя
 
 @param count количество друзей, которое нужно вернуть
 @param offset смещение, необходимое для выборки определенного подмножества друзей
 @param fields перечисленные через запятую поля анкет, необходимые для получения
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsCount:(NSUInteger)count offset:(NSUInteger)offset fields:(NSString *)fields;

/** Возвращает список идентификаторов друзей пользователя или расширенную информацию о друзьях пользователя
 
 @param count количество друзей, которое нужно вернуть
 @param offset смещение, необходимое для выборки определенного подмножества друзей
 @param order порядок, в котором нужно вернуть список друзей. 
 Допустимые значения: name - сортировать по имени (работает только при переданном 
 параметре fields). hints - сортировать по рейтингу, аналогично тому, как друзья 
 сортируются в разделе Мои друзья. 
 random - возвращает друзей в случайном порядке.
 @param fields перечисленные через запятую поля анкет, необходимые для получения
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsCount:(NSUInteger)count offset:(NSUInteger)offset order:(NSString *)order fields:(NSString *)fields;

/** Возвращает список идентификаторов друзей пользователя или расширенную информацию о друзьях пользователя (при использовании параметра fields).
 
 @param options словарь ключи-значения ( со списком ключей можно ознакомиться по этой ссылке https://vk.com/dev/friends.get )
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsCustomOptions:(NSDictionary *)options;

/**
 @name friends.getOnline
 */
/** Возвращает список идентификаторов друзей пользователя, находящихся на сайте
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsOnline;

/** Возвращает список идентификаторов друзей пользователя, находящихся на сайте
 
 @param count количество друзей онлайн, которое нужно вернуть
 @param offset смещение, необходимое для выборки определенного подмножества друзей онлайн
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsOnlineCount:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список идентификаторов друзей пользователя, находящихся на сайте
 
 @param options словарь ключи-значения ( со списком ключей можно ознакомиться по этой ссылке https://vk.com/dev/friends.getOnline )
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsOnlineCustomOptions:(NSDictionary *)options;

/**
 @name friends.getMutual
 */
/** Возвращает список идентификаторов общих друзей между текущим пользователем и указанным пользователем
 
 @param userID идентификатор пользователя общих друзей с котором необходимо определить
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsMutualWithUserID:(NSUInteger)userID;

/** Возвращает список идентификаторов общих друзей между текущим пользователем и указанным пользователем
 
 @param userID идентификатор пользователя общих друзей с котором необходимо определить
 @param count количество общих друзей, которое нужно вернуть
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsMutualWithUserID:(NSUInteger)userID count:(NSUInteger)count;

/** Возвращает список идентификаторов общих друзей между текущим пользователем и указанным пользователем
 
 @param userID идентификатор пользователя общих друзей с котором необходимо определить
 @param count количество общих друзей, которое нужно вернуть
 @param offset смещение, необходимое для выборки определенного подмножества общих друзей
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsMutualWithUserID:(NSUInteger)userID count:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список идентификаторов общих друзей между парой пользователей
 
 Дополнительная информация по обязательным ключам и форматам значений находится
 по этой ссылке https://vk.com/dev/friends.getMutual
 
 _Пример:_
 
    @{@"source_id": @1, 
      @"target_id": @3, 
      @"order": @"random"}
 
 @param options словарь ключи-значения
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsMutualCustomOptions:(NSDictionary *)options;

/**
 @name friends.getRecent
 */
/** Возвращает список идентификаторов недавно добавленных друзей текущего пользователя
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsGetRecent;

/** Возвращает список идентификаторов недавно добавленных друзей текущего пользователя
 
 @param count максимальное количество недавно добавленных друзей, которое необходимо получить (не более 1000).
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsGetRecentCount:(NSUInteger)count;

/**
 @name friends.getRequests
 */
/** Возвращает информацию о полученных заявках на добавление в друзья для текущего пользователя
 
 @param count максимальное количество заявок на добавление в друзья, которые необходимо получить (не более 1000)
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsInRequestsCount:(NSUInteger)count;

/** Возвращает информацию о полученных заявках на добавление в друзья для текущего пользователя
 
 @param count максимальное количество заявок на добавление в друзья, которые необходимо получить (не более 1000)
 @param offset смещение, необходимое для выборки определенного подмножества заявок на добавление в друзья
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsInRequestsCount:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает информацию об отправленных заявках на добавление в друзья для текущего пользователя
 
 @param count максимальное количество заявок на добавление в друзья, которые необходимо получить (не более 1000)
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsOutRequestsCount:(NSUInteger)count;

/** Возвращает информацию об отправленных заявках на добавление в друзья для текущего пользователя
 
 @param count максимальное количество заявок на добавление в друзья, которые необходимо получить (не более 1000)
 @param offset смещение, необходимое для выборки определенного подмножества заявок на добавление в друзья
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsOutRequestsCount:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает информацию о полученных или отправленных заявках на добавление в друзья для текущего пользователя
 
 _Пример:_
 
    @{@"need_count": @1,
      @"offset": @20,
      @"count": @10,
      @"out": @1}

 Cо всеми ключами и возможными значениями можно ознакомиться по этой ссылке: https://vk.com/dev/friends.getRequests
 
 @param options словарь ключи-значения
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsRequestsCustomOptions:(NSDictionary *)options;

/**
 @name friends.add
 */
/** Одобряет или создает заявку на добавление в друзья.
 
 Если идентификатор выбранного пользователя присутствует в списке заявок на добавление в друзья, полученном методом friends.getRequests, то одобряет заявку на добавление и добавляет выбранного пользователя в друзья к текущему пользователю. В противном случае создает заявку на добавление в друзья текущего пользователя к выбранному пользователю.
 
 @param userID идентификатор пользователя
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsAddUserID:(NSUInteger)userID;

/** Одобряет или создает заявку на добавление в друзья.
 
 Если идентификатор выбранного пользователя присутствует в списке заявок на добавление в друзья, полученном методом friends.getRequests, то одобряет заявку на добавление и добавляет выбранного пользователя в друзья к текущему пользователю. В противном случае создает заявку на добавление в друзья текущего пользователя к выбранному пользователю.
 
 @param userID идентификатор пользователя
 @param text текст сопроводительного сообщения для заявки на добавление в друзья. Максимальная длина сообщения — 500 символов.
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsAddUserID:(NSUInteger)userID text:(NSString *)text;

/**
 @name friends.edit
 */
/** Редактирует списки друзей для выбранного друга
 
 _Пример:_
 
     @{@"uid": @1,
       @"lids": @"1,2,3"}
 
 Cо всеми ключами и возможными значениями можно ознакомиться по этой ссылке: https://vk.com/dev/friends.edit
 
 @param options словарь ключи-значения
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsEditCustomOptions:(NSDictionary *)options;

/**
 @name friends.delete
 */
/** Удаляет пользователя из списка друзей или отклоняет заявку в друзья.
 
 Если идентификатор выбранного пользователя присутствует в списке заявок на добавление в друзья, полученном методом friends.getRequests, то отклоняет заявку на добавление в друзья к текущему пользователю. В противном случае удаляет выбранного пользователя из списка друзей текущего пользователя, который может быть получен методом friends.get.
 
 @param userID идентификатор пользователя
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsRemoveUserID:(NSUInteger)userID;

/**
 @name friends.getLists
 */
/** Возвращает список меток друзей текущего пользователя
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsLists;

/**
 @name friends.addList
 */
/** Создает новый список друзей у текущего пользователя
 
 @param listName название создаваемого списка друзей
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsCreateNewList:(NSString *)listName;

/** Создает новый список друзей у текущего пользователя
 
 @param listName название создаваемого списка друзей
 @param friendsIDs идентификаторы друзей пользователя, которых необходимо включить в создаваемый список. Идентификаторы пользователей, не являющихся друзьями текущего пользователя, игнорируются
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsCreateNewList:(NSString *)listName friendsIDs:(NSArray *)friendsIDs;

/**
 @name friends.editList
 */
/** Редактирует существующий список друзей текущего пользователя
 
 @param options словарь ключей-значений, детальная информация по этой ссылке : https://vk.com/dev/friends.editList
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsEditListCustomOptions:(NSDictionary *)options;

/**
 @name friends.deleteList
 */
/** Удаляет существующий список друзей текущего пользователя
 
 @param listID идентификатор списка друзей, который необходимо удалить
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsDeleteListID:(NSUInteger)listID;

/**
 @name friends.getAppUsers
 */
/** Возвращает список идентификаторов друзей текущего пользователя, которые установили данное приложение
 
 @return ответ на запрос в виде Foundation объекта 
 */
- (id)friendsInCurrentApplication;

/**
 @name friends.getByPhones
 */
/** Возвращает список друзей пользователя, у которых завалидированные или указанные в профиле телефонные номера входят в заданный список
 
 @param phones список телефонных номеров в формате MSISDN. Максимальное количество номеров в списке — 1000.
 @param fields перечисленные через запятую поля анкет, необходимые для получения
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsByPhones:(NSArray *)phones fields:(NSArray *)fields;

/**
 @name friends.deleteAllRequests
 */
/** Отмечает все входящие заявки на добавление в друзья как просмотренные
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsDeleteRequests;

/**
 @name friends.getSuggestions
 */
/** Возвращает список профилей пользователей, которые могут быть друзьями текущего пользователя
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsSuggestions;

/** Возвращает список профилей пользователей, которые могут быть друзьями текущего пользователя
 
 @param count количество рекомендаций, которое необходимо вернуть
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsSuggestionsCount:(NSUInteger)count;

/** Возвращает список профилей пользователей, которые могут быть друзьями текущего пользователя
 
 @param count количество рекомендаций, которое необходимо вернуть
 @param offset смещение, необходимое для выбора определённого подмножества списка
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsSuggestionsCount:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список профилей пользователей, которые могут быть друзьями текущего пользователя
 
 @param count количество рекомендаций, которое необходимо вернуть
 @param offset смещение, необходимое для выбора определённого подмножества списка
 @param fields перечисленные через запятую поля анкет, необходимые для получения
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsSuggestionsCount:(NSUInteger)count offset:(NSUInteger)offset fields:(NSArray *)fields;

/** Возвращает список профилей пользователей, которые могут быть друзьями текущего пользователя
 
 @param options словарь ключей-значений, детальная информация по этой ссылке : https://vk.com/dev/friends.getSuggestions
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsSuggestionsCustomOptions:(NSDictionary *)options;

/**
 @name friends.areFriends
 */
/** Возвращает информацию о том, добавлен ли текущий пользователь в друзья у указанных пользователей.
 
 Также возвращает информацию о наличии исходящей или входящей заявки в друзья (подписки).
 
 @param userIDs Список идентификаторов пользователей, статус дружбы с которыми необходимо получить
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsWithUsers:(NSArray *)userIDs;

@end