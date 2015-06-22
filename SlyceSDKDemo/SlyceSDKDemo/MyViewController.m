//
//  MyViewController.m
//  SlyceSDKDemo
//
//  Created by Nathan Gurfinkel on 2/10/15.
//  Copyright (c) 2015 Slyce. All rights reserved.
//

#import "MyViewController.h"
#import "MyCameraViewController.h"
#import "MyProductsViewController.h"
#import "MBProgressHUD.h"
#import <SlyceSDK/SlyceSDK.h>

#define kClientID @"ClientID"

@interface MyViewController () <SFCameraViewControllerDelegate, SFRequestDelegate, UITextFieldDelegate, UIAlertViewDelegate>

@property (nonatomic, copy) NSArray *products;
@property (nonatomic, strong) MBProgressHUD *hud;
@property (weak, nonatomic) IBOutlet UITextField *clientIDTextField;
@property (copy, nonatomic) NSString *clientID;
@property (weak, nonatomic) IBOutlet UILabel *premiumLabel;
@property (weak, nonatomic) IBOutlet UILabel *versionLabel;
@property (weak, nonatomic) IBOutlet UILabel *results2DLabel;
@property (weak, nonatomic) IBOutlet UILabel *results2DAdditionalLabel;

@property (nonatomic, strong) SFSlyce *slyce;
@property (nonatomic, strong) SFCameraViewController *cameraVC;

@end

@implementation MyViewController

@synthesize clientID = _clientID;

#pragma mark -
#pragma mark Accessors

- (void)setClientID:(NSString *)clientID
{
    _clientID = clientID;
    _clientIDTextField.text = clientID;
    [[NSUserDefaults standardUserDefaults] setObject:clientID forKey:kClientID];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (NSString *)clientID
{
    return self.clientIDTextField.text;
}

#pragma mark -
#pragma mark UITextFieldDelegate

- (BOOL)textFieldShouldReturn:(UITextField *)textField
{
    [self acceptButtonClicked:nil];
    
    return YES;
}

#pragma mark -
#pragma mark Segues

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    if ([segue.identifier isEqualToString:@"MyCameraViewControllerSegue"])
    {
        MyCameraViewController *myCameraVC = segue.destinationViewController;
        myCameraVC.slyce = sender;
    }
    else if ([segue.identifier isEqualToString:@"ProductsSegue"])
    {
        MyProductsViewController *productsVC = segue.destinationViewController;
        productsVC.products = _products;
    }
}

#pragma mark -
#pragma mark SFRequestDelegate

- (void)sfRequest:(SFRequest *)sfRequest didFailWithError:(NSError *)error
{
    NSLog(@"Error = %@", [error localizedDescription]);
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
    NSLog(@"Recognized 2D Products: data = %@", imageInfo);
    self.results2DLabel.text = [imageInfo description];
}

- (void)sfRequest:(SFRequest *)sfRequest didReceiveImageInfo:(NSArray *)products
{
    NSLog(@"2D additional info = %@", products);
    self.products = [products copy];
    [self.hud hide:YES];
    [self performSegueWithIdentifier:@"ProductsSegue" sender:nil];
}

- (void)sfRequest:(SFRequest *)sfRequest didReceiveResults:(NSDictionary *)results
{
    NSArray *products = [results objectForKey:@"products"];
    NSLog(@"Recognized 3D Products = %@", products);
    [self.hud hide:YES];
    
    if (products && products.count > 0)
    {
        self.products = [products copy];
        [self performSegueWithIdentifier:@"ProductsSegue" sender:nil];
    }
    else
    {
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Sorry..." message:@"No products found." delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
    }
}

- (void)sfRequest:(SFRequest *)sfRequest didFinishWithItemDescription:(NSDictionary *)itemDescription
{
    NSLog(@"Recognized 3D Item Description = %@", itemDescription);
    [self.hud hide:YES];
}

- (void)sfRequest:(SFRequest *)sfRequest didFinishWithMerchantIDs:(NSArray *)merchantIDs
{
    NSLog(@"Supported Merchant IDs = %@", merchantIDs);
    [self.hud hide:YES];
}

- (void)sfRequest:(SFRequest *)sfRequest didProgressToStage:(SFRequestStage)stage
{
    switch (stage)
    {
        case SFRequestStageSendingImage:
            NSLog(@"Current search stage = 'Sending Image'");
            break;
        case SFRequestStageAnalyzingImage:
            NSLog(@"Current search stage = 'Analyzing Image'");
            break;
        default:
            break;
    }
}

- (void)sfRequest:(SFRequest *)sfRequest didProgressToValue:(CGFloat)value withMessage:(NSString *)message
{
    NSLog(@"Finished %.2f percents, current step = %@", value, message);
    self.hud.labelText = message;
}

#pragma mark -
#pragma mark SFCameraViewControllerDelegate

- (void)sfCameraViewControllerWasDismissed:(SFCameraViewController *)cameraViewController
{
    NSLog(@"SFCameraViewController finished dismissing.");
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didProgressToValue:(CGFloat)value withMessage:(NSString *)message
{
    NSLog(@"Finished %.2f percents, current step = %@", value, message);
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didFailWithError:(NSError *)error
{
    NSString *message = error.domain == SlyceErrorDomain ? [error sf_message] : [error localizedDescription];
    NSLog(@"Error = %@", message);
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didDetectImage:(NSDictionary *)imageInfo
{
    NSLog(@"Recognized 2D Products: data = %@", imageInfo);
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didReceiveImageInfo:(NSArray *)products
{
    NSLog(@"Recognized 2D Products = %@", products);
    self.products = products;
    
    if (products && products.count > 0)
        [self performSegueWithIdentifier:@"ProductsSegue" sender:nil];
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didReceiveResults:(NSDictionary *)results
{
    NSArray *products = [results objectForKey:@"products"];
    NSLog(@"Recognized 3D Products = %@", products);
    self.products = products;
    
    if (products && products.count > 0)
        [self performSegueWithIdentifier:@"ProductsSegue" sender:nil];
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didDetectBarcode:(SFBarcode *)barcode
{
    NSLog(@"Recognized Barcode Text = %@", barcode.text);
    
    dispatch_async(dispatch_get_main_queue(), ^{
        UIAlertView *alert = [[UIAlertView alloc] initWithTitle:barcode.typeString message:barcode.text delegate:self cancelButtonTitle:@"OK" otherButtonTitles:nil];
        [alert show];
    });
}

#pragma mark
#pragma mark - UIAlertViewDelegate

- (void)alertView:(UIAlertView *)alertView didDismissWithButtonIndex:(NSInteger)buttonIndex
{
    if (_cameraVC)
        [_cameraVC.cameraView resumeCapture];
}

#pragma mark -
#pragma mark IBActions

- (IBAction)acceptButtonClicked:(id)sender
{
    [_clientIDTextField resignFirstResponder];
    
    NSString *clientID = [_clientIDTextField.text stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
    self.clientID = clientID;
    
    self.hud.labelText = @"Verifying...";
    self.hud.mode = MBProgressHUDModeIndeterminate;
    [self.hud show:YES];
    
    self.slyce = [SFSlyce sharedInstance];
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        NSError *error = nil;
        BOOL success = [_slyce openWithClientID:self.clientID error:&error];
        if (!success)
        {
            dispatch_async(dispatch_get_main_queue(), ^{
                [self.hud hide:YES];
                self.premiumLabel.text = [error sf_message];
            });
        }
        else
        {
            dispatch_async(dispatch_get_main_queue(), ^{
                [self.hud hide:YES];
                NSString *isPremium = _slyce.isPremiumUser ? @"YES" : @"NO";
                NSString *is2DEnabled = _slyce.is2DSearchEnabled ? @"YES" : @"NO";
                self.premiumLabel.text = [NSString stringWithFormat:@"Premium = %@, 2D Enabled = %@", isPremium, is2DEnabled];
            });
        }
    });
}

//Headless mode
- (IBAction)recognizeImage:(UIButton *)sender
{
    if (!_clientID || [_clientID isEqualToString:@""])
    {
        [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter a client ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
        
        return;
    }
    else if (_slyce.isPremiumUser == NO)
    {
        [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Unauthorized client ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
        
        return;
    }
    
    UIImage *img = [UIImage imageNamed:@"shoe.jpg"];
    UIImageView *imageView = [[UIImageView alloc] initWithImage:img];
    imageView.contentMode = UIViewContentModeScaleAspectFit;
    
    self.hud.labelText = @"Sending image";
    self.hud.customView = imageView;
    self.hud.animationType = MBProgressHUDAnimationFade;
    self.hud.mode = MBProgressHUDModeCustomView;
    [self.hud show:YES];
    
    if (_slyce.isPremiumUser)
    {
        //2D and 3D
        SFRequest *request = [[SFRequest alloc] initWithSlyce:self.slyce options:nil andDelegate:self];
        [request recognizeSimilarProductsFromImage:img];
    }
    else
    {
        //3D
        SFRequest *request = [[SFRequest alloc] initWithSlyce:self.slyce options:nil andDelegate:self];
        [request getProductsFromImage:img fromMerchantIDs:nil];
    }
    
    
//    SFRequest *request = [[SFRequest alloc] initWithSlyce:self.slyce options:nil andDelegate:self];
//    [request getProductsFromImage:img fromMerchantIDs:nil];
}

//Camera/Headless mode
- (IBAction)openCustomCameraViewController:(UIButton *)sender
{
    if (!_clientID || [_clientID isEqualToString:@""])
    {
        [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter a client ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
        
        return;
    }
    else if (_slyce.isPremiumUser == NO)
    {
        [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Unauthorized client ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
        
        return;
    }
    
    [self performSegueWithIdentifier:@"MyCameraViewControllerSegue" sender:_slyce];
}

//Full UI
- (IBAction)openSlyceCameraViewController:(UIButton *)sender
{
    if (!_clientID || [_clientID isEqualToString:@""])
    {
        [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter a client ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
        
        return;
    }
    else if (_slyce.isPremiumUser == NO)
    {
        [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Unauthorized client ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
        
        return;
    }

    self.cameraVC = [[SFCameraViewController alloc] initWithSlyce:_slyce resourcesBundle:nil options:nil andDelegate:self];
    [_cameraVC presentFromViewController:self usingAnimation:SFAnimationTypeZoom];
    
    [self.hud hide:YES];
}

#pragma mark -
#pragma mark View Lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.hud = [[MBProgressHUD alloc] initWithView:self.view];
    self.hud.dimBackground = YES;
    self.hud.animationType = MBProgressHUDAnimationFade;
    [self.view addSubview:self.hud];
    
    self.versionLabel.text = [NSString stringWithFormat:@"v%@", [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]];
    self.clientIDTextField.text = [[NSUserDefaults standardUserDefaults] objectForKey:kClientID];
    _clientID = self.clientIDTextField.text;
    
    if (_clientID && ! [_clientIDTextField.text isEqualToString:@""])
        [self acceptButtonClicked:nil];
}

@end
