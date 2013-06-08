//
// Created by AndrewShmig on 5/28/13.
//
// Copyright (c) AndrewShmig. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "VKRequest.h"


@class VKAccessToken; //+
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

/** Токен доступа
 */
@property (nonatomic, readwrite) VKAccessToken *token;

/** Блок-обработчик вызываемый после выполнения запросов.
 Выглядит следующим образом:
 
     void (^VKCompletionBlock)(SEL selector, id response, NSError *error)
 
 где:
 
 + SEL - селектор метода, который был вызван последним
 + response - ответ сервера
 + error - ошибка произошедшая во время осуществления запроса
 
 */
@property (nonatomic, copy, readwrite) VKCompletionBlock completionBlock;

/** Статусы.
 */
@property (nonatomic, readonly) VKStatus *status;

/** Стена.
 */
@property (nonatomic, readonly) VKWall *wall;

/** Фото альбомы.
 */
@property (nonatomic, readonly) VKPhotoAlbums *photoAlbums;

/** Аудио альбомы.
 */
@property (nonatomic, readonly) VKAudioAlbums *audioAlbums;

/** Видео альбомы.
 */
@property (nonatomic, readonly) VKVideoAlbums *videoAlbums;

/** Друзья пользователя.
 */
@property (nonatomic, readonly) VKFriends *friends;

/** Группы.
 */
@property (nonatomic, readonly) VKGroups *groups;

/** Записи.
 */
@property (nonatomic, readonly) VKNotes *notes;

/** Места.
 */
@property (nonatomic, readonly) VKPlaces *places;

/** Сообщения.
 */
@property (nonatomic, readonly) VKMessages *messages;

/** Новости.
 */
@property (nonatomic, readonly) VKNewsfeed *newsfeed;

/** "Мне нравится".
 */
@property (nonatomic, readonly) VKLikes *likes;

/** Документы/файлы.
 */
@property (nonatomic, readonly) VKDocs *docs;

/** Закладки.
 */
@property (nonatomic, readonly) VKFavourites *favourites;

/** Основной метод инициализации.
 
 @param accessToken Пользовательский токен доступа.
 */
- (id)initWithVKAccessToken:(VKAccessToken *)accessToken;

/** Запрос информации о текущем пользователе.
 
 Информация, которая будет запрошена:
 
 + nickaname
 + screen_name
 + sex
 + bdate
 + city
 + photo
 + online
 + last_seen
 + status
 
 Со списком всех доступных данных можно ознакомиться по этой ссылке: https://vk.com/dev/users.get
 */
- (void)info;

/** Запрос информации об определенном пользователе.
 
 @param user Пользователь о котором необходимо получить данные.
 @param fields Список полей (данных), которые необходимо запросить. 
 С полным списком данных можно ознакомиться по этой ссылке: https://vk.com/dev/users.get
 */
- (void)infoAboutUser:(VKUser *)user fields:(NSArray *)fields;

/** Запрос на проверку того, что пользователь установил наше приложение.
 С форматов возвращаемых сервером данных можно ознакомиться по этой ссылке: https://vk.com/dev/users.isAppUser
 */
- (void)isApplicationUser;

/** Возвращает список идентификаторов пользователей и групп, которые входят в список подписок пользователя.
 
 @param count кол-во записей, которые необходимо вернуть.
 @param offset cмещение необходимое для выборки определенного подмножества подписок.
 */
- (void)subscriptionsCount:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список идентификаторов пользователей, которые являются подписчиками пользователя. Идентификаторы пользователей в списке отсортированы в порядке убывания времени их добавления.
 
 @param count количество подписчиков, информацию о которых нужно получить.
 @param offset смещение, необходимое для выборки определенного подмножества подписчиков.
 @param fields перечисленные через запятую поля анкет, необходимые для получения.
 @param nameCase падеж для склонения имени и фамилии пользователя. Возможные значения: именительный – nom, родительный – gen, дательный – dat, винительный – acc, творительный – ins, предложный – abl.
 */
- (void)followersCount:(NSUInteger)count offset:(NSUInteger)offset fields:(NSArray *)fields nameCase:(NSString *)nameCase;

@end