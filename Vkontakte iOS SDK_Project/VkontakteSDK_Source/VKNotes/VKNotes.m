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

#import "VKNotes.h"
#import "VKConnector.h"
#import "VKUser.h"

@implementation VKNotes
{
    
}

#pragma mark - Visible VKNotes methods
#pragma mark notes.get

- (id)count:(NSUInteger)count
{
    return [self count:count
                offset:0
                  sort:0]; // 0  — по дате создания в порядке убывания, 1 - по дате создания в порядке возрастания
}

- (id)count:(NSUInteger)count offset:(NSUInteger)offset
{
    return [self count:count
                offset:offset
                  sort:0]; // 0  — по дате создания в порядке убывания, 1 - по дате создания в порядке возрастания
}

- (id)count:(NSUInteger)count offset:(NSUInteger)offset sort:(NSUInteger)sort
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"sort": @(sort)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesGet
                                                 options:options
                                                   error:nil];
}

- (id)withIDs:(NSArray *)notesIDs count:(NSUInteger)count offset:(NSUInteger)offset sort:(NSUInteger)sort
{
    NSDictionary *options = @{@"nids": [notesIDs componentsJoinedByString:@","],
                              @"count": @(count),
                              @"offset": @(offset),
                              @"sort": @(sort)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesGet
                                                 options:options
                                                   error:nil];
}

#pragma mark notes.getByID

- (id)noteWithID:(NSUInteger)noteID
{
    return [self noteWithID:noteID
                       wiki:1]; // вернуть с вики разметкой
}

- (id)noteWithID:(NSUInteger)noteID wiki:(NSUInteger)wiki
{
    NSUInteger currentUserID = [[VKUser currentUser] userID];
    
    return [self noteWithID:noteID
                       wiki:wiki
                    ownerID:currentUserID];
}

- (id)noteWithID:(NSUInteger)noteID wiki:(NSUInteger)wiki ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"nid": @(noteID),
                              @"owner_id": @(ownerID),
                              @"need_wiki": @(wiki)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesGetById
                                                 options:options
                                                   error:nil];
}

#pragma mark notes.getFriendsNotes

- (id)friendNotesCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesGetFriendsNotes
                                                 options:options
                                                   error:nil];
}

#pragma mark notes.add

- (id)addTitle:(NSString *)title text:(NSString *)text privacy:(NSUInteger)privacy commentPrivacy:(NSUInteger)commentPrivacy
{
    NSDictionary *options = @{@"title": title,
                              @"text": text,
                              @"privacy": @(privacy),
                              @"comment_privacy": @(commentPrivacy)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesAdd
                                                 options:options
                                                   error:nil];
}

#pragma mark notes.edit

- (id)editWithID:(NSUInteger)noteID title:(NSString *)title text:(NSString *)text privacy:(NSUInteger)privacy commentPrivacy:(NSUInteger)commentPrivacy
{
    NSDictionary *options = @{@"nid": @(noteID),
                              @"title": title,
                              @"text": text,
                              @"privacy": @(privacy),
                              @"comment_privacy": @(commentPrivacy)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesEdit
                                                 options:options
                                                   error:nil];
}

#pragma mark notes.delete

- (id)deleteWithID:(NSUInteger)noteID
{
    NSDictionary *options = @{@"nid": @(noteID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesDelete
                                                 options:options
                                                   error:nil];
}

#pragma mark notes.getComments

- (id)commentsWithID:(NSUInteger)noteID count:(NSUInteger)count offset:(NSUInteger)offset sort:(NSUInteger)sort
{
    NSDictionary *options = @{@"nid": @(noteID),
                              @"sort": @(sort),
                              @"offset": @(offset),
                              @"count": @(count)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesGetComments
                                                 options:options
                                                   error:nil];
}

#pragma mark notes.createComment

- (id)addComment:(NSString *)comment noteID:(NSUInteger)noteID ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"nid": @(noteID),
                              @"message": comment,
                              @"owner_id": @(ownerID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesCreateComment
                                                 options:options
                                                   error:nil];
}

- (id)addComment:(NSString *)comment noteID:(NSUInteger)noteID ownerID:(NSUInteger)ownerID replyToUserID:(NSUInteger)userID
{
    NSDictionary *options = @{@"nid": @(noteID),
                              @"message": comment,
                              @"owner_id": @(ownerID),
                              @"reply_to": @(userID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesCreateComment
                                                 options:options
                                                   error:nil];
}

#pragma mark notes.editComment

- (id)editCommentWithID:(NSUInteger)commentID comment:(NSString *)comment
{
    NSDictionary *options = @{@"cid": @(commentID),
                              @"message": comment};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesEditComment
                                                 options:options
                                                   error:nil];
}

#pragma mark notes.deleteComment

- (id)deleteCommentWithID:(NSUInteger)commentID ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"cid": @(commentID),
                              @"owner_id": @(ownerID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesDeleteComment
                                                 options:options
                                                   error:nil];
}

#pragma mark notes.restoreComment

- (id)restoreCommentWithID:(NSUInteger)commentID ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"cid": @(commentID),
                              @"owner_id": @(ownerID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKNotesRestoreComment
                                                 options:options
                                                   error:nil];
}

#pragma mark - Hidden VKNotes methods

@end