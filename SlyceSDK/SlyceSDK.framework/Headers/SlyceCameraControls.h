#import <Foundation/Foundation.h>

#import "SlyceBase.h"


NS_ASSUME_NONNULL_BEGIN
@protocol SlyceCameraControls <NSObject>

@property (nonatomic, readonly) BOOL paused;


- (BOOL)start:(SlyceOutError)error;

- (void)stop;

- (void)pause;

- (BOOL)resume:(SlyceOutError)error;


#pragma mark -

@property (nonatomic, readonly, nullable) CALayer *previewLayer;


#pragma mark -

@property (nonatomic, readonly) CGFloat zoomFactor;

- (BOOL)setZoomFactor:(CGFloat)zoomFactor error:(SlyceOutError)error
NS_SWIFT_NAME(setZoomFactor(_:));

@property (nonatomic, readonly) AVCaptureDevicePosition devicePosition;

- (BOOL)toggleBackFront:(SlyceOutError)error
NS_SWIFT_NAME(toggleBackFront());

- (BOOL)setFlashMode:(AVCaptureFlashMode)flashMode error:(SlyceOutError)error
NS_SWIFT_NAME(setFlashMode(_:));

- (BOOL)focusAtPoint:(CGPoint)point error:(SlyceOutError)error
NS_SWIFT_NAME(focusAtPoint(_:));

@end
NS_ASSUME_NONNULL_END
