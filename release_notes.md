Slyce SDK Changelog
===================================

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
	
	
	
