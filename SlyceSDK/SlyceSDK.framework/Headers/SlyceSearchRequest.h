#import <UIKit/UIKit.h>

#import "SlyceSearchRequestMethod.h"

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
 * @return A `SlyceSearchRequest` instance.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

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
             searchParameters:(nullable SlyceSearchParameters *)searchParameters;

/*!
 * @method
 *
 * @brief Initializes a new `SlyceSearchRequest` with the supplied `SlyceSearchRequestMethod`
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
                searchParameters:(nullable SlyceSearchParameters *)searchParameters;

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
- (instancetype)initWithMethod:(SlyceSearchRequestMethod)method __deprecated_msg("Specifying the `SlyceSearchRequestMethod` here is no longer supported.");


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
 * @abstract An optional UIImage that you wish to perform a visual search on.
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
 * @abstract An optional file path of an image that you wish to perform a visual search on.
 */
//@property (nonatomic, readonly, nullable) NSString *filePath;


/*!
 * @property
 *
 * @abstract An optional anchor point that indicates an area of interest within the supplied image.
 */
@property (nonatomic, readonly) CGPoint anchor;



@end
NS_ASSUME_NONNULL_END
