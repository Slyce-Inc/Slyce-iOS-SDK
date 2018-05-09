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

- (instancetype)initWithSession:(SlyceSession *)session mode:(SlyceViewControllerMode)mode;

@property (nonatomic, readonly) id<SlyceCameraControls> camera;

@property (nonatomic, readwrite, weak, nullable) id<SlyceSettingsPanelDelegate> settingsPanelDelegate;
@property (nonatomic, readwrite, weak, nullable) id<SlyceSettingsPanelDataSource> settingsPanelDataSource;
@property (nonatomic, readwrite, assign) BOOL settingsButtonHidden DEPRECATED_ATTRIBUTE;

- (void)reloadSettingsPanel;

@end
NS_ASSUME_NONNULL_END
