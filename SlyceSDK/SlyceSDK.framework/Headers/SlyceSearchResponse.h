#import <Foundation/Foundation.h>

@class SlyceSearchResult;

NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchResponse : NSObject <NSCoding>

/**
 * @property
 * @abstract The job identifier created by Forge.
 * 
 */
@property (nonatomic, readonly, copy) NSString *jobIdentifier;

/**
 * @property
 * @abstract An array of `SlyceSearchResult` returned by a `SlyceSearchTask`.
 */
@property (nullable, nonatomic, readonly, strong) NSArray<SlyceSearchResult *> *results;

@end
NS_ASSUME_NONNULL_END
