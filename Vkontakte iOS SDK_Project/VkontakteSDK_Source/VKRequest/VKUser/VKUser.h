//
// Created by AndrewShmig on 5/28/13.
//
// Copyright (c) AndrewShmig. All rights reserved.
//
#import <Foundation/Foundation.h>


typedef void (^VKCompletionBlock)(SEL selector, id response, NSError *error);


@class VKAccessToken;
@class VKStatus;
@class VKWall;
@class VKPhotoAlbums;
@class VKAudioAlbums;
@class VKVideoAlbums;
@class VKFriends;
@class VKGroups;
@class VKNotes;
@class VKPlaces;
@class VKMessages;
@class VKNewsfeed;
@class VKLikes;
@class VKDocs;
@class VKFavourites;


@interface VKUser : NSObject

@property (nonatomic, readwrite) VKAccessToken *token;

@property (nonatomic, copy, readwrite) VKCompletionBlock completionBlock;

@property (nonatomic, readonly) VKStatus *status;
@property (nonatomic, readonly) VKWall *wall;
@property (nonatomic, readonly) VKPhotoAlbums *photoAlbums;
@property (nonatomic, readonly) VKAudioAlbums *audioAlbums;
@property (nonatomic, readonly) VKVideoAlbums *videoAlbums;
@property (nonatomic, readonly) VKFriends *friends;
@property (nonatomic, readonly) VKGroups *groups;
@property (nonatomic, readonly) VKNotes *notes;
@property (nonatomic, readonly) VKPlaces *places;
@property (nonatomic, readonly) VKMessages *messages;
@property (nonatomic, readonly) VKNewsfeed *newsfeed;
@property (nonatomic, readonly) VKLikes *likes;
@property (nonatomic, readonly) VKDocs *docs;
@property (nonatomic, readonly) VKFavourites *favourites;


- (id)initWithVKAccessToken:(VKAccessToken *)accessToken;

- (void)info;
- (void)infoAboutUser:(VKUser *)user fields:(NSArray *)fields;
- (void)isApplicationUser;
- (void)subscriptionsCount:(NSUInteger)count offset:(NSUInteger)offset;
- (void)followersCount:(NSUInteger)count offset:(NSUInteger)offset fields:(NSArray *)fields nameCase:(NSString *)nameCase;

@end