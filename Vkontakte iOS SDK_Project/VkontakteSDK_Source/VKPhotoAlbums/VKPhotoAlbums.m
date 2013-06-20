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

#import "VKPhotoAlbums.h"
#import "VKConnector.h"

@implementation VKPhotoAlbums

#pragma mark Visible VKPhotoAlbums methods
#pragma mark - photos.createAlbum

- (id)createTitle:(NSString *)title description:(NSString *)description
{
    NSDictionary *options = @{@"title"       : title,
                              @"description" : description};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosCreateAlbum
                                 options:options
                                   error:nil];
}

- (id)createTitle:(NSString *)title
      description:(NSString *)description
   commentPrivacy:(NSUInteger)commentPrivacy
          privacy:(NSUInteger)privacy
{
    NSDictionary *options = @{@"title"           : title,
                              @"description"     : description,
                              @"comment_privacy" : @(commentPrivacy),
                              @"privacy"         : @(privacy)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosCreateAlbum
                                 options:options
                                   error:nil];
}

- (id)createCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosCreateAlbum
                                 options:options
                                   error:nil];
}

#pragma mark - photos.editAlbum

- (id)editAlbumID:(NSUInteger)albumID
            title:(NSString *)title
      description:(NSString *)description
{
    NSDictionary *options = @{@"aid"         : @(albumID),
                              @"title"       : title,
                              @"description" : description};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosEditAlbum
                                 options:options
                                   error:nil];
}

- (id)editAlbumID:(NSUInteger)albumID
            title:(NSString *)title
      description:(NSString *)description
   commentPrivacy:(NSUInteger)commentPrivacy
          privacy:(NSUInteger)privacy
{
    NSDictionary *options = @{@"aid"            : @(albumID),
                              @"title"          : title,
                              @"description"    : description,
                              @"commentPrivacy" : @(commentPrivacy),
                              @"privacy"        : @(privacy)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosEditAlbum
                                 options:options
                                   error:nil];
}

- (id)editCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosEditAlbum
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getAlbums

- (id)listCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetAlbums
                                 options:options
                                   error:nil];
}

#pragma mark - photos.get

- (id)listPhotosCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGet
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getAlbumsCount

- (id)count
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetAlbumsCount
                                 options:@{}
                                   error:nil];
}

#pragma mark - photos.getProfile

- (id)profileCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetProfile
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getById

- (id)photosByIDs:(NSArray *)photosIDs
{
    NSDictionary *options = @{@"photos" : [photosIDs componentsJoinedByString:@","]};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetById
                                 options:options
                                   error:nil];
}

- (id)photosByIDsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetById
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getUploadServer

- (id)uploadServer
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetUploadServer
                                 options:@{}
                                   error:nil];
}

- (id)uploadServerCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetUploadServer
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getProfileUploadServer

- (id)profileUploadServer
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetProfileUploadServer
                                 options:@{}
                                   error:nil];
}

#pragma mark - photos.saveProfilePhoto

- (id)saveProfilePhotoCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosSaveProfilePhoto
                                 options:options
                                   error:nil];
}

- (id)saveProfilePhoto:(NSString *)photo
                server:(NSString *)server
                  hash:(NSString *)hash
{
    NSDictionary *options = @{@"server" : server,
                              @"hash"   : hash,
                              @"photo"  : photo};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosSaveProfilePhoto
                                 options:options
                                   error:nil];
}

#pragma mark - photos.saveWallPhoto

- (id)saveWallPhotoCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosSaveWallPhoto
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getWallUploadServer

- (id)wallUploadServer
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetWallUploadServer
                                 options:@{}
                                   error:nil];
}

- (id)wallUploadServerCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetWallUploadServer
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getMessagesUploadServer

- (id)messagesUploadServer
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetMessageUploadServer
                                 options:@{}
                                   error:nil];
}

- (id)messagesUploadServerCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetMessageUploadServer
                                 options:options
                                   error:nil];
}

#pragma mark - photos.saveMessagesPhoto

- (id)saveMessagesPhotoCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosSaveMessagePhoto
                                 options:options
                                   error:nil];
}

#pragma mark - photos.search

- (id)searchQuery:(NSString *)searchQuery
         latitude:(CGFloat)latitude
        longitude:(CGFloat)longitude
{
    NSDictionary *options = @{@"q"    : searchQuery,
                              @"lat"  : @(latitude),
                              @"long" : @(longitude)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosSearch
                                 options:options
                                   error:nil];
}

- (id)searchQuery:(NSString *)searchQuery
{
    NSDictionary *options = @{@"q" : searchQuery};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosSearch
                                 options:options
                                   error:nil];
}

#pragma mark - photos.save

- (id)savePhotoCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosSave
                                 options:options
                                   error:nil];
}

#pragma mark - photos.edit

- (id)editPhotoCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosEdit
                                 options:options
                                   error:nil];
}

- (id)editPhotoID:(NSUInteger)photoID
          ownerID:(NSUInteger)ownerID
          caption:(NSString *)caption
{
    NSDictionary *options = @{@"pid"     : @(photoID),
                              @"oid"     : @(ownerID),
                              @"caption" : caption};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosEdit
                                 options:options
                                   error:nil];
}

#pragma mark - photos.move

- (id)movePhotoCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosMove
                                 options:options
                                   error:nil];
}

- (id)movePhotoID:(NSUInteger)photoID toAlbumID:(NSUInteger)albumID
{
    NSDictionary *options = @{@"pid"        : @(photoID),
                              @"target_aid" : @(albumID)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosMove
                                 options:options
                                   error:nil];
}

#pragma mark - photos.makeCover

- (id)makeCoverCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosMakeCover
                                 options:options
                                   error:nil];
}

- (id)makeCoverPhotoID:(NSUInteger)photoID albumID:(NSUInteger)albumID
{
    NSDictionary *options = @{@"pid" : @(photoID),
                              @"aid" : @(albumID)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosMakeCover
                                 options:options
                                   error:nil];
}

#pragma mark - photos.reorderAlbums

- (id)reorderCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosReorderAlbums
                                 options:options
                                   error:nil];
}

#pragma mark - photos.reorderPhotos

- (id)reorderPhotosCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosReorderPhotos
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getAll

- (id)allPhotosCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetAll
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getUserPhotos

- (id)taggedPhotosCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetUserPhotos
                                 options:options
                                   error:nil];
}

#pragma mark - photos.deleteAlbum

- (id)removeAlbumID:(NSUInteger)albumID
{
    NSDictionary *options = @{@"aid" : @(albumID)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosDeleteAlbum
                                 options:options
                                   error:nil];
}

#pragma mark - photos.delete

- (id)removePhotoID:(NSUInteger)photoID
{
    NSDictionary *options = @{@"pid" : @(photoID)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosDelete
                                 options:options
                                   error:nil];
}

#pragma mark - photos.confirmTag

- (id)confirmTagID:(NSUInteger)tagID photoID:(NSUInteger)photoID
{
    NSDictionary *options = @{@"pid"    : @(photoID),
                              @"tag_id" : @(tagID)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosConfirmTag
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getComments

- (id)photoCommentsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetComments
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getAllComments

- (id)allCommentsCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetAllComments
                                 options:options
                                   error:nil];
}

#pragma mark - photos.createComment

- (id)addCommentCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosCreateComment
                                 options:options
                                   error:nil];
}

#pragma mark - photos.deleteComment

- (id)removeCommentID:(NSUInteger)commentID
{
    NSDictionary *options = @{@"cid" : @(commentID)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosDeleteComment
                                 options:options
                                   error:nil];
}

#pragma mark - photos.restoreComment

- (id)restoreCommentID:(NSUInteger)commentID
{
    NSDictionary *options = @{@"cid" : @(commentID)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosRestoreComment
                                 options:options
                                   error:nil];
}

#pragma mark - photos.editComment

- (id)editCommentCustomOptions:(NSDictionary *)options
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosEditComment
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getTags

- (id)tagsPhotoID:(NSUInteger)photoID
{
    NSDictionary *options = @{@"pid" : @(photoID)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetTags
                                 options:options
                                   error:nil];
}

#pragma mark - photos.putTag

- (id)addTagPhotoID:(NSUInteger)photoID userID:(NSUInteger)userID
{
    NSDictionary *options = @{@"pid" : @(photoID),
                              @"uid" : @(userID)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosPutTag
                                 options:options
                                   error:nil];
}

#pragma mark - photos.removeTag

- (id)removeTagID:(NSUInteger)tagID photoID:(NSUInteger)photoID
{
    NSDictionary *options = @{@"tag_id" : @(tagID),
                              @"pid"    : @(photoID)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosRemoveTag
                                 options:options
                                   error:nil];
}

#pragma mark - photos.getNewTags

- (id)unseenPhotoTags
{
    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetNewTags
                                 options:@{}
                                   error:nil];
}

- (id)unseenPhotoTagsCount:(NSUInteger)count offset:(NSUInteger)offset
{
    NSDictionary *options = @{@"count"  : @(count),
                              @"offset" : @(offset)};

    return [[VKConnector sharedInstance]
                         performVKMethod:kVKPhotosGetNewTags
                                 options:options
                                   error:nil];
}

@end