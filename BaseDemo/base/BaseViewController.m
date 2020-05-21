//
//  BaseViewController.m
//  BaseDemo
//
//  Created by wch on 2020/5/21.
//  Copyright © 2020 hai7. All rights reserved.
//

#import "BaseViewController.h"

@interface BaseViewController ()

@end

@implementation BaseViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (void)initConfig
{
 #if __IPHONE_OS_VERSION_MAX_ALLOWED >= __IPHONE_11_0
    UIScrollView.appearance.contentInsetAdjustmentBehavior = UIScrollViewContentInsetAdjustmentNever;
#else
    self.automaticallyAdjustsScrollViewInsets = NO;
#endif
}

-(id)initWithHidesBottomBarWhenPushed:(BOOL)Hides
{
    self = [super init];
    if (self)
    {
        self.hidesBottomBarWhenPushed = Hides;
    }
    return self;
}

-(id)init
{
    self = [super init];
    if (self)
    {
        self.hidesBottomBarWhenPushed = YES;
    }
    return self;
}

@end
