//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTTool.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * This tool is used to fill PDF forms (AcroForms). This includes text boxes, check boxes,
 * radio buttons, drop downs, and more.
 *
 * Signatures fields are handled by the `PTDigitalSignatureTool`.
 */
@interface PTFormFillTool : PTTool

/**
 * Whether an `inputAccessoryView` is shown for text fields (single and multi-line). The default
 * value is `YES`.
 */
@property (nonatomic, assign) BOOL displaysInputAccessoryView;

@end

NS_ASSUME_NONNULL_END
