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

@end