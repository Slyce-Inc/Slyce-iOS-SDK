#import <Foundation/Foundation.h>

#import "SlyceImageMatchingSyncDelegate.h"
#import "SlyceSession.h"

/*
 Main Slyce workflow entry point
 */
NS_ASSUME_NONNULL_BEGIN
@interface Slyce : NSObject

+ (instancetype)shared;


/*!
 *  @method
 *
 *  @brief Initializes a new Slyce object using valid AccountID, SpaceID, and API Key.
 *
 *  @discussion Use this method to open the SDK for 'Public' recognition functionality.
 *
 *  @param accountID the Account ID for your organization.
 *  @param spaceID the Space ID for this SlyceInstance.
 *  @param apiKey the API Key for your organization.
 *  @param completion the completion block.
 *
 *  **Important:** Successfully opening the Slyce object is mandatory before you start
 *  performing any tasks in the SDK!
 *
 */
- (void)openWithAccountID:(NSString *)accountID spaceID:(NSString *)spaceID apiKey:(NSString *)apiKey completion:(void (^)(NSError * _Nullable))completion
NS_SWIFT_NAME(open(accountID:spaceID:apiKey:completion:));

/*!
 * @method
 *
 * @brief Closes this instance of Slyce.
 */
- (void)close;


- (SlyceSession *)defaultSession;

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

@end
NS_ASSUME_NONNULL_END

typedef Slyce SFSlyce __deprecated __deprecated_msg("Use 'Slyce' instead.");
