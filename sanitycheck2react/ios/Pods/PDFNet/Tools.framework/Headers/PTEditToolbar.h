//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class PTEditToolbar;

/**
 * The `PTEditToolbarDelegate` procotol defines the interface that edit toolbar delegate objects
 * implement to respond to toolbar events.
 */
@protocol PTEditToolbarDelegate <UIToolbarDelegate>
@optional

/**
 * Notifies the delegate that an undo action has been requested.
 */
- (void)editToolbarUndoChange:(PTEditToolbar *)editToolbar;

/**
 * Notifies the delegate that a redo action has been requested.
 */
- (void)editToolbarRedoChange:(PTEditToolbar *)editToolbar;

/**
 * Notifies the delegate that all changes should be discarded and the toolbar should be closed.
 */
- (void)editToolbarDidCancel:(PTEditToolbar *)editToolbar;

/**
 * Notifies the delegate that the changes should be saved.
 */
- (void)editToolbarDidCommit:(PTEditToolbar *)editToolbar;

/**
 * Notifies the delegate that the style picker should be shown/hidden.
 */
- (void)editToolbarToggleStylePicker:(UIBarButtonItem*)sender;

@end

/**
 * The PTEditToolbar is used while creating certain annotation types and provides buttons for
 * saving or discarding changes, as well as an optional undo/redo interface.
 */
@interface PTEditToolbar : UIToolbar

/**
 * The edit toolbar's delegate object.
 */
@property (nonatomic, weak, nullable) id<PTEditToolbarDelegate> delegate;

/**
 * Whether the undo/redo buttons are hidden. The default is `NO`.
 */
@property (nonatomic, assign) BOOL undoRedoHidden;

/**
 * Whether the undo button is enabled. The default is `NO`.
 */
@property (nonatomic, assign, getter=isUndoEnabled) BOOL undoEnabled;

/**
 * Whether the redo button is enabled. The default is `NO`.
 */
@property (nonatomic, assign, getter=isRedoEnabled) BOOL redoEnabled;

@end

NS_ASSUME_NONNULL_END
