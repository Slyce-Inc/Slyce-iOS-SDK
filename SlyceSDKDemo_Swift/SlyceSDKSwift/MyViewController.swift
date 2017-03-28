//
//  MyViewController.swift
//  SlyceSDKSwift
//
//  Created by HADI MRIH on 02/03/2016.
//  Copyright © 2016 Slyce inc. All rights reserved.
//

import UIKit

class MyViewController: UIViewController,SFRequestDelegate,SFCameraViewControllerDelegate {

    
    let slyce: SFSlyce = SFSlyce.sharedInstance() as! SFSlyce
    var products = [AnyObject]()
    var hub = MBProgressHUD()
    var cameraVC = SFCameraViewController()

    @IBOutlet weak var versionLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        hub = MBProgressHUD.init(view: self.view)
        hub.dimBackground = true
        hub.animationType = MBProgressHUDAnimationFade
        self.view.addSubview(hub)

        if let text = Bundle.main.infoDictionary?["CFBundleShortVersionString"] as? String
        {
            versionLabel.text = NSString(format: "v%@",text) as String
        }
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func viewDidAppear(_ animated: Bool) {
     
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
       
    @IBAction func headlessModeBtnPressed(_ sender: AnyObject)
    {
        
        let image: UIImage = UIImage(named: "shoe.jpg")!
        let bgImage = UIImageView(image: image)
        bgImage.contentMode = .scaleAspectFit
        self.view.addSubview(bgImage)
        
        hub.labelText = "Sending image"
        hub.customView = bgImage
        hub.animationType = MBProgressHUDAnimationFade
        hub.mode = MBProgressHUDModeCustomView
        hub.show(true)
        
        
        let request = SFRequest.init(slyce: slyce, options: nil, andDelegate: self)
        request?.getResultsFrom(image)
    }
    
    
    @IBAction func fullUIModeBtnPressed(_ sender: AnyObject)
    {
        self.cameraVC = SFCameraViewController.init(slyce: slyce, resourcesBundle: Bundle.main, options: nil, andDelegate: self)
        
        self.cameraVC.present(from: self, using: SFAnimationType.zoom)
        {
            print("SFCameraViewController was presented")
        }
    }

    
    
    // MARK: - SFRequestDelegate
    
    func sfRequest(_ sfRequest: SFRequest!, didStartFor image: UIImage!)
    {
        print("didStartForImage")
    }
    
    func sfRequest(_ sfRequest: SFRequest!, didStartForImageURL imageURL: URL!)
    {
        print("didStartForImageURL")
    }

    func sfRequest(_ sfRequest: SFRequest!, didFinishWith statusType: SFStatusType)
    {
        print(NSString(format: "didFinishWithStatus: %@", String(describing: SFStatusType.self)));
    }
    
    func sfRequest(_ sfRequest: SFRequest!, didReceiveResults results: [AnyHashable: Any]!)
    {
        print(NSString(format: "didReceiveResults:results %@",results));
        
        hub.hide(true)

        let resultsDic = results as NSDictionary
        
        let productsFromResults = resultsDic.object(forKey: "products") as! [AnyObject]
        
        self.products = productsFromResults
        
        self.performSegue(withIdentifier: "ProductsSegue", sender: nil)
    }
    
    func sfRequest(_ sfRequest: SFRequest!, didFailWithError error: NSError!)
    {
        
        let message = error.domain == SlyceErrorDomain ? error.sf_message() : error.localizedDescription
        print(NSString(format: "didFailWithError:errorMessage %@",message!));
        
        let alertController = UIAlertController(title: "Error", message:
            message, preferredStyle: UIAlertControllerStyle.alert)
        
        alertController.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default,handler:nil))
        
        self.present(alertController, animated: true, completion: nil)
        
        hub.hide(true)
        print("didFailWithError")
    }
    
    func sfRequest(_ sfRequest: SFRequest!, didProgressToValue value: CGFloat, withMessage message: String!)
    {
        print(NSString(format: "didProgressToValue %f withMessage %@",value,message));
        hub.labelText = message
    }
    
    func sfRequest(_ sfRequest: SFRequest!, didDetectImage imageInfo: [AnyHashable: Any]!)
    {
        print(NSString(format: "didDetectImage:imageInfo %@",imageInfo));
    }
    
    func sfRequest(_ sfRequest: SFRequest!, didReceiveImageInfo products: [AnyObject]!)
    {
        print(NSString(format: "didReceiveImageInfo:products %@",products));
        
        self.products = products
        
        self.performSegue(withIdentifier: "ProductsSegue", sender: nil)
        
        hub.hide(true)

    }
    
    func sfRequest(_ sfRequest: SFRequest!, didReceiveResultsExt results: String)
    {
        print(NSString(format: "didReceiveResultsExt:results %@",results));
    }

    func sfRequest(_ sfRequest: SFRequest!, didProgressTo stage: SFRequestStage)
    {
        switch stage
        {
        case SFRequestStage.sendingImage:
            print("sfRequest:didProgressToStage:'Sending Image'")
            break
        case SFRequestStage.analyzingImage:
            print("sfRequest:didProgressToStage:'Analyzing Image'")
            break
        }
    }

    func sfRequest(_ sfRequest: SFRequest!, didProgressExt progress: String)
    {
        print(NSString(format: "didProgressExt:progress %@",progress));
    }
    
    
    // MARK: - SFCameraViewControllerDelegate
    
    func sfCameraViewController(_ cameraViewController: SFCameraViewController!, didStart request: SFRequest!, for image: UIImage!)
    {
        print("sfCameraViewController: didStartRequest")
    }
  
    func sfCameraViewController(_ cameraViewController: SFCameraViewController!, didSnapImage image: UIImage!)
    {
        print("sfCameraViewController:didSnapImage:")
    }
    
    func sfCameraViewControllerWasDismissed(_ cameraViewController: SFCameraViewController!)
    {
        print("sfCameraViewControllerWasDismissed:")
    }
   
    func sfCameraViewController(_ cameraViewController: SFCameraViewController!, didProgressToValue value: CGFloat, withMessage message: String!)
    {
        print(NSString(format: "sfCameraViewController:didProgressToValue:%.2f withMessage:%@",value, message))
    }
    
    func sfCameraViewController(_ cameraViewController: SFCameraViewController!, didProgressExt progress: String!)
    {
        print(NSString(format: "sfCameraViewController:didProgressExt: %@",progress));
    }
    
    func sfCameraViewController(_ cameraViewController: SFCameraViewController!, didFailWithError error: NSError!)
    {
        let message = error.domain == SlyceErrorDomain ? error.sf_message() : error.localizedDescription
        print(NSString(format: "didFailWithError:errorMessage %@",message!));
        
        let alertController = UIAlertController(title: "Error", message:
            message, preferredStyle: UIAlertControllerStyle.alert)
        
        alertController.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default,handler:nil))
        
        self.present(alertController, animated: true, completion: nil)
    }
    
    func sfCameraViewController(_ cameraViewController: SFCameraViewController!, didDetectImage imageInfo: [AnyHashable: Any]!)
    {
        print(NSString(format: "sfCameraViewController:didDetectImage: %@",imageInfo));

    }
    
    func sfCameraViewController(_ cameraViewController: SFCameraViewController!, didReceiveImageInfo products: [AnyObject]!)
    {
        
        print(NSString(format: "sfCameraViewController:didReceiveImageInfo: %@",products));

        hub.hide(true)
        
        if products.count > 0
        {
            self.products = products
            
            self.performSegue(withIdentifier: "ProductsSegue", sender: nil)
        }
    }
    
    func sfCameraViewController(_ cameraViewController: SFCameraViewController!, didReceiveResults results: [AnyHashable: Any]!)
    {
        print(NSString(format: "sfCameraViewController:didReceiveResults: %@",results));
        
        hub.hide(true)
        
        let resultsDic = results as NSDictionary
        
        if let productsFromResults = resultsDic.object(forKey: "products") as? [AnyObject] {
            self.products = productsFromResults

            self.performSegue(withIdentifier: "ProductsSegue", sender: nil)
        }
    }
    
    func sfCameraViewController(_ cameraViewController: SFCameraViewController!, didReceiveResultsExt results: String!)
    {
        print(NSString(format: "sfCameraViewController:didReceiveResultsExt: %@",results));

    }
    
    func sfCameraViewController(_ cameraViewController: SFCameraViewController!, didDetect barcode: SFBarcode!)
    {
        print(NSString(format: "sfCameraViewController:didDetectBarcode: %@",barcode.text));
        
        DispatchQueue.main.async(execute: {
                        
                        let alertController = UIAlertController(title: barcode.typeString, message:
                            barcode.text, preferredStyle: UIAlertControllerStyle.alert)
                        
                        alertController.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default,handler:nil))
                        
                        self.present(alertController, animated: true, completion: nil)
        })
    }
    
    func sfCameraViewController(_ cameraViewController: SFCameraViewController!, didReceiveBarcodeInfo productURL: URL!)
    {
        print(NSString(format: "sfCameraViewController:didReceiveBarcodeInfo: %@", productURL.absoluteString));
    }
    
    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
        
        if segue.identifier == "ProductsSegue" {
            
            let productsVC  = segue.destination as! MyProductsViewController
            productsVC.products = self.products
            
        }
        
    }

    
    
}

