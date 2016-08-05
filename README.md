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

Download the BobbleOnboarding folder from GitHub, move this subfolder over to your project folder, and drag it into your Xcode project.

## Usage

To use it in any class, you should import the BobbleiOSSDK to that class. For Objective-C, #import <BobbleSDK/BobbleSDK.h> and for swift, import BobbleSDK.

Write the following line in your AppDelegate to use it anywhere in the app.

```objc
[BobbleSDK initialize:CLIENT_ID] // Obj-C
```
```swift
BobbleSDK.initialize(CLIENT_ID) // Swift
```

Here, CLIENT_ID is a unique identifier you should request Bobble before using the SDK. If it is not initialized before using any of its API’s,
they will not work as intended.

Before calling any of the API’s, call `isReady` function to check whether SDK is ready or not.
```objc
[BobbleSDK isReady] // Obj-C
```
```swift
BobbleSDK.isReady() // Swift
```

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
