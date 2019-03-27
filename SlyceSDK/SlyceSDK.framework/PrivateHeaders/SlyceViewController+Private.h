
#ifdef SLYCE_SDK_INTERNAL
#import "SlyceViewController.h"
#endif


NS_ASSUME_NONNULL_BEGIN

@interface SlyceViewController (Private)

#pragma mark Search History

- (void)clearSearchHistory:(void(^)(NSError * _Nullable error))completion;

@end

NS_ASSUME_NONNULL_END
