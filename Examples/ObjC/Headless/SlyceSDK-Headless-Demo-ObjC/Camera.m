
#import "Camera.h"

@interface Camera () <AVCapturePhotoCaptureDelegate>

@property (nonatomic, strong) AVCaptureVideoPreviewLayer *cameraPreviewLayer;

@end

@implementation Camera

- (AVCaptureVideoPreviewLayer *)start {
    if (nil == self.cameraCaptureSession) {
        self.cameraCaptureSession = [self setupCaptureSession];
        
        if (!self.cameraCaptureSession) {
            NSLog(@"Unable to create a camera capture session; this means the camera is unavailable or impossible to access and none of the SDK features will work!");
            return nil;
        }
    }
    
    if (nil == self.cameraPreviewLayer) {
        AVCaptureVideoPreviewLayer *previewLayer = [[AVCaptureVideoPreviewLayer alloc] initWithSession:self.cameraCaptureSession];
        previewLayer.videoGravity = AVLayerVideoGravityResizeAspectFill;
        self.cameraPreviewLayer = previewLayer;
        
        if (nil == self.cameraPreviewLayer) {
            NSLog(@"Unable to create a camera preview layer; this means the camera will be invisible in the demo UI and it is unlikely that the SDK features will work!");
            return nil;
        }
    }
    
    
    if (self.cameraCaptureSession.isRunning == false) {
        [self.cameraCaptureSession startRunning];
    }
    
    return self.cameraPreviewLayer;
}


- (AVCaptureDevice *_Nullable)getAvailableCamera {
    return [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
}

- (void)prepareCamera:(AVCaptureDevice *)camera {
    NSError *error;
    [camera lockForConfiguration:&error];
    
    if (error != nil) {
        NSLog(@"%@", error.localizedDescription);
        return;
    }
    
    camera.focusMode = AVCaptureFocusModeContinuousAutoFocus;
    [camera unlockForConfiguration];
}

- (AVCaptureSession * _Nullable)setupCaptureSession {
    // create session
    AVCaptureSession *captureSession = [[AVCaptureSession alloc] init];
    captureSession.sessionPreset = AVCaptureSessionPresetHigh;
    
    // create, setup camera
    AVCaptureDevice *camera = [self getAvailableCamera];
    if (!camera) {
        return nil;
    }
    
    [self prepareCamera:camera];
    
    
    // add camera input to session
    NSError *error;
    AVCaptureDeviceInput *cameraInput = [[AVCaptureDeviceInput alloc] initWithDevice:camera error:&error];
    if (error != nil) {
        NSLog(@"%@", error.localizedDescription);
        return nil;
    }
    
    if (![captureSession canAddInput:cameraInput]) {
        return nil;
    }
    
    [captureSession addInput:cameraInput];
    return captureSession;
}

@end
