#import <Foundation/Foundation.h>

@class Slyce;
@class SlyceSession;
@class SlyceSearchTask;
@class SlyceSearchRequest;
@class SlyceScanner;
@class SlyceLensConfiguration;
@protocol SlyceSessionDelegate;
@protocol SlyceSearchTaskListener;


NS_ASSUME_NONNULL_BEGIN
@protocol SlyceSessionListener <NSObject>

/*!
 * @method
 *
 * @brief Implement this method in order to be notified when the session creates `SlyceSearchTask`'s.
 *
 * @param session - The `SlyceSession` instance that has sent this message.
 * @param searchTask - The `SlyceSearchTask` that has been created.
 *
 */
@optional
- (void)slyceSession:(SlyceSession *)session willStartSearchTask:(SlyceSearchTask *)searchTask NS_SWIFT_NAME(slyce(session:willStart:));

/*!
 * @method
 *
 * @brief Implement this method in order to be notified when the session has completed a `SlyceSearchTask`.
 *
 * @param session - The `SlyceSession` instance that has sent this message.
 * @param searchTask - The `SlyceSearchTask` that has finished.
 *
 */
@optional
- (void)slyceSession:(SlyceSession *)session didFinishSearchTask:(SlyceSearchTask *)searchTask NS_SWIFT_NAME(slyce(session:didFinish:));

@end


@interface SlyceSession : NSObject

/*!
 * @method
 *
 * @brief The static initializer for `SlyceSession`. Use this to create your own instance of a SlyceSession.
 *
 * @discussion In most cases you can use the `defaultSession` on `Slyce`.
 *
 * @param slyce - An opened instance of `Slyce`.
 * @param outError - A pointer to an error that will be assigned if a problem occurs.
 *
 */
+ (nullable instancetype)sessionWithSlyce:(Slyce *)slyce error:(SlyceOutError)outError;

/*!
 * @method
 *
 * @brief Adds the instance of `SlyceSessionListener` as a listener on this instance of `SlyceSession`.
 *
 * @param listener The instance of the listener to be added.
 *
 */
- (void)addListener:(id<SlyceSessionListener>)listener
NS_SWIFT_NAME(addListener(_:));

/*!
 * @method
 *
 * @brief Removes the instance of `SlyceSessionListener` as a listener on this instance of `SlyceSession`.
 *
 * @param listener The instance of the listener to be removed.
 *
 */
- (void)removeListener:(id<SlyceSessionListener>)listener
NS_SWIFT_NAME(removeListener(_:));

/*!
 * @method
 *
 * @brief Invalidates the session, all active tasks will be canceled.
 *
 */
- (void)invalidate;

/*!
 * @property
 *
 * A flag indicating the validity of this session instance.
 */
@property (nonatomic, readonly) BOOL isInvalidated;

#pragma mark - SlyceSearchTask

/*!
 * @method
 *
 * @brief Creates and starts a search task based on the provided request and workflow identifier.
 *
 * @param searchRequest - The search request.
 * @param workflowIdentifier - The identifier of the workflow to use.
 * @param listener - A listener to add to the task. Nullable.
 *
 * @return a new `SlyceSearchTask` for the request and workflow identifier.
 */
- (nullable SlyceSearchTask *)startSearchTaskWithRequest:(SlyceSearchRequest *)searchRequest workflowIdentifier:(NSString *)workflowIdentifier listener:(nullable id<SlyceSearchTaskListener>)listener
NS_SWIFT_NAME(startSearchTask(request:workflowIdentifier:listener:));

/*!
 * @property
 *
 * @brief Gets all `SlyceSearchTask` objects that have been started and not yet completed.
 *
 @ @return A copy of all active `SlyceSearchTask` objects.
 */
@property (nonatomic, readonly, copy) NSArray<SlyceSearchTask *> *searchTasks;

/*!
 * @method
 *s
 * @brief Gets the task with the provided task identifier.
 *
 * @param taskIdentifier - The identifier of the task to get.
 *
 * @return the corresponding task, or null if not found.
 */
- (nullable SlyceSearchTask *)getSearchTaskByIdentifier:(NSString *)taskIdentifier NS_SWIFT_NAME(getSearchTask(identifier:));

/*!
 * @method
 *
 * @brief Cancels all tasks within this session.
 */
- (void)cancelAllTasks;


#pragma mark -
#pragma mark Deprecated Methods

/*!
 * @property
 *
 * The object that acts as the delegate of the session.
 *
 * @deprecated in version 5.1.0
 */
@property (nonatomic, weak, nullable) id<SlyceSessionDelegate> delegate __deprecated_msg("SlyceSessionDelegate has been replaced by SlyceSessionListener APIs and may be removed in a future release.");

/*!
 * @method
 *
 * @brief Creates a search task based on the provided request and workflow identifier.
 *
 * @param searchRequest - The search request.
 * @param workflowIdentifier - The identifier of the workflow to use.
 *
 * @return a new `SlyceSearchTask` for the request and workflow identifier.
 
 */
- (nullable SlyceSearchTask *)searchTaskWithRequest:(SlyceSearchRequest *)searchRequest workflowIdentifier:(NSString *)workflowIdentifier NS_SWIFT_NAME(searchTask(request:workflowIdentifier:)) __deprecated_msg("Use 'startSearchTaskWithRequest:workflowIdentifier:listener:' instead.");

/*!
 * @method
 *
 * @brief Cancels the task with the provided task identifier.
 *
 * @param taskIdentifier - The ID of the task to cancel.
 *
 * @deprecated in version 5.1.0
 */
- (void)cancelSearchTaskWithIdentifier:(NSString *)taskIdentifier NS_SWIFT_NAME(cancelSearchTask(identifier:)) __deprecated;


@end
NS_ASSUME_NONNULL_END


NS_ASSUME_NONNULL_BEGIN
@protocol SlyceSessionDelegate <SlyceSessionListener>
    
/*!
 * @method
 *
 * @brief Implement this method in order to be notified when the session creates `SlyceSearchTask`'s.
 *
 * @param session - The `SlyceSession` instance that has sent this message.
 * @param searchTask - The `SlyceSearchTask` that has been created.
 *
* @deprecated as of 5.1.0
*/
- (void)slyceSession:(SlyceSession *)session didCreateSearchTask:(SlyceSearchTask *)searchTask NS_SWIFT_NAME(slyce(session:didCreateSearchTask:)) __deprecated_msg("Use `slyceSession:willStartSearchTask:` instead");
    
@end
NS_ASSUME_NONNULL_END
