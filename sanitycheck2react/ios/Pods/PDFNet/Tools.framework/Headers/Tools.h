//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <UIKit/UIKit.h>

//! Project version number for Tools.
FOUNDATION_EXPORT double PTToolsVersionNumber;

//! Project version string for Tools.
FOUNDATION_EXPORT const unsigned char PTToolsVersionString[];

#import <Tools/AnnotTypes.h>
#import <Tools/PTAnalyticsHandlerAdapter.h>
#import <Tools/PTAnalyticsManager.h>
#import <Tools/PTAnnotEditTool.h>
#import <Tools/PTAnnotStyleViewController.h>
#import <Tools/PTAnnotationOptions.h>
#import <Tools/PTAnnotationToolbar.h>
#import <Tools/PTAnnotationViewController.h>
#import <Tools/PTAnnotStyleViewController.h>
#import <Tools/PTAreaCreate.h>
#import <Tools/PTBookmarkViewController.h>
#import <Tools/PTDiffViewController.h>
#import <Tools/PTEditToolbar.h>
#import <Tools/PTFindTextToolbar.h>
#import <Tools/PTOutlineViewController.h>
#import <Tools/PTThumbnailSliderViewController.h>
#import <Tools/PTThumbnailsViewController.h>
#import <Tools/PTThumbnailViewCell.h>
#import <Tools/PTThumbnailViewLayout.h>
#import <Tools/PTHalfModalPresentationManager.h>
#import <Tools/PTBookmarkUtils.h>
#import <Tools/PTToolsUtil.h>
#import <Tools/PTToolManager.h>
#import <Tools/PTAnnotEditTool.h>
#import <Tools/PTFormFillTool.h>
#import <Tools/PTLineEditTool.h>
#import <Tools/PTArrowCreate.h>
#import <Tools/PTBookmarkManager.h>
#import <Tools/PTBookmarkUtils.h>
#import <Tools/PTBookmarkViewController.h>
#import <Tools/PTChoiceFormViewController.h>
#import <Tools/PTCloudCreate.h>
#import <Tools/PTColorDefaults.h>
#import <Tools/PTColorPickerViewController.h>
#import <Tools/PTCoordinatedDocument.h>
#import <Tools/PTCreateToolBase.h>
#import <Tools/PTDigSigView.h>
#import <Tools/PTDigSigViewController.h>
#import <Tools/PTDigitalSignatureTool.h>
#import <Tools/PTDocumentViewController.h>
#import <Tools/PTEditToolbar.h>
#import <Tools/PTEllipseCreate.h>
#import <Tools/PTEraser.h>
#import <Tools/PTFileAttachmentCreate.h>
#import <Tools/PTFileAttachmentHandler.h>
#import <Tools/PTFindTextToolbar.h>
#import <Tools/PTFloatingSigViewController.h>
#import <Tools/PTFormFillTool.h>
#import <Tools/PTFreeHandCreate.h>
#import <Tools/PTFreeTextCreate.h>
#import <Tools/PTHalfModalPresentationManager.h>
#import <Tools/PTImageStampCreate.h>
#import <Tools/PTLineCreate.h>
#import <Tools/PTLineEditTool.h>
#import <Tools/PTMagnifierView.h>
#import <Tools/PTMeasurementScale.h>
#import <Tools/PTModel.h>
#import <Tools/PTNavigationListsViewController.h>
#import <Tools/PTNoteEditController.h>
#import <Tools/PTOutlineViewController.h>
#import <Tools/PTOverridable.h>
#import <Tools/PTOverrides.h>
#import <Tools/PTPDFTronUtil.h>
#import <Tools/PTPageIndicatorViewController.h>
#import <Tools/PTPanTool.h>
#import <Tools/PTPerimeterCreate.h>
#import <Tools/PTPolygonCreate.h>
#import <Tools/PTPolylineCreate.h>
#import <Tools/PTPolylineEditTool.h>
#import <Tools/PTRectangleCreate.h>
#import <Tools/PTRectangleRedactionCreate.h>
#import <Tools/PTReflowViewController.h>
#import <Tools/PTResizeWidgetView.h>
#import <Tools/PTRichMediaTool.h>
#import <Tools/PTRulerCreate.h>
#import <Tools/PTSelectionBar.h>
#import <Tools/PTSelectionRectContainerView.h>
#import <Tools/PTSelectionRectView.h>
#import <Tools/PTSettingsViewController.h>
#import <Tools/PTStampManager.h>
#import <Tools/PTStickyNoteCreate.h>
#import <Tools/PTTabbedDocumentViewController.h>
#import <Tools/PTTextHighlightCreate.h>
#import <Tools/PTTextMarkupCreate.h>
#import <Tools/PTTextMarkupEditTool.h>
#import <Tools/PTTextRedactionCreate.h>
#import <Tools/PTTextSearchViewController.h>
#import <Tools/PTTextSelectTool.h>
#import <Tools/PTTextSquigglyCreate.h>
#import <Tools/PTTextStrikeoutCreate.h>
#import <Tools/PTTextUnderlineCreate.h>
#import <Tools/PTThumbnailSliderViewController.h>
#import <Tools/PTThumbnailViewCell.h>
#import <Tools/PTThumbnailViewLayout.h>
#import <Tools/PTThumbnailsViewController.h>
#import <Tools/PTTool.h>
#import <Tools/PTToolManager.h>
#import <Tools/PTToolsUtil.h>
#import <Tools/PTUserBookmark.h>
#import <Tools/ToolsMacros.h>
