//
//  SFSlyce.h
//  SlyceSDK
//
//  Created by Nathan Gurfinkel on 3/17/15.
//  Copyright (c) 2015 BuyCode. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 
 @abstract Main object used to initialize the Slyce SDK.
 
 */

@interface SFSlyce : NSObject

///---------------------------------------------------------------------------------------
/// @name Initialization and disposal
///---------------------------------------------------------------------------------------

/*!
*  @method
*
*  @brief Initializes and returns a singleton instance of the SDK.
*
*  @return a shared SFSlyce instance.
*
*/

+ (id)sharedInstance;

/*!
 *  @method
 *
 *  @brief Initializes a new SFSlyce object.
 *
 *  @discussion Use this method to open the SDK for 2D/3D recognition functionality.
 *  Depending on your client ID, the SDK will be able to perform standard/premium tasks.
 *
 *  @param clientID the client ID.
 *  @param error the pointer to the error object, if any.
 *
 *  @return `YES` if it succeeded, `NO` otherwise.
 *
 *  @warning As this method performs validation checks of your client ID on our
 *  servers, call this method off the main (UI) thread!
 *
 *  **Important:** Successfully opening the SFSlyce object is mandatory before you start
 *  performing any tasks in the SDK!
 *
 */

- (BOOL)openWithClientID:(NSString *)clientID error:(NSError **)error;

///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------

/*!
 
 @property
 
 @abstract The client ID used to initialize the SFSlyce object.
 
 */

@property (nonatomic, readonly, copy) NSString *clientID;

/*!
 
 @property
 
 @abstract Indicates whether the user can use premium features of the SDK.
 @discussion default is `NO`.
 
 @note The value of this property depends on your client ID.
 
 */

@property (nonatomic, readonly) BOOL isPremiumUser;

/*!
 
 @property
 
 @abstract Indicates whether the user can ask the SDK to perform 2D searches.
 @discussion default is `NO`.
 
 @note The value of this property depends on your client ID.
 
 */

@property (nonatomic, readonly) BOOL is2DSearchEnabled;

/*!
 
 @property
 
 @abstract If set, the device will vibrate when the a barcode/2D item auto-matched.
 @discussion default is `YES`.
 
 */

@property (nonatomic) BOOL vibrate;

/*!
 
 @property
 
 @abstract If set, the device will play a sound when the a barcode/2D item auto-matched.
 @discussion default is `YES`.
 
 */

@property (nonatomic) BOOL sound;

@end
