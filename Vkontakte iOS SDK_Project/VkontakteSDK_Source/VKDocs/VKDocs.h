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

/** Класс предназначен для работы с документами пользователя.
 
 @warning Пока класс не реализует функционал загрузки самих документов на сервер,
 но в скором времени это будет.
 */
@interface VKDocs : NSObject

/**
 @name docs.get
 */
/** Возвращает расширенную информацию о документах пользователя или сообщества
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)list;

/** Возвращает расширенную информацию о документах пользователя или сообщества
 
 @param count количество документов, информацию о которых нужно вернуть
 @param offset смещение, необходимое для выборки определенного подмножества документов
 @return ответ на запрос в виде Foundation объекта
 */
- (id)listCount:(NSUInteger)count offset:(NSUInteger)offset;

/**
 @name docs.getById
 */
/** Возвращает информацию о документах по их идентификаторам
 
 @param docsIDs идентификаторы документов, информацию о которых нужно вернуть ( Пример значения docs: 66748_91488,66748_91455 )
 @return ответ на запрос в виде Foundation объекта
 */
- (id)byIDs:(NSArray *)docsIDs;

/**
 @name docs.getUploadServer
 */
/** Возвращает адрес сервера для загрузки документов
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)uploadServer;

/** Возвращает адрес сервера для загрузки документов
 
 @param groupID идентификатор сообщества (если необходимо загрузить документ в сообщество)
 @return ответ на запрос в виде Foundation объекта
 */
- (id)uploadServerGroupID:(NSUInteger)groupID;

/**
 @name docs.getWallUploadServer
 */
/** Возвращает адрес сервера для загрузки документов в папку Отправленные, для последующей отправки документа на стену или личным сообщением
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)wallUploadServer;

/** Возвращает адрес сервера для загрузки документов в папку Отправленные, для последующей отправки документа на стену или личным сообщением
 
 @param groupID идентификатор сообщества, в которое нужно загрузить документ
 @return ответ на запрос в виде Foundation объекта
 */
- (id)wallUploadServerGroupID:(NSUInteger)groupID;

/**
 @name docs.save
 */
/** Сохраняет документ после его успешной загрузки на сервер
 
 @param file параметр, возвращаемый в результате загрузки файла на сервер
 @return ответ на запрос в виде Foundation объекта
 */
- (id)save:(NSString *)file;

/**
 @name docs.delete
 */
/** Удаляет документ пользователя или группы
 
 @param documentID идентификатор документа
 @return ответ на запрос в виде Foundation объекта
 */
- (id)removeDocumentID:(NSUInteger)documentID;

/**
 @name docs.add
 */
/** Копирует документ в документы текущего пользователя
 
 @param documentID идентификатор документа
 @param ownerID идентификатор пользователя или сообщества, которому принадлежит документ
 @return ответ на запрос в виде Foundation объекта
 */
- (id)addDocumentID:(NSUInteger)documentID ownerID:(NSUInteger)ownerID;

/** Копирует документ в документы текущего пользователя
 
 @param documentID идентификатор документа
 @param ownerID идентификатор пользователя или сообщества, которому принадлежит документ
 @param accessKey ключ доступа документа. Этот параметр следует передать, если вместе с остальными данными о документе было возвращено поле access_key.
 @return ответ на запрос в виде Foundation объекта
 */
- (id)addDocumentID:(NSUInteger)documentID ownerID:(NSUInteger)ownerID accessKey:(NSString *)accessKey;

@end