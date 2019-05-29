#import <Foundation/Foundation.h>

#ifdef SLYCE_SDK_INTERNAL
#import "SlyceInstance.h"
#endif

NS_ASSUME_NONNULL_BEGIN

@interface Slyce (Private)

- (NSArray<NSString *> *)configuredLensNames;

/*!
 * @property
 * @brief The default `SlyceSession`.
 * @discussion The default `SlyceSession`. The default session cannot be manually invalidated, but will be invalidated when `Slyce` is closed.
 * @return A `SlyceSession` instance.
 */
@property (nonatomic, readonly, nullable) SlyceSession *defaultSession __deprecated_msg("The default session is deprecated and will be removed in a future release. Sessions may be created using the SlyceSession.sessionWithSlyce method.");

@end

NS_ASSUME_NONNULL_END
