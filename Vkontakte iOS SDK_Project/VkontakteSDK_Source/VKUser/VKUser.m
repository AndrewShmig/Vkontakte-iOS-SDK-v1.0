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
#import "VKMethods.h"
#import "VKAccessToken.h"


@implementation VKUser
{
    VKAccessToken *_accessToken;
    
    VKStatus *_status;
    VKWall *_wall;
    VKPhotoAlbums *_photoAlbums;
    VKAudioAlbums *_audioAlbums;
    VKVideoAlbums *_videoAlbums;
    VKFriends *_friends;
    VKGroups *_groups;
    VKNotes *_notes;
    VKPlaces *_places;
    VKMessages *_messages;
    VKNewsfeed *_newsfeed;
    VKLikes *_likes;
    VKDocs *_docs;
    VKFavourites *_favourites;
}

#pragma mark - Init methods

- (id)init
{
    self = [super init];
    
    if(nil != self){
        _accessToken = [[VKAccessToken alloc] init];
        
        if([_accessToken load])
            return self;
    }
    
    return nil;
}

#pragma mark - Singleton methods

+ (id)currentUser
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

- (VKStatus *)status
{
    if(nil == _status)
        _status = [[VKStatus alloc] init];
    
    return _status;
}

- (VKWall *)wall
{
    if(nil == _wall)
        _wall = [[VKWall alloc] init];
    
    return _wall;
}

- (VKPhotoAlbums *)photoAlbums
{
    if(nil == _photoAlbums)
        _photoAlbums = [[VKPhotoAlbums alloc] init];
    
    return _photoAlbums;
}

- (VKAudioAlbums *)audioAlbums
{
    if(nil == _audioAlbums)
        _audioAlbums = [[VKAudioAlbums alloc] init];
    
    return _audioAlbums;
}

- (VKVideoAlbums *)videoAlbums
{
    if(nil == _videoAlbums)
        _videoAlbums = [[VKVideoAlbums alloc] init];
    
    return _videoAlbums;
}

- (VKFriends *)friends
{
    if(nil == _friends)
        _friends = [[VKFriends alloc] init];
    
    return _friends;
}

- (VKGroups *)groups
{
    if(nil == _groups)
        _groups = [[VKGroups alloc] init];
    
    return _groups;
}

- (VKNotes *)notes
{
    if(nil == _notes)
        _notes = [[VKNotes alloc] init];
    
    return _notes;
}

- (VKPlaces *)places
{
    if(nil == _places)
        _places = [[VKPlaces alloc] init];
    
    return _places;
}

- (VKMessages *)messages
{
    if(nil == _messages)
        _messages = [[VKMessages alloc] init];
    
    return _messages;
}

- (VKNewsfeed *)newsfeed
{
    if(nil == _newsfeed)
        _newsfeed = [[VKNewsfeed alloc] init];
    
    return _newsfeed;
}

- (VKLikes *)likes
{
    if(nil == _likes)
        _likes = [[VKLikes alloc] init];
    
    return _likes;
}

- (VKDocs *)docs
{
    if(nil == _docs)
        _docs = [[VKDocs alloc] init];
    
    return _docs;
}

- (VKFavourites *)favourites
{
    if(nil == _favourites)
        _favourites = [[VKFavourites alloc] init];
    
    return _favourites;
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