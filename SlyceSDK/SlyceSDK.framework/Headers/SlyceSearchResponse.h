#import <Foundation/Foundation.h>

@class SlyceSearchProgress;
@class SlyceSearchResult;

NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchResponse : NSObject <NSCoding>

@property (nonatomic, readonly, copy) NSString *jobIdentifier;
@property (nullable, nonatomic, readonly, strong) NSArray<SlyceSearchResult *> *results;

@end
NS_ASSUME_NONNULL_END
