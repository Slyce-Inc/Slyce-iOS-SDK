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
#import <SlyceSDK/SlyceSDK.h>
#import "MBProgressHUD.h"


@interface MyProductsViewController () <UICollectionViewDataSource, UICollectionViewDelegateFlowLayout,SFRequestDelegate>


@property (weak, nonatomic) IBOutlet UICollectionView *resultsCollectionView;
@property (nonatomic, strong) MBProgressHUD *hud;

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

    NSString *imgUrlStr = [product objectForKey:@"productImageURL"];
    
    if ([imgUrlStr rangeOfString:@"?"].location != NSNotFound && [imgUrlStr rangeOfString:@"["].location != NSNotFound)
    {
        NSArray* splitStringArr = [imgUrlStr componentsSeparatedByString: @"?"];
        
        if (splitStringArr.count > 1)
        {
            NSString *address = [splitStringArr objectAtIndex:0];
            NSString *params1 = [splitStringArr objectAtIndex:1];
            
            params1 = [self escape:params1];
            
            // Build the url and loadRequest
            NSString *urlString = [NSString stringWithFormat:@"%@?%@",address,params1];
            
            
            [cell.productImageView setImageWithURL:[NSURL URLWithString:urlString] placeholderImage:nil usingActivityIndicatorStyle:UIActivityIndicatorViewStyleWhite];

        }else
        {
            [cell.productImageView setImageWithURL:[NSURL URLWithString:imgUrlStr] placeholderImage:nil usingActivityIndicatorStyle:UIActivityIndicatorViewStyleWhite];
        }
    }else
    {
        [cell.productImageView setImageWithURL:[NSURL URLWithString:imgUrlStr] placeholderImage:nil usingActivityIndicatorStyle:UIActivityIndicatorViewStyleWhite];
    }
    
    
   if ([product objectForKey:@"productPrice"] && ![[product objectForKey:@"productPrice"] isKindOfClass:[NSNull class]])
        cell.productPriceLabel.text = [NSString stringWithFormat:@"%.2f", [[product objectForKey:@"productPrice"] floatValue]];
    if ([product objectForKey:@"productName"])
        cell.productDescriptionLabel.text = [product objectForKey:@"productName"];
    if ([product objectForKey:@"brandName"])
        cell.productBrandLabel.text = [[product objectForKey:@"brandName"] uppercaseString];
    
    
    [cell.showSimilarBtn removeTarget:self action:@selector(showSimilar:) forControlEvents:UIControlEventTouchUpInside];
    [cell.showSimilarBtn addTarget:self action:@selector(showSimilar:) forControlEvents:UIControlEventTouchUpInside];
    
    return cell;
}

- (NSString *)escape:(NSString *)text
{
    return (__bridge NSString *)CFURLCreateStringByAddingPercentEscapes(NULL,
                                                                        (__bridge CFStringRef)text, NULL,
                                                                        (CFStringRef)@"!*'();:@&=+$,/?%#[]",
                                                                        kCFStringEncodingUTF8);
}

- (void)showSimilar:(UIButton *)sender
{
   
    CGPoint point = [_resultsCollectionView convertPoint:sender.center fromView:sender.superview];
    NSIndexPath *indexPath = [_resultsCollectionView indexPathForItemAtPoint:point];
   
    NSMutableDictionary *productDic = [_products objectAtIndex:indexPath.row];
    
    if ([productDic objectForKey:@"productImageURL"])
    {
        self.hud.labelText = @"Loading similars...";
        self.hud.mode = MBProgressHUDModeIndeterminate;
        [self.hud show:YES];
        
        SFRequest *request = [[SFRequest alloc] initWithSlyce:[SFSlyce sharedInstance] options:nil andDelegate:self];
        [request getSimilarFromResults:[NSURL URLWithString:[productDic objectForKey:@"productImageURL"]]];
    }
}


#pragma mark -
#pragma mark SFRequestDelegate

- (void)sfRequest:(SFRequest *)sfRequest didStartForImage:(UIImage *)image
{
    NSLog(@"sfRequest:didStartForImage:");
}

- (void)sfRequest:(SFRequest *)sfRequest didStartForImageURL:(NSURL *)imageURL
{
    NSLog(@"sfRequest:didStartForImageURL:%@", imageURL.absoluteString);
}

- (void)sfRequest:(SFRequest *)sfRequest didFinishWithStatus:(SFStatusType)statusType
{
    NSLog(@"sfRequest:didFinishWithStatus:%lu", (unsigned long)statusType);
}

- (void)sfRequest:(SFRequest *)sfRequest didFailWithError:(NSError *)error
{
    NSLog(@"sfRequest:didFailWithError:%@", [error localizedDescription]);
    if (error.code != SFErrorCredMismatch)
        [self.hud hide:YES];
    
    NSString *message;
    
    if (error.domain == SlyceErrorDomain)
        message = [error sf_message];
    else
        message = [error localizedDescription];
    
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error" message:message delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
    [alert show];
}

//Premium
- (void)sfRequest:(SFRequest *)sfRequest didDetectImage:(NSDictionary *)imageInfo
{
    NSLog(@"sfRequest:didDetectImage:%@", imageInfo);
}

- (void)sfRequest:(SFRequest *)sfRequest didReceiveImageInfo:(NSArray *)products
{
    NSLog(@"sfRequest:didReceiveImageInfo:%@", products);
    self.products = [products copy];
    [self.hud hide:YES];
    [self.resultsCollectionView reloadData];
    [_resultsCollectionView setContentOffset:CGPointZero animated:YES];


}

- (void)sfRequest:(SFRequest *)sfRequest didReceiveResults:(NSDictionary *)results
{
    
    NSArray *products = [results objectForKey:@"products"];
    NSLog(@"sfRequest:didReceiveResults:%@", products);
    [self.hud hide:YES];
    
    if (products && products.count > 0)
    {
        self.products = [products copy];
        [self.resultsCollectionView reloadData];
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Sorry..." message:@"No products found." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
    }
    
    [_resultsCollectionView setContentOffset:CGPointZero animated:YES];

}

- (void)sfRequest:(SFRequest *)sfRequest didReceiveResultsExt:(NSString *)results
{
    NSLog(@"sfRequest:didReceiveResultsExt: %@", results);
    
    [self.hud hide:YES];
}

- (void)sfRequest:(SFRequest *)sfRequest didFinishWithMerchantIDs:(NSArray *)merchantIDs
{
    NSLog(@"sfRequest:didFinishWithMerchantIDs:%@", merchantIDs);
    [self.hud hide:YES];
}

- (void)sfRequest:(SFRequest *)sfRequest didProgressToStage:(SFRequestStage)stage
{
    switch (stage)
    {
        case SFRequestStageSendingImage:
            NSLog(@"sfRequest:didProgressToStage:'Sending Image'");
            break;
        case SFRequestStageAnalyzingImage:
            NSLog(@"sfRequest:didProgressToStage:'Analyzing Image'");
            break;
        default:
            break;
    }
}

- (void)sfRequest:(SFRequest *)sfRequest didProgressToValue:(CGFloat)value withMessage:(NSString *)message
{
    NSLog(@"sfRequest:didProgressToValue:%.2f withMessage:%@", value, message);
    self.hud.labelText = message;
}

- (void)sfRequest:(SFRequest *)sfRequest didProgressExt:(NSString *)progress
{
    NSLog(@"sfRequest:didProgressExt:%@", progress);
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
    self.hud = [[MBProgressHUD alloc] initWithView:self.view];
    self.hud.dimBackground = YES;
    self.hud.animationType = MBProgressHUDAnimationFade;
    [self.view addSubview:self.hud];
    
    [super viewDidLoad];
}

@end
