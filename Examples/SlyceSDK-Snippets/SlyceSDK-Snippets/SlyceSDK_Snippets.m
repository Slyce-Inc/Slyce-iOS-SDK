#import <SlyceSDK/SlyceSDK.h>

#pragma mark Search Parameters


/*!
 * @brief Demonstrates how to add custom workflow options for a single search task.
 */
void addWorkflowOptionsForSingleTask() {
    
    // set up some example data
    UIImage *searchImage = [[UIImage alloc] init]; // must use a real image in practice
    
    // create a `SlyceSearchParameters` object and set the workflow options dictionary.
    // this dictionary must only contain JSON-compatible values: strings, numbers, arrays
    // and other dictionaries
    SlyceSearchParameters *searchParams = [[SlyceSearchParameters alloc] init];
    searchParams.workflowOptions = @{@"key1": @"myValue",
                                     @"key2:": @5};
    
    SlyceSearchRequest *request = [[SlyceSearchRequest alloc] initWithImage:searchImage
                                                           searchParameters:searchParams];

    NSError *error;
    SlyceSession *session = [SlyceSession sessionWithSlyce:[Slyce shared] error:&error];
    if (session) {
        // handle error
        return;
    }
    [session startSearchTaskWithRequest:request workflowIdentifier:@"your workflow id" listener:nil];
}


void addDefaultWorkOptions() {
    
    // create a `SlyceSearchParameters` object and set the workflow options dictionary.
    // this dictionary must only contain JSON-compatible values: strings, numbers, arrays
    // and other dictionaries
    SlyceSearchParameters *searchParams = [[SlyceSearchParameters alloc] init];
    searchParams.workflowOptions = @{@"key1": @"myValue",
                                     @"key2:": @5};


    // add to a custom session
    SlyceSession *session = [SlyceSession sessionWithSlyce:[Slyce shared] error:NULL];
    session.defaultSearchParameters = searchParams;
    
    // or alternatively, add to the default session
    [Slyce shared].defaultSession.defaultSearchParameters = searchParams;
}


#pragma mark Analytics

/*!
 * @brief Demonstrates how to manually trigger analytics, for headless modes.
 *
 * @discussion This assumes that the Slyce instances has been configured and open.
 */
void reportManualAnalytics() {
    
    // set up some simple example variables
    NSString *jobId = @"xyz"; // retreieve this from a SlyceSearchResponse
    NSString *itemId = @"123";
    NSString *itemRevenue = @"$9.99";
    NSString *itemURL = @"https://store.com/123";
    NSInteger itemQuantity = 1;
    
    // track that an image was captured outside of the SlyceSDK
    [[Slyce shared].eventTracker trackCaptureImage];
 
    // track add to cart
    [[Slyce shared].eventTracker trackAddToCartTapForJobIdentifier:jobId
                                                    itemIdentifier:itemId
                                                        itemRevenue:itemRevenue
                                                            itemURL:itemURL
                                                       itemQuantity:itemQuantity];
    
    // track successful checkout
    [[Slyce shared].eventTracker trackCheckoutTapForJobIdentifier:jobId
                                                   itemIdentifier:itemId
                                                       itemRevenue:itemRevenue
                                                           itemURL:itemURL
                                                      itemQuantity:itemQuantity];
}
