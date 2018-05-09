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
- (void)slyceSession:(SlyceSession *)session didCreateSearchTask:(SlyceSearchTask *)searchTask NS_SWIFT_NAME(slyce(session:didCreateSearchTask:));

@end

@interface SlyceSession : NSObject


/*!
 * @property
 *
 * The object that acts as the delegate of the table session.
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





@end
NS_ASSUME_NONNULL_END
