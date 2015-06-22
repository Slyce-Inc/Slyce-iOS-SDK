//
//  SFRequestDelegate.h
//  SlyceSDK
//
//  Created by Nathan Gurfinkel on 2/3/15.
//  Copyright (c) 2015 Slyce. All rights reserved.
//

#ifndef SlyceSDK_SFRequestDelegate_h
#define SlyceSDK_SFRequestDelegate_h

@class SFRequest;
@class SFBarcode;

/*!
 * Enumeration for 3D recognition stages.
 */

typedef NS_ENUM(NSUInteger, SFRequestStage)
{
    /// Image uploading stage.
    SFRequestStageSendingImage,
    /// Image recognition stage.
    SFRequestStageAnalyzingImage
};

/*!
 *  The protocol by which the delegate is kept notified of SFRequest scan results.
 */

@protocol SFRequestDelegate <NSObject>

@optional

///---------------------------------------------------------------------------------------
/// @name Standard/Premium
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFRequestDelegate that 3D products for the image in the request
 *  have been found. The result is an `NSDictionary` representing some metadata and the matched 3D products in key-value pairs.
 *
 *  @param sfRequest the current SFRequest.
 *  @param results `NSDictionary` containing the matched 3D products and their metadata. Guranteed to be non-`nil`.
 */

- (void)sfRequest:(SFRequest *)sfRequest didReceiveResults:(NSDictionary *)results;

/*! 
 *  @brief Informs the SFRequestDelegate that an item description for the image in the request
 *  has been found.
 *
 *  @param sfRequest the current SFRequest.
 *  @param itemDescription the `NSDictionary` representaton of the item description found. Can be empty in case no match has been found.
 */

- (void)sfRequest:(SFRequest *)sfRequest didFinishWithItemDescription:(NSDictionary *)itemDescription;

/*!
 *  @brief Informs the SFRequestDelegate that a barcode was matched.
 *
 *  @param sfRequest the current SFRequest.
 *  @param barcode recognized barcode object. Guranteed to be non-`nil`.
 *
 *  @see SFBarcode
 */

- (void)sfRequest:(SFRequest *)sfRequest didDetectBarcode:(SFBarcode *)barcode;

///---------------------------------------------------------------------------------------
/// @name Premium
///---------------------------------------------------------------------------------------
/*!
 *  @brief Informs the SFRequestDelegate that 2D products for the image in the request
 *  have been found. The result is an `NSDictionary` representing a short info about the
 *  matched products and their contents in key-value pairs.
 *
 *  @param sfRequest the current `SFRequest`.
 *  @param imageInfo `NSDictionary` represeting a short info about the matched 2D products. Can
 *  be empty in case no match has been found.
 *
 *  @note This callback may be called only if SFRequest was initialized with a Slyce
 *  object containing a Premium client ID.
 */

- (void)sfRequest:(SFRequest *)sfRequest didDetectImage:(NSDictionary *)imageInfo;

/*!
 *  @brief Informs the SFRequestDelegate that additional info for the previously
 *  recognized 2D
 *  products has been found. The result is an `NSArray` representing the additional products
 *  info in key-value pairs.
 *
 *  @param sfRequest the current `SFRequest`.
 *  @param products `NSArray` represeting the 2D products found. Cannot be `nil`.
 *
 *  @note This callback may be called only if SFRequest was previously initialized with a Slyce
 *  object containing a **Premium** client ID.
 */

- (void)sfRequest:(SFRequest *)sfRequest didReceiveImageInfo:(NSArray *)products;

///---------------------------------------------------------------------------------------
/// @name Progress Reporting
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFRequestDelegate of the progress done by reporting the stage currently being processed.
 *
 *  @param sfRequest the current SFRequest.
 *  @param stage enum representing the current recognition stage.
 *
 */

- (void)sfRequest:(SFRequest *)sfRequest didProgressToStage:(SFRequestStage)stage;

/*!
 *  @brief Informs the SFRequestDelegate of the progress done by reporting a numeric value and informative message.
 *
 *  @discussion The numeric value is a percentage from the whole process and it is float ranged from 0 to 1.
 *  The message is a short description of the current search stage.
 *
 *  @param sfRequest the current SFRequest.
 *  @param value a percentage from the whole search process (from 0 to 1).
 *  @param message a short description of the current search stage.
 *
 */
- (void)sfRequest:(SFRequest *)sfRequest didProgressToValue:(CGFloat)value withMessage:(NSString *)message;

///---------------------------------------------------------------------------------------
/// @name Error Reporting
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFRequestDelegate that an error has occured while trying to complete the SFRequest.
 *
 *  @param sfRequest the current SFRequest.
 *  @param error the encountered matching error.
 *
 */

- (void)sfRequest:(SFRequest *)sfRequest didFailWithError:(NSError *)error;

///---------------------------------------------------------------------------------------
/// @name Miscellaneous
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFRequestDelegate that the Slyce 3D search has finished.
 *
 *  @param sfRequest the current SFRequest.
 *
 */
- (void)sfRequestDidFinish:(SFRequest *)sfRequest;

/*!
 *  @brief Informs the SFRequestDelegate of the supported merchat IDs to match the search with.
 *
 *  @param sfRequest the current SFRequest.
 *  @param merchantIDs Array of merchant IDs.
 *
 */

- (void)sfRequest:(SFRequest *)sfRequest didFinishWithMerchantIDs:(NSArray *)merchantIDs;

///---------------------------------------------------------------------------------------
/// @name Deprecated
///---------------------------------------------------------------------------------------

/*!
 *  @brief Informs the SFRequestDelegate that 3D products for the image in the request
 *  have been found. The result is an `NSDictionary` representing some metadata and the matched 3D products in key-value pairs.
 *
 *  @param sfRequest the current SFRequest.
 *  @param products `NSDictionary` containing the matched 3D products and their metadata. Guranteed to be non-`nil`.
 *
 *  @deprecated since 1.9. Use sfRequest:didReceiveResults: instead.
 */

- (void)sfRequest:(SFRequest *)sfRequest didFinishWith3DProducts:(NSDictionary *)products __attribute((deprecated("This method is deprecated since 1.9. Use sfRequest:didReceiveResults: instead.")));

/*!
 *  @brief Informs the SFRequestDelegate that a barcode was matched.
 *
 *  @param sfRequest the current SFRequest.
 *  @param barcode recognized barcode object. Guranteed to be non-`nil`.
 *
 *  @see SFBarcode
 *
 *  @deprecated since 1.9. Use sfRequest:didDetectBarcode: instead.
 */

- (void)sfRequest:(SFRequest *)sfRequest didRecognizeBarcode:(SFBarcode *)barcode __attribute((deprecated("This method is deprecated since 1.9. Use sfRequest:didDetectBarcode: instead.")));

/*!
 *  @brief Informs the SFRequestDelegate that 2D products for the image in the request
 *  have been found. The result is base64 encoded string representation of the products
 *  along with an additional `NSDictionary` representing a short info about the matched products
 *  and their contents in key-value pairs.
 *
 *  @param sfRequest the current `SFRequest`.
 *  @param encodedString string representing the recognized 2D products in base64 format. Can be
 *  en empty string in case no match has been found.
 *  @param productInfo `NSDictionary` represeting a short info about the matched 2D products. Can
 *  be empty in case no match has been found.
 *
 *  @note This callback may be called only if SFRequest was initialized with a Slyce
 *  object containing a Premium client ID.
 *
 *  @deprecated since 1.9. Use sfRequest:didDetectImage: instead.
 */

- (void)sfRequest:(SFRequest *)sfRequest didFinishWithEncodedString:(NSString *)encodedString and2DProductInfo:(NSDictionary *)productInfo __attribute((deprecated("This method is deprecated since 1.9. Use sfRequest:didDetectImage: instead.")));

/*!
 *  @brief Informs the SFRequestDelegate that additional info for the previously
 *  recognized 2D
 *  products has been found. The result is an `NSArray` representing the additional products
 *  info in key-value pairs.
 *
 *  @param sfRequest the current `SFRequest`.
 *  @param products `NSArray` represeting the 2D products found. Cannot be `nil`.
 *
 *  @note This callback may be called only if SFRequest was previously initialized with a Slyce
 *  object containing a **Premium** client ID.
 *
 *  @deprecated since 1.9. Use sfRequest:didReceiveImageInfo: instead.
 */

- (void)sfRequest:(SFRequest *)sfRequest didFinishWithExtendedInfoFor2DProducts:(NSArray *)products __attribute((deprecated("This method is deprecated since 1.9. Use sfRequest:didReceiveImageInfo: instead.")));

@end

#endif
