//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTTextSelectTool.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Tool for editing existing text markup annotations, such as highlights, underlines, etc.
 * In addition to changing basic properties like colour and opacity, it can change the
 * annotation's size, and it's type (e.g. turn a highlight into an underline).
 */
@interface PTTextMarkupEditTool : PTTextSelectTool

/**
 * Selects the specified text markup annotation.
 *
 * @param annotation the annotation to select
 *
 * @param pageNumber the page number of the annotation
 *
 * @return `YES` if the annotation was selected, `NO` otherwise.
 */
- (BOOL)selectTextMarkupAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned int)pageNumber;

@end

NS_ASSUME_NONNULL_END
