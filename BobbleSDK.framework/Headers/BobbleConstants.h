//
//  BobbleConstants.h
//  BobbleiOSSDK
//
//  Created by GAURAV SRIVASTAVA on 17/06/16.
//  Copyright © 2016 TALENT UNLIMITED SERVICES PRIVATE LIMITED. All rights reserved.
//

#ifndef BobbleConstants_h
#define BobbleConstants_h

#define SYSTEM_VERSION_EQUAL_TO(v)                  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedSame)
#define SYSTEM_VERSION_GREATER_THAN(v)              ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedDescending)
#define SYSTEM_VERSION_GREATER_THAN_OR_EQUAL_TO(v)  ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN(v)                 ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] == NSOrderedAscending)
#define SYSTEM_VERSION_LESS_THAN_OR_EQUAL_TO(v)     ([[[UIDevice currentDevice] systemVersion] compare:v options:NSNumericSearch] != NSOrderedDescending)

#define SYSTEM_SCALE_1X [[UIScreen mainScreen]scale] == 1.0
#define SYSTEM_SCALE_2X [[UIScreen mainScreen]scale] == 2.0
#define SYSTEM_SCALE_3X [[UIScreen mainScreen]scale] == 3.0


typedef NS_ENUM(NSUInteger, BobbleGenderType) {
    BobbleGenderMale,
    BobbleGenderFemale,
    BobbleGenderAll
};

#endif /* BobbleConstants_h */
