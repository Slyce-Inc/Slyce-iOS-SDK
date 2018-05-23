#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface SlyceLink : NSObject

/**
 * @property
 * @abstract A string representing the call to action for this link.
 */
@property (nonatomic, copy, readonly) NSString *callToAction;

/**
 * @property
 * @abstract A string representing the url of this link
 */
@property (nonatomic, copy, readonly) NSString *urlString;

@end
NS_ASSUME_NONNULL_END
