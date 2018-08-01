import UIKit
import SlyceSDK

class TableViewController: UITableViewController
{
    let requireGDPR = false // set to `true` to use GDPR compliance support
    
    // MARK: - Slyce
    var slyceIsOpen: Bool {
        return Slyce.shared().isOpen()
    }
    
    func openSlyce() {
        // Slyce should be opened once, generally at application startup. We have to
        // do so before launching any of our demos in order to get results.

        let accountIdentifier = ""
        let spaceIdentifier = ""
        let apiKey = ""
        
        // GDPR Compliance support (optional)
        if (requireGDPR) {
            Slyce.shared().complianceManager.userRequiresGDPRCompliance = true
        }
        
        
        Slyce.shared().open(accountIdentifier: accountIdentifier, apiKey: apiKey, spaceIdentifier: spaceIdentifier) { (err) in
            OperationQueue.main.addOperation {
                
                if (self.requireGDPR) {
                    
                    guard let privacyPolicy = Slyce.shared().complianceManager.privacyPolicy else {
                        fatalError("failed to retrieve Privacy Policy")
                    }
                    
                    // Here you are required to display the information in the Privacy Policy and capture
                    // the user's consesnt. See documentation for `SlycePrivacyPolicy`.
                    
                    // If user consensents...
                    Slyce.shared().complianceManager.setUserConsentedTo(privacyPolicy)
                }
                
                self.tableView.reloadData()
            }
        }
    }
    
    func openSlyceExample(_ number: Int) {
        if slyceIsOpen == false {
            return
        }
        
        // Depending on which mode the user tapped, launch the appropriate
        // view controller which completely handles the Slyce search.
        
        var viewController: UIViewController
        
        switch (number) {
        case 0:
            viewController = VisualSearchViewController()
        case 1:
            viewController = ScannerViewController(lensIdentifier: SlyceLensIdentifierBarcode)
        case 2:
            viewController = ScannerViewController(lensIdentifier: SlyceLensIdentifierImageMatching)
        default:
            return
        }
        
        navigationController?.pushViewController(viewController, animated: true)
    }
    
    // MARK: - UI
    override func viewDidLoad()
    {
        super.viewDidLoad()
        
        // The following code is used to setup and show all Headless
        // example modes in a standard UITableView frontend.
        //
        // None of this code is necessary to run Slyce and
        // is only included to help navigate the example app.

        title = "Slyce SDK 5 Headless Examples"
        tableView.register(TableViewCell.self, forCellReuseIdentifier: TableViewCell.reuseIdentifier)
    }
    
    override func numberOfSections(in tableView: UITableView) -> Int
    {
        return slyceIsOpen ? 2 : 1
    }
    
    override func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int
    {
        if section == 0 {
            return 1
        }
        
        return 3
    }
    
    override func tableView(_ tableView: UITableView, titleForHeaderInSection section: Int) -> String?
    {
        if section == 0 {
            return "Connect to Slyce to use demos."
        }
        
        return "Tap below to perform an example search."
    }
    
    override func tableView(_ tableView: UITableView, heightForRowAt indexPath: IndexPath) -> CGFloat
    {
        return 60
    }
    
    override func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell
    {
        let cell = tableView.dequeueReusableCell(withIdentifier: TableViewCell.reuseIdentifier, for: indexPath)
        cell.accessoryType = .disclosureIndicator
        cell.textLabel?.font = UIFont.systemFont(ofSize: 18)
        
        if indexPath.section == 0 {
            cell.textLabel?.text = "Open Slyce"
            return cell
        }
        
        switch (indexPath.row) {
        case 0:
            cell.textLabel?.text = "Visual Search"
        case 1:
            cell.textLabel?.text = "Barcode Search"
        case 2:
            cell.textLabel?.text = "Image Match"
        default:
            cell.textLabel?.text = nil
        }
        
        return cell
    }
    
    override func tableView(_ tableView: UITableView, didSelectRowAt indexPath: IndexPath)
    {
        if indexPath.section == 0 {
            openSlyce()
        } else {
            openSlyceExample(indexPath.row)
        }
    }
    
    override var supportedInterfaceOrientations: UIInterfaceOrientationMask
    {
        return .portrait
    }
}

class TableViewCell: UITableViewCell
{
    static let reuseIdentifier = "TableViewCellIdentifier"
}
