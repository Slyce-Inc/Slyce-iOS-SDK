//
//  SFSlyce.h
//  SlyceSDK
//
//  Created by Nathan Gurfinkel on 3/17/15.
//  Copyright (c) 2015 BuyCode. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


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
 *  @brief Initializes a new SFSlyce object using valid App Key and App Secret credentials.
 *
 *  @discussion Use this method to open the SDK for 'Public' recognition functionality.
 *
 *  @param appKey the App Key.
 *  @param appSecret the App Secret.
 *  @param error the pointer to the error object, if any.
 *
 *  @return `YES` if it succeeded, `NO` otherwise.
 *
 *  **Important:** Successfully opening the SFSlyce object is mandatory before you start
 *  performing any tasks in the SDK!
 *
 */

- (BOOL)openWithAppKey:(NSString *)appKey appSecret:(NSString *)appSecret error:(NSError **)error;

/*!
 *  @return Slyce public AppKey
 */
- (NSString *)getAppKey;

/*!
 *  @return Slyce public AppSecret
 */
- (NSString *)getAppSecret;

/*!
 *  @method
 *
 *  @brief Initializes a new SFSlyce object using a customer ID.
 *
 *  @discussion Use this method to open the SDK for 2D/3D 'Premium' recognition functionality.
 *  Depending on your client ID, the SDK will be able to perform Standard and/or Premium  
 *  tasks.
 *
 *  @param clientID the customer ID.
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
/// @name Unavailable
///---------------------------------------------------------------------------------------

- (instancetype)init __attribute__((unavailable("Use +[SFSlyce sharedInstance] instead")));

+ (instancetype)new __attribute__ ((unavailable("Use +[SFSlyce sharedInstance] instead")));

///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------



/**
 * @method
 * @brief Adds custom statistics event to the Slyce tracking system.
 * @param eventName Custom event name
 * @param params Custom event paramteters. Only string keys and values supported.
 */
- (void)reportStatisticsEventWithName:(NSString *)eventName additionalParameters:(NSDictionary *)params;


/*!
 
 @property
 
 @abstract The client ID used to initialize the SFSlyce object for 'Premium' mode.
 
 */

@property(nonatomic, readonly, copy) NSString *clientID;

/*!
 
 @property
 
 @abstract Indicates whether the user can use premium features of the SDK.
 @discussion default is `NO`.
 
 @note The value of this property depends on your client ID.
 
 */

@property(nonatomic, readonly) BOOL isPremiumUser;

/*!
 
 @property
 
 @abstract Indicates whether the user can ask the SDK to perform 2D searches.
 @discussion default is `NO`.
 
 @note The value of this property depends on your client ID.
 
 */

@property(nonatomic, readonly) BOOL is2DSearchEnabled;

/*!
 
 @property
 
 @abstract Indicates whether the user can crop the image after snapping.
 @discussion default is `NO`.
 
 @note The value of this property depends on your client ID.
 
 */

@property(nonatomic, readonly) BOOL isCroppingEnabled;

/*!
 
 @property
 
 @abstract If set, the device will vibrate when the a barcode/2D item auto-matched.
 @discussion default is `YES`.
 
 */

@property(nonatomic) BOOL vibrate;

/*!
 
 @property
 
 @abstract If set, the device will play a sound when the a barcode/2D item auto-matched.
 @discussion default is `YES`.
 
 */

@property(nonatomic) BOOL sound;


/*!
 
 @property
 
 @abstract You can set your own custom circular progress color
 @discussion default is `[UIColor colorWithRed:152/255.f green:183/255.f blue:208/255.f alpha:1]`.
 
 */

@property(nonatomic, strong) UIColor *customProgressColor;


/**
 * @property
 * @abstract Current max image width setting
 * @discussion Image will be resized according to this setting before uploading it to the server
 */
@property(nonatomic, readonly) int maxWidthDimension;


/**
 * @property
 * @abstract Current max image height setting
 * @discussion Image will be resized according to this setting before uploading it to the server
 */
@property(nonatomic, readonly) int maxHeightDimension;


@end
