# BobbleSDK

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

## System Requirements
iOS 8.0 or above

## Installation

#### As a CocoaPods Dependency
in progress
#### Manual Installation

Download the BobbleSDK.framework and opencv2.framework from this GitHub, move over to your project folder, and drag it into your Xcode project.

## Usage

To use it in any class, you should import the BobbleSDK to that class. For Objective-C, #import <BobbleSDK/BobbleSDK.h> and for swift, import BobbleSDK.

Write the following line in your AppDelegate to use it anywhere in the app.

```objc
// Objective-C
[BobbleSDKCore initialize:CLIENT_ID]
```
```swift
// Swift
BobbleSDKCore.initialize(CLIENT_ID)
```

Here, CLIENT_ID is a unique identifier you should request Bobble before using the SDK. If it is not initialized before using any of its API’s,
they will not work as intended.

Before calling any of the API’s, call `isReady` function to check whether SDK is ready or not.
```objc
// Objective-C
[BobbleSDKCore isReady]]
```
```swift
// Swift
BobbleSDKCore.isReady()
```

To bobblify your face, you can use the following function as given below

### Bobblification without UI (Net connectivity is necesssary)
``` objc
// Objective-C
[BobbleSDKCore bobblify:IMAGE_OBJ gender:@"male" completionBlock:^(BobbleSDKFace *face, NSError *error) {
    if (error) {
        NSLog(@"failed to bobblify the face");
    }
}];
```
``` Swift
// swift
BobbleSDKCore.bobblify(IMAGE_OBJ, gender: "female") { (face, error) in
    if (error != nil) {
        print("failed to bobblify the face")
    }
}
```
You can give "male" or "female" in the gender. IMAGE_OBJ is an `UIImage` object that you should pass to get `BobbleSDKFace`

### Bobblification with UI (Net connectivity is good for bobble quality but not necessary)
Class `BobbleOnboardingViewController` operates around a very strict modal implementation. It cannot be pushed to a `UINavigationController` stack, and must be presented as a full-screen dialog on an existing view controller.

#### Basic Implementation
```objc
- (void)presentBobbleOnboardingController 
{
  BobbleOnboardingViewController* VC = [BobbleOnboardingViewController new];
  VC.delegate = self;

  UINavigationController* navVC = [[UINavigationController alloc] initWithRootViewController:VC];
  [self presentViewController:navVC animated:YES completion:nil];
}

- (void)bobblificationSuccess:(BobbleSDKFace *)face {
  // Bobblification succeeded returning BobbleSDKFace object.
}

- (void)bobblificationFailure:(NSError *)error {
  // Bobblification process failed with error.
}

- (void)onboardingController bobblificationCanceled {
  // The user canceled the bobblification process.
}
```

To get all faces(`BobbleSDKFace`),
``` Swift
// Objective-C
NSArray *allFaces = [BobbleSDKCore getAllFaces];
```
``` Swift
// Swift
let allFaces = BobbleSDKCore.getAllFaces();
```

To get all heads(`BobbleSDKHead`),
``` Swift
// Objective-C
NSArray *allHeads = [BobbleSDKCore getAllBobbleHeads];
```
``` Swift
// Swift
let allHeads = BobbleSDKCore.getAllBobbleHeads();
```

To get the list of Sticker Categories(`BobbleSDKStickerCategory`) available for download,
``` Swift
// Objective-C
[BobbleSDKCore getStickerCategoryList:LIMIT page:PAGE completionBlock:^(NSArray *results, NSError *error) {
    if (!error) {
        //results consist of BobbleSDKStickerCategory objects
    }else {
        NSLog(@"failed to get list");    
    }
}];
```
``` Swift
// Swift
BobbleSDKCore.getStickerCategoryList(LIMIT, page: PAGE) { (results, error) in
    if error != nil {
        //results consist of BobbleSDKStickerCategory objects
    }else {
        print("failed to get list")
    }
}
```
LIMIT -> Limit on number of sticker categories to be fetched
PAGE -> page number. Starts with zero.

To download a particular sticker category, you can do the following
``` Swift
// Objective-C
[BobbleSDKCore downloadStickerCategory:STICKER_CATEGORY completionBlock:^(NSError *error) {
    if (!error) {
        NSLog(@"failed to get sticker categories");
    }
}];
```
``` Swift
// Swift
BobbleSDKCore.downloadStickerCategory(STICKER_CATEGORY) { (error) in
    if (error != nil) {
        print("successfully downloaded stickers from sticker pack")
    }
}
```
STICKER_CATEGORY -> `BobbleSDKStickerCategory`

To get the list of all downloaded sticker categories
``` Swift
// Objective C
NSArray *allStickerCategories = [BobbleSDKCore getAllStickerCategories];
```
``` Swift
// Swift
let allStickerCategories = BobbleSDKCore.getAllStickerCategories()
```

To get list of stickers(`BobbleSDKSticker` object) for a sticker category(`BobbleSDKStickerCategory` object)
``` Swift
// Objective-C 
NSArray *stickerList = [BobbleSDKCore getStickerListForStickerCategory:STICKER_CATEGORY withGender:BobbleGenderMale];
```
``` Swift
// Swift
let stickerList = BobbleSDKCore.getStickerListForStickerCategory(STICKER_CATEGORY, withGender: BobbleGenderType.Male)
```
`BobbleGenderType` -> enum representing gender type
STICKER_CATEGORY -> `BobbleSDKStickerCategory` object

To get preferred bobble head for bobble face
``` Swift
// Objective-C
BobbleSDKHead *head = [BobbleSDKCore getPreferredBobbleHeadForFace:BOBBLE_HEAD];
``` 
``` Swift
// Swift
let head:BobbleSDKHead = BobbleSDKCore.getPreferredBobbleHeadForFace(BOBBLE_HEAD)
```
BOBBLE_HEAD -> `BobbleSDKHead` object

To get sticker image, do the following
``` Swift
// Objective-C
[BobbleSDKCore createSticker:HEAD sticker:STICKER completionBlock:^(UIImage *image, NSError *error) {
    if(error) {
        NSLog(@"failed to create image");
    }else {
        // sticker image created
    }
}];
```
``` Swift
// Swift
BobbleSDKCore.createSticker(HEAD, sticker: STICKER) { (image, error) in
    if (error != nil) {
        print("failed to create image")    
    }else {
        // sticker image created
    }
}
```
HEAD -> `BobbleSDKHead` object
STICKER -> `BobbleSDKSticker` object

To get sticker image with text, do the following
``` Swift
// Objective-C
[BobbleSDKCore createStickerOnTheFly:HEAD sticker:STICKER text:TEXT completionBlock:^(UIImage *image, NSError *error) {
    if(!error) {
        // Use the sticker image
    }else {
        NSLog(@"failed to create sticker");
    }
}];
```
``` swift
// Swift
BobbleSDKCore.createStickerOnTheFly(HEAD, sticker: STICKER, text: TEXT) { (image, error) in
    if (error != nil) {
        print("failed to create sticker");
    }else {
        // Use the sticker image
    }
}
```
HEAD -> `BobbleSDKHead` object
STICKER -> `BobbleSDKSticker` object
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
Method to close bobble SDK instance.
**Precondition:-** SDK should be enabled

#### 4. Bobblify
``` swift
+ (void)bobblify:(UIImage*)image
          gender:(NSString*)gender
 completionBlock:(BobbleSDKBobblificationHandler)handler
 ```
 This method is used to create bobble head from your selfie. The argument 'gender' can either be the string `"male"` or `"female"`. Usage of the function is as demonstrated in the previous section. None of the arguments passed should be Null.
**PreCondition:-** SDK should be enabled. 
 
#### 5. Create Sticker
``` swift
+ (void)createSticker:(BobbleSDKHead*)head
              sticker:(BobbleSDKSticker*)sticker
      completionBlock:(BobbleSDKStickerCreationHandler)handler
```
This method is for creating stickers. Usage of the function is as demonstrated in the previous section. None of the arguments passed should be Null.
**PreCondition:-** SDK should be enabled.

#### 6. Create OTF Sticker
``` swift
+ (void)createStickerOnTheFly:(BobbleSDKHead*)head
                      sticker:(BobbleSDKSticker*)sticker
                         text:(NSString*)text
              completionBlock:(BobbleSDKStickerCreationHandler)handler
```
This method is for creating stickers with OTF text. Usage of the function is as demonstrated in the previous section. None of the arguments passed should be Null.
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
Sample Code has been included with this project.
