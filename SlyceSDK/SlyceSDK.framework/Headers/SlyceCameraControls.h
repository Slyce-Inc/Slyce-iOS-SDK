#import <Foundation/Foundation.h>

#import "SlyceBase.h"


NS_ASSUME_NONNULL_BEGIN
@protocol SlyceCameraControls <NSObject>

/*!
 *  @method
 *
 *  @brief Starts the camera.
 *
 *  @discussion Use this method to start a camera instance for the first time.
 *
 *  @param error An error that is assigned if the underlying camera cannot be started.
 *
 */
- (BOOL)start:(SlyceOutError)error;

/*!
 *  @method
 *
 *  @brief Stops the camera.
 *
 *  @discussion Calling stop tears down the underlying AVCaptureSession and its associated inputs and outputs. After a camera is stopped, start: must be called in order to resume.
 *
 */
- (void)stop;

/*!
 *  @method
 *
 *  @brief Pauses the camera.
 *
 *  @discussion Pauses the camera, a paused camera may be resumed at a later time.
 *
 */
- (void)pause;

/*!
 *  @method
 *
 *  @brief Resumes the camera.
 *
 *  @discussion Use this method to resume a camera instance that has already been started
 *
 *  @param error An error that is assigned if the underlying camera cannot be resumed.
 *
 */
- (BOOL)resume:(SlyceOutError)error;

/**
 * @property
 *
 * @abstract YES if the camera has been paused.
 *
 */
@property (nonatomic, readonly) BOOL paused;


#pragma mark -

/**
 * @property
 *
 * @abstract The preview layer of this camera.
 *
 * @discussion This layer may be used to view the output of the camera.
 *
 */
@property (nonatomic, readonly, nullable) CALayer *previewLayer;


#pragma mark -

/**
 * @property
 *
 * @abstract The zoom factor of the camera. Defaults to 1.0.
 *
 * @discussion This layer may be used to view the output of the camera.
 *
 */
@property (nonatomic, readonly) CGFloat zoomFactor;

/**
 * @property
 *
 * @abstract The current position of the capture device. Defaults to AVCaptureDevicePositionBack.
 *
 */
@property (nonatomic, readonly) AVCaptureDevicePosition devicePosition;

/*!
 *  @method
 *
 *  @brief Sets the zoom factor of the
 *
 *  @discussion Use this method to start a camera instance for the first time.
 *
 *  @param zoomFactor The zoom factor to be set.
 *  @param error An error that is assigned if the zoom factor cannot be set.
 *
 */
- (BOOL)setZoomFactor:(CGFloat)zoomFactor error:(SlyceOutError)error
NS_SWIFT_NAME(setZoomFactor(_:));

/*!
 *  @method
 *
 *  @brief Toggles the devicePosition.
 *
 *  @discussion Use this method to start a camera instance for the first time.
 *
 *  @param error An error that is assigned if this operation fails.
 *
 */
- (BOOL)toggleBackFront:(SlyceOutError)error
NS_SWIFT_NAME(toggleBackFront());

/*!
 *  @method
 *
 *  @brief Sets the flash mode.
 *
 *  @discussion Use this method to set the flash mode of the camera.
 *
 *  @param error An error that is assigned if this operation fails.
 *
 */
- (BOOL)setFlashMode:(AVCaptureFlashMode)flashMode error:(SlyceOutError)error
NS_SWIFT_NAME(setFlashMode(_:));

/*!
 *  @method
 *
 *  @brief Focuses the camera at the provided point.
 *
 *  @discussion Use this method to set the flash mode of the camera.
 *
 *  @param point The point to be focues upon.
 *  @param error An error that is assigned if this operation fails.
 *
 */
- (BOOL)focusAtPoint:(CGPoint)point error:(SlyceOutError)error
NS_SWIFT_NAME(focusAtPoint(_:));

@end
NS_ASSUME_NONNULL_END
