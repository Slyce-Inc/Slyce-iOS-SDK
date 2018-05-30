#import <Foundation/Foundation.h>

@class SlyceSearchTask;
@class SlyceSearchResult;
@class SlyceSearchRequest;
@class SlyceSearchResponse;
@class SlyceSession;
@class SlyceSearchResponseUpdate;
@protocol SlyceSearchTaskDelegate;


NS_ASSUME_NONNULL_BEGIN
@protocol SlyceSearchTaskListener <NSObject>

/*!
 * @method
 *
 * @brief Notifies all listeners that the `SlyceSearchTask` has finished sucessfully.
 *
 * @discussion Once this message is received you will no longer get any notifications from this task.
 *
 * @param searchTask - The `SlyceSearchTask` instance that is being updated.
 * @param response - The final `SlyceSearchResponse` object.
 */
@optional
- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFinishWithResponse:(SlyceSearchResponse *)response
NS_SWIFT_NAME(slyce(searchTask:didFinishWith:));

/*!
 * @method
 *
 * @brief Notifies all listeners that the `SlyceSearchTask` has failed with errors.
 *
 * @discussion Once this message is received you will no longer get any notifications from this task.
 *
 * @param searchTask - The `SlyceSearchTask` instance that is being updated.
 * @param errors - An array of errors. This will not be nil and contain at least one error.
 */
@optional
- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFailWithErrors:(NSArray<NSError *> *)errors
NS_SWIFT_NAME(slyce(searchTask:didFailWith:));

/*!
 * @method
 *
 * @brief Notifies all listeners that the `SlyceSearchTask` has failed with errors.
 *
 * @discussion Once this message is received you will no longer get any notifications from this task.
 *
 * @param searchTask - The `SlyceSearchTask` instance that is being updated.
 * @param update - A `SlyceSearchResponseUpdate` object which describes the kind of update and the value changed.
 */
@optional
- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didReceiveSearchResponseUpdate:(SlyceSearchResponseUpdate *)searchResponseUpdate
NS_SWIFT_NAME(slyce(searchTask:didReceive:));

@end
NS_ASSUME_NONNULL_END


NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchTask : NSObject

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
 * @brief The unique identifier for this task.
 *
 * @discussion This identifier is generated locally when the task is created, and not related to any backend services.
 *
 */
@property (nonatomic, copy, readonly) NSString *identifier;

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
 * @discussion An empty `SlyceSearchResponse` object will be created when this task is started. As information related to the task, such as tags and results, become available it will be appended to the task.
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
 * @brief Cancels this task
 */
- (void)cancel;


#pragma mark Listeners

/*!
 * @method
 *
 * @brief Adds the instance of `SlyceSearchTaskListener` as a listener on this instance of `SlyceSearchTask`.
 *
 * @param listener The instance of the listener to be added.
 *
 */
- (void)addListener:(id<SlyceSearchTaskListener>)listener
NS_SWIFT_NAME(addListener(_:));

/*!
 * @method
 *
 * @brief Removes the instance of `SlyceSearchTaskListener` as a listener on this instance of `SlyceSearchTask`.
 *
 * @param listener The instance of the listener to be removed.
 *
 */
- (void)removeListener:(id<SlyceSearchTaskListener>)listener
NS_SWIFT_NAME(removeListener(_:));


#pragma mark Deprecated

/*!
 * @method
 *
 * @brief Starts the search task.
 *
 */
- (void)start __deprecated_msg("Use SlyceSession:startSearchTask method instead.");


/*!
 * @property
 *
 * @brief The `SlyceSearchTaskDelegate` of this instance.
 *
 */
@property (nonatomic, weak, nullable) id<SlyceSearchTaskDelegate> delegate  __deprecated_msg("SlyceSearchTaskDelegate functionality has been replaced by SlyceSearchTaskListener APIs and may be removed in a future release.");

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

