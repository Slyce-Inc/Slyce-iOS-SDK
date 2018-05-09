#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface SlyceLensConfiguration: NSObject

/**
 * @property
 *
 * @abstract The detection threshold for image matching.
 *
 */
@property (nonatomic, assign) float detectionThreshold2D;

/**
 * @property
 *
 * @abstract YES if a sound should be played upon detection.
 *
 */
@property (nonatomic, assign) BOOL sound;

/**
 * @property
 *
 * @abstract YES if the device should vibrate upon detection.
 *
 */
@property (nonatomic, assign) BOOL vibrate;

@end
NS_ASSUME_NONNULL_END

