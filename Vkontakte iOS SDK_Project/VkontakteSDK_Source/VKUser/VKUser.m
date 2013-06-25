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

#import "VKConnector.h"
#import "VKUser.h"
#import "VKAccessToken.h"


@implementation VKUser
{
    VKAccessToken *_accessToken;
}

#pragma mark - Init methods

- (instancetype)init
{
    self = [super init];
    _accessToken = [[VKAccessToken alloc] init];

    if(nil != self && [_accessToken load]){
//        создаем связанные объекты
        _status = [[VKStatus alloc] init];
        _wall = [[VKWall alloc] init];
        _photoAlbums = [[VKPhotoAlbums alloc] init];
        _audioAlbums = [[VKAudioAlbums alloc] init];
        _videoAlbums = [[VKVideoAlbums alloc] init];
        _friends = [[VKFriends alloc] init];
        _groups = [[VKGroups alloc] init];
        _notes = [[VKNotes alloc] init];
        _places = [[VKPlaces alloc] init];
        _messages = [[VKMessages alloc] init];
        _newsfeed = [[VKNewsfeed alloc] init];
        _likes = [[VKLikes alloc] init];
        _docs = [[VKDocs alloc] init];
        _favourites = [[VKFavourites alloc] init];

        return self;
    }
    
    return nil;
}

#pragma mark - Singleton methods

+ (instancetype)currentUser
{
    static VKUser *me;
    static dispatch_once_t onceToken;
    
    dispatch_once(&onceToken, ^{
        me = [[[self class] alloc] init];
    });
    
    return me;
}

#pragma mark - Setters & Getters

- (NSUInteger)userID
{
    return _accessToken.userID;
}

- (NSArray *)userPermissions
{
    return _accessToken.permissions;
}
#pragma mark - Overriden methods

- (NSString *)description
{
    return [NSString stringWithFormat:@"%@", _accessToken];
}

#pragma mark - VKUser methods

- (id)infoAboutUserWithID:(NSUInteger)userID
                   fields:(NSArray *)fields
                 nameCase:(NSString *)nameCase
{
    NSDictionary *params = @{@"uids": @(userID),
                             @"fields": [fields componentsJoinedByString:@","],
                             @"name_case": nameCase};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKUsersGet
                                                 options:params
                                                   error:nil];
}

- (id)infoAboutUserWithID:(NSUInteger)userID fields:(NSArray *)fields
{
    return [self infoAboutUserWithID:self.userID
                              fields:fields
                            nameCase:@"nom"];
}

- (id)info
{
    return [self infoAboutUserWithID:self.userID
                              fields:[@"nickname,sex,bdate,city,country,photo_medium,online,last_seen,status" componentsSeparatedByString:@","]
                            nameCase:@"nom"];
}

- (id)searchUsersWithOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance] performVKMethod:kVKUsersSearch
                                                 options:options
                                                   error:nil];
}

- (id)isApplicationUserID:(NSUInteger)userID
{
    return [[VKConnector sharedInstance] performVKMethod:kVKUsersIsAppUser
                                                 options:@{@"uid": @(userID)}
                                                   error:nil];
}

- (id)subscriptionsOfUserWithID:(NSUInteger)userID count:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *params = @{@"uids": @(userID),
                             @"count": @(count),
                             @"offset": @(offset)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKUsersGetSubscriptions
                                                 options:params
                                                   error:nil];
}

- (id)subscriptionsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    return [self subscriptionsOfUserWithID:self.userID
                                     count:count
                                    offset:offset];
}

- (id)subscriptions
{
    NSDictionary *params = @{@"uids": @(self.userID)};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKUsersGetSubscriptions
                                                 options:params
                                                   error:nil];
}

- (id)followersOfUserWithID:(NSUInteger)userID count:(NSUInteger)count offset:(NSUInteger)offset fields:(NSArray *)fields
{
    NSDictionary *params = @{@"uid": @(userID),
                             @"offset": @(offset),
                             @"count": @(count),
                             @"fields": [fields componentsJoinedByString:@","]};
    
    return [[VKConnector sharedInstance] performVKMethod:kVKUsersGetFollowers
                                                 options:params
                                                   error:nil];
}

- (id)followersOfUserWithID:(NSUInteger)userID count:(NSUInteger)count offset:(NSUInteger)offset
{
    return [self followersOfUserWithID:userID
                                 count:count
                                offset:offset
                                fields:@[]];
}

- (id)followersCount:(NSUInteger)count offset:(NSUInteger)offset fields:(NSArray *)fields
{
    return [self followersOfUserWithID:self.userID
                                 count:count
                                offset:offset
                                fields:fields];
}

- (id)followersCount:(NSUInteger)count offset:(NSUInteger)offset
{
    return [self followersOfUserWithID:self.userID
                                 count:count
                                offset:offset
                                fields:@[]];
}

- (id)followers
{
    return [self followersOfUserWithID:self.userID
                                 count:100
                                offset:0
                                fields:@[@"nickname", @"screen_name", @"sex", @"bdate", @"photo_medium", @"online"]];
}

@end