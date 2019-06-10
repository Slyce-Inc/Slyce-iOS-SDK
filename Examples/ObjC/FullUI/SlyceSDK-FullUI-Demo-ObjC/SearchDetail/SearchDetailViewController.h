
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface SearchDetailViewController : UIViewController

@property(nonatomic, weak) IBOutlet UITextView *itemTextView;

@property(nonatomic, strong) NSDictionary *item;

@end

NS_ASSUME_NONNULL_END
