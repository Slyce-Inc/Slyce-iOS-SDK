
#import "ViewController.h"
#import <SlyceSDK/SlyceSDK.h>
#import "SearchDetailViewController.h"

@interface ViewController ()<SlyceViewControllerDelegate>

@property (nonatomic, assign) BOOL useCustomSearchDetail;

@property (nonatomic, assign) BOOL applyCustomTheme;

@property (nonatomic, strong)  SlyceViewController * _Nullable slyceViewController;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}


- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    
    self.useCustomSearchDetail = NO; // set to YES to use custom search detail
    self.applyCustomTheme = NO; // set to YES to use custom theme values
    
    
    NSString *slyceAccountIdentifier = @"";
    NSString *slyceSpaceIdentifier = @"";
    NSString *slyceAPIKey = @"";
    
    
    if (self.applyCustomTheme) {
        [self applyCustomTheme];
    }
    
    
    // Slyce should be opened once, generally at application startup. We're doing
    // it here for demo purposes.
    
    [[Slyce shared] openWithAccountIdentifier:slyceAccountIdentifier
                                       apiKey:slyceAPIKey
                              spaceIdentifier:slyceSpaceIdentifier
                                   completion:^(NSError * _Nullable error) {
                                       if (error != nil) {
                                           NSLog(@"Error opening Slyce!\n%@", error.localizedDescription);
                                           return;
                                       }
                                       
                                       SlyceSearchParameters *searchParams = [[SlyceSearchParameters alloc] init];
                                       // All search parameters are optional and independent
                                       
                                       // Country Code
                                       //searchParams.countryCode = @"BE";
                                       
                                       // Language Code
                                       //searchParams.languageCode = @"fr";
                                       
                                       // Demo Mode. Set to `YES` to receive test data. Defaults to NO.
                                       searchParams.demoMode = NO;
                                       
                                       
                                       // Setting search parameters here will automatically include them for all
                                       // SearchRequests in the session.
                                       [Slyce shared].defaultSearchParameters = searchParams;
                                       
                                       // The current completion block may not be on the main thread
                                       // so we dispatch the SlyceViewController creation on the main queue
                                       
                                       dispatch_async(dispatch_get_main_queue(), ^{
                                           self.slyceViewController = [[SlyceViewController alloc] initWithSlyce:[Slyce shared] mode:SlyceViewControllerModePicker];
                                           self.slyceViewController.delegate = self;
                                           [self presentViewController:self.slyceViewController animated:YES completion:nil];
                                       });
                                   }];
}


- (void)applySlyceTheme {
    // - Header
    [[SlyceTheme shared] setAppearanceStyle:SlyceHeaderStyleLeftBackButton forPropertyName:@"appearance_headerStyle_left"];
    [[SlyceTheme shared] setAppearanceStyle:SlyceHeaderStyleCenterImage forPropertyName:@"appearance_headerStyle_center"];
    
    // - Accent Color
    [[SlyceTheme shared] setColor:[UIColor purpleColor] forPropertyName:@"global_accent_color"];
    
    // - Coaching Tips
    [[SlyceTheme shared] setString:@"Your Headline Here" forPropertyName:@"string_coachingTip_headline_visualSearch"];
    [[SlyceTheme shared] setString:@"Your body text here" forPropertyName:@"string_coachingTip_body_visualSearch"];
    [[SlyceTheme shared] setImage:[UIImage imageNamed:@"your_image"] forPropertyName:@"bg_coachingTip_visualSearch"];
}


#pragma mark - SlyceViewControllerDelegate


- (BOOL)slyceViewController:(SlyceViewController *)viewController shouldDisplayDefaultDetailForItemDescriptor:(SlyceItemDescriptor *)itemDescriptor {
    if (self.useCustomSearchDetail) {
        if (self.slyceViewController == nil) {
            [NSException raise:@"SlyceViewController was nil" format:@""];
        } else {
            // This a very simple implementation that will present the custom search detail modally over
            // the SlyceViewController. In your application you may wish to dismiss the SlyceViewController
            // or push the detail controller in a navigation controller.
            
            SearchDetailViewController *detailVC = [[SearchDetailViewController alloc] initWithNibName:@"SearchDetailViewController" bundle:nil];
            detailVC.item = itemDescriptor.item;
            [self.slyceViewController presentViewController:detailVC animated:YES completion:nil];
            return NO;
        }
    }
    
    return NO;
}

- (BOOL)slyceViewController:(SlyceViewController *)viewController  shouldDisplayDefaultListForItemDescriptors:(NSArray<SlyceItemDescriptor *> *)itemDescriptors {
    
    return YES;
}

@end
