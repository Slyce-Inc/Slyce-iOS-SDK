//
//  CustomHistoryViewController.m
//  SlyceSDKDemo
//
//  Created by HADI MRIH on 11/01/2016.
//  Copyright © 2016 BuyCode. All rights reserved.
//

#import "CustomHistoryViewController.h"

@interface CustomHistoryViewController ()

@end

@implementation CustomHistoryViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(IBAction)backBtnPressed:(id)sender
{
    [self dismissViewControllerAnimated:YES completion:nil];
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
