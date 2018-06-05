#import <Foundation/Foundation.h>

@interface SlyceSearchParameters : NSObject

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
 */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, id> *workflowOptions;

@end
