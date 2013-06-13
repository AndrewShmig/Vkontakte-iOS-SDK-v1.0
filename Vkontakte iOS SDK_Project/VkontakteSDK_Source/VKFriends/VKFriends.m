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

- (id)count:(NSUInteger)count
{
    NSDictionary *options = @{@"order": @"hints",
                              @"count": @(count),
                              @"fields": @"first_name,last_name,sex,bdate,photo_medium"};
    
    return [self customOptions:options];
}

- (id)count:(NSUInteger)count fields:(NSString *)fields
{
    NSDictionary *options = @{@"count": @(count),
                              @"fields": fields,
                              @"order": @"hints"};
    
    return [self customOptions:options];
}

- (id)count:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"fields": @"first_name,last_name,sex,bdate,photo_medium",
                              @"order": @"hints"};
    
    return [self customOptions:options];
}

- (id)count:(NSUInteger)count offset:(NSUInteger)offset fields:(NSString *)fields
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"fields": fields,
                              @"order": @"hints"};
    
    return [self customOptions:options];
}

- (id)count:(NSUInteger)count offset:(NSUInteger)offset order:(NSString *)order fields:(NSString *)fields
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"order": order,
                              @"fields": fields};
    
    return [self customOptions:options];
}

- (id)customOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGet
                                                 options:options
                                                   error:nil];
}

- (id)onlineCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetOnline
                                                 options:options
                                                   error:nil];
}

- (id)onlineCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSUInteger userID = [[VKUser currentUser] userID];
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"uid": @(userID)};
    
    return [self onlineCustomOptions:options];
}

- (id)online
{
    NSUInteger userID = [[VKUser currentUser] userID];
    NSDictionary *options = @{@"uid": @(userID)};
    
    return [self onlineCustomOptions:options];
}

- (id)mutualCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetMutual
                                                 options:options
                                                   error:nil];
}

- (id)mutualWithUserID:(NSUInteger)userID count:(NSUInteger)count offset:(NSUInteger)offset
{
    NSUInteger currentUserID = [[VKUser currentUser] userID];
    NSDictionary *options = @{@"source_uid": @(currentUserID),
                              @"target_uid": @(userID),
                              @"count": @(count),
                              @"offset": @(offset)};
    
    return [self mutualCustomOptions:options];
}

- (id)mutualWithUserID:(NSUInteger)userID count:(NSUInteger)count
{
    return [self mutualWithUserID:userID
                            count:count
                           offset:0];
}

- (id)mutualWithUserID:(NSUInteger)userID
{
    NSUInteger currentUserID = [[VKUser currentUser] userID];
    NSDictionary *options = @{@"source_uid": @(currentUserID),
                              @"target_uid": @(userID)};
    
    return [self mutualCustomOptions:options];
}

- (id)recentCount:(NSUInteger)count
{
    NSDictionary *options = @{@"count": @(count)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetRecent
                                                 options:options
                                                   error:nil];
}

- (id)recent
{
    return [self recentCount:100];
}

- (id)requestsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetRequests
                                                 options:options
                                                   error:nil];
}

- (id)outRequestsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"need_count": @1,
                              @"offset": @(offset),
                              @"count": @(count),
                              @"out": @(1)};
    
    return [self requestsCustomOptions:options];
}

- (id)outRequestsCount:(NSUInteger)count
{
    return [self outRequestsCount:count
                           offset:0];
}

- (id)inRequestsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"need_count": @1,
                              @"offset": @(offset),
                              @"count": @(count),
                              @"out": @(0)};
    
    return [self requestsCustomOptions:options];
}

- (id)inRequestsCount:(NSUInteger)count
{
    return [self inRequestsCount:count offset:0];
}

- (id)addUserID:(NSUInteger)userID text:(NSString *)text
{
    NSDictionary *options = @{@"uid": @(userID),
                              @"text": text};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsAdd
                                                 options:options
                                                   error:nil];
}

- (id)addUserID:(NSUInteger)userID
{
    return [self addUserID:userID text:@""];
}

- (id)editCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsEdit
                                                 options:options
                                                   error:nil];
}

- (id)removeUserID:(NSUInteger)userID
{
    NSDictionary *options = @{@"uid": @(userID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsDelete
                                                 options:options
                                                   error:nil];
}

- (id)lists
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetLists
                                                 options:@{}
                                                   error:nil];
}

- (id)createNewList:(NSString *)listName friendsIDs:(NSArray *)friendsIDs
{
    NSDictionary *options = @{@"name": listName,
                              @"uids": [friendsIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsAddList
                                                 options:options
                                                   error:nil];
}

- (id)createNewList:(NSString *)listName
{
    return [self createNewList:listName
                    friendsIDs:@[]];
}

- (id)editListCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsEditList
                                                 options:options
                                                   error:nil];
}

- (id)deleteListID:(NSUInteger)listID
{
    NSDictionary *options = @{@"lid": @(listID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsDeleteList
                                                 options:options
                                                   error:nil];
}

- (id)inCurrentApplication
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetAppUsers
                                                 options:@{}
                                                   error:nil];
}

- (id)byPhones:(NSArray *)phones fields:(NSArray *)fields
{
    NSDictionary *options = @{@"phones": [phones componentsJoinedByString:@","],
                              @"fields": [fields componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetByPhones
                                                 options:options
                                                   error:nil];
}

- (id)deleteRequests
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsDeleteAllRequests
                                                 options:@{}
                                                   error:nil];
}

- (id)suggestionsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsGetSuggestions
                                                 options:options
                                                   error:nil];
}

- (id)suggestionsCount:(NSUInteger)count offset:(NSUInteger)offset fields:(NSArray *)fields
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"fields": [fields componentsJoinedByString:@","]};
    
    return [self suggestionsCustomOptions:options];
}

- (id)suggestionsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    return [self suggestionsCount:count
                           offset:offset
                           fields:@[]];
}

- (id)suggestionsCount:(NSUInteger)count
{
    return [self suggestionsCount:count
                           offset:0];
}

- (id)suggestions
{
    return [self suggestionsCustomOptions:@{}];
}

- (id)withUsers:(NSArray *)userIDs
{
    NSDictionary *options = @{@"uids": [userIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFriendsAreFriends
                                                 options:options
                                                   error:nil];
}

@end