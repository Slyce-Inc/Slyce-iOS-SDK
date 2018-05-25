#import <Foundation/Foundation.h>

@class SlycePrivacyPolicy;

NS_ASSUME_NONNULL_BEGIN
@interface SlyceGDPRComplianceManager : NSObject

/**
 * @property
 * @abstract Sets the flag indicating that this user must accept GDPR terms for Slyce.
 * @discussion This flag must be set _before_ opening a Slyce instance. Only set this for users covered by GDPR.
 * @default NO
 */
@property (nonatomic, assign) BOOL userRequiresGDPRCompliance;

/**
 * @property
 * @abstract A reference to the `SlycePrivacyPolicy` object which contains the GDPR terms for Slyce.
 * @discussion This property is only available _after_ Slyce has been opened.
 * @default NO
 */
@property (nonatomic, strong, nullable, readonly) SlycePrivacyPolicy *privacyPolicy;

/*!
 * @method
 *
 * @brief The identifier representing the user in the host application.
 *
 * @discussion The host application must set the user identifier to enable cross-device compliance with GDPR.
 */
- (void)setUserIdentifier:(NSString *)userIdentifier;

/*!
 * @method
 *
 * @brief Informs Slyce that a user has accepted the terms of the given `SlycePrivacyPolicy`
 *
 * @discussion The `SlycePrivacyPolicy` can be obtained from an instance of `SlyceGDPRComplianceManager`.
 *
 * @param privacyPolicy the `SlycePrivacyPolicy` that the user has agreed to.
 */
- (void)setUserConsentedToPrivacyPolicy:(SlycePrivacyPolicy *)privacyPolicy;

/*!
 * @method
 *
 * @brief Tells Slyce to forget the user.
 *
 * @discussion Tells Slyce to forget the user and opt-out of privacy policy so they will be prompted to opt-in next time they utilize Slyce
 * @param completion A completion block that informs if the request to forget the user was _received_ successfully, an error is passed when the request fails. If a request fails, you must prompt the user to run the request again.
 */
- (void)optOutAndForgetUser:(void (^)(NSError * _Nullable))completion;

@end
NS_ASSUME_NONNULL_END
