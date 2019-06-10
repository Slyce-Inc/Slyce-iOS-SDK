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
    [Slyce shared].defaultSearchParameters = searchParams;
}

/*!
 * @brief Demonstrates how to perform a Find Similar search task by setting workflow options or with an image url.
 */
void findSimilarTask() {
    SlyceSearchRequest *request;
    
    NSURL *url = [[NSURL alloc] initWithString:@"http://imageUrl"];
    
    // Search with an image url or item identifier
    if (url != nil) {
        request = [[SlyceSearchRequest alloc] initWithImageURL:url.absoluteString
                                              searchParameters:[[SlyceSearchParameters alloc] init]];
    } else {
        SlyceSearchParameters *parameters = [[SlyceSearchParameters alloc] init];
        parameters.workflowOptions = @{ @"item_id": @"myValue" };
        request = [[SlyceSearchRequest alloc] initWithSearchParameters:parameters];
    }
    
    NSError *error;
    SlyceSession *session = [SlyceSession sessionWithSlyce:[Slyce shared] error:&error];
    if (!session) {
        // handle error
        return;
    }
    
    NSError *searchError;
    [session startSearchTaskWithRequest:request workflowName:SlyceWorkflowNameFindSimilar listener:NULL error:&searchError];
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


#pragma mark Full UI Mode

/*!
 * @brief Shows how to display the universal lens in the "Legacy Multi Search" capture mode
 *
 * @discussion This assumes that the Slyce instances has been configured and open.
 */
void legacyMultiSearch() {
    
    // Create an options dictionary, with the appropriate capture mode set for the Universal lens
    NSDictionary *options = @{
                              SlyceOptionLensesKey: @{
                                      SlyceLensIdentifierUniversal: @{
                                              SlyceLensOptionKeyCaptureMode: SlyceLensCaptureModeLegacyMulti
                                              }
                                      }
                              };
    
    SlyceViewController *slyceVC __unused;
    slyceVC = [[SlyceViewController alloc] initWithSlyce:[Slyce shared]
                                                    mode:SlyceViewControllerModeUniversal
                                                 options:options
                                                delegate:nil];
    
    // Present view controller here...
}

