//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTTool.h"
#import "PTDigSigViewController.h"
#import "PTFloatingSigViewController.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * Handles creation of signatures and digitally signing documents.
 */
@interface PTDigitalSignatureTool : PTTool <PTDigSigViewControllerDelegate, PTFloatingSigViewControllerDelegate>

/**
 * Whether to allow saving and using a default signature. The default value of this property is `YES`.
 */
@property (nonatomic, assign) BOOL showDefaultSignature;

@end

NS_ASSUME_NONNULL_END
