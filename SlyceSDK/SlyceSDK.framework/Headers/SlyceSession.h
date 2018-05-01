#import <Foundation/Foundation.h>

#import "SlyceSearchTask.h"
#import "SlyceSearchRequest.h"
#import "SlyceScanner.h"
#import "SlyceLensConfiguration.h"


NS_ASSUME_NONNULL_BEGIN
@protocol SlyceSessionDelegate <NSObject>

/*!
 * @method
 *
 * @brief Implement this method in order to be notified when the session creates `SlyceSearchTask`'s.
 *
 * @param session - The `SlyceSession` instance that has sent this message.
 * @param searchTask - The `SlyceSearchTask` that has been created.
 *
 */
- (void)slyceSession:(SlyceSession *)session didCreateSearchTask:(SlyceSearchTask *)searchTask NS_SWIFT_NAME(slyce(session:didCreateTask:));

@end

@interface SlyceSession : NSObject


/*!
 * @property
 *
 * The `SlyceSessionDelegate` assigned to this insance.
 */
@property (nonatomic, weak, nullable) id<SlyceSessionDelegate> delegate;


#pragma mark - SlyceSearchTask

/*!
 * @method
 *
 * @brief Builds a search task based on the provided request and workflow identifier.
 *
 * @param searchRequest - The search request.
 * @param workflowIdentifier - The identifier of the workflow to use.
 *
 * @return a new `SlyceSearchTask` for the request and workflow identifier.
 */
- (nullable SlyceSearchTask *)searchTaskWithRequest:(SlyceSearchRequest *)searchRequest workflowIdentifier:(NSString *)workflowIdentifier NS_SWIFT_NAME(searchTask(request:workflowIdentifier:));


/*!
 * @method
 *
 * @brief Cancels all tasks within this session.
 */
- (void)cancelAllTasks;


/*!
 * @method
 *
 * @brief Cancels the task with the provided task identifier.
 *
 * @param taskIdentifier - The ID of the task to cancel.
 */
- (void)cancelSearchTaskWithIdentifier:(NSString *)taskIdentifier NS_SWIFT_NAME(cancelSearchTask(identifier:));


/*!
 * @method
 *
 * @brief Gets the task with the provided task identifier.
 *
 * @param taskIdentifier - The identifier of the task to get.
 *
 * @return the corresponding task, or null if not found.
 */
- (nullable SlyceSearchTask *)getSearchTaskByIdentifier:(NSString *)taskIdentifier NS_SWIFT_NAME(getSearchTask(identifier:));


#pragma mark - SlyceScanner


/*!
 * @method
 *
 * @brief Checks the configuration for the provided lens identifier.
 *
 * @param lensIdentifier  - The identifier of the lens to create.
 *
 * @return YES if the lensIdentifier is able to be used to create a `SlyceScanner`.
 */
- (BOOL)canCreateScannerForLensIdentifier:(NSString *)lensIdentifier NS_SWIFT_NAME(canCreateScanner(lensIdentifier:));


/*!
 * @method
 *
 * @brief Creates a new headless lens matching the spec of the provided lens identifier.
 *
 * @param identifier  - The identifier of the lens to create.
 * @param config - The configuration for this lens.
 * @param error - A pointer to an error that may be emitted.
 *
 * @return a new headless lens.
 */
- (nullable SlyceScanner *)createScannerWithLensIdentifier:(NSString *)identifier configuration:(nullable SlyceLensConfiguration *)config error:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NAME(createScanner(lensIdentifier:configuration:));


/*!
 * @method
 *
 * @brief Creates a new headless lens matching the spec of the provided lens identifier with a default configuration.
 *
 * @param identifier  - The identifier of the lens to create.
 * @param error - A pointer to an error that may be emitted.
 *
 * @return a new headless lens.
 */
- (nullable SlyceScanner *)createScannerWithLensIdentifier:(NSString *)identifier error:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NAME(createScanner(lensIdentifier:));


@end
NS_ASSUME_NONNULL_END
