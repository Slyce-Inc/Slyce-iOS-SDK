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
#import "CustomHistoryViewController.h"



#define kClientID @"ClientID"
#define kAppID @"AppID"
#define kAppKey @"AppKey"
#define kClientMode @"ClientMode"

typedef NS_ENUM(NSUInteger, ClientMode)
{
    ClientModePremium,
    ClientModePublic
};

@interface MyViewController () <SFCameraViewControllerDelegate, SFRequestDelegate, UITextFieldDelegate, UIAlertViewDelegate, NSStreamDelegate, NSURLConnectionDataDelegate>

@property (nonatomic, copy) NSArray *products;
@property (nonatomic, strong) MBProgressHUD *hud;
@property (weak, nonatomic) IBOutlet UITextField *clientIDTextField;
@property (weak, nonatomic) IBOutlet UITextField *appIDTextField;
@property (weak, nonatomic) IBOutlet UITextField *appKeyTextField;

@property (copy, nonatomic) NSString *clientID;
@property (copy, nonatomic) NSString *appID;
@property (copy, nonatomic) NSString *appKey;
@property (weak, nonatomic) IBOutlet UILabel *premiumLabel;
@property (weak, nonatomic) IBOutlet UILabel *publicLabel;
@property (weak, nonatomic) IBOutlet UILabel *versionLabel;
@property (weak, nonatomic) IBOutlet UILabel *results2DLabel;
@property (weak, nonatomic) IBOutlet UILabel *results2DAdditionalLabel;
@property (weak, nonatomic) IBOutlet UIView *premiumView;
@property (weak, nonatomic) IBOutlet UIView *publicView;
@property (weak, nonatomic) IBOutlet UIButton *premiumPublicButton;

@property (nonatomic, strong) SFSlyce *slyce;
@property (nonatomic, strong) SFCameraViewController *cameraVC;

@property (nonatomic) ClientMode clientMode;

@end

@implementation MyViewController

#pragma mark -
#pragma mark Accessors

- (void)setClientMode:(ClientMode)clientMode
{
    _clientMode = clientMode;
    
    if (clientMode == ClientModePremium)
    {
        [_premiumPublicButton setTitle:@"PUBLIC" forState:UIControlStateNormal];
        
        [UIView animateWithDuration:0.2 animations:^{
           
            _premiumView.alpha = 1;
            _publicView.alpha = 0;
        }];
        
        self.clientID = [[NSUserDefaults standardUserDefaults] objectForKey:kClientID];
        
        if (self.clientID && ! [self.clientID isEqualToString:@""])
            [self acceptButtonClicked:nil];
        
        [[NSUserDefaults standardUserDefaults] setObject:@"premium" forKey:kClientMode];
        [[NSUserDefaults standardUserDefaults] synchronize];
    }
    else if (clientMode == ClientModePublic)
    {
        [_premiumPublicButton setTitle:@"PREMIUM" forState:UIControlStateNormal];
        
        [UIView animateWithDuration:0.2 animations:^{
            
            _premiumView.alpha = 0;
            _publicView.alpha = 1;
        }];
        
        self.appID = [[NSUserDefaults standardUserDefaults] objectForKey:kAppID];
        self.appKey = [[NSUserDefaults standardUserDefaults] objectForKey:kAppKey];
        
        if (self.appID && ! [self.appID isEqualToString:@""] && self.appKey && ! [self.appKey isEqualToString:@""])
            [self acceptButtonClicked:nil];
        
        [[NSUserDefaults standardUserDefaults] setObject:@"public" forKey:kClientMode];
        [[NSUserDefaults standardUserDefaults] synchronize];
    }
}

- (void)setClientID:(NSString *)clientID
{
    _clientIDTextField.text = clientID;
    [[NSUserDefaults standardUserDefaults] setObject:clientID forKey:kClientID];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (NSString *)clientID
{
    return _clientIDTextField.text;
}

- (void)setAppID:(NSString *)appID
{
    _appIDTextField.text = appID;
    [[NSUserDefaults standardUserDefaults] setObject:appID forKey:kAppID];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (NSString *)appID
{
    return _appIDTextField.text;
}

- (void)setAppKey:(NSString *)appKey
{
    _appKeyTextField.text = appKey;
    [[NSUserDefaults standardUserDefaults] setObject:appKey forKey:kAppKey];
    [[NSUserDefaults standardUserDefaults] synchronize];
}

- (NSString *)appKey
{
    return _appKeyTextField.text;
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
    self.results2DLabel.text = [imageInfo description];
}

- (void)sfRequest:(SFRequest *)sfRequest didReceiveImageInfo:(NSArray *)products
{
    NSLog(@"sfRequest:didReceiveImageInfo:%@", products);
    self.products = [products copy];
    [self.hud hide:YES];
    [self performSegueWithIdentifier:@"ProductsSegue" sender:nil];
}

- (void)sfRequest:(SFRequest *)sfRequest didReceiveResults:(NSDictionary *)results
{
    NSArray *products = [results objectForKey:@"products"];
    NSLog(@"sfRequest:didReceiveResults:%@", products);
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
    NSLog(@"sfRequest:didFinishWithItemDescription:%@", itemDescription);
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

#pragma mark -
#pragma mark SFCameraViewControllerDelegate

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didFinishWithStatus:(SFStatusType)statusType
{
    NSLog(@"sfCameraViewController:didFinishWithStatus:%lu", (unsigned long)statusType);
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didStartRequest:(SFRequest *)request forImage:(UIImage *)image
{
    NSLog(@"sfCameraViewController:didStartRequest:forImage:");
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didSnapImage:(UIImage *)image
{
    
    
    NSLog(@"sfCameraViewController:didSnapImage:");
}

- (void)sfCameraViewControllerWasDismissed:(SFCameraViewController *)cameraViewController
{
    NSLog(@"sfCameraViewControllerWasDismissed:");
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didProgressToValue:(CGFloat)value withMessage:(NSString *)message
{
    NSLog(@"sfCameraViewController:didProgressToValue:%.2f withMessage:%@", value, message);
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didFailWithError:(NSError *)error
{
    NSString *message = error.domain == SlyceErrorDomain ? [error sf_message] : [error localizedDescription];
    NSLog(@"sfCameraViewController:didFailWithError:%@", message);
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didDetectImage:(NSDictionary *)imageInfo
{
    NSLog(@"sfCameraViewController:didDetectImage:%@", imageInfo);
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didReceiveImageInfo:(NSArray *)products
{
    NSLog(@"sfCameraViewController:didReceiveImageInfo:%@", products);
    self.products = products;
    
    if (products && products.count > 0)
        [self performSegueWithIdentifier:@"ProductsSegue" sender:nil];
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didReceiveResults:(NSDictionary *)results
{
    NSArray *products = [results objectForKey:@"products"];
    NSLog(@"sfCameraViewController:didReceiveResults:%@", products);
    self.products = products;
    
    if (products && products.count > 0)
        [self performSegueWithIdentifier:@"ProductsSegue" sender:nil];
}

- (void)sfCameraViewController:(SFCameraViewController *)cameraViewController didDetectBarcode:(SFBarcode *)barcode
{
    NSLog(@"sfCameraViewController:didDetectBarcode:%@", barcode.text);
    
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

- (IBAction)togglePremiumPublic:(UIButton *)sender
{
    if (_clientMode == ClientModePremium)
        self.clientMode = ClientModePublic;
    else if (_clientMode == ClientModePublic)
        self.clientMode = ClientModePremium;
}

- (IBAction)acceptButtonClicked:(id)sender
{
    [_clientIDTextField resignFirstResponder];
    [_appIDTextField resignFirstResponder];
    [_appKeyTextField resignFirstResponder];
    
    if (_clientMode == ClientModePremium)
    {
        NSString *clientID = [_clientIDTextField.text stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.clientID = clientID;
    }
    else if (_clientMode == ClientModePublic)
    {
        NSString *appID = [_appIDTextField.text stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.appID = appID;
        NSString *appKey = [_appKeyTextField.text stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceAndNewlineCharacterSet]];
        self.appKey = appKey;
    }
    
    self.hud.labelText = @"Verifying...";
    self.hud.mode = MBProgressHUDModeIndeterminate;
    [self.hud show:YES];
    
    self.slyce = [SFSlyce sharedInstance];;
    
    dispatch_async(dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_DEFAULT, 0), ^{
        
        NSError *error = nil;
        if (_clientMode == ClientModePremium)
        {
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
        }
        else if (_clientMode == ClientModePublic)
        {
            BOOL success = [_slyce openWithAppId:self.appID appKey:self.appKey error:&error];
            if (!success)
            {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self.hud hide:YES];
                    self.publicLabel.text = [error sf_message];
                });
            }
            else
            {
                dispatch_async(dispatch_get_main_queue(), ^{
                    [self.hud hide:YES];
                    self.publicLabel.text = @"Success";
                });
            }
        }
        
    });
}

//Headless mode
- (IBAction)recognizeImage:(UIButton *)sender
{
    if (_clientMode == ClientModePremium)
    {
        if (!self.clientID || [self.clientID isEqualToString:@""])
        {
            [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter a client ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
            
            return;
        }
    }
    
    else if (_clientMode == ClientModePublic)
    {
        if (!self.appID || [self.appID isEqualToString:@""])
        {
            [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter an app ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
            
            return;
        }
        
        if (!self.appKey || [self.appKey isEqualToString:@""])
        {
            [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter an app Key" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
            
            return;
        }
    }
    
    UIImage *img = [UIImage imageNamed:@"shoe.jpg"];
    UIImageView *imageView = [[UIImageView alloc] initWithImage:img];
    imageView.contentMode = UIViewContentModeScaleAspectFit;
    
    self.hud.labelText = @"Sending image";
    self.hud.customView = imageView;
    self.hud.animationType = MBProgressHUDAnimationFade;
    self.hud.mode = MBProgressHUDModeCustomView;
    [self.hud show:YES];
    
    
        
    SFRequest *request = [[SFRequest alloc] initWithSlyce:self.slyce options:nil andDelegate:self];
    [request getProductsFromImage:img merchantIDs:nil];
  
}

//Camera/Headless mode
- (IBAction)openCustomCameraViewController:(UIButton *)sender
{
    if (_clientMode == ClientModePremium)
    {
        if (!self.clientID || [self.clientID isEqualToString:@""])
        {
            [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter a client ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
            
            return;
        }
    }
    
    else if (_clientMode == ClientModePublic)
    {
        if (!self.appID || [self.appID isEqualToString:@""])
        {
            [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter an app ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
            
            return;
        }
        
        if (!self.appKey || [self.appKey isEqualToString:@""])
        {
            [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter an app Key" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
            
            return;
        }
    }
   
    
    [self performSegueWithIdentifier:@"MyCameraViewControllerSegue" sender:_slyce];
}

//Full UI
- (IBAction)openSlyceCameraViewController:(UIButton *)sender
{
    if (_clientMode == ClientModePremium)
    {
        if (!self.clientID || [self.clientID isEqualToString:@""])
        {
            [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter a client ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
            
            return;
        }
    }
    
    else if (_clientMode == ClientModePublic)
    {
        if (!self.appID || [self.appID isEqualToString:@""])
        {
            [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter an app ID" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
            
            return;
        }
        
        if (!self.appKey || [self.appKey isEqualToString:@""])
        {
            [[[UIAlertView alloc] initWithTitle:@"Error" message:@"Please enter an app Key" delegate:nil cancelButtonTitle:@"OK" otherButtonTitles:nil] show];
            
            return;
        }
    }
  
    
    // _slyce.customProgressColor = [UIColor redColor]; //Uncomment this line if you wish to set your own custom progress color.
    
    self.cameraVC = [[SFCameraViewController alloc] initWithSlyce:_slyce resourcesBundle:[NSBundle mainBundle] options:nil andDelegate:self];
       
    // _cameraVC.cameraView.shouldUseContinuousRecognition = NO; //Uncomment this line if you don't wish to get notified automatically about recognized barcodes/2D items (Premium) (default is YES)
    
    // _cameraVC.cameraView.shouldUseContinuousRecognition2D = NO; //Uncomment this line if you don't wish to get notified automatically about recognized 2D items (Premium) (default is YES)
    
    // _cameraVC.cameraView.shouldUseContinuousRecognitionBarcodes = NO; //Uncomment this line if you don't wish to get notified automatically about recognized Barcodes items (default is YES)
    
    // _cameraVC.cameraView.shouldPauseScannerAfterRecognition = NO; //Uncomment this line if you don't wish the auto scanner to pause after a successful detection (default is YES), default resume capture delay time is '3 sec'.
    
    // _cameraVC.cameraView.shouldPauseScannerDelayTime = 4; //Uncomment this line if you don't wish the auto scanner to pause after a successful detection with your custom delay time.
    
    
    /*
    // Use this method to add your own custom button with a custom viewController to the SFCameraViewController.
     
    UIStoryboard* storyboard = [UIStoryboard storyboardWithName:@"Main" bundle:nil];
    CustomHistoryViewController *historyView = [storyboard instantiateViewControllerWithIdentifier:@"CustomHistoryViewController"];
    [self.cameraVC addCustomBtnWithVC:historyView postionInPercentX:15 postionInPercentY:4 btnImage:[UIImage imageNamed:@"historyBtn"] popUpAnimation:NO];
    
     
    // Used to override the default 'help' viewController with your custom viewController.
     
    [self.cameraVC setCustomHelpViewController:historyView];
     
     
    // Used to override the default 'not found' viewController with your custom viewController.
     
    [self.cameraVC setCustomNotFoundViewController:historyView];
     */
    
    
    
    [_cameraVC presentFromViewController:self usingAnimation:SFAnimationTypeZoom completionBlock:^{
        NSLog(@"SFCameraViewController was presented");
    }];
    
    [self.hud hide:YES];
}

#pragma mark -
#pragma mark View Lifecycle

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    if ([[NSUserDefaults standardUserDefaults] objectForKey:kClientMode])
    {
        NSString *mode = [[NSUserDefaults standardUserDefaults] objectForKey:kClientMode];
        if ([mode isEqualToString:@"premium"])
            self.clientMode = ClientModePremium;
        else if ([mode isEqualToString:@"public"])
            self.clientMode = ClientModePublic;
    }
    else
        self.clientMode = ClientModePremium;
    
    self.hud = [[MBProgressHUD alloc] initWithView:self.view];
    self.hud.dimBackground = YES;
    self.hud.animationType = MBProgressHUDAnimationFade;
    [self.view addSubview:self.hud];
    
    self.versionLabel.text = [NSString stringWithFormat:@"v%@", [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleShortVersionString"]];
    
}

@end
