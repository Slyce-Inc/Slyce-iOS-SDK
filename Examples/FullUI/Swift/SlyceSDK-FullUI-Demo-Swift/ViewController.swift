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
        
        Slyce.shared().open(accountIdentifier: slyceAccountIdentifier, apiKey: apiKey, spaceIdentifier: spaceIdentifier) { (errorOrNil) in
            if let error = errorOrNil {
                print("Error opening Slyce!\n" + error.localizedDescription)
                return;
            }

            // The current completion block may not be on the main thread
            // so we dispatch the SlyceViewController creation on the main queue
            
            OperationQueue.main.addOperation {
                guard let vc = Slyce.shared().defaultSession().slyceViewController(with: .picker) else {
                    // If Slyce has been opened, this should not be nil
                    fatalError("Could not build SlyceViewController")
                }
                
                self.present(vc, animated: true, completion: nil)
            }
        }
    }
}
