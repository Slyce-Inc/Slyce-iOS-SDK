#import "SlyceBase.h"

__attribute__((objc_subclassing_restricted))
@interface SlyceSearchParameters : NSObject <NSCopying>

/*!
 * @property
 *
 * @abstract The ISO 639-1 alpha-2 language code for this request.
 */
@property (nonatomic, copy, nullable) NSString *languageCode;

/*!
 * @property
 *
 * @abstract The ISO 3166-1 alpha-2 country code for this request.
 */
@property (nonatomic, copy, nullable) NSString *countryCode;

/*!
 * @property
 *
 * @abstract Arbitrary options to pass to the workflow.
 *
 * @discussion All values in this dictionary must be JSON-compatible. The dictionary is deep-copied on assignment.
 */
@property (nonatomic, copy, nullable) NSDictionary<NSString *, id> *workflowOptions;

/*!
 * @property
 *
 * @abstract Enables demo mode.
 *
 * @discussion If demo mode is enabled, some of the more time consuming operations will be disabled. This allows clients to receive faster, but less accurate results while integrating the SlyceSDK. Demo mode should not be enabled in your production application.
 */
@property (nonatomic, assign) BOOL demoMode;

@end
