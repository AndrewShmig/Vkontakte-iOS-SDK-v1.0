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
#import "VKFriends.h"
#import "VKConnector.h"
#import "VKUser.h"


@implementation VKFriends

#pragma mark - Visible VKFriends methods

- (id)friendsCount:(NSUInteger)count
{
    NSDictionary *options = @{@"order": @"hints",
                              @"count": @(count),
                              @"fields": @"first_name,last_name,sex,bdate,photo_medium"};
    
    return [self friendsCustomOptions:options];
}

- (id)friendsCount:(NSUInteger)count fields:(NSString *)fields
{
    NSDictionary *options = @{@"count": @(count),
                              @"fields": fields,
                              @"order": @"hints"};
    
    return [self friendsCustomOptions:options];
}

- (id)friendsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"fields": @"first_name,last_name,sex,bdate,photo_medium",
                              @"order": @"hints"};
    
    return [self friendsCustomOptions:options];
}

- (id)friendsCount:(NSUInteger)count offset:(NSUInteger)offset fields:(NSString *)fields
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"fields": fields,
                              @"order": @"hints"};
    
    return [self friendsCustomOptions:options];
}

- (id)friendsCount:(NSUInteger)count offset:(NSUInteger)offset order:(NSString *)order fields:(NSString *)fields
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"order": order,
                              @"fields": fields};
    
    return [self friendsCustomOptions:options];
}

- (id)friendsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGet
                                                 options:options
                                                   error:nil];
}

- (id)friendsOnlineCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetOnline
                                                 options:options
                                                   error:nil];
}

- (id)friendsOnlineCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSUInteger userID = [[VKUser currentUser] userID];
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"uid": @(userID)};
    
    return [self friendsOnlineCustomOptions:options];
}

- (id)friendsOnline
{
    NSUInteger userID = [[VKUser currentUser] userID];
    NSDictionary *options = @{@"uid": @(userID)};
    
    return [self friendsCustomOptions:options];
}

- (id)friendsMutualCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetMutual
                                                 options:options
                                                   error:nil];
}

- (id)friendsMutualWithUserID:(NSUInteger)userID count:(NSUInteger)count offset:(NSUInteger)offset
{
    NSUInteger currentUserID = [[VKUser currentUser] userID];
    NSDictionary *options = @{@"source_uid": @(currentUserID),
                              @"target_uid": @(userID),
                              @"count": @(count),
                              @"offset": @(offset)};
    
    return [self friendsOnlineCustomOptions:options];
}

- (id)friendsMutualWithUserID:(NSUInteger)userID count:(NSUInteger)count
{
    return [self friendsMutualWithUserID:userID
                                   count:count
                                  offset:0];
}

- (id)friendsMutualWithUserID:(NSUInteger)userID
{
    NSUInteger currentUserID = [[VKUser currentUser] userID];
    NSDictionary *options = @{@"source_uid": @(currentUserID),
                              @"target_uid": @(userID)};
    
    return [self friendsMutualCustomOptions:options];
}

- (id)friendsGetRecentCount:(NSUInteger)count
{
    NSDictionary *options = @{@"count": @(count)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetRecent
                                                 options:options
                                                   error:nil];
}

- (id)friendsGetRecent
{
    return [self friendsGetRecentCount:100];
}

- (id)friendsRequestsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetRequests
                                                 options:options
                                                   error:nil];
}

- (id)friendsOutRequestsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"need_count": @1,
                              @"offset": @(offset),
                              @"count": @(count),
                              @"out": @(1)};
    
    return [self friendsRequestsCustomOptions:options];
}

- (id)friendsOutRequestsCount:(NSUInteger)count
{
    return [self friendsOutRequestsCount:count
                                  offset:0];
}

- (id)friendsInRequestsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"need_count": @1,
                              @"offset": @(offset),
                              @"count": @(count),
                              @"out": @(0)};
    
    return [self friendsRequestsCustomOptions:options];
}

- (id)friendsInRequestsCount:(NSUInteger)count
{
    return [self friendsInRequestsCount:count offset:0];
}

- (id)friendsAddUserID:(NSUInteger)userID text:(NSString *)text
{
    NSDictionary *options = @{@"uid": @(userID),
                              @"text": text};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsAdd
                                                 options:options
                                                   error:nil];
}

- (id)friendsAddUserID:(NSUInteger)userID
{
    return [self friendsAddUserID:userID text:@""];
}

- (id)friendsEditCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsEdit
                                                 options:options
                                                   error:nil];
}

- (id)friendsRemoveUserID:(NSUInteger)userID
{
    NSDictionary *options = @{@"uid": @(userID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsDelete
                                                 options:options
                                                   error:nil];
}

- (id)friendsLists
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetLists
                                                 options:@{}
                                                   error:nil];
}

- (id)friendsCreateNewList:(NSString *)listName friendsIDs:(NSArray *)friendsIDs
{
    NSDictionary *options = @{@"name": listName,
                              @"uids": [friendsIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsAddList
                                                 options:options
                                                   error:nil];
}

- (id)friendsCreateNewList:(NSString *)listName
{
    return [self friendsCreateNewList:listName
                           friendsIDs:@[]];
}

- (id)friendsEditListCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsEditList
                                                 options:options
                                                   error:nil];
}

- (id)friendsDeleteListID:(NSUInteger)listID
{
    NSDictionary *options = @{@"lid": @(listID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsDeleteList
                                                 options:options
                                                   error:nil];
}

- (id)friendsInCurrentApplication
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetAppUsers
                                                 options:@{}
                                                   error:nil];
}

- (id)friendsByPhones:(NSArray *)phones fields:(NSArray *)fields
{
    NSDictionary *options = @{@"phones": [phones componentsJoinedByString:@","],
                              @"fields": [fields componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetByPhones
                                                 options:options
                                                   error:nil];
}

- (id)friendsDeleteRequests
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsDeleteAllRequests
                                                 options:@{}
                                                   error:nil];
}

- (id)friendsSuggestionsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetSuggestions
                                                 options:options
                                                   error:nil];
}

- (id)friendsSuggestionsCount:(NSUInteger)count offset:(NSUInteger)offset fields:(NSArray *)fields
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"fields": [fields componentsJoinedByString:@","]};
    
    return [self friendsSuggestionsCustomOptions:options];
}

- (id)friendsSuggestionsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    return [self friendsSuggestionsCount:count
                                  offset:offset
                                  fields:@[]];
}

- (id)friendsSuggestionsCount:(NSUInteger)count
{
    return [self friendsSuggestionsCount:count
                                  offset:0];
}

- (id)friendsSuggestions
{
    return [self friendsSuggestionsCustomOptions:@{}];
}

- (id)friendsWithUsers:(NSArray *)userIDs
{
    NSDictionary *options = @{@"uids": [userIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsAreFriends
                                                 options:options
                                                   error:nil];
}

@end