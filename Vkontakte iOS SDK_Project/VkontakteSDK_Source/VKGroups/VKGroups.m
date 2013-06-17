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
#import "VKGroups.h"
#import "VKConnector.h"
#import "VKUser.h"

@implementation VKGroups
{
    
}

#pragma mark Visible VKGroups methods
#pragma mark - groups.isMember

- (id)isMemberGroupID:(NSUInteger)groupID
{
    NSUInteger currentUserID = [[VKUser currentUser] userID];
    NSDictionary *options = @{@"group_id": @(groupID),
                              @"user_id": @(currentUserID),
                              @"extended": @1};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKGroupsIsMember
                                                 options:options
                                                   error:nil];
}

- (id)isMemberGroupID:(NSUInteger)groupID userID:(NSUInteger)userID
{
    NSDictionary *options = @{@"group_id": @(groupID),
                              @"user_id": @(userID),
                              @"extended": @1};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKGroupsIsMember
                                                 options:options
                                                   error:nil];
}

#pragma mark - groups.getById

- (id)byIDs:(NSArray *)groupsIDs fields:(NSArray *)fields
{
    NSDictionary *options = @{@"gids": [groupsIDs componentsJoinedByString:@","],
                              @"fields": [fields componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKGroupsGetById
                                                 options:options
                                                   error:nil];
}

- (id)byIDs:(NSArray *)groupsIDs
{
    return [self byIDs:groupsIDs fields:@[]];
}

#pragma mark - groups.get

- (id)listCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKGroupsGet
                                                 options:options
                                                   error:nil];
}

- (id)listCount:(NSUInteger)count offset:(NSUInteger)offset filter:(NSArray *)filter fields:(NSArray *)fields
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"filter": [filter componentsJoinedByString:@","],
                              @"fields": [fields componentsJoinedByString:@","]};
    
    return [self listCustomOptions:options];
}

- (id)listCount:(NSUInteger)count offset:(NSUInteger)offset
{
    return [self listCount:count offset:offset filter:@[] fields:@[]];
}

#pragma mark - groups.getMembers

- (id)membersCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKGroupsGetMembers
                                                 options:options
                                                   error:nil];
}

- (id)membersGroupID:(NSUInteger)groupID count:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"group_id": @(groupID),
                              @"count": @(count),
                              @"offset": @(offset)};
    
    return [self membersCustomOptions:options];
}

#pragma mark - groups.join

- (id)joinMeetingID:(NSUInteger)meetingID notSure:(NSUInteger)notSure
{
    NSDictionary *options = @{@"group_id": @(meetingID),
                              @"not_sure": @(notSure)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKGroupsJoin
                                                 options:options
                                                   error:nil];
}

- (id)joinGroupID:(NSUInteger)groupID
{
    return [self joinMeetingID:groupID notSure:0];
}

#pragma mark - groups.leave

- (id)leaveGroupID:(NSUInteger)groupID
{
    NSDictionary *options = @{@"group_id": @(groupID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKGroupsLeave
                                                 options:options
                                                   error:nil];
}

#pragma mark - groups.search

- (id)searchQuery:(NSString *)query sort:(NSUInteger)sort count:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"q": query,
                              @"sort": @(sort),
                              @"count": @(count),
                              @"offset": @(offset)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKGroupsSearch
                                                 options:options
                                                   error:nil];
}

- (id)searchQuery:(NSString *)query count:(NSUInteger)count offset:(NSUInteger)offset
{
    return [self searchQuery:query sort:0 count:count offset:offset];
}

- (id)searchQuery:(NSString *)query count:(NSUInteger)count
{
    return [self searchQuery:query count:count offset:0];
}

- (id)searchQuery:(NSString *)query
{
    return [self searchQuery:query count:20]; // default value https://vk.com/dev/groups.search
}

#pragma mark - groups.getInvites

- (id)invitesCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKGroupsGetInvites
                                                 options:options
                                                   error:nil];
}

- (id)invitesCount:(NSUInteger)count
{
    return [self invitesCount:count offset:0];
}

- (id)invites
{
    return [self invitesCount:20]; // default value https://vk.com/dev/groups.getInvites
}

@end