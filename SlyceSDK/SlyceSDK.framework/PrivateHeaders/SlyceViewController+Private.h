#import <SlyceSDK/SlyceViewController.h>


@interface SlyceViewController (Private)

#pragma mark Search History

- (void)clearSearchHistory:(void(^)(NSError * _Nullable error))completion;

@end
