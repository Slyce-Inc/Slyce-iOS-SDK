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

/*!
 * @property
 *
 * @brief A set of tags returned by this `SlyceSearchTask`.
 *
 * @discussion The tags represent keywords that are produced by the Workflow that backs this `SlyceSearchTask`. These tags will be updated as the task goes through its progression.
 *
 */
@property (nonatomic, readonly) NSOrderedSet<NSString *> *tags;

/**
 * @property
 * @abstract An array of `SlyceSearchResult` returned by a `SlyceSearchTask`.
 */
@property (nullable, nonatomic, readonly, strong) NSArray<SlyceSearchResult *> *results;

@end
NS_ASSUME_NONNULL_END
