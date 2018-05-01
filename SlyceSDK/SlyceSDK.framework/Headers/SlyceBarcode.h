#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>

/*!
 * Enumeration for barcode result types.
 */
typedef NS_ENUM(NSUInteger, SlyceBarcodeType) {
    /*! None. */
    SlyceBarcodeTypeNone,
    
    /*! Aztec 2D barcode format. */
    SlyceBarcodeTypeAztec,
    
    /*! CODABAR 1D format. */
    SlyceBarcodeTypeCodabar,
    
    /*! Code 39 1D format. */
    SlyceBarcodeTypeCode39,
    
    /*! Code 93 1D format. */
    SlyceBarcodeTypeCode93,
    
    /*! Code 128 1D format. */
    SlyceBarcodeTypeCode128,
    
    /*! Data Matrix 2D barcode format. */
    SlyceBarcodeTypeDataMatrix,
    
    /*! EAN-8 1D format. */
    SlyceBarcodeTypeEan8,
    
    /*! EAN-13 1D format. */
    SlyceBarcodeTypeEan13,
    
    /*! ITF (Interleaved Two of Five) 1D format. */
    SlyceBarcodeTypeITF,
    
    /*! MaxiCode 2D barcode format. */
    SlyceBarcodeTypeMaxiCode,
    
    /*! PDF417 format. */
    SlyceBarcodeTypePDF417,
    
    /*! QR Code 2D barcode format. */
    SlyceBarcodeTypeQRCode,
    
    /*! RSS 14 */
    SlyceBarcodeTypeRSS14,
    
    /*! RSS EXPANDED */
    SlyceBarcodeTypeRSSExpanded,
    
    /*! UPC-A 1D format. */
    SlyceBarcodeTypeUPCA,
    
    /*! UPC-E 1D format. */
    SlyceBarcodeTypeUPCE,
    
    /*! UPC/EAN extension format. Not a stand-alone format. */
    SlyceBarcodeTypeUPCEANExtension
};

/*! 
 *  @brief Class representing a barcode
 */
@interface SlyceBarcode : NSObject <NSCoding>

/*!
 * @property
 *
 * @brief The barcode result type.
 *
 */
@property(nonatomic, readonly) SlyceBarcodeType type;


/*!
 * @property
 *
 * @brief The barcode result type in a string representation.
 *
 */
@property(nonatomic, copy, readonly, nonnull) NSString *typeString;


/*!
 * @property
 *
 * @brief The UTF-8 encoded string representing the scan result.
 *
 */
@property(nonatomic, copy, readonly, nonnull) NSString *text;


/*!
 * @property
 *
 * @brief The barcode's AVFoundation metadata.
 *
 */
@property (nonatomic, strong, nullable) AVMetadataMachineReadableCodeObject *metadata;

/*!
 * @method
 *
 * @brief Designated initializer.
 *
 * @discussion Use this method to create a new `SlyceSearchRequest`.
 *
 * @param type Barcode type.
 * @param text Barcode string.
 *
 * @return instance of SlyceBarcode.
 */
- (nonnull instancetype)initWithType:(SlyceBarcodeType)type
                             andText:(nonnull NSString *)text
NS_DESIGNATED_INITIALIZER NS_SWIFT_NAME(init(type:text:));


/*!
 * @method
 *
 * @brief Convert a `SlyceBarcodeType` value to string format.
 *
 * @param barcodeType Barcode type.
 *
 * @return a string representation of the barcode type
 */
+ (nullable NSString *)stringFromBarcodeType:(SlyceBarcodeType)barcodeType;


/*!
 * @method
 *
 * @brief Convert a string to a `SlyceBarcodeType` value.
 *
 * @param typeString Barcode type string representation.
 *
 * @return The `SlyceBarcodeType` value, or `SlyceBarcodeTypeNone` if the string could not be converted.
 */
+ (SlyceBarcodeType)barcodeTypeFromString:(nonnull NSString *)typeString
NS_SWIFT_NAME(barcodeType(fromString:));


@end
