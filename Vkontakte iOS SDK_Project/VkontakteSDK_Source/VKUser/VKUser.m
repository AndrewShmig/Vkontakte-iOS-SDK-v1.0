//
// Created by AndrewShmig on 5/28/13.
//
// Copyright (c) AndrewShmig. All rights reserved.
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


@implementation VKUser
{
    VKAccessToken *_token;
    
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
    }
    
    return self;
}

#pragma mark - Setters & Getters

- (void)setToken:(VKAccessToken *)token
{
    _token = token;
    
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
    // TODO
}

- (void)infoAboutUser:(VKUser *)user
               fields:(NSArray *)fields
{
    // TODO
}

- (void)isApplicationUser
{
    // TODO
}

- (void)subscriptionsCount:(NSUInteger)count
                    offset:(NSUInteger)offset
{
    // TODO
}

- (void)followersCount:(NSUInteger)count
                offset:(NSUInteger)offset
                fields:(NSArray *)fields
              nameCase:(NSString *)nameCase
{
    // TODO
}

@end