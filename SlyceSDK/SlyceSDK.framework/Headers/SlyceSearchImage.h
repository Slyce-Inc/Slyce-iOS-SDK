#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchImage : NSObject

- (instancetype)initWithImage:(UIImage *)image;
- (instancetype)initWithImage:(UIImage *)image anchor:(CGPoint)anchor NS_DESIGNATED_INITIALIZER;

@property (nonatomic, readonly) UIImage *image;
@property (nonatomic, readonly) CGPoint anchor;


@end
NS_ASSUME_NONNULL_END
