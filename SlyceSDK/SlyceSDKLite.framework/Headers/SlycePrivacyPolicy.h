#import <Foundation/Foundation.h>
#import "SlycePrivacyPolicyConsent.h"
#import "SlycePrivacyPolicyLink.h"

NS_ASSUME_NONNULL_BEGIN
__attribute__((objc_subclassing_restricted))
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
 * @abstract An array of `SlycePrivacyPolicyConsent` objects.
 */
@property (nonatomic, strong, readonly) NSArray<SlycePrivacyPolicyConsent *> *consents;

/**
 * @property
 * @abstract An array of SlycePrivacyPolicyLinkObjects.
 */
@property (nonatomic, strong, readonly) NSArray<SlycePrivacyPolicyLink *> *links;
@end
NS_ASSUME_NONNULL_END
