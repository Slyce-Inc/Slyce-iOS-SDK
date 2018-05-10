import Foundation
import SlyceSDK
import SlyceSDK.Private

class SearchDetailViewControllerProvider: NSObject, SlyceCustomSearchDetailViewControllerProvider
{
    func searchDetailViewController(forResultItem resultItem: [AnyHashable : Any]) -> UIViewController? {
        
        let vc = SearchDetailViewController();
        vc.slyceResultItem = resultItem;
        return vc
    }
    
}
