#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

#import "SlyceLensIdentifiers.h"

@protocol SlyceScannerDelegate;
@class SlyceSearchRequest;
@class SlyceSearchResult;
@class SlyceLensConfiguration;
@class SlyceSession;

NS_ASSUME_NONNULL_BEGIN
@interface SlyceScanner : NSObject


/*!
 * @method
 *
 * @brief Creates a new scanner matching the spec of the provided lens identifier.
 *
 * @param session - A valid Slyce session to link to the scanner.
 * @param lensIdentifier  - The identifier of the lens to create.
 * @param lensConfiguration - The configuration for this lens.
 * @param outError - A pointer to an error that may be emitted.
 *
 * @return a new headless lens.
 */
+ (nullable instancetype)scannerWithSession:(SlyceSession *)session lensIdentifier:(NSString *)lensIdentifier lensConfiguration:(nullable SlyceLensConfiguration *)lensConfiguration error:(SlyceOutError)outError;



/*!
 * @property
 *
 * @abstract The lens identifier associated with this scanner instance.
 */
@property (nonatomic, readonly) NSString *lensIdentifier;

/*!
 * @property
 *
 * @abstract The `SlyceScannerDelegate` for the scanner instance.
 */
@property (nonatomic, weak, nullable) id<SlyceScannerDelegate> delegate __deprecated_msg("Please use SlyceSession and SlyceSearchTask instead, SlyceScannerDelegate will be removed in a future release.");


/*!
 * @property
 *
 * @abstract A reference to the captureSession that the scanner is attached to.
 */
@property (nonatomic, strong, readonly, nullable) AVCaptureSession *captureSession;


/*!
 * @property
 *
 * @abstract The current state of detection
 */
@property (readonly, getter=isDetectionSuspended) BOOL detectionSuspended;


/*!
 * @method
 *
 * @brief Attaches the scanner to the provided capture session.
 *
 * @discussion Use this method to attach your existing captureSession to the scanner.
 *
 * @param captureSession - The AVCaptureSession.
 * @param error - An optional error that may be passed back.
 *
 * @return YES if the operation was successful.
 */
- (BOOL)attachToCaptureSession:(AVCaptureSession *)captureSession error:(NSError * _Nullable __autoreleasing * _Nullable)error NS_SWIFT_NAME(attachTo(captureSession:));


/*!
 * @method
 *
 * @brief Detaches the scanner to the provided capture session.
 */
- (void)detachFromCaptureSession;


/*!
 * @method
 *
 * @brief Suspends result detection for the scanner.
 */
- (void)suspendDetection;


/*!
 * @method
 *
 * @brief Resumes result detection for the scanner.
 */
- (void)resumeDetection;


#pragma mark Camera Pass-through

/*!
 * @property
 *
 * @brief Pass-through `AVCaptureVideoDataOutputSampleBufferDelegate`
 *
 * @discussion Setting this property will pass-through all `AVCaptureVideoDataOutputSampleBufferDelegate` delegate methods after Slyce has finished processing. This can be use to do your own processing of video frames.
 */
@property (nonatomic, weak, nullable) id<AVCaptureVideoDataOutputSampleBufferDelegate> avCaptureVideoDataOutputSampleBufferDelegate;


/*!
 * @property
 *
 * @brief Pass-through `AVCaptureMetadataOutputObjectsDelegate`
 *
 * @discussion Setting this property will pass-through all `AVCaptureMetadataOutputObjectsDelegate` delegate methods after Slyce has finished processing. This can be used to do your own processing of any detected barcodes.
 */
@property (nonatomic, weak, nullable) id<AVCaptureMetadataOutputObjectsDelegate> avCaptureMetadataOutputObjectsDelegate;


#pragma mark Deprecated

/*
 * @deprecated as of 5.1.0
 */
@property (nonatomic, readonly) NSString *identifier __deprecated_msg("Use 'lensIdentifier' instead.");

@end
NS_ASSUME_NONNULL_END



NS_ASSUME_NONNULL_BEGIN
@protocol SlyceScannerDelegate <NSObject>

@optional
/*!
 * @brief Alerts the delegate that a request has been created.
 *
 * @param scanner - The `SlyceScanner` instance.
 * @param request - The `SlyceSearchRequest` that has been created.
 *
 */
- (void)slyceScanner:(SlyceScanner *)scanner didCreateRequest:(SlyceSearchRequest *)request
NS_SWIFT_NAME(slyce(scanner:didCreateRequest:)) __deprecated_msg("Please use SlyceSession and SlyceSearchTask instead, SlyceScannerDelegate will be removed in a future release.");


/*!
 * @brief Alerts the delegate that a response has finished.
 *
 * @param scanner - The `SlyceScanner` instance.
 * @param results - An array of `SlyceSearchResult` returned by the `SlyceScanner` upon completion.
 * @param errors - An array of NSError returned by the `SlyceScanner` upon completion.
 *
 */
- (void)slyceScanner:(SlyceScanner *)scanner didFinishWithResults:(NSArray<SlyceSearchResult *> *)results errors:(NSArray<NSError *> *)errors
NS_SWIFT_NAME(slyce(scanner:didFinishWithResults:errors:)) __deprecated_msg("Please use SlyceSession and SlyceSearchTask instead, SlyceScannerDelegate will be removed in a future release.");


/*!
 * @brief Alerts the delegate that an error has been encountered.
 *
 * @param scanner - The `SlyceScanner` instance.
 * @param error - The error that has been encountered.
 *
 */
- (void)slyceScanner:(SlyceScanner *)scanner didEncounterError:(nullable NSError *)error
NS_SWIFT_NAME(slyce(scanner:didEncounterError:)) __deprecated_msg("Please use SlyceSession and SlyceSearchTask instead, SlyceScannerDelegate will be removed in a future release.");

@end
NS_ASSUME_NONNULL_END

