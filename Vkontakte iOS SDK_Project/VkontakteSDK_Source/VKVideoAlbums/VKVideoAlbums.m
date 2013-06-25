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

#import "VKVideoAlbums.h"
#import "VKConnector.h"


@implementation VKVideoAlbums

#pragma mark Visible VKVideoAlbums methods
#pragma mark - video.get

- (id)getCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoGet
                                 options:options
                                   error:nil];
}

#pragma mark - video.edit

- (id)editCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoEdit
                                 options:options
                                   error:nil];
}

- (id)editVideoID:(NSUInteger)videoID
          newName:(NSString *)newName
   newDescription:(NSString *)newDescription
{
    NSDictionary *options = @{@"video_id" : @(videoID),
                              @"name"     : newName,
                              @"desc"     : newDescription};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoEdit
                    options:options
                      error:nil];
}

#pragma mark - video.add

- (id)addCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoAdd
                                 options:options
                                   error:nil];
}

#pragma mark - video.save

- (id)saveCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoSave
                                 options:options
                                   error:nil];
}

#pragma mark - video.delete

- (id)deleteCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoDelete
                                 options:options
                                   error:nil];
}

#pragma mark - video.restore

- (id)restoreCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoRestore
                                 options:options
                                   error:nil];
}

#pragma mark - video.search

- (id)searchCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoSearch
                                 options:options
                                   error:nil];
}

- (id)searchQuery:(NSString *)query
{
    NSDictionary *options = @{@"q": query};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoSearch
                    options:options
                      error:nil];
}

- (id)searchQuery:(NSString *)query
             sort:(NSUInteger)sort
            count:(NSUInteger)count
           offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"q"      : query,
                              @"sort"   : @(sort),
                              @"count"  : @(count),
                              @"offset" : @(offset)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoSearch
                    options:options
                      error:nil];
}

#pragma mark - video.getUserVideos

- (id)getUserVideosCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoGetUserVideos
                                 options:options
                                   error:nil];
}

- (id)getUserVideosCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count"  : @(count),
                              @"offset" : @(offset)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoGetUserVideos
                    options:options
                      error:nil];
}

#pragma mark - video.getAlbums

- (id)getAlbumsCustomtOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoGetAlbums
                                 options:options
                                   error:nil];
}

- (id)getAlbumsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count"  : @(count),
                              @"offset" : @(offset)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoGetAlbums
                    options:options
                      error:nil];
}

#pragma mark - video.addAlbum

- (id)addAlbumCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoAddAlbum
                                 options:options
                                   error:nil];
}

- (id)addAlbum:(NSString *)albumName
{
    NSDictionary *options = @{@"title": albumName};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoAddAlbum
                    options:options
                      error:nil];
}

#pragma mark - video.editAlbum

- (id)editAlbumCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoEditAlbum
                                 options:options
                                   error:nil];
}

- (id)editAlbumID:(NSUInteger)albumID newTitle:(NSString *)newTitle
{
    NSDictionary *options = @{@"album_id" : @(albumID),
                              @"title"    : newTitle};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoEditAlbum
                    options:options
                      error:nil];
}

#pragma mark - video.deleteAlbum

- (id)deleteAlbumCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoDeleteAlbum
                                 options:options
                                   error:nil];
}

- (id)deleteAlbumID:(NSUInteger)albumID
{
    NSDictionary *options = @{@"album_id": @(albumID)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoDeleteAlbum
                    options:options
                      error:nil];
}

#pragma mark - video.moveToAlbum

- (id)moveToAlbumCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoMoveToAlbum
                                 options:options
                                   error:nil];
}

#pragma mark - video.getComments

- (id)getCommentsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoGetComments
                                 options:options
                                   error:nil];
}

#pragma mark - video.createComment

- (id)createCommentCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoCreateComment
                                 options:options
                                   error:nil];
}

#pragma mark - video.deleteComment

- (id)deleteCommentCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoDeleteComment
                                 options:options
                                   error:nil];
}

- (id)deleteCommentID:(NSUInteger)commentID
{
    NSDictionary *options = @{@"comment_id": @(commentID)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoDeleteComment
                    options:options
                      error:nil];
}

#pragma mark - video.restoreComment

- (id)restoreCommentCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoRestoreComment
                                 options:options
                                   error:nil];
}

- (id)restoreCommentID:(NSUInteger)commentID
{
    NSDictionary *options = @{@"comment_id": @(commentID)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoRestoreComment
                    options:options
                      error:nil];
}

#pragma mark - video.editComment

- (id)editCommentCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoEditComment
                                 options:options
                                   error:nil];
}

#pragma mark - video.getTags

- (id)getTagsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoGetTags
                                 options:options
                                   error:nil];
}

- (id)getTagsVideoID:(NSUInteger)videoID ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"owner_id" : @(ownerID),
                              @"video_id" : @(videoID)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoGetTags
                    options:options
                      error:nil];
}

#pragma mark - video.putTag

- (id)putTagCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoPutTag
                                 options:options
                                   error:nil];
}

- (id)putTagName:(NSString *)tagName
         videoID:(NSUInteger)videoID
          userID:(NSUInteger)userID
         ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"tagged_name" : tagName,
                              @"video_id"    : @(videoID),
                              @"owner_id"    : @(ownerID),
                              @"user_id"     : @(userID)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoPutTag
                    options:options
                      error:nil];
}

#pragma mark - video.removeTag

- (id)removeTagCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoRemoveTag
                                 options:options
                                   error:nil];
}

- (id)removeTagID:(NSUInteger)tagID videoID:(NSUInteger)videoID
{
    NSDictionary *options = @{@"tag_id"   : @(tagID),
                              @"video_id" : @(videoID)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoRemoveTag
                    options:options
                      error:nil];
}

#pragma mark - video.getNewTags

- (id)getNewTagsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKVideoGetNewTags
                                 options:options
                                   error:nil];
}

- (id)getNewTagsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count"  : @(count),
                              @"offset" : @(offset)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKVideoGetNewTags
                    options:options
                      error:nil];
}

#pragma mark - Uploading video

- (id)uploadVideo:(NSData *)videoData name:(NSString *)videoFileName
{
    id uploadServer = [self saveCustomOptions:@{@"name": videoFileName}];
    NSURL *uploadURL = [NSURL URLWithString:uploadServer[@"response"][@"upload_url"]];

    id responseUpload = [[VKConnector sharedInstance]
                                      uploadFile:videoData
                                            name:videoFileName
                                             URL:uploadURL
                                     contentType:@"application/octet-stream"
                                       fieldName:@"video_file"];

    return responseUpload;
}

@end