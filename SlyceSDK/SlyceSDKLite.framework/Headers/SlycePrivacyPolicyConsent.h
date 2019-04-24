#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
__attribute__((objc_subclassing_restricted))
@interface SlycePrivacyPolicyConsent : NSObject

/**
 * @property
 * @abstract A string representing the body of this consent object.
 */
@property (nonatomic, copy, readonly) NSString *body;

/**
 * @property
 * @abstract A string representing the title of this consent object.
 */
@property (nonatomic, copy, readonly) NSString *title;

/**
 * @property
 * @abstract A string representing the call to action of this consent object.
 */
@property (nonatomic, copy, readonly) NSString *callToAction;

@end
NS_ASSUME_NONNULL_END
