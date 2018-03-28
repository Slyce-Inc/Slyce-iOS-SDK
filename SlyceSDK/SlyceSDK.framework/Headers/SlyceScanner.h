#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import "SlyceLensIdentifiers.h"
#import "SlyceCameraDelegate.h"

@protocol SlyceScannerDelegate;
@class SlyceScannerAVCaptureAdapter;
@class SlyceScannerCameraAdapter;
@class SlyceSearchResult;


NS_ASSUME_NONNULL_BEGIN
@interface SlyceScanner : NSObject <SlyceCameraDelegate>

@property (nonatomic, readonly) NSString *identifier;

@property (nonatomic, weak, nullable) id<SlyceScannerDelegate> delegate;

@property (nonatomic, strong, readonly, nullable) AVCaptureSession *captureSession;

- (BOOL)attachToCaptureSession:(AVCaptureSession *)captureSession error:(NSError * _Nullable __autoreleasing * _Nullable)error;
- (void)detachFromCaptureSession;

- (void)suspendDetection;
- (void)resumeDetection;
@property (readonly, getter=isDetectionSuspended) BOOL detectionSuspended;

@end
NS_ASSUME_NONNULL_END



NS_ASSUME_NONNULL_BEGIN
@protocol SlyceScannerDelegate <NSObject>

- (void)slyceScanner:(SlyceScanner *)scanner didCreateRequest:(id)request
NS_SWIFT_NAME(slyce(scanner:didCreateRequest:));

- (void)slyceScanner:(SlyceScanner *)scanner didFinishWithResults:(NSArray<SlyceSearchResult  *> *)results errors:(NSArray<NSError *> *)errors
NS_SWIFT_NAME(slyce(scanner:didFinishWithResults:errors:));

- (void)slyceScanner:(SlyceScanner *)scanner didEncounterError:(nullable NSError *)error
NS_SWIFT_NAME(slyce(scanner:didEncounterError:));

@end
NS_ASSUME_NONNULL_END

