//
//  VKConnector.m
//
//  Created by Andrew Shmig on 18.12.12.
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

#import "VKConnector.h"
#import "VKAccessToken.h"


@implementation VKConnector
{
    const NSString *_appID;
    const NSString *_settings;
    NSString *_redirectURL;
    NSString *_display;

    UIWebView *_innerWebView;
    UIActivityIndicatorView *_activityIndicator;

    void (^_cancelBlock) (void);
    void (^_acceptedBlock) (VKAccessToken *);
}

static VKConnector *instanceVKConnector = nil;


#pragma mark - Init methods

+ (id) sharedInstance {
	@synchronized(self) {
		if (instanceVKConnector == nil) {
			instanceVKConnector = [[self alloc] init]; //Пустая инициализация
		}
	}
	return instanceVKConnector;
}

- (void)startWithAppID:(NSString*)appID permissons:(NSArray*)permissions {
	_permissions = permissions;
	_appID = appID;

	if (self.parentView) {
		// Код расположения всплывающего окна в parent view
	} else {
		// Код вызова модального окна
	}
}

- (id)initWithWebView:(UIWebView *)webView
                appID:(NSString *)appID
          permissions:(NSArray *)permissions
{
    self = [super init];

    if (self) {
        _appID = [appID copy];
        
        NSMutableString *settingAsString = [[NSMutableString alloc] init];
        for(NSString *permission in permissions){
            [settingAsString appendFormat:@",%@", permission];
        }
        [settingAsString deleteCharactersInRange:NSMakeRange(0, 1)];
        
        _settings = settingAsString;
        _redirectURL = @"https://oauth.vk.com/blank.html";
        _display = @"touch";

        _innerWebView = webView;
        [_innerWebView setDelegate:self];

        CGPoint centerPoint = [_innerWebView center];
        CGRect frame = CGRectMake(centerPoint.x - 20, centerPoint.y - 50, 30, 30);
        _activityIndicator = [[UIActivityIndicatorView alloc]
                                                        initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
        [_activityIndicator setColor:[UIColor darkGrayColor]];
        [_activityIndicator setFrame:frame];
        [_activityIndicator setHidesWhenStopped:YES];
        [_activityIndicator setHidden:NO];

        [_innerWebView addSubview:_activityIndicator];
    }

    return self;
}

#pragma mark - Public VKConnector Methods

- (void)setParentView:(UIView *)parentView {
	_parentView = parentView;
	
}

- (void)startOnCancelBlock:(void (^)(void))cancelBlock
            onSuccessBlock:(void (^)(VKAccessToken *))acceptedBlock
{
    _cancelBlock = cancelBlock;
    _acceptedBlock = acceptedBlock;

    NSURL *url = [NSURL URLWithString:[NSString stringWithFormat:@"https://oauth.vk.com/authorize?client_id=%@&redirect_uri=%@&scope=%@&response_type=token&display=%@",
                                                                 _appID,
                                                                 _redirectURL,
                                                                 _settings,
                                                                 _display]];

    NSURLRequest *request = [NSURLRequest requestWithURL:url];
    [_innerWebView loadRequest:request];
}

#pragma mark - WebView Delegate Methods

- (BOOL)           webView:(UIWebView *)webView
shouldStartLoadWithRequest:(NSURLRequest *)request
            navigationType:(UIWebViewNavigationType)navigationType
{
    NSString *url = [[request URL] absoluteString];

    // checking URL we are currently parsing
    if ([url hasPrefix:_redirectURL]) {
        NSString *query_string = [url substringFromIndex:[_redirectURL length] + 1];

        // checking if user accepted application or not
        if ([query_string hasPrefix:@"access_token"]) {
            NSArray *parts = [query_string componentsSeparatedByString:@"&"];

            // user accepted our app, parsing response data
            NSString *access_token = [parts[0] componentsSeparatedByString:@"="][1];
            NSTimeInterval expiration_time = [[parts[1] componentsSeparatedByString:@"="][1] doubleValue];
            NSUInteger user_id = [[parts[2] componentsSeparatedByString:@"="][1] unsignedIntValue];

            VKAccessToken *vkAccessToken = [[VKAccessToken alloc]
                    initWithUserID:user_id
                       accessToken:access_token
                    expirationTime:expiration_time
                       permissions:[_settings componentsSeparatedByString:@","]];

            _acceptedBlock(vkAccessToken);

        } else {
            // user denied to authorize our app
            _cancelBlock();

        }
    }

    return YES;
}

- (void)webViewDidFinishLoad:(UIWebView *)webView
{
    [_activityIndicator stopAnimating];
}

- (void)webViewDidStartLoad:(UIWebView *)webView
{
    [_activityIndicator startAnimating];
}

@end
