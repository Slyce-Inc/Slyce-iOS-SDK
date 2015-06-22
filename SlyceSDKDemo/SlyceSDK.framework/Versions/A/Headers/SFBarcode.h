//
//  SFBarcode.h
//  SlyceSDK
//
//  Created by Nathan Gurfinkel on 2/4/15.
//  Copyright (c) 2015 Slyce. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 * Enumeration for barcode result types.
 */
typedef NS_ENUM(NSUInteger, SFBarcodeType)
{
    /*! None. */
    SFBarcodeTypeNone,
    
    /*! Aztec 2D barcode format. */
    SFBarcodeTypeAztec,
    
    /*! CODABAR 1D format. */
    SFBarcodeTypeCodabar,
    
    /*! Code 39 1D format. */
    SFBarcodeTypeCode39,
    
    /*! Code 93 1D format. */
    SFBarcodeTypeCode93,
    
    /*! Code 128 1D format. */
    SFBarcodeTypeCode128,
    
    /*! Data Matrix 2D barcode format. */
    SFBarcodeTypeDataMatrix,
    
    /*! EAN-8 1D format. */
    SFBarcodeTypeEan8,
    
    /*! EAN-13 1D format. */
    SFBarcodeTypeEan13,
    
    /*! ITF (Interleaved Two of Five) 1D format. */
    SFBarcodeTypeITF,
    
    /*! MaxiCode 2D barcode format. */
    SFBarcodeTypeMaxiCode,
    
    /*! PDF417 format. */
    SFBarcodeTypePDF417,
    
    /*! QR Code 2D barcode format. */
    SFBarcodeTypeQRCode,
    
    /*! RSS 14 */
    SFBarcodeTypeRSS14,
    
    /*! RSS EXPANDED */
    SFBarcodeTypeRSSExpanded,
    
    /*! UPC-A 1D format. */
    SFBarcodeTypeUPCA,
    
    /*! UPC-E 1D format. */
    SFBarcodeTypeUPCE,
    
    /*! UPC/EAN extension format. Not a stand-alone format. */
    SFBarcodeTypeUPCEANExtension
};

/*! 
 *  @brief Class representing a barcode
 */

@interface SFBarcode : NSObject

/*! The barcode result type. */
@property (nonatomic, readonly) SFBarcodeType type;

/*! The barcode result type in a string representation. */
@property (nonatomic, copy, readonly) NSString *typeString;

/*! The UTF-8 encoded string representing the scan result. */
@property (nonatomic, copy, readonly) NSString *text;

/*!
 @brief Designated initializer.
 @param type Barcode type.
 @param text Barcode string.
 @return instance of SFBarcode.
 */
- (instancetype)initWithType:(SFBarcodeType)type andText:(NSString *)text;

@end
