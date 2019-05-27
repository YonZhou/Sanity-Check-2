//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "ToolsMacros.h"

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * The default line, interitem, and section inset spacing.
 */
PT_EXPORT const CGFloat PTThumbnailViewLayoutDefaultSpacing;

/**
 * A `UICollectionViewLayout` for use with `PTThumbnailsViewController`.
 */
@interface PTThumbnailViewLayout : UICollectionViewFlowLayout


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
