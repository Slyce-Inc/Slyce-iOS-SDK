#import <Foundation/Foundation.h>

#import <SlyceSDK/SlyceInstance.h>

typedef NS_ENUM(NSUInteger, SlyceEnvironment) {
    SlyceEnvironmentStaging,
    SlyceEnvironmentProduction,
};


@interface Slyce (Environments)

/* Sets the environment for the shared Slyce instance. This must be
   called before accessing `[Slyce sharedInstance]`. Otherwise it will have
   no effect
 */
+ (void)setSharedInstanceEnvironment:(SlyceEnvironment)env;

@end
