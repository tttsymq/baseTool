//
//  Header.h
//  BaseDemo
//
//  Created by wch on 2020/5/21.
//  Copyright © 2020 hai7. All rights reserved.
//

#ifndef Header_h
#define Header_h

/** ----------------打印----------------*/
#ifdef DEBUG
#define KKLog(...) NSLog(@"%s 第%d行 \n %@\n\n",__func__,__LINE__,[NSString stringWithFormat:__VA_ARGS__])
#else
#define KKLog(...)
#endif

/** ----------------设备----------------*/
// 判断是否为iPhone
#define KKIS_IPHONE (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPhone)
// 判断是否为iPad
#define KKIS_IPAD (UI_USER_INTERFACE_IDIOM() == UIUserInterfaceIdiomPad)
// 判断是否为ipod
#define KKIS_IPOD ([[[UIDevice currentDevice] model] isEqualToString:@"iPod touch"])

/** ----------------机型判断----------------*/
// 判断是否为 iPhone 4/4S - 3.5 inch
#define iPhone4_4S [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 480.0f
// 判断是否为 iPhone 5/5SE - 4.0 inch
#define iPhone5_5SE [[UIScreen mainScreen] bounds].size.width == 320.0f && [[UIScreen mainScreen] bounds].size.height == 568.0f
// 判断是否为iPhone 6/6S/7/8 - 4.7 inch
#define iPhone6_6S [[UIScreen mainScreen] bounds].size.width == 375.0f && [[UIScreen mainScreen] bounds].size.height == 667.0f
// 判断是否为iPhone 6Plus/6SPlus/7P/8P - 5.5 inch
#define iPhone6Plus_8Plus [[UIScreen mainScreen] bounds].size.width == 414.0f && [[UIScreen mainScreen] bounds].size.height == 736.0f
// 判断是否为iPhoneX - 5.8 inch
#define iPhoneX ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
// 判断是否为iPhoneXS - 5.8 inch
#define iPhoneXS ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1125, 2436), [[UIScreen mainScreen] currentMode].size) : NO)
// 判断是否为iPhoneXR - 6.1 inch
#define iPhoneXR ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(828, 1792), [[UIScreen mainScreen] currentMode].size) : NO)
// 判断是否为iPhoneXS MAX - 6.5 inch
#define iPhoneXSMax ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(1242, 2688), [[UIScreen mainScreen] currentMode].size) : NO)



// 获取系统版本
#define IOS_SYSTEM_VERSION [[[UIDevice currentDevice] systemVersion] floatValue]
// 判断 iOS 8 或更高的系统版本
#define IOS_VERSION_8_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >=8.0)? (YES):(NO))
// 判断 iOS 10 或更高的系统版本
#define IOS_VERSION_10_OR_LATER (([[[UIDevice currentDevice] systemVersion] floatValue] >=10.0)? (YES):(NO))


#define KKLiuHaiPhone \
({BOOL isLiuHaiPhone = NO;\
if (@available(iOS 11.0, *)) {\
isLiuHaiPhone = [[UIApplication sharedApplication] delegate].window.safeAreaInsets.bottom > 0.0;\
}\
(isLiuHaiPhone);})


/** ----------------颜色----------------*/
#define KKRandomColor [UIColor colorWithRed:(arc4random()%256)/255.0 green:(arc4random()%256)/255.0 blue:(arc4random()%256)/255.0 alpha:1.0]
#define KKRRGBColor(r, g, b) [UIColor colorWithRed:(r)/255.0 green:(g)/255.0 blue:(b)/255.0 alpha:1.0]
#define KKRRGBAColor(r, g, b, a) [UIColor colorWithRed:(r)/255.0 green:(r)/255.0 blue:(r)/255.0 alpha:a]
#define KKRGB_COLOR(_STR_,a) ([UIColor colorWithRed:[[NSString stringWithFormat:@"%lu", strtoul([[_STR_ substringWithRange:NSMakeRange(1, 2)] UTF8String], 0, 16)] intValue] / 255.0 green:[[NSString stringWithFormat:@"%lu", strtoul([[_STR_ substringWithRange:NSMakeRange(3, 2)] UTF8String], 0, 16)] intValue] / 255.0 blue:[[NSString stringWithFormat:@"%lu", strtoul([[_STR_ substringWithRange:NSMakeRange(5, 2)] UTF8String], 0, 16)] intValue] / 255.0 alpha:a])


/** 弹框*/
//9.1AlertView
#define  KKAlertShow(Message)   [[[UIAlertView alloc]initWithTitle:@"提示" message:Message delegate:nil cancelButtonTitle:@"确定" otherButtonTitles:nil, nil] show]

//9.2UIAlertController的宏定义
//参数中的 MESSAGE是提示内容,  PCBVC是UIViewController就是你当前操作的页面,调用时直接传递 self
#define KKAlertVShow(Message,PCBVC) \
UIAlertController *alertController = [UIAlertController alertControllerWithTitle:@"温馨提示" message:Message preferredStyle:UIAlertControllerStyleAlert]; \
UIAlertAction *okAction = [UIAlertAction actionWithTitle:@"确定" style:UIAlertActionStyleDefault handler:nil]; \
[alertController addAction:okAction]; \
[PCBVC presentViewController:alertController animated:YES completion:nil];

/** 尺寸*/
#define  KK_BoundWidth ([[UIScreen mainScreen] bounds].size.width)
#define  KK_BoundHeight ([[UIScreen mainScreen] bounds].size.height)

#define KKStatus_H    ([[UIApplication sharedApplication] statusBarFrame].size.height>20?44:20) // 适配刘海屏状态栏
#define KKTabbar_H    ([[UIApplication sharedApplication] statusBarFrame].size.height>20?83:49) // 适配刘海屏底栏高度
#define KKSafeBottom_H    ([[UIApplication sharedApplication] statusBarFrame].size.height>20?34:0)  // 适配刘海屏底部多出来的高度
#define KKNav_h    (KKStatus_H +44)

/** ----------------字符串为空判断----------------*/
//字符串空的判断
#define NumbertoStr(str) [NSString stringWithFormat:@"%@",str]
#define NULLStr(str) (str != nil)?str:@""
#define NULLStrTo0(str)  (str != nil) ? str : @"0"
#define NULLClass(str) [str isEqual:[NSNull class]]?@"":str
#define NumberTo0(str) (str != nil) ? str : @(0)

/** ----------------沙盒路径----------------*/
// 获取沙盒主目录路径
#define KKPath_Home = NSHomeDirectory();
//获取沙盒 Document
#define KKPath_Document [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) firstObject]
//获取沙盒 Library
#define KKPath_Library [NSSearchPathForDirectoriesInDomains(NSLibraryDirectory, NSUserDomainMask, YES) lastObject];
//获取沙盒 Cache
#define KKPath_Cache [NSSearchPathForDirectoriesInDomains(NSCachesDirectory, NSUserDomainMask, YES) firstObject]
//获取temp
#define KKPath_Temp NSTemporaryDirectory()

/** ----------------主线程----------------*/
#ifndef dispatch_main_async_safe
#define dispatch_main_async_safe(block)\
if (strcmp(dispatch_queue_get_label(DISPATCH_CURRENT_QUEUE_LABEL), dispatch_queue_get_label(dispatch_get_main_queue())) == 0) {\
block();\
} else {\
dispatch_async(dispatch_get_main_queue(), block);\
}
#endif




/** ----------------强弱引用----------------*/
#define WeakSelf(type)    __weak typeof(type) weak##type = type;
#define StrongSelf(type)  __strong typeof(type) type = weak##type;


#ifndef weakify
#if DEBUG
#if __has_feature(objc_arc)
#define weakify(object) autoreleasepool{} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) autoreleasepool{} __block __typeof__(object) block##_##object = object;
#endif
#else
#if __has_feature(objc_arc)
#define weakify(object) try{} @finally{} {} __weak __typeof__(object) weak##_##object = object;
#else
#define weakify(object) try{} @finally{} {} __block __typeof__(object) block##_##object = object;
#endif
#endif
#endif

#ifndef strongify
#if DEBUG
#if __has_feature(objc_arc)
#define strongify(object) autoreleasepool{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) autoreleasepool{} __typeof__(object) object = block##_##object;
#endif
#else
#if __has_feature(objc_arc)
#define strongify(object) try{} @finally{} __typeof__(object) object = weak##_##object;
#else
#define strongify(object) try{} @finally{} __typeof__(object) object = block##_##object;
#endif
#endif
#endif



#ifdef __cplusplus
#define KK_EXTERN_C_BEGIN  extern "C" {
#define KK_EXTERN_C_END  }
#else
#define KK_EXTERN_C_BEGIN
#define KK_EXTERN_C_END
#endif

KK_EXTERN_C_BEGIN

#ifndef KK_CLAMP // return the clamped value
#define KK_CLAMP(_x_, _low_, _high_)  (((_x_) > (_high_)) ? (_high_) : (((_x_) < (_low_)) ? (_low_) : (_x_)))
#endif

#ifndef KK_SWAP // swap two value
#define KK_SWAP(_a_, _b_)  do { __typeof__(_a_) _tmp_ = (_a_); (_a_) = (_b_); (_b_) = _tmp_; } while (0)
#endif


#define KKAssertNil(condition, description, ...) NSAssert(!(condition), (description), ##__VA_ARGS__)
#define KKCAssertNil(condition, description, ...) NSCAssert(!(condition), (description), ##__VA_ARGS__)

#define KKAssertNotNil(condition, description, ...) NSAssert((condition), (description), ##__VA_ARGS__)
#define KKCAssertNotNil(condition, description, ...) NSCAssert((condition), (description), ##__VA_ARGS__)

#endif /* Header_h */
