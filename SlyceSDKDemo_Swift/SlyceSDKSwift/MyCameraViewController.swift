//
//  MyCameraViewController.swift
//  SlyceSDKSwift
//
//  Created by HADI MRIH on 17/08/2016.
//  Copyright © 2016 Slyce inc. All rights reserved.
//

import UIKit

class MyCameraViewController: UIViewController,SFCameraViewDelegate,SFRequestDelegate {

    var cameraView = SFCameraView()
    var products = NSArray()
    var hub = MBProgressHUD()
    @IBOutlet weak var cancelRewBtn: UIButton!
    
    override func viewDidDisappear(animated: Bool)
    {
        super.viewDidDisappear(animated)
        self.cameraView.pauseCapture()
    }
    
    override func viewDidLayoutSubviews()
    {
       self.cameraView.previewLayer.frame = self.view.frame
    }

    override func viewDidAppear(animated: Bool)
    {
        super.viewDidAppear(animated)
        
        self.cameraView.startCamera()
        self.cameraView.resumeCapture()
    }
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        
        hub = MBProgressHUD.init(view: self.view)
        hub.dimBackground = true
        hub.labelText = "Sending image"
        hub.animationType = MBProgressHUDAnimationZoom
        hub.mode = MBProgressHUDModeIndeterminate
        self.view.addSubview(hub)
        
        
        self.cameraView = SFCameraView.init(slyce: SFSlyce.sharedInstance() as! SFSlyce, view: self.view, options: nil, andDelegate: self)
        
        self.view.bringSubviewToFront(cancelRewBtn)
        
     
        // Do any additional setup after loading the view.
    }
    
    
    
    @IBAction func snapBtnPressed(sender: AnyObject)
    {
        hub.labelText = "Sending image"

        self.cameraView.snap()
    }
    
    
    @IBAction func flipCameraPressed(sender: AnyObject)
    {
        cameraView.flipCameraPosition()
    }
    
    @IBAction func toggleFlashPressed(sender: AnyObject)
    {
        let toglleFlashBtn = sender as! UIButton
        toglleFlashBtn.selected = !toglleFlashBtn.selected
        cameraView.turnFlash(toglleFlashBtn.selected)
    }
    
    @IBAction func cancelReqBtnPressed(sender: AnyObject)
    {
        cameraView.resumeCapture()
        cameraView.currentRequest.cancel()
        hub.hide(true)
        cancelRewBtn.hidden = true
    }
    
    // MARK: - SFCameraViewDelegate
    
    func sfCameraView(sfCameraView: SFCameraView!, didStartForImage image: UIImage!)
    {
        print("didStartForImage")
    }
    
    func sfCameraView(sfCameraView: SFCameraView!, didFinishWithStatus statusType: SFStatusType)
    {
        print(NSString(format: "didFinishWithStatus: %@", String(SFStatusType)));
    }
    
    func sfCameraView(sfCameraView: SFCameraView!, didDetectBarcode barcode: SFBarcode)
    {
        print(NSString(format: "didDetectBarcode: %@", barcode.text));
        
        cameraView.pauseCapture()

        let alertController = UIAlertController(title: barcode.typeString, message:
            barcode.text, preferredStyle: UIAlertControllerStyle.Alert)
        
        alertController.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.Default,handler:{(alert: UIAlertAction!) in self.cameraView.resumeCapture()}))
        
        self.presentViewController(alertController, animated: true, completion: nil)
    }
    
    func sfCameraView(sfCameraView: SFCameraView!, didReceiveResults results: [NSObject : AnyObject]!)
    {
        print(NSString(format: "didReceiveResults:results %@",results));
        
        let resultsDic = results as NSDictionary
        
        let productsFromResults = resultsDic.objectForKey("products") as! NSArray

        self.products = productsFromResults
        
        self.performSegueWithIdentifier("ProductsSegue", sender: nil)
        hub.hide(true)
        cancelRewBtn.hidden = true

    }
    
    func sfCameraView(sfRequest: SFCameraView!, didFailWithError error: NSError!)
    {
        let message = error.domain == SlyceErrorDomain ? error.sf_message() : error.localizedDescription
        print(NSString(format: "didFailWithError:errorMessage %@",message));
        
        let alertController = UIAlertController(title: "Error", message:
            message, preferredStyle: UIAlertControllerStyle.Alert)
        
        alertController.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.Default,handler:{(alert: UIAlertAction!) in self.cameraView.resumeCapture()}))
        
        self.presentViewController(alertController, animated: true, completion: nil)
    }
    
    func sfCameraView(sfCameraView: SFCameraView!, didProgressToValue value: CGFloat, withMessage message: String!)
    {
        print(NSString(format: "didProgressToValue %f withMessage %@",value,message));
        
        hub.labelText = message
    }
    
    func sfCameraView(sfCameraView: SFCameraView!, didDetectImage imageInfo: [NSObject : AnyObject]!)
    {
        print(NSString(format: "didDetectImage:imageInfo %@",imageInfo));
    }
    
    func sfCameraView(sfCameraView: SFCameraView!, didReceiveImageInfo products: [AnyObject]!)
    {
        print(NSString(format: "didReceiveImageInfo:products %@",products));
        self.products = products
        
        self.performSegueWithIdentifier("ProductsSegue", sender: nil)
        hub.hide(true)
        cancelRewBtn.hidden = true

    }
    
    func sfCameraView(sfCameraView: SFCameraView!, didReceiveResultsExt results: String)
    {
        print(NSString(format: "didReceiveResultsExt:results %@",results));
        hub.hide(true)
        cancelRewBtn.hidden = true
    }
    
    func sfCameraView(sfCameraView: SFCameraView!, didProgressToStage stage: SFRequestStage)
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
    
    func sfCameraView(sfCameraView: SFCameraView!, didProgressExt progress: String)
    {
        print(NSString(format: "didProgressExt:progress %@",progress));
    }

    func sfCameraView(sfCameraView: SFCameraView!, didSnapImage image: UIImage)
    {
        hub.show(true)
        cameraView.pauseCapture()
        cancelRewBtn.hidden = false

        print("sfCameraView:didSnapImage:")
    }
    
    func sfCameraView(sfCameraView: SFCameraView!, wasTappedInPoint point: CGPoint)
    {
        print(NSString(format: "sfCameraView:wasTappedInPoint: %@",NSStringFromCGPoint(point)));
    }
    

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: - Navigation

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
