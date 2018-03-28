#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
@interface SlyceLayerSearchResult: NSObject <NSCoding>

@property(nonatomic, nonnull) NSDate* createdDate;
@property(nonatomic, nonnull) NSDictionary* searchResultJSON;
@property(nonatomic, nullable) NSString* searchItemId;

@property(nonatomic, nullable) NSArray <NSString *>* searchProductColors;
@property(nonatomic, nullable) NSArray* searchProductGTINS;
@property(nonatomic, nullable) NSArray* searchProductGenders;
@property(nonatomic, nullable) NSArray* searchProductImageURLs;
@property(nonatomic, nullable) NSArray <NSString *>* searchProductSizes;
@property(nonatomic, nullable) NSArray* searchProductTags;

@property(nonatomic, nullable) NSString* searchProductBrand;
@property(nonatomic, nullable) NSString* searchProductCategory;
@property(nonatomic, nullable) NSString* searchProductDescription;
@property(nonatomic, nullable) NSString* searchProductId;
@property(nonatomic, nullable) NSString* searchProductImageURL;
@property(nonatomic, nullable) NSString* searchProductMaterials;
@property(nonatomic, nullable) NSString* searchProductName;
@property(nonatomic, nullable) NSString* searchProductPatterns;
@property(nonatomic, nullable) NSString* searchProductURL;
@property(nonatomic, nullable) NSString* searchProductAltId;

@property(nonatomic) BOOL searchProductInStock;

@property(nonatomic, nullable) NSNumber* searchProductPrice;
@property(nonatomic, nullable) NSNumber* searchProductSalePrice;

@property(nonatomic, nullable) NSNumber* searchProductReviewCount;
@property(nonatomic, nullable) NSNumber* searchProductStarRating;
@property(nonatomic, nullable) NSNumber* sku;
@property(nonatomic, nullable) NSString* barcodeText;

- (instancetype) initWithJSON:(nonnull NSData*)JSON
NS_SWIFT_NAME(init(json:));

- (instancetype) initWithDictionary:(nonnull NSDictionary*)array
NS_SWIFT_NAME(init(dictionary:));

- (nullable NSString*) searchFormattedPriceString;

- (NSString*) effectiveSearchResultID;

+ (nonnull NSArray<SlyceLayerSearchResult *> *)arrayFromDictionaryArray:(nonnull NSArray<NSDictionary *> *)dictArray;

+ (SlyceLayerSearchResult *)firstExample;
+ (SlyceLayerSearchResult *)secondExample;
+ (SlyceLayerSearchResult *)exampleSearchResult;

@end
NS_ASSUME_NONNULL_END
