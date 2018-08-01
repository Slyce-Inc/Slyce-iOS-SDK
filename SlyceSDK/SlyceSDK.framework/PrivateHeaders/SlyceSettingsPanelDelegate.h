#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol SlyceSettingsPanelDelegate <NSObject>

- (void)settingsPanel:(UIViewController *)viewController didSelectItemAtIndexPath:(NSIndexPath *)indexPath;

@end
NS_ASSUME_NONNULL_END
