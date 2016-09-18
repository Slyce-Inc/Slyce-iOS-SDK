//
//  MyProductsViewController.swift
//  SlyceSDKSwift
//
//  Created by HADI MRIH on 17/08/2016.
//  Copyright © 2016 Slyce inc. All rights reserved.
//

import UIKit

class MyProductsViewController: UIViewController {

    var products = NSArray()
    
    @IBOutlet weak var resultsCollectionView: UICollectionView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        // Do any additional setup after loading the view.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
   
    
    //2
    func collectionView(collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return  products.count
    }
    
    //3
    func collectionView(collectionView: UICollectionView, cellForItemAtIndexPath indexPath: NSIndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCellWithReuseIdentifier("MyProductCollectionViewCell", forIndexPath: indexPath) as! MyProductCollectionViewCell

        
        let productDic = products.objectAtIndex(indexPath.row) as! NSDictionary
        
        cell.productPriceLabel.text = productDic.objectForKey("productPrice") as? String
        cell.productDescriptionLabel.text = productDic.objectForKey("productName") as? String
        cell.productBrandLabel.text = productDic.objectForKey("brandName") as? String

        
        var imgURL = NSURL()
        
        let urlString = productDic["productImageURL"] as? String
        
        if urlString!.rangeOfString("?") != nil && urlString!.rangeOfString("[") != nil
        {
            let arr = urlString!.characters.split("?").map(String.init) as NSArray
            print(arr)
            
            if arr.count > 1
            {
                let address = arr.objectAtIndex(0) as! String
                var params1 = arr.objectAtIndex(1) as! String

                params1 = self.escapeStr(params1 )
                
                let urlString1 = NSString(format: "%@?%@",address,params1)
                
                imgURL = NSURL(string: urlString1 as String)!
            }
        }else
        {
            imgURL = NSURL(string: urlString! as String)!
        }
        
        
        // The image isn't cached, download the img data
        // We should perform this in a background thread
        let request: NSURLRequest = NSURLRequest(URL: imgURL)
        let mainQueue = NSOperationQueue.mainQueue()
        NSURLConnection.sendAsynchronousRequest(request, queue: mainQueue, completionHandler: { (response, data, error) -> Void in
            if error == nil {
                // Convert the downloaded data in to a UIImage object
                let image = UIImage(data: data!)
                // Store the image in to our cache
                // Update the cell
                dispatch_async(dispatch_get_main_queue(), {
                   cell.productImageView.image = image
                })
            }
            else {
                print("Error: \(error!.localizedDescription)")
            }
        })
 
        
        // Configure the cell
        return cell
    }
    
    func escapeStr(stringToChange: String) -> (String) {

        let str = CFURLCreateStringByAddingPercentEscapes(kCFAllocatorDefault,stringToChange,"[].",":/?&=;+!@#$()',*",CFStringConvertNSStringEncodingToEncoding(NSUTF8StringEncoding))
        return str as (String)
    }
    
    
    func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAtIndexPath indexPath: NSIndexPath) -> CGSize
    {
        return CGSizeMake(self.view.frame.size.width/2, 200)
    }

    func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumLineSpacingForSectionAtIndex section: Int) -> CGFloat {
        
        
        return 0
    }
    
    func collectionView(collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumInteritemSpacingForSectionAtIndex section: Int) -> CGFloat {
        
        
        
        return 0
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepareForSegue(segue: UIStoryboardSegue, sender: AnyObject?) {
        // Get the new view controller using segue.destinationViewController.
        // Pass the selected object to the new view controller.
    }
    */
}
