//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "ToolsMacros.h"

#import <UIKit/UIKit.h>
#import <PDFNet/PDFNet.h>

#define KEY_TITLE       @"title"
#define KEY_CHILDREN    @"hasChildren"
#define KEY_PAGENUM     @"pageNumber"
#define KEY_BOOKMARK    @"_bookmark"

NS_ASSUME_NONNULL_BEGIN

@class PTOutlineViewController;

/**
 * The methods declared by the `PTOutlineViewControllerDelegate` protocol allow the adopting delegate to respond to messages from
 * the PTAnnotationViewController class.
 */
@protocol PTOutlineViewControllerDelegate <NSObject>
@optional

/**
 * Tells the delegate that an outline item was selected. Note that the PDF specification refers to outline items as "bookmarks",
 * which are _not_ user bookmarks. The `PTBookmark` and related classes refer to outline items, not user bookmarks.
 *
 * @param outlineViewController The `PTOutlineViewController` object informing the delegate about the bookmark's selection.
 *
 * @param bookmark A dictionary of bookmark information, with key-value pairs: {KEY_TITLE, NSString holding the bookmark's title},
 * {KEY_CHILDREN, NSNumber with a BOOL value indicating the presence of children at this node}, {KEY_BOOKMARK, PTBookmark that's the next bookmark}.
 */
- (void)outlineViewController:(PTOutlineViewController *)outlineViewController selectedBookmark:(NSDictionary *)bookmark;

/**
 * Tells the delegate that the outline control wants to be closed.
 */
- (void)outlineViewControllerDidCancel:(PTOutlineViewController *)outlineViewController;

@end

/**
 * The PTOutlineViewController will display a document's outline (PDF bookmakrs) that can be used to
 * navigate the document in a `PTPDFViewCtrl`. When a bookmark is selected, the controller will navigate the
 * `PTPDFViewCtrl` to that page.
 */
@interface PTOutlineViewController : UITableViewController

/**
 * Returns a new instance of an PTOutlineViewController.
 *
 * @param pdfViewCtrl The `PTPDFViewCtrl` object that provides the `PTPDFDoc` from which to create the outline,
 * and which will change pages when the user selects an annotation item.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * An object that conforms to the `PTOutlineViewControllerDelegate` protocol.
 *
 */
@property (nonatomic, weak, nullable) id<PTOutlineViewControllerDelegate> delegate;

/**
 * Refresh the contents of the PTOutlineViewController
 */
- (void)refresh;


- (instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
