#import <UIKit/UIKit.h>

#import <SlyceSDK/SlyceInstance.h>

@protocol SlyceMappable;

NS_ASSUME_NONNULL_BEGIN
@protocol SlyceCustomSearchDetailProvider <NSObject>
- (nullable UIViewController *)searchDetailViewControllerFor:(id <SlyceMappable>)result lensIdentifier:(NSString *)lensIdentifier;
@end

@interface Slyce (SlyceCustomSearchDetailProvider)

@property (nonatomic, readwrite, nullable) id<SlyceCustomSearchDetailProvider> customSearchDetailProvider;

@end
NS_ASSUME_NONNULL_END
