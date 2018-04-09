Slyce iOS SDK
==============

The Slyce iOS SDK makes it easy to add visual search capabilities to mobile apps.

[*If you're looking for SDK 5.0, click here.*](https://github.com/Slyce-Inc/Slyce-iOS-SDK/tree/release_5.0)

## Contents

- [Use Cases](#use-cases)
- [Requirements](#requirements)
- [Add the SDK to Your Project](#add-the-sdk-to-your-project)
- [Credentials](#credentials)
- [Documentation](#documentation)


## Use Cases

The SDK enables 3 major modes of operation: **Headless**, **Headless/Camera**, **Full UI**.

### Headless

SDK provides the methods required to submit images and receive results. 
Ideal for cases where the app already handles the camera and has its own UI.

### Headless/Camera

A headless mode where the SDK manages the camera. **App developers are responsible to implement their own UI.** 
Ideal for cases where app developers would like to utilize SDK features such as continues barcodes detection, yet would like to maintain full flexibility with anything related to the UI/UX.

### Full UI

The SDK takes care of the entire flow from scanning to getting results. The SDK provides a UI that can be customized. Provides a turnkey scan-to-products solution.


## Requirements

* An iOS development environment including Xcode 5.0 or above and iOS SDK 7.0 or above
* An iPhone/iPad running iOS 7.0 or above (you cannot use the iOS Simulator when using the Headless/Camera or Full UI Mode, as the Simulator cannot produce video frames)
* A Slyce client ID


## Add the SDK to Your Project

### If you use [CocoaPods](http://cocoapods.org), then add these lines to your podfile:

```ruby
platform :ios, '7.0'
pod 'Slyce-iOS-SDK'
```

### If you use [Carthage](https://github.com/carthage/carthage), then add these lines to your Cartfile:

 ```
 binary "https://www.yourDomain.com/Slyce-iOS-SDK.json"
 ```
 Then upload the following json string to your https://www.yourDomain.com/ 
 
 ```
 {
	   "4.5.10": "https://github.com/Slyce-Inc/Slyce-iOS-SDK/archive/4.5.10.zip"
 }
 ```
 And run `carthage update`, and you should now have the latest version of Slyce in your Carthage folder.
 

### If you don't use CocoaPods, and Carthage then:

1. Clone or download the SDK, which consists of a framework, resources bundle, API docs, SDK Overview PDF and release notes. It also includes a sample app.
2. Drag and the drop the `SlyceSDK.framework` to the app’s project (make sure you copy the framework to the project).
3. If you plan to use the Full UI mode, drag and the drop the `SlyceSDK.bundle` to the app’s project (make sure you copy the bundle to the project).
4. In your project's **Build Settings** (in the `TARGETS` section, not the `PROJECTS` section):
  * add `-ObjC` to `Other Linker Flags`
  * set `Enable Bitcode` to `NO`
5. In your **info.plist**:
  * set `NSAllowsArbitraryLoads` to `YES` 
6. In your project's **Build Phases**, link your project with the following library:
  * `libicucore.dylib`
7. To start working, import `<SlyceSDK/SlyceSDK.h>` in order to import all the public headers.


## Credentials

Your mobile integration requires a `client_id`.

You can obtain these Slyce API credentials via a [Slyce](http://slyce.it/) representative.

After you obtain one, you should use it when initializing the central `SFSlyce` object when using of the SDK modes.


## Documentation

* These docs in the SDK, which include an overview of usage (PDF), API Reference (appledoc format), and sample code.
* The sample app included in this SDK.
* Header files are thoroughly documented; refer to them as needed for extra details about any given property or parameter.
