
#import "TextViewViewController.h"

NS_ASSUME_NONNULL_BEGIN

// This class performs a Slyce visual search immediately when launched.
// In order to get results, the user MUST already have opened Slyce.
// In order to send the search through the correct workflow, the workflow key is included.

@interface VisualSearchViewController : TextViewViewController

- (instancetype)init;

@end

NS_ASSUME_NONNULL_END
