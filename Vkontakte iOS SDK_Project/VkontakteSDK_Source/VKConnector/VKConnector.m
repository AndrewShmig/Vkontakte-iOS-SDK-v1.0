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
#import "NSString+encodeURL.h"
#import "KGModal.h"


#define MARGIN_WIDTH 25.0 // ширина отступа от границ экрана
#define MARGIN_HEIGHT 50.0 // высота отступа
#define DEFAULT_TIMEOUTINTERVAL 5 * 60.0 // 5 минут


@implementation VKConnector
{
    NSString *_settings;
    NSString *_redirectURL;

    UIWebView *_innerWebView;
    UIActivityIndicatorView *_activityIndicator;
    UIView *_mainView;

    VKAccessToken *_accessToken;
}

#pragma mark - Init methods

+ (instancetype)sharedInstance
{
    static VKConnector *instanceVKConnector = nil;

    @synchronized (self) {
        if (instanceVKConnector == nil) {
            instanceVKConnector = [[self alloc] init];
        }
    }

    return instanceVKConnector;
}

#pragma mark - VKConnector public methods

- (void)startWithAppID:(NSString *)appID
            permissons:(NSArray *)permissions
{
    _permissions = permissions;
    _appID = appID;

    _settings = [self.permissions componentsJoinedByString:@","];
    _redirectURL = @"https://oauth.vk.com/blank.html";

    if (nil == _mainView) {
        // настраиваем попап окно для отображения UIWebView
        CGRect frame = [[UIScreen mainScreen] bounds];
        frame.size.height -= MARGIN_HEIGHT;
        frame.size.width -= MARGIN_WIDTH;
        _mainView = [[UIView alloc] initWithFrame:frame];

        if (nil == _innerWebView) {
            _innerWebView = [[UIWebView alloc] initWithFrame:_mainView.frame];
            [_innerWebView setDelegate:self];
        }

        CGPoint centerPoint = [_innerWebView center];
        CGRect activityIndicatorFrame = CGRectMake(centerPoint.x - 20, centerPoint.y - 50, 30, 30);

        if (nil == _activityIndicator) {
            _activityIndicator = [[UIActivityIndicatorView alloc]
                                                           initWithActivityIndicatorStyle:UIActivityIndicatorViewStyleWhiteLarge];
            [_activityIndicator setColor:[UIColor darkGrayColor]];
            [_activityIndicator setFrame:activityIndicatorFrame];
            [_activityIndicator setHidesWhenStopped:YES];
            [_activityIndicator startAnimating];
        }

        [_innerWebView addSubview:_activityIndicator];
        [_mainView addSubview:_innerWebView];
    }

//    преобразование словаря параметров в строку параметров
    NSDictionary *params = @{@"client_id"     : self.appID,
                             @"redirect_uri"  : _redirectURL,
                             @"scope"         : _settings,
                             @"response_type" : @"token",
                             @"display"       : @"touch"};
    NSMutableString *urlAsString = [[NSMutableString alloc] init];
    NSMutableArray *urlParams = [[NSMutableArray alloc] init];

    [urlAsString appendString:@"https://oauth.vk.com/authorize?"];
    [params enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop)
    {
        [urlParams addObject:[NSString stringWithFormat:@"%@=%@", key, obj]];
    }];
    [urlAsString appendString:[urlParams componentsJoinedByString:@"&"]];

//    запрос на страницу авторизации приложения
    NSURL *url = [NSURL URLWithString:urlAsString];
    NSURLRequest *request = [NSURLRequest requestWithURL:url];

//    отображаем попап, если токен недействителен
    if (![_accessToken load] || ![_accessToken isValid]) {
        [_innerWebView loadRequest:request];

        if ([self.delegate respondsToSelector:@selector(VKConnector:willShowModalView:)])
            [self.delegate VKConnector:self
                     willShowModalView:[KGModal sharedInstance]];

        [[KGModal sharedInstance] showWithContentView:_mainView
                                          andAnimated:YES];
    }
}

- (void)logout
{
    NSArray *cookies = [[NSHTTPCookieStorage sharedHTTPCookieStorage] cookies];

    for (NSHTTPCookie *cookie in cookies) {
        if (NSNotFound != [cookie.domain rangeOfString:@"vk.com"].location) {
            [[NSHTTPCookieStorage sharedHTTPCookieStorage]
                                  deleteCookie:cookie];
        }
    }
}

- (id)performVKMethod:(NSString *)methodName
              options:(NSDictionary *)options
                error:(NSError **)error
{
    if (![_accessToken isValid]) {

        if ([self.delegate respondsToSelector:@selector(VKConnector:accessTokenInvalidated:)])
            [self.delegate VKConnector:self
                accessTokenInvalidated:_accessToken];

        return nil;
    }

//    формируем УРЛ на который буде отправлен запрос
    NSMutableString *fullRequestURL = [NSMutableString stringWithFormat:@"%@%@",
                                                                        kVkontakteAPIURL,
                                                                        methodName];

    [fullRequestURL appendString:@"?"];

    [options enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop)
    {
        [fullRequestURL appendFormat:@"%@=%@&",
                                     key,
                                     [[obj description] encodeURL]];
    }];

    [fullRequestURL appendFormat:@"access_token=%@", _accessToken.token];

    NSURL *url = [NSURL URLWithString:fullRequestURL];
    NSMutableURLRequest *urlRequest = [NSMutableURLRequest requestWithURL:url];

    return [self performVKRequest:urlRequest];
}

- (id)performVKRequest:(NSMutableURLRequest *)request
{
    //    отправка запроса
    NSHTTPURLResponse *httpResponse;
    NSError *requestError;
    NSData *response = [NSURLConnection sendSynchronousRequest:request
                                             returningResponse:&httpResponse
                                                         error:&requestError];

//    во время запроса произошла ошибка
    if (nil != requestError) {
        if ([self.delegate respondsToSelector:@selector(VKConnector:connectionErrorOccured:)])
            [self.delegate VKConnector:self
                connectionErrorOccured:requestError];

        return nil;
    }

    NSError *jsonParsingError;
    id jsonResponse = [NSJSONSerialization JSONObjectWithData:response
                                                      options:NSJSONReadingMutableContainers
                                                        error:&jsonParsingError];

//    ошибка парсинга ответа сервера
    if (nil != jsonParsingError) {
        if ([self.delegate respondsToSelector:@selector(VKConnector:parsingErrorOccured:)])
            [self.delegate VKConnector:self
                   parsingErrorOccured:jsonParsingError];

        return nil;
    }

//    результат
    return jsonResponse;
}

- (id)uploadFile:(NSData *)file
            name:(NSString *)fileName
             URL:(NSURL *)url
     contentType:(NSString *)contentType
       fieldName:(NSString *)fieldName
{
    // формируем запрос
    NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:url];
    NSString *boundary = [[NSProcessInfo processInfo] globallyUniqueString];
    NSMutableData *body = [NSMutableData data];

    [request setTimeoutInterval:DEFAULT_TIMEOUTINTERVAL];

    // тело
    [body appendData:[[NSString stringWithFormat:@"--%@\r\n", boundary]
                                dataUsingEncoding:NSUTF8StringEncoding]];
    [body appendData:[[NSString stringWithFormat:@"Content-Disposition: form-data; name=\"%@\"; filename=\"%@\"\r\n",
                                                 fieldName, fileName]
                                                 dataUsingEncoding:NSUTF8StringEncoding]];
    [body appendData:[[NSString stringWithFormat:@"Content-Type: %@\r\n\r\n",
                                                 contentType]
                                                 dataUsingEncoding:NSUTF8StringEncoding]];
    [body appendData:file];
    [body appendData:[[NSString stringWithFormat:@"\r\n--%@--\r\n", boundary]
                                dataUsingEncoding:NSUTF8StringEncoding]];

    [request setHTTPBody:body];

    // заголовки
    [request setHTTPMethod:@"POST"];

    [request setValue:[NSString stringWithFormat:@"multipart/form-data; boundary=\"%@\"",
                                                 boundary]
   forHTTPHeaderField:@"Content-Type"];

    [request setValue:[NSString stringWithFormat:@"%d", [body length]]
   forHTTPHeaderField:@"Content-Length"];

    // отправка запроса
    return [self performVKRequest:request];
}

#pragma mark - WebView delegate methods

- (BOOL)           webView:(UIWebView *)webView
shouldStartLoadWithRequest:(NSURLRequest *)request
            navigationType:(UIWebViewNavigationType)navigationType
{
    NSString *url = [[request URL] absoluteString];

    if ([url hasPrefix:_redirectURL]) {
        NSString *query_string = [url componentsSeparatedByString:@"#"][1];

//        проверяем одобрил ли пользователь наше приложение или нет
        if ([query_string hasPrefix:@"access_token"]) {
            NSArray *parts = [query_string componentsSeparatedByString:@"&"];

//            пользователь одобрил наше приложение, парсим полученные данные
            NSString *access_token = [parts[0] componentsSeparatedByString:@"="][1];
            NSTimeInterval expiration_time = [[parts[1] componentsSeparatedByString:@"="][1] doubleValue];
            NSUInteger user_id = [[parts[2] componentsSeparatedByString:@"="][1] unsignedIntValue];

            _accessToken = [[VKAccessToken alloc]
                                           initWithUserID:user_id
                                              accessToken:access_token
                                           expirationTime:expiration_time
                                              permissions:[_settings componentsSeparatedByString:@","]];

//            сохраняем токен доступа
            [_accessToken save];

//            уведомляем программиста, что токен был обновлён
            if ([self.delegate respondsToSelector:@selector(VKConnector:accessTokenRenewalSucceeded:)])
                [self.delegate VKConnector:self
               accessTokenRenewalSucceeded:_accessToken];

        } else {
//            пользователь отказался авторизовать приложение
//            не удалось обновить/получить токен доступа
            if ([self.delegate respondsToSelector:@selector(VKConnector:accessTokenRenewalFailed:)])
                [self.delegate VKConnector:self
                  accessTokenRenewalFailed:nil];
        }
    }

    if ([url hasPrefix:@"https://oauth.vk.com/blank.html"]) {
        if ([self.delegate respondsToSelector:@selector(VKConnector:willHideModalView:)])
            [self.delegate VKConnector:self
                     willHideModalView:[KGModal sharedInstance]];

        [[KGModal sharedInstance] hideAnimated:YES];
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
