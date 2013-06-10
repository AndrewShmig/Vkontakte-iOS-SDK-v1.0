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
#import "KGModal.h"


#define MARGIN_WIDTH 50.0f // ширина отступа от границ экрана


@implementation VKConnector
{
    NSString *_appID;
    NSString *_settings;
    NSString *_redirectURL;

    UIWebView *_innerWebView;
    UIActivityIndicatorView *_activityIndicator;
    
    VKAccessToken *_accessToken;

    void (^_cancelBlock) (void);
    void (^_acceptedBlock) (VKAccessToken *);
}

#pragma mark - Init methods

+ (id) sharedInstance
{
    static VKConnector *instanceVKConnector = nil;
    
	@synchronized(self) {
		if (instanceVKConnector == nil) {
			instanceVKConnector = [[self alloc] init];
		}
	}
    
	return instanceVKConnector;
}

#pragma mark - VKConnector public methods

- (void)startWithAppID:(NSString*)appID
            permissons:(NSArray*)permissions
{
	_permissions = permissions;
	_appID = appID;

    _settings = [_permissions componentsJoinedByString:@","];
    _redirectURL = @"https://oauth.vk.com/blank.html";
    
    // настраиваем попап окно для отображения UIWebView
    CGRect frame = [[UIScreen mainScreen] bounds];
    frame.size.height -= MARGIN_WIDTH;
    frame.size.width -= MARGIN_WIDTH;
    UIView *view = [[UIView alloc] initWithFrame:frame];
    
    if(nil == _innerWebView){
        _innerWebView = [[UIWebView alloc] initWithFrame:view.frame];
        [_innerWebView setDelegate:self];
    }
    
    CGPoint centerPoint = [_innerWebView center];
    CGRect activityIndicatorFrame = CGRectMake(centerPoint.x - 20, centerPoint.y - 50, 30, 30);
    
    if(nil == _activityIndicator){
        _activityIndicator = [[UIActivityIndicatorView alloc]
                              initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
        [_activityIndicator setColor:[UIColor darkGrayColor]];
        [_activityIndicator setFrame:activityIndicatorFrame];
        [_activityIndicator setHidesWhenStopped:YES];
        [_activityIndicator startAnimating];
    }

    [_innerWebView addSubview:_activityIndicator];
    [view addSubview:_innerWebView];
    
//    преобразование словаря параметров в строку параметров
    NSDictionary *params = @{@"client_id": _appID,
                             @"redirect_uri": _redirectURL,
                             @"scope": _settings,
                             @"response_type": @"token",
                             @"display": @"touch"};
    NSMutableString *urlAsString = [[NSMutableString alloc] init];
    NSMutableArray *urlParams = [[NSMutableArray alloc] init];
    
    [urlAsString appendString:@"https://oauth.vk.com/authorize?"];
    [params enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        [urlParams addObject:[NSString stringWithFormat:@"%@=%@", key, obj]];
    }];
    [urlAsString appendString:[urlParams componentsJoinedByString:@"&"]];

//    запрос на страницу авторизации приложения
    NSURL *url = [NSURL URLWithString:urlAsString];
    NSURLRequest *request = [NSURLRequest requestWithURL:url];
    [_innerWebView loadRequest:request];
    
//    отображаем попап
    [[KGModal sharedInstance] showWithContentView:view
                                      andAnimated:YES];
}

#pragma mark - WebView Delegate Methods

- (BOOL)           webView:(UIWebView *)webView
shouldStartLoadWithRequest:(NSURLRequest *)request
            navigationType:(UIWebViewNavigationType)navigationType
{
    NSString *url = [[request URL] absoluteString];

    if ([url hasPrefix:_redirectURL]) {
        NSString *query_string = [url substringFromIndex:[_redirectURL length] + 1];

//        проверяем одобрил ли пользователь наше приложение или нет
        if ([query_string hasPrefix:@"access_token"]) {
            NSArray *parts = [query_string componentsSeparatedByString:@"&"];

//            пользователь одобрил наше приложение, парсим полученные данные
            NSString *access_token = [parts[0] componentsSeparatedByString:@"="][1];
            NSTimeInterval expiration_time = [[parts[1] componentsSeparatedByString:@"="][1] doubleValue];
            NSUInteger user_id = [[parts[2] componentsSeparatedByString:@"="][1] unsignedIntValue];

            VKAccessToken *vkAccessToken = [[VKAccessToken alloc]
                    initWithUserID:user_id
                       accessToken:access_token
                    expirationTime:expiration_time
                       permissions:[_settings componentsSeparatedByString:@","]];

            NSLog(@"Access token: %@", vkAccessToken);
//            TODO: сохранение токена в общем списке токенов

        } else {
            
            NSLog(@"Пользователь отказался авторизовывать приложение");
//            TODO: вызов какого-то обратного блока

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
