//
//  BobbleError.h
//  BobbleiOSSDK
//
//  Created by GAURAV SRIVASTAVA on 24/06/16.
//  Copyright © 2016 TALENT UNLIMITED SERVICES PRIVATE LIMITED. All rights reserved.
//

#ifndef BobbleError_h
#define BobbleError_h

typedef NS_ENUM(NSUInteger, BobbleErrorCode) {
    BobbleNoFaceDetectedError,
    BobbleInternalError,
    BobbleInvalidFaceRectError,
    BobbleFileNotSupportedError,
    BobbleInvalidGenderError,
    BobbleInvalidColorConfigError,
    BobbleInvalidBobbleTypeError,
    BobbleImageKeyNotFoundError,
    BobbleUnAuthorizedError,
    
    BobbleInvalidDeviceIdError,
    BobbleInvalidClientIdError,
    BobbleInvalidApnKeyError,
    BobbleClientNotFoundError,
    BobbleClientConfigNotFoundError,
    BobbleInvalidRequestError,
    BobbleInvalidClientError,
    BobbleDeviceNotRegisteredError,
    
    BobbleStickerCategoryNotFoundError,
    BobbleStickersNotFoundError,
    
    BobbleStickerCategoriesNotFoundError,
    BobbleNoInternetConnectionError,
    
    BobbleSDKNotReadyError,
    BobbleInvalidImageError,
    BobbleInvalidBobbleError
};


#endif /* BobbleError_h */
