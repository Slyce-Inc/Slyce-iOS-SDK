#import <Foundation/Foundation.h>

@class SlyceSearchTask;
@class SlyceSearchResult;
@class SlyceSearchRequest;
@class SlyceSearchProgress;
@class SlyceSearchResponse;

NS_ASSUME_NONNULL_BEGIN

@protocol SlyceSearchTaskDelegate <NSObject>


/*!
 * @method
 *
 * @brief Notifies the `SlyceSearchTaskDelegate` that the `SlyceSearchTask` has updated.
 *
 * @param searchTask - The `SlyceSearchTask` instance that is being updated.
 * @param progress - A `SlyceSearchProgress` object that contains progress information.
 *
 */
- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didUpdateWithProgress:(SlyceSearchProgress *)progress
NS_SWIFT_NAME(slyce(searchTask:didUpdateWithProgress:));


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
NS_SWIFT_NAME(slyce(searchTask:didFinishWithResult:errors:));

@end


@interface SlyceSearchTask : NSObject <NSCoding>

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
 * @brief The `SlyceSearchRequest` represented by this task.
 *
 */
@property (nonatomic, copy, readonly) NSString *identifier;
@property (nonatomic, copy, readonly) NSString *sessionIdentifier;

/*!
 * @property
 *
 * @brief The `SlyceSearchRequest` represented by this task.
 *
 */
@property (nonatomic, strong) SlyceSearchRequest *request;

/*!
 * @property
 *
 * @brief The `SlyceSearchResponse` represented by this task.
 *
 * @discussion This property is only available after a task has successfully completed.
 */
@property (nonatomic, strong, nullable) SlyceSearchResponse *response;

/*!
 * @property
 *
 * @brief The `SlyceSearchProgress` represented by this task.
 *
 */
@property (nullable, nonatomic, strong) SlyceSearchProgress *progress;
/*!
 * @property
 *
 * @brief An array of errors that have occurred.
 *
 */
@property (nonatomic, strong, readonly) NSArray<NSError *> *errors;

/*!
 * @method
 *
 * @brief Starts the search task.
 *
 * @discussion After you receive the `SlyceSearchTask` you must hold a strong reference to it, otherwise you may not reveive the delegate notifications.
 *
 */
- (void)start;

@end

NS_ASSUME_NONNULL_END
