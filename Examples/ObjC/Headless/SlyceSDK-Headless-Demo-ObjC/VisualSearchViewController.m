
#import "VisualSearchViewController.h"
#import <SlyceSDK/SlyceSDK.h>

@interface VisualSearchViewController ()<SlyceSearchTaskListener>

@property (nonatomic, strong) SlyceSession *session;

@property (nonatomic, strong) SlyceSearchTask *task;

@end

@implementation VisualSearchViewController


- (instancetype)init {
    self = [super initWithNibName:nil bundle:nil];
    
    NSError *error;
    self.session = [SlyceSession sessionWithSlyce:[Slyce shared] error:&error];
    if (error != nil) {
        [NSException raise:@"" format:@""];
    }
    
    return self;
}


- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self appendStringToTextView:@"\n\nStarting example Visual Search..."];
    
    NSString *visualSearchWorkflowIdentifier = @"";
    UIImage *visualSearchExampleImage = [UIImage imageNamed:@"shirt"];
    
    // We create a new request, which encapsulates the payload needed to start a visual search.
    // Instead of attaching an image, an imageURL may also be used.
    // Anchor is optional, and represents the tap point relative to the coordinates of the image.
    
    // Optionally, we can add additional search parameters
    SlyceSearchParameters *searchParams = [[SlyceSearchParameters alloc] init];
    searchParams.workflowOptions = @{@"gender": @"F"};
    searchParams.demoMode = YES;
    
    SlyceSearchRequest *request = [[SlyceSearchRequest alloc] initWithImage:visualSearchExampleImage
                                                                     anchor:SlyceAnchorPointNone
                                                           searchParameters:searchParams];
    
    // In order to receive updates after starting the task, we must provide a SlyceSearchTaskListener,
    // which will be called whenever there are errors, updates, or a completed result.
    self.task = [self.session startSearchTaskWithRequest:request
                                      workflowIdentifier:visualSearchWorkflowIdentifier
                                                listener:self];
    
    [self appendTaskToTextView:self.task finished:NO];
}

- (void)viewDidDisappear:(BOOL)animated {
    [super viewDidDisappear:animated];
    [self.session cancelAllTasks];
}


#pragma mark - SlyceSearchTaskListener

// These methods are used to handle the results and updates from Slyce after starting a search.
// Here, we only display the raw data in the text view managed by the base class
// (see TextViewViewController), however, in production, a view would be rendered to showcase
// the output.
- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFailWithErrors:(NSArray<NSError *> *)errors {
    [self appendErrorsToTextView:errors];
}

- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didReceiveSearchResponseUpdate:(SlyceSearchResponseUpdate *)searchResponseUpdate {
    [self appendUpdateToTextView:searchResponseUpdate];
}

- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFinishWithResponse:(SlyceSearchResponse *)response {
    [self appendResponseToTextView:response];
}

@end
