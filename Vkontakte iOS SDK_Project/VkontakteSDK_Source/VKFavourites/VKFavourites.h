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


@interface VKFavourites : NSObject

/**
 @name Users
 */
/** Возвращает список пользователей, добавленных текущим пользователем в закладки
 
 @param count количество пользователей, информацию о которых необходимо вернуть
 @return ответ на запрос в виде Foundation объекта
 */
- (id)usersCount:(NSUInteger)count;

/** Возвращает список пользователей, добавленных текущим пользователем в закладки
 
 @param count количество пользователей, информацию о которых необходимо вернуть
 @param offset смещение, необходимое для выборки определенного подмножества пользователей
 @return ответ на запрос в виде Foundation объекта
 */
- (id)usersCount:(NSUInteger)count offset:(NSUInteger)offset;

/**
 @name Photos
 */
/** Возвращает фотографии, на которых текущий пользователь поставил отметку "Мне нравится"
 
 @param count Число фотографий, информацию о которых необходимо вернуть
 @return ответ на запрос в виде Foundation объекта
 */
- (id)photosCount:(NSUInteger)count;

/** Возвращает фотографии, на которых текущий пользователь поставил отметку "Мне нравится"
 
 @param count Число фотографий, информацию о которых необходимо вернуть
 @param offset смещение, необходимое для выборки определенного подмножества фотографий
 @return ответ на запрос в виде Foundation объекта
 */
- (id)photosCount:(NSUInteger)count offset:(NSUInteger)offset;

/**
 @name Posts
 */
/** Возвращает записи, на которых текущий пользователь поставил отметку «Мне нравится»
 
 @param count количество записей, информацию о которых нужно вернуть (но не более 100)
 @return ответ на запрос в виде Foundation объекта
 */
- (id)postsCount:(NSUInteger)count;

/** Возвращает записи, на которых текущий пользователь поставил отметку «Мне нравится»
 
 @param count количество записей, информацию о которых нужно вернуть (но не более 100)
 @param offset смещение, необходимо для выборки определенного подмножества записей
 @return ответ на запрос в виде Foundation объекта
 */
- (id)postsCount:(NSUInteger)count offset:(NSUInteger)offset;

/** Возвращает записи, на которых текущий пользователь поставил отметку «Мне нравится»
 
 @param count количество записей, информацию о которых нужно вернуть (но не более 100)
 @param offset смещение, необходимо для выборки определенного подмножества записей
 @param extended 1 — будут возвращены три массива wall, profiles и groups. 0 - дополнительные поля не будут возвращены.
 @return ответ на запрос в виде Foundation объекта
 */
- (id)postsCount:(NSUInteger)count offset:(NSUInteger)offset extended:(NSUInteger)extended;

/**
 @name Videos
 */
/** Возвращает список видеозаписей, на которых текущий пользователь поставил отметку «Мне нравится»
 
 @param count количество видеозаписей, информацию о которых необходимо вернуть
 @return ответ на запрос в виде Foundation объекта
 */
- (id)videosCount:(NSUInteger)count;

/** Возвращает список видеозаписей, на которых текущий пользователь поставил отметку «Мне нравится»
 
 @param count количество видеозаписей, информацию о которых необходимо вернуть
 @param offset смещение, необходимое для выборки определенного подмножества видеозаписей
 @return ответ на запрос в виде Foundation объекта
 */
- (id)videosCount:(NSUInteger)count offset:(NSUInteger)offset;

/**
 @name Links
 */
/** Возвращает ссылки, добавленные в закладки текущим пользователем
 
 После успешного выполнения возвращает общее количество ссылок и массив объектов link, каждый из которых содержит поля url, title, description и image_src.
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)links;


@end