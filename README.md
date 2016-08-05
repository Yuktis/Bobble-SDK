# BobbleSDK

BobbleSDKOnboarding is a framework built to allow users to add Bobble creation functionality inside their app.

## System Requirements
iOS 8.0 or above

## Installation

#### As a CocoaPods Dependency
in progress
#### Manual Installation

Download the BobbleOnboarding folder from GitHub, move this subfolder over to your project folder, and drag it into your Xcode project.

## Overview
Bobble iOS SDK enables you to do the following tasks
* Create bobblified heads
* Select preferred head
* Download list of sticker categories(sticker packs) available on our server
* Download corresponding stickers for each sticker category available on our server
* Fetch all sticker categories available in the offline database
* Fetch all corresponding stickers for given sticker category and gender
* Create default sticker-image for given bobble head and bobble sticker
* Create sticker-image for given bobble head, bobble sticker and text

The following guide explains all the steps involved in integrating BobbleSDK with your app.

## Usage

To use it in any class, you should import the BobbleiOSSDK to that class. For Objective-C, #import <BobbleSDK/BobbleSDK.h> and for swift, import BobbleSDK.

Write the following line in your AppDelegate to use it anywhere in the app.

```objc
[BobbleSDK initialize:CLIENT_ID]
```
```swift
BobbleSDK.initialize(CLIENT_ID)
```

Here, CLIENT_ID is a unique identifier you should request Bobble before using the SDK. If it is not initialized before using any of its API’s,
they will not work as intended.

Before calling any of the API’s, call `isReady` function to check whether SDK is ready or not.
```objc
[BobbleSDK isReady]]
```
```swift
BobbleSDK.isReady()
```
To bobblify your face, you can use the following function as given below
``` Swift
// Objective-C
[BobbleSDK bobblify:IMAGE_OBJ gender:@"male" completionBlock:^(BobbleSDKFace *face, NSError *error) {
    if (error) {
        NSLog(@"failed to bobblify the face");
    }
}];
```
``` Swift
// swift
BobbleSDK.bobblify(IMAGE_OBJ, gender: "female") { (face, error) in
    if (error != nil) {
        print("failed to bobblify the face")
    }
}
```
You can give "male" or "female" in the gender. IMAGE_OBJ is an `UIImage` object that you should pass to get `BobbleSDKFace`

To get all faces(`BobbleSDKFace`),
``` Swift
// Objective-C
NSArray *allFaces = [BobbleSDK getAllFaces];
```
``` Swift
// Swift
let allFaces = BobbleSDK.getAllFaces();
```

To get all heads(`BobbleSDKHead`),
``` Swift
// Objective-C
NSArray *allHeads = [BobbleSDK getAllBobbleHeads];
```
``` Swift
// Swift
let allHeads = BobbleSDK.getAllBobbleHeads();
```

To get the list of Sticker Categories(`BobbleSDKStickerCategory`) available for download,
``` Swift
// Objective-C
[BobbleSDK getStickerCategoryList:LIMIT page:PAGE completionBlock:^(NSArray *results, NSError *error) {
    if (!error) {
        //results consist of BobbleSDKStickerCategory objects
    }else {
        NSLog(@"failed to get list");    
    }
}];
```
``` Swift
// Swift
BobbleSDK.getStickerCategoryList(LIMIT, page: PAGE) { (results, error) in
    if error != nil {
        //results consist of BobbleSDKStickerCategory objects
    }else {
        print("failed to get list")
    }
}
```
LIMIT -> Limit on number of sticker categories to be fetched \
PAGE -> page number

To download a particular sticker category, you can do the following
``` Swift
// Objective-C
[BobbleSDK downloadStickerCategory:STICKER_CATEGORY completionBlock:^(NSError *error) {
    if (!error) {
        NSLog(@"failed to get sticker categories");
    }
}];
```
``` Swift
// Swift
BobbleSDK.downloadStickerCategory(STICKER_CATEGORY) { (error) in
    if (error != nil) {
        print("successfully downloaded stickers from sticker pack")
    }
}
```
STICKER_CATEGORY -> `BobbleSDKStickerCategory`

To get the list of all downloaded sticker categories
``` Swift
// Objective C
NSArray *allStickerCategories = [BobbleSDK getAllStickerCategories];
```
``` Swift
// Swift
let allStickerCategories = BobbleSDK.getAllStickerCategories()
```

To get list of stickers(`BobbleSDKSticker` object) for a sticker category(`BobbleSDKStickerCategory` object)
``` Swift
// Objective-C 
NSArray *stickerList = [BobbleSDK getStickerListForStickerCategory:STICKER_CATEGORY withGender:BobbleGenderMale];
```
``` Swift
// Swift
let stickerList = BobbleSDK.getStickerListForStickerCategory(STICKER_CATEGORY, withGender: BobbleGenderType.Male)
```
`BobbleGenderType` -> enum representing gender type\
STICKER_CATEGORY -> `BobbleSDKStickerCategory` object


To get preferred bobble head for bobble face
``` Swift
// Objective-C
BobbleSDKHead *head = [BobbleSDK getPreferredBobbleHeadForFace:BOBBLE_HEAD];
``` 
``` Swift
// Swift
let head:BobbleSDKHead = BobbleSDK.getPreferredBobbleHeadForFace(BOBBLE_HEAD)
```
BOBBLE_HEAD -> `BobbleSDKHead` object

To get sticker image, do the following
``` Swift
// Objective-C
[BobbleSDK createSticker:HEAD sticker:STICKER completionBlock:^(UIImage *image, NSError *error) {
    if(error) {
        NSLog(@"failed to create image");
    }else {
        // sticker image created
    }
}];
```
``` Swift
// Swift
BobbleSDK.createSticker(HEAD, sticker: STICKER) { (image, error) in
    if (error != nil) {
        print("failed to create image")    
    }else {
        // sticker image created
    }
}
```
HEAD -> `BobbleSDKHead` object\
STICKER -> `BobbleSDKSticker` object

To get sticker image with text, do the following
``` Swift
// Objective-C
[BobbleSDK createStickerOnTheFly:HEAD sticker:STICKER text:TEXT completionBlock:^(UIImage *image, NSError *error) {
    if(!error) {
        // Use the sticker image
    }else {
        NSLog(@"failed to create sticker");
    }
}];
```
``` swift
// Swift
BobbleSDK.createStickerOnTheFly(HEAD, sticker: STICKER, text: TEXT) { (image, error) in
    if (error != nil) {
        print("failed to create sticker");
    }else {
        // Use the sticker image
    }
}
```
HEAD -> `BobbleSDKHead` object\
STICKER -> `BobbleSDKSticker` object\
TEXT -> string

### APIs

#### 1. Intialize
``` swift
+ (void)initialize:(NSString*)clientId
```
You should invoke initialize API from your landing activity. This API accepts one argument, clientId which is used to authenticate and authorize your application with Bobble server. This cannot be Null.

#### 2. isReady
``` swift
+ (BOOL)isReady
```
Method to check if SDK is ready to do something.

#### 3. ShutDown
``` swift
+ (void)shutDown
```
Method to close bobble SDK instance.\
**Precondition:-** SDK should be enabled

#### 4. Bobblify
``` swift
+ (void)bobblify:(UIImage*)image
          gender:(NSString*)gender
 completionBlock:(BobbleSDKBobblificationHandler)handler
 ```
 This method is used to create bobble head from your selfie. The argument 'gender' can either be the string `"male"` or `"female"`. Usage of the function is as demonstrated in the previous section. None of the arguments passed should be Null.\
**PreCondition:-** SDK should be enabled. 
 
#### 5. Create Sticker
``` swift
+ (void)createSticker:(BobbleSDKHead*)head
              sticker:(BobbleSDKSticker*)sticker
      completionBlock:(BobbleSDKStickerCreationHandler)handler
```
This method is for creating stickers. Usage of the function is as demonstrated in the previous section. None of the arguments passed should be Null.\
**PreCondition:-** SDK should be enabled.

#### 6. Create OTF Sticker
``` swift
+ (void)createStickerOnTheFly:(BobbleSDKHead*)head
                      sticker:(BobbleSDKSticker*)sticker
                         text:(NSString*)text
              completionBlock:(BobbleSDKStickerCreationHandler)handler
```
This method is for creating stickers with OTF text. Usage of the function is as demonstrated in the previous section. None of the arguments passed should be Null.\
**PreCondition:-** SDK should be enabled.

#### 7. getAllFaces
``` swift
+ (NSArray*)getAllFaces
```
To get all faces. This will return a list of faces.

#### 8. getAllBobbleHeads
``` Swift
+ (NSArray*)getAllBobbleHeads
```
To get a list of all bobblified heads for all faces

#### 9. getBobbleHeadForFace
``` Swift
+ (NSArray*)getBobbleHeadsForFace:(BobbleSDKFace*)face
```
To get list of all bobblified heads for a particular face

#### 10. getPreferredBobbleHeadForFace
``` Swift
+ (BobbleSDKHead*)getPreferredBobbleHeadForFace:(BobbleSDKFace*)face
```
This will return the preferred head for a particular faceId, the priority is set by server.

#### 11. getAllStickerCategories
``` Swift
+ (NSArray*)getAllStickerCategories
```
To get list of all Sticker Categories

#### 12. getStickerListForStickerCategory
``` Swift
+ (NSArray*)getStickerListForStickerCategory:(BobbleSDKStickerCategory*)category    withGender:(BobbleGenderType)genderType
```
To fetch all sticker for a particular stickercategory id. It accepts two arguments, first is stickercategoryid which is unique id for each stickercategory, second is bobblified head.

#### 13. getStickerCategoryList
``` Swift
+ (void)getStickerCategoryList:(NSInteger)limit
                          page:(NSInteger)page
               completionBlock:(BobbleSDKAPIStickerCategoryListHandler)handler
```
To get pagewise sticker categories list. Arguments are :-
1. limit numeric value to set limit, this should not be changed in a session
2. page to set no. of pages

#### 14. downloadStickerCategory
``` Swift
+ (void)downloadStickerCategory:(BobbleSDKStickerCategory*)category
                completionBlock:(BobbleSDKStickerCategoryDownloadHandler)handler
```
It accepts BobbleSDKStickerCategory as an argument to download the pack

## Examples
`BobbleOnboarding` operates around a very strict modal implementation. It cannot be pushed to a `UINavigationController` stack, and must be presented as a full-screen dialog on an existing view controller.

### Basic Implementation
```objc
- (void)presentBobbleOnboardingController 
{
  BobbleOnboardingViewController* VC = [BobbleOnboardingViewController new];
  VC.delegate = self;

  UINavigationController* navVC = [[UINavigationController alloc] initWithRootViewController:VC];
  [self presentViewController:navVC animated:YES completion:nil];
}

- (void)onboardingController:(BobbleOnboardingViewController*) onboardingController bobblificationSuccess:(BobbleSDKFace *)face {
  // Bobblification succeeded returning BobbleSDKFace object.
}

- (void)onboardingController:(BobbleOnboardingViewController*) onboardingController bobblificationFailure:(NSError *)error {
  // Bobblification process failed with error.
}

- (void)onboardingController:(BobbleOnboardingViewController*) onboardingController bobblificationCanceled {
  // The user canceled the bobblification process.
}
```
