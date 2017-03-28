//
//  MyProductsViewController.swift
//  SlyceSDKSwift
//
//  Created by HADI MRIH on 17/08/2016.
//  Copyright © 2016 Slyce inc. All rights reserved.
//

import UIKit

class MyProductsViewController: UIViewController {

    var products = [AnyObject]()
    
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
    func collectionView(_ collectionView: UICollectionView, numberOfItemsInSection section: Int) -> Int {
        return  products.count
    }
    
    //3
    func collectionView(_ collectionView: UICollectionView, cellForItemAtIndexPath indexPath: IndexPath) -> UICollectionViewCell {
        
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "MyProductCollectionViewCell", for: indexPath) as! MyProductCollectionViewCell

        
        let productDic = products[indexPath.row] as! NSDictionary
        
        cell.productPriceLabel.text = productDic.object(forKey: "productPrice") as? String
        cell.productDescriptionLabel.text = productDic.object(forKey: "productName") as? String
        cell.productBrandLabel.text = productDic.object(forKey: "brandName") as? String

        
        var imgURL: URL?
        
        let urlString = productDic["productImageURL"] as? String
        
        if urlString!.range(of: "?") != nil && urlString!.range(of: "[") != nil
        {
            let arr = urlString!.characters.split(separator: "?").map(String.init) as NSArray
            print(arr)
            
            if arr.count > 1
            {
                let address = arr.object(at: 0) as! String
                var params1 = arr.object(at: 1) as! String

                params1 = self.escapeStr(params1 )
                
                let urlString1 = NSString(format: "%@?%@",address,params1)
                
                imgURL = URL(string: urlString1 as String)!
            }
        }else
        {
            imgURL = URL(string: urlString! as String)!
        }
        
        
        if let _ = imgURL {
            // The image isn't cached, download the img data
            // We should perform this in a background thread
            let request: URLRequest = URLRequest(url: imgURL!)
            let mainQueue = OperationQueue.main
            NSURLConnection.sendAsynchronousRequest(request, queue: mainQueue, completionHandler: { (response, data, error) -> Void in
                if error == nil {
                    // Convert the downloaded data in to a UIImage object
                    let image = UIImage(data: data!)
                    // Store the image in to our cache
                    // Update the cell
                    DispatchQueue.main.async(execute: {
                       cell.productImageView.image = image
                    })
                }
                else {
                    print("Error: \(error!.localizedDescription)")
                }
            })
        }
 
        
        // Configure the cell
        return cell
    }
    
    func escapeStr(_ stringToChange: String) -> (String) {
        return stringToChange.addingPercentEncoding(withAllowedCharacters: .urlHostAllowed)!
    }
    
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, sizeForItemAtIndexPath indexPath: IndexPath) -> CGSize
    {
        return CGSize(width: self.view.frame.size.width/2, height: 200)
    }

    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumLineSpacingForSectionAtIndex section: Int) -> CGFloat {
        
        
        return 0
    }
    
    func collectionView(_ collectionView: UICollectionView, layout collectionViewLayout: UICollectionViewLayout, minimumInteritemSpacingForSectionAtIndex section: Int) -> CGFloat {
        
        
        
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
