//
//  BobbleOnboardingBaseController.h
//  Bobble
//
//  Created by GAURAV SRIVASTAVA on 28/01/16.
//  Copyright © 2016 Touchtalent. All rights reserved.
//

#import <UIKit/UIKit.h>

@class BobbleSDKFace;
@protocol BobbleOnboardingDelegate <NSObject>

- (void)bobblificationSuccess:(BobbleSDKFace *)face;
- (void)bobblificationFailure:(NSError *)error;
- (void)bobblificationCanceled;

@end

@interface BobbleOnboardingBaseController : UIViewController

@property(weak, nonatomic) id<BobbleOnboardingDelegate> delegate;

@end
