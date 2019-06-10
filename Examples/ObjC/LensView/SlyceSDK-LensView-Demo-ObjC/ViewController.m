
#import "ViewController.h"
#import <SlyceSDK/SlyceSDK.h>


@interface ViewController () <SlyceSessionListener, SlyceSearchTaskListener>

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupSlyce];
}

- (void)setupSlyce {
    // Slyce should be opened once, generally at application startup.
    
    NSString *slyceAccountIdentifier = @"";
    NSString *slyceSpaceIdentifier = @"";
    NSString *slyceAPIKey = @"";
    
    [[Slyce shared] openWithAccountIdentifier:slyceAccountIdentifier
                                       apiKey:slyceAPIKey
                              spaceIdentifier:slyceSpaceIdentifier
                                   completion:^(NSError * _Nullable error) {
                                       if (error != nil) {
                                           NSLog(@"Unable to login to Slyce, %@", error.localizedDescription);
                                       } else {
                                           dispatch_async(dispatch_get_main_queue(), ^{
                                               [self setupLensView];
                                           });
                                       }
                                   }];
}


- (void)setupLensView {
    // In order to create a LensView, we must provide an active session
    // (available once opening Slyce), and a lensIdentifier, which is specific
    // to the lens type.
    //
    // In this case, we are creating a LensView which can
    // be used to detect and receive Visual Search results.
    
    NSError *error;
    SlyceSession *session = [SlyceSession sessionWithSlyce:[Slyce shared] error:&error];
    
    if (error != nil) {
        NSLog(@"Unable to access Slyce!");
        return;
    }
    
    SlyceLensIdentifier lensIdentifier = SlyceLensIdentifierVisualSearch;
    
    
    // A LensView can be added to any superview and is a fully contained Slyce
    // camera experience, managed through the session and configuration given
    // at init-time.
    SlyceLensView *lensView = [SlyceLensView lensViewWithSession:session
                                                  lensIdentifier:lensIdentifier
                                                         options:nil
                                                           error:&error];
    
    if (error != nil) {
        NSLog(@"Unable to start camera,  %@", error.localizedDescription);
        return;
    }
    
    lensView.frame = self.view.frame;
    [self.view addSubview:lensView];
    
    // In order to receive results, we must add ourselves as a listener on the session.
    [session addListener:self];
}


#pragma mark - SlyceSessionListener

- (void)slyceSession:(SlyceSession *)session willStartSearchTask:(SlyceSearchTask *)searchTask {
    // In order to receive updates to the task after it is created, we must
    // assign a listener, which will funnel information through the below
    // SlyceSearchTaskListener methods.
    
    [searchTask addListener:self];
    NSLog(@"\nSession didCreateSearchTask:\n\t%@", searchTask.debugDescription);
}


#pragma mark - SlyceSearchTaskListener

// These methods are used to handle the results and updates from Slyce after starting a search.

- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFailWithErrors:(NSArray<NSError *> *)errors {
    NSLog(@"\nSearch Task didFailWithErrors:\n\t%@", errors.debugDescription);
}

- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didReceiveSearchResponseUpdate:(SlyceSearchResponseUpdate *)searchResponseUpdate {
    NSLog(@"\nSearch Task didUpdate:\n\t%@", searchResponseUpdate.debugDescription);
}

- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFinishWithResponse:(SlyceSearchResponse *)response {
    NSLog(@"\nSearch Task didFinishWithResponse:\n\t%@", response.debugDescription);
}

@end
