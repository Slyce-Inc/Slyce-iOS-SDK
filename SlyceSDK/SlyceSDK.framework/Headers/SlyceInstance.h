#import "SlyceBase.h"

#import "SlyceImageMatchingSyncDelegate.h"

@class SlyceSearchParameters;
@class SlyceSession;
@class SlyceCredentials;
@class SlyceGDPRComplianceManager;
@protocol SlyceEventTracker;
@protocol SlyceImageMatchingSyncDelegate;

extern _Nonnull NSNotificationName const SlyceDidOpenNotification;
extern _Nonnull NSNotificationName const SlyceWillCloseNotification;
extern _Nonnull NSNotificationName const SlyceDidCloseNotification;

/*
 Main Slyce workflow entry point
 */
NS_ASSUME_NONNULL_BEGIN
__attribute__((objc_subclassing_restricted))
@interface Slyce : NSObject

+ (instancetype)shared;


/*!
 *  @method
 *
 *  @brief Initializes a new Slyce object using valid Account Identifier, API Key, and Space Identifier.
 *
 *  @discussion Use this method to open the SDK for 'Public' recognition functionality. On success, this will also post a `SlyceDidOpenNotification`.
 *
 *  @param accountIdentifier the Account Identifier for your organization.
 *  @param apiKey the API Key for your organization.
 *  @param spaceIdentifier the Space Identifier for this SlyceInstance.
 *  @param completion the completion block. This will always be returned on the main queue.
 *
 *  **Important:** Successfully opening the Slyce object is mandatory before you start
 *  performing any tasks in the SDK!
 *
 */
- (void)openWithAccountIdentifier:(NSString *)accountIdentifier apiKey:(NSString *)apiKey spaceIdentifier:(NSString *)spaceIdentifier completion:(void (^)(NSError * _Nullable))completion
NS_SWIFT_NAME(open(accountIdentifier:apiKey:spaceIdentifier:completion:));

/*!
 * @property
 *
 * @brief Returns a `SlyceCredentials` object if Slyce is authenticated and open. nil otherwise.
 */
@property (nonatomic, readonly, nullable) SlyceCredentials *credentials;

/*!
 * @method
 *
 * @brief Returns Slyce "open" status.
 */
- (BOOL)isOpen;

/*!
 * @method
 *
 * @brief Closes this instance of Slyce.
 *
 * @discussion Posts a `SlyceWillCloseNotification` before begining to close, and a `SlyceDidCloseNotification` after close completes.
 */
- (void)close;

/*!
 * @property
 * @brief The default `SlyceSession`.
 * @discussion The default `SlyceSession`. The default session cannot be manually invalidated, but will be invalidated when `Slyce` is closed.
 * @return A `SlyceSession` instance.
 */
@property (nonatomic, readonly, nullable) SlyceSession *defaultSession __deprecated_msg("The default session is deprecated and will be removed in a future release. Sessions may be created using the SlyceSession.sessionWithSlyce method.");

/*!
 * @property
 *
 * The `SlyceSearchParameters` for all requests in this Slyce instance..
 *
 */
@property (nonatomic, copy, nullable) SlyceSearchParameters *defaultSearchParameters;

/**
 * @property
 * @abstract 2D catalogs sync delegate
 * @discussion This object will receive updates about the 2D catalogs sync progress
 */
@property (nonatomic, weak, nullable) id<SlyceImageMatchingSyncDelegate> imageMatchingSyncDelegate;


#pragma mark Analytics

/**
 * @property
 * @abstract Enables or disables analytics
 * @default YES
 */
@property (nonatomic) BOOL analyticsEnabled;

/**
 * @property
 * @abstract Include location information with analytics, if available.
 * @default YES
 */
@property (nonatomic) BOOL analyticsShouldIncludeLocationInformation;

/**
 * @property
 * @abstract An instance of `SlyceEventTracker` for posting events that occur inside of or outside of the SlyceSDK.
 */
@property (nonatomic, readonly) id<SlyceEventTracker> eventTracker;

/**
 * @property
 * @abstract An instance of `SlyceGDPRComplianceManager` for handling GDPR compliance within Slyce.
 */
@property (nonatomic, readonly) SlyceGDPRComplianceManager *complianceManager;

@end
NS_ASSUME_NONNULL_END
