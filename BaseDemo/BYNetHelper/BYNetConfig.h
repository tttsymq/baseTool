//
//  BYNetConfig.h
//  Binding
//
//  Created by admin on 2020/5/18.
//  Copyright © 2020 hai7. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface BYNetConfig : NSObject

@property (nonatomic,   copy) NSString *baseURL;

@property (nonatomic,strong,nullable)NSDictionary <NSString *,NSString *> *commonParameter;

@property (nonatomic,copy  ,nullable)NSDictionary <NSString *,NSString *> *(^commonDynamicParameter)(void);

@property (nonatomic,strong,nullable)NSDictionary <NSString *,NSString *>*commonHeaders;

@property (nonatomic,copy,nullable)NSDictionary <NSString *,NSString *>*(^commonDynamicHeaders)(void);

+ (_Nonnull instancetype)shareInstance;
/** 添加公共请求参数 */
+ (void)addGeneralParameter:(NSString * _Nonnull)sKey value:(id _Nonnull )sValue;
/** 移除请求参数 */
+ (void)removeGeneralParameter:(NSString * _Nonnull)sKey;

@end

NS_ASSUME_NONNULL_END
