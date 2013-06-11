//
//  ASAAppDelegate.h
//  Vkontakte iOS SDK_Project
//
//  Created by AndrewShmig on 05/27/13.
//  Copyright (c) 2013 AndrewShmig. All rights reserved.
//

#import <UIKit/UIKit.h>

@class ASAViewController;
@protocol VKConnectorProtocol;


@interface ASAAppDelegate : UIResponder <UIApplicationDelegate, VKConnectorProtocol>

@property (strong, nonatomic) UIWindow *window;

@property (strong, nonatomic) ASAViewController *viewController;

@end