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

/** Класс предназначен для работы с группами от лица текущего пользователя
 */
@interface VKGroups : NSObject

/**
 @name groups.isMember
 */
/** Возвращает информацию о том, является ли пользователь участником сообщества
 
 @param groupID идентификатор или короткое имя сообщества
 @return ответ на запрос в виде Foundation объекта
 */
- (id)isMemberGroupID:(NSUInteger)groupID;

/** Возвращает информацию о том, является ли пользователь участником сообщества
 
 @param groupID идентификатор или короткое имя сообщества
 @param userID идентификатор пользователя
 @return ответ на запрос в виде Foundation объекта
 */
- (id)isMemberGroupID:(NSUInteger)groupID userID:(NSUInteger)userID;

/**
 @name groups.getById
 */
/** Возвращает информацию о заданном сообществе или о нескольких сообществах
 
 @param groupsIDs идентификаторы или короткие имена сообществ
 @return ответ на запрос в виде Foundation объекта
 */
- (id)byIDs:(NSArray *)groupsIDs;

/** Возвращает информацию о заданном сообществе или о нескольких сообществах
 
 @param groupsIDs идентификаторы или короткие имена сообществ
 @param fields список полей, которые необходимо вернуть
 @return ответ на запрос в виде Foundation объекта
 */
- (id)byIDs:(NSArray *)groupsIDs fields:(NSArray *)fields;

/**
 @name groups.get
 */
/** Возвращает список сообществ указанного пользователя
 
 @param count количество сообществ, информацию о которых нужно вернуть, не более 1000
 @param offset смещение, необходимое для выборки определённого подмножества групп
 @return ответ на запрос в виде Foundation объекта
 */
- (id)listCount:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список сообществ указанного пользователя
 
 @param count количество сообществ, информацию о которых нужно вернуть, не более 1000
 @param offset смещение, необходимое для выборки определённого подмножества групп
 @param filter список фильтров сообществ, которые необходимо вернуть, перечисленные через запятую. Доступны значения admin, groups, publics, events.
 @param fields список полей, которые необходимо вернуть
 @return ответ на запрос в виде Foundation объекта
 */
- (id)listCount:(NSUInteger)count offset:(NSUInteger)offset filter:(NSArray *)filter fields:(NSArray *)fields;

/** Возвращает список сообществ указанного пользователя
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/groups.get
 @return ответ на запрос в виде Foundation объекта
 */
- (id)listCustomOptions:(NSDictionary *)options;

/**
 @name groups.getMembers
 */
/** Возвращает список участников сообщества
 
 @param groupID идентификатор или короткое имя сообщества
 @param count количество участников сообщества, информацию о которых необходимо получить. Максимальное значение 1000.
 @param offset смещение, необходимое для выборки определенного подмножества участников
 @return ответ на запрос в виде Foundation объекта
 */
- (id)membersGroupID:(NSUInteger)groupID count:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список цчастников сообщества
 
 @param options ключи-значения, полный список : https://vk.com/dev/groups.getMembers
 @return ответ на запрос в виде Foundation объекта
 */
- (id)membersCustomOptions:(NSDictionary *)options;

/**
 @name groups.join
 */
/** Данный метод позволяет вступить в группу, публичную страницу, а также подтвердить участие во встрече
 
 @param groupID идентификатор сообщества
 @return ответ на запрос в виде Foundation объекта
 */
- (id)joinGroupID:(NSUInteger)groupID;

/** Данный метод позволяет подтвердить участие во встрече
 
 @param meetingID идентификатор сообщества
 @param notSure опциональный параметр, учитываемый, если gid принадлежит встрече. 1 — Возможно пойду. 0 — Точно пойду.
 @return ответ на запрос в виде Foundation объекта
 */
- (id)joinMeetingID:(NSUInteger)meetingID notSure:(NSUInteger)notSure;

/**
 @name groups.leave
 */
/** Данный метод позволяет выходить из группы, публичной страницы, или встречи
 
 @param groupID идентификатор сообщества
 @return ответ на запрос в виде Foundation объекта
 */
- (id)leaveGroupID:(NSUInteger)groupID;

/**
 @name groups.search
 */
/** Осуществляет поиск сообществ по заданной подстроке
 
 @param query текст поискового запроса
 @return ответ на запрос в виде Foundation объекта
 */
- (id)searchQuery:(NSString *)query;

/** Осуществляет поиск сообществ по заданной подстроке
 
 @param query текст поискового запроса
 @param count количество результатов поиска, которое необходимо вернуть.
 @return ответ на запрос в виде Foundation объекта
 */
- (id)searchQuery:(NSString *)query count:(NSUInteger)count;

/** Осуществляет поиск сообществ по заданной подстроке
 
 @param query текст поискового запроса
 @param count количество результатов поиска, которое необходимо вернуть.
 @param offset смещение, необходимое для выборки определённого подмножества результатов поиска.
 @return ответ на запрос в виде Foundation объекта
 */
- (id)searchQuery:(NSString *)query count:(NSUInteger)count offset:(NSUInteger)offset;

/** Осуществляет поиск сообществ по заданной подстроке
 
 @param query текст поискового запроса
 @param sort параметр сортировки
 
     0 - сортировать по количеству пользователей (по умолчанию)
     1 - сортировать по скорости роста
     2 - сортировать по отношению дневной посещаемости ко количеству пользователей
     3 - сортировать по отношению количества лайков к количеству пользователей
     4 - сортировать по отношению количества комментариев к количеству пользователей
     5 - сортировать по отношению количества записей в обсуждениях к количеству пользователей
 
 @param count количество результатов поиска, которое необходимо вернуть.
 @param offset смещение, необходимое для выборки определённого подмножества результатов поиска.
 @return ответ на запрос в виде Foundation объекта
 */
- (id)searchQuery:(NSString *)query sort:(NSUInteger)sort count:(NSUInteger)count offset:(NSUInteger)offset;

/**
 @name groups.getInvites
 */
/** Данный метод возвращает список приглашений в сообщества и встречи
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)invites;

/** Данный метод возвращает список приглашений в сообщества и встречи
 
 @param count количество приглашений, которое необходимо вернуть
 @return ответ на запрос в виде Foundation объекта
 */
- (id)invitesCount:(NSUInteger)count;

/** Данный метод возвращает список приглашений в сообщества и встречи
 
 @param count количество приглашений, которое необходимо вернуть
 @param offset смещение, необходимое для выборки определённого подмножества приглашений
 @return ответ на запрос в виде Foundation объекта
 */
- (id)invitesCount:(NSUInteger)count offset:(NSUInteger)offset;

@end