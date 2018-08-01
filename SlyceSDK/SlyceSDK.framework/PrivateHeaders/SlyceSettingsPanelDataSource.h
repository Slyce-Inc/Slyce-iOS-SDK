#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@protocol SlyceSettingsPanelDataSource <NSObject>

- (NSInteger)settingsPanelNumberOfSections;
- (NSInteger)settingsPanelNumberOfItemsInSection:(NSInteger)section;

- (BOOL)settingsPanelShowsHeaderForSection:(NSInteger)section;
- (NSString *)settingsPanelTitleForHeaderInSection:(NSInteger)section;

- (CGFloat)settingsPanelHeightForItemInSection:(NSInteger)section;

// Only one of the following is required (the former implements the latter using the default SlyceSettingsPanelItemView)
@optional
- (NSString *)settingsPanelTitleForItemAtIndexPath:(NSIndexPath *)indexPath;

@optional
- (UIView *)settingsPanelViewForItemAtIndexPath:(NSIndexPath *)indexPath;

@end
NS_ASSUME_NONNULL_END
