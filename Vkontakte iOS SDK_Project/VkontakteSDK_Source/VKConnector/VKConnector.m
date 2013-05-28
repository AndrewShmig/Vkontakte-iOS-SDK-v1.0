//
//  VKConnector.m
//
//  Created by Andrew Shmig on 18.12.12.
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

#pragma mark - Init methods

- (id)initWithWebView:(UIWebView *)webView
{
    self = [super init];

    if (self) {
        _appID = kVKAppID;
        _settings = kVKPermissionList;
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

            NSLog(@"parts: %@", parts);

            // user accepted our app, parsing response data
            NSString *access_token = [parts[0] componentsSeparatedByString:@"="][1];
            NSTimeInterval expiration_time = [[parts[1] componentsSeparatedByString:@"="][1] doubleValue];
            NSUInteger user_id = [[parts[2] componentsSeparatedByString:@"="][1] unsignedIntValue];

            VKAccessToken *vkAccessToken = [[VKAccessToken alloc]
                    initWithUserID:user_id
                       accessToken:access_token
                    expirationTime:expiration_time
                       permissions:[kVKPermissionList componentsSeparatedByString:@","]];

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
