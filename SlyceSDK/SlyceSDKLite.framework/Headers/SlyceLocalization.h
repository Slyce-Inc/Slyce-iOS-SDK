#import <Foundation/Foundation.h>

typedef NSString *_Nullable (^SlyceLocalizationHandler)(NSString * _Nonnull);

@interface SlyceLocalization : NSObject

+ (void)setCustomLocalizationHandler:(nullable SlyceLocalizationHandler)handler;

@end
