//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>
#import <PDFNet/PDFNet.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The `PTPageIndicatorViewController` displays the current page number in a document.
 */
@interface PTPageIndicatorViewController : UIViewController

/**
 * Initializes a new `PTPageIndicatorViewController` instance.
 *
 * @param pdfViewCtrl the `PTPDFViewCtrl` instance that the control will coordinate with
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * The view that provides the background appearance. The default background view blurs the content
 * behind the page indicator. Setting a value of `nil` resets this property to the default background
 * view.
 */
@property (nonatomic, strong, null_resettable) UIView *backgroundView;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;

- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
