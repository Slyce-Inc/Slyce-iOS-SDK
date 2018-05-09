#import <UIKit/UIKit.h>

FOUNDATION_EXPORT double SlyceSDKVersionNumber;
FOUNDATION_EXPORT const unsigned char SlyceSDKVersionString[];


#pragma mark Main

#import "SlyceBase.h"
#import "SlyceInstance.h"
#import "SlyceErrorCodes.h"
#import "SlyceSession.h"


#pragma mark Models

#import "SlyceBarcode.h"


#pragma mark Camera

#import "SlyceCameraControls.h"


#pragma mark Lenses

#import "SlyceLensConfiguration.h"


#pragma mark Headless Mode

#import "SlyceSearchRequest.h"
#import "SlyceSearchTask.h"
#import "SlyceSearchResponse.h"
#import "SlyceSearchResult.h"
#import "SlyceScanner.h"


#pragma mark LensView

#import "SlyceLensView.h"


#pragma mark Analytics

#import "SlyceEventTracker.h"
