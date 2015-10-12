//
//  SFCameraViewControllerDelegate.h
//  SlyceSDK
//
//  Created by Nathan Gurfinkel on 2/9/15.
//  Copyright (c) 2015 Slyce. All rights reserved.
//

#ifndef SlyceSDK_SFCameraViewControllerDelegate_h
#define SlyceSDK_SFCameraViewControllerDelegate_h

#import "SFRequestDelegate.h"

@class SFBarcode;
@class SFCameraViewController;
@class SFRequest;

/*!
 *  The protocol by which the delegate is kept notified of SFCameraViewController's various functionalities.
 */

@protocol SFCameraViewControllerDelegate <NSObject>

@optional

///---------------------------------------------------------------------------------------
/// @name Standard/Premium
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewControllerDelegate that the continuous scanner did recognize a barcode.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param barcode recognized barcode object. Guranteed to be non-`nil`.
 *
 *  @see SFBarcode
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didDetectBarcode:(SFBarcode *)barcode;

///---------------------------------------------------------------------------------------
/// @name Premium
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewControllerDelegate that additional info for the previously
 *  recognized barcode has been found.
 *  The result is an `NSURL` representing the additional the url to the matched product.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param productURL `NSURL` represeting the url to the product found. Cannot be `nil`.
 *
 *  @note This callback may be called only if SFCameraViewController was initialized with a Slyce
 *  object containing a Premium client ID.
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didReceiveBarcodeInfo:(NSURL *)productURL;

/*!
 *  @brief Informs the SFCameraViewControllerDelegate that 2D products for the image from the 
 *  current video
 *  frame have been found. The result is an `NSDictionary` representing a short info about the matched products
 *  and their contents in key-value pairs.
 *  have been found. This method is called upon a successful match either from a live video preview 
 *  (automatic match) or from an image -
 *  either captured by pressing the *snap* button or picked from the Photo Library (manual match).
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param imageInfo `NSDictionary` represeting a short info about the matched 2D products. Can
 *  be `nil` in case no match has been found.
 *
 *  @note This callback may be called only if SFCameraViewController was initialized with a 
 *  Slyce  object containing a Premium client ID.
 *  
 *  @warning **Important:** the auto scanner session automatically pauses processing before 
 *  calling this method. This means the caller must call [SFCameraView resumeCapture] when
 *  frames should start being processed again. If you do not wish to stop the scanner, set 
 *  [SFCameraView shouldPauseScannerAfterRecognition] to `NO`.
 *
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didDetectImage:(NSDictionary *)imageInfo;

/*!
 *  @brief Informs the SFCameraViewControllerDelegate that additional info for the previously
 *  recognized 2D
 *  products has been found. The result is an `NSArray` representing the additional products
 *  info in key-value pairs.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param products `NSArray` represeting the 2D products found. Cannot be `nil`.
 *
 *  @note This callback is Premium. It will be called as soon as additional info will be ready 
 *  and *AFTER* sfCameraViewController:didDetectImage: returned non-`nil products.
 *
 *  @note This callback may be called only if SFCameraViewController was initialized with a 
 *  Slyce object containing a Premium client ID.
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didReceiveImageInfo:(NSArray *)products;

///---------------------------------------------------------------------------------------
/// @name Standard
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewControllerDelegate that 3D products for the image from the current
 *  video frame or from Photo Library has been found. This method is called upon a successful
 *  match from a *manual* request - either from an image captured by pressing the *snap* button or
 *  from an image picked from the Photo Library.
 *
 *  You must press the *snap* button or pick a photo from the Photo Library on the device in order
 *  to start the 3D recognition process.
 *
 *  The result is an `NSDictionary` representing the matched 3D products and some metadata. Guranteed to be non-`nil`.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param results NSDictionary represeting the matched 3D products and some metadata. Cannot be `nil`.
 *
 *  @note Note that 3D products cannot be matched automatically, i.e. by a continuous scanner.
 *
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didReceiveResults:(NSDictionary *)results;

///---------------------------------------------------------------------------------------
/// @name Error Reporting
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs that an error has occured while trying to fulfil some task of the 2D recognition engine (verification of credentials,
 *  sync with local storage, no response from the matching server, etc).
 *
 *  This method is only called when using the Premium account.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param error the encountered scanning error.
 *
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didFailWithError:(NSError *)error;

///---------------------------------------------------------------------------------------
/// @name Progress Reporting
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewControllerDelegate of the progress done in matching the 
 *  image snapped by reporting the stage
 *  currently being processed.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param stage enum representing the current recognition stage.
 *
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didProgressToStage:(SFRequestStage)stage;

/*!
 *  @brief Informs the SFCameraViewControllerDelegate of the progress done in matching the 
 *  image snapped by reporting a numeric value and
 *  informative message.
 *
 *  @discussion The numeric value is a percentage from the whole process and it is float ranged from 0 to 1.
 *  The message is a short description of the current search stage.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param value a percentage from the whole search process (from 0 to 1).
 *  @param message a short description of the current search stage.
 *
 */
- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didProgressToValue:(CGFloat)value withMessage:(NSString *)message;

///---------------------------------------------------------------------------------------
/// @name Miscellaneous
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewControllerDelegate that the Slyce 3D search has finished.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param statusType the status about the current request. Refer to SFRequest:SFStatusType to see the possible status values.
 *
 *  @see SFRequest
 *
 */
- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didFinishWithStatus:(SFStatusType)statusType;

/*!
 *  @brief Informs the SFCameraViewControllerDelegate that an image object from the current video frame is ready.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param image representing the video frame captured when pressed the snap button.
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didSnapImage:(UIImage *)image;

/*!
 *  @brief Informs the delegate the image matching process has started.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param request the request fulfilling the image recognition.
 *  @param image the image being searched. The image is the video frame captured when
 *  `snap` button was pressed.
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didStartRequest:(SFRequest *)request forImage:(UIImage *)image;

/*!
 *  @brief Informs the delegate the camera view controller finished dismissing.
 *
 *  @param cameraViewController the current SFCameraViewController.
 */

- (void)sfCameraViewControllerWasDismissed:(SFCameraViewController *)cameraViewController;

///---------------------------------------------------------------------------------------
/// @name Deprecated
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFCameraViewControllerDelegate that 3D products for the image from the current
 *  video frame or from Photo Library has been found. This method is called upon a successful
 *  match from a *manual* request - either from an image captured by pressing the *snap* button or
 *  from an image picked from the Photo Library.
 *
 *  You must press the *snap* button or pick a photo from the Photo Library on the device in order
 *  to start the 3D recognition process.
 *
 *  The result is an `NSDictionary` representing the matched 3D products and some metadata. Guranteed to be non-`nil`.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param products NSDictionary represeting the matched 3D products and some metadata. Cannot be `nil`.
 *
 *  @note Note that 3D products cannot be matched automatically, i.e. by a continuous scanner.
 *
 *
 *  @deprecated since 1.9. Use sfCameraViewController:didReceiveResults: instead.
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didFinishWith3DProducts:(NSDictionary *)products __attribute((deprecated("This method is deprecated since 1.9. Use sfCameraViewController:didReceiveResults: instead.")));

/*!
 *  @brief Informs the SFCameraViewControllerDelegate that the continuous scanner did recognize a barcode.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param barcode recognized barcode object. Guranteed to be non-`nil`.
 *
 *  @see SFBarcode
 *
 *  @deprecated since 1.9. Use sfCameraViewController:didDetectBarcode: instead.
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didRecognizeBarcode:(SFBarcode *)barcode __attribute((deprecated("This method is deprecated since 1.9. Use sfCameraViewController:didDetectBarcode: instead.")));

/*!
 *  @brief Informs the SFCameraViewControllerDelegate that 2D products for the image from the
 *  current video
 *  frame have been found. The result is base64 encoded string representation of the products
 *  along with an additional `NSDictionary` representing a short info about the matched products
 *  and their contents in key-value pairs.
 *  have been found. This method is called upon a successful match either from a live video preview
 *  (automatic match) or from an image -
 *  either captured by pressing the *snap* button or picked from the Photo Library (manual match).
 *
 *  The result is an `NSDictionary` representing matched products and their contents in key-value
 *  pairs.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param encodedString string representing the recognized 2D products in base64 format. Can be
 *  `nil` in case no match has been found.
 *  @param productInfo `NSDictionary` represeting a short info about the matched 2D products. Can
 *  be `nil` in case no match has been found.
 *
 *  @note This callback may be called only if SFCameraViewController was initialized with a Slyce
 *  object containing a Premium client ID.
 * @warning **Important:** the auto scanner session automatically pauses processing before calling
 * this method. This means the caller must call [SFCameraView resumeCapture] when frames should start being processed again. If you do not wish to stop the scanner, set [SFCameraView shouldPauseScannerAfterRecognition] to `NO`.
 *
 *  @deprecated since 1.9. Use sfCameraViewController:didDetectImage: instead.
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didFinishWithEncodedString:(NSString *)encodedString and2DProductInfo:(NSDictionary *)productInfo __attribute((deprecated("This method is deprecated since 1.9. Use sfCameraViewController:didDetectImage: instead.")));

/*!
 *  @brief Informs the SFCameraViewControllerDelegate that additional info for the previously
 *  recognized 2D
 *  products has been found. The result is an `NSArray` representing the additional products
 *  info in key-value pairs.
 *
 *  @param cameraViewController the current SFCameraViewController.
 *  @param products `NSArray` represeting the 2D products found. Cannot be `nil`.
 *
 *  @note This callback is Premium. It will be called as soon as additional info will be ready and
 *  *AFTER* sfCameraViewController:didDetectImage: returned non-`nil`
 *  products.
 *
 *  @note This callback may be called only if SFCameraViewController was initialized with a Slyce
 *  object containing a Premium client ID.
 *
 *  @deprecated since 1.9. Use sfCameraViewController:didReceiveImageInfo: instead.
 */

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didFinishWithExtendedInfoFor2DProducts:(NSArray *)products __attribute((deprecated("This method is deprecated since 1.9. Use sfCameraViewController:didReceiveImageInfo: instead.")));

@end

#endif
