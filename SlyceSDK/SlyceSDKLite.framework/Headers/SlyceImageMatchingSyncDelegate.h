#import <Foundation/Foundation.h>

@class Slyce;

NS_ASSUME_NONNULL_BEGIN
@protocol SlyceImageMatchingSyncDelegate <NSObject>

/*!
 *  @method
 *
 *  @brief Alerts the delegate that an image matching sync has started.
 *
 *  @param slyce The instance of `Slyce` started the sync.
 *
 */
- (void)slyceImageMatchingSyncDidStart:(Slyce *)slyce
NS_SWIFT_NAME(slyce(imageMatchingSyncDidStart:));

/*!
 *  @method
 *
 *  @brief Alerts the delegate that an image matching sync has finished.
 *
 *  @param slyce The instance of `Slyce` started the sync.
 *
 */
- (void)slyceImageMatchingSyncDidFinish:(Slyce *)slyce
NS_SWIFT_NAME(slyce(imageMatchingSyncDidFinish:));

/*!
 *  @method
 *
 *  @brief Alerts the delegate that an image matching sync has failed.
 *
 *  @param slyce The instance of `Slyce` started the sync.
 *  @param failMessage A message describing the failure.
 *
 */
- (void)slyce:(Slyce *)slyce imageMatchingSyncFailedWithMessage:(NSString *)failMessage
NS_SWIFT_NAME(slyce(_:imageMatchingSyncFailedWithMessage:));

/*!
 *  @method
 *
 *  @brief Alerts the delegate of the number of catalogs that have been synced and a running total of all catalogs that have been synced.
 *
 *  @param slyce The instance of `Slyce` started the sync.
 *  @param count The number of catalogs that have just been synced.
 *  @param total The total number of catalogs that have been synced.
 *
 */
- (void)slyce:(Slyce *)slyce imageMatchingSyncedCatalogCount:(NSInteger)count fromTotalCount:(NSInteger)total
NS_SWIFT_NAME(slyce(_:imageMatchingSyncedCatalogCount:fromTotalCount:));

@end
NS_ASSUME_NONNULL_END
