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
#import "VKLikes.h"
#import "VKUser.h"
#import "VKConnector.h"

@implementation VKLikes

#pragma mark - VKLikes methods

- (id)likeObjectWithID:(NSUInteger)objectID type:(NSString *)type ownerID:(NSUInteger)ownerID
{
    NSDictionary *params = @{@"item_id": @(objectID),
                             @"type": type,
                             @"owner_id": @(ownerID),
                             @"access_key": @""};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKLikesAdd
                                                 options:params
                                                   error:nil];
}

- (id)unlikeObjectWithID:(NSUInteger)objectID type:(NSString *)type ownerID:(NSUInteger)ownerID
{
    NSDictionary *params = @{@"item_id": @(objectID),
                             @"owner_id": @(ownerID),
                             @"type": type};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKLikesDelete
                                                 options:params
                                                   error:nil];
}

- (id)isLikedObjectWithID:(NSUInteger)objectID type:(NSString *)type ownerID:(NSUInteger)ownerID
{
    NSUInteger userID = [[VKUser currentUser] userID];
    NSDictionary *params = @{@"user_id": @(userID),
                             @"type": type,
                             @"owner_id": @(ownerID),
                             @"item_id": @(objectID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKLikesIsLiked
                                                 options:params
                                                   error:nil];
}

- (id)isLikedObjectWithID:(NSUInteger)objectID type:(NSString *)type
{
    NSUInteger userID = [[VKUser currentUser] userID];
    
    return [self isLikedObjectWithID:objectID
                                type:type
                             ownerID:userID];
}

- (id)obtainListWithOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKLikesGetList
                                                 options:options
                                                   error:nil];
}

@end