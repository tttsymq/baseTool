//
//  NSRegularExpression+Extension.h
//  Binding
//
//  Created by admin on 2020/5/13.
//  Copyright © 2020 hai7. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSRegularExpression (Extension)


/// 判断是否匹配
/// @param regex 正则表达式
/// @param checkString 字符串
+ (BOOL)isMatchRegularExpression:(NSString *)regex checkString:(NSString *)checkString;



/// 根据正则匹配的字符串
/// @param regex 正则表达式
/// @param checkString 字符串
+ (NSString *)partStringOfCheckStringWithRegularExpression:(NSString *)regex checkString:(NSString *)checkString;


/// 根据正则匹配的字符串数组
/// @param regex 正则表达式
/// @param checkString 字符串
+ (NSArray<NSString *> *)arrayOfCheckStringWithRegularExpression:(NSString *)regex checkString:(NSString *)checkString;


@end

NS_ASSUME_NONNULL_END
