//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "ToolsMacros.h"

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The scrolling direction of a reflow view controller.
 */
typedef NS_ENUM(NSUInteger, PTReflowViewControllerScrollingDirection) {
    /// Horizontal scrolling.
    PTReflowViewControllerScrollingDirectionHorizontal,
    /// Vertical scrolling.
    PTReflowViewControllerScrollingDirectionVertical,
};

@class PTReflowViewController;

/**
 * The delegate of a reflow view controller must adopt the `PTReflowViewControllerDelegate` protocol.
 * These methods allow the delegate to receive notification when the page is changed and when the
 * reflow view controller should be dismissed.
 */
@protocol PTReflowViewControllerDelegate <NSObject>
@optional

/**
 * Called after the current page number has changed.
 */
- (void)reflowController:(PTReflowViewController *)reflowController didChangeToPageNumber:(int)pageNumber;

/**
 * Called when an unhandled tap occurs in the reflow view controller.
 */
- (void)reflowController:(PTReflowViewController *)reflowController handleTap:(UITapGestureRecognizer *)gestureRecognizer;

/**
 * Called when the reflow view controller should be dismissed. This is called only when the reflow
 * view controller is presented modally.
 */
- (void)reflowControllerDidCancel:(PTReflowViewController *)reflowController;

@end

/**
 * Displays reflowed page content from a PDF document.
 */
@interface PTReflowViewController : UIViewController

/**
 * Initializes a newly created reflow view controller that scrolls horizontally.
 *
 * @param pdfViewCtrl the PDFViewCtrl instance that the control coordinates with
 *
 * @return The initialized reflow view controller.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl;

/**
 * Initializes a newly created reflow view controller.
 *
 * @param pdfViewCtrl the PDFViewCtrl instance that the control coordinates with
 *
 * @param scrollingDirection the scrolling direction of the reflow view controller
 *
 * @return The initialized reflow view controller.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl scrollingDirection:(PTReflowViewControllerScrollingDirection)scrollingDirection NS_DESIGNATED_INITIALIZER;

/**
 * The delegate object.
 */
@property (nonatomic, weak) id<PTReflowViewControllerDelegate> delegate;

/**
 * The scrolling direction of the reflow view controller. The default value is
 * `PTReflowViewControllerScrollingDirectionHorizontal`.
 */
@property (nonatomic, assign) PTReflowViewControllerScrollingDirection scrollingDirection;

/**
 * The current page number. This is initially set to the provided `PTPDFViewCtrl`'s current page.
 */
@property (nonatomic, assign) int pageNumber;

/**
 * Sets the current page number of the reflow view controller.
 *
 * @param pageNumber the new page number
 *
 * @param animated whether to animate the change in page number
 */
- (void)setPageNumber:(int)pageNumber animated:(BOOL)animated;

/**
 * The scale factor for the reflowed text content. The default value is 1.0.
 */
@property (nonatomic, assign) CGFloat scale;

/**
 * Whether tapping on the edge of a page changes the page. The default value is `NO`.
 */
@property (nonatomic, assign) BOOL turnPageOnTap;


- (instancetype)init PT_UNAVAILABLE;

- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil PT_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder PT_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
