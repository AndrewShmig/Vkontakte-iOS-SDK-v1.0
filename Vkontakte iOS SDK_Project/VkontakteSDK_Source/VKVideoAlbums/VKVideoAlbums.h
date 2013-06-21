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

/**
@name video.getUserVideos
*/
/** Возвращает список видеозаписей, на которых отмечен пользователь
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.getUserVideos
@return ответ на запрос в виде Foundation объекта
*/
- (id)getUserVideosCustomOptions:(NSDictionary *)options;

/**
@name video.getAlbums
*/
/** Возвращает список альбомов видеозаписей пользователя или сообщества
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.getAlbums
@return ответ на запрос в виде Foundation объекта
*/
- (id)getAlbumsCustomtOptions:(NSDictionary *)options;

/**
@name video.addAlbum
*/
/** Создает пустой альбом видеозаписей
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.addAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)addAlbumCustomOptions:(NSDictionary *)options;

/**
@name video.editAlbum
*/
/** Редактирует название альбома видеозаписей
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.editAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)editAlbumCustomOptions:(NSDictionary *)options;

/**
@name video.deleteAlbum
*/
/** Удаляет альбом видеозаписей
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.deleteAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)deleteAlbumCustomOptions:(NSDictionary *)options;

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

/**
@name video.restoreComment
*/
/** Восстанавливает удаленный комментарий к видеозаписи
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.restoreComment
@return ответ на запрос в виде Foundation объекта
*/
- (id)restoreCommentCustomOptions:(NSDictionary *)options;

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

/**
@name video.putTag
*/
/** Добавляет отметку на видеозапись
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.putTag
@return ответ на запрос в виде Foundation объекта
*/
- (id)putTagCustomOptions:(NSDictionary *)options;

/**
@name video.removeTag
*/
/** Удаляет отметку с видеозаписи
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.removeTag
@return ответ на запрос в виде Foundation объекта
*/
- (id)removeTagCustomOptions:(NSDictionary *)options;

/**
@name video.getNewTags
*/
/** Возвращает список видеозаписей, на которых есть непросмотренные отметки
@param options ключи-значения, со списком можно ознакомиться по этой ссылке: https://vk.com/dev/video.getNewTags
@return ответ на запрос в виде Foundation объекта
*/
- (id)getNewTagsCustomOptions:(NSDictionary *)options;

@end