//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTCreateToolBase.h"

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class PTFreeHandCreate;

/**
 * Informs the delegate object of changes in the originator's state.
 */
@protocol PTFreeHandCreateDelegate <NSObject>
@optional

/**
 * Called when a user adds a new stroke by touching the screen (as opposed to a redo action).
 * Typically used to enable an "undo" button.
 *
 * @param freeHandCreate the instance of the object calling the method
 */
- (void)strokeAdded:(PTFreeHandCreate*)freeHandCreate;

@end

/**
 * Creates FreeHand (Ink) annotations.
 */
@interface PTFreeHandCreate : PTCreateToolBase

// The following selectors are useful if implementing PTFreeHandCreate with multistrokeMode YES

/**
 * Removes the most recently added stroke.
 */
-(void)undoStroke;

/**
 * Restores a stroke removed with `undoStroke`.
 */
-(void)redoStroke;

/**
 * @return Returns `YES` if there are strikes than can be removed via `undoStroke`.
 */
-(BOOL)canUndoStroke;

/**
 * @return Returns `YES` if there are strikes than can be restoried via `redoStroke`.
 */
-(BOOL)canRedoStroke;


/**
 * Adds the freehand annotation to the document. Used when `multistrokeMode` is set to
 * `YES`.
 */
-(void)commitAnnotation;

/**
 * Set to `YES` if the annotation should include multiple strokes. Call `commitAnnotation`
 * push the annotation back into the PDF.
 */
@property (nonatomic, assign) BOOL multistrokeMode;

/**
 * An object that conforms to the PTFreeHandCreateDelegate protocol.
 */
@property (nonatomic, weak, nullable) id<PTFreeHandCreateDelegate> delegate;

@end

NS_ASSUME_NONNULL_END
