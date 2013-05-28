//
//  ASAViewController.m
//  Vkontakte iOS SDK_Project
//
//  Created by AndrewShmig on 05/27/13.
//  Copyright (c) 2013 AndrewShmig. All rights reserved.
//

#import "ASAViewController.h"
#import "VKConnector.h"


NSString *const kVKAppID = @"3541027";
NSString *const kVKPrivateKey = @"EImkkJQ8jF7obXFVSHIZ";
NSString *const kVKPermissionList = @"friends,status,wall,messages,offline,photos,docs,audio";


@implementation ASAViewController
{
    VKConnector *_vk;
    UIWebView *_webView;
}

- (void)viewDidLoad
{
    [super viewDidLoad];

	// Do any additional setup after loading the view, typically from a nib.
    CGRect frame = [[UIScreen mainScreen] bounds];
    _webView = [[UIWebView alloc] initWithFrame:frame];
    [self.view addSubview:_webView];

    _vk = [[VKConnector alloc] initWithWebView:_webView];


    [_vk startOnCancelBlock:^
    {
        NSLog(@"Canceled...");
    }
             onSuccessBlock:^(VKAccessToken *token)
             {
                 NSLog(@"accessToken: %@", token);
             }];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end