import UIKit
import SlyceSDK

class ViewController: UIViewController {
    
    let slyceAccountIdentifier = ""
    let slyceSpaceIdentifier = ""
    let slyceAPIKey = ""
    
    let useCustomSearchDetail = false // set to true to use custom search detail
    let applyCustomTheme = false // set to true to use custom theme values
    
    var slyceViewController: SlyceViewController?

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        if (applyCustomTheme) {
            self.applySlyceTheme()
        }
        
        // Slyce should be opened once, generally at application startup. We're doing
        // it here for demo purposes.
        
        Slyce.shared().open(accountIdentifier: slyceAccountIdentifier, apiKey: slyceAPIKey, spaceIdentifier: slyceSpaceIdentifier) { (errorOrNil) in
            if let error = errorOrNil {
                print("Error opening Slyce!\n" + error.localizedDescription)
                return;
            }
            
            guard let session = Slyce.shared().defaultSession else {
                fatalError();
            }
            
            let searchParams = SlyceSearchParameters();
            
            // All search parameters are optional and independent
            
            // Country Code
            //searchParams.countryCode = "BE"
            
            // Language Code
            //searchParams.languageCode = "fr"
            
            // Demo Mode. Set to `true` to receive test data
            //searchParams.demoMode = true
            
            // Setting search parameters here will automatically include them for all
            // SearchRequests in the session.
            session.defaultSearchParameters = searchParams;

            // The current completion block may not be on the main thread
            // so we dispatch the SlyceViewController creation on the main queue
            
            OperationQueue.main.addOperation {
                
                let vc = SlyceViewController(slyce: Slyce.shared(), mode: .picker)
                self.slyceViewController = vc
                vc.delegate = self
                self.present(vc, animated: true, completion: nil)
            }
        }
    }
    
    func applySlyceTheme() {
        // - Header
        SlyceTheme.shared().setAppearanceStyle(SlyceHeaderStyleLeft.backButton.rawValue, forPropertyName: "appearance_headerStyle_left")
        SlyceTheme.shared().setAppearanceStyle(SlyceHeaderStyleCenter.image.rawValue, forPropertyName: "appearance_headerStyle_center")
        SlyceTheme.shared().setAppearanceStyle(SlyceHeaderStyleRight.settings.rawValue, forPropertyName: "appearance_headerStyle_right")
        
        // - Accent Color
        SlyceTheme.shared().setColor(UIColor.purple, forPropertyName: "global_accent_color")
        
        // - Coaching Tips
        SlyceTheme.shared().setString("Your Headline Here", forPropertyName: "string_coachingTip_headline_visualSearch")
        SlyceTheme.shared().setString("Your body text here", forPropertyName: "string_coachingTip_body_visualSearch")
        SlyceTheme.shared().setImage(UIImage(named: "your_image")!, forPropertyName: "bg_coachingTip_visualSearch")
    }
}

extension ViewController : SlyceViewControllerDelegate {
    
    func slyceViewController(_ viewController: SlyceViewController, shouldDisplayDefaultDetailFor itemDescriptor: SlyceItemDescriptor) -> Bool {
        
        if (self.useCustomSearchDetail) {
            
            guard let slyceVC = self.slyceViewController else {
                fatalError("SlyceViewController was nil")
            }
            
            // This a very simple implementation that will present the custom search detail modally over
            // the SlyceViewController. In your application you may wish to dismiss the SlyceViewController
            // or push the detail controller in a navigation controller.
            
            let detailVC = SearchDetailViewController(nibName: "SearchDetailViewController", bundle: nil)
            detailVC.item = itemDescriptor.item
            slyceVC.present(detailVC, animated: true, completion: nil)
            
            return false
            
        } else {
            return true
        }
    }
}
