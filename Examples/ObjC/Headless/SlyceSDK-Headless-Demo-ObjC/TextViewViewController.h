
#import <UIKit/UIKit.h>
#import <SlyceSDK/SlyceSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface TextViewViewController : UIViewController

- (void)appendStringToTextView:(NSString *)string;

- (void)appendTaskToTextView:(SlyceSearchTask *)task finished:(BOOL)finished;

- (void)appendErrorsToTextView:(NSArray<NSError*>*)errors;

- (void)appendUpdateToTextView:(SlyceSearchResponseUpdate *)update;

- (void)appendResponseToTextView:(SlyceSearchResponse *) response;

@end

NS_ASSUME_NONNULL_END
