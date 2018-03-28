#import <UIKit/UIKit.h>

typedef NS_ENUM(NSUInteger, SlyceSearchRequestMethod) {
    SlyceSearchRequestMethodWebSocket,
//    SlyceSearchRequestMethodHTTP,
};

NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchRequest : NSObject

- (instancetype)initWithMethod:(SlyceSearchRequestMethod)method NS_DESIGNATED_INITIALIZER;

@property (nonatomic, strong, readonly) NSDate *timestamp;
@property (nonatomic, copy, readonly) NSString *identifier;
@property (nonatomic, assign, readonly) SlyceSearchRequestMethod method;

#pragma mark Input Image

@property (nonatomic, strong, nullable) UIImage *image;
@property (nonatomic, copy, nullable) NSString *imageURL;
@property (nonatomic, copy, nullable) NSString *filePath;

@property (nonatomic, assign) CGPoint anchor;

#pragma mark -

- (NSDictionary *)workflowOptions;
- (NSDictionary *)encodedRequest;

@end
NS_ASSUME_NONNULL_END
