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

@class VKStatus;
@class VKWall;
@class VKPhotoAlbums;
@class VKAudioAlbums;
@class VKVideoAlbums;
@class VKFriends;
@class VKGroups;
@class VKNotes;
@class VKPlaces;
@class VKMessages;
@class VKNewsfeed;
@class VKLikes;
@class VKDocs;
@class VKFavourites;

/**
 Класс представляет пользователя социальной сети со связями вроде
 стены, аудиозаписей, видеозаписей, сообщений и тд.
 */
@interface VKUser : NSObject

/** Идентификатор пользователя
 */
@property (nonatomic, readonly) NSUInteger userID;

/** Список доступов, которые пользователь предоставил
 */
@property (nonatomic, readonly) NSArray *userPermissions;

/**
 @name Связи пользователя
 */

/** Статус пользователя
 */
@property (nonatomic, strong, readonly) VKStatus *status;

/** Стена
 */
@property (nonatomic, strong, readonly) VKWall *wall;

/** Фото альбомы
 */
@property (nonatomic, strong, readonly) VKPhotoAlbums *photoAlbums;

/** Аудио альбомы
 */
@property (nonatomic, strong, readonly) VKAudioAlbums *audioAlbums;

/** Видео альбомы
 */
@property (nonatomic, strong, readonly) VKVideoAlbums *videoAlbums;

/** Друзья пользователя
 */
@property (nonatomic, strong, readonly) VKFriends *friends;

/** Группы
 */
@property (nonatomic, strong, readonly) VKGroups *groups;

/** Записки
 */
@property (nonatomic, strong, readonly) VKNotes *notes;

/** Места
 */
@property (nonatomic, strong, readonly) VKPlaces *places;

/** Сообщения
 */
@property (nonatomic, strong, readonly) VKMessages *messages;

/** Лента новостей
 */
@property (nonatomic, strong, readonly) VKNewsfeed *newsfeed;

/** "Мне нравится"
 */
@property (nonatomic, strong, readonly) VKLikes *likes;

/** Документы
 */
@property (nonatomic, strong, readonly) VKDocs *docs;

/** Избранное
 */
@property (nonatomic, strong, readonly) VKFavourites *favourites;

/**
 @name Текущий пользователь
 */

/** Текущий пользователь от лица которого будут совершаться все запросы.
 */
+ (id)currentUser;

/**
 @name Информация о пользователях
 */

/** Получение информации о текущем пользователе.
 
Данные, которые будут получены:
 
 - first_name (имя)
 - last_name (фамилия)
 - nickname (ник)
 - sex (пол)
 - bdate (дата рождения)
 - city (город)
 - country (страна)
 - photo_medium (фотография среднего размера)
 - online (онлайн/оффлайн ли пользователь)
 - last_seen (время последнего посещения)
 - status (статус пользователя)
 
 Имя и фамилия будут в именительном падеже.
 
 С форматом возвращаемых данных можно ознакомиться по этой ссылке: https://vk.com/dev/users.get
 
 @return ответ на запрос в виде Foundation объекта
 
 @see infoAboutUserWithID:fields:nameCase:
 */
- (id)info;

/** Получение информации о пользвоателе.
 
 Имя и фамилия будут в в именительном падеже.
 
 @param userID идентификатор пользователя о котором необходимо получить информацию
 @param fields данные, которые необходимо получить ( со списком возможных можно 
 ознакомиться по этой ссылке https://vk.com/dev/users.get )
 
 @return ответ на запрос в виде Foundation объекта

 @see infoAboutUserWithID:fields:nameCase:
 */
- (id)infoAboutUserWithID:(NSUInteger)userID fields:(NSArray *)fields;

/** Получение информации о пользователе.
 
 @param userID идентификатор пользователя о котором необходимо получить информацию
 @param fields перечисленные через запятую поля анкет, необходимые для получения ( со списком возможных можно
 ознакомиться по этой ссылке https://vk.com/dev/users.get )
 @param nameCase падеж в котором будут возвращены имя и фамилия пользователя
 @return ответ на запрос в виде Foundation объекта
 */
- (id)infoAboutUserWithID:(NSUInteger)userID fields:(NSArray *)fields nameCase:(NSString *)nameCase;

/**
 @name Поиск пользователей
 */

/** Поиск пользователей
 
 @param options набор опций по которым необходимо произвести поиск пользовтелей 
 ( со списком параметров можно ознакомиться по этой ссылке https://vk.com/dev/users.search )
 @return ответ на запрос в виде Foundation объекта
 */
- (id)searchUsersWithOptions:(NSDictionary *)options;


/**
 @name Приложение
 */

/** Установил ли пользователь текущее приложение.
 
 @param userID идентификатор пользователя, которого хотим проверить
 @return ответ на запрос в виде Foundation объекта ( с форматом возвращаемых данных
 можно ознакомиться по данной ссылке https://vk.com/dev/users.isAppUser )
 */
- (id)isApplicationUserID:(NSUInteger)userID;


/**
 @name Подписки пользователя
 */

/** Возвращает список идентификаторов пользователей и групп, которые входят в список подписок пользователя.
 
 @return ответ на запрос в виде Foundation объекта ( с форматом возвращаемых данных
 можно ознакомиться по этой ссылке https://vk.com/dev/users.getSubscriptions )
 
  @see subscriptionsOfUserWithID:count:offset:
 */
- (id)subscriptions;

/** Возвращает список идентификаторов пользователей и групп, которые входят в список подписок пользователя.
 
 @param count количество подписок, которые необходимо вернуть
 @param offset смещение необходимое для выборки определенного подмножества подписок
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)subscriptionsCount:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список идентификаторов пользователей и групп, которые входят в список подписок пользователя.
 
 @param userID идентификатор пользователя, подписки которого необходимо получить
 @param count количество подписок, которые необходимо вернуть
 @param offset смещение необходимое для выборки определенного подмножества подписок
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)subscriptionsOfUserWithID:(NSUInteger)userID count:(NSUInteger)count offset:(NSUInteger)offset;

/**
 @name Подписчики пользователя
 */

/** Возвращает список идентификаторов пользователей, которые являются подписчиками пользователя. Идентификаторы пользователей в списке отсортированы в порядке убывания времени их добавления.
 
 @return ответ на запрос в виде Foundation объекта ( с форматом возвращаемых
 данных можно ознакомиться по этой ссылке https://vk.com/dev/users.getFollowers )
 
 @see followersCount:offset:fields:
 */
- (id)followers;

/** Возвращает список идентификаторов пользователей, которые являются подписчиками пользователя. Идентификаторы пользователей в списке отсортированы в порядке убывания времени их добавления.
 
 @param count количество подписчиков, информацию о которых нужно получить
 @param offset смещение, необходимое для выборки определенного подмножества подписчиков
 @return ответ на запрос в виде Foundation объекта ( с форматом возвращаемых
 данных можно ознакомиться по этой ссылке https://vk.com/dev/users.getFollowers )
 
 @see followersCount:offset:fields:
 */
- (id)followersCount:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список идентификаторов пользователей, которые являются подписчиками пользователя. Идентификаторы пользователей в списке отсортированы в порядке убывания времени их добавления.
 
 @param count количество подписчиков, информацию о которых нужно получить
 @param offset смещение, необходимое для выборки определенного подмножества подписчиков
 @param fields перечисленные через запятую поля анкет, необходимые для получения
 @return ответ на запрос в виде Foundation объекта ( с форматом возвращаемых
 данных можно ознакомиться по этой ссылке https://vk.com/dev/users.getFollowers )
 */
- (id)followersCount:(NSUInteger)count offset:(NSUInteger)offset fields:(NSArray *)fields;

/** Возвращает список идентификаторов пользователей, которые являются подписчиками пользователя. Идентификаторы пользователей в списке отсортированы в порядке убывания времени их добавления.
 
 @param userID идентификатор пользователя подписки которого необходимо получить
 @param count количество подписчиков, информацию о которых нужно получить
 @param offset смещение, необходимое для выборки определенного подмножества подписчиков

 @return ответ на запрос в виде Foundation объекта ( с форматом возвращаемых
 данных можно ознакомиться по этой ссылке https://vk.com/dev/users.getFollowers )
 
 @see followersOfUserWithID:count:offset:fields:
 */
- (id)followersOfUserWithID:(NSUInteger)userID count:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список идентификаторов пользователей, которые являются подписчиками пользователя. Идентификаторы пользователей в списке отсортированы в порядке убывания времени их добавления.
 
 @param userID идентификатор пользователя подписки которого необходимо получить
 @param count количество подписчиков, информацию о которых нужно получить
 @param offset смещение, необходимое для выборки определенного подмножества подписчиков
 @param fields перечисленные через запятую поля анкет, необходимые для получения
 
 @return ответ на запрос в виде Foundation объекта ( с форматом возвращаемых
 данных можно ознакомиться по этой ссылке https://vk.com/dev/users.getFollowers )
 */
- (id)followersOfUserWithID:(NSUInteger)userID count:(NSUInteger)count offset:(NSUInteger)offset fields:(NSArray *)fields;

@end