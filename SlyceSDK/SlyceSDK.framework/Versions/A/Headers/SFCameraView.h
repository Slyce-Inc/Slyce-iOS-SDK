//
//  CameraView.h
//  SlyceSDK
//
//  Created by Nathan Gurfinkel on 2/3/15.
//  Copyright (c) 2015 Slyce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SFCameraViewDelegate.h"
#import <AVFoundation/AVCaptureVideoPreviewLayer.h>

@class SFSlyce;
@class SFRequest;

/*!
 *  Provides an integral camera functionality
 *
 *  Set of methods that allow developers to perform continuous barcode detection, continuous 2D visual recognition (Premium feature),
 *  taking a snap, operating the flash, performing focus etc.
 *
 *  @warning SFCameraView does NOT provide any UI, hence, it should be used in a predefined UIView.
 *
 *  @note This mode of operation is mostly used when the user wants to use his own UI with the SDK’s capture capabilities.
 */

@interface SFCameraView : UIView <SFRequestDelegate>

///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------

/*!
  *  @property
  *  @brief A property to enable/disable 2D/3D recognition after snapping an image.
  *
  *  @discussion Use this property to toggle the image recognition after calling snap method.
  *  Setting this property to `NO` will not start an image recognition after the image was 
  *  snapped. This means [SFCameraViewDelegate sfCameraView:didStartRequest:forImage:] callback will NOT be called after [SFCameraViewDelegate sfCameraView:didSnap:].
  *  This is generally useful if the user wants to make some visual editing for the snapped image prior to sending it for recognition to Slyce.
  *  Default is `YES`.
  *
  */

@property (nonatomic) BOOL shouldRecognizeAfterSnap;


/*!
 *  @property
 *  @brief A property to enable/disable pausing the auto scanner after a successful 2D detection.
 *
 *  @discussion Setting this property to `NO` will let the auto scanner continuously recognize products.
 *  Default is `YES`, meaning the auto scanner will pause after the detection. It's up to the user then to resume it by calling resumeCapture:.
 *  This property has no effect if shouldUseContinuousRecognition was set to `NO`.
 *
 */

@property (nonatomic) BOOL shouldPauseScannerAfterRecognition;

/*!
 *  @property
 *  @brief A property to enable/disable continuous recognition functionality.
 *
 *  @discussion Use this property to toggle the continuous 2D/3D recognition. Setting this property
 *  to `NO` will stop recognizing barcodes in a Regular mode and will stop recognizing 2D products
 *  and barcodes in Premium mode.
 *  Default is `YES`.
 *
 */

@property (nonatomic) BOOL shouldUseContinuousRecognition;

/*!
 *  @property
 *  @brief Options dictionary.
 *  @discussion Use this dictionary to pass properties to Slyce servers.
 *  For example: @{@"storeID" : @"1234", @"state" : @"CA"}. Can be `nil`.
 */

@property (nonatomic, copy) NSDictionary *options;

/*!
 *  @property
 *  @brief The camera view delegate that will be notified of scan results.
 */
@property (nonatomic, weak) id<SFCameraViewDelegate> delegate;

/*!
 *  @property
 *  @brief The layer used to display the video capture on a given UIView.
 */
@property (nonatomic, strong, readonly) AVCaptureVideoPreviewLayer *previewLayer;

///---------------------------------------------------------------------------------------
/// @name Initialization
///---------------------------------------------------------------------------------------

/*!
 *  @method
 *  @brief Initializes a new `SFCameraView` object.
 *
 *  @discussion Use this method to initialize the SDK's camera functionalities and place the video preview in the view hierarchy beneath
 *  the view passed as a param to this method. One of the use cases of the camera's functionalities is a continuous barcode scanning.
 *  If you do not wish to get notified about barcodes detection, set shouldUseContinuousRecognition property to `NO`.
 *
 *  @param slyce The initialized Slyce object.
 *  @param view The view on top of which this camera view will placed.
 *  @param options options dictionary (optional). Pass `nil` for no options.
 *  @param delegate Object that implements SFCameraViewDelegate protocol.
 *b
 *  @note This method does NOT start the video preview. Use startCamera to start the video frames processing.
 *
 *  @see SFCameraViewDelegate
 *
 *  @return Returns an instance of SFCameraView.
 */

- (instancetype)initWithSlyce:(SFSlyce *)slyce view:(UIView *)view options:(NSDictionary *)options andDelegate:(id<SFCameraViewDelegate>)delegate;

///---------------------------------------------------------------------------------------
/// @name Video Capture
///---------------------------------------------------------------------------------------

/*!
 *  @method
 *  @brief Starts the video preview and processing frames.
 *
 *  @discussion This method is pre-requisite so that the Slyce scanner can start receiving and processing
 *  camera frames. The type of the processing depends on the SFCamera object initialization:
 *  
 *  If it was initialized using slyce object containing Premium client ID,
 *  startCamera will trigger 2D and barcodes continuous recognition. In case of a match, the delegate will be
 *  notified via sfCameraView:didDetectImage: or sfCameraView:didDetectBarcode:.
 *
 *
 *  If it was initialized using a Standard client ID, startCamera will trigger only barcodes continuous
 *  recognition. In case of a match, the delegate will be notified via sfCameraView:didDetectBarcode:.
 *
 *  If the video was already started, this method does nothing.
 *
 *  @warning As video frames processing is a CPU consuming operation, remember to stop the camera by using
 *  stopCamera method when the video is no longer visible to the user. If the video should be visible without
 *  the actual recognition process, use pauseCapture method instead.
 *
 *  @see [SFCameraViewDelegate sfCameraView:didDetectImage:]
 *  @see [SFCameraViewDelegate sfCameraView:didDetectBarcode:]
 */

- (void)startCamera;

/*!
 *  @method
 *  @brief Stops the video preview and processing frames.
 *
 *  @discussion This method stops the video preview. Hence, video frames will no longer be processed.
 *  If the video was not previously started, this method does nothing.
 *
 *  @warning You must always stop the camera once done to release underlying camera resources.
 */

- (void)stopCamera;

///---------------------------------------------------------------------------------------
/// @name Session State
///---------------------------------------------------------------------------------------

/*!
 *  @method
 *  @brief Stops processing frames temporarily.
 *
 *  @discussion The scanner keeps receiving frames from the camera, but they are no more processed.
 *  This means the video capture layer keeps being refreshed, but the session can no more report
 *  any scan result.
 *
 *  If the video was already paused, this method does nothing.
 *
 *  @note This method useful if you want to display an help section on-top of the scanner 
 *  while making sure you will not be notified with unexpected scan results.
 *
 */

- (void)pauseCapture;

/*!
 *  @method
 *  @brief Starts processing frames again.
 *
 *  @discussion Call this method to resume processing video frames again after a call to pauseCapture.
 *  If the video was already resumed, this method does nothing.
 *
 */

- (void)resumeCapture;

///---------------------------------------------------------------------------------------
/// @name Slyce Search
///---------------------------------------------------------------------------------------

/*!
 *  @method
 *  @brief Stops the Slyce search.
 *
 *  @discussion Asks the underlying Slyce Search request to be stopped, if one was previously 
 *  initiated. Slyce request is initiated as soon as the user calls the method snap. If Slyce 
 *  search was not initiated, this method does nothing.
 *
 */

- (void)stopSearch;

///---------------------------------------------------------------------------------------
/// @name General
///---------------------------------------------------------------------------------------

/*!
 *  @method
 *  @brief Changes the camera device from rear to front and vice versa.
 *
 */

- (void)flipCameraPosition;

/*!
 *  @method
 *  @brief Turns on/off the flash of the device.
 *
 *  @param on A boolean representing the required state of the flash (YES = ON, NO = OFF).
 */

- (void)turnFlash:(BOOL)on;

/*!
 *  @method
 *  @brief Perform an image recognition for the current frame.
 *
 *  @discussion Use this method to ask the scanner to grab the current video frame and match it. 
 *  The grabbing operation is done asynchronously due to a rendering of a video frame to an image
 *  object. Once the image is rendered and
 *  ready, it is returned via a delegate method [SFCameraViewDelegate 
 *  sfCameraView:didStartRequest:forImage:].
 *
 *  @note Calling this method again before the previous image was matched, will create a
 *  new image recognition request for the new video frame. As the image is ready, it will be returned via a delegate method [SFCameraViewDelegate 
 *  sfCameraView:didSnapImage:].
 *  The request created for this image will be returned via a delegate method [SFCameraViewDelegate sfCameraView:didStartRequest:forImage:].
 *
 *  @see SFCameraViewDelegate
 *  @see SFRequest
 */

- (void)snap;

/*!
 *  @method
 *  @brief Asks the scanner to focus the underlying camera to a specific point.
 *
 *  @discussion This method will simply focus the camera at the passed point.
 *
 *  @param point The point to focus at.
 *
 *  @note *An example use case*: Focusing at the point the user tapped.
 *
 */

- (void)focusAtPoint:(CGPoint)point;

@end
