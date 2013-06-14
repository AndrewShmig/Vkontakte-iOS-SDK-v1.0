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

/**
 Класс предназначен для работы с заметками пользователя
 */
@interface VKNotes : NSObject

/**
 @name notes.get
 */
/** Возвращает список заметок, созданных пользователем
 
 Заметки отсортированы по дате создания в порядке убывания.
 
 @param count количество заметок, информацию о которых необходимо получить
 @return ответ на запрос в виде Foundation объекта
 */
- (id)count:(NSUInteger)count;

/** Возвращает список заметок, созданных пользователем
 
 Заметки отсортированы по дате создания в порядке убывания.
 
 @param count количество заметок, информацию о которых необходимо получить
 @param offset смещение, необходимое для выборки определенного подмножества заметок
 @return ответ на запрос в виде Foundation объекта
 */
- (id)count:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает список заметок, созданных пользователем
 
 @param count количество заметок, информацию о которых необходимо получить
 @param offset смещение, необходимое для выборки определенного подмножества заметок
 @param sort сортировка результатов (0 — по дате создания в порядке убывания, 1 - по дате создания в порядке возрастания).
 @return ответ на запрос в виде Foundation объекта
 */
- (id)count:(NSUInteger)count offset:(NSUInteger)offset sort:(NSUInteger)sort;

/** Возвращает список заметок, созданных пользователем

 @param notesIDs идентификаторы заметок, информацию о которых необходимо получить
 @param count количество заметок, информацию о которых необходимо получить
 @param offset смещение, необходимое для выборки определенного подмножества заметок
 @param sort сортировка результатов (0 — по дате создания в порядке убывания, 1 - по дате создания в порядке возрастания).
 @return ответ на запрос в виде Foundation объекта
 */
- (id)withIDs:(NSArray *)notesIDs count:(NSUInteger)count offset:(NSUInteger)offset sort:(NSUInteger)sort;

/**
 @name notes.getByID
 */
/** Возвращает заметку по её id, владельцем является текущий пользователь
 
 @param noteID идентификатор заметки
 @return ответ на запрос в виде Foundation объекта
 */
- (id)noteWithID:(NSUInteger)noteID;

/** Возвращает заметку по её id, владельцем является текущий пользователь
 
 @param noteID идентификатор заметки
 @param wiki определяет, требуется ли в ответе wiki-представление заметки (работает, только если запрашиваются заметки текущего пользователя)
 @return ответ на запрос в виде Foundation объекта
 */
- (id)noteWithID:(NSUInteger)noteID wiki:(NSUInteger)wiki;

/** Возвращает заметку по её id
 
 @param noteID идентификатор заметки
 @param wiki определяет, требуется ли в ответе wiki-представление заметки (работает, только если запрашиваются заметки текущего пользователя)
 @param ownerID идентификатор владельца заметки
 @return ответ на запрос в виде Foundation объекта
 */
- (id)noteWithID:(NSUInteger)noteID wiki:(NSUInteger)wiki ownerID:(NSUInteger)ownerID;

/**
 @name notes.getFriendsNotes
 */
/** Возвращает список заметок друзей пользователя
 
 @param count количество заметок, информацию о которых необходимо получить.
 @param offset смещение, необходимое для выборки определенного подмножества заметок
 @return ответ на запрос в виде Foundation объекта
 */
- (id)friendsNotesCount:(NSUInteger)count offset:(NSUInteger)offset;

/**
 @name notes.add
 */
/** Создает новую заметку у текущего пользователя
 
 @param title заголовок заметки
 @param text текст заметки
 @param privacy уровень доступа к заметке. Возможные значения:
 0 — все пользователи, 1 — только друзья, 2 — друзья и друзья друзей, 3 — только пользователь.
 @param commentPrivacy уровень доступа к комментированию заметки. Возможные значения:
 0 — все пользователи, 1 — только друзья, 2 — друзья и друзья друзей, 3 — только пользователь.
 @return ответ на запрос в виде Foundation объекта
 */
- (id)addTitle:(NSString *)title text:(NSString *)text privacy:(NSUInteger)privacy commentPrivacy:(NSUInteger)commentPrivacy;

/**
 @name notes.edit
 */
/** Редактирует заметку текущего пользователя
 
 @param noteID идентификатор редактируемой заметки.
 @param title заголовок заметки
 @param text текст заметки
 @param privacy уровень доступа к заметке. Возможные значения:
 0 — все пользователи, 1 — только друзья, 2 — друзья и друзья друзей, 3 — только пользователь
 @param commentPrivacy уровень доступа к комментированию заметки. Возможные значения:
 0 — все пользователи, 1 — только друзья, 2 — друзья и друзья друзей, 3 — только пользователь
 @return ответ на запрос в виде Foundation объекта
 */
- (id)editWithID:(NSUInteger)noteID title:(NSString *)title text:(NSString *)text privacy:(NSUInteger)privacy commentPrivacy:(NSUInteger)commentPrivacy;

/**
 @name notes.delete
 */
/** Удаляет заметку текущего пользователя
 
 @param noteID идентификатор заметки
 @return ответ на запрос в виде Foundation объекта
 */
- (id)deleteWithID:(NSUInteger)noteID;

/**
 @name notes.getComments
 */
/** Возвращает список комментариев к заметке
 
 @param noteID идентификатор заметки, информацию о комментариях к которой нужно вернуть
 @param count количество комментариев, которое необходимо получить
 @param offset смещение, необходимое для выборки определенного подмножества комментариев
 @param sort сортировка результатов (0 — по дате добавления в порядке возрастания, 1 — по дате добавления в порядке убывания)
 @return ответ на запрос в виде Foundation объекта
 */
- (id)commentsWithID:(NSUInteger)noteID count:(NSUInteger)count offset:(NSUInteger)offset sort:(NSUInteger)sort;

/**
 @name notes.createComment
 */
/** Добавляет новый комментарий к заметке
 
 @param comment текст комментария
 @param noteID идентификатор заметки
 @param ownerID идентификатор владельца заметки
 @return ответ на запрос в виде Foundation объекта
 */
- (id)addComment:(NSString *)comment noteID:(NSUInteger)noteID ownerID:(NSUInteger)ownerID;

/** Добавляет новый комментарий к заметке
 
 @param comment текст комментария
 @param noteID идентификатор заметки
 @param ownerID идентификатор владельца заметки
 @param userID идентификатор пользователя, ответом на комментарий которого является добавляемый комментарий (не передаётся, если комментарий не является ответом)
 @return ответ на запрос в виде Foundation объекта
 */
- (id)addComment:(NSString *)comment noteID:(NSUInteger)noteID ownerID:(NSUInteger)ownerID replyToUserID:(NSUInteger)userID;

/**
 @name notes.editComment
 */
/** Редактирует указанный комментарий у заметки
 
 @param commentID идентификатор комментария
 @param comment новый текст комментария
 @return ответ на запрос в виде Foundation объекта
 */
- (id)editCommentWithID:(NSUInteger)commentID comment:(NSString *)comment;

/**
 @name notes.deleteComment
 */
/** Удаляет комментарий к заметке
 
 @param commentID идентификатор комментария
 @param ownerID идентификатор владельца заметки
 @return ответ на запрос в виде Foundation объекта
 */
- (id)deleteCommentWithID:(NSUInteger)commentID ownerID:(NSUInteger)ownerID;

/**
 @name notes.restoreComment
 */
/** Восстанавливает удалённый комментарий
 
 @param commentID идентификатор удаленного комментария
 @param ownerID идентификатор владельца заметки
 @return ответ на запрос в виде Foundation объекта
 */
- (id)restoreCommentWithID:(NSUInteger)commentID ownerID:(NSUInteger)ownerID;

@end