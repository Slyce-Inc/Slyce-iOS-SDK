
#import "TextViewViewController.h"


@interface TextViewViewController ()

@property (nonatomic, strong) UITextView *textView;

@end

@implementation TextViewViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.view.backgroundColor = [UIColor whiteColor];
    
    self.textView = [[UITextView alloc] init];
    [self.textView setEditable:NO];
    [self.textView setScrollEnabled:YES];
    self.textView.showsHorizontalScrollIndicator = NO;
    self.textView.alwaysBounceHorizontal = NO;
    self.textView.alwaysBounceVertical = YES;
    [self.textView setDirectionalLockEnabled:YES];
    self.textView.font = [UIFont systemFontOfSize:20];
    self.textView.textColor = [UIColor blackColor];
    self.textView.backgroundColor = [UIColor whiteColor];
    self.textView.translatesAutoresizingMaskIntoConstraints = NO;
    [self.view addSubview:self.textView];
    
    [[self.textView.topAnchor constraintEqualToAnchor:self.view.topAnchor] setActive:YES];
    [[self.textView.leftAnchor constraintEqualToAnchor:self.view.leftAnchor] setActive:YES];
    [[self.textView.rightAnchor constraintEqualToAnchor:self.view.rightAnchor] setActive:YES];
    [[self.textView.bottomAnchor constraintEqualToAnchor:self.view.bottomAnchor] setActive:YES];
}

- (UIInterfaceOrientationMask)supportedInterfaceOrientations {
    return UIInterfaceOrientationMaskPortrait;
}

- (void)appendTaskToTextView:(SlyceSearchTask *)task finished:(BOOL)finished {
    NSString *stateString = [NSString stringWithFormat:@"\nSlyceSearchTask %@:\n\t", finished ? @"finished" : @"created"];
    NSMutableAttributedString *string = [[NSMutableAttributedString alloc] initWithString:stateString attributes:@{NSFontAttributeName : [UIFont systemFontOfSize:18 weight:UIFontWeightBold]}];
    
    [self appendAttributedStringToTextView:string];
    [self appendImageToTextView:task.request.image];
}

- (void)appendErrorsToTextView:(NSArray<NSError*>*)errors {
    NSMutableAttributedString *string = [[NSMutableAttributedString alloc] initWithString:@"\nSlyceSearchTask errors:\n\t" attributes:@{NSFontAttributeName : [UIFont systemFontOfSize:18 weight:UIFontWeightBold]}];
    
    for (NSError *error in errors) {
        [string appendAttributedString:[[NSAttributedString alloc] initWithString:[error.localizedDescription stringByAppendingString:@"\n"]]];
    }
    
    [self appendAttributedStringToTextView:string];
}

- (void)appendUpdateToTextView:(SlyceSearchResponseUpdate *)update {
    NSMutableAttributedString *string = [[NSMutableAttributedString alloc] initWithString:@"\nSlyceSearchTask update:\n\t" attributes:@{NSFontAttributeName : [UIFont systemFontOfSize:18 weight:UIFontWeightBold]}];
    
    [string appendAttributedString:[[NSAttributedString alloc] initWithString:[NSString stringWithFormat:@"Type: %li", update.type]]];
    [string appendAttributedString:[[NSAttributedString alloc] initWithString:[NSString stringWithFormat:@"\n\tValue: %@", update.value]]];
    
    [self appendAttributedStringToTextView:string];
}


- (void)appendResponseToTextView:(SlyceSearchResponse *) response {
    NSMutableAttributedString *string = [[NSMutableAttributedString alloc] initWithString:@"\nSlyceSearchTask response:\n\t" attributes:@{NSFontAttributeName : [UIFont systemFontOfSize:18 weight:UIFontWeightBold]}];
    
    [string appendAttributedString:[[NSAttributedString alloc] initWithString:[NSString stringWithFormat:@"Results: %@", response.results.debugDescription]]];
    [string appendAttributedString:[[NSAttributedString alloc] initWithString:[NSString stringWithFormat:@"\n\tTags: %@", response.tags.debugDescription]]];
    
    [self appendAttributedStringToTextView:string];
}


- (void)appendStringToTextView:(NSString *)string {
    [self appendAttributedStringToTextView:[[NSAttributedString alloc] initWithString:string]];
}


- (void)appendImageToTextView:(UIImage *)image {
    NSTextAttachment *imageAttachment = [[NSTextAttachment alloc] init];
    
    dispatch_async(dispatch_get_main_queue(), ^{
        CGFloat maxSize = self.view.frame.size.width - 50.0;
        
        if (image.size.height > maxSize || image.size.height > maxSize) {
            CGFloat newWidth = maxSize;
            CGFloat scale = newWidth / image.size.width;
            CGFloat newHeight = image.size.height * scale;
            UIGraphicsBeginImageContext(CGSizeMake(newWidth, newHeight));
            [image drawInRect:CGRectMake(0, 0, newWidth, newHeight)];
            UIImage *newImage = UIGraphicsGetImageFromCurrentImageContext();
            UIGraphicsEndImageContext();
            imageAttachment.image = newImage;
        } else {
            imageAttachment.image = image;
        }
    });
    
    
    [self appendAttributedStringToTextView:[NSAttributedString attributedStringWithAttachment:imageAttachment]];
}

- (void)appendAttributedStringToTextView:(NSAttributedString *)attributedString {
    dispatch_async(dispatch_get_main_queue(), ^{
        NSMutableAttributedString *appendingString = [[NSMutableAttributedString alloc] initWithAttributedString:self.textView.attributedText];
        [appendingString appendAttributedString:attributedString];
        
        NSRange endOfTextRange = NSMakeRange(appendingString.string.length - 1, 1);
        self.textView.attributedText = appendingString;
        
        dispatch_async(dispatch_get_main_queue(), ^{
            [self.textView scrollRangeToVisible:endOfTextRange];
        });
    });
}

@end
