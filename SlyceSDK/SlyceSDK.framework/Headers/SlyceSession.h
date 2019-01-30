#import "SlyceBase.h"

@class Slyce;
@class SlyceSession;
@class SlyceSearchTask;
@class SlyceSearchRequest;
@class SlyceSearchParameters;
@class SlyceDetectionDescriptor;
@class SlyceSearchImage;
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


/*!
 * @method
 *
 * @brief Implement this method in order to be notified when the session has performed a local detection, such as a barcode
 *
 * @param session - The `SlyceSession` instance that has sent this message.
 * @param detection - A `SlyceDetectionDescriptor` that describes the detection.
 *
 */
@optional
- (void)slyceSession:(SlyceSession *)session didPerformDetection:(SlyceDetectionDescriptor *)detection NS_SWIFT_NAME(slyce(session:didPerformDetection:));

@end


__attribute__((objc_subclassing_restricted))
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
 * @property
 *
 * The object that acts as the delegate of the session.
 *
 */
@property (nonatomic, weak, nullable) id<SlyceSessionDelegate> delegate;


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
 * @method
 *
 * @brief Creates and starts a search task based on the provided request and workflow identifier.
 *
 * @param searchRequest - The search request.
 * @param workflowName - The name of the workflow to use, for example, `SlyceWorkflowName3D` or `SlyceWorkflowNameFindSimilar`.
 * @param listener - A listener to add to the task. Nullable.
 *
 * @see SlyceWorkflowNames
 *
 * @return a new `SlyceSearchTask` for the request and workflow identifier.
 */
- (nullable SlyceSearchTask *)startSearchTaskWithRequest:(SlyceSearchRequest *)searchRequest workflowName:(NSString *)workflowName listener:(nullable id<SlyceSearchTaskListener>)listener error:(SlyceOutError)outError
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

/*!
 * @property
 *
 * The `SlyceSearchParameters` for all requests in this session.
 *
 */
@property (nonatomic, copy, nullable) SlyceSearchParameters *defaultSearchParameters;




@end
NS_ASSUME_NONNULL_END


NS_ASSUME_NONNULL_BEGIN
@protocol SlyceSessionDelegate <NSObject>

@optional
- (nullable SlyceSearchParameters *)slyceSession:(SlyceSession *)session searchParametersForImage:(SlyceSearchImage *)searchImage NS_SWIFT_NAME(slyce(session:searchParametersForImage:));


@end
NS_ASSUME_NONNULL_END
