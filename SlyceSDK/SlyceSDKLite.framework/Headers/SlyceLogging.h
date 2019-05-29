#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, SlyceLogLevel) {
    SlyceLogLevelVerbose = 2,
    SlyceLogLevelDebug   = 3,
    /** Log informational messages, warnings, and errors. */
    SlyceLogLevelInfo    = 4,
    /** Log warnings and errors. */
    SlyceLogLevelWarning = 5,
    /** Log errors only. */
    SlyceLogLevelError   = 6,
    /** No logging. Default in Production builds. */
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


/** Slyce logging system. */
NS_ASSUME_NONNULL_BEGIN
__attribute__((objc_subclassing_restricted))
@interface SlyceLogging : NSObject

+ (instancetype)shared;

/** Set the log level. */
@property (nonatomic, assign) SlyceLogLevel logLevel;

/** Set a custom logger implementation */
@property (nonatomic, strong) id<SlyceLogger> logger;

@end
NS_ASSUME_NONNULL_END
