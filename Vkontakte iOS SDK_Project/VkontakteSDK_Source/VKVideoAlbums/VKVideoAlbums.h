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

#import <Foundation/Foundation.h>

/**
Класс предназначен для работы с пользовательскими видео альбомами.
*/
@interface VKVideoAlbums : NSObject

/**
@name video.get
*/
/** Возвращает информацию о видеозаписях
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.get
@return ответ на запрос в виде Foundation объекта
*/
- (id)getCustomOptions:(NSDictionary *)options;

/**
@name video.edit
*/
/** Редактирует данные видеозаписи на странице пользователя
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.edit
@return ответ на запрос в виде Foundation объекта
*/
- (id)editCustomOptions:(NSDictionary *)options;

/** Редактирует данные видеозаписи на странице пользователя
@param videoID идентификатор видеозаписи
@param newName новое название для видеозаписи
@param newDescription новое описание для видеозаписи
@return ответ на запрос в виде Foundation объекта
*/
- (id)editVideoID:(NSUInteger)videoID
          newName:(NSString *)newName
   newDescription:(NSString *)newDescription;

/**
@name video.add
*/
/** Добавляет видеозапись в список пользователя
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.add
@return ответ на запрос в виде Foundation объекта
*/
- (id)addCustomOptions:(NSDictionary *)options;

/**
@name video.save
*/
/** Возвращает адрес сервера (необходимый для загрузки) и данные видеозаписи
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.save
@return ответ на запрос в виде Foundation объекта
*/
- (id)saveCustomOptions:(NSDictionary *)options;

/**
@name video.delete
*/
/** Удаляет видеозапись со страницы пользователя
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.delete
@return ответ на запрос в виде Foundation объекта
*/
- (id)deleteCustomOptions:(NSDictionary *)options;

/**
@name video.restore
*/
/** Восстанавливает удаленную видеозапись
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.restore
@return ответ на запрос в виде Foundation объекта
*/
- (id)restoreCustomOptions:(NSDictionary *)options;

/**
@name video.search
*/
/** Возвращает список видеозаписей в соответствии с заданным критерием поиска
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.search
@return ответ на запрос в виде Foundation объекта
*/
- (id)searchCustomOptions:(NSDictionary *)options;

/** Возвращает список видеозаписей в соответствии с заданным критерием поиска
@param query строка поискового запроса. Например, The Beatles
@return ответ на запрос в виде Foundation объекта
*/
- (id)searchQuery:(NSString *)query;

/** Возвращает список видеозаписей в соответствии с заданным критерием поиска
@param query строка поискового запроса. Например, The Beatles
@param sort вид сортировки. 0 — по дате добавления видеозаписи, 1 — по длительности, 2 — по релевантности.
@param count количество возвращаемых видеозаписей (максимум 200)
@param offset смещение относительно первой найденной видеозаписи для выборки определенного подмножества.
@return ответ на запрос в виде Foundation объекта
*/
- (id)searchQuery:(NSString *)query
             sort:(NSUInteger)sort
            count:(NSUInteger)count
           offset:(NSUInteger)offset;

/**
@name video.getUserVideos
*/
/** Возвращает список видеозаписей, на которых отмечен пользователь
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.getUserVideos
@return ответ на запрос в виде Foundation объекта
*/
- (id)getUserVideosCustomOptions:(NSDictionary *)options;

/** Возвращает список видеозаписей, на которых отмечен пользователь
@param count количество возвращаемых видеозаписей
@param offset смещение относительно первой найденной видеозаписи для выборки определенного подмножества
@return ответ на запрос в виде Foundation объекта
*/
- (id)getUserVideosCount:(NSUInteger)count offset:(NSUInteger)offset;

/**
@name video.getAlbums
*/
/** Возвращает список альбомов видеозаписей пользователя или сообщества
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.getAlbums
@return ответ на запрос в виде Foundation объекта
*/
- (id)getAlbumsCustomtOptions:(NSDictionary *)options;

/** Возвращает список альбомов видеозаписей пользователя или сообщества
@param count количество альбомов, информацию о которых нужно вернуть. По умолчанию — не больше 50, максимум — 100)
@param offset смещение, необходимое для выборки определенного подмножества альбомов.
@return ответ на запрос в виде Foundation объекта
*/
- (id)getAlbumsCount:(NSUInteger)count offset:(NSUInteger)offset;

/**
@name video.addAlbum
*/
/** Создает пустой альбом видеозаписей
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.addAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)addAlbumCustomOptions:(NSDictionary *)options;

/** Создает пустой альбом видеозаписей
@param albumName название альбома
@return ответ на запрос в виде Foundation объекта
*/
- (id)addAlbum:(NSString *)albumName;

/**
@name video.editAlbum
*/
/** Редактирует название альбома видеозаписей
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.editAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)editAlbumCustomOptions:(NSDictionary *)options;

/** Редактирует название альбома видеозаписей
@param albumID идентификатор альбома
@param newTitle новое название для альбома
@return ответ на запрос в виде Foundation объекта
*/
- (id)editAlbumID:(NSUInteger)albumID newTitle:(NSString *)newTitle;

/**
@name video.deleteAlbum
*/
/** Удаляет альбом видеозаписей
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.deleteAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)deleteAlbumCustomOptions:(NSDictionary *)options;

/** Удаляет альбом видеозаписей
@param albumID идентификатор альбома
@return ответ на запрос в виде Foundation объекта
*/
- (id)deleteAlbumID:(NSUInteger)albumID;

/**
@name video.moveToAlbum
*/
/** Перемещает видеозаписи в альбом
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.moveToAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)moveToAlbumCustomOptions:(NSDictionary *)options;

/**
@name video.getComments
*/
/** Возвращает список комментариев к видеозаписи
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.getComments
@return ответ на запрос в виде Foundation объекта
*/
- (id)getCommentsCustomOptions:(NSDictionary *)options;

/**
@name video.createComment
*/
/** Cоздает новый комментарий к видеозаписи
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.createComment
@return ответ на запрос в виде Foundation объекта
*/
- (id)createCommentCustomOptions:(NSDictionary *)options;

/**
@name video.deleteComment
*/
/** Удаляет комментарий к видеозаписи
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.deleteComment
@return ответ на запрос в виде Foundation объекта
*/
- (id)deleteCommentCustomOptions:(NSDictionary *)options;

/** Удаляет комментарий к видеозаписи
@param commentID идентификатор комментария
@return ответ на запрос в виде Foundation объекта
*/
- (id)deleteCommentID:(NSUInteger)commentID;

/**
@name video.restoreComment
*/
/** Восстанавливает удаленный комментарий к видеозаписи
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.restoreComment
@return ответ на запрос в виде Foundation объекта
*/
- (id)restoreCommentCustomOptions:(NSDictionary *)options;

/** Восстанавливает удаленный комментарий к видеозаписи
@param commentID идентификатор удаленного комментария
@return ответ на запрос в виде Foundation объекта
*/
- (id)restoreCommentID:(NSUInteger)commentID;

/**
@name video.editComment
*/
/** Изменяет текст комментария к видеозаписи
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.editComment
@return ответ на запрос в виде Foundation объекта
*/
- (id)editCommentCustomOptions:(NSDictionary *)options;

/**
@name video.getTags
*/
/** Возвращает список отметок на видеозаписи
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.getTags
@return ответ на запрос в виде Foundation объекта
*/
- (id)getTagsCustomOptions:(NSDictionary *)options;

/** Возвращает список отметок на видеозаписи
@param videoID идентификатор видеозаписи
@param ownerID идентификатор владельца видеозаписи (пользователь или сообщество). По умолчанию — идентификатор текущего пользователя
@return ответ на запрос в виде Foundation объекта
*/
- (id)getTagsVideoID:(NSUInteger)videoID ownerID:(NSUInteger)ownerID;

/**
@name video.putTag
*/
/** Добавляет отметку на видеозапись
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.putTag
@return ответ на запрос в виде Foundation объекта
*/
- (id)putTagCustomOptions:(NSDictionary *)options;

/** Добавляет отметку на видеозапись
@param tagName текст отметки
@param videoID идентификатор видеозаписи
@param userID идентификатор пользователя, которого нужно отметить
@param ownerID идентификатор владельца видеозаписи (пользователь или сообщество
@return ответ на запрос в виде Foundation объекта
*/
- (id)putTagName:(NSString *)tagName
         videoID:(NSUInteger)videoID
          userID:(NSUInteger)userID
         ownerID:(NSUInteger)ownerID;

/**
@name video.removeTag
*/
/** Удаляет отметку с видеозаписи
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.removeTag
@return ответ на запрос в виде Foundation объекта
*/
- (id)removeTagCustomOptions:(NSDictionary *)options;

/** Удаляет отметку с видеозаписи
@param tagID идентификатор отметки
@param videoID идентификатор видеозаписи
@return ответ на запрос в виде Foundation объекта
*/
- (id)removeTagID:(NSUInteger)tagID videoID:(NSUInteger)videoID;

/**
@name video.getNewTags
*/
/** Возвращает список видеозаписей, на которых есть непросмотренные отметки
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.getNewTags
@return ответ на запрос в виде Foundation объекта
*/
- (id)getNewTagsCustomOptions:(NSDictionary *)options;

/** Возвращает список видеозаписей, на которых есть непросмотренные отметки
@param count количество видеозаписей, которые необходимо вернуть
@param offset смещение, необходимое для получения определённого подмножества видеозаписей
@return ответ на запрос в виде Foundation объекта
*/
- (id)getNewTagsCount:(NSUInteger)count offset:(NSUInteger)offset;

/**
@name Загрузка видео
*/
/** Загрузка видео на сервер ВК
@param videoData байтовое представление видео
@param videoFileName наименование файла видео

@return ответ на запрос в виде Foundation объекта
*/
- (id)uploadVideo:(NSData *)videoData name:(NSString *)videoFileName;

@end