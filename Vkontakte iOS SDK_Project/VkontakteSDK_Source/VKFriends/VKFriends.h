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

@interface VKFriends : NSObject

// friends.get
- (id)friendsCount:(NSUInteger)count;
- (id)friendsCount:(NSUInteger)count fields:(NSString *)fields;
- (id)friendsCount:(NSUInteger)count offset:(NSUInteger)offset;
- (id)friendsCount:(NSUInteger)count offset:(NSUInteger)offset fields:(NSString *)fields;
- (id)friendsCount:(NSUInteger)count offset:(NSUInteger)offset order:(NSString *)order fields:(NSString *)fields;
- (id)friendsCustomOptions:(NSDictionary *)options;

// friends.getOnline
- (id)friendsOnline;
- (id)friendsOnlineCount:(NSUInteger)count offset:(NSUInteger)offset;
- (id)friendsOnlineCustomOptions:(NSDictionary *)options;

// friends.getMutual
- (id)friendsMutualWithUserID:(NSUInteger)userID;
- (id)friendsMutualWithUserID:(NSUInteger)userID count:(NSUInteger)count;
- (id)friendsMutualWithUserID:(NSUInteger)userID count:(NSUInteger)count offset:(NSUInteger)offset;
- (id)friendsMutualCustomOptions:(NSDictionary *)options;

// friends.getRecent
- (id)friendsGetRecent;
- (id)friendsGetRecentCount:(NSUInteger)count;

// friends.getRequests
- (id)friendsInRequestsCount:(NSUInteger)count;
- (id)friendsInRequestsCount:(NSUInteger)count offset:(NSUInteger)offset;
- (id)friendsOutRequestsCount:(NSUInteger)count;
- (id)friendsOutRequestsCount:(NSUInteger)count offset:(NSUInteger)offset;
- (id)friendsRequestsCustomOptions:(NSDictionary *)options;

// friends.add
- (id)friendsAddUserID:(NSUInteger)userID;
- (id)friendsAddUserID:(NSUInteger)userID text:(NSString *)text;

// friends.edit
- (id)friendsEditCustomOptions:(NSDictionary *)options;

// friends.delete
- (id)friendsRemoveUserID:(NSUInteger)userID;

// friends.getLists
- (id)friendsLists;

// friends.addList
- (id)friendsCreateNewList:(NSString *)listName;
- (id)friendsCreateNewList:(NSString *)listName friendsIDs:(NSArray *)friendsIDs;

// friends.editList
- (id)friendsEditListCustomOptions:(NSDictionary *)options;

// friends.deleteList
- (id)friendsDeleteListID:(NSUInteger)listID;

// friends.getAppUsers
- (id)friendsInCurrentApplication;

// friends.getByPhones
- (id)friendsByPhones:(NSArray *)phones fields:(NSArray *)fields;

// friends.deleteAllRequests
- (id)friendsDeleteRequests;

// friends.getSuggestions
- (id)friendsSuggestions;
- (id)friendsSuggestionsCount:(NSUInteger)count;
- (id)friendsSuggestionsCount:(NSUInteger)count offset:(NSUInteger)offset;
- (id)friendsSuggestionsCount:(NSUInteger)count offset:(NSUInteger)offset fields:(NSArray *)fields;
- (id)friendsSuggestionsCustomOptions:(NSDictionary *)options;

// friends.areFriends
- (id)friendsWithUsers:(NSArray *)userIDs;

@end