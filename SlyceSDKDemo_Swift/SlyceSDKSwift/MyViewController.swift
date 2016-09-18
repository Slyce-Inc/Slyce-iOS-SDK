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
    var products = NSArray()
    var hub = MBProgressHUD()
    var cameraVC = SFCameraViewController()

    @IBOutlet weak var versionLabel: UILabel!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        hub = MBProgressHUD.init(view: self.view)
        hub.dimBackground = true
        hub.animationType = MBProgressHUDAnimationFade
        self.view.addSubview(hub)

        if let text = NSBundle.mainBundle().infoDictionary?["CFBundleShortVersionString"] as? String
        {
            versionLabel.text = NSString(format: "v%@",text) as String
        }
        
        // Do any additional setup after loading the view, typically from a nib.
    }
    
    override func viewDidAppear(animated: Bool) {
     
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
       
    @IBAction func headlessModeBtnPressed(sender: AnyObject)
    {
        
        let image: UIImage = UIImage(named: "shoe.jpg")!
        let bgImage = UIImageView(image: image)
        bgImage.contentMode = .ScaleAspectFit
        self.view.addSubview(bgImage)
        
        hub.labelText = "Sending image"
        hub.customView = bgImage
        hub.animationType = MBProgressHUDAnimationFade
        hub.mode = MBProgressHUDModeCustomView
        hub.show(true)
        
        
        let request = SFRequest.init(slyce: slyce, options: nil, andDelegate: self)
        request.getResultsFromImage(image)
    }
    
    
    @IBAction func fullUIModeBtnPressed(sender: AnyObject)
    {
        self.cameraVC = SFCameraViewController.init(slyce: slyce, resourcesBundle: NSBundle.mainBundle(), options: nil, andDelegate: self)
        
        self.cameraVC.presentFromViewController(self, usingAnimation: SFAnimationType.Zoom)
        {
            print("SFCameraViewController was presented")
        }
    }

    
    
    // MARK: - SFRequestDelegate
    
    func sfRequest(sfRequest: SFRequest!, didStartForImage image: UIImage!)
    {
        print("didStartForImage")
    }
    
    func sfRequest(sfRequest: SFRequest!, didStartForImageURL imageURL: NSURL!)
    {
        print("didStartForImageURL")
    }

    func sfRequest(sfRequest: SFRequest!, didFinishWithStatus statusType: SFStatusType)
    {
        print(NSString(format: "didFinishWithStatus: %@", String(SFStatusType)));
    }
    
    func sfRequest(sfRequest: SFRequest!, didReceiveResults results: [NSObject : AnyObject]!)
    {
        print(NSString(format: "didReceiveResults:results %@",results));
        
        hub.hide(true)

        let resultsDic = results as NSDictionary
        
        let productsFromResults = resultsDic.objectForKey("products") as! NSArray
        
        self.products = productsFromResults
        
        self.performSegueWithIdentifier("ProductsSegue", sender: nil)
    }
    
    func sfRequest(sfRequest: SFRequest!, didFailWithError error: NSError!)
    {
        
        let message = error.domain == SlyceErrorDomain ? error.sf_message() : error.localizedDescription
        print(NSString(format: "didFailWithError:errorMessage %@",message));
        
        let alertController = UIAlertController(title: "Error", message:
            message, preferredStyle: UIAlertControllerStyle.Alert)
        
        alertController.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.Default,handler:nil))
        
        self.presentViewController(alertController, animated: true, completion: nil)
        
        hub.hide(true)
        print("didFailWithError")
    }
    
    func sfRequest(sfRequest: SFRequest!, didProgressToValue value: CGFloat, withMessage message: String!)
    {
        print(NSString(format: "didProgressToValue %f withMessage %@",value,message));
        hub.labelText = message
    }
    
    func sfRequest(sfRequest: SFRequest!, didDetectImage imageInfo: [NSObject : AnyObject]!)
    {
        print(NSString(format: "didDetectImage:imageInfo %@",imageInfo));
    }
    
    func sfRequest(sfRequest: SFRequest!, didReceiveImageInfo products: [AnyObject]!)
    {
        print(NSString(format: "didReceiveImageInfo:products %@",products));
        
        self.products = products
        
        self.performSegueWithIdentifier("ProductsSegue", sender: nil)
        
        hub.hide(true)

    }
    
    func sfRequest(sfRequest: SFRequest!, didReceiveResultsExt results: String)
    {
        print(NSString(format: "didReceiveResultsExt:results %@",results));
    }

    func sfRequest(sfRequest: SFRequest!, didProgressToStage stage: SFRequestStage)
    {
        switch stage
        {
        case SFRequestStage.SendingImage:
            print("sfRequest:didProgressToStage:'Sending Image'")
            break
        case SFRequestStage.AnalyzingImage:
            print("sfRequest:didProgressToStage:'Analyzing Image'")
            break
        }
    }

    func sfRequest(sfRequest: SFRequest!, didProgressExt progress: String)
    {
        print(NSString(format: "didProgressExt:progress %@",progress));
    }
    
    
    // MARK: - SFCameraViewControllerDelegate
    
    func sfCameraViewController(cameraViewController: SFCameraViewController!, didStartRequest request: SFRequest!, forImage image: UIImage!)
    {
        print("sfCameraViewController: didStartRequest")
    }
  
    func sfCameraViewController(cameraViewController: SFCameraViewController!, didSnapImage image: UIImage!)
    {
        print("sfCameraViewController:didSnapImage:")
    }
    
    func sfCameraViewControllerWasDismissed(cameraViewController: SFCameraViewController!)
    {
        print("sfCameraViewControllerWasDismissed:")
    }
   
    func sfCameraViewController(cameraViewController: SFCameraViewController!, didProgressToValue value: CGFloat, withMessage message: String!)
    {
        print(NSString(format: "sfCameraViewController:didProgressToValue:%.2f withMessage:%@",value, message))
    }
    
    func sfCameraViewController(cameraViewController: SFCameraViewController!, didProgressExt progress: String!)
    {
        print(NSString(format: "sfCameraViewController:didProgressExt: %@",progress));
    }
    
    func sfCameraViewController(cameraViewController: SFCameraViewController!, didFailWithError error: NSError!)
    {
        let message = error.domain == SlyceErrorDomain ? error.sf_message() : error.localizedDescription
        print(NSString(format: "didFailWithError:errorMessage %@",message));
        
        let alertController = UIAlertController(title: "Error", message:
            message, preferredStyle: UIAlertControllerStyle.Alert)
        
        alertController.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.Default,handler:nil))
        
        self.presentViewController(alertController, animated: true, completion: nil)
    }
    
    func sfCameraViewController(cameraViewController: SFCameraViewController!, didDetectImage imageInfo: [NSObject : AnyObject]!)
    {
        print(NSString(format: "sfCameraViewController:didDetectImage: %@",imageInfo));

    }
    
    func sfCameraViewController(cameraViewController: SFCameraViewController!, didReceiveImageInfo products: [AnyObject]!)
    {
        
        print(NSString(format: "sfCameraViewController:didReceiveImageInfo: %@",products));

        hub.hide(true)
        
        if products.count > 0
        {
            self.products = products
            
            self.performSegueWithIdentifier("ProductsSegue", sender: nil)
        }
    }
    
    func sfCameraViewController(cameraViewController: SFCameraViewController!, didReceiveResults results: [NSObject : AnyObject]!)
    {
        print(NSString(format: "sfCameraViewController:didReceiveResults: %@",results));
        
        hub.hide(true)
        
        let resultsDic = results as NSDictionary
        
        let productsFromResults = resultsDic.objectForKey("products") as! NSArray
        
        self.products = productsFromResults
        
        self.performSegueWithIdentifier("ProductsSegue", sender: nil)
    }
    
    func sfCameraViewController(cameraViewController: SFCameraViewController!, didReceiveResultsExt results: String!)
    {
        print(NSString(format: "sfCameraViewController:didReceiveResultsExt: %@",results));

    }
    
    func sfCameraViewController(cameraViewController: SFCameraViewController!, didDetectBarcode barcode: SFBarcode!)
    {
        print(NSString(format: "sfCameraViewController:didDetectBarcode: %@",barcode.text));
        
        dispatch_async(dispatch_get_main_queue(),
                       {
                        
                        let alertController = UIAlertController(title: barcode.typeString, message:
                            barcode.text, preferredStyle: UIAlertControllerStyle.Alert)
                        
                        alertController.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.Default,handler:nil))
                        
                        self.presentViewController(alertController, animated: true, completion: nil)
        })
    }
    
    func sfCameraViewController(cameraViewController: SFCameraViewController!, didReceiveBarcodeInfo productURL: NSURL!)
    {
        print(NSString(format: "sfCameraViewController:didReceiveBarcodeInfo: %@",productURL));
    }
    
    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
        
        if segue.identifier == "ProductsSegue" {
            
            let productsVC  = segue.destinationViewController as! MyProductsViewController
            productsVC.products = self.products
            
        }
        
    }

    
    
}

