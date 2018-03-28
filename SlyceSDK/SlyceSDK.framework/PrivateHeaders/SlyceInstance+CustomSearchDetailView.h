#import <UIKit/UIKit.h>

#import <SlyceSDK/SlyceInstance.h>
#import "SlyceLensType.h"

@class SlyceLayerSearchResult;

@protocol SlyceCustomSearchDetailProvider <NSObject>
- (nullable UIViewController *)searchDetailViewControllerFor:(nonnull SlyceLayerSearchResult *)result lensType:(SlyceLensType)lensType;
@end

@interface Slyce (SlyceCustomSearchDetailProvider)

@property (nonatomic, readwrite, nullable) id<SlyceCustomSearchDetailProvider> customSearchDetailProvider;

@end
