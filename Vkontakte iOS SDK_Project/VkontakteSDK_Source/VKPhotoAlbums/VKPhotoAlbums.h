//
// Created by AndrewShmig on 5/28/13.
//
// Copyright (c) AndrewShmig. All rights reserved.
//
#import <Foundation/Foundation.h>
#import "VKRequest.h"


@class VKAccessToken;

@interface VKPhotoAlbums : NSObject

- (id)initWithAccessToken:(VKAccessToken *)accessToken;

@end