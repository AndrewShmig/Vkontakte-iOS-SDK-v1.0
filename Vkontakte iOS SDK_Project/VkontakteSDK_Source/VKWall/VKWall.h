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

/** Класс предназначен для работы со стеной пользователя.
 */
@interface VKWall : NSObject

/**
 @name wall.get
 */
/** Возвращает список записей со стены пользователя
 
 @param count количество записей, которое необходимо получить (но не более 100)
 @param offset смещение, необходимое для выборки определенного подмножества записей
 @return ответ на запрос в виде Foundation объекта
 */
- (id)count:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список записей со стены пользователя
 
 @param count количество записей, которое необходимо получить (но не более 100)
 @param offset смещение, необходимое для выборки определенного подмножества записей
 @param ownerID идентификатор пользователя или сообщества, со стены которого необходимо получить записи
 @return ответ на запрос в виде Foundation объекта
 */
- (id)count:(NSUInteger)count offset:(NSUInteger)offset ownerID:(NSUInteger)ownerID;

/** Возвращает список записей со стены пользователя или сообщества
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/wall.get
 @return ответ на запрос в виде Foundation объекта
 */
- (id)customOptions:(NSDictionary *)options;

/**
 @name wall.getById
 */
/** Возвращает список записей со стен пользователей по их идентификаторам
 
 @param postsIDs перечисленные через запятую идентификаторы, которые представляют собой идущие через знак подчеркивания id владельцев стен и id самих записей на стене
 @return ответ на запрос в виде Foundation объекта
 */
- (id)byIDs:(NSArray *)postsIDs;

/**
 @name wall.savePost
 */
/** Сохраняет запись на стене пользователя. Запись может содержать фотографию, ранее загруженную на сервер ВКонтакте, или любую доступную фотографию из альбома пользователя
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/wall.savePost
 @return ответ на запрос в виде Foundation объекта
 */
- (id)savePostCustomOptions:(NSDictionary *)options;

/**
 @name wall.post
 */
/** Публикует новую запись на своей или чужой стене.
 Данный метод позволяет создать новую запись на стене, а также опубликовать предложенную новость или отложенную запись
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/wall.post
 @return ответ на запрос в виде Foundation объекта
 */
- (id)postCustomOptions:(NSDictionary *)options;

/**
 @name wall.repost
 */
/** Копирует объект на стену пользователя или сообщества
 
 @param objectID строковый идентификатор объекта, который необходимо разместить на стене, например wall66748_3675
 @param message сопроводительный текст, который будет добавлен к записи с объектом
 @return ответ на запрос в виде Foundation объекта
 */
- (id)repostObjectID:(NSUInteger)objectID message:(NSString *)message;

/**
 @name wall.getReposts
 */
/** Позволяет получать список репостов заданной записи
 
 @param ownerID идентификатор пользователя или сообщества, на стене которого находится запись
 @param postID идентификатор записи на стене
 @param count количество записей, которое необходимо получить
 @param offset смещение, необходимое для выборки определенного подмножества записей
 @return ответ на запрос в виде Foundation объекта
 */
- (id)repostsOwnerID:(NSUInteger)ownerID postID:(NSUInteger)postID count:(NSUInteger)count offset:(NSUInteger)offset;

/**
 @name wall.edit
 */
/** Редактирует запись на стене
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/wall.edit
 @return ответ на запрос в виде Foundation объекта
 */
- (id)editCustomOptions:(NSDictionary *)options;

/**
 @name wall.delete
 */
/** Удаляет запись со стены.
 
 @param postID идентификатор записи на стене
 @param ownerID идентификатор пользователя или сообщества, на стене которого находится запись
 @return ответ на запрос в виде Foundation объекта
 */
- (id)removePostID:(NSUInteger)postID ownerID:(NSUInteger)ownerID;

/**
 @name wall.restore
 */
/** Восстанавливает удаленную запись на стене пользователя
 
 @param ownerID идентификатор пользователя или сообщества, на стене которого находилась удаленная запись
 @param postID идентификатор записи на стене
 @return ответ на запрос в виде Foundation объекта
 */
- (id)restorePostID:(NSUInteger)postID ownerID:(NSUInteger)ownerID;

/**
 @name wall.getComments
 */
/** Возвращает список комментариев к записи на стене пользователя
 
 @param postID идентификатор записи на стене
 @param ownerID идентификатор пользователя или сообщества, на чьей стене находится запись, к которой необходимо получить комментарии
 @return ответ на запрос в виде Foundation объекта
 */
- (id)commentsPostID:(NSUInteger)postID ownerID:(NSUInteger)ownerID;

/** Возвращает список комментариев к записи на стене пользователя
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/wall.getComments
 @return ответ на запрос в виде Foundation объекта
 */
- (id)commentsCustomOptions:(NSDictionary *)options;

/**
 @name wall.addComment
 */
/** Добавляет комментарий к записи на стене пользователя или сообщества
 
 @param postID идентификатор записи на стене пользователя или сообщества
 @param ownerID идентификатор пользователя или сообщества, на чьей стене находится запись, к которой необходимо добавить комментарий
 @param text текст комментария к записи
 @return ответ на запрос в виде Foundation объекта
 */
- (id)addCommentPostID:(NSUInteger)postID ownerID:(NSUInteger)ownerID text:(NSString *)text;

/** Добавляет комментарий к записи на стене пользователя или сообщества
 
 @param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: http://vk.com/dev/wall.addComment
 @return ответ на запрос в виде Foundation объекта
 */
- (id)addCommentCustomOptions:(NSDictionary *)options;

/**
 @name wall.deleteComment
 */
/** Удаляет комментарий текущего пользователя к записи на своей или чужой стене
 
 @param commentID идентификатор комментария
 @param ownerID идентификатор пользователя, на чьей стене находится комментарий к записи
 @return ответ на запрос в виде Foundation объекта
 */
- (id)removeCommentID:(NSUInteger)commentID ownerID:(NSUInteger)ownerID;

/**
 @name wall.restoreComment
 */
/** Восстанавливает комментарий текущего пользователя к записи на своей или чужой стене
 
 @param commentID идентификатор комментария на стене
 @param ownerID идентификатор пользователя или сообщества, на стене которого находится комментарий к записи
 @return ответ на запрос в виде Foundation объекта
 */
- (id)restoreCommentID:(NSUInteger)commentID ownerID:(NSUInteger)ownerID;

@end