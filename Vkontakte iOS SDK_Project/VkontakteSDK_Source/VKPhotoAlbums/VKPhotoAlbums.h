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

#import <Foundation/Foundation.h>

/**
* Класс позволяет работать с фотографиями и альбомами пользователя.
*/
@interface VKPhotoAlbums : NSObject

/**
* @name photos.createAlbum
*/
- (id)createTitle:(NSString *)title
      description:(NSString *)description;

- (id)createTitle:(NSString *)title
      description:(NSString *)description
   commentPrivacy:(NSUInteger)commentPrivacy
          privacy:(NSUInteger)privacy;

- (id)createCustomOptions:(NSDictionary *)options;

/**
* @name photos.editAlbum
*/
- (id)editAlbumID:(NSUInteger)albumID
            title:(NSString *)title
      description:(NSString *)description;

- (id)editAlbumID:(NSUInteger)albumID
            title:(NSString *)title
      description:(NSString *)description
   commentPrivacy:(NSUInteger)commentPrivacy
          privacy:(NSUInteger)privcay;

- (id)editCustomOptions:(NSDictionary *)options;

/**
* @name photos.getAlbums
*/
- (id)listCustomOptions:(NSDictionary *)options;

/**
* @name photos.get
*/
- (id)listPhotosCustomOptions:(NSDictionary *)options;

/**
* @name photos.getAlbumsCount
*/
- (id)count;

/**
* @name photos.getProfile
*/
- (id)profileCustomOptions:(NSDictionary *)options;

/**
* @name photos.getById
*/
- (id)photosByIDs:(NSArray *)photosIDs;

- (id)photosByIDsCustomOptions:(NSDictionary *)options;

/**
* @name photos.getUploadServer
*/
- (id)uploadServer;

- (id)uploadServerCustomOptions:(NSDictionary *)options;

/**
* @name photos.getProfileUploadServer
*/
- (id)profileUploadServer;

/**
* @name photos.saveProfilePhoto
*/
- (id)saveProfilePhotoCustomOptions:(NSDictionary *)options;

- (id)saveProfilePhoto:(NSString *)photo
                server:(NSString *)server
                  hash:(NSString *)hash;

/**
* @name photos.saveWallPhoto
*/
- (id)saveWallPhotoCustomOptions:(NSDictionary *)options;

/**
* @name photos.getWallUploadServer
*/
- (id)wallUploadServer;

- (id)wallUploadServerCustomOptions:(NSDictionary *)options;

/**
* @name photos.getMessagesUploadServer
*/
- (id)messagesUploadServer;

- (id)messagesUploadServerCustomOptions:(NSDictionary *)options;

/**
* @name photos.saveMessagesPhoto
*/
- (id)saveMessagesPhotoCustomOptions:(NSDictionary *)options;

/**
* @name photos.search
*/
- (id)searchQuery:(NSString *)searchQuery
         latitude:(CGFloat)latitude
        longitude:(CGFloat)longitude;

- (id)searchQuery:(NSString *)searchQuery;

/**
* @name photos.save
*/
- (id)savePhotoCustomOptions:(NSDictionary *)options;

/**
* @name photos.edit
*/
- (id)editPhotoCustomOptions:(NSDictionary *)options;

- (id)editPhotoID:(NSUInteger)photoID
          ownerID:(NSUInteger)ownerID
          caption:(NSString *)caption;

/**
* @name photos.move
*/
- (id)movePhotoCustomOptions:(NSDictionary *)options;

- (id)movePhotoID:(NSUInteger)photoID
        toAlbumID:(NSUInteger)albumID;

/**
* @name photos.makeCover
*/
- (id)makeCoverCustomOptions:(NSDictionary *)options;

- (id)makeCoverPhotoID:(NSUInteger)photoID
               albumID:(NSUInteger)albumID;

/**
* @name photos.reorderAlbums
*/
- (id)reorderCustomOptions:(NSDictionary *)options;

/**
* @name photos.reorderPhotos
*/
- (id)reorderPhotosCustomOptions:(NSDictionary *)options;

/**
* @name photos.getAll
*/
- (id)allPhotosCustomOptions:(NSDictionary *)options;

/**
* @name photos.getUserPhotos
*/
- (id)taggedPhotosCustomOptions:(NSDictionary *)options;

/**
* @name photos.deleteAlbum
*/
- (id)removeAlbumID:(NSUInteger)albumID;

/**
* @name photos.delete
*/
- (id)removePhotoID:(NSUInteger)photoID;

/**
* @name photos.confirmTag
*/
- (id)confirmTagID:(NSUInteger)tagID
           photoID:(NSUInteger)photoID;

/**
* @name photos.getComments
*/
- (id)photoCommentsCustomOptions:(NSDictionary *)options;

/**
* @name photos.getAllComments
*/
- (id)allCommentsCustomOptions:(NSDictionary *)options;

/**
* @name photos.createComment
*/
- (id)addCommentCustomOptions:(NSDictionary *)options;

/**
* @name photos.deleteComment
*/
- (id)removeCommentID:(NSUInteger)commentID;

/**
* @name photos.restoreComment
*/
- (id)restoreCommentID:(NSUInteger)commentID;

/**
* @name photos.editComment
*/
- (id)editCommentCustomOptions:(NSDictionary *)options;

/**
* @name photos.getTags
*/
- (id)tagsPhotoID:(NSUInteger)photoID;

/**
* @name photos.putTag
*/
- (id)addTagPhotoID:(NSUInteger)photoID
             userID:(NSUInteger)userID;

/**
* @name photos.removeTag
*/
- (id)removeTagID:(NSUInteger)tagID
          photoID:(NSUInteger)photoID;

/**
* @name photos.getNewTags
*/
- (id)unseenPhotoTags;

- (id)unseenPhotoTagsCount:(NSUInteger)count
                    offset:(NSUInteger)offset;

@end