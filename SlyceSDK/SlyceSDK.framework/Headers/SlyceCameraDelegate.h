#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@protocol SlyceCamera;

@protocol SlyceCameraDelegate <NSObject>

/*!
 * @method
 *
 * @brief Receive sample buffers from a `SlyceCamera` that can be used for individual frame analysis and recognition.
 *
 * @param camera A SlyceCamera instance.
 * @param sampleBuffer A sampleBuffer received from the running camera
 *
 */
- (void)camera:(id<SlyceCamera>)camera didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
NS_SWIFT_NAME(camera(_:didOutputSampleBuffer:));

/*!
 * @method
 *
 * @brief Receive metadata output from a `SlyceCamera` that can be used particularly for barcode recognition.
 *
 * @param camera A SlyceCamera instance.
 * @param metadataObjects AVFoundation-provided array of AVMetadataObjects received from the running camera.
 *
 */
- (void)camera:(id<SlyceCamera>)camera didOutputMetadataObjects:(NSArray *)metadataObjects
NS_SWIFT_NAME(camera(_:didOutputMetadataObjects:));

@end
