//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTToolManager.h"

#import <UIKit/UIKit.h>
#import <PDFNet/PDFNet.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Displays a grid of thumbnails that can be used for navigation, plus re-arranging and
 * deleting pages.
 */
@interface PTThumbnailsViewController : UIViewController <UICollectionViewDataSource, UICollectionViewDelegateFlowLayout>

/**
 * Initializes a new instance of the class.
 *
 * @param pdfViewCtrl The `PTPDFViewCtrl` instance that the control will coordinate with.
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl *)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Initializes a new instance of the class.
 *
 * @param toolManager The `PTToolManager` instance that the control will coordinate with.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager;

/**
 * Whether editing of thumbnails is allowed. The default is `YES`.
 */
@property (nonatomic, assign, getter=isEditingEnabled) BOOL editingEnabled;

/**
 * Associates a thumbnail image with a page number
 *
 * @param image The image of the page.
 *
 * @param pageNum The page number of the page.
 */
- (void)setThumbnail:(UIImage *)image forPage:(NSInteger)pageNum;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
