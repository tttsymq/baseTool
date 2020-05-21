//
//  BYNetConfig.m
//  Binding
//
//  Created by admin on 2020/5/18.
//  Copyright © 2020 hai7. All rights reserved.
//

#import "BYNetConfig.h"

@implementation BYNetConfig

+ (instancetype)shareInstance
{
    static dispatch_once_t onceToken;
    static BYNetConfig * manager = nil;
    dispatch_once(&onceToken, ^{
        manager =[[[self class] alloc] init];
    });
    
    return manager;
}

- (instancetype)init
{
    self =[super init];
    if (self) {
        
    }
    return self;
}


// MARK: 接口
/** 添加公共请求参数 */
+ (void)addGeneralParameter:(NSString *)sKey value:(id)sValue {
    BYNetConfig *manager = BYNetConfig.shareInstance;
    NSMutableDictionary *mDict = [[NSMutableDictionary alloc] init];
    mDict[sKey] = sValue;
    [mDict addEntriesFromDictionary:manager.commonParameter];
    manager.commonParameter = mDict.copy;
}

/** 移除请求参数 */
+ (void)removeGeneralParameter:(NSString *)sKey {
    BYNetConfig *manager = BYNetConfig.shareInstance;
    NSMutableDictionary *mDict = manager.commonParameter.mutableCopy;
    [mDict removeObjectForKey:sKey];
    manager.commonParameter = mDict.copy;
}

@end
