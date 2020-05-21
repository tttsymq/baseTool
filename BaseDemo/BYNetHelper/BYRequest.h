//
//  BYRequest.h
//  BYNetworking
//
//  Created by hai8 on 2018/4/19.
//  Copyright © 2018年 hai. All rights reserved.
//



#import "BYRequestLog.h"

//-----------服务器判断
#define ServerModefy  1  //是否测试服务器 1：是  0 否
#if ServerModefy
//测试
#define KKKLinkBaseUrl @"http://mapi.kuailai.me/api/"
//http://mapi.mall.kuailai.me
#else
//正式
#define KKKLinkBaseUrl @"https://mapi.kuailai.me/"

#endif


/**< 注册验证码  post*/
#define KKKRegistSendCode @"login/sendsignupvcode"
/**< 发送登录验证码 post*/
#define KKKLoginSendCode @"login/sendloginvcode"
/**< 注册 get*/
#define KKKRegist @"login/register"
/**< 查询手机是否注册*/
#define KKKCheck @"login/check"
/**< 用户密码登录*/
#define KKKLoginPsw @"login/pwd"
/**< 验证码登录*/
#define KKKLoginCode @"login/vcode"






