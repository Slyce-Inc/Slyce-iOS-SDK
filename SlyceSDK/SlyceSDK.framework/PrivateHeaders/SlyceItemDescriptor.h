#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
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
@property (nonatomic, strong, readonly) NSDictionary *item;

@end
NS_ASSUME_NONNULL_END
