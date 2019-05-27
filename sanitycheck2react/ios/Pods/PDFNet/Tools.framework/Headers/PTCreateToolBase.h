//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTTool.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * An abstract class that many of the annotation-creating tools derive from.
 */
@interface PTCreateToolBase : PTTool {

    
    /// backing variables for readonly properties who's subclasses need write access
    @protected
    
    int _pageNumber;
    
    double _thickness;
}

/**
 * The thickness of the annotation's stroke.
 */
@property (nonatomic, readonly, assign) double thickness;

/**
 * The pageNumber that this annotation will be created on.
 */
@property (nonatomic, readonly, assign) int pageNumber;

/**
 * The rectangle defined by the points when the user first touched and his/her finger has
 * moved to.
 */
@property (nonatomic, readonly, assign) CGRect drawArea;

/**
 * The point where the user's finger first made contact with the `PTPDFViewCtrl`.
 */
@property (nonatomic, assign) CGPoint startPoint;

/**
 * The point where the user's finger first made contact with the `PTPDFViewCtrl`.
 */
@property (nonatomic, assign) CGPoint endPoint;

/**
 * Whether this tool requires an editing interface (toolbar) to operate.
 */
@property (nonatomic, readonly, assign) BOOL requiresEditSupport;

/**
 * Sets up the drawing context with correct properties such as stroke and fill thickness
 * and color, etc.
 *
 * @param currentContext The current context, typically that returned by
 * `UIGraphicsGetCurrentContext()`.
 */
-(double)setupContext:(CGContextRef)currentContext;

/**
 * Saves new annotation default properties via `ColorDefaults`.
 *
 * @param annotation The annotation with perperties that will be used when the next
 * annotation of this type is created.
 */
-(void)setPropertiesFromAnnotation:(PTAnnot *)annotation;

/**
 * Restricts the input point to the PDFPage `pageNumber`.
 *
 * @param touchPoint An input point, in screen (PTPDFViewCtrl) coordinates.
 *
 * @param thickness A thickness value that imposes a margin around the edge of the page.
 */
-(CGPoint)boundToPageScreenPoint:(CGPoint)touchPoint withThicknessCorrection:(CGFloat)thickness;


/**
 * Restricts the input point to the PDFPage `pageNumber`.
 *
 * @param touchPoint An input point, in screen (PTPDFViewCtrl) coordinates.
 *
 * @param left A thickness value that imposes a margin at the left edge of the page.
 *
 * @param right A thickness value that imposes a margin at the right edge of the page.
 *
 * @param bottom A thickness value that imposes a margin at the bottom edge of the page.
 *
 * @param top A thickness value that imposes a margin at the left top of the page.
 */
-(CGPoint)boundToPageScreenPoint:(CGPoint)touchPoint
                         withPaddingLeft:(CGFloat)left
                                   right:(CGFloat)right
                                  bottom:(CGFloat)bottom
                                     top:(CGFloat)top;
@end

NS_ASSUME_NONNULL_END
