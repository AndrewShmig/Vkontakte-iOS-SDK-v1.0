//
// Created by AndrewShmig on 5/28/13.
//
// Copyright (c) AndrewShmig. All rights reserved.
//
#import "VKPlaces.h"
#import "VKAccessToken.h"

@implementation VKPlaces
{
    VKAccessToken *_token;
}

#pragma mark - Init methods

- (id)initWithAccessToken:(VKAccessToken *)accessToken
{
    self = [super init];
    
    if(self){
        _token = accessToken;
    }
    
    return self;
}
@end