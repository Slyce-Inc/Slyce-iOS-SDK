#import "SlyceBase.h"

#import <UIKit/UIKit.h>


typedef NS_ENUM(NSUInteger, SlyceViewControllerMode) {
    /*! @brief Sets "universal" lens mode. You must have a universal lens configured for your Slyce account. */
    SlyceViewControllerModeUniversal NS_SWIFT_NAME(universal),
    
    /*! @brief Set "picker" lens mode. This allows the user to choose between all configured lenses, except universal lens. */
    SlyceViewControllerModePicker NS_SWIFT_NAME(picker),
};


@class Slyce;
@class SlyceItemDescriptor;
@class SlyceSession;
@protocol SlyceCameraControls;
@protocol SlyceViewControllerDelegate;


NS_ASSUME_NONNULL_BEGIN


/*!
 * @brief Slyce "Full UI" mode entry point.
 */
@interface SlyceViewController : UIViewController

#pragma mark Initialization

/*!
 *
 * @brief Initializes a `SlyceViewController`.
 *
 * @param slyce An open `Slyce` instance.
 * @param mode The mode, either Universal Lens or Lens Picker. See `SlyceViewControllerMode`.
 *
 * @return An instance of a `SlyceViewController`.
 */
- (instancetype)initWithSlyce:(Slyce *)slyce mode:(SlyceViewControllerMode)mode NS_DESIGNATED_INITIALIZER;


#pragma mark Properties

/*!
 * @brief Sets the delegate, which can be used to override the `SlyceViewController`'s layer behavior.
 */
@property (nonatomic, readwrite, weak, nullable) id<SlyceViewControllerDelegate> delegate;

/*!
 * @property
 *
 * @brief Access the camera interface.
 */
@property (nonatomic, readonly) id<SlyceCameraControls> camera;

@end


/*!
 * @brief Delegate protocol for `SlyceViewController`.
 */
@protocol SlyceViewControllerDelegate <NSObject>

/*!
 * @discussion This delegate method allows for the host application to handle an item selected from
 * search results, presumably to show it's own custom view controller instead of Slyce's
 * default layer.
 *
 * @param viewController The attached `SlyceViewController`.
 * @param itemDescriptor A `SlyceItemDescriptor` object which provides information
 * about the selected item.
 *
 * @return Return `YES` or `true` if the `SlyceViewController` should show it's own default
 * item detail layer. Return `NO` or `false` if your application will handle the the display
 * of the item.
 */
@optional
- (BOOL)slyceViewController:(SlyceViewController *)viewController shouldDisplayDefaultDetailForItemDescriptor:(SlyceItemDescriptor *)itemDescriptor;

@end


NS_ASSUME_NONNULL_END
