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
    var products = [AnyObject]()
    var hub = MBProgressHUD()
    @IBOutlet weak var cancelRewBtn: UIButton!
    
    override func viewDidDisappear(_ animated: Bool)
    {
        super.viewDidDisappear(animated)
        self.cameraView.pauseCapture()
    }
    
    override func viewDidLayoutSubviews()
    {
       self.cameraView.previewLayer.frame = self.view.frame
    }

    override func viewDidAppear(_ animated: Bool)
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
        
        self.view.bringSubview(toFront: cancelRewBtn)
        
     
        // Do any additional setup after loading the view.
    }
    
    
    
    @IBAction func snapBtnPressed(_ sender: AnyObject)
    {
        hub.labelText = "Sending image"

        self.cameraView.snap()
    }
    
    
    @IBAction func flipCameraPressed(_ sender: AnyObject)
    {
        cameraView.flipCameraPosition()
    }
    
    @IBAction func toggleFlashPressed(_ sender: AnyObject)
    {
        let toglleFlashBtn = sender as! UIButton
        toglleFlashBtn.isSelected = !toglleFlashBtn.isSelected
        cameraView.turnFlash(toglleFlashBtn.isSelected)
    }
    
    @IBAction func cancelReqBtnPressed(_ sender: AnyObject)
    {
        cameraView.resumeCapture()
        cameraView.currentRequest.cancel()
        hub.hide(true)
        cancelRewBtn.isHidden = true
    }
    
    // MARK: - SFCameraViewDelegate
    
    func sfCameraView(_ sfCameraView: SFCameraView!, didStartForImage image: UIImage!)
    {
        print("didStartForImage")
    }
    
    func sfCameraView(_ sfCameraView: SFCameraView!, didFinishWith statusType: SFStatusType)
    {
        print(NSString(format: "didFinishWithStatus: %@", String(describing: SFStatusType.self)));
    }
    
    func sfCameraView(_ sfCameraView: SFCameraView!, didDetect barcode: SFBarcode)
    {
        print(NSString(format: "didDetectBarcode: %@", barcode.text));
        
        cameraView.pauseCapture()

        let alertController = UIAlertController(title: barcode.typeString, message:
            barcode.text, preferredStyle: UIAlertControllerStyle.alert)
        
        alertController.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default,handler:{(alert: UIAlertAction!) in self.cameraView.resumeCapture()}))
        
        self.present(alertController, animated: true, completion: nil)
    }
    
    func sfCameraView(_ sfCameraView: SFCameraView!, didReceiveResults results: [AnyHashable: Any]!)
    {
        print(NSString(format: "didReceiveResults:results %@",results));
        
        let resultsDic = results as NSDictionary
        
        let productsFromResults = resultsDic.object(forKey: "products") as! [AnyObject]

        self.products = productsFromResults
        
        self.performSegue(withIdentifier: "ProductsSegue", sender: nil)
        hub.hide(true)
        cancelRewBtn.isHidden = true

    }
    
    func sfCameraView(_ sfRequest: SFCameraView!, didFailWithError error: NSError!)
    {
        let message = error.domain == SlyceErrorDomain ? error.sf_message() : error.localizedDescription
        print(NSString(format: "didFailWithError:errorMessage %@", message!));
        
        let alertController = UIAlertController(title: "Error", message:
            message!, preferredStyle: UIAlertControllerStyle.alert)
        
        alertController.addAction(UIAlertAction(title: "OK", style: UIAlertActionStyle.default,handler:{(alert: UIAlertAction!) in self.cameraView.resumeCapture()}))
        
        self.present(alertController, animated: true, completion: nil)
    }
    
    func sfCameraView(_ sfCameraView: SFCameraView!, didProgressToValue value: CGFloat, withMessage message: String!)
    {
        print(NSString(format: "didProgressToValue %f withMessage %@",value,message));
        
        hub.labelText = message
    }
    
    func sfCameraView(_ sfCameraView: SFCameraView!, didDetectImage imageInfo: [AnyHashable: Any]!)
    {
        print(NSString(format: "didDetectImage:imageInfo %@",imageInfo));
    }
    
    func sfCameraView(_ sfCameraView: SFCameraView!, didReceiveImageInfo products: [AnyObject]!)
    {
        print(NSString(format: "didReceiveImageInfo:products %@",products));
        self.products = products
        
        self.performSegue(withIdentifier: "ProductsSegue", sender: nil)
        hub.hide(true)
        cancelRewBtn.isHidden = true

    }
    
    func sfCameraView(_ sfCameraView: SFCameraView!, didReceiveResultsExt results: String)
    {
        print(NSString(format: "didReceiveResultsExt:results %@",results));
        hub.hide(true)
        cancelRewBtn.isHidden = true
    }
    
    func sfCameraView(_ sfCameraView: SFCameraView!, didProgressTo stage: SFRequestStage)
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
    
    func sfCameraView(_ sfCameraView: SFCameraView!, didProgressExt progress: String)
    {
        print(NSString(format: "didProgressExt:progress %@",progress));
    }

    func sfCameraView(_ sfCameraView: SFCameraView!, didSnapImage image: UIImage)
    {
        hub.show(true)
        cameraView.pauseCapture()
        cancelRewBtn.isHidden = false

        print("sfCameraView:didSnapImage:")
    }
    
    func sfCameraView(_ sfCameraView: SFCameraView!, wasTappedIn point: CGPoint)
    {
        print(NSString(format: "sfCameraView:wasTappedInPoint: %@",NSStringFromCGPoint(point)));
    }
    

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    // MARK: - Navigation

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
