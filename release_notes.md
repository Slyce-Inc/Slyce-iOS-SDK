Slyce SDK Changelog
===================================

4.5.7 - 2017/09/15
-----------------
*ADDED exact match threshold parameter
*CHANGED Exact Match scanning improvements in speed and quality


4.5.6 - 2017/08/21
-----------------
*ADDED Find similar statistics tracking


4.5.5 - 2017/08/02
-----------------
*FIXED issue in getting similar by combined parameters


4.5.4 - 2017/07/25
-----------------
*ADDED find similar method by product ID and image URL
*IMPROVED connection security
*IMPROVED 2D sync process


4.5.3 - 2017/06/15
-----------------
*IMPROVED 2D catalog sync (relocated to camera init)
*IMPROVED 2D scanning performance
*ADDED find similar by product ID
*FIXED crash on SDK init


4.5.2 - 2017/05/15
-----------------
*IMPROVED 2D sync and processing


4.5.1 - 2017/05/01
-----------------
*ADDED custom event reporting
*FIXED white balance camera issues
*FIXED auto sending image on snap in Full UI mode


4.5 - 2017/04/11
-----------------
*IMPROVED: 2D scanning optimisations for better on-device recognition
*IMPROVED: 2D scanning improvements for server-side processing
*ADDED: x86_64 and i386 architectures to run on the iOS Simulator
*FIXED: 'image not found' runtime crash
*IMPROVED: 2D Syncing layer


4.4 - 2017/03/28
-----------------
backward compatibility for old retailer IDs - preserved

* CHANGED: 2D recognition framework replaced with a new one - on-device as well as server-side
* FIXED: 2D and 3D simultaneous recognition
* CHANGED: sending image request on snap is performed by “Use Photo” only


4.3.1 - 2016/12/19

* FIXED: Incorrect zooming on old iPads

4.3 - 2016/11/10
------------------

* ADDED:  in `SFCameraView` class `detectionDelay2D` - A property to add delay before 2D image detection starts or between detections.
* ADDED:  in `SFCameraView` class `detectionDelay2DSameImage` - A property to override the default '3 sec' delay between same 2D image detections.

4.2 - 2016/11/03
------------------

* ADDED: Real-time modification of image upload resizing parameters.

4.1 - 2016/09/18
------------------

* ADDED: Added Find Similar search support.
* FIXED: Full UI mode - workflow message are excluded. Color, category, gender, keywords are the only ones to appear.
* IMPROVED: Secure connections optimization.
* ADDED: Full Public Users support, implemented with the new Portal system.

3.1 - 2016/07/07
------------------

* FIXED: Minor bug fixes

3.0 - 2016/06/02
------------------

* ADDED:  Support for public users.
* ADDED:  in `SFRequest` class `setPublicResultsType:` - Set the result type of the public request.
* ADDED:  in `SFCameraView` class `setPublicResultsType:` - Set the result type of the public request.
* ADDED:  in `SFRequest` class `getResultsFromImage:` and `getResultsFromImageUrl:`.
* ADDED:  in `SFRequestDelegate` - `sfRequest: didReceiveResultsExt:` and `sfRequest: didProgressExt:` for extended info from the server.
* ADDED:  in `SFCameraViewDelegate` - `sfCameraView: didReceiveResultsExt:` and `sfCameraView: didProgressExt:` for extended info from the server.
* ADDED:  in `SFCameraViewControllerDelegate` - `sfCameraViewController: didReceiveResultsExt:` and `sfCameraViewController: didProgressExt:` for extended info from the server.

2.4.6 - 2016/04/12
------------------

* FIXED: Minor bug fixes

2.4.5 - 2016/03/22
------------------

* FIXED: Minor bug fixes

2.4.4 - 2016/03/08
------------------

* FIXED: Minor bug fixes

2.4.3 - 2016/02/10
------------------

* FIXED: Minor bug fix

2.4.2 - 2016/02/03
------------------

* FIXED: Bug fixes

2.4.1 - 2016/01/21
------------------

* FIXED: Minor bug fixes

2.4 - 2016/01/17
------------------

* ADDED: shouldUseContinuousRecognition2D property to enable/disable continuous recognition for 2D products functionality.
* ADDED: shouldUseContinuousRecognitionBarcodes property to enable/disable continuous recognition for barcodes functionality.
* ADDED: shouldPauseScannerDelayTime property to override the default '3 sec' delay time for resuming the auto scanner automatincly after a successful 1D/2D detection.
* ADDED: setCustomHelpViewController used to override the default 'help' viewController with your custom viewController.
* ADDED: setCustomNotFoundViewController used to override the default 'not found' viewController with your custom viewController.
* ADDED: addCustomBtnWithVC use this method to add your own custom button with a custom viewController to the SFCameraViewController(Full UI mode).
* ADDED: customProgressColor use this method to set your own circular progress color (Full UI mode).

2.3.3 - 2016/01/08
------------------
* FIXED: Minor bug fixes

2.3.1 - 2016/01/07
------------------
* FIXED: Minor bug fixes

2.3 - 2016/01/06
------------------
* FIXED: Screen orientation inverted in landscape when Semi-UI mode implemented
* FIXED: EAN-13 Barcode detection
* ADDED: Assets Sets for different platform support

2.2 - 2015/12/17
------------------
* FIXED: local image cache synchronization bug
* FIXED: image cropping bug on iPhone 5s
* FIXED: redundant events reporting while app is in background
* IMPROVED: analytics reporting

2.1.2 - 2015/11/18
------------------
* IMPROVED: Foundation error handling

2.1.1 - 2015/11/13
------------------
* FIXED: Critical compilation errors when working with iPhone Simulator (Xcode 7.1 and above)

2.1 - 2015/11/11
------------------
* CHANDED: Full UI Progress screen - progressive blocks loading
* FIXED: Scanning objects parallel to the ground
* REMOVED: iPhone Simulator from SlyceSDK.bundle's info.plist file
* IMPROVED: Analytics reporting

2.0 - 2015/10/12
------------------
* NEW: Full UI mode - a total NEW design!
* NEW: Full UI mode - Use/Retake screen
* NEW: Public flow API
* ADDED: iOS 9 support
* ADDED: More barcode types are supported using continuous scanning
* ADDED: Front facing camera support
* ADDED: More Slyce domain error codes (see NSError+Slyce category or SFErrorCode enum in the docs)
* ADDED: SFCameraView - flipCameraPosition method to change the camera position (front vs rear)
* ADDED: SFCameraViewDelegate - new callback method sfCameraView:didChangeCameraPosition:
* ADDED: SFCameraView - shouldRecognizeAfterSnap property to enable/disable image recognition after snapping the image
* ADDED: SFCameraView - stopSearch method to stop the image recognition process after snapping the image
* ADDED: SFRequestDelegate - sfRequest:didStartForImage: and sfRequest:didStartForImageURL:
* CHANGED: SFCameraViewController - didSnapImage: delegate method is also called when taking a picture from Camera Roll
* CHANGED: SFCameraView - shouldRecognizeAfterSnap property affects taking a picture from Camera Roll as well

1.9.3 - 2015/07/14
------------------
* ADDED: camera zoom functionality
* ADDED: completionBlock to SFCameraViewController present method (presentFromViewController:usingAnimation:completionBlock:) (#36)
* FIXED: indeterminate message still appeared when pushing a new view controller before receiving 2D didReceiveImageInfo: callback (#35)
* ADDED: SFStatusType - status type param was added to didFinish: callbacks in all 3 modes (#31)
* CHANGED: recognizeSimilarProductsFromImage: was deprecated. Use getProductsFromImage:merchantIDs: instead.
* CHANGED: recognizeSimilarProductsFromImageURL: was deprecated. Use getProductsFromImageURL:merchantIDs: instead.

1.9.1 - 2015/06/14
------------------
* ADDED: delay between two idetical successive 2D detections
* IMPROVED: landscape support

1.9 - 2015/06/11
------------------
* ADDED: sfCameraViewControllerWasDismissed: callback
* ADDED: shouldPauseScannerAfterRecognition property to enable/disable pausing the auto scanner after a successful detection
* ADDED: Full UI mode - spinner is shown after a successful 2D detection until products found
* ADDED: Support for multiple results for one 3D request
* ADDED: Docs - guide for customizing resources in Full UI mode (Appendix A)
* ADDED: new didFinish: callback is sent when the Slyce 3D search is finished
* CHANGED: didFinishWith3DProducts: was deprecated. Use didReceiveResults: instead.
* CHANGED: didFinishWithEncodedString:and2DProductInfo: was deprecated. Use didDetectImage: instead.
* CHANGED: didFinishWithExtendedInfoFor2DProducts: was deprecated. Use didReceiveImageInfo: instead.
* CHANGED: didRecognizeBarcode: was deprecated. Use didDetectBarcode: instead.
* CHANGED: auto scanner is paused after a successful barcode or 2D detection
* CHANGED: 2D server side detection stops a 3D server side detection
* IMPROVED: barcode auto detection
* IMPROVED: landscape support

1.8 - 2015/06/03
------------------
* NEW: added detection for the following barcode formats: Aztec, Codabar, Code39, Code93, Code128, MaxiCode, PDF417, RSS14, RSSExpanded, UPCA, UPCE, UPCEANExtension
* NEW: ITF barcodes server side recognition
* ADDED: didFinishWithExtendedInfoFor2DProducts: callback now returns an array of 2D products
* ADDED: "bad" or "invalid" image errors are now explicitly reported via didFailWithError: callbacks
* CHANGED: didFinishWith3DProducts: callbacks now return an NSDictionary containing the matched products along with some metadata
* CHANGED: in case of no products found (2D/3D), didFailWithError: callbacks are called instead of didFinish: with empty arrays
* FIXED: better landscape support
* FIXED: shouldUseContinuousRecognition did not have effect when using SFCameraViewController

1.7.2 - 2015/05/25
------------------
* ADDED: optional 'options' params to each one of the initialization methods
* ADDED: server side barcode recognition
* FIXED: possible auto-scan detection while progress screen being launched
* FIXED: images from Camera Roll were not resized when sent for 2D recognition
