// NOTE: SlyceViewController functionality is currently Public *Preview*

import UIKit
import SlyceSDK
import SlyceSDK.Private

class ViewController: UIViewController {

    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        let slyceAccountIdentifier = ""
        let apiKey = ""
        let spaceIdentifier = ""
        
        let useCustomSearchDetail = false // set to true to use custom search detail
        
        // Slyce should be opened once, generally at application startup. We're doing
        // it here for demo purposes.
        
        Slyce.shared().open(accountIdentifier: slyceAccountIdentifier, apiKey: apiKey, spaceIdentifier: spaceIdentifier) { (errorOrNil) in
            if let error = errorOrNil {
                print("Error opening Slyce!\n" + error.localizedDescription)
                return;
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
