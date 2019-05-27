//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "ToolsMacros.h"


#import "PTCoordinatedDocument.h"
#import "PTToolManager.h"
#import "PTNavigationListsViewController.h"
#import "PTThumbnailsViewController.h"
#import "PTOverridable.h"
#import "PTAnnotationToolbar.h"
#import "PTTextSearchViewController.h"
#import "PTPageIndicatorViewController.h"
#import "PTReflowViewController.h"
#import "PTSettingsViewController.h"
#import "PTThumbnailSliderViewController.h"

#import <UIKit/UIKit.h>
#import <PDFNet/PDFNet.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The default interval used for automatic document saving.
 */
PT_EXPORT const NSTimeInterval PTDocumentViewControllerSaveDocumentInterval;

/**
 * The default time delay used for automatic control hiding.
 */
PT_EXPORT const NSTimeInterval PTDocumentViewControllerHideControlsInterval;

@class PTDocumentViewController;

/**
 * The methods declared by the `PTDocumentViewControllerDelegate` protocol allow the adopting delegate
 * to respond to messages from the `PTDocumentViewController` class.
 */
@protocol PTDocumentViewControllerDelegate <NSObject>
@optional

/**
 * The document view controller no longer has a valid document, and needs to be closed.
 */
- (void)documentViewControllerDidBecomeInvalid:(PTDocumentViewController *)documentViewController;

/**
 * The document view controller has opened a document.
 */
- (void)documentViewControllerDidOpenDocument:(PTDocumentViewController *)documentViewController;

/**
 * Called when an error occurs when opening a document.
 */
- (void)documentViewController:(PTDocumentViewController *)documentViewController didFailToOpenDocumentWithError:(NSError *)error;

/**
 * Implement to override default save location when non-PDFs and remote documents are opened via `openDocumentWithURL`.
 */
- (nullable NSURL *)documentViewController:(PTDocumentViewController *)documentViewController destinationURLForDocumentAtURL:(NSURL *)sourceUrl;

@end

/**
 * A view controller that displays a `PTPDFViewCtrl` along with other controls.
 */
@interface PTDocumentViewController : UIViewController <PTOverridable, PTPDFViewCtrlDelegate, PTToolManagerDelegate, PTCoordinatedDocumentDelegate, PTAnnotationToolbarDelegate, PTThumbnailSliderViewDelegate, PTOutlineViewControllerDelegate, PTAnnotationViewControllerDelegate, PTBookmarkViewControllerDelegate, PTReflowViewControllerDelegate, PTSettingsViewControllerDelegate, PTTextSearchViewControllerDelegate>

/**
 * Returns an initialized `PTDocumentViewController`.
 *
 * @return an initialized `PTDocumentViewController`.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Open a document with the given URL.
 *
 * @param url The URL to open.
 *
 */
- (void)openDocumentWithURL:(NSURL *)url;

/**
 * Open a document with the given URL and password.
 *
 * @param url The URL to open.
 *
 * @param password The password for the document.
 *
 */
- (void)openDocumentWithURL:(NSURL *)url password:(nullable NSString *)password;

/**
 * Open the given `PTPDFDoc`.
 *
 * @param document The `PTPDFDoc` to open.
 *
 */
- (void)openDocumentWithPDFDoc:(PTPDFDoc *)document;

/**
 * The `PTPDFDoc` if the viewer is displaying a document opened with `openDocumentWithPDFDoc:`.
 */
@property (nonatomic, readonly, strong, nullable) PTPDFDoc* document;

/**
 * The `PTCoordinatedDocument` if the viewer opens a local file with `openDocumentWithURL:`.
 */
@property (nonatomic, readonly, strong, nullable) PTCoordinatedDocument* coordinatedDocument;

/**
 * Save the current document with the specified options.
 *
 * @param saveOptions The options to save the document with.
 *
 * @param completionHandler A block with code that is executed when the save operation concludes.
 * The block returns no value, and the `success` param is `YES` if the save operation succeeds, otherwise `NO`.
 */
- (void)saveDocument:(PTSaveOptions)saveOptions completionHandler:(nullable void (^)(BOOL success))completionHandler;

/**
 * The view controller's underlying `PTPDFViewCtrl`.
 */
@property (nonatomic, readonly, strong) PTPDFViewCtrl *pdfViewCtrl;

/**
 * The tool manager attached to the underlying `PTPDFViewCtrl`.
 */
@property (nonatomic, readonly, strong) PTToolManager *toolManager;


/**
 * Whether changes in the document are saved automatically. The default value is `YES`.
 */
@property (nonatomic, assign) BOOL automaticallySavesDocument;

/**
 * The interval in seconds that the document is automatically saved. The default value is
 * `PTDocumentViewControllerSaveDocumentInterval`.
 */
@property (nonatomic, assign) NSTimeInterval automaticDocumentSavingInterval;

/**
 * Restart the automatic document saving timer with the interval specified in the
 * `automaticDocumentSavingInterval` property.
 */
- (void)restartAutomaticDocumentSavingTimer;

/**
 * Restart the automatic document saving timer with the specified interval.
 *
 * The `automaticDocumentSavingInterval1 property is updated with the specified interval.
 *
 * @param interval The interval to use for automatic document saving.
 */
- (void)restartAutomaticDocumentSavingTimerWithInterval:(NSTimeInterval)interval;

/**
 * Stop the automatic document saving timer.
 */
- (void)stopAutomaticDocumentSavingTimer;

/**
 * Closes the document after saving with the `-saveDocument:completionHandler:` method.
 *
 * @param completionHandler Called when the document has been successfully or unsuccessfully closed
 * as indicated by the success handler.
 */
- (void)closeDocumentWithCompletionHandler:(nullable void (^)(BOOL success))completionHandler;

#pragma mark - Viewer

/**
 * The document view controller's delegate object.
 */
@property (nonatomic, weak, nullable) id<PTDocumentViewControllerDelegate> delegate;

#pragma mark - Viewer Options

/**
 * Whether night mode is enabled for the `pdfViewCtrl`. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isNightModeEnabled) BOOL nightModeEnabled;

/**
 * Controls if the `ThumbnailSlider` is enabled. The default value is `YES`.
 */
@property (nonatomic, assign, getter=isBottomToolbarEnabled) BOOL bottomToolbarEnabled;

/**
 * Controls if the `PTPageIndicatorViewController` is enabled. The default value is `YES`.
 */
@property (nonatomic, assign, getter=isPageIndicatorEnabled) BOOL pageIndicatorEnabled;

/**
 * Whether the `PTPageIndicatorViewController` is shown when the current page changes. The default
 * value is `YES`.
 */
@property (nonatomic, assign) BOOL pageIndicatorShowsOnPageChange;

/**
 * Whether the `PTPageIndicatorViewController` is shown with the navigation bar and toolbars. The
 * default value is `YES`.
 */
@property (nonatomic, assign) BOOL pageIndicatorShowsWithControls;

#pragma mark - Viewer Button Visibility

/**
 * Controls the visibility of the `settingsButtonItem` in the navigation bar. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isViewerSettingsButtonHidden) BOOL viewerSettingsButtonHidden;

/**
 * Controls the visibility of the `shareButtonItem` in the navigation bar. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isShareButtonHidden) BOOL shareButtonHidden;

/**
 * Controls the visibility of the `searchButtonItem` in the navigation bar. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isSearchButtonHidden) BOOL searchButtonHidden;

/**
 * Controls the visibility of the `annotationButtonItem` in the navigation bar. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isAnnotationToolbarButtonHidden) BOOL annotationToolbarButtonHidden;

/**
 * Controls the visibility of the `thumbnailsButtonItem` on the leading side of the `PTThumbnailsViewController`. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isThumbnailBrowserButtonHidden) BOOL thumbnailBrowserButtonHidden;

/**
 * Controls the visibility of the `navigationListsButtonItem` on the trailing side of the `PTThumbnailsViewController`. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isNavigationListsButtonHidden) BOOL navigationListsButtonHidden;

#pragma mark - Navigation List ViewControllers

/**
 * Whether the `PTNavigationListsViewController` includes the default `PTAnnotationViewController`
 */
@property (nonatomic, assign, getter=isAnnotationListHidden) BOOL annotationListHidden;

/**
 * Whether the `PTNavigationListsViewController` includes the default `PTOutlineViewController`
 */
@property (nonatomic, assign, getter=isOutlineListHidden) BOOL outlineListHidden;

/**
 * Whether the `PTNavigationListsViewController` includes the default `PTBookmarkViewController`
 */
@property (nonatomic, assign, getter=isBookmarkListHidden) BOOL bookmarkListHidden;

#pragma mark - Bar button items

/**
 * Shows the `PTTextSearchViewController` toolbar for text search.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *searchButtonItem;

/**
 * Shows a `UIDocumentInteractionController` for the current document.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *shareButtonItem;

/**
 * Shows a `PTSettingsViewController` to control the view settings.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *settingsButtonItem;

/**
 * Shows a `PTThumbnailsViewController` for the current document.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *thumbnailsButtonItem;

/**
 * Shows a `PTNavigationListsViewController` with outline, annotations, and bookmarks view controllers.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *navigationListsButtonItem;

/**
 * Shows the `PTAnnotationToolbar` toolbar for annotating.
 */
@property (nonatomic, readonly, strong) UIBarButtonItem *annotationButtonItem;

#pragma mark - Controls

/**
 * The navigation lists view controller managed by this view controller.
 */
@property (nonatomic, strong) PTNavigationListsViewController *navigationListsViewController;

/**
 * Shows the `navigationListsViewController`.
 */
- (void)showNavigationLists;

/**
 * The `PTThumbnailsViewController` view controller managed by this view controller.
 */
@property (nonatomic, strong) PTThumbnailsViewController *thumbnailsViewController;

/**
 * Hides any presented view controllers and shows the `thumbnailsViewController`.
 */
- (void)showThumbnailsController;

/**
 * The `PTAnnotationToolbar` managed by this view controller.
 */
@property (nonatomic, strong) PTAnnotationToolbar *annotationToolbar;

/**
 * The `PTTextSearchViewController` managed by this view controller.
 */

@property (nonatomic, strong) PTTextSearchViewController *textSearchViewController;

/**
 * Hides any presented view controllers and shows the `textSearchViewController`.
 */
- (void)showSearchViewController;

/**
 * The `PTThumbnailSliderViewController` managed by this view controller.
 */
@property (nonatomic, strong) PTThumbnailSliderViewController *thumbnailSliderController;

/**
 * The `PTPageIndicatorViewController` managed by this view controller.
 */
@property (nonatomic, strong) PTPageIndicatorViewController *pageIndicatorViewController;

/**
 * The `PTSettingsViewController` managed by this view controller.
 */
@property (nonatomic, strong) PTSettingsViewController *settingsViewController;

/**
 * The `PTReflowViewController` managed by this view controller.
 */
@property (nonatomic, strong) PTReflowViewController *reflowViewController;

#pragma mark - Hiding user interface controls

/**
 * Whether the navigation bar, toolbars, and other controls are hidden. The default value is `NO`.
 */
@property (nonatomic, assign) BOOL controlsHidden;

/**
 * Sets whether the controls are hidden.
 *
 * For animated transitions, the duration of the animation is specified by the value in the
 * `UINavigationControllerHideShowBarDuration` constant.
 *
 * @param hidden Specify `YES` to hide the controls or `NO` to show them
 *
 * @param animated Specify `YES` if you want to animate the change in visibility or `NO` if you want the
 * controls to appear immediately.
 */
- (void)setControlsHidden:(BOOL)hidden animated:(BOOL)animated;

/**
 * Whether the annotation toolbar is hidden. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isAnnotationToolbarHidden) BOOL annotationToolbarHidden;

/**
 * Whether the find text toolbar is hidden. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isSearchViewControllerHidden) BOOL searchViewControllerHidden;

/**
 * Whether the thumbnail slider control is hidden. The default value is `NO`.
 */
@property (nonatomic, assign, getter=isThumbnailSliderHidden) BOOL thumbnailSliderHidden;

/**
 * Sets whether the thumbnail slider control is hidden.
 *
 * For animated transitions, the duration of the animation is specified by the value in the
 * `UINavigationControllerHideShowBarDuration` constant.
 *
 * @param hidden Specify `YES` to hide the thumbnail slider or `NO` to show it
 *
 * @param animated Specify `YES` if you want to animate the change in visibility or `NO` if you want the
 * control to appear immediately
 */
- (void)setThumbnailSliderHidden:(BOOL)hidden animated:(BOOL)animated;

/**
 * Whether the page indicator control is hidden. The default value is `YES`.
 */
@property (nonatomic, assign, getter=isPageIndicatorHidden) BOOL pageIndicatorHidden;

/**
 * Sets whether the page indicator control is hidden.
 *
 * @param hidden Specify `YES` to hide the page indicator or `NO` to show it.
 * @param animated Specify `YES` if you want to animate the change in visibility or `NO` if you want the
 * control to appear immediately.
 */
- (void)setPageIndicatorHidden:(BOOL)hidden animated:(BOOL)animated;

/**
 * Whether the reflow control is hidden. The default value is `YES`.
 */
@property (nonatomic, assign, getter=isReflowHidden) BOOL reflowHidden;

#pragma mark Automatic control hiding

/**
 * Whether the controls are hidden automatically after a period of time. The default value is `YES`.
 *
 * The `automaticControlHidingDelay` is used to specify the time delay.
 */
@property (nonatomic, assign) BOOL automaticallyHidesControls;

/**
 * The number of seconds to wait before automatically hiding the controls. The default value is
 * `PTDocumentViewControllerHideControlsInterval`.
 */
@property (nonatomic, assign) NSTimeInterval automaticControlHidingDelay;

/**
 * Restart the automatic control hiding timer with the delay specified in the
 * `automaticControlHidingDelay` property.
 */
- (void)restartAutomaticControlHidingTimer;

/**
 * Restart the automatic control hiding timer with the specified delay.
 *
 * The `automaticControlHidingDelay` property is updated with the specified delay.
 *
 * @param delay The delay to use for automatic control hiding.
 */
- (void)restartAutomaticControlHidingTimerWithDelay:(NSTimeInterval)delay;

/**
 * Stop the automatic control hiding timer.
 */
- (void)stopAutomaticControlHidingTimer;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
