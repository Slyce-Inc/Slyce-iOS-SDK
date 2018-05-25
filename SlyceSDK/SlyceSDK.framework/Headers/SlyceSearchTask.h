#import <Foundation/Foundation.h>

@class SlyceSearchTask;
@class SlyceSearchResult;
@class SlyceSearchRequest;
@class SlyceSearchResponse;
@class SlyceSession;
@class SlyceSearchResponseUpdate;


NS_ASSUME_NONNULL_BEGIN
@protocol SlyceSearchTaskListener <NSObject>

@optional
- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFinishWithResponse:(SlyceSearchResponse *)response
NS_SWIFT_NAME(slyce(searchTask:didFinishWithResponse:));

@optional
- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFailWithErrors:(NSArray<NSError *> *)errors
NS_SWIFT_NAME(slyce(searchTask:didFailWithErrors:));

@optional
- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didUpdateResponse:(SlyceSearchResponseUpdate *)update
NS_SWIFT_NAME(slyce(searchTask:didUpdate:));

@end
NS_ASSUME_NONNULL_END


NS_ASSUME_NONNULL_BEGIN
@protocol SlyceSearchTaskDelegate <SlyceSearchTaskListener>


/*!
 * @method
 *
 * @brief Notifies the `SlyceSearchTaskDelegate` that the `SlyceSearchTask` has finished.
 *
 * @discussion Once this message is received you will no longer get any notifications from this task.
 *
 * @param searchTask - The `SlyceSearchTask` instance that is being updated.
 * @param results - An array of `SlyceSearchResult` objects.
 * @param errors - An array of NSErrors.
 *
 */
@optional
- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFinishWithResults:(NSArray<SlyceSearchResult *> *)results errors:(NSArray<NSError *> *)errors
NS_SWIFT_NAME(slyce(searchTask:didFinishWithResults:errors:)) __deprecated;

@end
NS_ASSUME_NONNULL_END


NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchTask : NSObject

/*!
 * @property
 *
 * @brief The `SlyceSearchTaskDelegate` of this instance.
 *
 */
@property (nonatomic, weak, nullable) id<SlyceSearchTaskDelegate> delegate  __deprecated __deprecated_msg("SlyceSearchTaskDelegate functionality has been replaced by SlyceSearchTaskListener APIs and may be removed in a future release.");

/*!
 * @method
 *
 * @brief Adds the instance of `SlyceSearchTaskListener` as a listener on this instance of `SlyceSearchTask`.
 *
 * @param listener The instance of the listener to be added.
 *
 */
- (void)addListener:(id<SlyceSearchTaskListener>)listener;


/*!
 * @method
 *
 * @brief Removes the instance of `SlyceSearchTaskListener` as a listener on this instance of `SlyceSearchTask`.
 *
 * @param listener The instance of the listener to be removed.
 *
 */
- (void)removeListener:(id<SlyceSearchTaskListener>)listener;


/*!
 * @property
 *
 * @brief The unique identifier for this task.
 *
 */
@property (nonatomic, copy, readonly) NSString *identifier;

/*!
 * @property
 *
 * @brief The session that was used to create this task.
 *
 */
@property (nonatomic, readonly) SlyceSession *session;

/*!
 * @property
 *
 * @brief The `SlyceSearchRequest` represented by this task.
 *
 */
@property (nonatomic, readonly, strong) SlyceSearchRequest *request;

/*!
 * @property
 *
 * @brief The `SlyceSearchResponse` represented by this task.
 *
 * @discussion This property is only available after a task has successfully completed. Supports KVO.
 */
@property (nullable, nonatomic, readonly, strong) SlyceSearchResponse *response;

/*!
 * @property
 *
 * @brief An array of errors that have occurred. Supports KVO.
 *
 */
@property (nonatomic, readonly) NSArray<NSError *> *errors;

/*!
 * @method
 *
 * @brief Starts the search task.
 *
 * @discussion After you receive the `SlyceSearchTask` you must hold a strong reference to it, otherwise you may not receive the delegate notifications.
 *
 */
- (void)start;

@end
NS_ASSUME_NONNULL_END



typedef NS_ENUM(NSUInteger, SlyceSearchTaskUpdateType) {
    SlyceSearchTaskUpdateTypeTagFound,
    SlyceSearchTaskUpdateTypeResultsReceived,
};


NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchResponseUpdate : NSObject

@property (nonatomic, readonly) SlyceSearchResponse *response;
@property (nonatomic, readonly) NSDate *timestamp;
@property (nonatomic, readonly) SlyceSearchTaskUpdateType type;

@property (nonatomic, readonly, nullable) id value;

@end
NS_ASSUME_NONNULL_END
