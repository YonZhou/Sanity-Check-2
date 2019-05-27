//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTDigSigViewController;

/**
 * The methods declared by the PTDigSigViewControllerDelegate protocol allow the adopting delegate
 * to respond to message from the `PTDigSigViewController` class.
 */
@protocol PTDigSigViewControllerDelegate <NSObject>
@required

/**
 * Informs the delegate to save the specified path appearance for the signature form field.
 */
- (void)digSigViewController:(PTDigSigViewController *)digSigViewController saveAppearanceWithPath:(NSMutableArray *)points fromCanvasSize:(CGSize)canvasSize;

/**
 * Informs the delegate to save the specified image appearance for the signature form field.
 */
- (void)digSigViewController:(PTDigSigViewController *)digSigViewController saveAppearanceWithUIImage:(UIImage *)image;

/**
 * Informs the delegate that the signature view controller should be closed.
 */
- (void)digSigViewControllerCloseSignatureDialog:(PTDigSigViewController *)digSigViewController;

/**
 * Informs the delegate that the document should be digitally signed and saved.
 */
- (void)digSigViewControllerSignAndSave:(PTDigSigViewController *)digSigViewController;

@end

/**
 * The PTDigSigViewController allows the user to draw a signature or select an image for
 * a signature form field. A certificate can be used for digital signing.
 */
@interface PTDigSigViewController : UIViewController <UIImagePickerControllerDelegate, UINavigationControllerDelegate>

/**
 * The thickness of the drawn lines.
 */
@property (nonatomic, assign) CGFloat strokeThickness;

/**
 * The color to use for drawing.
 */
@property (nonatomic, strong) UIColor *strokeColor;

/**
 * Whether digital signing is allowed.
 */
@property (nonatomic, assign) BOOL allowDigitalSigning;

/**
 * An object that conforms to the `PTDigSigViewControllerDelegate` protocol.
 */
@property (nonatomic, weak) id<PTDigSigViewControllerDelegate> delegate;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
