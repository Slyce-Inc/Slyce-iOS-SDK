import UIKit
import SlyceSDK

class VisualSearchViewController: TextViewViewController
{
    // This class performs a Slyce visual search immediately when launched.
    // In order to get results, the user MUST already have opened Slyce.
    // In order to send the search through the correct workflow, the workflow key is included.

    var visualSearchWorkflowIdentifier: String { return "" }
    var visualSearchExampleImage: UIImage { return UIImage(named: "shirt")! }
    
    let session: SlyceSession = Slyce.shared().defaultSession!
    var task: SlyceSearchTask?
    
    init()
    {
        super.init(nibName: nil, bundle: nil)
    }
    
    required init?(coder aDecoder: NSCoder)
    {
        fatalError("init(coder:) has not been implemented")
    }
    
    override func viewDidLoad()
    {
        super.viewDidLoad()
        
        appendStringToTextView("\n\nStarting example Visual Search...")
        
        let workflowIdentifier = visualSearchWorkflowIdentifier
        let image = visualSearchExampleImage

        // We create a new request, which encapsulates the payload needed to start a visual search.
        // Instead of attaching an image, an imageURL may also be used.
        // Anchor is optional, and represents the tap point relative to the coordinates of the image.
        
        // Optionally, we can add additional search parameters
        let searchParams = SlyceSearchParameters()
        searchParams.workflowOptions = ["gender": "F"]
        
        let request = SlyceSearchRequest(image: image, anchor: SlyceAnchorPointNone, searchParameters: searchParams)

        // In order to receive updates after starting the task, we must provide a SlyceSearchTaskListener,
        // which will be called whenever there are errors, updates, or a completed result.
        task = session.startSearchTask(request: request, workflowIdentifier: workflowIdentifier, listener: self)
        appendTaskToTextView(task!)
    }
    
    override func viewDidDisappear(_ animated: Bool)
    {
        super.viewDidDisappear(animated)
        
        // We can cancel all tasks via the session if we no longer need updates or results.
        session.cancelAllTasks()
    }
}

extension VisualSearchViewController: SlyceSearchTaskListener
{
    // These methods are used to handle the results and updates from Slyce after starting a search.
    // Here, we only display the raw data in the text view managed by the base class
    // (see TextViewViewController), however, in production, a view would be rendered to showcase
    // the output.

    func slyce(searchTask: SlyceSearchTask, didFailWith errors: [Error])
    {
        appendErrorsToTextView(errors)
    }
    
    func slyce(searchTask: SlyceSearchTask, didReceive update: SlyceSearchResponseUpdate)
    {
        appendUpdateToTextView(update)
    }
    
    func slyce(searchTask: SlyceSearchTask, didFinishWith response: SlyceSearchResponse)
    {
        appendResponseToTextView(response)
    }
}
