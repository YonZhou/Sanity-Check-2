//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTSelectionRectView.h"
#import "PTResizeWidgetView.h"

#import <UIKit/UIKit.h>
#import <PDFNet/PDFNet.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A transparent container view for the shaded `PTSelectionRectView` and the resize widgets.
 */
@interface PTSelectionRectContainerView : UIView

/** @name Properties
 */
#pragma mark - Properties

/**
 * The shaded rectangle that is overlayed onto the selected annotation.
 */
@property (readonly, nonatomic, strong) PTSelectionRectView* selectionRectView;

/**
 * The PTPDFViewCtrl that the selection is on.
 */
@property (nonatomic, weak) PTPDFViewCtrl* pdfViewCtrl;

/** @name Resize Widget Visibility
 */
#pragma mark - Resize Widget Visibility

/**
 * When true, only displays corner resize handles. Default is `false`.
 */
@property (nonatomic, assign) BOOL displaysOnlyCornerResizeHandles;

/**
 * Hides all of the resize widgets.
 */
-(void)hideResizeWidgetViews;

/**
 * Shows all of the resize widgets.
 */
-(void)showResizeWidgetViews;

/**
 * Shows the North-East and South-West resize widgets (for lines/arrows).
 */
-(void)showNESWWidgetViews;

/**
 * Shows the North-West and South-East resize widgets (for lines/arrows).
 */
-(void)showNWSEWidgetViews;

/**
 * Used to set the view's frame to match the selected annotation's frame.
 *
 * @param frame The view's new frame.
 */
-(void)setFrameFromAnnot:(CGRect)frame;

/** @name FreeText editing
 */
#pragma mark - FreeText annotation specific

/**
 The text view used for free text annotation editing.
 */
@property (nonatomic, strong, nullable) UITextView *textView;

/**
 * Scales the text size of a free text annotation that's being edited for the current
 * zoom.
 */
-(void)setEditTextSizeForZoom:(double)zoom forFontSize:(int)size;

/**
 * Adds a UITextView to the selection rectangle for PTFreeText annotation editing.
 */
-(void)useTextViewWithText:(nullable NSString*)text withAlignment:(int)alignment atZoom:(double)zoom forFontSize:(int)size withDelegate:(id<UITextViewDelegate>)delegateView;

/**
 * Saves any changes made to a PTFreeText back to the PTPDFDoc.
 *
 * @param annot The annotation that is selected.
 */
-(void)setAnnotationContents:(PTAnnot*)annot;


/** @name Line/Arrow editing specific
 */
#pragma mark - Line/Arrow editing specific

/**
 * Shows the selection rect. For use when editing line and arrow annotations, where the selection
 * rectangle is not shown when the annotation is not being moved, and has a different appearance than
 * other annotation types.
 */
-(void)showSelectionRect;

/**
 * Hides the selection rect. For use when editing line and arrow annotations, where the selection
 * rectangle is not shown when the annotation is not being moved, and has a different appearance than
 * other annotation types.
 */
-(void)hideSelectionRect;

/**
 * Sets the annot type that is selected. Used to determine the appearance of the child `PTSelectionRectView`.
 *
 * @param annot The annotation that is selected.
 */
-(void)setAnnot:(nullable PTAnnot *)annot;

/**
 * Instantiates a new PTSelectionRectContainerView object.
 *
 * @param pdfViewCtrl The PTPDFViewCtrl instance that this view uses.
 *
 * @param annot The annotation that this view will be shown over.
 *
 * @param tool The current tool.
 */
-(instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl forAnnot:(nullable PTAnnot*)annot withTool:(PTTool*)tool NS_DESIGNATED_INITIALIZER;


-(instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


-(instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


-(instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
