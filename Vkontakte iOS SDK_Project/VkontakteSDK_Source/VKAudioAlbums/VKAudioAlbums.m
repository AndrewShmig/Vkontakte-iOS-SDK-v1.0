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
#import "VKAudioAlbums.h"
#import "VKConnector.h"


@implementation VKAudioAlbums

#pragma mark Visible VKAudioAlbums
#pragma mark - audio.get

- (id)getCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioGet
                                 options:options
                                   error:nil];
}

#pragma mark - audio.getById

- (id)getByIDCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioGetById
                                 options:options
                                   error:nil];
}

#pragma mark - audio.getLyrics

- (id)getLyricsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioGetLyrics
                                 options:options
                                   error:nil];
}

- (id)getLyricsID:(NSUInteger)lyricsID
{
    NSDictionary *options = @{@"lyrics_id": @(lyricsID)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioGetLyrics
                    options:options
                      error:nil];
}

#pragma mark - audio.search

- (id)searchCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioSearch
                                 options:options
                                   error:nil];
}

- (id)searchQuery:(NSString *)query
{
    NSDictionary *options = @{@"q": query};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioSearch
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
            performVKMethod:kVKAudioSearch
                    options:options
                      error:nil];
}

#pragma mark - audio.getUploadServer

- (id)getUploadServerCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioGetUploadServer
                                 options:options
                                   error:nil];
}

#pragma mark - audio.save

- (id)saveCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioSave
                                 options:options
                                   error:nil];
}

#pragma mark - audio.add

- (id)addCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioAdd
                                 options:options
                                   error:nil];
}

- (id)addAudioID:(NSUInteger)audioID ownerID:(NSUInteger)ownerID
{
    NSDictionary *options = @{@"aid" : @(audioID),
                              @"oid" : @(ownerID)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioAdd
                    options:options
                      error:nil];
}

#pragma mark - audio.delete

- (id)deleteCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioDelete
                                 options:options
                                   error:nil];
}

#pragma mark - audio.edit

- (id)editCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioEdit
                                 options:options
                                   error:nil];
}

- (id)editAudioID:(NSUInteger)audioID
          ownerID:(NSUInteger)ownerID
        newArtist:(NSString *)newArtist
         newTitle:(NSString *)newTitle
          newText:(NSString *)newText
{
    NSDictionary *options = @{@"aid"    : @(audioID),
                              @"oid"    : @(ownerID),
                              @"artist" : newArtist,
                              @"title"  : newTitle,
                              @"text"   : newText};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioEdit
                    options:options
                      error:nil];
}

#pragma mark - audio.reorder

- (id)reorderCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioReorder
                                 options:options
                                   error:nil];
}

#pragma mark - audio.restore

- (id)restoreCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioRestore
                                 options:options
                                   error:nil];
}

- (id)restoreAudioID:(NSUInteger)audioID
{
    NSDictionary *options = @{@"aid": @(audioID)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioRestore
                    options:options
                      error:nil];
}

#pragma mark - audio.getAlbums

- (id)getAlbumsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioGetAlbums
                                 options:options
                                   error:nil];
}

- (id)getAlbumsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count"  : @(count),
                              @"offset" : @(offset)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioGetAlbums
                    options:options
                      error:nil];
}

#pragma mark - audio.addAlbum

- (id)addAlbumCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioAddAlbum
                                 options:options
                                   error:nil];
}

- (id)addAlbumTitle:(NSString *)albumTitle
{
    NSDictionary *options = @{@"title": albumTitle};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioAddAlbum
                    options:options
                      error:nil];
}

#pragma mark - audio.editAlbum

- (id)editAlbumCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioEditAlbum
                                 options:options
                                   error:nil];
}

- (id)editAlbumID:(NSUInteger)albumID newTitle:(NSString *)newTitle
{
    NSDictionary *options = @{@"album_id" : @(albumID),
                              @"title"    : newTitle};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioEditAlbum
                    options:options
                      error:nil];
}

#pragma mark - audio.deleteAlbum

- (id)deleteAlbumCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioDeleteAlbum
                                 options:options
                                   error:nil];
}

- (id)deleteAlbumID:(NSUInteger)albumID
{
    NSDictionary *options = @{@"album_id": @(albumID)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioDeleteAlbum
                    options:options
                      error:nil];
}

#pragma mark - audio.moveToAlbum

- (id)moveToAlbumCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioMoveToAlbum
                                 options:options
                                   error:nil];
}

#pragma mark - audio.setBroadcast

- (id)setBroadcastCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioSetBroadcast
                                 options:options
                                   error:nil];
}

#pragma mark - audio.getBroadcastList

- (id)getBroadcastListCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioGetBroadcast
                                 options:options
                                   error:nil];
}

#pragma mark - audio.getRecommendations

- (id)getRecommendationsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioGetRecommendations
                                 options:options
                                   error:nil];
}

- (id)getRecommendationsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count"  : @(count),
                              @"offset" : @(offset)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioGetRecommendations
                    options:options
                      error:nil];
}

#pragma mark - audio.getPopular

- (id)getPopularCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioGetPopular
                                 options:options
                                   error:nil];
}

- (id)getPopularCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count"  : @(count),
                              @"offset" : @(offset)};

    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioGetPopular
                    options:options
                      error:nil];
}

#pragma mark - audio.getCount

- (id)getCountCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKAudioGetPopular
                                 options:options
                                   error:nil];
}

- (id)getCount
{
    return [[VKConnector sharedInstance]
            performVKMethod:kVKAudioGetCount
                    options:@{}
                      error:nil];
}

#pragma mark - Uploading audio

- (id)uploadAudio:(NSData *)audioData name:(NSString *)audioFileName
{
    id uploadServer = [self getUploadServerCustomOptions:@{}];
    NSURL *uploadURL = [NSURL URLWithString:uploadServer[@"response"][@"upload_url"]];

    id responseUpload = [[VKConnector sharedInstance]
            uploadFile:audioData
                  name:audioFileName
                   URL:uploadURL
           contentType:@"application/octet-stream"
             fieldName:@"file"];

    NSString *server = responseUpload[@"server"];
    NSString *audio = responseUpload[@"audio"];
    NSString *hash = responseUpload[@"hash"];

    id finalResponse = [self saveCustomOptions:@{
            @"server": server,
            @"audio": audio,
            @"hash": hash
    }];

    return  finalResponse;
}

@end