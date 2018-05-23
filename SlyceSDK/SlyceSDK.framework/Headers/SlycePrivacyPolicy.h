#import <Foundation/Foundation.h>
#import "SlyceConsent.h"
#import "SlyceLink.h"

NS_ASSUME_NONNULL_BEGIN
@interface SlycePrivacyPolicy : NSObject

/**
 * @property
 * @abstract A string representing the description of the privacy policy.
 */
@property (nonatomic, copy, readonly) NSString *policyDescription;

/**
 * @property
 * @abstract A string representing the title of the privacy policy.
 */
@property (nonatomic, copy, readonly) NSString *title;

/**
 * @property
 * @abstract An array of `SlyceConsent` objects.
 */
@property (nonatomic, strong, readonly) NSArray<SlyceConsent *> *consents;

/**
 * @property
 * @abstract An array of SlyceLinkObjects.
 */
@property (nonatomic, strong, readonly) NSArray<SlyceLink *> *links;
@end
NS_ASSUME_NONNULL_END
