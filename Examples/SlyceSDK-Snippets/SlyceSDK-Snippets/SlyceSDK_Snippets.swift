import SlyceSDK


// MARK: Search Parameters

/**
 Demonstrates how to add custom workflow options for a single search task.
 */
func addWorkflowOptionsForSingleTask() {
    
    // set up some example data
    let searchImage = UIImage()  // must use a real image in practice
    
    // create a `SlyceSearchParameters` object and set the workflow options dictionary.
    // this dictionary must only contain JSON-compatible values: strings, numbers, arrays
    // and other dictionaries
    let searchParams = SlyceSearchParameters()
    searchParams.workflowOptions = ["key1": "myValue",
                                    "key2:": 5]
    

    let request = SlyceSearchRequest(image: searchImage, searchParameters: searchParams)
    
    do {
        let session = try SlyceSession(slyce: Slyce.shared())
        session.startSearchTask(request: request, workflowIdentifier: "your workflow id", listener: nil)
    } catch {
        // handle error
    }
}

func addDefaultWorkOptions() {
    
    // create a `SlyceSearchParameters` object and set the workflow options dictionary.
    // this dictionary must only contain JSON-compatible values: strings, numbers, arrays
    // and other dictionaries
    let searchParams = SlyceSearchParameters()
    searchParams.workflowOptions = ["key1": "myValue",
                                    "key2:": 5]
    
    // add to a custom session
    do {
        let session = try SlyceSession(slyce: Slyce.shared())
        session.defaultSearchParameters = searchParams
    } catch {
        // handle error
    }
    
    // or alternatively, add to the default session
    Slyce.shared().defaultSession?.defaultSearchParameters = searchParams
}


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
