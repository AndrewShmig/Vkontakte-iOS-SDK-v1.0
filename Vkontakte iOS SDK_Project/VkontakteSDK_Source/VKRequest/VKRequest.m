//
//  VKRequest.m
//  Vkontakte iOS SDK_Project
//
//  Created by AndrewShmig on 6/8/13.
//  Copyright (c) 2013 AndrewShmig. All rights reserved.
//

#import "VKRequest.h"
#import "NSString+encodeURL.h"
#import "VKAccessToken.h"


@implementation VKRequest
{
    VKAccessToken *_accessToken;
}

#pragma mark - Synthesize

@synthesize accessToken = _accessToken;

#pragma mark - Init methods

- (id)initWithAccessToken:(VKAccessToken *)accessToken
{
    if(self = [super init]){
        _accessToken = accessToken;
    }
    
    return self;
}

#pragma mark - Request methods

- (id)performVKMethod:(NSString *)methodName
              options:(NSDictionary *)options
                error:(NSError **)error
{
    // appending params to URL
    NSMutableString *fullRequestURL = [NSMutableString stringWithFormat:@"%@%@",
                                       kVkontakteAPIURL, methodName];
    
    [fullRequestURL appendString:@"?"];
    
    [options enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop)
     {
         [fullRequestURL appendFormat:@"%@=%@&", key, [[obj description] encodeURL]];
     }];
    
    if(nil != _accessToken && 0 != _accessToken.token.length)
        [fullRequestURL appendFormat:@"access_token=%@", _accessToken.token];
    
    // performing HTTP GET request to vkURLMethodSignature URL
    NSURL *url = [NSURL URLWithString:fullRequestURL];
    NSURLRequest *urlRequest = [NSURLRequest requestWithURL:url];
    
    NSHTTPURLResponse *httpResponse;
    NSError *requestError;
    NSData *response = [NSURLConnection sendSynchronousRequest:urlRequest
                                             returningResponse:&httpResponse
                                                         error:&requestError];
    
    // error performing request
    if(nil != requestError){
        *error = requestError;
        
        return nil;
    }
    
    NSError *jsonParsingError;
    id jsonResponse = [NSJSONSerialization JSONObjectWithData:response
                                                      options:NSJSONReadingMutableContainers
                                                        error:&jsonParsingError];
    
    // error parsing JSON response
    if(nil != jsonParsingError){
        *error = jsonParsingError;
        
        return nil;
    }
    
    // final response
    *error = nil;
    return jsonResponse;
}

@end
