import UIKit
import SlyceSDK

class ViewController: UIViewController
{
    override func viewDidLoad()
    {
        super.viewDidLoad()
        setupSlyce()
    }
    
    func setupSlyce()
    {
        // Slyce should be opened once, generally at application startup.
        
        let accountIdentifier = ""
        let spaceIdentifier = ""
        let apiKey = ""
        
        Slyce.shared().open(accountIdentifier: accountIdentifier, apiKey: apiKey, spaceIdentifier: spaceIdentifier) { (err) in
            if let validErr = err {
                print("Unable to login to Slyce, " + validErr.localizedDescription)
            } else {
                OperationQueue.main.addOperation {
                    self.setupLensView()
                }
            }
        }
    }
    
    func setupLensView()
    {
        // In order to create a LensView, we must provide an active session
        // (available once opening Slyce), and a lensIdentifier, which is specific
        // to the lens type.
        //
        // In this case, we are creating a LensView which can
        // be used to detect and receive Visual Search results.
        
        guard let session = try? SlyceSession(slyce: Slyce.shared()) else {
            print("Unable to access Slyce!")
            return
        }
        
        let lensIdentifier = SlyceLensIdentifier.visualSearch
        
        do {
            // A LensView can be added to any superview and is a fully contained Slyce
            // camera experience, managed through the session and configuration given
            // at init-time.
            let lensView = try SlyceLensView(session: session, lensIdentifier: lensIdentifier.rawValue, settings: nil)
            lensView.frame = view.frame
            view.addSubview(lensView)
            
            // In order to receive results, we must add ourselves as a listener on the session.
            session.addListener(self)
        } catch let e {
            print("Unable to start camera, " + e.localizedDescription)
            return
        }
    }
}

extension ViewController: SlyceSessionListener
{
    func slyce(session: SlyceSession, didCreateSearchTask searchTask: SlyceSearchTask)
    {
        // In order to receive updates to the task after it is created, we must
        // assign a listener, which will funnel information through the below
        // SlyceSearchTaskListener methods.
        searchTask.addListener(self)
        print("\nSession didCreateSearchTask:\n\t", searchTask.debugDescription)
    }
}

extension ViewController: SlyceSearchTaskListener
{
    // These methods are used to handle the results and updates from Slyce after starting a search.
    
    func slyce(searchTask: SlyceSearchTask, didFailWith errors: [Error])
    {
        print("\nSearch Task didFailWithErrors:\n\t", errors.debugDescription)
    }
    
    func slyce(searchTask: SlyceSearchTask, didReceive update: SlyceSearchResponseUpdate)
    {
        print("\nSearch Task didUpdate:\n\t", update.debugDescription)
    }
    
    func slyce(searchTask: SlyceSearchTask, didFinishWith response: SlyceSearchResponse)
    {
        print("\nSearch Task didFinishWithResponse:\n\t", response.debugDescription)
    }
}
