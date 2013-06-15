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

/** Класс предназначен для работы с пользовательскими местами (добавление нового места,
 осуществления chekinа и тд)
 */
@interface VKPlaces : NSObject

/**
 @name places.add
 */
/** Добавляет новое место в базу географических мест
 
 @param type идентификатор типа нового места, полученный методом types:
 @param title название нового места
 @param latitude географическая широта нового места, заданная в градусах (от -90 до 90)
 @param longitude географическая долгота нового места, заданная в градусах (от -180 до 180)
 @return ответ на запрос в ввиде Foundation объекта
 */
- (id)addType:(NSUInteger)type title:(NSString *)title latitude:(CGFloat)latitude longitude:(CGFloat)longitude;

/** Добавляет новое место в базу географических мест
 
 @param type идентификатор типа нового места, полученный методом types:
 @param title название нового места
 @param latitude географическая широта нового места, заданная в градусах (от -90 до 90)
 @param longitude географическая долгота нового места, заданная в градусах (от -180 до 180)
 @param country идентификатор страны нового места, полученный методом countries:
 @param city идентификатор города нового места, полученный методом citiesCountryID:
 @return ответ на запрос в ввиде Foundation объекта
 */
- (id)addType:(NSUInteger)type title:(NSString *)title latitude:(CGFloat)latitude longitude:(CGFloat)longitude country:(NSUInteger)country city:(NSUInteger)city;

/** Добавляет новое место в базу географических мест
 
 @param type идентификатор типа нового места, полученный методом types:
 @param title название нового места
 @param latitude географическая широта нового места, заданная в градусах (от -90 до 90)
 @param longitude географическая долгота нового места, заданная в градусах (от -180 до 180)
 @param country идентификатор страны нового места, полученный методом countries:
 @param city идентификатор города нового места, полученный методом citiesCountryID:
 @param address строка с адресом нового места (например, Невский просп. 1)
 @return ответ на запрос в ввиде Foundation объекта
 */
- (id)addType:(NSUInteger)type title:(NSString *)title latitude:(CGFloat)latitude longitude:(CGFloat)longitude country:(NSUInteger)country city:(NSUInteger)city address:(NSString *)address;

/**
 @name places.getById
 */
/** Возвращает информацию о местах по их идентификаторам
 
 @param placesIDs идентификаторы мест
 @return ответ на запрос в виде Foundation объекта
 */
- (id)byIDs:(NSArray *)placesIDs;

/**
 @name places.search
 */
/** Возвращает список мест, найденных по заданным условиям поиска
 
 @param options ключи-значение, с полным списком можно ознакомиться по ссылке: https://vk.com/dev/places.search
 @return ответ на запрос в виде Foundation объекта
 */
- (id)searchCustomOptions:(NSDictionary *)options;

/**
 @name places.checkin
 */
/** Отмечает пользователя в указанном месте
 
 @param placeID идентификатор места
 @param text комментарий к отметке длиной до 255 символов (переводы строк не поддерживаются)
 @param latitude географическая широта отметки, заданная в градусах (от -90 до 90)
 @param longitude географическая долгота отметки, заданная в градусах (от -180 до 180)
 @param friendsOnly 1 — отметка будет доступна только друзьям, 0 — отметка будет доступна всем пользователям
 @return ответ на запрос в виде Foundation объекта
 */
- (id)checkInPlaceID:(NSUInteger)placeID text:(NSString *)text latitude:(CGFloat)latitude longitude:(CGFloat)longitude friendsOnly:(NSUInteger)friendsOnly;

/** Отмечает пользователя в указанном месте
 
 @param options ключи-значения, с полным списком можно ознакомиться по ссылке: https://vk.com/dev/places.checkin
 @return ответ на запрос в виде Foundation объекта
 */
- (id)checkInCustomOptions:(NSDictionary *)options;

/**
 @name places.getCheckins
 */
/** Возвращает список отметок пользователей в местах согласно заданным параметрам
 
 @param options ключи-значения, с полным списком можно ознакомиться по ссылке: http://vk.com/dev/places.getCheckins
 @return ответ на запрос в виде Foundation объекта
 */
- (id)checkinsCustomOptions:(NSDictionary *)options;

/**
 @name places.getTypes
 */
/** Возвращает список всех возможных типов мест
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)types;

/**
 @name places.getCountries
 */
/** Возвращает список стран
 
 @return ответ на запрос в виде Foundation объекта
 */
- (id)countries;

/** Возвращает список стран
 
 @param options ключи-значения, с полным спсиком можно ознакомиться по ссылке: https://vk.com/dev/places.getCountries
 @return ответ на запрос в виде Foundation объекта
 */
- (id)countriesCustomOptions:(NSDictionary *)options;

/**
 @name places.getRegions
 */
/** Возвращает список регионов
 
 @param countryID идентификатор страны, полученный в методе countries:
 @return ответ на запрос в виде Foundation объекта
 */
- (id)regionsCuntryID:(NSUInteger)countryID;

/** Возвращает список регионов
 
 @param countryID идентификатор страны, полученный в методе countries:
 @param query строка поискового запроса. Например, Лен.
 @return ответ на запрос в виде Foundation объекта
 */
- (id)regionsCuntryID:(NSUInteger)countryID searchQuery:(NSString *)query;

/**
 @name places.getStreetById
 */
/** Возвращает информацию об улицах по их идентификаторам
 
 @param streetsIDs идентификаторы улиц
 @return ответ на запрос в виде Foundation объекта
 */
- (id)streetsByIDs:(NSArray *)streetsIDs;

/**
 @name places.getCountryById
 */
/** Возвращает информацию о странах по их идентификаторам
 
 @param countriesIDs идентификаторы стран
 @return ответ на запрос в виде Foundation объекта
 */
- (id)countriesByIDs:(NSArray *)countriesIDs;

/**
 @name places.getCities
 */
/** Возвращает список городов
 
 @param countryID идентификатор страны, полученный в методе countries:
 @return ответ на запрос в виде Foundation объекта
 */
- (id)citiesCountryID:(NSUInteger)countryID;

/** Возвращает список городов
 
 @param countryID идентификатор страны, полученный в методе countries:
 @param query строка поискового запроса. Например, Санкт.
 @return ответ на запрос в виде Foundation объекта
 */
- (id)citiesCountryID:(NSUInteger)countryID searchQuery:(NSString *)query;

/**
 @name places.getCityById
 */
/** Возвращает информацию о городах по их идентификаторам
 
 @param citiesIDs идентификаторы городов
 @return ответ на запрос в виде Foundation объекта
 */
- (id)citiesByIDs:(NSArray *)citiesIDs;

@end