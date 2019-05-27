//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTDocumentViewController.h"

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTTabbedDocumentViewController;

/**
 * The methods declared by the PTTabbedDocumentViewControllerDelegate protocol allow the adopting delegate
 * to respond to messages from the `PTTabbedDocumentViewController` class.
 */
@protocol PTTabbedDocumentViewControllerDelegate <NSObject>
@optional

/**
 * Informs the delegate that a tab will be removed from the tabbed document view controller.
 */
- (void)tabbedDocumentViewController:(PTTabbedDocumentViewController *)tabbedDocumentViewController willRemoveTabAtIndex:(NSUInteger)index;

/**
 * Informs the delegate that a `PTDocumentViewController` will be added. This provides an opportunity to perform any setup on the
 * view controller before it is presented to the user.
 */
- (void)tabbedDocumentViewController:(PTTabbedDocumentViewController *)tabbedDocumentViewController willAddDocumentViewController:(PTDocumentViewController*)documentViewController;

@end

/**
 * A container view controller that displays multiple documents with a tab bar control to allow
 * switching between documents.
 */
@interface PTTabbedDocumentViewController : UIViewController

/**
 * Returns an initialized `PTTabbedDocumentViewController`.
 *
 * @return an initialized `PTTabbedDocumentViewController`.
 */
- (instancetype)init NS_DESIGNATED_INITIALIZER;

/**
 * Open a document with the given URL.
 *
 * @param url The URL to open.
 */
- (void)openDocumentWithURL:(NSURL *)url;

/**
 * Open a document with the given URL and password.
 *
 * @param url The URL to open.
 *
 * @param password The password for the document.
 */
- (void)openDocumentWithURL:(NSURL *)url password:(nullable NSString *)password;

/**
 * Whether multiple tabs can be displayed.
 *
 * The default value of this property is `YES`. If tabs are disabled, the tab bar will be hidden and
 * all tabs except the selected tab will be removed.
 */
@property (nonatomic, assign) BOOL tabsEnabled;

/**
 * The maximum number of tabs allowed. There is no limit by default.
 *
 * When the maximum number of tabs is reached, adding subsequent tabs will remove other tabs to respect
 * the limit.
 *  
 * @note The value of this property must be greater than zero.
 */
@property (nonatomic, assign) NSUInteger maximumTabCount;

#pragma mark Tab management

/**
 * An array of the URLs managed by the view controller and displayed by the tab bar interface.
 * The tabs are displayed in the same order as in the array.
 */
@property (nonatomic, copy, nonnull) NSArray<NSURL *> *tabURLs;

/**
 * Returns the `PTDocumentViewController` at the specified tab index.
 *
 * @param index the view controller's tab index
 *
 * @return the `PTDocumentViewController` at the specified tab index, or `nil` if it is not loaded.
 */
- (nullable PTDocumentViewController *)documentViewControllerAtIndex:(NSUInteger)index;

/**
 * Inserts the given URL at the end of the tab bar.
 *
 * If the URL already exists in the view controller then it will not be re-added.
 *
 * @param url The URL to add to the end of the tab bar.
 *
 * @param selected Whether to select the tab after it has been added.
 */
- (void)addTabWithURL:(NSURL *)url selected:(BOOL)selected;

/**
 * Inserts the given URL into the tab bar at the specified index.
 *
 * If the URL already exists in the view controller then it will not be re-added.
 *
 * @param url The URL to add to the tab bar.
 *
 * @param index The index in the tab bar at which to insert the URL. This value must not be greater than
 * the number of tabs in the tab bar.
 *
 * @param selected Whether to selected the tab after it has been inserted.
 */
- (void)insertTabWithURL:(NSURL *)url atIndex:(NSUInteger)index selected:(BOOL)selected;

/**
 * Removes the first occurence of the given URL in the tab bar.
 *
 * @param url The URL to remove from the tab bar.
 */
- (void)removeTabWithURL:(NSURL *)url;

/**
 * Removes the tab at the given index.
 *
 * @param index The index from which to remove the tab in the tab bar.
 */
- (void)removeTabAtIndex:(NSUInteger)index;

#pragma mark Selection

/**
 * The URL associated with the currently selected tab.
 */
@property (nonatomic, weak, nullable) NSURL *selectedURL;

/**
 * The index of the tab URL associated with the currently selected tab.
 */
@property (nonatomic, assign) NSUInteger selectedIndex;

/**
 * The currently selected `PTDocumentViewController`.
 */
@property (nonatomic, readonly, nullable) PTDocumentViewController *selectedViewController;

#pragma mark Tab bar

/**
 * A Boolean value that indicates whether the tab bar is hidden.
 *
 * If `YES`, the tab bar is hidden. The default value is `NO` if the `tabsEnabled` property is enabled.
 * Setting this property changes the visibility of the tab bar without animating the changes. If you want
 * to animate the change, use the `-setTabBarHidden:animated:` method instead.
 */
@property (nonatomic, assign, getter=isTabBarHidden) BOOL tabBarHidden;

/**
 * Sets whether the tab bar is hidden.
 *
 * For animated transitions, the duration of the animation is specified by the value in the `UINavigationControllerHideShowBarDuration` constant.
 *
 * @param hidden Specify `YES` to hide the tab bar or `NO` to show it
 *
 * @param animated Specify `YES` if you want to animate the change in visibility or `NO` if you want the
 * tab bar to appear immediately.
 */
- (void)setTabBarHidden:(BOOL)hidden animated:(BOOL)animated;

#pragma mark Other

/**
 The delegate of the tabbed document view controller object.
 */
@property (nonatomic, weak, nullable) id<PTTabbedDocumentViewControllerDelegate> delegate;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
