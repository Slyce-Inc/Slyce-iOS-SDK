
#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface Camera : NSObject

@property (nonatomic, strong, nullable) AVCaptureSession *cameraCaptureSession;


- (AVCaptureVideoPreviewLayer * _Nullable)start;

@end

NS_ASSUME_NONNULL_END
