//
//  NSError+Slyce.h
//  SlyceSDK
//
//  Created by Nathan Gurfinkel on 2/3/15.
//  Copyright (c) 2015 Slyce. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const SlyceErrorDomain;

/*!
 *  Enumeration for main Slyce SDK error codes.
 */

typedef NS_ENUM(NSUInteger, SFErrorCode)
{
    ///0:  success.
    SFSuccess = 0,
    ///1:  unspecified error.
    SFErrorUnspecified,
    ///2:  invalid use of the library.
    SFErrorMisuse,
    ///3:  access permission denied.
    SFErrorNoPerm,
    ///4:  file not found.
    SFErrorNoFile,
    ///5:  database file locked.
    SFErrorBusy,
    ///6:  database file corrupted.
    SFErrorCorrupt,
    ///7:  empty database.
    SFErrorEmpty,
    ///8:  authorization denied.
    SFErrorAuth,
    ///9:  no internet connection.
    SFErrorNoConn,
    ///10: operation timeout.
    SFErrorTimeout,
    ///11: threading error.
    SFErrorThread,
    ///12: credentials mismatch.
    SFErrorCredMismatch,
    ///13: internet connection too slow.
    SFErrorSlowConn,
    ///14: record not found.
    SFErrorNoRec,
    ///15: operation aborted.
    SFErrorAbort,
    ///16: resource temporarily unavailable.
    SFErrorUnavail,
    ///17: image size or format not supported.
    SFErrorImg,
    ///18: wrong API key or no offline image.
    SFErrorApiKey,
    ///19: a network problem occurred.
    SFErrorNetworkFail,
    ///20: scanner is not open.
    SFErrorNotOpen,
    ///21: could not read bundle.
    SFErrorBundle,
    ///22: wrong API secret.
    SFErrorApiSecret,
    ///23: bad or missing client ID.
    SFErrorClientID,
    ///24: not a premium user.
    SFErrorNotPremium,
    ///25: request still in progress.
    SFErrorRequestInProgress,
    ///26: request fulfilled. Create a new request to perform the operation.
    SFErrorRequestFulfil,
    ///27: products not found.
    SFErrorRequestProductsNotFound,
    ///28: bad image.
    SFErrorRequestBadImage,
    ///29: invalid image.
    SFErrorRequestInvalidImage
};

@interface NSError (Slyce)

/** Create an error object configured with the Slyce error domain.
 *
 * @param code the Slyce error code (e.g `SFErrorMisuse`)
 * @return The created error object.
 */
+ (NSError *)sf_errorWithCode:(NSInteger)code;

/** Return the message string related to the error code.
 *
 * @return The user friendly message string.
 */
- (NSString *)sf_message;

@end
