//
//  BYNetHelper.h
//  BYNetworking
//
//  Created by hai8 on 2017/7/19.
//  Copyright © 2017年 hai. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef void(^BYResponseIsSuccess)(BOOL isSuccess,id data);

@interface BYNetHelper : NSObject

///** 登录*/
+ (NSURLSessionTask *)getLoginWithParameters:(id)parameters
                                   isSuccess:(BYResponseIsSuccess)isSuccess;

///** 绑定*/
+ (NSURLSessionTask *)getBindWithParameters:(id)parameters
                                  isSuccess:(BYResponseIsSuccess)isSuccess;

+ (NSURLSessionTask *)getBindMoveWithParameters:(id)parameters
                                      isSuccess:(BYResponseIsSuccess)isSuccess;

///** 业务员列表*/
+ (NSURLSessionTask *)getSaleListWithParameters:(id)parameters
                                      isSuccess:(BYResponseIsSuccess)isSuccess;

///** 用户列表*/
+ (NSURLSessionTask *)getUserListWithParameters:(id)parameters
                                      isSuccess:(BYResponseIsSuccess)isSuccess;

///** 充值*/
+ (NSURLSessionTask *)getAddMoneyWithParameters:(id)parameters
                                      isSuccess:(BYResponseIsSuccess)isSuccess;

/**
 请求的公用方法
 */
+ (NSURLSessionTask *)requestWithURL:(NSString *)URL
                          parameters:(NSDictionary *)parameter
                              method:(BOOL)method
                           isSuccess:(BYResponseIsSuccess)isSuccess;


@end
