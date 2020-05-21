//
//  BYNetMacro.h
//  BYNetworking
//
//  Created by hai8 on 2017/7/19.
//  Copyright © 2017年 hai. All rights reserved.
//

#ifndef BYNetMacro_h
#define BYNetMacro_h

#import "BYNetHelper.h"
#import "BYNetManager.h"


#ifdef DEBUG
#define BYLog(...) printf("[%s] %s [第%d行]: %s\n", __TIME__ ,__PRETTY_FUNCTION__ ,__LINE__, [[NSString stringWithFormat:__VA_ARGS__] UTF8String])
#else
#define BYLog(...)
#endif

#define BYNSStringFormat(format,...) [NSString stringWithFormat:format,##__VA_ARGS__]

//服务器地址
//1:生产环境  0:测试环境
#define ServerOnline 1

#if ServerOnline

#define BYBaseUrl @"http://mapi.kuailai.me/api"

#else

#define BYBaseUrl @"http://192.168.0.73:8080"

#endif



#endif /* BYNetMacro_h */
