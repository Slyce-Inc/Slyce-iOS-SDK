//
//  MyProductCollectionViewCell.h
//  SlyceSDKDemo
//
//  Created by Nathan Gurfinkel on 2/27/15.
//  Copyright (c) 2015 BuyCode. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface MyProductCollectionViewCell : UICollectionViewCell

@property (weak, nonatomic) IBOutlet UIImageView *productImageView;
@property (weak, nonatomic) IBOutlet UILabel *productDescriptionLabel;
@property (weak, nonatomic) IBOutlet UILabel *productPriceLabel;
@property (weak, nonatomic) IBOutlet UILabel *productBrandLabel;


@end
