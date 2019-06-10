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
    Slyce.shared().defaultSearchParameters = searchParams
}

/**
 Demonstrates how to perform a Find Similar search task by setting workflow options or with an image url.
 */
func findSimilarTask() {
    var request: SlyceSearchRequest
    
    // Search with an image url or item identifier
    if let url = URL(string: "http://imageUrl") {
        request = SlyceSearchRequest(imageURL: url.absoluteString, searchParameters: SlyceSearchParameters())
    } else {
        let parameters = SlyceSearchParameters()
        parameters.workflowOptions = ["item_id": "myValue"]
        request = SlyceSearchRequest(searchParameters: parameters)
    }
    
    let workflowName = SlyceWorkflowName.findSimilar
    
    do {
        let session = try SlyceSession(slyce: Slyce.shared())
        try session.startSearchTask(request: request, workflowName: workflowName, listener: nil)
    } catch {
        // handle error
    }
}


// MARK: Analytics

/**
 Demonstrates how to manually trigger analytics, for headless modes
 
 This assumes that the Slyce instances has been configured and open.
 
 */
func reportManualAnalytics() {
    

    // set up some simple example variables
    let jobId = "xyz" // retreieve this from a SlyceSearchResponse
    let itemId = "123"
    let itemRevenue = "$9.99"
    let itemURL = "https://store.com/123"
    let itemQuantity = 1

    // track that an image was captured outside of the SlyceSDK
    Slyce.shared().eventTracker.trackCaptureImage()
    
    // track add to cart
    Slyce.shared().eventTracker.trackAddToCartTap(forJobIdentifier: jobId, itemIdentifier: itemId, itemRevenue: itemRevenue, itemURL: itemURL, itemQuantity: itemQuantity)
    
    // track successful checkout
    Slyce.shared().eventTracker.trackCheckoutTap(forJobIdentifier: jobId, itemIdentifier: itemId, itemRevenue: itemRevenue, itemURL: itemURL, itemQuantity: 1)
}


// MARK: Full UI Mode

/*!
 * @brief Shows how to display the universal lens in the "Legacy Multi Search" capture mode
 *
 * @discussion This assumes that the Slyce instances has been configured and open.
 */
func legacyMultiSearch() {
    
    // Create an options dictionary, with the appropriate capture mode set for the Universal lens
    let options = [
        SlyceOptionKey.Lenses: [
            SlyceLensIdentifier.universal: [
                SlyceLensOptionKey.captureMode: SlyceLensCaptureMode.legacyMulti
            ]
        ]
    ]

    let _ = SlyceViewController(slyce: Slyce.shared(), mode: .universal, options: options, delegate: nil)
    
    // Present view controller here...
}
