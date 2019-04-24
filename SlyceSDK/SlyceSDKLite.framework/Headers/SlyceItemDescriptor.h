#import "SlyceBase.h"

NS_ASSUME_NONNULL_BEGIN
__attribute__((objc_subclassing_restricted))
@interface SlyceItemDescriptor : NSObject

/*!
 * @property
 *
 * @brief The identifier of the selected item.
 *
 */
@property (nonatomic, copy, readonly) NSString *identifier;

/*!
 * @property
 *
 * @brief The dictionary representation of the selected item.
 *
 */
@property (nonatomic, strong, readonly) NSDictionary<NSString *, id> *item;

/*!
 * @property
 *
 * @brief The identifier of the originating search.
 *
 * @discussion This is the jobIdentifier to use for all analytics callbacks related to this item or search result.
 *
 */
@property (nonatomic, copy, readonly) NSString *jobIdentifier;

@end
NS_ASSUME_NONNULL_END
