//
//  SFCameraViewDelegate.h
//  SlyceSDK
//
//  Created by Nathan Gurfinkel on 2/4/15.
//  Copyright (c) 2015 Slyce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SFRequestDelegate.h"

#ifndef SlyceSDK_SFCameraViewDelegate_h
#define SlyceSDK_SFCameraViewDelegate_h

@class SFCameraView;
@class SFBarcode;

/*!
 *  The protocol by which the delegate is kept notified of SFCamera's operations and scan 
 *  results.
 */

@protocol SFCameraViewDelegate <NSObject>

@optional

///---------------------------------------------------------------------------------------
/// @name Standard/Premium
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewDelegate that 3D products for the image snapped
 *  have been found. The result is an `NSDictionary` representing some metadata and the matched 3D products in key-value pairs.
 *
 *  @param cameraView the current SFCameraView.
 *  @param results `NSDictionary` representing the matched 3D products and some metadata. Guranteed to be non-`nil`.
 */

- (void)sfCameraView:(SFCameraView *)cameraView didReceiveResults:(NSDictionary *)results;

/*!
 *  @brief Informs the SFCameraViewDelegate that an item description for the image snapped
 *  has been found.
 *
 *  @param cameraView the current SFCameraView.
 *  @param itemDescription the `NSDictionary` representaton of the item description found. Can be empty in case no match has been found.
 */

- (void)sfCameraView:(SFCameraView *)cameraView didFinishWithItemDescription:(NSDictionary *)itemDescription;

/*!
 *  @brief Informs the SFCameraViewDelegate that a barcode was matched.
 *
 *  @param cameraView the current SFCameraView.
 *  @param barcode recognized barcode object. Guranteed to be non-`nil`.
 *
 *  @warning **Important:** the auto scanner session automatically pauses processing before calling
 *  this method. This means the caller must call [SFCameraView resumeCapture] when frames should start being processed again.
 *
 *  @see SFBarcode
 */

- (void)sfCameraView:(SFCameraView *)cameraView didDetectBarcode:(SFBarcode *)barcode;

///---------------------------------------------------------------------------------------
/// @name Premium
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewDelegate that 2D products for the image from the current video
 *  frame have been found. The result is an `NSDictionary` representing a short info about the matched products and their contents in key-value pairs.
 *
 *  @param cameraView the current `SFCameraView`.
 *  @param imageInfo `NSDictionary` represeting a short info about the matched 2D products. Can
 *  be `nil` in case no match has been found.
 *
 *  @note This callback may be called only if SFCameraView was initialized with a Slyce
 *  object containing a Premium client ID.
 *
 * @warning **Important:** the auto scanner session automatically pauses processing before calling
 * this method. This means the caller must call [SFCameraView resumeCapture] when frames should start being processed again. If you do not wish to stop the scanner, set [SFCameraView shouldPauseScannerAfterRecognition] to `NO`.
 */

- (void)sfCameraView:(SFCameraView *)cameraView didDetectImage:(NSDictionary *)imageInfo;

/*!
 *  @brief Informs the SFCameraViewDelegate that additional info for the previously recognized 2D
 *  products has been found. The result is an `NSArray` representing the additional products
 *  info in key-value pairs.
 *
 *  @param cameraView the current `SFCameraView`.
 *  @param products `NSArray` represeting the 2D products found. Cannot be `nil`.
 *
 *  @note This callback is Premium. It will be called as soon as additional info will be ready and
 *  *AFTER* sfCameraView:didDetectImage: returned non-`nil` products.
 *
 *  @note This callback may be called only if SFCameraView was initialized with a Slyce
 *  object containing a Premium client ID.
 */

- (void)sfCameraView:(SFCameraView *)cameraView didReceiveImageInfo:(NSArray *)products;

///---------------------------------------------------------------------------------------
/// @name Progress Reporting
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewDelegate of the progress done in matching the image snapped by reporting the stage
 *  currently being processed.
 *
 *  @param cameraView the current SFCameraView.
 *  @param stage enum representing the current recognition stage.
 *
 */

- (void)sfCameraView:(SFCameraView *)cameraView didProgressToStage:(SFRequestStage)stage;

/*!
 *  @brief Informs the SFCameraViewDelegate of the progress done in matching the image snapped by reporting a numeric value and
 *  informative message.
 *
 *  @discussion The numeric value is a percentage from the whole process and it is float ranged from 0 to 1.
 *  The message is a short description of the current search stage.
 *
 *  @param cameraView the current SFCameraView.
 *  @param value a percentage from the whole search process (from 0 to 1).
 *  @param message a short description of the current search stage.
 *
 */
- (void)sfCameraView:(SFCameraView *)cameraView didProgressToValue:(CGFloat)value withMessage:(NSString *)message;

///---------------------------------------------------------------------------------------
/// @name Error Reporting
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewDelegate that an error has occured while trying to fulfil 
 *  some task of the 2D recognition engine (verification of credentials, sync with local storage,
 *  no response from the matching server, etc). This method is only called when using the Premium 
 *  account.
 *
 *  @param cameraView the current SFCameraView`.
 *  @param error the encountered scanning error.
 */

- (void)sfCameraView:(SFCameraView *)cameraView didFailWithError:(NSError *)error;

///---------------------------------------------------------------------------------------
/// @name Miscellaneous
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewDelegate that the Slyce 3D search has finished.
 *
 *  @param cameraView the current SFCameraView.
 *  @param statusType the status about the current request. Refer to SFRequest:SFStatusType to see the possible status values.
 *
 *  @see SFRequest
 *
 */
- (void)sfCameraViewDidFinish:(SFCameraView *)cameraView withStatus:(SFStatusType)statusType;

/*!
 *  @brief Informs the SFCameraViewDelegate that an image object from the current video frame is ready.
 *
 *  @param cameraView the current SFCameraView.
 *  @param image image representing the video frame captured when SFCameraView’s snap method was invoked.
 */

- (void)sfCameraView:(SFCameraView *)cameraView didSnapImage:(UIImage *)image;

/*!
 *  @brief Informs the delegate the image matching process has started.
 *
 *  @param cameraView the current SFCameraView.
 *  @param request the request fulfilling the image recognition.
 *  @param image the image being searched. The image is the video frame captured when
 *  SFCameraView's snap method was invoked.
 */

- (void)sfCameraView:(SFCameraView *)cameraView didStartRequest:(SFRequest *)request forImage:(UIImage *)image;

/*!
 *  @brief Informs the SFCameraViewDelegate that the scanner was touched in a specific point.
 *
 *  @param cameraView the current SFCameraView.
 *  @param point point representing a touch location in the presenting view (the one that SFCameraView object was initialized with) coordinate system.
 */

- (void)sfCameraView:(SFCameraView *)cameraView wasTappedInPoint:(CGPoint)point;

///---------------------------------------------------------------------------------------
/// @name Deprecated
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewDelegate that 3D products for the image snapped
 *  have been found. The result is an `NSDictionary` representing some metadata and the matched 3D products in key-value pairs.
 *
 *  @param cameraView the current SFCameraView.
 *  @param products `NSDictionary` representing the matched 3D products and some metadata. Guranteed to be non-`nil`.
 *
 *  @deprecated since 1.9. Use sfCameraView:didReceiveResults: instead.
 */

- (void)sfCameraView:(SFCameraView *)cameraView didFinishWith3DProducts:(NSDictionary *)products __attribute((deprecated("This method is deprecated since 1.9. Use sfCameraView:didReceiveResults: instead.")));

/*!
 *  @brief Informs the SFCameraViewDelegate that a barcode was matched.
 *
 *  @param cameraView the current SFCameraView.
 *  @param barcode recognized barcode object. Guranteed to be non-`nil`.
 *
 *  @warning **Important:** the auto scanner session automatically pauses processing before calling
 *  this method. This means the caller must call [SFCameraView resumeCapture] when frames should start being processed again.
 *
 *  @see SFBarcode
 *
 *  @deprecated since 1.9. Use sfCameraView:didDetectBarcode: instead.
 */

- (void)sfCameraView:(SFCameraView *)cameraView didRecognizeBarcode:(SFBarcode *)barcode __attribute((deprecated("This method is deprecated since 1.9. Use sfCameraView:didDetectBarcode: instead.")));

/*!
 *  @brief Informs the SFCameraViewDelegate that 2D products for the image from the current video
 *  frame have been found. The result is base64 encoded string representation of the products
 *  along with an additional `NSDictionary` representing a short info about the matched products
 *  and their contents in key-value pairs.
 *
 *  @param cameraView the current `SFCameraView`.
 *  @param encodedString string representing the recognized 2D products in base64 format. Can be
 *  `nil` in case no match has been found.
 *  @param productInfo `NSDictionary` represeting a short info about the matched 2D products. Can
 *  be `nil` in case no match has been found.
 *
 *  @note This callback may be called only if SFCameraView was initialized with a Slyce
 *  object containing a Premium client ID.
 *
 * @warning **Important:** the auto scanner session automatically pauses processing before calling
 * this method. This means the caller must call [SFCameraView resumeCapture] when frames should start being processed again. If you do not wish to stop the scanner, set [SFCameraView shouldPauseScannerAfterRecognition] to `NO`.
 *
 * @deprecated since 1.9. Use sfCameraView:didDetectImage: instead.
 */

- (void)sfCameraView:(SFCameraView *)cameraView didFinishWithEncodedString:(NSString *)encodedString and2DProductInfo:(NSDictionary *)productInfo __attribute((deprecated("This method is deprecated since 1.9. Use sfCameraView:didDetectImage: instead.")));

/*!
 *  @brief Informs the SFCameraViewDelegate that additional info for the previously recognized 2D
 *  products has been found. The result is an `NSArray` representing the additional products
 *  info in key-value pairs.
 *
 *  @param cameraView the current `SFCameraView`.
 *  @param products `NSArray` represeting the 2D products found. Cannot be `nil`.
 *
 *  @note This callback is Premium. It will be called as soon as additional info will be ready and
 *  *AFTER* sfCameraView:didDetectImage: returned non-`nil` products.
 *
 *  @note This callback may be called only if SFCameraView was initialized with a Slyce
 *  object containing a Premium client ID.
 *
 *  @deprecated since 1.9. Use sfCameraView:didReceiveImageInfo: instead.
 */

- (void)sfCameraView:(SFCameraView *)cameraView didFinishWithExtendedInfoFor2DProducts:(NSArray *)products __attribute((deprecated("This method is deprecated since 1.9. Use sfCameraView:didReceiveImageInfo: instead.")));

@end

#endif