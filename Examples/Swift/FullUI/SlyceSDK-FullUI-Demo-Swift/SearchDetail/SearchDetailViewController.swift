
import UIKit

class SearchDetailViewController: UIViewController {
    
    @IBOutlet weak var itemTextView: UITextView?
    
    var item: [AnyHashable: Any]? {
        didSet {
            updateItemTextView()
        }
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        updateItemTextView()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func close(_ sender: UIButton) {
        self.dismiss(animated: true, completion: nil)
    }
    
    fileprivate func updateItemTextView() {
        self.itemTextView?.text = self.item?.description
    }

}
