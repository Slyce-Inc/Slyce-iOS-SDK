import UIKit
import SlyceSDK

class ScannerViewController: TextViewViewController
{
    // Performing a Barcode Search or Image Match is similar to a Visual Search.
    // In order to differentiate between modes, we must provide the lensIdentifier
    // (used when creating a new Scanner, see viewDidLoad below).
    let lensIdentifier: SlyceLensIdentifier
    
    // A SlyceScanner attaches to an existing AVFoundation camera session and wires
    // Slyce into the active camera, allowing us to get instant continuous results.
    // We have created a Camera class that wraps the basic Apple boilerplate for
    // starting, resuming, and displaying a standard iOS camera.
    let camera = Camera()
    var cameraLayer: CALayer?
    
    var session: SlyceSession?
    var scanner: SlyceScanner?

    init(lensIdentifier identifier: SlyceLensIdentifier)
    {
        self.lensIdentifier = identifier
        super.init(nibName: nil, bundle: nil)
    }
    
    required init?(coder aDecoder: NSCoder)
    {
        fatalError()
    }
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        
        appendStringToTextView("\n\nStarting example Scanner...")

        // In some cases, we will not be able to access the camera.
        // This often happens when (1) running in the iOS simulator,
        // (2) if the user did not accept the iOS Camera Privacy popup.

        guard let layer = camera.start(),
            let slyceSession = try? SlyceSession(slyce: Slyce.shared()),
            let cameraSession = camera.cameraCaptureSession else {
            print("Unable to access Slyce session and/or start camera")
            return
        }
        
        layer.frame = CGRect(x: 0, y: 0, width: view.frame.width, height: view.frame.height)
        view.layer.addSublayer(layer)
        
        // After starting the camera, we want to add the preview layer to the current
        // view in order to see the output of the camera session.
        
        cameraLayer = layer
        session = slyceSession
        
        do {
            // Once the standard Apple camera is completely set up, AND Slyce has been opened,
            // we can create a scanner using the session and lens identifier. This might also
            // fail if the camera is unavailable.
            
            let slyceScanner = try SlyceScanner(session: slyceSession, lensIdentifier: lensIdentifier.rawValue, lensConfiguration: nil)
            scanner = slyceScanner
            
            try slyceScanner.attachTo(captureSession: cameraSession)

            // After attaching to a camera session, we MUST call resumeDetection to begin
            // detecting barcode or image match results.
            slyceScanner.resumeDetection()
            
            // In order to receive updates from the SlyceScanner after attaching it to an active
            // AVFoundation camera capture session, we must add a listener to the session, which
            // will feed us SlyceSearchTasks whenever they are created.
            slyceSession.addListener(self)
        } catch let e {
            print(e.localizedDescription)
        }
    }
}

extension ScannerViewController: SlyceSessionListener
{
    func slyce(session: SlyceSession, willStart searchTask: SlyceSearchTask)
    {
        // After creating a new task, we pause the scanner to prevent duplicate
        // scans of the same item, and we remove the preview layer to see the
        // text view underneath (see TextViewViewController).
        OperationQueue.main.addOperation {
            self.scanner?.suspendDetection() // unpause scanning with resumeDetection
            self.cameraLayer?.removeFromSuperlayer()
        }
        
        appendTaskToTextView(searchTask)
        
        // In order to receive updates to the task after it is created, we must
        // assign a listener, which will funnel information through the below
        // SlyceSearchTaskListener methods.
        searchTask.addListener(self)
    }
    
    func slyce(session: SlyceSession, didFinish searchTask: SlyceSearchTask)
    {
        appendTaskToTextView(searchTask, true)
    }
}

extension ScannerViewController: SlyceSearchTaskListener
{
    // These methods are used to handle the results and updates from Slyce after starting a search.
    // Here, we only display the raw data in the text view managed by the base class
    // (see TextViewViewController), however, in production, a view would be rendered to showcase
    // the output.
    
    func slyce(searchTask: SlyceSearchTask, didReceive update: SlyceSearchResponseUpdate)
    {
        appendUpdateToTextView(update)
    }
    
    func slyce(searchTask: SlyceSearchTask, didFailWith errors: [Error])
    {
        appendErrorsToTextView(errors)
    }
    
    func slyce(searchTask: SlyceSearchTask, didFinishWith response: SlyceSearchResponse)
    {
        appendResponseToTextView(response)
    }
}
