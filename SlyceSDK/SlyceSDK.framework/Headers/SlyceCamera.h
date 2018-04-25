#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <AVFoundation/AVFoundation.h>

#import "SlyceCameraControls.h"

@protocol SlyceCameraDelegate;

NS_ASSUME_NONNULL_BEGIN
@protocol SlyceCamera <SlyceCameraControls>

@property (nonatomic, weak) id<SlyceCameraDelegate> delegate;

@property (nonatomic, readonly, nullable) CALayer *layer;

@property (nonatomic, readonly, nullable) AVCaptureVideoPreviewLayer *previewLayer;

- (void)snap:(void (^) (UIImage * _Nullable, NSError * _Nullable))completion;

@property (nonatomic, readonly) AVCaptureDevicePosition devicePosition;

@property (nonatomic, readonly) CGFloat zoomFactor;

- (BOOL)setZoomFactor:(CGFloat)zoomFactor andReturnError:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NAME(setZoomFactor(_:));

- (BOOL)toggleBackFrontAndReturnError:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NAME(toggleBackFront());

- (BOOL)setFlashMode:(AVCaptureFlashMode)flashMode andReturnError:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NAME(setFlashMode(_:));

- (BOOL)focusAtPoint:(CGPoint)point andReturnError:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NAME(focusAtPoint(_:));

- (BOOL)setCapturePreset:(AVCaptureSessionPreset)present andReturnError:(NSError * _Nullable __autoreleasing *)error NS_SWIFT_NAME(setCapturePreset(_:));

#pragma mark Preview / Image Buffer mapping

- (CGPoint)imageBufferPointForPreviewLayerPoint:(CGPoint)previewLayerPoint;
- (CGPoint)previewLayerPointForImageBufferPoint:(CGPoint)bufferPoint;

@end
NS_ASSUME_NONNULL_END
