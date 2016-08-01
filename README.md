# BobbleSDK

BobbleSDKOnboarding is a framework built to allow users to add Bobble creation functionality inside their app.

## System Requirements
iOS 8.0 or above

## Installation

#### As a CocoaPods Dependency
in progress
#### Manual Installation

Download the BobbleOnboarding folder from GitHub, move this subfolder over to your project folder, and drag it into your Xcode project.

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
