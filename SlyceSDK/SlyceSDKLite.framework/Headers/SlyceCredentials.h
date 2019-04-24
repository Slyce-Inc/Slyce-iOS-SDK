#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
__attribute__((objc_subclassing_restricted))
@interface SlyceCredentials : NSObject <NSCopying>

@property (nonatomic, copy, readonly) NSString *accountIdentifier;
@property (nonatomic, copy, readonly) NSString *spaceIdentifier;

- (BOOL)isEqualToCredentials:(SlyceCredentials *)other;

@end
NS_ASSUME_NONNULL_END
