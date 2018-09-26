#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN
__attribute__((objc_subclassing_restricted))
@interface SlyceSearchResult : NSObject <NSCoding>

/**
 * @property
 *
 * @abstract The type of SlyceSearchResult.
 *
 * @discussion This the type of response specified by Forge, for instance "TextSearch"
 *
 */
@property(nonatomic, readonly) NSString *type;


/*!
 * @property
 *
 * @abstract The identifier of the dataset where result originated.
 *
 */
@property(nonatomic, readonly) NSString *datasetIdentifier;

/*!
 * @property
 *
 * @brief The unmapped items represented by this `SlyceSearchResult`.
 *
 * @discussion Each item is a dictionary representation of a result in the format specified in its associated dataset.
 *
 */
@property(nonatomic, readonly) NSArray <NSDictionary *> *items;

@end
NS_ASSUME_NONNULL_END
