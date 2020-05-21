//
//  NSRegularExpression+Extension.m
//  Binding
//
//  Created by admin on 2020/5/13.
//  Copyright © 2020 hai7. All rights reserved.
//

#import "NSRegularExpression+Extension.h"

@implementation NSRegularExpression (Extension)

+ (BOOL)isMatchRegularExpression:(NSString *)regex checkString:(NSString *)checkString {
    if (!checkString) {
        return NO;
    }
    NSError *error = NULL;
    NSRegularExpression *regularExpression = [NSRegularExpression regularExpressionWithPattern:regex
                                                                                       options:NSRegularExpressionCaseInsensitive | NSRegularExpressionDotMatchesLineSeparators
                                                                                         error:&error];
    
    NSTextCheckingResult *result =
    [regularExpression firstMatchInString:checkString options:NSMatchingReportProgress range:NSMakeRange(0, [checkString length])];
    return result != nil;
}

+ (NSString *)partStringOfCheckStringWithRegularExpression:(NSString *)regex checkString:(NSString *)checkString {
    if (!checkString) {
        return nil;
    }
    NSError *error = NULL;
    NSRegularExpression *regularExpression = [NSRegularExpression regularExpressionWithPattern:regex
                                                                                       options:NSRegularExpressionCaseInsensitive | NSRegularExpressionDotMatchesLineSeparators
                                                                                         error:&error];
    NSTextCheckingResult *result =
    [regularExpression firstMatchInString:checkString options:NSMatchingReportProgress range:NSMakeRange(0, [checkString length])];
    return result ? [checkString substringWithRange:result.range] : nil;
}

+ (NSArray<NSString *> *)arrayOfCheckStringWithRegularExpression:(NSString *)regex checkString:(NSString *)checkString {
    if (!checkString) {
        return nil;
    }
    NSError *error = NULL;
    NSRegularExpression *regularExpression = [NSRegularExpression regularExpressionWithPattern:regex
                                                                                       options:NSRegularExpressionCaseInsensitive | NSRegularExpressionDotMatchesLineSeparators
                                                                                         error:&error];
    NSTextCheckingResult *result =
    [regularExpression firstMatchInString:checkString options:NSMatchingReportProgress range:NSMakeRange(0, [checkString length])];
    
    NSMutableArray *arr = [[NSMutableArray alloc] initWithCapacity:0];
    
    for (NSInteger i = 1; i < [result numberOfRanges]; i++) {
        NSString *matchString;
        
        NSRange range = [result rangeAtIndex:i];
        
        if (range.location != NSNotFound) {
            matchString = [checkString substringWithRange:[result rangeAtIndex:i]];
        } else {
            matchString = @"";
        }
        [arr addObject:matchString];
    }
    
    return [arr copy];
}


@end
