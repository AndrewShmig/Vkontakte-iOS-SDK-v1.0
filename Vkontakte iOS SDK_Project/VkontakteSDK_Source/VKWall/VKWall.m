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

#import "VKWall.h"
#import "VKConnector.h"
#import "VKUser.h"

@implementation VKWall

#pragma mark Visible VKWall methods
#pragma mark - wall.get

- (id)count:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKWallGet
                                                 options:options
                                                   error:nil];
}

- (id)count:(NSUInteger)count offset:(NSUInteger)offset ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"owner_id": @(ownerID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKWallGet
                                                 options:options
                                                   error:nil];
}

- (id)customOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKWallGet
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.getById

- (id)byIDs:(NSArray *)postsIDs
{
    NSDictionary *options = @{@"posts": [postsIDs componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKWallGetById
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.savePost

- (id)savePostCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKWallSavePost
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.post

- (id)postCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKWallPost
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.repost

- (id)repostObjectID:(NSUInteger)objectID message:(NSString *)message
{
    NSDictionary *options = @{@"object": @(objectID),
                              @"message": message};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKWallRepost
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.getReposts

- (id)repostsOwnerID:(NSUInteger)ownerID postID:(NSUInteger)postID count:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"owner_id": @(ownerID),
                              @"post_id": @(postID),
                              @"count": @(count),
                              @"offset": @(offset)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKWallGetReposts
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.edit

- (id)editCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKWallEdit
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.delete

- (id)removePostID:(NSUInteger)postID ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"owner_id": @(ownerID),
                              @"post_id": @(postID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKWallDelete
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.restore

- (id)restorePostID:(NSUInteger)postID ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"owner_id": @(ownerID),
                              @"post_id": @(postID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKWallRestore
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.getComments

- (id)commentsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKWallGetComments
                                                 options:options
                                                   error:nil];
}

- (id)commentsPostID:(NSUInteger)postID ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"post_id": @(postID),
                              @"owner_id": @(ownerID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKWallGetComments
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.addComment

- (id)addCommentCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKWallAddComment
                                                 options:options
                                                   error:nil];
}

- (id)addCommentPostID:(NSUInteger)postID ownerID:(NSUInteger)ownerID text:(NSString *)text
{
    NSDictionary *options = @{@"post_id": @(postID),
                              @"owner_id": @(ownerID),
                              @"text": text};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKWallAddComment
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.deleteComment

- (id)removeCommentID:(NSUInteger)commentID ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"owner_id": @(ownerID),
                              @"cid": @(commentID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKWallDeleteComment
                                                 options:options
                                                   error:nil];
}

#pragma mark - wall.restoreComment

- (id)restoreCommentID:(NSUInteger)commentID ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"owner_id": @(ownerID),
                              @"cid": @(commentID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKWallRestoreComment
                                                 options:options
                                                   error:nil];
}

@end