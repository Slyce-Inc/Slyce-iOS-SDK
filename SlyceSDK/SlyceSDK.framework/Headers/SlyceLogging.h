#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, SlyceLogLevel) {
    SlyceLogLevelVerbose = 2,
    SlyceLogLevelDebug   = 3,
    SlyceLogLevelInfo    = 4,
    SlyceLogLevelWarning = 5,
    SlyceLogLevelError   = 6,
    SlyceLogLevelNone    = NSUIntegerMax

};

extern const NSUInteger SlyceDefaultLogLevel;

NS_ASSUME_NONNULL_BEGIN
@protocol SlyceLogger <NSObject>

- (void)info:(NSString *)message;
- (void)warning:(NSString *)message;
- (void)error:(NSString *)message;

@end
NS_ASSUME_NONNULL_END


NS_ASSUME_NONNULL_BEGIN
@interface SlyceLogging : NSObject

+ (instancetype)shared;

@property (nonatomic, assign) SlyceLogLevel logLevel;

@property (nonatomic, strong) id<SlyceLogger> logger;

@end
NS_ASSUME_NONNULL_END
