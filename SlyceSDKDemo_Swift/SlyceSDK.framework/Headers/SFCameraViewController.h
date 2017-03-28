//
//  SFCameraViewController.h
//  SlyceSDK
//
//  Created by Nathan Gurfinkel on 2/5/15.
//  Copyright (c) 2015 Slyce. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SFCameraViewControllerDelegate.h"

@class SFCameraView;
@class SFSlyce;

/*!
 *  Enumeration for transitions to the current view controller.
 *  A - presenting (your) view controller   B - SFCameraViewController (this)
 */

typedef NS_ENUM(NSUInteger, SFAnimationType) {
    ///No animation
            SFAnimationTypeNone,

    ///B pushes A from the right (navigation view controller style). A *must* be part of the navigation stack!
            SFAnimationTypePush,

    ///B reveals from the bottom (modal view controller style)
            SFAnimationTypeModal,

    ///B zooms in
            SFAnimationTypeZoom,

    ///A fades out with zoom, B fades in
            SFAnimationTypeFade
};




/*!
 *  Provides an integrated `UIViewController` with all the Slyce SDK functionalities.
 *
 *  The Slyce SDK may be utilized out of the box as a turnkey solution. Using 
 *  SFCameraViewController, the SDK will present the UI of the
 *  camera screen as well as progress indication during the recognition phase. Using this view 
 *  controller, a developer will a continuous
 *  barcodes/2D(Premium) scanning, slylized buttons for toggling the flash ON/OFF, opening an 
 *  image from the Photo Library, as well as a
 *  possibility to
 *  manually send an image from Photo Library / video preview for a 3D/2D(Premium) recognition. 
 *  The developer has to conform to
 *  SFCameraViewControllerDelegate protocol to get the results.
 *
 *  @note This mode of operation is mostly used when the user wants to utilize the Slyce SDK along 
 *  with the Slyce UI.
 *
 *  @note One can also use his own resource images instead of the SDK's built-in resource bundle, 
 *  in case the developer wants to match
 *  the look and feel of his own app.
 *
 */

@interface SFCameraViewController : UIViewController

///---------------------------------------------------------------------------------------
/// @name Properties
///---------------------------------------------------------------------------------------

/*!
 *  @property
 *  @brief The camera view controller delegate that will be notified of scan results.
 */
@property(weak, nonatomic) id <SFCameraViewControllerDelegate> delegate;

/*!
 *  @property
 *  @brief Options dictionary.
 *  @discussion Use this dictionary to pass properties to Slyce servers.
 *  For example: @{@"storeID" : @"1234", @"state" : @"CA"}. Can be `nil`.
 */

@property(nonatomic, copy) NSDictionary *options;




/*!
 *  @property
 *  @brief A handle to the underlying camera/scanner view used.
 *
 *  @discussion Use this property if you need to tweak the SDK's scanner functionalities or 
 *  perform camera's specific operations, like turn the flash
 *  on/off, snap an image etc. SFCameraViewController is started along with the continuous 
 *  barcodes/2D(premium) recognition by default. If you do
 *  not wish to use a continuous recognition, set [SFCameraView shouldUseContinuousRecognition]
 *  property of SFCameraView's object to `NO`.
 *
 */

@property(strong, nonatomic, readonly) SFCameraView *cameraView;




/*!
 *  @method
 *  @brief Used to override the default 'help' viewController with your custom viewController.
 *
 *  @discussion
 *  Your custom viewController will be replaced with the default 'help' viewController.
 *
 *  @param customHelpView The custom viewController.
 *
 *  @note You have to make sure that your custom viewController includes a back/close button that his action will be '[self dismissViewControllerAnimated:YES completion:nil]'.
 */


- (void)setCustomHelpViewController:(id)customHelpView;


/*!
 *  @method
 *  @brief Used to override the default 'not found' viewController with your custom viewController.
 *
 *  @discussion
 *  Your custom viewController will be replaced with the default 'not found' viewController.
 *
 *  @param customNotFoundView The custom viewController.
 *
 *  @note You have to make sure that your custom viewController includes a back/close button that his action will be '[self dismissViewControllerAnimated:YES completion:nil]'.
 */

- (void)setCustomNotFoundViewController:(id)customNotFoundView;


/*!
*  @method
*  @brief Add your own custom button with a custom viewController to the SFCameraViewController(Full UI mode).
*
*  @discussion Use this method to add your own custom button with a custom viewController to the SFCameraViewController(Full UI mode).
*
*  @param viewController Your Custom viewController.
*  @param x Position of the custom button in percent, when 100% is width of the screen.
*  @param y Position of the custom button in percent, when 100% is height of the screen.
*  @param btnImage The image of the custom button.
*  @param popUpAnimation PopUp animation.
*
*  @note The position of the custom button will be set in percents when 100% is for both width and height of the screen.
*
*
*/

- (void)addCustomBtnWithVC:(id)viewController postionInPercentX:(CGFloat)x postionInPercentY:(CGFloat)y btnImage:(UIImage *)btnImage popUpAnimation:(BOOL)popUpAnimation;



- (void)setSlyceLogoHidden:(BOOL)slyceLogoHidden;



///---------------------------------------------------------------------------------------
/// @name Initialization
///---------------------------------------------------------------------------------------

/*!
 *  @method
 *  @brief Initializes a new SFCameraViewController object.
 *
 *  @discussion This method initializes SFCameraViewController object. Depending on you client ID, 
 *  it will be initialized for Standard/Premium SDK's features. If you wish to use Premium 
 *  features, make sure your client ID is registered for Premium features.
 *
 *  Use this method to prepare the Slyce's integral view controller. You may also provide you own 
 *  bundle of resources. The size and name
 *  of the assets
 *  you provide must follow the guidelines in the docs to be presented correctly by the SDK.
 *  In case you wish to use the built-in SDK's assets, simply pass `nil` to this parameter.
 *
 *  @param slyce The initialized Slyce object.
 *  @param resourcesBundle An *optional* bundle of resources to use as assets for the current view 
 *  controller. In case you wish to use the built-in
 *  SDK's assets, simply pass `nil` to this parameter.
 *  @param options options dictionary (optional). Pass `nil` for no options.
 *  @param delegate Object that implements SFCameraViewControllerDelegate protocol.
 *
 *  @note This method only initiliazes the view controller object and does NOT start 
 *  the video  frames processing nor the video preview
 *  at all, until the view controller is actually presented via 
 *  presentFromViewController:usingAnimation:completionBlock: method.
 *
 *  @note Initializing SFCameraViewController using this method will prepare the view controller 
 *  for a continuous and manual 3D recognition.
 *
 *  @see SFCameraViewControllerDelegate protocol
 *
 *  @return Returns an instance of SFCameraViewController.
 */

- (instancetype)initWithSlyce:(SFSlyce *)slyce resourcesBundle:(NSBundle *)resourcesBundle options:(NSDictionary *)options andDelegate:(id <SFCameraViewControllerDelegate>)delegate;

///---------------------------------------------------------------------------------------
/// @name Presentation
///---------------------------------------------------------------------------------------

/*!
 *  @method
 *  @brief Presents the SFCameraViewController using animation.
 *
 *  @discussion Use this method to present the camera view controller. You can choose among
 *  predefined animation types the presentation animation that will best fit to your app style.
 *  For the available animation types, refer to SFAnimationType enum.
 *
 *  @param fromViewController The view controller from which SFCameraViewController is presented.
 *  @param animationType Presentation animation.
 *  @param completionBlock block that executes after presenting animation completes.
 *
 *  @note This method may look a bit different to the usual iOS native view controllers' 
 *  presentation technique. It is due to the fact
 *  this method encapsulted all the operations needed to present a view controller using a custom 
 *  transition in iOS. Please refer to the
 *  code below.
 *
 *  <pre><code>
 *      SFCameraViewController *cameraVC = [[SFCameraViewController alloc] initWithSlyce:self.slyce resourcesBundle:nil andDelegate:self];
 *      [cameraVC presentFromViewController:self usingAnimation:SFAnimationTypeZoom completionBlock:nil];
 *  </code></pre>
 *
 */

- (void)presentFromViewController:(UIViewController *)fromViewController usingAnimation:(SFAnimationType)animationType completionBlock:(void (^)(void))completionBlock;


@end
