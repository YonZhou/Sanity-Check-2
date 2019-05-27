//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTToolManager.h"
#import "PTUserBookmark.h"

#import <PDFNet/PDFNet.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTBookmarkViewController;

/**
 * The methods declared by the `PTBookmarkViewControllerDelegate` protocol allow the adopting delegate to respond to messages from
 * the `PTBookmarkViewController` class.
 *
 */
@protocol PTBookmarkViewControllerDelegate <NSObject>
@optional

/**
 * Tells the delegate that a bookmark in the list was selected.
 *
 * @param bookmarkViewController The `PTBookmarkViewController` object informing the delegate about the bookmark's selection.
 *
 * @param bookmark A bookmark object.
 */
- (void)bookmarkViewController:(PTBookmarkViewController *)bookmarkViewController selectedBookmark:(PTUserBookmark *)bookmark;

/**
 * Tells the delegate that the bookmark control wants to be closed.
 *
 */
- (void)bookmarkViewControllerDidCancel:(PTBookmarkViewController *)bookmarkViewController;

@end

/**
 * The PTBookmarkViewController displays a list of user-created bookmarks in a document being viewed by a PTPDFViewCtrl
 * See the sample project Complete Reader for example usage.
 *
 */
@interface PTBookmarkViewController : UITableViewController

/**
 * An object that conforms to the `PTBookmarkViewControllerDelegate` protocol.
 *
 */
@property (nonatomic, weak, nullable) id<PTBookmarkViewControllerDelegate> delegate;

/**
 * Returns a new instance of a `PTBookmarkViewController`.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Returns a new instance of a `PTBookmarkViewController`.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * User bookmarks
 */
@property (nonatomic, strong) NSMutableArray<PTUserBookmark *> *bookmarks;

/**
 * Whether the text of newly created bookmarks is immediately editable. The default value is `NO`.
 */
@property (nonatomic, assign) BOOL bookmarksEditableOnCreation;


-(instancetype)initWithStyle:(UITableViewStyle)style NS_UNAVAILABLE;


-(instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


-(instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
