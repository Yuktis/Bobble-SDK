//
//  BobbleSDKStickerCategory.h
//  BobbleiOSSDK
//
//  Created by GAURAV SRIVASTAVA on 17/06/16.
//  Copyright © 2016 TALENT UNLIMITED SERVICES PRIVATE LIMITED. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface BobbleSDKStickerCategory : NSObject

@property (nonatomic) NSNumber* stickerCategoryId;
@property (nonatomic) NSString* stickerCategoryName;
@property (nonatomic) NSString* stickerCategoryDescription;
@property (nonatomic) NSString* stickerCategoryImage;
@property (nonatomic) NSString* stickerCategoryBannerImageUrl;
@property (nonatomic) NSString* fileSize;
@property (nonatomic) NSString* stickerCategoryPreviewImageUrl;
@property (nonatomic) NSNumber* numberStickers;
@property (nonatomic) NSArray* stickerCategoryPreviewImages;

@end
