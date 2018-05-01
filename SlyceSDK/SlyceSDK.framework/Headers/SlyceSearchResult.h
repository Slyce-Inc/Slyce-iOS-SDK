#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchResult : NSObject <NSCoding>

/*!
 * @method
 *
 * @brief The type of SlyceSearchResult.
 *
 */
- (NSString *)type;


/*!
 * @method
 *
 * @brief The unmapped items represented by this `SlyceSearchResult`.
 *
 */
- (NSArray <NSDictionary *> *)items;

@end
NS_ASSUME_NONNULL_END
