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
#import "VKUser.h"
#import "VKStatus.h"
#import "VKWall.h"
#import "VKPhotoAlbums.h"
#import "VKAudioAlbums.h"
#import "VKVideoAlbums.h"
#import "VKFriends.h"
#import "VKGroups.h"
#import "VKNotes.h"
#import "VKPlaces.h"
#import "VKMessages.h"
#import "VKNewsfeed.h"
#import "VKLikes.h"
#import "VKDocs.h"
#import "VKFavourites.h"
#import "VKRequest.h"
#import "VKMethods.h"
#import "VKAccessToken.h"


@implementation VKUser
{
    VKAccessToken *_token;
    
    VKRequest *_request;
    
    VKCompletionBlock _completionBlock;
    
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

- (id)initWithVKAccessToken:(VKAccessToken *)accessToken
{
    self = [super init];
    
    if(self){
        _token = accessToken;
        _request = [[VKRequest alloc] initWithAccessToken:_token];
    }
    
    return self;
}

#pragma mark - Setters & Getters

- (void)setToken:(VKAccessToken *)token
{
    _token = token;
    
    _request = [[VKRequest alloc] initWithAccessToken:_token];
    
    _status = [[VKStatus alloc] initWithAccessToken:_token];
    _wall = [[VKWall alloc] initWithAccessToken:_token];
    _photoAlbums = [[VKPhotoAlbums alloc] initWithAccessToken:_token];
    _audioAlbums = [[VKAudioAlbums alloc] initWithAccessToken:_token];
    _videoAlbums = [[VKVideoAlbums alloc] initWithAccessToken:_token];
    _friends = [[VKFriends alloc] initWithAccessToken:_token];
    _groups = [[VKGroups alloc] initWithAccessToken:_token];
    _notes = [[VKNotes alloc] initWithAccessToken:_token];
    _places = [[VKPlaces alloc] initWithAccessToken:_token];
    _messages = [[VKMessages alloc] initWithAccessToken:_token];
    _newsfeed = [[VKNewsfeed alloc] initWithAccessToken:_token];
    _likes = [[VKLikes alloc] initWithAccessToken:_token];
    _docs = [[VKDocs alloc] initWithAccessToken:_token];
    _favourites = [[VKFavourites alloc] initWithAccessToken:_token];
}

- (VKStatus *)status
{
    if(nil == _status)
        _status = [[VKStatus alloc] initWithAccessToken:_token];
    
    return _status;
}

- (VKWall *)wall
{
    if(nil == _wall)
        _wall = [[VKWall alloc] initWithAccessToken:_token];

    return _wall;
}

- (VKPhotoAlbums *)photoAlbums
{
    if(nil == _photoAlbums)
        _photoAlbums = [[VKPhotoAlbums alloc] initWithAccessToken:_token];
    
    return _photoAlbums;
}

- (VKAudioAlbums *)audioAlbums
{
    if(nil == _audioAlbums)
        _audioAlbums = [[VKAudioAlbums alloc] initWithAccessToken:_token];
    
    return _audioAlbums;
}

- (VKVideoAlbums *)videoAlbums
{
    if(nil == _videoAlbums)
        _videoAlbums = [[VKVideoAlbums alloc] initWithAccessToken:_token];
    
    return _videoAlbums;
}

- (VKFriends *)friends
{
    if(nil == _friends)
        _friends = [[VKFriends alloc] initWithAccessToken:_token];
    return _friends;
}

- (VKGroups *)groups
{
    if(nil == _groups)
        _groups = [[VKGroups alloc] initWithAccessToken:_token];
    
    return _groups;
}

- (VKNotes *)notes
{
    if(nil == _notes)
        _notes = [[VKNotes alloc] initWithAccessToken:_token];
    
    return _notes;
}

- (VKPlaces *)places
{
    if(nil == _places)
        _places = [[VKPlaces alloc] initWithAccessToken:_token];
    
    return _places;
}

- (VKMessages *)messages
{
    if(nil == _places)
        _messages = [[VKMessages alloc] initWithAccessToken:_token];
    
    return _messages;
}

- (VKNewsfeed *)newsfeed
{
    if(nil == _newsfeed)
        _newsfeed = [[VKNewsfeed alloc] initWithAccessToken:_token];
    
    return _newsfeed;
}

- (VKLikes *)likes
{
    if(nil == _likes)
        _likes = [[VKLikes alloc] initWithAccessToken:_token];
    
    return _likes;
}

- (VKDocs *)docs
{
    if(nil == _docs)
        _docs = [[VKDocs alloc] initWithAccessToken:_token];
    
    return _docs;
}

- (VKFavourites *)favourites
{
    if(nil == _favourites)
        _favourites = [[VKFavourites alloc] initWithAccessToken:_token];
    
    return _favourites;
}

#pragma mark - Public methods

- (void)info
{
    [self infoAboutUser:self
                 fields:@[@"nickname", @"screen_name", @"sex", @"bdate",
                          @"city", @"photo", @"online", @"last_seen", @"status"]];
}

- (void)infoAboutUser:(VKUser *)user
               fields:(NSArray *)fields
{
    NSError *error;
    id serverResponse = [_request performVKMethod:kVKUsersGet
                                          options:@{@"uids":  @(user.token.userID),
                                                    @"fields": [fields componentsJoinedByString:@","]}
                                            error:&error];
    
    _completionBlock(_cmd, serverResponse, error);
}

- (void)isApplicationUser
{
    NSError *error;
    id serverResponse = [_request performVKMethod:kVKUsersIsAppUser
                                          options:@{@"uid": @(self.token.userID)}
                                            error:&error];
    
    _completionBlock(_cmd, serverResponse, error);
}

- (void)subscriptionsCount:(NSUInteger)count
                    offset:(NSUInteger)offset
{
    NSError *error;
    id serverResponse = [_request performVKMethod:kVKUsersGetSubscriptions
                                          options:@{@"uid": @(self.token.userID),
                                                    @"count": @(count),
                                                    @"offset": @(offset)}
                                            error:&error];
    
    _completionBlock(_cmd, serverResponse, error);
}

- (void)followersCount:(NSUInteger)count
                offset:(NSUInteger)offset
                fields:(NSArray *)fields
              nameCase:(NSString *)nameCase
{
    NSError *error;
    id serverResponse = [_request performVKMethod:kVKUsersGetFollowers
                                          options:@{@"uid": @(self.token.userID),
                                                    @"count": @(count),
                                                    @"offset": @(offset),
                                                    @"name_case": nameCase,
                                                    @"fields": [fields componentsJoinedByString:@","]}
                                            error:&error];
    
    _completionBlock(_cmd, serverResponse, error);
}

@end