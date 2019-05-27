//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTToolManager.h"
#import "PTAnnotStyle.h"
#import "PTHalfModalPresentationManager.h"

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTAnnotStyleViewController;

/**
 * The methods declared by the PTAnnotStyleViewControllerDelegate protocol allow the adopting delegate
 * to respond to messages from the AnnotStyleViewController class.
 */
@protocol PTAnnotStyleViewControllerDelegate <NSObject>

/**
 * Informs the delegate when the annotation style has been committed by the user.
 */
- (void)annotStyleViewController:(PTAnnotStyleViewController *)annotStyleViewController didCommitStyle:(PTAnnotStyle *)annotStyle;

@optional

/**
 * Informs the delegate when the annotation style has been changed by the user.
 */
- (void)annotStyleViewController:(PTAnnotStyleViewController *)annotStyleViewController didChangeStyle:(PTAnnotStyle *)annotStyle;

@end

/**
 * The AnnotStyleViewController displays a list of controls for adjusting the appearance and properties
 * of an annotation or annotation type.
 * The available controls are determined based on the type of annotation provided.
 */
@interface PTAnnotStyleViewController : UIViewController <PTAnnotStyleDelegate>

/**
 * Returns a new instance of an AnnotStyleViewController.
 *
 * @param annotStyle An instance of `PTAnnotStyle` initialized with an annotation or annotation type.
 */
- (instancetype)initWithAnnotStyle:(PTAnnotStyle *)annotStyle NS_DESIGNATED_INITIALIZER;

/**
 * Returns a new instance of an AnnotStyleViewController.
 *
 * @param toolManager An instance of `PTToolManager`.
 * @param annotStyle An instance of `PTAnnotStyle` initialized with an annotation or annotation type.
 */
- (instancetype)initWithToolManager:(PTToolManager *)toolManager annotStyle:(PTAnnotStyle *)annotStyle;

/**
 * The presentation manager responsible for displaying the style picker.
 */
@property (nonatomic, strong, nullable) PTHalfModalPresentationManager *presentationManager;

/**
 * An object that manages and stores the current colors and properties for an annotation.
 */
@property (nonatomic, strong) PTAnnotStyle *annotStyle;

/**
 * An object that conforms to the PTAnnotStyleViewControllerDelegate protocol.
 */
@property (nonatomic, weak, nullable) id<PTAnnotStyleViewControllerDelegate> delegate;

/**
 * Request the AnnotStyleViewController to call its delegate's `annotStyleViewController:didCommitStyle` method.
 */
- (void)selectStyle;


- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;


- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
