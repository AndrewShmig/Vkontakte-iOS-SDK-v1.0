//
//  ASAAppDelegate.m
//  Vkontakte iOS SDK_Project
//
//  Created by AndrewShmig on 05/27/13.
//  Copyright (c) 2013 AndrewShmig. All rights reserved.
//

#import "ASAAppDelegate.h"
#import "ASAViewController.h"
#import "VKUser.h"


static NSString *const kVKAppID = @"3541027";
static NSString *const kVKPermissionsArray = @"friends,status,wall,messages,offline,photos,docs,audio";


@implementation ASAAppDelegate

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
    self.window = [[UIWindow alloc] initWithFrame:[[UIScreen mainScreen] bounds]];
    
    [[VKConnector sharedInstance] startWithAppID:kVKAppID
                                      permissons:[kVKPermissionsArray componentsSeparatedByString:@","]];
    [[VKConnector sharedInstance] setDelegate:self];

    // Override point for customization after application launch.
    self.viewController = [[ASAViewController alloc] initWithNibName:@"ASAViewController" bundle:nil];
    self.window.rootViewController = self.viewController;
    [self.window makeKeyAndVisible];
    return YES;
}

- (void)VKConnector:(VKConnector *)connector accessTokenInvalidated:(VKAccessToken *)accessToken
{
    NSLog(@"%s", __FUNCTION__);
    NSLog(@"%@", accessToken);
}

- (void)VKConnector:(VKConnector *)connector accessTokenRenewalFailed:(VKAccessToken *)accessToken
{
    NSLog(@"%s", __FUNCTION__);
}

- (void)VKConnector:(VKConnector *)connector accessTokenRenewalSucceeded:(VKAccessToken *)accessToken
{
    NSLog(@"%s", __FUNCTION__);
    NSLog(@"%@", accessToken);
    
    NSLog(@"User info: %@", [[VKUser currentUser] followers]);
}

@end