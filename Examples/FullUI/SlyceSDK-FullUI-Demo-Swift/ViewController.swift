// NOTE: SlyceViewController functionality is currently Public *Preview*

import UIKit
import SlyceSDK
import SlyceSDK.Private

class ViewController: UIViewController {

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        // Uncomment the following lines to customize the Full UI experience using SlyceTheme
        // - Header
        // SlyceTheme.shared().headerLeftNavigation = .backButton
        // SlyceTheme.shared().headerCenter = .image
        // SlyceTheme.shared().headerRightNavigation = .settings
        
        // - Accent Color
        // SlyceTheme.shared().global_accent_color = UIColor.purple
        
        // - Coaching Tips
        // SlyceTheme.shared().string_coachingTip_headline_visualSearch = ""
        // SlyceTheme.shared().string_coachingTip_body_visualSearch = ""
        // SlyceTheme.shared().bg_coachingTip_visualSearch = UIImage(named: "")
        
        let slyceAccountIdentifier = ""
        let spaceIdentifier = ""
        let apiKey = ""
        
        let useCustomSearchDetail = false // set to true to use custom search detail
        let useCustomSearchParams = false // set to use custom search params for the entire session

        // Slyce should be opened once, generally at application startup. We're doing
        // it here for demo purposes.
        
        Slyce.shared().open(accountIdentifier: slyceAccountIdentifier, apiKey: apiKey, spaceIdentifier: spaceIdentifier) { (errorOrNil) in
            if let error = errorOrNil {
                print("Error opening Slyce!\n" + error.localizedDescription)
                return;
            }
            
            if (useCustomSearchParams) {
                // (Optional) Use to set custom language and/or country codes
                
                guard let session = Slyce.shared().defaultSession else {
                    fatalError();
                }
                
                let searchParams = SlyceSearchParameters();
                searchParams.countryCode = "BE"    // one of both of these may be set
                searchParams.languageCode = "fr"
                
                // Setting search parameters here will automatically include them for all
                // SearchRequests in the session.
                session.defaultSearchParameters = searchParams;
            }

            // The current completion block may not be on the main thread
            // so we dispatch the SlyceViewController creation on the main queue
            
            OperationQueue.main.addOperation {
                let vc = SlyceViewController(slyce: Slyce.shared(), mode: .picker)
                if useCustomSearchDetail {
                    vc.customSearchDetailViewControllerProvider = SearchDetailViewControllerProvider()
                }
                self.present(vc, animated: true, completion: nil)
            }
        }
    }
}
