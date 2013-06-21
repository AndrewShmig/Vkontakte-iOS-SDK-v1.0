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
* Класс позволяет работать с фотографиями и альбомами пользователя.
*/
@interface VKPhotoAlbums : NSObject

/**
 @name photos.createAlbum
*/
/** Создает пустой альбом для фотографий
@param title название альбома
@param description текст описания альбома
@return ответ на запрос в виде Foundation объекта
*/
- (id)createTitle:(NSString *)title
      description:(NSString *)description;

/** Создает пустой альбом для фотографий
@param title название альбома
@param description текст описания альбома
@param commentPrivacy уровень доступа к комментированию альбома
@param privacy уровень доступа к альбому
@return ответ на запрос в виде Foundation объекта
*/
- (id)createTitle:(NSString *)title
      description:(NSString *)description
   commentPrivacy:(NSUInteger)commentPrivacy
          privacy:(NSUInteger)privacy;

/**
@param options ключи-значения, с детельным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.createAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)createCustomOptions:(NSDictionary *)options;

/**
  @name photos.editAlbum
*/
/** Редактирует данные альбома для фотографий пользователя
@param albumID идентификатор редактируемого альбома
@param title новое название альбома
@param description новый текст описания альбома
@return ответ на запрос в виде Foundation объекта
*/
- (id)editAlbumID:(NSUInteger)albumID
            title:(NSString *)title
      description:(NSString *)description;

/** Редактирует данные альбома для фотографий пользователя
@param albumID идентификатор редактируемого альбома
@param title новое название альбома
@param description новый текст описания альбома
@param commentPrivacy новый уровень доступа к комментированию альбома
@param privacy новый уровень доступа к альбому
@return ответ на запрос в виде Foundation объекта
*/
- (id)editAlbumID:(NSUInteger)albumID
            title:(NSString *)title
      description:(NSString *)description
   commentPrivacy:(NSUInteger)commentPrivacy
          privacy:(NSUInteger)privacy;

/** Редактирует данные альбома для фотографий пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.editAlbum
@return ответ на запрос в виде Foundation объекта
*/
- (id)editCustomOptions:(NSDictionary *)options;

/**
  @name photos.getAlbums
*/
/** Возвращает список альбомов пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.getAlbums
@return ответ на запрос в виде Foundation объекта
*/
- (id)listCustomOptions:(NSDictionary *)options;

/**
  @name photos.get
*/
/** Возвращает список фотографий в альбоме
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.get
@return ответ на запрос в виде Foundation объекта
*/
- (id)listPhotosCustomOptions:(NSDictionary *)options;

/**
  @name photos.getAlbumsCount
*/
/** Возвращает количество доступных альбомов пользователя
@return ответ на запрос в виде Foundation объекта
*/
- (id)count;

/**
  @name photos.getProfile
*/
/** Возвращает список фотографий со страницы пользователя или сообщества
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.getProfile
@return ответ на запрос в виде Foundation объекта
*/
- (id)profileCustomOptions:(NSDictionary *)options;

/**
  @name photos.getById
*/
/** Возвращает информацию о фотографиях по их идентификаторам
@param photosIDs идентификаторы фотографий, информацию о которых необходимо вернуть
@return ответ на запрос в виде Foundation объекта
*/
- (id)photosByIDs:(NSArray *)photosIDs;

/** Возвращает информацию о фотографиях по их идентификаторам
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.getById
@return ответ на запрос в виде Foundation объекта
*/
- (id)photosByIDsCustomOptions:(NSDictionary *)options;

/**
  @name photos.getUploadServer
*/
/** Возвращает адрес сервера для загрузки фотографий
@return ответ на запрос в виде Foundation объекта
*/
- (id)uploadServer;

/** Возвращает адрес сервера для загрузки фотографий
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.getUploadServer
@return ответ на запрос в виде Foundation объекта
*/
- (id)uploadServerCustomOptions:(NSDictionary *)options;

/**
  @name photos.getProfileUploadServer
*/
/** Возвращает адрес сервера для загрузки фотографии на страницу пользователя
@return ответ на запрос в виде Foundation объекта
*/
- (id)profileUploadServer;

/**
  @name photos.saveProfilePhoto
*/
/** Сохраняет фотографию пользователя после успешной загрузки
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.saveProfilePhoto
@return ответ на запрос в виде Foundation объекта
*/
- (id)saveProfilePhotoCustomOptions:(NSDictionary *)options;

/** Сохраняет фотографию пользователя после успешной загрузки
@param photo параметр, возвращаемый в результате загрузки фотографии на сервер
@param server параметр, возвращаемый в результате загрузки фотографии на сервер
@param hash параметр, возвращаемый в результате загрузки фотографии на сервер
@return ответ на запрос в виде Foundation объекта
*/
- (id)saveProfilePhoto:(NSString *)photo
                server:(NSString *)server
                  hash:(NSString *)hash;

/**
  @name photos.saveWallPhoto
*/
/** Сохраняет фотографии после успешной загрузки на URI, полученный методом photos.getWallUploadServer
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.saveWallPhoto
@return ответ на запрос в виде Foundation объекта
*/
- (id)saveWallPhotoCustomOptions:(NSDictionary *)options;

/**
  @name photos.getWallUploadServer
*/
/** Возвращает адрес сервера для загрузки фотографии на стену пользователя
@return ответ на запрос в виде Foundation объекта
*/
- (id)wallUploadServer;

/** Возвращает адрес сервера для загрузки фотографии на стену пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.getWallUploadServer
@return ответ на запрос в виде Foundation объекта
*/
- (id)wallUploadServerCustomOptions:(NSDictionary *)options;

/**
  @name photos.getMessagesUploadServer
*/
/** Возвращает адрес сервера для загрузки фотографии в личное сообщение пользователю
@return ответ на запрос в виде Foundation объекта
*/
- (id)messagesUploadServer;

/**
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.getMessagesUploadServer
@return ответ на запрос в виде Foundation объекта
*/
- (id)messagesUploadServerCustomOptions:(NSDictionary *)options;

/**
  @name photos.saveMessagesPhoto
*/
/** Сохраняет фотографию после успешной загрузки на URI, полученный методом photos.getMessagesUploadServer
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.saveMessagesPhoto
@return ответ на запрос в виде Foundation объекта
*/
- (id)saveMessagesPhotoCustomOptions:(NSDictionary *)options;

/**
  @name photos.search
*/
/** Осуществляет поиск изображений по местоположению или описанию
@param searchQuery строка поискового запроса, например, "Nature"
@param latitude географическая широта отметки, заданная в градусах (от -90 до 90)
@param longitude географическая долгота отметки, заданная в градусах (от -180 до 180)
@return ответ на запрос в виде Foundation объекта
*/
- (id)searchQuery:(NSString *)searchQuery
         latitude:(CGFloat)latitude
        longitude:(CGFloat)longitude;

/** Осуществляет поиск изображений по местоположению или описанию
@param searchQuery строка поискового запроса, например, "Nature"
@return ответ на запрос в виде Foundation объекта
*/
- (id)searchQuery:(NSString *)searchQuery;

/**
  @name photos.save
*/
/** Сохраняет фотографии после успешной загрузки
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.save
@return ответ на запрос в виде Foundation объекта
*/
- (id)savePhotoCustomOptions:(NSDictionary *)options;

/**
  @name photos.edit
*/
/** Изменяет описание у выбранной фотографии
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.edit
@return ответ на запрос в виде Foundation объекта
*/
- (id)editPhotoCustomOptions:(NSDictionary *)options;

/** Изменяет описание у выбранной фотографии
@param photoID идентификатор фотографии
@param ownerID идентификатор пользователя или сообщества, которому принадлежит фотография
@param caption новый текст описания к фотографии
@return ответ на запрос в виде Foundation объекта
*/
- (id)editPhotoID:(NSUInteger)photoID
          ownerID:(NSUInteger)ownerID
          caption:(NSString *)caption;

/**
  @name photos.move
*/
/** Переносит фотографию из одного альбома в другой
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.move
@return ответ на запрос в виде Foundation объекта
*/
- (id)movePhotoCustomOptions:(NSDictionary *)options;

/** Переносит фотографию из одного альбома в другой
@param photoID идентификатор фотографии, которую нужно перенести
@param albumID идентификатор альбома, в который нужно перенести фотографию
@return ответ на запрос в виде Foundation объекта
*/
- (id)movePhotoID:(NSUInteger)photoID
        toAlbumID:(NSUInteger)albumID;

/**
  @name photos.makeCover
*/
/** Делает фотографию обложкой альбома
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.makeCover
@return ответ на запрос в виде Foundation объекта
*/
- (id)makeCoverCustomOptions:(NSDictionary *)options;

/** Делает фотографию обложкой альбома
@param photoID идентификатор фотографии
@param albumID идентификатор альбома
@return ответ на запрос в виде Foundation объекта
*/
- (id)makeCoverPhotoID:(NSUInteger)photoID
               albumID:(NSUInteger)albumID;

/**
  @name photos.reorderAlbums
*/
/** Меняет порядок альбома в списке альбомов пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.reorderAlbums
@return ответ на вопрос в виде Foundation объекта
*/
- (id)reorderCustomOptions:(NSDictionary *)options;

/**
  @name photos.reorderPhotos
*/
/** Меняет порядок фотографии в списке фотографий альбома пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.reorderPhotos
@return ответ на запрос в виде Foundation объекта
*/
- (id)reorderPhotosCustomOptions:(NSDictionary *)options;

/**
  @name photos.getAll
*/
/** Возвращает все фотографии пользователя или сообщества в антихронологическом порядке
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.getAll
@return ответ на запрос в виде Foundation объекта
*/
- (id)allPhotosCustomOptions:(NSDictionary *)options;

/**
  @name photos.getUserPhotos
*/
/** Возвращает список фотографий, на которых отмечен пользователь
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.getUserPhotos
@return ответ на запрос в виде Foundation объекта
*/
- (id)taggedPhotosCustomOptions:(NSDictionary *)options;

/**
  @name photos.deleteAlbum
*/
/** Удаляет указанный альбом для фотографий у текущего пользователя
@param albumID идентификатор альбома
@return ответ на запрос в виде Foundation объекта
*/
- (id)removeAlbumID:(NSUInteger)albumID;

/**
  @name photos.delete
*/
/** Удаление фотографии на сайте
@param photoID идентификатор фотографии
@return ответ на запрос в виде Foundation объекта
*/
- (id)removePhotoID:(NSUInteger)photoID;

/**
  @name photos.confirmTag
*/
/** Подтверждает отметку на фотографии
@param tagID идентификатор отметки на фотографии
@param ownerID идентификатор пользователя или сообщества, которому принадлежит фотография
@param photoID идентификатор фотографии
@return ответ на запрос в виде Foundation объекта
*/
- (id)confirmTagID:(NSUInteger)tagID
           ownerID:(NSUInteger)ownerID
           photoID:(NSUInteger)photoID;

/**
  @name photos.getComments
*/
/** Возвращает список комментариев к фотографии
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.getComments
@return ответ на запрос в виде Foundation объекта
*/
- (id)photoCommentsCustomOptions:(NSDictionary *)options;

/**
  @name photos.getAllComments
*/
/** Возвращает отсортированный в антихронологическом порядке список всех комментариев к конкретному альбому или ко всем альбомам пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.getAllComments
@return ответ на запрос в виде Foundation объекта
*/
- (id)allCommentsCustomOptions:(NSDictionary *)options;

/**
  @name photos.createComment
*/
/** Создает новый комментарий к фотографии
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.createComment
@return ответ на запрос в виде Foundation объекта
*/
- (id)addCommentCustomOptions:(NSDictionary *)options;

/**
  @name photos.deleteComment
*/
/** Удаляет комментарий к фотографии
@param commentID идентификатор комментария
@return ответ на запрос в виде Foundation объекта
*/
- (id)removeCommentID:(NSUInteger)commentID;

/**
  @name photos.restoreComment
*/
/** Восстанавливает удаленный комментарий к фотографии
@param commentID идентификатор комментария
@return ответ на запрос в виде Foundation объекта
*/
- (id)restoreCommentID:(NSUInteger)commentID;

/**
  @name photos.editComment
*/
/** Изменяет текст комментария к фотографии
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/photos.editComment
@return ответ на запрос в виде Foundation объекта
*/
- (id)editCommentCustomOptions:(NSDictionary *)options;

/**
  @name photos.getTags
*/
/** Возвращает список отметок на фотографии
@param photoID идентификатор фотографии
@return ответ на запрос в виде Foundation объекта
*/
- (id)tagsPhotoID:(NSUInteger)photoID;

/**
  @name photos.putTag
*/
/** Добавляет отметку на фотографию
@param photoID идентификатор фотографии
@param userID идентификатор пользователя, которого нужно отметить на фотографии
@return ответ на запрос в виде Foundation объекта
*/
- (id)addTagPhotoID:(NSUInteger)photoID
             userID:(NSUInteger)userID;

/**
  @name photos.removeTag
*/
/** Удаляет отметку с фотографии
@param tagID идентификатор отметки
@param photoID идентификатор фотографии
@return ответ на запрос в виде Foundation объекта
*/
- (id)removeTagID:(NSUInteger)tagID
          photoID:(NSUInteger)photoID;

/**
  @name photos.getNewTags
*/
/** Возвращает список фотографий, на которых есть непросмотренные отметки
@return ответ на запрос в виде Foundation объекта
*/
- (id)unseenPhotoTags;

/** Возвращает список фотографий, на которых есть непросмотренные отметки
@param count количество фотографий, которые необходимо вернуть
@param offset смещение необходимой для получения определённого подмножества фотографий
@return ответ на запрос в виде Foundation объекта
*/
- (id)unseenPhotoTagsCount:(NSUInteger)count
                    offset:(NSUInteger)offset;

@end