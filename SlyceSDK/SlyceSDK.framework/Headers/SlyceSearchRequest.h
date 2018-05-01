#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SlyceSearchRequestMethod) {
    SlyceSearchRequestMethodWebSocket,
};

NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchRequest : NSObject <NSCoding>


/*!
 * @method
 *
 * @brief Initializes a new `SlyceSearchRequest` with the supplied `SlyceSearchRequestMethod`
 *
 * @discussion Use this method to create a new `SlyceSearchRequest`.
 *
 * @param method - The `SlyceSearchRequestMethod` to use.
 *
 * @return A `SlyceSearchRequest` instance.
 */
- (instancetype)initWithMethod:(SlyceSearchRequestMethod)method NS_DESIGNATED_INITIALIZER;


/*!
 * @property
 *
 * @abstract The time that the request was created.
 */
@property (nonatomic, strong, readonly) NSDate *timestamp;


#pragma mark Input Image


/*!
 * @property
 *
 * @abstract An optional UIImage that you wish to perform a visual search on.
 */
@property (nonatomic, strong, nullable) UIImage *image;


/*!
 * @property
 *
 * @abstract An optional URL of an image that you wish to perform a visual search on.
 */
@property (nonatomic, copy, nullable) NSString *imageURL;


/*!
 * @property
 *
 * @abstract An optional file path of an image that you wish to perform a visual search on.
 */
@property (nonatomic, copy, nullable) NSString *filePath;


/*!
 * @property
 *
 * @abstract An optional anchor point that indicates an area of interest within the supplied image.
 */
@property (nonatomic, assign) CGPoint anchor;

@end
NS_ASSUME_NONNULL_END
