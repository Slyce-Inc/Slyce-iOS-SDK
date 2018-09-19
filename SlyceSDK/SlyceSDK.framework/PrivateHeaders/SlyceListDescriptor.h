#import <SlyceSDK/SlyceBase.h>

@class SlyceItemDescriptor;

NS_ASSUME_NONNULL_BEGIN
__attribute__((objc_subclassing_restricted))
@interface SlyceListDescriptor : NSObject

/*!
 * @property
 *
 * @brief The name of the list.
 *
 */
@property (nonatomic, copy, readonly) NSString *name;

/*!
 * @property
 *
 * @brief The list of items on this list instance.
 *
 */
@property (nonatomic, strong, readonly) NSArray<SlyceItemDescriptor *> *items;

@end
NS_ASSUME_NONNULL_END
