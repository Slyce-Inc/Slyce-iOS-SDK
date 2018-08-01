#import "SlyceBase.h"

#import <UIKit/UIKit.h>


@class SlyceSearchParameters;


NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchRequest : NSObject <NSCoding>

/*!
 * @method
 *
 * @brief Initializes a new `SlyceSearchRequest`.
 *
 * @discussion Use this method to create a new `SlyceSearchRequest`.
 *
 * @param image - The `UIImage` to be used for this search request.
 * @param anchor - The focal point to be used for this search request.
 * @param searchParameters - Nullable `SlyceSearchParameters` for this search request.
 *
 * @return A `SlyceSearchRequest` instance.
 */
- (instancetype)initWithImage:(UIImage *)image
                       anchor:(CGPoint)anchor
             searchParameters:(nullable SlyceSearchParameters *)searchParameters NS_DESIGNATED_INITIALIZER;


/*!
 * @method
 *
 * @brief Initializes a new `SlyceSearchRequest`.
 *
 * @discussion Use this method to create a new `SlyceSearchRequest`.
 *
 * @param image - The `UIImage` to be used for this search request.
 * @param searchParameters - Nullable `SlyceSearchParameters` for this search request.
 *
 * @return A `SlyceSearchRequest` instance.
 */
- (instancetype)initWithImage:(UIImage *)image
             searchParameters:(nullable SlyceSearchParameters *)searchParameters;

/*!
 * @method
 *
 * @brief Initializes a new `SlyceSearchRequest` for an image URL and anchor.
 *
 * @discussion Use this method to create a new `SlyceSearchRequest`.
 *
 * @param imageURL - An NSString representing the URL of an image to be used for this search request.
 * @param anchor - The focal point to be used for this search request.
 * @param searchParameters - Nullable `SlyceSearchParameters` for this search request.
 *
 * @return A `SlyceSearchRequest` instance.
 */
- (instancetype)initWithImageURL:(NSString *)imageURL
                          anchor:(CGPoint)anchor
                searchParameters:(nullable SlyceSearchParameters *)searchParameters __deprecated_msg("Searching an image URL with an anchor is currently not supported, please use `initWithImageURL:searchParameters` instead.");

/*!
 * @method
 *
 * @brief Initializes a new `SlyceSearchRequest` for an image URL.
 *
 * @discussion Use this method to create a new `SlyceSearchRequest`.
 *
 * @param imageURL - An NSString representing the URL of an image to be used for this search request.
 * @param searchParameters - Nullable `SlyceSearchParameters` for this search request.
 *
 * @return A `SlyceSearchRequest` instance.
 */
- (instancetype)initWithImageURL:(NSString *)imageURL
                searchParameters:(nullable SlyceSearchParameters *)searchParameters NS_DESIGNATED_INITIALIZER;

/*!
 * @property
 *
 * @abstract The time that the request was created.
 */
@property (nonatomic, strong, readonly) NSDate *timestamp;


/*!
 * @property
 *
 * @abstract The ISO 639-1 alpha-2 language code for this request.
 */
@property (nonatomic, readonly, nullable) NSString *languageCode;


/*!
 * @property
 *
 * @abstract The ISO 3166-1 alpha-2 country code for this request.
 */
@property (nonatomic, readonly, nullable) NSString *countryCode;


/*!
 * @property
 *
 * @abstract Gets demo mode setting.
 *
 * @discussion If demo mode is enabled, some of the more time consuming operations will be disabled. This also clients to receive faster, but less accurate results while integrating the SlyceSDK. Demo mode should not be enabled in your production application.
 */
@property (nonatomic, readonly) BOOL demoMode;


#pragma mark Input Image


/*!
 * @property
 *
 * @abstract The image related to this search request.
 *
 * @discussion Before this request is queued on a search task,
 * this property will return the original image the request was created with.
 * Once a task has been queued, this propery will return a down-scaled version of the original image.
 */
@property (nonatomic, readonly, nullable) UIImage *image;


/*!
 * @property
 *
 * @abstract An optional URL of an image that you wish to perform a visual search on.
 */
@property (nonatomic, readonly, nullable) NSString *imageURL;


/*!
 * @property
 *
 * @abstract An optional anchor point that indicates an area of interest within the supplied image.
 *
 * @discussion This property will always return an anchor point correctly scaled to the `image` property.
 * Before the search request is queue, this will return the original anchor.
 * After the search request is queueud, this will return an anchor properly scaled to the `image` property.
 */
@property (nonatomic, readonly) CGPoint anchor;

@end
NS_ASSUME_NONNULL_END
