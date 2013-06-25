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
#import "VKMessages.h"
#import "VKConnector.h"


@implementation VKMessages

#pragma mark Visible VKMessages methods
#pragma mark - messages.get

- (id)getCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesGet
                    options:options
                      error:nil];
}

#pragma mark - messages.getDialogs

- (id)getDialogsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesGetDialogs
                    options:options
                      error:nil];
}

#pragma mark - messages.getById

- (id)getByIdCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesGetById
                    options:options
                      error:nil];
}

#pragma mark - messages.search

- (id)searchCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesSearch
                    options:options
                      error:nil];
}

#pragma mark - messages.getHistory

- (id)getHistoryCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesGetHistory
                    options:options
                      error:nil];
}

#pragma mark - messages.send

- (id)sendCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesSend
                    options:options
                      error:nil];
}

#pragma mark - messages.delete

- (id)deleteCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesDelete
                    options:options
                      error:nil];
}

#pragma mark - messages.deleteDialog

- (id)deleteDialogCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesDeleteDialog
                    options:options
                      error:nil];
}

#pragma mark - messages.restore

- (id)restoreCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesRestore
                    options:options
                      error:nil];
}

#pragma mark - messages.markAsRead

- (id)markAsReadCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesMarkAsRead
                    options:options
                      error:nil];
}

#pragma mark - messages.markAsNew

- (id)markAsNewCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesMarkAsNew
                    options:options
                      error:nil];
}

#pragma mark - messages.getLongPollServer

- (id)getLongPollServerCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesGetLongPollServer
                    options:options
                      error:nil];
}

#pragma mark - messages.getLongPollHistoryServer

- (id)getLongPollHistoryCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesGetLongPollHistory
                    options:options
                      error:nil];
}

#pragma mark - messages.getChat

- (id)getChatCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesGetChat
                    options:options
                      error:nil];
}

#pragma mark - messages.createChat

- (id)createChatCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesCreateChat
                    options:options
                      error:nil];
}

#pragma mark - messages.editChat

- (id)editChatCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesEditChat
                    options:options
                      error:nil];
}

#pragma mark - messages.getChatUsers

- (id)getChatUsersCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesGetChatUsers
                    options:options
                      error:nil];
}

#pragma mark - messages.setActivity

- (id)setActivityCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesSetActivity
                    options:options
                      error:nil];
}

#pragma mark - messages.searchDialogs

- (id)searchDialogsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesSearchDialogs
                    options:options
                      error:nil];
}

#pragma mark - messages.addChatUser

- (id)addChatUserCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesAddChatUser
                    options:options
                      error:nil];
}

#pragma mark - messages.removeChatUser

- (id)removeChatUserCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesRemoveChatUser
                    options:options
                      error:nil];
}

#pragma mark - messages.getLastActivity

- (id)getLastActivityCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKMessagesGetLastActivity
                    options:options
                      error:nil];
}

@end