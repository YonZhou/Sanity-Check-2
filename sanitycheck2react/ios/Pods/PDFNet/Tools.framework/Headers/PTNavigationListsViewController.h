//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTToolManager.h"
#import "PTAnnotationViewController.h"
#import "PTOutlineViewController.h"
#import "PTBookmarkViewController.h"

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A container view controller similar to a `UITabBarController` that displays a segmented control where
 * the selection determines which child view controller to display.
 *
 * By default, the navigation lists controller contains an `PTOutlineViewController`, `PTAnnotationViewController`,
 * and a `PTBookmarkViewController`.
 */
@interface PTNavigationListsViewController : UIViewController

/**
 * Returns an initialized `PTNavigationListsViewController` with the default lists.
 *
 * @param toolManager the tool manager used to initialize the default child view controllers
 *
 * @return an initialized `PTNavigationListsViewController` with the default lists
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager NS_DESIGNATED_INITIALIZER;

/**
 * The child view controllers to manage and display.
 */
@property (nullable, nonatomic, copy) NSArray<UIViewController *> *listViewControllers;

/**
 * The currently selected view controller in `listViewControllers`.
 */
@property (nonatomic, assign, nullable) UIViewController *selectedViewController;

/**
 * The index of the currently selected list view controller. The default value is `0`.
 */
@property (nonatomic, assign) NSUInteger selectedIndex;

/**
 * The `PTOutlineViewController` that is added when the control is first instantiated.
 */
@property (nonatomic, strong, readonly) PTOutlineViewController *outlineViewController;

/**
 * The `PTAnnotationViewController` that is added when the control is first instantiated.
 */
@property (nonatomic, strong, readonly) PTAnnotationViewController *annotationViewController;

/**
 * The `PTBookmarkViewController` that is added when the control is first instantiated.
 */
@property (nonatomic, strong, readonly) PTBookmarkViewController *bookmarkViewController;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
