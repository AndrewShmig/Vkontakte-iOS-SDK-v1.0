//
// Created by AndrewShmig on 5/28/13.
//
// Copyright (c) AndrewShmig. All rights reserved.
//
#import "VKAccessToken.h"


@implementation VKAccessToken
{
    NSArray *_permissions;
    NSTimeInterval _expirationTime;
    NSUInteger _userID;
    NSString *_token;
}


@synthesize permissions = _permissions;
@synthesize expirationTime = _expirationTime;
@synthesize userID = _userID;
@synthesize token = _token;


#pragma mark - Init methods

- (id)initWithUserID:(NSUInteger)userID
         accessToken:(NSString *)token
      expirationTime:(NSTimeInterval)expirationTime
         permissions:(NSArray *)permissions
{
    if(self = [super init]){
        _permissions = [permissions copy];
        _expirationTime = expirationTime;
        _userID = userID;
        _token = [token copy];
    }

    return self;
}

- (id)initWithUserID:(NSUInteger)userID
         accessToken:(NSString *)token
      expirationTime:(NSTimeInterval)expirationTime
{
    return [self initWithUserID:userID
                    accessToken:token
                 expirationTime:expirationTime
                    permissions:@[]];
}

- (id)initWithUserID:(NSUInteger)userID accessToken:(NSString *)token
{
    return [self initWithUserID:userID
                    accessToken:token
                 expirationTime:0
                    permissions:@[]];
}

#pragma mark - Overriden methods

- (NSString *)description
{
    NSDictionary *desc = @{
            @"User ID": @(self.userID),
            @"Expiration time": @(self.expirationTime),
            @"Permissions": self.permissions,
            @"Token": self.token
    };

    return [desc description];
}

#pragma mark - Public methods

- (BOOL)hasPermission:(NSString *)permission
{
    return [_permissions containsObject:permission];
}

- (BOOL)isExpired
{
    NSTimeInterval currentTimestamp = [[NSDate date] timeIntervalSince1970];

    if(_expirationTime == 0 && [self hasPermission:@"offline"])
        return NO;
    else
        return (_expirationTime < currentTimestamp);

}

@end