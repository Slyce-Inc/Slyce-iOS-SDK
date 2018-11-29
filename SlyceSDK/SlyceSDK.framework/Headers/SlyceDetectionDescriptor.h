#import "SlyceBase.h"


typedef NS_ENUM(NSUInteger, SlyceDetectionType) {
    SlyceDetectionTypeBarcode = 1,
};


NS_ASSUME_NONNULL_BEGIN

@interface SlyceDetectionDescriptor : NSObject


/*!
 * @property
 *
 * @brief The type of update. See `SlyceDetectionType`.
 */
@property (nonatomic, readonly) SlyceDetectionType type;


/*!
 * @property
 *
 * @brief Gets the value associated with this detection.
 * @discussion If `type` is `SlyceDetectionTypeBarcode`, `value` will be a `SlyceBarcode` object.
 */
@property (nonatomic, readonly, nullable) id value;

@end


NS_ASSUME_NONNULL_END
