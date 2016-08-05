//
//  ViewController.m
//  BobbleOnboardingDemo
//
//  Created by GAURAV SRIVASTAVA on 29/07/16.
//  Copyright © 2016 TALENT UNLIMITED SERVICES PRIVATE LIMITED. All rights reserved.
//

#import "ViewController.h"
#import <BobbleSDK/BobbleSDK.h>

@interface ViewController () <BobbleOnboardingDelegate>
@property (weak, nonatomic) IBOutlet UIImageView *imageView;
@property (weak, nonatomic) IBOutlet UIImageView *stickerImageView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [BobbleSDKCore initialize:@"Insert your ClientID here."];
    
    self.stickerImageView.contentMode = UIViewContentModeScaleAspectFit;
    self.imageView.contentMode = UIViewContentModeScaleAspectFit;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (IBAction)bobble:(id)sender {
    BobbleOnboardingViewController* VC = [BobbleOnboardingViewController new];
    VC.delegate = self;
    
    UINavigationController* navVC = [[UINavigationController alloc] initWithRootViewController:VC];
    [self presentViewController:navVC animated:YES completion:nil];
}

- (void)bobblificationSuccess:(BobbleSDKFace *)face {
    UIImage* image = [BobbleSDKCore getBobbleForFace:face];
    
    self.imageView.image = image;
    
    [BobbleSDKCore getStickerCategoryList:1 page:0 completionBlock:^(NSArray *results, NSError *error) {
        if (error == nil && results && results.count) {
            
            BobbleSDKStickerCategory* category = [results objectAtIndex:0];
            [BobbleSDKCore downloadStickerCategory:category completionBlock:^(NSError *error) {
                if (error == nil) {
                    NSArray* stickers = [BobbleSDKCore getStickerListForStickerCategory:category withGender:BobbleGenderAll];
                    BobbleSDKSticker* sticker = stickers[0];
                    BobbleSDKHead* head = [BobbleSDKCore getPreferredBobbleHeadForFace:face];
                    
                    [BobbleSDKCore createStickerOnTheFly:head sticker:sticker text:@"Congratulations" completionBlock:^(UIImage *image, NSError *error) {
                        self.stickerImageView.image = image;
                    }];
                }
            }];
        }
    }];
}

- (void)bobblificationCanceled {
    
}

- (void)bobblificationFailure:(NSError *)error {
    
}

@end
