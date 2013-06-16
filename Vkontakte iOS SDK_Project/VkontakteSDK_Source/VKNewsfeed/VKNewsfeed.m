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
#import "VKNewsfeed.h"
#import "VKConnector.h"


@implementation VKNewsfeed
{
    
}

#pragma mark Visible VKNewsfeed methods
#pragma mark - newsfeed.get

- (id)filterCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedGet
                                                 options:options
                                                   error:nil];
}

#pragma mark - newsfeed.getRecommended

- (id)recommendedCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedGetRecommended
                                                 options:options
                                                   error:nil];
}

#pragma mark - newsfeed.getComments

- (id)commentsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedGetComments
                                                 options:options
                                                   error:nil];
}

#pragma mark - newsfeed.getMentions

- (id)mentionsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedGetMentions
                                                 options:options
                                                   error:nil];
}

#pragma mark - newsfeed.getBanned

- (id)banned
{
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedGetBanned
                                                 options:@{}
                                                   error:nil];
}

- (id)bannedExtended
{
    NSDictionary *options = @{@"extended": @1};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedGetBanned
                                                 options:options
                                                   error:nil];
}

- (id)bannedCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedGetBanned
                                                 options:options
                                                   error:nil];
}

#pragma mark - newsfeed.addBan

- (id)banUsers:(NSArray *)usersIDs
{
    NSDictionary *options = @{@"uids": [usersIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedAddBan
                                                 options:options
                                                   error:nil];
}

- (id)banGroups:(NSArray *)groupsIDs
{
    NSDictionary *options = @{@"gids": [groupsIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedAddBan
                                                 options:options
                                                   error:nil];
}

#pragma mark - newsfeed.deleteBan

- (id)unbanUsers:(NSArray *)usersIDs
{
    NSDictionary *options = @{@"uids": [usersIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedDeleteBan
                                                 options:options
                                                   error:nil];
}

- (id)unbanGroups:(NSArray *)groupsIDs
{
    NSDictionary *options = @{@"gids": [groupsIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedDeleteBan
                                                 options:options
                                                   error:nil];
}

#pragma mark - newsfeed.search

- (id)searchCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedSearch
                                                 options:options
                                                   error:nil];
}

#pragma mark - newsfeed.getLists

- (id)lists
{
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedGetLists
                                                 options:@{}
                                                   error:nil];
}

#pragma mark - newsfeed.unsibscribe

- (id)unsibscribeType:(NSString *)type ownerID:(NSUInteger)ownerID objectID:(NSUInteger)objectID
{
    NSDictionary *options = @{@"type": type,
                              @"owner_id": @(ownerID),
                              @"item_id": @(objectID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNewsfeedUnsibscribe
                                                 options:options
                                                   error:nil];
}

@end