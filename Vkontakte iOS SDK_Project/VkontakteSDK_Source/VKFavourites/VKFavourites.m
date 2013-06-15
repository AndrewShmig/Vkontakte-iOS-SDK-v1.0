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
#import "VKFavourites.h"
#import "VKConnector.h"


@implementation VKFavourites
{
    
}

#pragma mark Visible VKFavourites methods
#pragma mark - Users

- (id)usersCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFaveGetUsers
                                                 options:options
                                                   error:nil];
}

- (id)usersCount:(NSUInteger)count
{
    return [self usersCount:count
                     offset:0];
}

#pragma mark - Photos

- (id)photosCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFaveGetPhotos
                                                 options:options
                                                   error:nil];
}

- (id)photosCount:(NSUInteger)count
{
    return [self photosCount:count
                      offset:0];
}

#pragma mark - Posts

- (id)postsCount:(NSUInteger)count offset:(NSUInteger)offset extended:(NSUInteger)extended
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset),
                              @"extended": @(extended)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFaveGetPosts
                                                 options:options
                                                   error:nil];
}

- (id)postsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    return [self postsCount:count
                     offset:offset
                   extended:1];
}

- (id)postsCount:(NSUInteger)count
{
    return [self postsCount:count
                     offset:0];
}

#pragma mark - Video

- (id)videosCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count": @(count),
                              @"offset": @(offset)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKFaveGetVideos
                                                 options:options
                                                   error:nil];
}

- (id)videosCount:(NSUInteger)count
{
    return [self videosCount:count
                      offset:0];
}

#pragma mark - Links

- (id)links
{
    return [[VKConnector sharedInstance] performVKMethod:kVKFaveGetLinks
                                                 options:@{}
                                                   error:nil];
}

@end