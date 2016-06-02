//
//  SFRequest.h
//  SlyceSDK
//
//  Created by Nathan Gurfinkel on 2/3/15.
//  Copyright (c) 2015 Slyce. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SFRequestDelegate.h"
#import "SFCameraView.h"

@class SFSlyce;




/*!
 *  Provides a way to perform visual search without using SDK’s integral camera functionality.
 *
 *  Set of asynchronuous methods that allow developers to send a request for recognition by providing an UIImage object or an NSURL to the image.
 *
 */

@interface SFRequest : NSObject




///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------

/*!
 *  @property
 *  @brief The unique identifier of the request.
 *  @discussion The request ID is generated *only* after making the actual request, i.e. after 
 *  calling one of SFRequest's methods.
 */

@property (nonatomic, copy) NSString *requestID;

/*!
 *  @property
 *  @brief Options dictionary.
 *  @discussion Use this dictionary to pass properties to Slyce servers.
 *  For example: @{@"storeID" : @"1234", @"state" : @"CA"}. Can be `nil`.
 */

@property (nonatomic, copy) NSDictionary *options;

/*!
 *  @property
 *  @brief The request delegate that will be notified of the results.
 */
@property (nonatomic, weak) id<SFRequestDelegate> delegate;


/*!
 *  @property
 *  @brief For public users only. Use this enum to set the results type that will be retrived from the server. SFPublicDescription/SFPublicProducts.
 *  @discussion SFPublicDescription - the description of the image detected. SFPublicProducts - the retrieved products based on the image detected.
 *  @note The default is SFPublicDescription.
 */
@property (nonatomic) SFPublicResultsType publicResultsType;


///---------------------------------------------------------------------------------------
/// @name Initialization
///---------------------------------------------------------------------------------------

/*!
 *  @method
 *  @brief Initializes a new SFRequest object.
 *
 *  @discussion Use this method to prepare the SDK for 2D/3D recognition functionality.
 *  In order to successfully use this method to initialize a new SFRequest, you *must* first
 *  have a valid SFSlyce object, previously initialized with your client ID.
 *  Depending on your client ID, SFRequest will be able to perform a 2D and/or 3D search.
 *
 *  @param slyce the Slyce object.
 *  @param options options dictionary (optional). Pass `nil` for no options.
 *  @param delegate object that implements SFRequestDelegate protocol.
 *
 *  @see SFRequestDelegate
 *
 *  @return Returns an instance of SFRequest.
 */

- (instancetype)initWithSlyce:(SFSlyce *)slyce options:(NSDictionary *)options andDelegate:(id<SFRequestDelegate>)delegate;

///---------------------------------------------------------------------------------------
/// @name Product Search
///---------------------------------------------------------------------------------------


/*!
 *  @method
 *  @brief Used to asynchronously retrieve a list of products and extended info from image.
 *
 *  @discussion
 *  The delegate will be notified in case of a match for a 2D product and in case of 3D products, separately, via
 *  [SFRequestDelegate sfRequest:didDetectImage:] and [SFRequestDelegate sfRequest:didReceiveResults:] and [SFRequestDelegate sfRequest:didReceiveResultsExt:], accordingly. 2D match is possible for Premium and 2D-enabled users only. In case of a 2D match, additional info might be delivered, via [SFRequestDelegate sfRequest:didReceiveImageInfo:] callback.
 *  The 3D products array cannot be empty. For more information, refer to SFRequestDelegate class.
 *
 *  @param image The image object to recognize.
 *
 *  @see getResultsFromImageUrl:
 *  @see SFRequestDelegate
 */

- (void)getResultsFromImage:(UIImage *)image;

/*!
 *  @method
 *  @brief Used to asynchronously retrieve a list of products and extended info from the URL to the image.
 *
 *  @discussion Calling this method will begin the visual 3D recognition of the image object param. The results, as well as the progress,
 *  will be notified via the SFRequestDelegate object. For more information, see the reference for SFRequestDelegate class.
 *
 *  @param imageURL The URL of the image to recognize.
 *
 *  @see getResultsFromImage:
 *  @see SFRequestDelegate
 */


- (void)getResultsFromImageUrl:(NSURL *)imageURL;

/*
 *  @method
 *  @brief Used to retrieve a payload describing the description of the product in the image, along with optional parameters.
 *
 *  @discussion This method will ask the SDK to asynchronously recognize the image in the param and return an `NSDictionary` representing the description of 
 *  the item matched.
 *
 *  @param image the image object.
 *
 *  @see getItemDescriptionFromImageURL:
 *  @see SFRequestDelegate

- (void)getItemDescriptionFromImage:(UIImage *)image;
 */

/*
 *  @method
 *  @brief Used to asynchronously retrieve a list of products from URL to the image. May also provide an array of merchant IDs to narrow the search to specific merchants. Merchant IDs array is only relevant for non-premimum users. Premium users sould simply pass `nil`.
 *
 *  @discussion The delegate will be notified in case of a match for a 2D product and in case of 3D products, separately, via
 *  [SFRequestDelegate sfRequest:didDetectImage:] and [SFRequestDelegate sfRequest:didReceiveResults:], accordingly. 2D match is possible for Premium and 2D-enabled users only. In case of a 2D match, additional info might be delivered, via [SFRequestDelegate sfRequest:didReceiveImageInfo:] callback.
 *  The 3D products array cannot be empty. For more information, refer to SFRequestDelegate class.
 *
 *  @param imageURL the URL to the image.
 *
 *  @see getItemDescriptionFromImage:
 *  @see SFRequestDelegate
 
- (void)getItemDescriptionFromImageURL:(NSURL *)imageURL;
 */


/*!
 *  @method
 *  @brief Used to asynchronously retrieve a list of products from image. May also provide an array of merchant IDs to narrow the search to specific merchants. Merchant IDs array is only relevant for non-premimum users. Premium users sould simply pass `nil`.
 *
 *  @discussion  
 *  The delegate will be notified in case of a match for a 2D product and in case of 3D products, separately, via
 *  [SFRequestDelegate sfRequest:didDetectImage:] and [SFRequestDelegate sfRequest:didReceiveResults:], accordingly. 2D match is possible for Premium and 2D-enabled users only. In case of a 2D match, additional info might be delivered, via [SFRequestDelegate sfRequest:didReceiveImageInfo:] callback.
 *  The 3D products array cannot be empty. For more information, refer to SFRequestDelegate class.
 *
 *  @param image The image object to recognize.
 *  @param merchantIDs An array of merchant IDs to match (optional). Pass nil to search all the supported merchants.
 *
 *  @note Another way to get all the supported merchants is using a convinient method getMerchantIDs. You can pass the return array of this
 *  method as a param to the current method.
 *
 *  @see getProductsFromImageURL:merchantIDs:
 *  @see SFRequestDelegate
 */

- (void)getProductsFromImage:(UIImage *)image merchantIDs:(NSArray *)merchantIDs;

/*!
 *  @method
 *  @brief Used to asynchronously retrieve a list of products from the URL to the image. May also provide an array of merchantIDs
 *  to narrow the search to specific merchants.
 *
 *  @discussion Calling this method will begin the visual 3D recognition of the image object param. The results, as well as the progress,
 *  will be notified via the SFRequestDelegate object. For more information, see the reference for SFRequestDelegate class.
 *
 *  @param imageURL The URL to the image to recognize.
 *  @param merchantIDs An array of merchant IDs to match (optional). Pass nil to search all the supported merchants.
 *
 *  @note Another way to get all the supported merchants is using a convinient method getMerchantIDs. You can pass the return array of this
 *  method as a param to the current method.
 *
 *  @see getProductsFromImage:merchantIDs:
 *  @see SFRequestDelegate
 */

- (void)getProductsFromImageURL:(NSURL *)imageURL merchantIDs:(NSArray *)merchantIDs;

///---------------------------------------------------------------------------------------
/// @name Miscellaneous
///---------------------------------------------------------------------------------------

/*!
 *  @method
 *  @brief Cancels the current request.
 *
 *  @discussion Use this method when you want to cancel the current visual search processing. This method will stop both the 3D and 2D
 *  (Premium) recognitions, if used.
 *
 */

- (void)cancel;

///---------------------------------------------------------------------------------------
/// @name Helpers
///---------------------------------------------------------------------------------------

/*!
 *  @method
 *  @brief Method to get the IDs of all the supported merchants.
 *
 *  @discussion Used to asynchronously retrieve a list of all merchant IDs that can be used with getProductsFromImage:merchantIDs: and
 *  getProductsFromImageURL:merchantIDs: methods.
 *
 */

- (void)getMerchantIDs;

///---------------------------------------------------------------------------------------
/// @name Deprecated
///---------------------------------------------------------------------------------------

/*!
 *  @method
 *  @brief A Premium method to asynchrounsly retrieve 2D and 3D products from the image passed.
 *
 *  @discussion This method is a Premium feature. Use this method if you are interested in retrieving a 2D product along with 3D products
 *  from the SDK. 2D visual recognition is possible if the SFSlyce object was initialized using client ID that supports premium features.
 *  Otherwise, the delegate will be notified via [SFRequestDelegate sfRequest:didFailWithError:] with an SFErrorNotPremium error (In case of a success, the
 *  delegate won't be notified).
 *
 *  The delegate will be notified in case of a match for a 2D product and in case of 3D products, separately, via
 *  [SFRequestDelegate sfRequest:didDetectImage:] and [SFRequestDelegate sfRequest:didReceiveResults:], accordingly. In
 *  case of a 2D match, additional info might be delivered, via [SFRequestDelegate sfRequest:didReceiveImageInfo:] callback.
 *  The 3D products array cannot be empty. For more information, refer to SFRequestDelegate class.
 *
 *  @param image The image object to recognize.
 *
 *  @see recognizeSimilarProductsFromImageURL:
 *  @see getProductsFromImage:merchantIDs:
 *  @see SFRequestDelegate
 *
 *  @deprecated since 2.0. Use getProductsFromImage:merchantIDs: instead.
 */

- (void)recognizeSimilarProductsFromImage:(UIImage *)image __attribute((deprecated("This method is deprecated since 2.0. Use getProductsFromImage:merchantIDs: instead.")));

/*!
 *  @method
 *  @brief A Premium method to asynchrounsly retrieve 2D and 3D products from the URL to the image.
 *
 *  @discussion This method is a Premium feature. Use this method if you are interested in retrieving a 2D product along with 3D products
 *  from the SDK. 2D visual recognition is possible if the SFSlyce object was initialized using client ID that supports premium features.
 *  Otherwise, the delegate will be notified via [SFRequestDelegate sfRequest:didFailWithError:] with an SFErrorNotPremium error (In case of a success, the
 *  delegate won't be notified).
 *
 *  The delegate will be notified in case of a match for a 2D product and in case of 3D products, separately, via
 *  [SFRequestDelegate sfRequest:didDetectImage:] and [SFRequestDelegate sfRequest:didReceiveResults:], accordingly. In
 *  case of a 2D match, additional info might be delivered, via [SFRequestDelegate sfRequest:didReceiveImageInfo:] callback.
 *  The 3D products array cannot be empty. For more information, refer to SFRequestDelegate class.
 *
 *  @param imageURL The URL to the image to recognize.
 *
 *  @see recognizeSimilarProductsFromImage:
 *  @see getProductsFromImage:merchantIDs:
 *  @see SFRequestDelegate
 *
 *  @deprecated since 2.0. Use getProductsFromImageURL:merchantIDs: instead.
 */

- (void)recognizeSimilarProductsFromImageURL:(NSURL *)imageURL __attribute((deprecated("This method is deprecated since 2.0. Use getProductsFromImageURL:merchantIDs: instead.")));



- (void)cancelInternal;


@end
