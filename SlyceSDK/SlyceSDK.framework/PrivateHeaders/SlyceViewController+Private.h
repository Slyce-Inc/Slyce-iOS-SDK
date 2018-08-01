#import <SlyceSDK/SlyceViewController.h>

@protocol SlyceSettingsPanelDelegate;
@protocol SlyceSettingsPanelDataSource;


@interface SlyceViewController (Private)

#pragma mark Settings Panel

@property (nonatomic, readwrite, weak, nullable) id<SlyceSettingsPanelDelegate> settingsPanelDelegate;

@property (nonatomic, readwrite, weak, nullable) id<SlyceSettingsPanelDataSource> settingsPanelDataSource;

- (void)reloadSettingsPanel;

#pragma mark Search History

- (void)clearSearchHistory:(void(^)(NSError * _Nullable error))completion;

@end
