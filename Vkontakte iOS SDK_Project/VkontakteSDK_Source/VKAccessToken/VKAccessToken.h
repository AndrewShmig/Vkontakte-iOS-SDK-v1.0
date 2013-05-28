//
// Created by AndrewShmig on 5/28/13.
//
// Copyright (c) AndrewShmig. All rights reserved.
//
#import <Foundation/Foundation.h>


@interface VKAccessToken : NSObject


@property (nonatomic, readonly) NSArray *permissions;
@property (nonatomic, readonly) NSTimeInterval expirationTime;
@property (nonatomic, readonly) NSUInteger userID;
@property (nonatomic, readonly) NSString *token;


- (id)initWithUserID:(NSUInteger)userID
         accessToken:(NSString *)token
      expirationTime:(NSTimeInterval)expirationTime
         permissions:(NSArray *)permissions;

- (id)initWithUserID:(NSUInteger)userID
         accessToken:(NSString *)token
      expirationTime:(NSTimeInterval)expirationTime;

- (id)initWithUserID:(NSUInteger)userID
         accessToken:(NSString *)token;


- (NSString *)description;

- (BOOL)hasPermission:(NSString *)permission;
- (BOOL)isExpired;



@end