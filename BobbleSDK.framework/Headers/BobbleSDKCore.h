//
//  BobbleSDKCore.h
//  BobbleSDK
//
//  Created by GAURAV SRIVASTAVA on 17/06/16.
//  Copyright © 2016 TALENT UNLIMITED SERVICES PRIVATE LIMITED. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "BobbleSDKFace.h"
#import "BobbleSDKHead.h"
#import "BobbleSDKStickerCategory.h"
#import "BobbleSDKSticker.h"

typedef void (^BobbleSDKStickerCategoryDownloadHandler)(NSError *error);
typedef void (^BobbleSDKAPIStickerCategoryListHandler)(NSArray* results, NSError *error);
typedef void (^BobbleSDKBobblificationHandler)(BobbleSDKFace* face, NSError *error);
typedef void (^BobbleSDKStickerCreationHandler)(UIImage* image, NSError *error);

@interface BobbleSDKCore : NSObject

+ (void)initialize:(NSString*)clientId;

+ (BOOL)isReady;

+ (void)shutDown;

+ (void)bobblify:(UIImage*)image
          gender:(NSString*)gender
 completionBlock:(BobbleSDKBobblificationHandler)handler;

+ (void)createSticker:(BobbleSDKHead*)head
              sticker:(BobbleSDKSticker*)sticker
      completionBlock:(BobbleSDKStickerCreationHandler)handler;

+ (void)createStickerOnTheFly:(BobbleSDKHead*)head
                      sticker:(BobbleSDKSticker*)sticker
                         text:(NSString*)text
              completionBlock:(BobbleSDKStickerCreationHandler)handler;

+ (NSArray*)getAllFaces;

+ (NSArray*)getAllBobbleHeads;

+ (NSArray*)getBobbleHeadsForFace:(BobbleSDKFace*)face;

+ (BobbleSDKHead*)getPreferredBobbleHeadForFace:(BobbleSDKFace*)face;

+ (CGPoint)getNeckOffsetForFace:(BobbleSDKFace*)face;

+ (UIImage*)getBobbleForFace:(BobbleSDKFace*)face;

+ (NSArray*)getAllStickerCategories;

+ (NSArray*)getStickerListForStickerCategory:(BobbleSDKStickerCategory*)category
                                  withGender:(BobbleGenderType)genderType;

+ (void)getStickerCategoryList:(NSInteger)limit
                          page:(NSInteger)page
               completionBlock:(BobbleSDKAPIStickerCategoryListHandler)handler;

+ (void)downloadStickerCategory:(BobbleSDKStickerCategory*)category
                completionBlock:(BobbleSDKStickerCategoryDownloadHandler)handler;

@end
