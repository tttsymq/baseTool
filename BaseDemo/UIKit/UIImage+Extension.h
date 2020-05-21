//
//  UIImage+Extension.h
//  BaseDemo
//
//  Created by wch on 2020/5/21.
//  Copyright © 2020 hai7. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (Extension)

#pragma mark - Create image

/** 获取gif*/
+ (nullable UIImage *)imageWithSmallGIFData:(NSData *)data scale:(CGFloat)scale;

/** 是否可gif*/
+ (BOOL)isAnimatedGIFData:(NSData *)data;

/** 是否可gif*/
+ (BOOL)isAnimatedGIFFile:(NSString *)path;

/** PDF*/
+ (nullable UIImage *)imageWithPDF:(id)dataOrPath;

/** PDF*/
+ (nullable UIImage *)imageWithPDF:(id)dataOrPath size:(CGSize)size;

/** 表情图片*/
+ (nullable UIImage *)imageWithEmoji:(NSString *)emoji size:(CGFloat)size;

/** 颜色生成图片*/
+ (nullable UIImage *)imageWithColor:(UIColor *)color;

/** 根据颜色生成图片*/
+ (nullable UIImage *)imageWithColor:(UIColor *)color size:(CGSize)size;

/** 自定义绘制*/
+ (nullable UIImage *)imageWithSize:(CGSize)size drawBlock:(void (^)(CGContextRef context))drawBlock;

#pragma mark - Image Info

/** 是否有alpha通道*/
- (BOOL)hasAlphaChannel;


#pragma mark - Modify Image

/** 裁剪图片*/
- (void)drawInRect:(CGRect)rect withContentMode:(UIViewContentMode)contentMode clipsToBounds:(BOOL)clips;

/** 重置大小*/
- (nullable UIImage *)imageByResizeToSize:(CGSize)size;

/** 重置大小，设置UIViewContentMode*/
- (nullable UIImage *)imageByResizeToSize:(CGSize)size contentMode:(UIViewContentMode)contentMode;

/** 裁剪后的图片*/
- (nullable UIImage *)imageByCropToRect:(CGRect)rect;

/** 设置内边距*/
- (nullable UIImage *)imageByInsetEdge:(UIEdgeInsets)insets withColor:(nullable UIColor *)color;

/** 设置圆角*/
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius;
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                                   borderWidth:(CGFloat)borderWidth
                                   borderColor:(nullable UIColor *)borderColor;
- (nullable UIImage *)imageByRoundCornerRadius:(CGFloat)radius
                                       corners:(UIRectCorner)corners
                                   borderWidth:(CGFloat)borderWidth
                                   borderColor:(nullable UIColor *)borderColor
                                borderLineJoin:(CGLineJoin)borderLineJoin;

/** 旋转*/
- (nullable UIImage *)imageByRotate:(CGFloat)radians fitSize:(BOOL)fitSize;
- (nullable UIImage *)imageByRotateLeft90;
- (nullable UIImage *)imageByRotateRight90;
- (nullable UIImage *)imageByRotate180;

- (nullable UIImage *)imageByFlipVertical;
- (nullable UIImage *)imageByFlipHorizontal;


#pragma mark - Image Effect
///=============================================================================
/// @name Image Effect
///=============================================================================

/**
 Tint the image in alpha channel with the given color.
 
 @param color  The color.
 */
- (nullable UIImage *)imageByTintColor:(UIColor *)color;

/**
 Returns a grayscaled image.
 */
- (nullable UIImage *)imageByGrayscale;

/**
 Applies a blur effect to this image. Suitable for blur any content.
 */
- (nullable UIImage *)imageByBlurSoft;

/**
 Applies a blur effect to this image. Suitable for blur any content except pure white.
 (same as iOS Control Panel)
 */
- (nullable UIImage *)imageByBlurLight;

/**
 Applies a blur effect to this image. Suitable for displaying black text.
 (same as iOS Navigation Bar White)
 */
- (nullable UIImage *)imageByBlurExtraLight;

/**
 Applies a blur effect to this image. Suitable for displaying white text.
 (same as iOS Notification Center)
 */
- (nullable UIImage *)imageByBlurDark;

/**
 Applies a blur and tint color to this image.
 
 @param tintColor  The tint color.
 */
- (nullable UIImage *)imageByBlurWithTint:(UIColor *)tintColor;

/**
 Applies a blur, tint color, and saturation adjustment to this image,
 optionally within the area specified by @a maskImage.
 
 @param blurRadius     The radius of the blur in points, 0 means no blur effect.
 
 @param tintColor      An optional UIColor object that is uniformly blended with
                       the result of the blur and saturation operations. The
                       alpha channel of this color determines how strong the
                       tint is. nil means no tint.
 
 @param tintBlendMode  The @a tintColor blend mode. Default is kCGBlendModeNormal (0).
 
 @param saturation     A value of 1.0 produces no change in the resulting image.
                       Values less than 1.0 will desaturation the resulting image
                       while values greater than 1.0 will have the opposite effect.
                       0 means gray scale.
 
 @param maskImage      If specified, @a inputImage is only modified in the area(s)
                       defined by this mask.  This must be an image mask or it
                       must meet the requirements of the mask parameter of
                       CGContextClipToMask.
 
 @return               image with effect, or nil if an error occurs (e.g. no
                       enough memory).
 */
- (nullable UIImage *)imageByBlurRadius:(CGFloat)blurRadius
                              tintColor:(nullable UIColor *)tintColor
                               tintMode:(CGBlendMode)tintBlendMode
                             saturation:(CGFloat)saturation
                              maskImage:(nullable UIImage *)maskImage;

@end

NS_ASSUME_NONNULL_END
