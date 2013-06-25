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


/**
Класс предназначен для работы с пользовательскими аудио файлами и аудио альбомами.
*/
@interface VKAudioAlbums : NSObject

/**
@name audio.get
*/
/** Возвращает список аудиозаписей пользователя или сообщества
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.get
@return ответ на запрос в виде Foundation объекта
*/
- (id)getCustomOptions:(NSDictionary *)options;

/**
@name audio.getById
*/
/** Возвращает информацию об аудиозаписях
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.getById
@return ответ на запрос в виде Foundation объекта
*/
- (id)getByIDCustomOptions:(NSDictionary *)options;

/**
@name audio.getLyrics
*/
/** Возвращает текст аудиозаписи
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.getLyrics
@return ответ на запрос в виде Foundation объекта
*/
- (id)getLyricsCustomOptions:(NSDictionary *)options;

/** Возвращает текст аудиозаписи
@param lyricsID идентификатор текста аудиозаписи, информацию о котором необходимо вернуть
@return ответ на запрос в виде Foundation объекта
*/
- (id)getLyricsID:(NSUInteger)lyricsID;

/**
@name audio.search
*/
/** Возвращает список аудиозаписей в соответствии с заданным критерием поиска
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.search
@return ответ на запрос в виде Foundation объекта
*/
- (id)searchCustomOptions:(NSDictionary *)options;

/** Возвращает список аудиозаписей в соответствии с заданным критерием поиска
@param query текст поискового запроса, например, The Beatles
@return ответ на запрос в виде Foundation объекта
*/
- (id)searchQuery:(NSString *)query;

/** Возвращает список аудиозаписей в соответствии с заданным критерием поиска
@param query текст поискового запроса, например, The Beatles
@param sort Вид сортировки. 2 — по популярности, 1 — по длительности аудиозаписи, 0 — по дате добавления.
@param count количество аудиозаписей, информацию о которых необходимо вернуть
@param offset смещение, необходимое для выборки определенного подмножетсва аудиозаписей
@return ответ на запрос в виде Foundation объекта
*/
- (id)searchQuery:(NSString *)query
             sort:(NSUInteger)sort
            count:(NSUInteger)count
           offset:(NSUInteger)offset;

/**
@name audio.getUploadServer
*/
/** Возвращает адрес сервера для загрузки аудиозаписей
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.getUploadServer
@return ответ на запрос в виде Foundation объекта
*/
- (id)getUploadServerCustomOptions:(NSDictionary *)options;

/**
@name audio.save
*/
/** Сохраняет аудиозаписи после успешной загрузки
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.save
@return ответ на запрос в виде Foundation объекта
*/
- (id)saveCustomOptions:(NSDictionary *)options;

/**
@name audio.add
*/
/** Копирует аудиозапись на страницу пользователя или группы
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.add
@return ответ на запрос в виде Foundation объекта
*/
- (id)addCustomOptions:(NSDictionary *)options;

/** Копирует аудиозапись на страницу пользователя или группы
@param audioID идентификатор аудиозаписи
@param ownerID идентификатор владельца аудиозаписи (пользователь или сообщество)
@return ответ на запрос в виде Foundation объекта
*/
- (id)addAudioID:(NSUInteger)audioID ownerID:(NSUInteger)ownerID;

/**
@name audio.delete
*/
/** Удаляет аудиозапись со страницы пользователя или сообщества
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.delete
@return ответ на запрос в виде Foundation объекта
*/
- (id)deleteCustomOptions:(NSDictionary *)options;

/**
@name audio.edit
*/
/** Редактирует данные аудиозаписи на странице пользователя или сообщества
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.edit
@return ответ на запрос в виде Foundation объекта
*/
- (id)editCustomOptions:(NSDictionary *)options;

/** Редактирует данные аудиозаписи на странице пользователя или сообщества
@param audioID идентификатор аудиозаписи
@param ownerID идентификатор владельца аудиозаписи (пользователь или сообщество)
@param newArtist новое название исполнителя
@param newTitle новое название композиции
@param newText новый текст аудиозаписи
@return ответ на запрос в виде Foundation объекта
*/
- (id)editAudioID:(NSUInteger)audioID
          ownerID:(NSUInteger)ownerID
        newArtist:(NSString *)newArtist
         newTitle:(NSString *)newTitle
          newText:(NSString *)newText;

/**
@name audio.reorder
*/
/** Изменяет порядок аудиозаписи, перенося ее между аудиозаписями, идентификаторы которых переданы параметрами after и before
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.reorder
@return ответ на запрос в виде Foundation объекта
*/
- (id)reorderCustomOptions:(NSDictionary *)options;

/**
@name audio.restore
*/
/** Восстанавливает аудиозапись после удаления
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.restore
@return ответ на запрос в виде Foundation объекта
*/
- (id)restoreCustomOptions:(NSDictionary *)options;

/** Восстанавливает аудиозапись после удаления
@param audioID идентификатор аудиозаписи
@return ответ на запрос в виде Foundation объекта
*/
- (id)restoreAudioID:(NSUInteger)audioID;

/**
@name audio.getAlbums
*/
/** Возвращает список альбомов аудиозаписей пользователя или группы
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.getAlbums
@return ответ на запрос в виде Foundation объекта
*/
- (id)getAlbumsCustomOptions:(NSDictionary *)options;

/** Возвращает список альбомов аудиозаписей пользователя или группы
@param count количество альбомов, которое необходимо вернуть
@param offset смещение, необходимое для выборки определенного подмножества альбомов
@return ответ на запрос в виде Foundation объекта
*/
- (id)getAlbumsCount:(NSUInteger)count offset:(NSUInteger)offset;

/**
@name audio.addAlbum
*/
/** Создает пустой альбом аудиозаписей
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.addAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)addAlbumCustomOptions:(NSDictionary *)options;

/** смещение, необходимое для выборки определенного подмножества альбомов
@param albumTitle название альбома
@return ответ на запрос в виде Foundation объекта
*/
- (id)addAlbumTitle:(NSString *)albumTitle;

/**
@name audio.editAlbum
*/
/** Редактирует название альбома аудиозаписей
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.editAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)editAlbumCustomOptions:(NSDictionary *)options;

/** Редактирует название альбома аудиозаписей
@param albumID идентификатор альбома
@param newTitle новое название для альбома
@return ответ на запрос в виде Foundation объекта
*/
- (id)editAlbumID:(NSUInteger)albumID newTitle:(NSString *)newTitle;

/**
@name audio.deleteAlbum
*/
/** Удаляет альбом аудиозаписей
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.deleteAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)deleteAlbumCustomOptions:(NSDictionary *)options;

/** Удаляет альбом аудиозаписей
@param albumID идентификатор альбома
@return ответ на запрос в виде Foundation объекта
*/
- (id)deleteAlbumID:(NSUInteger)albumID;

/**
@name audio.moveToAlbum
*/
/** Перемещает аудиозаписи в альбом
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.moveToAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)moveToAlbumCustomOptions:(NSDictionary *)options;

/**
@name audio.setBroadcast
*/
/** Транслирует аудиозапись в статус пользователю или сообществу
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.setBroadcast
@return ответ на запрос в виде Foundation объекта
*/
- (id)setBroadcastCustomOptions:(NSDictionary *)options;

/**
@name audio.getBroadcastList
*/
/** Возвращает список друзей и сообществ пользователя, которые транслируют музыку в статус
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.getBroadcastList
@return ответ на запрос в виде Foundation объекта
*/
- (id)getBroadcastListCustomOptions:(NSDictionary *)options;

/**
@name audio.getRecommendations
*/
/** Возвращает список рекомендуемых аудиозаписей на основе списка воспроизведения заданного пользователя или на основе одной выбранной аудиозаписи
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.getRecommendations
@return ответ на запрос в виде Foundation объекта
*/
- (id)getRecommendationsCustomOptions:(NSDictionary *)options;

/** Возвращает список рекомендуемых аудиозаписей на основе списка воспроизведения заданного пользователя или на основе одной выбранной аудиозаписи
@param count количество возвращаемых аудиозаписей
@param offset смещение относительно первой найденной аудиозаписи для выборки определенного подмножества
@return ответ на запрос в виде Foundation объекта
*/
- (id)getRecommendationsCount:(NSUInteger)count offset:(NSUInteger)offset;

/**
@name audio.getPopular
*/
/** Возвращает список аудиозаписей из раздела "Популярное"
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.getPopular
@return ответ на запрос в виде Foundation объекта
*/
- (id)getPopularCustomOptions:(NSDictionary *)options;

/** Возвращает список аудиозаписей из раздела "Популярное"
@param count количество возвращаемых аудиозаписей
@param offset смещение, необходимое для выборки определенного подмножества аудиозаписей
@return ответ на запрос в виде Foundation объекта
*/
- (id)getPopularCount:(NSUInteger)count offset:(NSUInteger)offset;

/**
@name audio.getCount
*/
/** Возвращает количество аудиозаписей пользователя или сообщества
@param options  ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/audio.getCount
@return ответ на запрос в виде Foundation объекта
*/
- (id)getCountCustomOptions:(NSDictionary *)options;

/** Возвращает количество аудиозаписей пользователя или сообщества
@return ответ на запрос в виде Foundation объекта
*/
- (id)getCount;

/**
@name Загрузка аудио
*/
/** Загружает аудио на сервер ВК

@param audioData байтовое представление аудио файла
@param audioFileName наименование файла аудио

@return ответ на запрос в виде Foundation объекта
*/
- (id)uploadAudio:(NSData *)audioData name:(NSString *)audioFileName;

@end