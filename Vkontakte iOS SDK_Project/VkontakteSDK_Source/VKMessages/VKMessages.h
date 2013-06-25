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
Класс предназначен для работы с пользовательскими сообщения, групповыми чатами и тд.
*/
@interface VKMessages : NSObject

/**
@name messages.get
*/
/** Возвращает список входящих либо исходящих личных сообщений текущего пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.get
@return ответ на запрос в виде Foundation объекта
*/
- (id)getCustomOptions:(NSDictionary *)options;

/**
@name messages.getDialogs
*/
/** Возвращает список диалогов текущего пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.getDialogs
@return ответ на запрос в виде Foundation объекта
*/
- (id)getDialogsCustomOptions:(NSDictionary *)options;

/**
@name messages.getById
*/
/** Возвращает сообщения по их id
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.getById
@return ответ на запрос в виде Foundation объекта
*/
- (id)getByIdCustomOptions:(NSDictionary *)options;

/**
@name messages.search
*/
/** Возвращает список найденных личных сообщений текущего пользователя по введенной строке поиска
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.search
@return ответ на запрос в виде Foundation объекта
*/
- (id)searchCustomOptions:(NSDictionary *)options;

/**
@name messages.getHistory
*/
/** Возвращает историю сообщений для указанного пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.getHistory
@return ответ на запрос в виде Foundation объекта
*/
- (id)getHistoryCustomOptions:(NSDictionary *)options;

/**
@name messages.send
*/
/** Отправляет сообщение
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.send
@return ответ на запрос в виде Foundation объекта
*/
- (id)sendCustomOptions:(NSDictionary *)options;

/**
@name messages.delete
*/
/** Удаляет сообщение
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.delete
@return ответ на запрос в виде Foundation объекта
*/
- (id)deleteCustomOptions:(NSDictionary *)options;

/**
@name messages.deleteDialog
*/
/** Удаляет все личные сообщения в диалоге
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.deleteDialog
@return ответ на запрос в виде Foundation объекта
*/
- (id)deleteDialogCustomOptions:(NSDictionary *)options;

/**
@name messages.restore
*/
/** Восстанавливает удаленное сообщение
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.restore
@return ответ на запрос в виде Foundation объекта
*/
- (id)restoreCustomOptions:(NSDictionary *)options;

/**
@name messages.markAsNew
*/
/** Помечает сообщения как непрочитанные
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.markAsNew
@return ответ на запрос в виде Foundation объекта
*/
- (id)markAsNewCustomOptions:(NSDictionary *)options;

/**
@name messages.markAsRead
*/
/** Помечает сообщения как прочитанные
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.markAsRead
@return ответ на запрос в виде Foundation объекта
*/
- (id)markAsReadCustomOptions:(NSDictionary *)options;

/**
@name messages.getLongPollServer
*/
/** Возвращает данные, необходимые для подключения к Long Poll серверу
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.getLongPollServer
@return ответ на запрос в виде Foundation объекта
*/
- (id)getLongPollServerCustomOptions:(NSDictionary *)options;

/**
@name messages.getLongPollHistory
*/
/** Возвращает обновления в личных сообщениях пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.getLongPollHistory
@return ответ на запрос в виде Foundation объекта
*/
- (id)getLongPollHistoryCustomOptions:(NSDictionary *)options;

/**
@name messages.getChat
*/
/** Возвращает информацию о беседе
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.getChat
@return ответ на запрос в виде Foundation объекта
*/
- (id)getChatCustomOptions:(NSDictionary *)options;

/**
@name messages.createChat
*/
/** Создаёт беседу с несколькими участниками
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.createChat
@return ответ на запрос в виде Foundation объекта
*/
- (id)createChatCustomOptions:(NSDictionary *)options;

/**
@name messages.editChat
*/
/** Изменяет название беседы
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.editChat
@return ответ на запрос в виде Foundation объекта
*/
- (id)editChatCustomOptions:(NSDictionary *)options;

/**
@name messages.getChatUsers
*/
/** Позволяет получить список пользователей мультидиалога по его id
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.getChatUsers
@return ответ на запрос в виде Foundation объекта
*/
- (id)getChatUsersCustomOptions:(NSDictionary *)options;

/**
@name messages.setActivity
*/
/** Изменяет статус набора текста пользователем в диалоге
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.setActivity
@return ответ на запрос в виде Foundation объекта
*/
- (id)setActivityCustomOptions:(NSDictionary *)options;

/**
@name messages.searchDialogs
*/
/** Возвращает список найденных диалогов текущего пользователя по введенной строке поиска
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.searchDialogs
@return ответ на запрос в виде Foundation объекта
*/
- (id)searchDialogsCustomOptions:(NSDictionary *)options;

/**
@name messages.addChatUser
*/
/** Добавляет в мультидиалог нового пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.addChatUser
@return ответ на запрос в виде Foundation объекта
*/
- (id)addChatUserCustomOptions:(NSDictionary *)options;

/**
@name messages.removeChatUser
*/
/** Исключает из мультидиалога пользователя, если текущий пользователь был создателем беседы либо пригласил исключаемого пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.removeChatUser
@return ответ на запрос в виде Foundation объекта
*/
- (id)removeChatUserCustomOptions:(NSDictionary *)options;

/**
@name messages.getLastActivity
*/
/** Возвращает текущий статус и дату последней активности указанного пользователя
@param options ключи-значения, с полным списком можно ознакомиться по этой ссылке: https://vk.com/dev/messages.getLastActivity
@return ответ на запрос в виде Foundation объекта
*/
- (id)getLastActivityCustomOptions:(NSDictionary *)options;

@end