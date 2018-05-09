#import <Foundation/Foundation.h>

#import <SlyceSDK/SlyceSession.h>

@class Slyce;

NS_ASSUME_NONNULL_BEGIN
@interface SlyceSession (Creation)

+ (instancetype)createSession:(Slyce *)slyce;

@end
NS_ASSUME_NONNULL_END
