#import <UIKit/UIKit.h>
#import "SlyceTypes.h"

NS_ASSUME_NONNULL_BEGIN


/*!
 * @brief Object encapsulating an image to be analyzed and a corresponding point of interest (anchor).
 */
@interface SlyceSearchImage : NSObject

/*!
 * @method
 *
 * @brief Initializes a new `SlyceSearchImage`.
 *
 * @discussion Use this method to create a new `SlyceSearchImage` without an anchor point.
 *
 * @param image - The `UIImage` to be used for this search.
 *
 * @return A `SlyceSearchImage` instance.
 */
- (instancetype)initWithImage:(UIImage *)image;

/*!
 * @method
 *
 * @brief Initializes a new `SlyceSearchImage`.
 *
 * @discussion Use this method to create a new `SlyceSearchImage` with an anchor point.
 *
 * @param image - The `UIImage` to be used for this search.
 *
 * @return A `SlyceSearchImage` instance.
 */
- (instancetype)initWithImage:(UIImage *)image anchor:(CGPoint)anchor NS_DESIGNATED_INITIALIZER;

/*!
 * @property
 *
 * @brief The image to be searched.
 */
@property (nonatomic, readonly) UIImage *image;

/*!
 * @property
 *
 * @brief The point of interest. If no anchor was supplied, this will equal `SlyceAnchorPointNone`.
 */
@property (nonatomic, readonly) CGPoint anchor;

@end


NS_ASSUME_NONNULL_END
