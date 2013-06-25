//
// Created by AndrewShmig on 5/28/13.
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
//
#import "VKDocs.h"
#import "VKConnector.h"
#import "VKUser.h"


@implementation VKDocs

#pragma mark Visible VKDocs methods
#pragma mark - docs.get

- (id)list
{
    return [[VKConnector sharedInstance] performVKMethod:kVKDocsGet
                                                 options:@{}
                                                   error:nil];
}

- (id)listCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count"  : @(count),
                              @"offset" : @(offset)};

    return [[VKConnector sharedInstance] performVKMethod:kVKDocsGet
                                                 options:options
                                                   error:nil];
}

#pragma mark - docs.getById

- (id)byIDs:(NSArray *)docsIDs
{
    NSDictionary *options = @{@"docs" : [docsIDs componentsJoinedByString:@","]};

    return [[VKConnector sharedInstance] performVKMethod:kVKDocsGetById
                                                 options:options
                                                   error:nil];
}

#pragma mark - docs.getUploadServer

- (id)uploadServer
{
    return [[VKConnector sharedInstance] performVKMethod:kVKDocsGetUploadServer
                                                 options:@{}
                                                   error:nil];
}

- (id)uploadServerGroupID:(NSUInteger)groupID
{
    NSDictionary *options = @{@"gid" : @(groupID)};

    return [[VKConnector sharedInstance] performVKMethod:kVKDocsGetUploadServer
                                                 options:options
                                                   error:nil];
}

#pragma mark - docs.getWallUploadServer

- (id)wallUploadServer
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKDocsGetWallUloadServer
                                 options:@{}
                                   error:nil];
}

- (id)wallUploadServerGroupID:(NSUInteger)groupID
{
    NSDictionary *options = @{};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKDocsGetWallUloadServer
                                 options:options
                                   error:nil];
}

#pragma mark - docs.save

- (id)save:(NSString *)file
{
    NSDictionary *options = @{@"file" : file};

    return [[VKConnector sharedInstance] performVKMethod:kVKDocsSave
                                                 options:options
                                                   error:nil];
}

#pragma mark - docs.delete

- (id)removeDocumentID:(NSUInteger)documentID
{
    NSUInteger currentUserID = [[VKUser currentUser] userID];

    NSDictionary *options = @{@"oid" : @(currentUserID),
                              @"did" : @(documentID)};

    return [[VKConnector sharedInstance] performVKMethod:kVKDocsDelete
                                                 options:options
                                                   error:nil];
}

#pragma mark - docs.add

- (id)addDocumentID:(NSUInteger)documentID ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"oid" : @(ownerID),
                              @"did" : @(documentID)};

    return [[VKConnector sharedInstance] performVKMethod:kVKDocsAdd
                                                 options:options
                                                   error:nil];
}

- (id)addDocumentID:(NSUInteger)documentID
            ownerID:(NSUInteger)ownerID
          accessKey:(NSString *)accessKey
{
    NSDictionary *options = @{@"oid"        : @(ownerID),
                              @"did"        : @(documentID),
                              @"access_key" : accessKey};

    return [[VKConnector sharedInstance] performVKMethod:kVKDocsAdd
                                                 options:options
                                                   error:nil];
}

#pragma mark - Uploading documents

- (id)uploadDocument:(NSData *)document name:(NSString *)documentName
{
    id uploadServer = [self uploadServer];
    NSURL *uploadURL = [NSURL URLWithString:uploadServer[@"response"][@"upload_url"]];

    id responseUpload = [[VKConnector sharedInstance]
                                      uploadFile:document
                                            name:documentName
                                             URL:uploadURL
                                     contentType:@"application/octet-stream"
                                       fieldName:@"file"];

    id finalResponse = [self save:responseUpload[@"file"]];

    return finalResponse;
}

@end