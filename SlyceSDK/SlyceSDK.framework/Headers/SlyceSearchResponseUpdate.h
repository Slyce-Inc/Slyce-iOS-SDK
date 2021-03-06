#import "SlyceBase.h"

typedef NS_ENUM(NSUInteger, SlyceSearchResponseUpdateType) {
    /// Indicates a job was created on the backend service. The `value` property will be an NSString containing the job id.
    SlyceSearchResponseUpdateTypeJobCreated,
    /// Indicates a tag was found during the search process. The `value` property will be an NSString containing the tag. The full list of tags are also available on the associated response object.
    SlyceSearchResponseUpdateTypeTagFound,
    /// Indicates that results were received. The `value` property will be an NSArray of SlyceSearchResults objects. The search results are also available on the associated response object.
    SlyceSearchResponseUpdateTypeResultsReceived,
    /// Indicates that an image was successfully uploaded to the backend service. The `value` property will be `nil`.
    SlyceSearchResponseUpdateTypeImageUploaded,
};

@class SlyceSearchResponse;

/**
 * @discussion An object representing updates sent via a `SlyceSearchTaskListener`.
 */
NS_ASSUME_NONNULL_BEGIN
__attribute__((objc_subclassing_restricted))
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
