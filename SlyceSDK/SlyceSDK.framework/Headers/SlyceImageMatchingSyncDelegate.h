#import <Foundation/Foundation.h>

@class Slyce;

NS_ASSUME_NONNULL_BEGIN
@protocol SlyceImageMatchingSyncDelegate <NSObject>

- (void)slyceImageMatchingSyncDidStart:(Slyce *)slyce
NS_SWIFT_NAME(slyce(imageMatchingSyncDidStart:));

- (void)slyceImageMatchingSyncDidFinish:(Slyce *)slyce
NS_SWIFT_NAME(slyce(imageMatchingSyncDidFinish:));

- (void)slyce:(Slyce *)slyce imageMatchingSyncFailedWithMessage:(NSString *)failMesage
NS_SWIFT_NAME(slyce(_:imageMatchingSyncFailedWithMessage:));

- (void)slyce:(Slyce *)slyce imageMatchingSyncedCatalogCount:(NSInteger)count fromTotalCount:(NSInteger)total
NS_SWIFT_NAME(slyce(_:imageMatchingSyncedCatalogCount:fromTotalCount:));

@end
NS_ASSUME_NONNULL_END
