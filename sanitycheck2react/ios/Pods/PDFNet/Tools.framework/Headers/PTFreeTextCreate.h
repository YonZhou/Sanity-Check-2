//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTTool.h"

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Creates a free text annotation.
 */
@interface PTFreeTextCreate: PTTool <UITextViewDelegate>

/**
 Sets the rect for a `PTFreeText` annotation.
 
 @param freeText The `PTFreeText` object.
 @param rect The `PTPDFRect` representation of the associated `UITextView`.
 @param pdfViewCtrl The `PTPDFViewCtrl` object.
 @param isRTL A `BOOL` indicating whether the text is in a right-to-left language.
 */
+(void)setRectForFreeText:(PTFreeText*)freeText withRect:(PTPDFRect*)rect pdfViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl isRTL:(BOOL)isRTL;

@end

NS_ASSUME_NONNULL_END
