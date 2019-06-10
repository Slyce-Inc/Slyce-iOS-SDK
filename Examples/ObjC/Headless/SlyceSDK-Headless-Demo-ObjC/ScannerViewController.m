
#import "ScannerViewController.h"
#import "Camera.h"

@interface ScannerViewController () <SlyceSessionListener, SlyceSearchTaskListener>


// Performing a Barcode Search or Image Match is similar to a Visual Search.
// In order to differentiate between modes, we must provide the lensIdentifier
// (used when creating a new Scanner, see viewDidLoad below).
@property (nonatomic, assign) SlyceLensIdentifier lensIdentifier;

// A SlyceScanner attaches to an existing AVFoundation camera session and wires
// Slyce into the active camera, allowing us to get instant continuous results.
// We have created a Camera class that wraps the basic Apple boilerplate for
// starting, resuming, and displaying a standard iOS camera.
@property (nonatomic, strong) Camera *camera;
@property (nonatomic, strong, nullable) CALayer *cameraLayer;

@property (nonatomic, strong, nullable) SlyceSession *session;
@property (nonatomic, strong, nullable) SlyceScanner *scanner;

@end

@implementation ScannerViewController

- (instancetype)initWithLensIdentifier:(SlyceLensIdentifier)lensidentifier {
    self = [super initWithNibName:nil bundle:nil];
    self.lensIdentifier = lensidentifier;
    return self;
}


- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.camera = [[Camera alloc] init];
    
    [self appendStringToTextView:@"\n\nStarting example Scanner..."];
    
    // In some cases, we will not be able to access the camera.
    // This often happens when (1) running in the iOS simulator,
    // (2) if the user did not accept the iOS Camera Privacy popup.
    NSError *error;
    AVCaptureVideoPreviewLayer *layer = [self.camera start];
    SlyceSession *slyceSession = [SlyceSession sessionWithSlyce:[Slyce shared] error:&error];
    AVCaptureSession *cameraSession = self.camera.cameraCaptureSession;
    
    if (layer == nil || error != nil || cameraSession == nil) {
        NSLog(@"Unable to access Slyce session and/or start camera");
        return;
    }

    layer.frame = CGRectMake(0, 0, self.view.frame.size.width, self.view.frame.size.height);
    [self.view.layer addSublayer:layer];
    
    // After starting the camera, we want to add the preview layer to the current
    // view in order to see the output of the camera session.
    
    self.cameraLayer = layer;
    self.session = slyceSession;
    
    
    // Once the standard Apple camera is completely set up, AND Slyce has been opened,
    // we can create a scanner using the session and lens identifier. This might also
    // fail if the camera is unavailable.
    SlyceScanner *slyceScanner = [SlyceScanner scannerWithSession:slyceSession
                                                   lensIdentifier:self.lensIdentifier
                                                lensConfiguration:nil error:&error];
    
    if (error != nil) {
        NSLog(@"%@", error.localizedDescription);
        return;
    }
    
    
    if (![slyceScanner attachToCaptureSession:cameraSession error:&error]) {
        NSLog(@"%@", error.localizedDescription);
        return;
    }
    
    
    // After attaching to a camera session, we MUST call resumeDetection to begin
    // detecting barcode or image match results.
    [slyceScanner resumeDetection];
    
    
    // In order to receive updates from the SlyceScanner after attaching it to an active
    // AVFoundation camera capture session, we must add a listener to the session, which
    // will feed us SlyceSearchTasks whenever they are created.
    [slyceSession addListener:self];
}


#pragma mark - SlyceSessionListener

- (void)slyceSession:(SlyceSession *)session willStartSearchTask:(SlyceSearchTask *)searchTask {
    // After creating a new task, we pause the scanner to prevent duplicate
    // scans of the same item, and we remove the preview layer to see the
    // text view underneath (see TextViewViewController).
    
    dispatch_async(dispatch_get_main_queue(), ^{
        [self.scanner suspendDetection];
        [self.cameraLayer removeFromSuperlayer];
    });
    
    [self appendTaskToTextView:searchTask finished:NO];
    
    // In order to receive updates to the task after it is created, we must
    // assign a listener, which will funnel information through the below
    // SlyceSearchTaskListener methods.
    [searchTask addListener:self];
}

- (void)slyceSession:(SlyceSession *)session didFinishSearchTask:(SlyceSearchTask *)searchTask {
    [self appendTaskToTextView:searchTask finished:YES];
}


#pragma mark - SlyceSearchTaskListener

// These methods are used to handle the results and updates from Slyce after starting a search.
// Here, we only display the raw data in the text view managed by the base class
// (see TextViewViewController), however, in production, a view would be rendered to showcase
// the output.

- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didReceiveSearchResponseUpdate:(SlyceSearchResponseUpdate *)searchResponseUpdate {
    [self appendUpdateToTextView:searchResponseUpdate];
}

- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFailWithErrors:(NSArray<NSError *> *)errors {
    [self appendErrorsToTextView:errors];
}

- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFinishWithResponse:(SlyceSearchResponse *)response {
    [self appendResponseToTextView:response];
}
@end
