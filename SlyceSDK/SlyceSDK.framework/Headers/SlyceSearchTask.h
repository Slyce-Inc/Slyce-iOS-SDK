#import <Foundation/Foundation.h>

@class SlyceSearchTask;
@class SlyceSearchResult;
@class SlyceSearchRequest;
@class SlyceSearchResponse;
@class SlyceSession;

NS_ASSUME_NONNULL_BEGIN
@protocol SlyceSearchTaskDelegate <NSObject>


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
- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFinishWithResults:(NSArray<SlyceSearchResult *> *)results errors:(NSArray<NSError *> *)errors
NS_SWIFT_NAME(slyce(searchTask:didFinishWithResults:errors:));

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
@property (nonatomic, weak, nullable) id<SlyceSearchTaskDelegate> delegate;

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
