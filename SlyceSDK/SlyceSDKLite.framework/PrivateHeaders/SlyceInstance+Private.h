#import <Foundation/Foundation.h>

#ifdef SLYCE_SDK_INTERNAL
#import "SlyceInstance.h"
#endif

@interface Slyce (Private)

- (NSArray<NSString *> *)configuredLensNames;

@end
