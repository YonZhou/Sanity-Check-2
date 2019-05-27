//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTColorPickerViewController;

/**
 * The methods declared by the PTColorPickerViewControllerDelegate protocol allow the adopting delegate to
 * respond to messages from the `PTColorPickerViewController` class.
 */
@protocol PTColorPickerViewControllerDelegate <NSObject>

/**
 * Informs the delegate that a color has been selected by the user.
 */
- (void)colorPickerController:(PTColorPickerViewController *)colorPickerController didSelectColor:(UIColor *)color;

@end

/**
 * The PTColorPickerViewController displays a grid of color cells for selection. Selecting a color cell notifies
 * the delegate object.
 */
@interface PTColorPickerViewController : UIPageViewController <UIPageViewControllerDataSource>

/**
 * The currently selected color.
 */
@property (nonatomic, strong, nullable) UIColor *color;

/**
 * An identifier that can be used to indicate the type of color being picked.
 */
@property (nonatomic, strong) id tag;

/**
 * An object that conforms to the `PTColorPickerViewControllerDelegate` protocol.
 */
@property (nonatomic, weak, nullable) id<PTColorPickerViewControllerDelegate> colorPickerDelegate;

@end

NS_ASSUME_NONNULL_END
