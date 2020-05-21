//
//  BYNetHelper.m
//  BYNetworking
//
//  Created by hai8 on 2017/7/19.
//  Copyright © 2017年 hai. All rights reserved.
//

#import "BYNetHelper.h"
#import "BYNetManager.h"
#import "BYNetMacro.h"

#import "BYRequestLog.h"

#import <AFNetworkReachabilityManager.h>


/*
 
 &username=admin&password=Heibao520
 */

/**********生产***************/
#define KKURL_Base  @"http://www.mtidia.com/"

/**********测试***************/
//#define KKURL_Base  @"http://test.mtidia.com/"

#define KKURL_Login   @"index.php?g=Appapi&m=Systeam&a=adminLogin" //登录
#define KKURL_Saleman @"index.php?g=Appapi&m=Systeam&a=getSalesmanInfo&keyword" //搜索业务员
#define KKURL_Blind   @"index.php?g=Appapi&m=Systeam&a=bindingUser"    //绑定
#define KKURL_M_Blind @"index.php?g=Appapi&m=Systeam&a=changeBind"     //转绑
#define KKURL_Money   @"index.php?g=Appapi&m=Systeam&a=adminRecharge" //充值
#define KKURL_Userman @"<#获取粉丝id列表#>"


@implementation BYNetHelper

/** 登录*/
+ (NSURLSessionTask *)getLoginWithParameters:(id)parameters isSuccess:(BYResponseIsSuccess)isSuccess
{
    // 将请求前缀与请求路径拼接成一个完整的URL
//    NSString *url = [NSString stringWithFormat:@"%@%@",KKAPIPrefix,kLogin];
    return [self requestWithURL:KKURL_Login parameters:parameters method:YES isSuccess:isSuccess];
}

/** 绑定*/
+ (NSURLSessionTask *)getBindWithParameters:(id)parameters isSuccess:(BYResponseIsSuccess)isSuccess
{
    return [self requestWithURL:KKURL_Blind parameters:parameters method:YES isSuccess:isSuccess];
}

/** 转绑*/
+ (NSURLSessionTask *)getBindMoveWithParameters:(id)parameters isSuccess:(BYResponseIsSuccess)isSuccess
{
    return [self requestWithURL:KKURL_M_Blind parameters:parameters method:YES isSuccess:isSuccess];
}

/** 充值*/
+ (NSURLSessionTask *)getAddMoneyWithParameters:(id)parameters isSuccess:(BYResponseIsSuccess)isSuccess
{
    return [self requestWithURL:KKURL_Money parameters:parameters method:YES isSuccess:isSuccess];;
}

/** 获取业务员列表*/
+ (NSURLSessionTask *)getSaleListWithParameters:(id)parameters isSuccess:(BYResponseIsSuccess)isSuccess
{
    return [self requestWithURL:KKURL_Saleman parameters:parameters method:YES isSuccess:isSuccess];
}

/** 获取用户列表*/
+ (NSURLSessionTask *)getUserListWithParameters:(id)parameters isSuccess:(BYResponseIsSuccess)isSuccess
{
    return [self requestWithURL:KKURL_Userman parameters:parameters method:YES isSuccess:isSuccess];
}


//+ (NSURLSessionTask *)requestMerchantWithParameters:(id)parameters isSuccess:(BYResponseIsSuccess)isSuccess
//{
//    NSString * url = [NSString stringWithFormat:@"%@%@",LinkerAddress,KKLinkerStoreList];
//
//    return [self requestWithURL:url parameters:parameters isSuccess:isSuccess];
//}


/*
 配置好BYNetManager各项请求参数,封装成一个公共方法,给以上方法调用,
 相比在项目中单个分散的使用BYNetManager/其他网络框架请求,可大大降低耦合度,方便维护
 在项目的后期, 你可以在公共请求方法内任意更换其他的网络请求工具,切换成本小
 */

#pragma mark - 请求的公共方法

/**
 请求的公用方法
 */
+ (NSURLSessionTask *)requestWithURL:(NSString *)URL parameters:(NSDictionary *)parameter method:(BOOL)method isSuccess:(BYResponseIsSuccess)isSuccess
{
    // 在请求之前你可以统一配置你请求的相关参数 ,设置请求头, 请求参数的格式, 返回数据的格式
    // 设置请求头
    
    [BYNetManager closeLog];
    
    NSString * baseUrl = [NSString stringWithFormat:@"%@",KKURL_Base];
    
    NSString * urlString = [NSString stringWithFormat:@"%@%@",baseUrl,URL];
    
//    [BYNetManager setRequestSerializer:(BYRequestSerializerJSON)];
    NSMutableSet *contentTypes = [[NSMutableSet alloc] init];
    [contentTypes addObject:@"text/html"];
    [contentTypes addObject:@"text/plain"];
    [contentTypes addObject:@"text/ja\ascript"];
    [contentTypes addObject:@"application/json"];
    [contentTypes addObject:@"text/json"];
    
    
    [[AFNetworkReachabilityManager sharedManager] setReachabilityStatusChangeBlock:^(AFNetworkReachabilityStatus status) {
        NSLog(@"Reachability: %@", AFStringFromNetworkReachabilityStatus(status));
        //self.networkStatus = status;
    }];
    [[AFNetworkReachabilityManager sharedManager] startMonitoring];
    
    [[BYRequestLog sharedLogger] setLevel:AFLoggerLevelDebug];
    [[BYRequestLog sharedLogger] startLogging];
    
//
//    [BYNetManager setAFHTTPSessionManagerProperty:^(AFHTTPSessionManager *sessionManager) {
//        sessionManager.responseSerializer.acceptableContentTypes = contentTypes;
//        //[sessionManager.requestSerializer ]
//    }];
    
    [BYNetManager setRequestSerializer:BYRequestSerializerJSON];

//    [BYNetManager setResponseSerializer:(BYResponseSerializerHTTP)];
    
    
    NSURLSessionTask * task =[BYNetManager GET:urlString parameters:parameter success:^(id responseObject) {
    
        NSDictionary * dic = (NSDictionary *)responseObject;
        
        if (responseObject &&  [dic[@"code"] isEqualToNumber:@(1)]) {
            
            isSuccess(YES,responseObject);
        }else{
            
//            ShowMessage(responseObject[@"msg"]);
            isSuccess(NO,responseObject);
            
        }
    } failure:^(NSError *error) {
        ShowMessage(@"请求失败");
        isSuccess(NO,error.localizedDescription);
    }];
    
    
    return task;
}

@end
