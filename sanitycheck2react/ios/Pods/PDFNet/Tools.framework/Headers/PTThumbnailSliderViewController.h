//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>
#import <PDFNet/PDFNet.h>

NS_ASSUME_NONNULL_BEGIN

@class PTThumbnailSliderViewController;

/**
 * The methods declared by the `PTThumbnailSliderViewDelegate` protocol allow the adopting delegate to
 * respond to messages from the `ThumbnailSliderView` class.
 */
@protocol PTThumbnailSliderViewDelegate <NSObject>
@optional

/**
 * Informs the delegate when the slider is touched by the user.
 */
- (void)thumbnailSliderViewInUse:(PTThumbnailSliderViewController *)thumbnailSliderViewController;

/**
 * Informs the delegate when the slider is no longer being touched by the user.
 */
- (void)thumbnailSliderViewNotInUse:(PTThumbnailSliderViewController *)thumbnailSliderViewController;

@end

/**
 * The `PTThumbnailSliderViewController` uses PDFViewCtrl's GetThumbAsync API to show thumbnails
 * of the current page as the slider is moved. See the Complete Reader sample project for example usage.
 */
@interface PTThumbnailSliderViewController : UIViewController

/**
 * Returns a new instance of a `PTThumbnailSliderViewController`.
 *
 * @param pdfViewCtrl The `PTPDFViewCtrl` instance that the control will coordinate with.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * The toolbar item placed to the left (leading end) of the slider control.
 * When `leadingToolbarItems` is used, this is the first item in the list.
 */
@property (nonatomic, strong, nullable) UIBarButtonItem *leadingToolbarItem;

/**
 * The toolbar items placed to the left (leading end) of the slider control.
 */
@property (nonatomic, copy, nullable) NSArray<UIBarButtonItem *> *leadingToolbarItems;

/**
 * The toolbar item placed to the right (trailing end) of the slider control.
 * When `trailingToolbarItems` is used, this is the first item in the list.
 */
@property (nonatomic, strong, nullable) UIBarButtonItem *trailingToolbarItem;

/**
 * The toolbar items placed to the right (trailing end) of the slider control.
 */
@property (nonatomic, copy, nullable) NSArray<UIBarButtonItem *> *trailingToolbarItems;

/**
 * Sets the slider value programmatically.
 *
 * @param pageNumber The new page number to set the slider to.
 */
- (void)setSliderValue:(int)pageNumber;

/**
 * Used to set a thumbnail for a given page, to be called by the delegate of PTPDFViewCtrl.
 *
 * @param image The thumbnail image.
 *
 * @param pageNum The page number of the thumbnail.
 */
- (void)setThumbnail:(nullable UIImage *)image forPage:(int)pageNum;

/**
 * An object that conforms to the `PTThumbnailSliderViewDelegate` protocol.
 */
@property (nonatomic, weak, nullable) id<PTThumbnailSliderViewDelegate> delegate;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

NS_ASSUME_NONNULL_END

@end
