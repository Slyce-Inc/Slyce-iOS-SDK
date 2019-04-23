#import <UIKit/UIKit.h>

@protocol SlyceCameraControls;
@class SlyceLensSettings;
@class SlyceSession;


NS_ASSUME_NONNULL_BEGIN
@interface SlyceLensView : UIView

/*!
 *  @method
 *
 *  @brief Initializes a new Slyce object using valid Account Identifier, API Key, and Space Identifier.
 *
 *  @discussion Use this method to open the SDK for 'Public' recognition functionality.
 *
 *  @param session An instance of `SlyceSession`.
 *  @param lensIdentifier The identifier of the lens to be used by this instance.
 *  @param options TODO:
 *  @param outError An error that is assigned if an instance of `SlyceLensView` cannot be created.
 *
 */
+ (nullable instancetype)lensViewWithSession:(SlyceSession *)session
                              lensIdentifier:(NSString *)lensIdentifier
                                    options:(nullable NSDictionary<NSString *, id> *)options
                                       error:(SlyceOutError)outError;

/*!
 *  @method
 *
 *  @brief Initializes a new Slyce object using valid Account Identifier, API Key, and Space Identifier.
 *
 *  @discussion Use this method to open the SDK for 'Public' recognition functionality.
 *
 *  @param session An instance of `SlyceSession`.
 *  @param lensIdentifier The identifier of the lens to be used by this instance.
 *  @param options TODO:
 *  @param settings An optional `SlyceLensConfiguration` object.
 *  @param outError An error that is assigned if an instance of `SlyceLensView` cannot be created.
 *
 */
+ (nullable instancetype)lensViewWithSession:(SlyceSession *)session
                              lensIdentifier:(NSString *)lensIdentifier
                                     options:(nullable NSDictionary<NSString *, id> *)options
                                    settings:(nullable SlyceLensSettings *)settings
                                       error:(SlyceOutError)outError;



/**
 * @property
 *
 * @abstract The identifier of the lens used by this instance.
 *
 */
@property (nonatomic, readonly) NSString *lensIdentifier;

/**
 * @property
 *
 * @abstract The `SlyceLensSettings` used to configure this instance.
 *
 */
@property (nonatomic, readonly) SlyceLensSettings *lensSettings;



#pragma mark Camera

/**
 * @property
 *
 * @abstract The `SlyceCameraControls` for this instance.
 *
 */
@property (nonatomic, readonly) id<SlyceCameraControls> camera;


#pragma mark Local Detection

/*!
 *  @method
 *
 *  @brief Suspends result detection of the underlying scanner.
 *
 */
- (void)suspendDetection;

/*!
 *  @method
 *
 *  @brief Resumes result detection of the underlying scanner.
 *
 */
- (void)resumeDetection;

/*!
 *  @method
 *
 *  @brief Yes is the underlying scanner is suspended.
 *
 */
- (BOOL)isDetectionSuspended;


#pragma mark Animations

/*!
 *  @method
 *
 *  @brief Resets the animation view to its default state.
 *
 */
- (void)resetAnimations;


#pragma mark Deprecated


/*!
 *  @method
 *
 *  @brief Initializes a new Slyce object using valid Account Identifier, API Key, and Space Identifier.
 *
 *  @discussion Use this method to open the SDK for 'Public' recognition functionality.
 *
 *  @param session An instance of `SlyceSession`.
 *  @param lensIdentifier The identifier of the lens to be used by this instance.
 *  @param lensConfiguration An optional `SlyceLensConfiguration` object.
 *  @param outError An error that is assigned if an instance of `SlyceLensView` cannot be created.
 *
 */
+ (nullable instancetype)lensViewWithSession:(SlyceSession *)session
                              lensIdentifier:(NSString *)lensIdentifier
                           lensConfiguration:(nullable SlyceLensSettings *)lensConfiguration
                                       error:(SlyceOutError)outError __deprecated_msg("Use lensViewWithSession:lensIdentifier:settings:error: instead");


/**
 * @property
 *
 * @abstract The `SlyceSession` used to configure this instance.
 *
 */
@property (nonatomic, readonly) SlyceSession *session;


/**
 * @property
 *
 * @abstract The `SlyceLensConfiguration` used to configure this instance.
 *
 */
@property (nonatomic, readonly) SlyceLensSettings *lensConfiguration __deprecated_msg("lensConfiguration has been renamed to lensSettings");

@end
NS_ASSUME_NONNULL_END

