#import <Foundation/Foundation.h>

#ifdef SLYCE_SDK_INTERNAL
#import "SlyceInstance.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface Slyce (Private)

- (NSArray<NSString *> *)configuredLensNames;

@end

NS_ASSUME_NONNULL_END
