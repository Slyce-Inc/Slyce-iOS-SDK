#import <SlyceSDK/SlyceSDK.h>

#pragma mark Analytics

/*!
 * @brief Demonstrates how to manually trigger analytics, for headless modes.
 *
 * @discussion This assumes that the Slyce instances has been configured and open.
 */
void reportManualAnalytics() {
    
    // set up some simple example variables
    NSString *itemId = @"123";
    NSString *itemRevenue = @"$9.99";
    NSString *itemURL = @"https://store.com/123";
    NSInteger itemQuantity = 1;
    
    // track that an image was captured outside of the SlyceSDK
    [[Slyce shared].eventTracker trackCaptureImage];
 
    // track add to cart
    [[Slyce shared].eventTracker trackAddToCartTapForItemIdentifier:itemId
                                                        itemRevenue:itemRevenue
                                                            itemURL:itemURL
                                                       itemQuantity:itemQuantity];
    
    // track successful checkout
    [[Slyce shared].eventTracker trackCheckoutTapForItemIdentifier:itemId
                                                       itemRevenue:itemRevenue
                                                           itemURL:itemURL
                                                      itemQuantity:itemQuantity];
}
