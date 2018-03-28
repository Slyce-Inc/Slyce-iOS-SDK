#import <Foundation/Foundation.h>

@class SlyceSearchTask;
@class SlyceSearchProgress;
@class SlyceSearchResult;

NS_ASSUME_NONNULL_BEGIN

@protocol SlyceSearchTaskDelegate <NSObject>

- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didUpdateWithProgress:(SlyceSearchProgress *)progress
NS_SWIFT_NAME(slyce(searchTask:didUpdateWithResponse:));

- (void)slyceSearchTask:(SlyceSearchTask *)searchTask didFinishWithResults:(NSArray<SlyceSearchResult *> *)results errors:(NSArray<NSError *> *)errors
NS_SWIFT_NAME(slyce(searchTask:didFinishWithResult:errors:));

@end


@interface SlyceSearchTask : NSObject

@property (nonatomic, weak, nullable) id<SlyceSearchTaskDelegate> delegate;

- (void)start;

@end

NS_ASSUME_NONNULL_END
