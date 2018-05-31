#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, SlyceSearchResponseUpdateType) {
    /// Indicates a job was created on the backend service. The `value` property will be an NSString containing the job id.
    SlyceSearchResponseUpdateTypeJobCreated,
    /// Indicates a tag was found during the search process. The `value` property will be an NSString containing the tag. The full list of tags are also available on the associated response object.
    SlyceSearchResponseUpdateTypeTagFound,
    /// Indicates that results were received. The `value` property will be an NSArray of SlyceSearchResults objects. The search results are also available on the associated response object.
    SlyceSearchResponseUpdateTypeResultsReceived,
};

@class SlyceSearchResponse;

/**
 * @discussion An object representing updates sent via a `SlyceSearchTaskListener`.
 */
NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchResponseUpdate : NSObject

/**
 * @property
 *
 * @brief Gets the `SlyceSearchResponse` associated with this update. This property
 * cannot be null.
 */
@property (nonatomic, readonly) SlyceSearchResponse *response;

/*
 * @property
 *
 * @brief The type of update. See `SlyceSearchResponseUpdateType`.
 */
@property (nonatomic, readonly) SlyceSearchResponseUpdateType type;

    
/*
 * @property
 *
* @brief Gets the value associated with this update.
 */
@property (nonatomic, readonly, nullable) id value;

@end
NS_ASSUME_NONNULL_END
