#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

@protocol SlyceCamera;

@protocol SlyceCameraDelegate <NSObject>

- (void)camera:(id<SlyceCamera>)camera didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer
NS_SWIFT_NAME(camera(_:didOutputSampleBuffer:));

- (void)camera:(id<SlyceCamera>)camera didOutputMetadataObjects:(NSArray *)metadataObjects
NS_SWIFT_NAME(camera(_:didOutputMetadataObjects:));

@end
