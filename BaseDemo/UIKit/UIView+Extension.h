//
//  UIView+Extension.h
//  BaseDemo
//
//  Created by wch on 2020/5/21.
//  Copyright © 2020 hai7. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// <#Description#>
@interface UIView (Extension)

/** view转image*/
- (nullable UIImage *)snapshotImage;

/** view转image*/
- (nullable UIImage *)snapshotImageAfterScreenUpdates:(BOOL)afterUpdates;

/** PDF*/
- (nullable NSData *)snapshotPDF;

/// 设置view
/// @param color color
/// @param offset offset
/// @param radius radius
- (void)setLayerShadow:(nullable UIColor*)color offset:(CGSize)offset radius:(CGFloat)radius;

/** 移除所有子视图*/
- (void)removeAllSubviews;

/** 获取当前视图所在的viewController*/
@property (nullable, nonatomic, readonly) UIViewController *viewController;

/** alpha*/
@property (nonatomic, readonly) CGFloat visibleAlpha;

/** 相对坐标*/
- (CGPoint)convertPoint:(CGPoint)point toViewOrWindow:(nullable UIView *)view;
- (CGPoint)convertPoint:(CGPoint)point fromViewOrWindow:(nullable UIView *)view;
- (CGRect)convertRect:(CGRect)rect toViewOrWindow:(nullable UIView *)view;
- (CGRect)convertRect:(CGRect)rect fromViewOrWindow:(nullable UIView *)view;


@property (nonatomic) CGFloat left;        ///< Shortcut for frame.origin.x.
@property (nonatomic) CGFloat top;         ///< Shortcut for frame.origin.y
@property (nonatomic) CGFloat right;       ///< Shortcut for frame.origin.x + frame.size.width
@property (nonatomic) CGFloat bottom;      ///< Shortcut for frame.origin.y + frame.size.height
@property (nonatomic) CGFloat width;       ///< Shortcut for frame.size.width.
@property (nonatomic) CGFloat height;      ///< Shortcut for frame.size.height.
@property (nonatomic) CGFloat centerX;     ///< Shortcut for center.x
@property (nonatomic) CGFloat centerY;     ///< Shortcut for center.y
@property (nonatomic) CGPoint origin;      ///< Shortcut for frame.origin.
@property (nonatomic) CGSize  size;        ///< Shortcut for frame.size.

@end

NS_ASSUME_NONNULL_END
