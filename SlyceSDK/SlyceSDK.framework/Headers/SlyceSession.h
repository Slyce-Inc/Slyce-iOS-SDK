#import <Foundation/Foundation.h>

@class SlyceSearchTask;
@class SlyceSearchRequest;
@class SlyceScanner;
@class SlyceLensConfiguration;

NS_ASSUME_NONNULL_BEGIN
@interface SlyceSession : NSObject

#pragma mark - SlyceSearchTask

/**
 * Builds a search task based on the provided request and workflow ID.
 *
 * @param searchRequest - The search request.
 * @param workflowID - The ID of the workflow to use.
 *
 * @return a new {@link SlyceSearchTask} for the request and workflow ID.
 */
- (nullable SlyceSearchTask *)searchTaskWithRequest:(SlyceSearchRequest *)searchRequest workflowID:(NSString *)workflowID;

/**
 * Cancels all tasks within this session.
 */
- (void)cancelAllTasks;

/**
 * Cancels the task with the provided task ID.
 *
 * @param taskID - The ID of the task to cancel.
 */
- (void)cancelSearchTaskWithIdentifier:(NSString *)taskID;

/**
 * Gets the task with the provided task ID.
 *
 * @param taskID - The ID of the task to get.
 *
 * @return the corresponding task, or null if not found.
 */
- (nullable SlyceSearchTask *)searchTaskForIdentifier:(NSString *)taskID;


#pragma mark - SlyceScanner


- (BOOL)canCreateScannerForLensIdentifier:(NSString *)lensIdentifier;

/**
 * Creates a new headless lens matching the spec of the provided lens ID.
 *
 * @param identifier  - The ID of the lens to create.
 * @param config - The configuration for this lens.
 * @param error - A pointer to an error that may be emitted.
 *
 * @return a new headless lens.
 */
- (nullable SlyceScanner *)scannerWithLensIdentifier:(NSString *)identifier configuration:(nullable SlyceLensConfiguration *)config error:(NSError * _Nullable __autoreleasing *)error;

/**
 * Creates a new headless lens matching the spec of the provided lens ID with a default configuration.
 *
 * @param identifier  - The ID of the lens to create.
 * @param error - A pointer to an error that may be emitted.
 *
 * @return a new headless lens.
 */
- (nullable SlyceScanner *)scannerWithLensIdentifier:(NSString *)identifier error:(NSError * _Nullable __autoreleasing *)error;

@end
NS_ASSUME_NONNULL_END
