//
//  VKConnector.h
//
//  Created by Andrew Shmig on 18.12.12.
//

#import <Foundation/Foundation.h>


extern NSString *const kVKAppID;
extern NSString *const kVKPrivateKey;
extern NSString *const kVKPermissionList;


@class VKAccessToken;


@interface VKConnector : NSObject <UIWebViewDelegate>

- (id)initWithWebView:(UIWebView *)webView;

- (void)startOnCancelBlock:(void (^)(void))cancelBlock
            onSuccessBlock:(void (^)(VKAccessToken *))acceptedBlock;

@end
