#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface SlyceCredentials : NSObject <NSCopying>

@property (nonatomic, copy, readonly) NSString *accountIdentifier;
@property (nonatomic, copy, readonly) NSString *spaceIdentifier;

- (BOOL)isEqualToCredentials:(SlyceCredentials *)other;

@end
NS_ASSUME_NONNULL_END
