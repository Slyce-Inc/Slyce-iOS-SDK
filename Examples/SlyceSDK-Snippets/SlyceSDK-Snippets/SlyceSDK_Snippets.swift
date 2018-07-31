import SlyceSDK

// MARK: Analytics

/**
 Demonstrates how to manually trigger analytics, for headless modes
 
 This assumes that the Slyce instances has been configured and open.
 
 */
func reportManualAnalytics() {

    // set up some simple example variables
    let itemId = "123"
    let itemRevenue = "$9.99"
    let itemURL = "https://store.com/123"
    let itemQuantity = 1

    // track that an image was captured outside of the SlyceSDK
    Slyce.shared().eventTracker.trackCaptureImage()
    
    // track add to cart
    Slyce.shared().eventTracker.trackAddToCartTap(forItemIdentifier: itemId, itemRevenue: itemRevenue, itemURL: itemURL, itemQuantity: itemQuantity)
    
    // track successful checkout
    Slyce.shared().eventTracker.trackCheckoutTap(forItemIdentifier: itemId, itemRevenue: itemRevenue, itemURL: itemURL, itemQuantity: 1)
}
