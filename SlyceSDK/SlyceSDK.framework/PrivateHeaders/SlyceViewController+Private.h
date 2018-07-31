#import "SlyceViewController.h"

@class SlyceLayerCoordinatorBase;

@interface SlyceViewController (Private)

- (void)clearSearchHistory:(void(^)(NSError * _Nullable error))completion;

@end
