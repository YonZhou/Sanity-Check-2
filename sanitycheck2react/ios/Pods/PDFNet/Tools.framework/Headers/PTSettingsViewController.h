//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTSettingsViewController;

/**
 * The methods declared by the `PTSettingsViewControllerDelegate` protocol allow the adopting class
 * to respond to messages from the `PTSettingsViewController` class.
 */
@protocol PTSettingsViewControllerDelegate <NSObject>
@optional

/**
 * Informs the delegate that the `PTPDFViewCtrl` view mode was changed.
 */
- (void)settingsViewControllerDidUpdateViewMode:(PTSettingsViewController *)settingsViewController;

/**
 * Informs the delegate that the sticky toolbar setting was changed.
 */
- (void)settingsViewControllerDidUpdateStickyToolbar:(PTSettingsViewController *)settingsViewController;

/**
 * Informs the delegate that the thumbnails option was selected.
 */
- (void)settingsViewControllerDidSelectThumbnails:(PTSettingsViewController *)settingsViewController;

/**
 * Informs the delegate that the clockwise rotation option was selected.
 */
- (void)settingsViewControllerDidRotateClockwise:(PTSettingsViewController *)settingsViewController;

/**
 * Informs the delegate that the counter-clockwise rotation option was selected.
 */
- (void)settingsViewControllerDidRotateCounterClockwise:(PTSettingsViewController *)settingsViewController;

/**
 * Informs the delegate that the night mode option was toggled.
 */
- (void)settingsViewControllerDidToggleNightMode:(PTSettingsViewController *)settingsViewController;

/**
 * Asks the delegate if the `PTPDFViewCtrl` is currently in night mode.
 */
- (BOOL)viewerIsNightMode;

@end

/**
 * The `PTSettingsViewController` class displays settings to control a `PTPDFViewCtrl`.
 */
@interface PTSettingsViewController : UITableViewController

/**
 * The settings view controller's delegate.
 */
@property (nonatomic, weak, nullable) id<PTSettingsViewControllerDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
