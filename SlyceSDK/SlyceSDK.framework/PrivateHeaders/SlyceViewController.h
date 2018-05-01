#import <UIKit/UIKit.h>

#import <SlyceSDK/SlyceSession.h>


typedef NS_ENUM(NSUInteger, SlyceViewControllerMode) {
    SlyceViewControllerModeUniversal NS_SWIFT_NAME(universal),
    SlyceViewControllerModePicker NS_SWIFT_NAME(picker),
};

@class Slyce;
@protocol SlyceCameraControls;
@protocol SlyceSettingsPanelDelegate;
@protocol SlyceSettingsPanelDataSource;


NS_ASSUME_NONNULL_BEGIN
@interface SlyceViewController : UIViewController

@property (nonatomic, readonly) id<SlyceCameraControls> camera;

@property (nonatomic, readwrite, weak, nullable) id<SlyceSettingsPanelDelegate> settingsPanelDelegate;
@property (nonatomic, readwrite, weak, nullable) id<SlyceSettingsPanelDataSource> settingsPanelDataSource;
@property (nonatomic, readwrite, assign) BOOL settingsButtonHidden DEPRECATED_ATTRIBUTE;

- (void)reloadSettingsPanel;

@end
NS_ASSUME_NONNULL_END



NS_ASSUME_NONNULL_BEGIN
@interface SlyceSession (SlyceViewController)

/*!
 * @method
 *
 * @brief Creates a new SlyceViewController instance.
 *
 * @param mode - The mode for the SlyceViewController
 *
 * @return A nullable `SlyceViewController`
 */
- (nullable SlyceViewController *)slyceViewControllerWithMode:(SlyceViewControllerMode)mode;

@end
NS_ASSUME_NONNULL_END
