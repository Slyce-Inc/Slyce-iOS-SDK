#import <UIKit/UIKit.h>

@protocol SlyceMappable <NSObject>

@property (strong, nonatomic) NSString *identifier;
@property (strong, nonatomic) NSString *name;
@property (copy, nonatomic) NSString *description;
@property (strong, nonatomic) NSString *imageURL;
@property (strong, nonatomic) NSString *url;
@property (strong, nonatomic) NSString *price;
@property (strong, nonatomic) NSString *thumbnailURL;

- (instancetype)init;

@end

