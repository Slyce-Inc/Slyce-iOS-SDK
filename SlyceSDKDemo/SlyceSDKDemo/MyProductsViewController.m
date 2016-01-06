//
//  MyProductsViewController.m
//  SlyceSDKDemo
//
//  Created by Nathan Gurfinkel on 2/27/15.
//  Copyright (c) 2015 BuyCode. All rights reserved.
//

#import "MyProductsViewController.h"
#import "MyProductCollectionViewCell.h"
#import "UIImageView+UIActivityIndicatorForSDWebImage.h"

@interface MyProductsViewController () <UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>

@end

@implementation MyProductsViewController

#pragma mark -
#pragma mark UICollectionViewDelegateFlowLayout

- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout minimumLineSpacingForSectionAtIndex:(NSInteger)section
{
    return 0;
}

- (CGFloat)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout minimumInteritemSpacingForSectionAtIndex:(NSInteger)section
{
    return 0;
}

- (CGSize)collectionView:(UICollectionView *)collectionView layout:(UICollectionViewLayout *)collectionViewLayout sizeForItemAtIndexPath:(NSIndexPath *)indexPath
{
    return CGSizeMake(self.view.frame.size.width/2, 200);
}

#pragma mark -
#pragma mark UICollectionViewDataSource

- (NSInteger)collectionView:(UICollectionView *)collectionView numberOfItemsInSection:(NSInteger)section
{
    return _products.count;
}

- (UICollectionViewCell *)collectionView:(UICollectionView *)collectionView cellForItemAtIndexPath:(NSIndexPath *)indexPath
{
    NSString *const identifier = @"MyProductCollectionViewCell";
    
    MyProductCollectionViewCell *cell = [collectionView dequeueReusableCellWithReuseIdentifier:identifier forIndexPath:indexPath];
    
    NSDictionary *product = [_products objectAtIndex:indexPath.row];
    
    [cell.productImageView setImageWithURL:[NSURL URLWithString:[product objectForKey:@"productImageURL"]] usingActivityIndicatorStyle:UIActivityIndicatorViewStyleGray];
    if ([product objectForKey:@"productPrice"] && ![[product objectForKey:@"productPrice"] isKindOfClass:[NSNull class]])
        cell.productPriceLabel.text = [NSString stringWithFormat:@"%.2f", [[product objectForKey:@"productPrice"] floatValue]];
    if ([product objectForKey:@"productName"])
        cell.productDescriptionLabel.text = [product objectForKey:@"productName"];
    if ([product objectForKey:@"brandName"])
        cell.productBrandLabel.text = [[product objectForKey:@"brandName"] uppercaseString];
    
    return cell;
}

#pragma mark -
#pragma mark IBActions

- (IBAction)closeWindow:(id)sender
{
    [self.navigationController popViewControllerAnimated:YES];
    [self dismissViewControllerAnimated:YES completion:nil];
}

#pragma mark -
#pragma mark View Lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
}

@end
