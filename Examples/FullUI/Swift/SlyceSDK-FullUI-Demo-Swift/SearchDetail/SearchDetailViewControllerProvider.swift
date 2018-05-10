import Foundation
import SlyceSDK
import SlyceSDK.Private

class SearchDetailViewControllerProvider: NSObject, SlyceCustomSearchDetailViewControllerProvider {
    
    func searchDetailViewViewController(forResultItem resultItem: [AnyHashable : Any]) -> UIViewControllerlleroller? {
        
        let vc = SearchDetailViewController();
        vc.slyceResultItem = resultItem;
        return vc
    }
    
}
