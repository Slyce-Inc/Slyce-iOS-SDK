#import <UIKit/UIKit.h>

#import "SlyceViewController.h"

NS_ASSUME_NONNULL_BEGIN
@protocol SlyceCustomSearchDetailViewControllerProvider <NSObject>
- (nullable UIViewController *)searchDetailViewControllerForResultItem:(NSDictionary *)resultItem;
@end

@interface SlyceViewController (CustomSearchDetail)

@property (nonatomic, readwrite, nullable) id<SlyceCustomSearchDetailViewControllerProvider> customSearchDetailViewControllerProvider;

@end
NS_ASSUME_NONNULL_END
