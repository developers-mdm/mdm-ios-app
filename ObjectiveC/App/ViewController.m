//
//  ViewController.m

//  Copyright ©. All rights reserved.
//

#import "ViewController.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
}

- (IBAction)openInbox:(UIButton *)sender {
    NSBundle *bundle = [NSBundle bundleWithIdentifier:@"br.com.hands.mdm.libs.ios.notification"];
    UIStoryboard *storyboard = [UIStoryboard storyboardWithName:@"MDMInBox" bundle:bundle];

    UINavigationController *navigationController = [storyboard instantiateViewControllerWithIdentifier:@"MDMInboxNavigationController"];
    navigationController.modalPresentationStyle = UIModalPresentationFullScreen;
    [self presentViewController:navigationController animated:YES completion:nil];
}

@end
