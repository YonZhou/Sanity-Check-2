//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/// The location of a `PTResizeWidgetView` selection dot around the edge of a rectangle.
typedef NS_ENUM(NSInteger, PTResizeHandleLocation) {
    /// The NW resize dot
    PTResizeHandleLocationTopLeft,
    /// The top center resize dot
    PTResizeHandleLocationTop,
    /// The NE resize dot
    PTResizeHandleLocationTopRight,
    /// The righthand center resize dot
    PTResizeHandleLocationRight,
    /// The SE resize dot
    PTResizeHandleLocationBottomRight,
    /// The bottom center resize dot
    PTResizeHandleLocationBottom,
    /// The SW resize dot
    PTResizeHandleLocationBottomLeft,
    /// The lefthand centre dot
    PTResizeHandleLocationLeft,
};

/**
 * The view for the small resize handles that appear for annotation resizing with a
 * `PTSelectionRectContainerView`.
 */
@interface PTResizeWidgetView : UIView

/**
 * This widget's location.
 */
@property (nonatomic, assign) PTResizeHandleLocation location;

/**
 * The size of a resize widget.
 */
@property (nonatomic, class, readonly) int length;

/**
 * Returns a new instance of a PTResizeWidgetView.
 *
 * @param point The resize handle's position in its superview.
 * @param loc The location of the resize handle.
 */
- (instancetype)initAtPoint:(CGPoint)point WithLocation:(PTResizeHandleLocation)loc NS_DESIGNATED_INITIALIZER;


- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
