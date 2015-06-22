//
//  NSError+Slyce.h
//  SlyceSDK
//
//  Created by Nathan Gurfinkel on 2/3/15.
//  Copyright (c) 2015 Slyce. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *const SlyceErrorDomain;

/** Enumeration for main Slyce SDK error codes.
 */

@interface NSError (Slyce)

/*!
 *  @enum SFErrorCode
 *  @brief Enumeration for Slyce error codes.
 *  @const SFSuccess success
 *  @const SFError unspecified error
 *  @const SFErrorMisuse invalid use of the library
 *  @const SFErrorNoPerm access permission denied
 *  @const SFErrorNoFile file not found
 *  @const SFErrorBusy database file locked
 *  @const SFErrorCorrupt database file corrupted
 *  @const SFErrorEmpty empty database
 *  @const SFErrorAuth authorization denied
 *  @const SFErrorNoConn no internet connection
 *  @const SFErrorTimeout operation timeout
 *  @const SFErrorThread threading error
 *  @const SFErrorCredMismatch credentials mismatch
 *  @const SFErrorSlowConn internet connection too slow
 *  @const SFErrorNoRec record not found
 *  @const SFErrorAbort operation aborted
 *  @const SFErrorUnavail resource temporarily unavailable
 *  @const SFErrorImg image size or format not supported
 *  @const SFErrorApiKey wrong API key or no offline image
 *  @const SFErrorNetworkFail a network problem occurred
 *  @const SFErrorNotOpen scanner is not open
 *  @const SFErrorBundle could not read bundle
 *  @const SFErrorApiSecret wrong API secret
 *  @const SFErrorClientID bad or missing client ID
 *  @const SFErrorNotPremium not a premium user
 *  @const SFErrorRequestInProgress request still in progress
 *  @const SFErrorRequestFulfil request fulfilled. Create a new request to perform the operation
 *  @const SFErrorRequestProductsNotFound products not found
 *  @const SFErrorRequestBadImage bad image
 *  @const SFErrorRequestInvalidImage invalid image
 */

typedef enum{
    /** @abstract 0:  success. */
    SFSuccess = 0,
    /** @abstract 1:  unspecified error. */
    SFError,
    /** @abstract 2:  invalid use of the library. */
    SFErrorMisuse,
    /** @abstract 3:  access permission denied. */
    SFErrorNoPerm,
    /** @abstract 4:  file not found. */
    SFErrorNoFile,
    /** @abstract 5:  database file locked.  */
    SFErrorBusy,
    /** @abstract 6:  database file corrupted. */
    SFErrorCorrupt,
    /** @abstract 7:  empty database. */
    SFErrorEmpty,
    /** @abstract 8:  authorization denied. */
    SFErrorAuth,
    /** @abstract 9:  no internet connection. */
    SFErrorNoConn,
    /** @abstract 10: operation timeout. */
    SFErrorTimeout,
    /** @abstract 11: threading error. */
    SFErrorThread,
    /** @abstract 12: credentials mismatch. */
    SFErrorCredMismatch,
    /** @abstract 13: internet connection too slow. */
    SFErrorSlowConn,
    /** @abstract 14: record not found. */
    SFErrorNoRec,
    /** @abstract 15: operation aborted. */
    SFErrorAbort,
    /** @abstract 16: resource temporarily unavailable. */
    SFErrorUnavail,
    /** @abstract 17: image size or format not supported. */
    SFErrorImg,
    /** @abstract 18: wrong API key or no offline image. */
    SFErrorApiKey,
    /** @abstract 19: a network problem occurred. */
    SFErrorNetworkFail,
    /** @abstract 20: scanner is not open. */
    SFErrorNotOpen,
    /** @abstract 21: could not read bundle. */
    SFErrorBundle,
    /** @abstract 22: wrong API secret. */
    SFErrorApiSecret,
    /** @abstract 23: bad or missing client ID. */
    SFErrorClientID,
    /** @abstract 24: not a premium user. */
    SFErrorNotPremium,
    /** @abstract 25: request still in progress. */
    SFErrorRequestInProgress,
    /** @abstract 26: request fulfilled. Create a new request to perform the operation. */
    SFErrorRequestFulfil,
    /** @abstract 27: products not found */
    SFErrorRequestProductsNotFound,
    /** @abstract 28: bad image */
    SFErrorRequestBadImage,
    /** @abstract 29: invalid image */
    SFErrorRequestInvalidImage
}SFErrorCode;

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
