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
                let session = Slyce.shared().defaultSession()
                let vc = SlyceViewController(session: session, mode: .picker)
                self.present(vc, animated: true, completion: nil)
            }
        }
    }
}
