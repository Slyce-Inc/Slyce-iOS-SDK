#import <Foundation/Foundation.h>

@class SlyceSearchTask;
@class SlyceSearchRequest;
@class SlyceScanner;
@class SlyceLensConfiguration;
@class SlyceContext;
@class SlyceViewController;

NS_ASSUME_NONNULL_BEGIN
@protocol SlyceSession <NSObject>

#pragma mark - SlyceSearchTask

/*!
 * @method
 *
 * @brief Builds a search task based on the provided request and workflow ID.
 *
 * @param searchRequest - The search request.
 * @param workflowIdentifier - The ID of the workflow to use.
 *
 * @return a new `SlyceSearchTask` for the request and workflow ID.
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
 * @brief Cancels the task with the provided task ID.
 *
 * @param taskID - The ID of the task to cancel.
 */
- (void)cancelSearchTaskWithIdentifier:(NSString *)taskID NS_SWIFT_NAME(cancelSearchTask(identifier:));


/*!
 * @method
 *
 * @brief Gets the task with the provided task ID.
 *
 * @param taskID - The ID of the task to get.
 *
 * @return the corresponding task, or null if not found.
 */
- (nullable SlyceSearchTask *)getSearchTaskByIdentifier:(NSString *)taskID NS_SWIFT_NAME(getSearchTask(identifier:));


#pragma mark - SlyceScanner


/*!
 * @method
 *
 * @brief Checks the configuration for the provided lensIdentifier.
 *
 * @param lensIdentifier  - The ID of the lens to create.
 *
 * @return YES if the lensIdentifier is able to be used to create a `SlyceScanner`.
 */
- (BOOL)canCreateScannerForLensIdentifier:(NSString *)lensIdentifier NS_SWIFT_NAME(canCreateScanner(lensIdentifier:));


/*!
 * @method
 *
 * @brief Creates a new headless lens matching the spec of the provided lens ID.
 *
 * @param identifier  - The ID of the lens to create.
 * @param config - The configuration for this lens.
 * @param error - A pointer to an error that may be emitted.
 *
 * @return a new headless lens.
 */
- (nullable SlyceScanner *)createScannerWithLensIdentifier:(NSString *)identifier configuration:(nullable SlyceLensConfiguration *)config error:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NAME(createScanner(lensIdentifier:configuration:));


/*!
 * @method
 *
 * @brief Creates a new headless lens matching the spec of the provided lens ID with a default configuration.
 *
 * @param identifier  - The ID of the lens to create.
 * @param error - A pointer to an error that may be emitted.
 *
 * @return a new headless lens.
 */
- (nullable SlyceScanner *)createScannerWithLensIdentifier:(NSString *)identifier error:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NAME(createScanner(lensIdentifier:));


typedef NS_ENUM(NSUInteger, SlyceViewControllerMode);
/*!
 * @method
 *
 * @brief Creates a new SlyceViewController instance.
 *
 * @param mode - The mode for the SlyceViewController
 *
 * @return A nullable `SlyceViewController`
 */
- (nullable SlyceViewController *)slyceViewControllerWithMode:(SlyceViewControllerMode)mode;

@end
NS_ASSUME_NONNULL_END
