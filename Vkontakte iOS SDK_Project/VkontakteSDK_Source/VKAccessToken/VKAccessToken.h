//
// Created by AndrewShmig on 5/28/13.
//
// Copyright (c) AndrewShmig. All rights reserved.
//
#import <Foundation/Foundation.h>


/**
 Класс содержит информацию о пользовательском токене доступа.
 
 Кроме самого токена доступа хранится следующая информация:
 
 - список прав к которым есть доступ приложения (offline, photo, docs, friends, ex и др)
 - срок истечения действия токена
 - пользовательский идентификатор в социальной сети ВКонтакте
 - токен доступа
 */

@interface VKAccessToken : NSObject

/**
 @name Свойства
 */

/**
 Массив пользовательских разрешений к которым был получен доступ приложением
 */
@property (nonatomic, readonly) NSArray *permissions;

/**
 Время истечения действия токена.
 */
@property (nonatomic, readonly) NSTimeInterval expirationTime;

/**
 Пользовательский идентификатор в социальной сети ВКонтакте.
 */
@property (nonatomic, readonly) NSUInteger userID;

/**
 Токен доступа.
 */
@property (nonatomic, readonly) NSString *token;



/**
 @name Методы инициализации
 */

/**
 Основной метод инициализации.
 
 @param userID Пользовательский идентификатор в социальной сети ВКонтакте.
 @param token Токен доступа.
 @param expirationTime Время истечения действия токена доступа.
 @param permissions Список полученных приложением прав.
 @return Объект VKAccessToken класса.
 */
- (id)initWithUserID:(NSUInteger)userID
         accessToken:(NSString *)token
      expirationTime:(NSTimeInterval)expirationTime
         permissions:(NSArray *)permissions;

/**
 Вторичный метод инициализации класса.
 
 permissions принимает значение по умолчанию  @[].
 
 @see initWithUserID:accessToken:expirationTime:permissions:
 
 @param userID Пользовательский идентификатор в социальной сети ВКонтакте.
 @param token Токен доступа.
 @param expirationTime Время истечения действия токена доступа.
 @return Объект VKAccessToken класса.
 */
- (id)initWithUserID:(NSUInteger)userID
         accessToken:(NSString *)token
      expirationTime:(NSTimeInterval)expirationTime;

/**
Вторичный метод инициализации класса.
 
 permissions принимает значение по умолчанию @[].
 
 expirationTime принимает значение по умолчанию 0.
 
 @see initWithUserID:accessToken:expirationTime:permissions:
 
 @param userID Пользовательский идентификатор в социальной сети ВКонтакте
 @param token Токен доступа.
 @return Объект VKAccessToken класса.
 */
- (id)initWithUserID:(NSUInteger)userID
         accessToken:(NSString *)token;

/**
 @name Перегруженные методы
 */
/**
 Описание состояния класса VKAccessToken.
 
 @return Строковое представление текущего класса.
 */
- (NSString *)description;



/**
 @name Публичные методы
 */
/**
 Метод проверяет наличие определенного доступа в общем списке доступов данного токена.
 
 @param permission Наименование доступа.
 @return YES - если такое право присутствует в общем списке, иначе - NO.
 */
- (BOOL)hasPermission:(NSString *)permission;

/**
 Метод проверяет истекло ли время действия текущего токена доступа или нет.
 
 @return YES - если токен всё еще действует, иначе - NO.
 
 Метод вернет YES в следующих случаях:
 
 - Время истечения токена больше нуля и больше текущего времени.
 - Время истечения токена равно нулю и в списке доступов присутствует "offline" доступ
 
 */
- (BOOL)isExpired;

@end