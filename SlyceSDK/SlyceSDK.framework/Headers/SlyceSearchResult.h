#import <Foundation/Foundation.h>

@protocol SlyceMappable;

NS_ASSUME_NONNULL_BEGIN
@interface SlyceSearchResult : NSObject <NSCoding>

- (instancetype)initWithType:(NSString *)type mappingIdentifier:(NSString *)mappingIdentifier items:(NSArray <NSDictionary *> *)items
NS_DESIGNATED_INITIALIZER;

- (NSString *)type;
- (NSString *)mappingIdentifier;
- (NSArray <NSDictionary *> *)items;

@property(nonatomic, strong) NSArray<id<SlyceMappable>> *mappedItems;

@end
NS_ASSUME_NONNULL_END
