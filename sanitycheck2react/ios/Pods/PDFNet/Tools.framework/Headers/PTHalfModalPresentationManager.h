//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * This class handles the creation of a UIPresentationController that displays its contents
 * covering a portion of the screen, anchored to the bottom of the screen.
 */
@interface PTHalfModalPresentationManager : NSObject <UIViewControllerTransitioningDelegate, UIPopoverPresentationControllerDelegate>

/**
 * The source rect used when a popover presentation is required.
 */
@property (nonatomic, assign) CGRect popoverSourceRect;

/**
 * The source view used when a popover presentation is required.
 */
@property (nonatomic, strong, nullable) UIView *popoverSourceView;

@end

NS_ASSUME_NONNULL_END
