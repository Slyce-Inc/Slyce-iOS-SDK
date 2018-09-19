#import <SlyceSDK/SlyceViewController.h>

@class SlyceListDescriptor;

NS_ASSUME_NONNULL_BEGIN

@protocol SlyceLabsViewControllerDelegate <NSObject>

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
