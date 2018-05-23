#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SlyceViewControllerMode) {
    SlyceViewControllerModeUniversal NS_SWIFT_NAME(universal),
    SlyceViewControllerModePicker NS_SWIFT_NAME(picker),
};

@class Slyce;
@class SlyceSession;
@protocol SlyceCameraControls;
@protocol SlyceSettingsPanelDelegate;
@protocol SlyceSettingsPanelDataSource;

NS_ASSUME_NONNULL_BEGIN
@interface SlyceViewController : UIViewController

- (instancetype)initWithSlyce:(Slyce *)slyce mode:(SlyceViewControllerMode)mode NS_DESIGNATED_INITIALIZER;

- (instancetype)initWithSession:(SlyceSession *)session mode:(SlyceViewControllerMode)mode __deprecated __deprecated_msg("Use 'initWithSlyce:mode:' instead.");

@property (nonatomic, readonly) id<SlyceCameraControls> camera;

@property (nonatomic, readwrite, weak, nullable) id<SlyceSettingsPanelDelegate> settingsPanelDelegate;
@property (nonatomic, readwrite, weak, nullable) id<SlyceSettingsPanelDataSource> settingsPanelDataSource;
@property (nonatomic, readwrite, assign) BOOL settingsButtonHidden DEPRECATED_ATTRIBUTE;

- (void)reloadSettingsPanel;

@end
NS_ASSUME_NONNULL_END
