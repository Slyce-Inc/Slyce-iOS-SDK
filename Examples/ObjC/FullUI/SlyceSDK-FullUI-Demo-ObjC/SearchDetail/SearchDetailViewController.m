
#import "SearchDetailViewController.h"

@interface SearchDetailViewController ()

@end

@implementation SearchDetailViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self updateItemTextView];
}

- (IBAction)close:(UIButton *)sender {
    [self dismissViewControllerAnimated:YES completion:nil];
}

- (void)setItem:(NSDictionary *)item {
    _item = item;
    [self updateItemTextView];
}

- (void)updateItemTextView {
    self.itemTextView.text = [self.item description];
}

@end
