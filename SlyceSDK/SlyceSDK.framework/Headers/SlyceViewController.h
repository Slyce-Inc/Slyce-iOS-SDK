#import "SlyceBase.h"

#import <UIKit/UIKit.h>

#import "SlyceViewControllerMode.h"


@class Slyce;
@class SlyceItemDescriptor;
@class SlyceListDescriptor;
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
 * @param options A dictionary of additional options. See `SlyceOptions.h` header.
 * @param delegate Optional delegate. This may be set later as well.
 *
 * @return An instance of a `SlyceViewController`.
 */
- (instancetype)initWithSlyce:(Slyce *)slyce
                         mode:(SlyceViewControllerMode)mode
                      options:(nullable NSDictionary<id, id> *)options
                     delegate:(nullable id<SlyceViewControllerDelegate>)delegate NS_DESIGNATED_INITIALIZER;


/*!
 *
 * @brief Initializes a `SlyceViewController`.
 *
 * @param slyce An open `Slyce` instance.
 * @param mode The mode, either Universal Lens or Lens Picker. See `SlyceViewControllerMode`.
 *
 * @return An instance of a `SlyceViewController`.
 */
- (instancetype)initWithSlyce:(Slyce *)slyce mode:(SlyceViewControllerMode)mode;


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



/*!
 * @property
 *
 * @brief Access the attached session.
 */
@property (nonatomic, readonly, nullable) SlyceSession *session;

@end


/*!
 * @brief Delegate protocol for `SlyceViewController`.
 */
@protocol SlyceViewControllerDelegate <NSObject>

@optional
- (void)slyceViewController:(SlyceViewController *)viewController didOpenSession:(SlyceSession *)session;

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

/*!
 * @discussion This delegate method allows for the host application to handle a list
 * of items returned from a Slyce search,  presumably to show it's own custom view controller
 * instead of Slyce's default layer.
 *
 * @param viewController The attached `SlyceViewController`.
 * @param itemDescriptors An array of `SlyceItemDescriptor` objects, each of which provide
 * information about an individual item.
 *
 * @return Return `YES` or `true` if the `SlyceViewController` should show it's own default
 * item list layer. Return `NO` or `false` if your application will handle the display
 * of the item list.
 */
@optional
- (BOOL)slyceViewController:(SlyceViewController *)viewController shouldDisplayDefaultListForItemDescriptors:(NSArray<SlyceItemDescriptor *> *)itemDescriptors;


/*!
 * @discussion This delegate method allows for the host application to handle a list
 * that has been created during batch capture mode.
 *
 * @param viewController The attached `SlyceViewController`.
 * @param list A `SlyceListDescriptor` object, representing each item selected by the user.
 */
@optional
- (void)slyceViewController:(SlyceViewController *)viewController didCreateList:(SlyceListDescriptor *)list;

@end

NS_ASSUME_NONNULL_END
