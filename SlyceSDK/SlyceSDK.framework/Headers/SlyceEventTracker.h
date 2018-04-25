#import <Foundation/Foundation.h>

@protocol SlyceEventTracker <NSObject>

/**
 * Tracks a user action to zoom in.
 */
- (void)trackZoomIn;

/**
 * Tracks a user action to zoom out.
 */
- (void)trackZoomOut;

/**
 * Tracks a user action to turn on the flash.
 */
- (void)trackTurnOnFlash;

/**
 * Tracks a user action to turn off the flash.
 */
- (void)trackTurnOffFlash;

/**
 * Tracks a user action to tap to focus.
 */
- (void)trackTapToFocus;

/**
 * Tracks a user action to capture an image.
 */
- (void)trackCaptureImage;

/**
 * Tracks a user action to tap to share feedback.
 */
- (void)trackShareFeedbackTap;

/**
 * Tracks a user action to tap to view a product's information.
 *
 * @param itemIdentifier The item identifier.
 * @param itemURL The item URL.
 */
- (void)trackViewProductInformationTapForItemIdentifier:(nullable NSString *)itemIdentifier
                                                itemURL:(nullable NSString *)itemURL;

/**
 * Tracks a user action to tap to view a product's reviews.
 *
 * @param itemIdentifier The item identifier.
 * @param itemURL The item URL.
 */
- (void)trackViewProductReviewsTapForItemIdentifier:(nullable NSString *)itemIdentifier
                                            itemURL:(nullable NSString *)itemURL;

/**
 * Tracks a user action to tap to add a product to a list.
 *
 * @param itemIdentifier  The item identifier.
 * @param itemURL The item URL.
 */
- (void)trackAddToListTapForItemIdentifier:(nullable NSString *)itemIdentifier
                                   itemURL:(nullable NSString *)itemURL;

/**
 * Tracks a user action to tap to specify the item quantity.
 *
 * @param itemIdentifier The item identifier.
 * @param itemURL      The item URL.
 * @param itemQuantity The item quantity.
 */
- (void)trackItemQuantityTapForItemIdentifier:(nullable NSString *)itemIdentifier
                                      itemURL:(nullable NSString *)itemURL
                                 itemQuantity:(NSInteger)itemQuantity;

/**
 * Tracks a user action to add an item to the cart.
 *
 * @param itemIdentifier The item identifier.
 * @param itemRevenue  The item revenue.
 * @param itemURL      The item URL.
 * @param itemQuantity The item quantity.
 */
- (void)trackAddToCartTapForItemIdentifier:(nullable NSString *)itemIdentifier
                               itemRevenue:(nullable NSString *)itemRevenue
                                   itemURL:(nullable NSString *)itemURL
                              itemQuantity:(NSInteger)itemQuantity;

/**
 * Tracks a user action to checkout.
 *
 * @param itemIdentifier The item identifier.
 * @param itemRevenue  The item revenue.
 * @param itemURL      The item URL.
 * @param itemQuantity The item quantity.
 */
- (void)trackCheckoutTapForItemIdentifier:(nullable NSString *)itemIdentifier
                              itemRevenue:(nullable NSString *)itemRevenue
                                  itemURL:(nullable NSString *)itemURL
                             itemQuantity:(NSInteger)itemQuantity;

/**
 * Tracks the successful completion of a user order.
 *
 * @param itemRevenue         The item revenue.
 * @param transactionCurrency The transaction currency.
 * @param transactionId       The transaction ID.
 * @param transactionRevenue  The transaction revenue.
 * @param transactionShipping The transaction shipping.
 * @param transactionTax      The transaction tax.
 * @param itemQuantity        The item quantity.
 */
- (void)trackOrderSuccessfullyCompletedForItemRevenue:(nullable NSString *)itemRevenue
                                  transactionCurrency:(nullable NSString *)transactionCurrency
                                        transactionId:(nullable NSString *)transactionId
                                   transactionRevenue:(nullable NSString *)transactionRevenue
                                  transactionShipping:(nullable NSString *)transactionShipping
                                       transactionTax:(nullable NSString *)transactionTax
                                         itemQuantity:(NSInteger)itemQuantity;

@end
