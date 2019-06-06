
#import "TableTableViewController.h"
#import <SlyceSDK/SlyceSDK.h>
#import "VisualSearchViewController.h"
#import "ScannerViewController.h"
#import "TableViewCell.h"


@interface TableTableViewController ()

@end

@implementation TableTableViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // The following code is used to setup and show all Headless
    // example modes in a standard UITableView frontend.
    //
    // None of this code is necessary to run Slyce and
    // is only included to help navigate the example app.
    
    self.title = @"Slyce SDK 5 Headless Examples";
    [self.tableView registerClass:[TableViewCell class] forCellReuseIdentifier:[TableViewCell reuseIdentifier]];
}

- (void)openSlyce {
    NSString *slyceAccountIdentifier = @"";
    NSString *slyceSpaceIdentifier = @"";
    NSString *slyceAPIKey = @"";
    
    
    BOOL requireGDPR = NO; // set to `YES` to use GDPR compliance support
    
    // GDPR Compliance support (optional)
    if (requireGDPR) {
        [Slyce shared].complianceManager.userRequiresGDPRCompliance = YES;
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
                                       
                                       dispatch_async(dispatch_get_main_queue(), ^{
                                           if (requireGDPR) {
                                               SlycePrivacyPolicy *privacyPolicy = [Slyce shared].complianceManager.privacyPolicy;
                                               if (privacyPolicy == nil) {
                                                   [NSException raise:@"failed to retrieve Privacy Policy" format:@""];
                                               }
                                               
                                               // Here you are required to display the information in the Privacy Policy and capture
                                               // the user's consesnt. See documentation for `SlycePrivacyPolicy`.
                                               
                                               // If user consensents...
                                               [[Slyce shared].complianceManager setUserConsentedToPrivacyPolicy:privacyPolicy];
                                           }
                                           
                                           [self.tableView reloadData];
                                       });
                                   }];
}


- (void)openSlyceExampleWithNumber:(NSInteger)number {
    if (![Slyce shared].isOpen) {
        return;
    }
    
    // Depending on which mode the user tapped, launch the appropriate
    // view controller which completely handles the Slyce search.
    
    UIViewController *viewController;
    
    switch (number) {
        case 0:
            viewController = [[VisualSearchViewController alloc] init];
            break;
        case 1:
            viewController = [[ScannerViewController alloc] initWithLensIdentifier:SlyceLensIdentifierBarcode];
            break;
        case 2:
            viewController = [[ScannerViewController alloc] initWithLensIdentifier:SlyceLensIdentifierImageMatching];
            break;
        default:
            break;
            
    }
    
    [self.navigationController pushViewController:viewController animated:YES];
}


#pragma mark - Table view data source

- (NSInteger)numberOfSectionsInTableView:(UITableView *)tableView {
    return [[Slyce shared] isOpen] ? 2 : 1;
}

- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    if (section == 0) {
        return 1;
    }
    
    return 3;
}

- (NSString *)tableView:(UITableView *)tableView titleForHeaderInSection:(NSInteger)section {
    if (section == 0) {
        return @"Connect to Slyce to use demos.";
    }
    
    return @"Tap below to perform an example search.";
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 64;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    TableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:[TableViewCell reuseIdentifier]];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    cell.textLabel.font = [UIFont systemFontOfSize:18];
    
    if (indexPath.section == 0) {
        cell.textLabel.text = @"Open Slyce";
        return cell;
    }
    
    switch (indexPath.row) {
        case 0:
            cell.textLabel.text = @"Visual Search";
            break;
        case 1:
            cell.textLabel.text = @"Barcode Search";
            break;
        case 2:
            cell.textLabel.text = @"Image Match";
            break;
        default:
            cell.textLabel.text = nil;
            break;
    }
    
    return cell;
}


- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    if (indexPath.section == 0) {
        [self openSlyce];
    } else {
        [self openSlyceExampleWithNumber:indexPath.row];
    }
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}

@end
