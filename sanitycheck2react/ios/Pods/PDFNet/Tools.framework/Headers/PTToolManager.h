//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "AnnotTypes.h"
#import "PTAnnotationOptions.h"
#import "PTTool.h"

#import <PDFNet/PDFNet.h>

NS_ASSUME_NONNULL_BEGIN

@class PTTool;
@protocol PTToolManagerDelegate;

/**
 * The `PTToolEvents` protocol allows the adopting class to receive events from a `PTToolSwitching`
 * and control the tool's behavior.
 */
@protocol PTToolEvents <NSObject>
@required

/**
 * Used by a tool to notify the tool manager that it has added an annotation.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The annotation that was added.
 *
 * @param pageNumber The page number of the PDF that the annotation was added to.
 *
 */
- (void)tool:(PTTool *)tool annotationAdded:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used by a tool to notify the tool manager that it has modified an annotation.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The annotation that was modified.
 *
 * @param pageNumber The page number of the PDF that the annotation was modified on.
 */
- (void)tool:(PTTool *)tool annotationModified:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used by a tool to notify the tool manager that it has removed an annotation.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The annotation that was removed.
 *
 * @param pageNumber The page number of the PDF that the annotation was removed from.
 */
- (void)tool:(PTTool *)tool annotationRemoved:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used by a tool to notify the tool manager that it has modified the data of a form field.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The form field annotation that has modified data.
 *
 * @param pageNumber The page number of the PDF that the form field annotation is on.
 */
- (void)tool:(PTTool *)tool formFieldDataModified:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the tool manager to take over link handling. Links can either be annotations,
 * or detected as links by PDFNet via text pattern matching. One of the two first parameters
 * will have a value, the other will be `nil`.
 *
 * @see `-[PTPDFViewCtrl SetUrlExtraction:]`
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The link annotation, if it exists, that will be handled. If there is not a link annotation, then `nil`.
 *
 * @param linkInfo If it exists, the text that was detected as matching the format of a link. `nil` otherwise.
 *
 * @param pageNumber The page number that the annotation or link is on.
 *
 * @return `YES` if the tool should handle the link; `NO` if not.
 */
-(BOOL)tool:(PTTool *)tool shouldHandleLinkAnnotation:(nullable PTAnnot *)annotation orLinkInfo:(nullable PTLinkInfo *)linkInfo onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the tool manager to control whether the tool should select the given annotation on `pageNumber`.
 *
 * @param tool The tool that sent the message.
 *
 * @param annotation The annotation that will be selected
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should continue to select the annotation; `NO` if not.
 */
-(BOOL)tool:(PTTool *)tool shouldSelectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Used by a tool to notify the tool manager that it has selected an annotation.
 *
 * @param tool The tool that sent the message.
 * @param annotation The annotation that was selected.
 * @param pageNumber The page number that the annotation is on.
 */
-(void)tool:(PTTool *)tool didSelectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the tool manager to control whether to show a menu controller for the given annotation and page number.
 *
 * @param tool The tool that sent the message.
 *
 * @param menuController The menu to be shown.
 *
 * @param annotation The annotation.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should show the UIMenuController; `NO` if not.
 */
-(BOOL)tool:(PTTool *)tool shouldShowMenu:(UIMenuController*)menuController forAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the tool manager to control handling of file attachments.
 *
 * @param tool The tool that sent the message.
 *
 * @param fileAttachment The file attachment annotation.
 *
 * @param pageNumber The page number that the annotation is on.
 */
- (void)tool:(PTTool *)tool handleFileAttachment:(PTFileAttachment *)fileAttachment onPageNumber:(unsigned long)pageNumber;

/**
 * Dispatches a "custom" event.
 *
 * This method triggers an asynchronous call to `-[PTToolSwitching onSwitchToolEvent:]` with
 * the provided user data.
 *
 * @param userData Arbitrary data provided by the tool.
 */
-(void)createSwitchToolEvent:(nullable id)userData;

@end

/**
 * The `PTToolOptionsDelegate` protocol allows the adopting class to provide annotation options
 * information to a tool.
 */
@protocol PTToolOptionsDelegate <NSObject>
@required

/**
 * Used by a tool to check whether the specified annotation type can be created.
 *
 * @param tool the tool that sent the message
 * @param annotType the annotation type to be created
 *
 * @return `YES` if the annotation type can be created, `NO` otherwise
 */
- (BOOL)tool:(PTTool *)tool canCreateExtendedAnnotType:(PTExtendedAnnotType)annotType;

/**
 * Used by a tool to check whether the specified annotation can be edited.
 *
 * @param tool the tool that sent the message
 *
 * @param annotation the annotation to be edited
 *
 * @return `YES` if the annotation can be edited, `NO` otherwise
 */
- (BOOL)tool:(PTTool *)tool canEditAnnotation:(PTAnnot *)annotation;

/**
 * Used by a tool to check whether the specified annotation type can be edited.
 *
 * @param tool the tool that sent the message
 *
 * @param annotType the annotation type to be edited
 *
 * @return `YES` if the annotation type can be edited, `NO` otherwise
 */
- (BOOL)tool:(PTTool *)tool canEditExtendedAnnotType:(PTExtendedAnnotType)annotType;

#pragma mark - Annotation permissions

/**
 * Used by a tool to check whether the specified annotation allows editing.
 *
 * @param tool the tool that sent the message.
 *
 * @param annot the annotation to be edited
 *
 * @return `YES` if the annotation allows editing, `NO` otherwise
 */
- (BOOL)tool:(PTTool *)tool hasEditPermissionForAnnot:(PTAnnot *)annot;

#pragma mark - Convenience

/**
 * Used by a tool to check if text selection is enabled.
 */
- (BOOL)isTextSelectionEnabledForTool:(PTTool *)tool;

/**
 * Used by a tool to check if form filling is enabled.
 */
- (BOOL)isFormFillingEnabledForTool:(PTTool *)tool;

/**
 * Used by a tool to check if link following is enabled.
 */
- (BOOL)isLinkFollowingEnabledForTool:(PTTool *)tool;

/**
 * Used by a tool to check if the eraser tool is enabled.
 */
- (BOOL)isEraserEnabledForTool:(PTTool *)tool;

/**
 * Used to check if auto resizing free text is enabled.
 */
- (BOOL)autoResizeFreeText;

/**
 * Used to set if auto resizing free text is enabled.
 */
- (void)setAutoResizeFreeText:(BOOL)enabled;

/**
 * Used to check if snapping to document geometry is enabled.
 */
- (BOOL)snapToDocumentGeometry;

/**
 * Used to set if snapping to document geometry is enabled.
 */
- (void)setSnapToDocumentGeometry:(BOOL)enabled;

@end

/**
 * The `PTToolManager` class is responsbile for forwarding events from the PDFViewCtrl to Tools,
 * and coordinating the control and data flow between tools.
 */
@interface PTToolManager : UIView <PTPDFViewCtrlToolDelegate, PTToolEvents, PTToolOptionsDelegate>

/**
 * The current tool.
 */
@property (nonatomic, strong, nullable) PTTool *tool;

/**
 * An object that conforms to the `PTToolManagerDelegate` protocol.
 */
@property (nonatomic, weak, nullable) id<PTToolManagerDelegate> delegate;

/**
 * The `PTPDFViewCtrl` that the `PTToolManager` was initialized with.
 */
@property (nonatomic, readonly, weak) PTPDFViewCtrl *pdfViewCtrl;

/**
 * Returns a newly initialized tool manager with the required pointer to the PTPDFViewCtrl on which it will operate.
 *
 * @param pdfViewCtrl a pointer to the PTPDFViewCtrl that the tool manager will operate.
 *
 * @return A newly initialized tool manager object.
 *
 */
- (instancetype)initWithPDFViewCtrl:(PTPDFViewCtrl*)pdfViewCtrl NS_DESIGNATED_INITIALIZER;

/**
 * Create and set a new tool of the given type as the current tool.
 */
- (PTTool *)changeTool:(Class)toolType;

/**
 * Selects the specified annotation.
 *
 * @param annotation the annotation to selected
 *
 * @param pageNumber the page number of the annotation
 *
 * @return `YES` if the annotation was selected, `NO` otherwise.
 */
- (BOOL)selectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;


- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


- (instancetype)initWithCoder:(NSCoder *)aDecoder NS_UNAVAILABLE;

/**
 * A string that will be used to set the author field of annotations that are created.
 */
@property (nonatomic, copy, nullable) NSString *annotationAuthor;

/**
 * When true, the UIMenuController shows after a tap (in addition to after a long press).
 * The default value of this property is `false`.
 */
@property (nonatomic, assign) BOOL showMenuOnTap;

/**
 * When true, the digital signature tool gives the option to save a default signature.
 * The default value of this property is `true`.
 */
@property (nonatomic, assign) BOOL showDefaultSignature;

/**
 * Whether the built-in page number indicator is enabled. The default value of this property is `false`.
 */
@property (nonatomic, assign, getter=isPageIndicatorEnabled) BOOL pageIndicatorEnabled;

/**
 * Whether the document associated with the `PTPDFViewCtrl` is read-only. The default value is `NO`.
 *
 * When in read-only mode, annotation creation and editing are disabled as well as other actions
 * that would modify the document.
 */
@property (nonatomic, assign, getter=isReadonly) BOOL readonly;

#pragma mark - Annotation options

/**
 * The options for text (`PTExtendedAnnotTypeText`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *textAnnotationOptions;

/**
 * The options for link (`PTExtendedAnnotTypeLink`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *linkAnnotationOptions;

/**
 * The options for free text (`PTExtendedAnnotTypeFreeText`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *freeTextAnnotationOptions;

/**
 * The options for line (`PTExtendedAnnotTypeLine`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *lineAnnotationOptions;

/**
 * The options for square (`PTExtendedAnnotTypeSquare`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *squareAnnotationOptions;

/**
 * The options for circle (`PTExtendedAnnotTypeCircle`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *circleAnnotationOptions;

/**
 * The options for polygon (`PTExtendedAnnotTypePolygon`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *polygonAnnotationOptions;

/**
 * The options for polyline (`PTExtendedAnnotTypePolyline`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *polylineAnnotationOptions;

/**
 * The options for highlight (`PTExtendedAnnotTypeHighlight`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *highlightAnnotationOptions;

/**
 * The options for underline (`PTExtendedAnnotTypeUnderline`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *underlineAnnotationOptions;

/**
 * The options for squiggly (`PTExtendedAnnotTypeSquiggly`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *squigglyAnnotationOptions;

/**
 * The options for strikeout (`PTExtendedAnnotTypeStrikeOut`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *strikeOutAnnotationOptions;

/**
 * The options for rubber stamp (`PTExtendedAnnotTypeStamp`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *stampAnnotationOptions;

/**
 * The options for caret (`PTExtendedAnnotTypeCaret`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *caretAnnotationOptions;

/**
 * The options for ink (`PTExtendedAnnotTypeInk`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *inkAnnotationOptions;

/**
 * The options for pop-up (`PTExtendedAnnotTypePopup`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *popupAnnotationOptions;

/**
 * The options for file attachment (`PTExtendedAnnotTypeFileAttachment`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *fileAttachmentAnnotationOptions;

/**
 * The options for sound (`PTExtendedAnnotTypeSound`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *soundAnnotationOptions;

/**
 * The options for movie (`PTExtendedAnnotTypeMovie`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *movieAnnotationOptions;

/**
 * The options for widget (`PTExtendedAnnotTypeWidget`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *widgetAnnotationOptions;

/**
 * The options for Screen (`PTExtendedAnnotTypeScreen`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *screenAnnotationOptions;

/**
 * The options for printer's mark (`PTExtendedAnnotTypePrinterMark`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *printerMarkAnnotationOptions;

/**
 * The options for trap network (`PTExtendedAnnotTypeTrapNet`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *trapNetAnnotationOptions;

/**
 * The options for watermark (`PTExtendedAnnotTypeWatermark`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *watermarkAnnotationOptions;

/**
 * The options for 3D (`PTExtendedAnnotType3D`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *threeDimensionalAnnotationOptions;

/**
 * The options for redact (`PTExtendedAnnotTypeRedact`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *redactAnnotationOptions;

/**
 * The options for projection (`PTExtendedAnnotTypeProjection`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *projectionAnnotationOptions;

/**
 * The options for Rich Media (`PTExtendedAnnotTypeRichMedia`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *richMediaAnnotationOptions;

/**
 * The options for arrow (`PTExtendedAnnotTypeArrow`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *arrowAnnotationOptions;

/**
 * The options for signature (`PTExtendedAnnotTypeSignature`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *signatureAnnotationOptions;

/**
 * The options for cloudy (`PTExtendedAnnotTypeCloudy`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *cloudyAnnotationOptions;

/**
 * The options for image stamp (`PTExtendedAnnotTypeImageStamp`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *imageStampAnnotationOptions;

/**
 * The options for ruler (`PTExtendedAnnotTypeRuler`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *rulerAnnotationOptions;

/**
 * The options for signature (`PTExtendedAnnotTypePerimeter`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *perimeterAnnotationOptions;

/**
 * The options for cloudy (`PTExtendedAnnotTypeArea`) annotations.
 */
@property (nonatomic, copy) PTAnnotationOptions *areaAnnotationOptions;

/**
 * Returns the `PTAnnotationOptions` for the specified annotation type.
 *
 * @param annotType the annotation type
 *
 * @return the `PTAnnotationOptions` for the specified annotation type, or `nil` if not found.
 */
- (nullable PTAnnotationOptions *)annotationOptionsForAnnotType:(PTExtendedAnnotType)annotType;

/**
 * Returns whether the specified annotation type can be created.
 */
- (BOOL)canCreateExtendedAnnotType:(PTExtendedAnnotType)annotType;

/**
 * Returns whether the specified annotation type can be edited.
 */
- (BOOL)canEditExtendedAnnotType:(PTExtendedAnnotType)annotType;

#pragma mark - Annotation permissions

/**
 * Returns whether the specified annotation allows editing.
 */
- (BOOL)hasEditPermissionForAnnot:(PTAnnot *)annot;

/**
 * Whether the permissions of an `PTAnnot`, returned via `-[PTAnnot GetFlag:]`, are checked when
 * determining whether the annotation can be edited.
 * The default value of this property is `NO`.
 */
@property (nonatomic, assign, getter=isAnnotationPermissionCheckEnabled) BOOL annotationPermissionCheckEnabled;

#pragma mark - Interaction features

/**
 * A boolean value that determines whether text selection is enabled.
 */
@property (nonatomic, assign, getter=isTextSelectionEnabled) BOOL textSelectionEnabled;

/**
 * A boolean value that determines whether form filling is enabled.
 */
@property (nonatomic, assign, getter=isFormFillingEnabled) BOOL formFillingEnabled;

/**
 * A boolean value that determines whether link following is enabled.
 */
@property (nonatomic, assign, getter=isLinkFollowingEnabled) BOOL linkFollowingEnabled;

/**
 * A boolean value that determines whether the eraser tool is enabled.
 */
@property (nonatomic, assign, getter=isEraserEnabled) BOOL eraserEnabled;

/**
 * A boolean value that determines whether free text annots should get automatically resized.
 */
@property (nonatomic, assign, getter=isAutoResizeFreeTextEnabled) BOOL autoResizeFreeTextEnabled;

/**
 * A boolean value that determines whether measurement annots should snap to document geometry.
 */
@property (nonatomic, assign, getter=isSnapToDocumentGeometryEnabled) BOOL snapToDocumentGeometryEnabled;

@end

/**
 * The methods declared by the `PTToolManagerDelegate` protocol allow the adopting
 * delegate to respond to messages from the PTToolManager class.
 */
@protocol PTToolManagerDelegate <NSObject>
@optional

/**
 * Allows the delegate to control if a tool should be activated
 *
 * @param toolManager The tool manager.
 *
 * @param tool The tool that will be activated
 *
 */
- (BOOL)toolManager:(PTToolManager *)toolManager shouldSwitchToTool:(PTTool *)tool;

/**
 * Tells the delegate that the tool has changed.
 *
 * @param toolManager The PTToolManager that had the tool change.
 *
 */
- (void)toolManagerToolChanged:(PTToolManager *)toolManager;

/**
 * Allows the delegate to take over link handling. Links can either be annotations, or detected
 * as links by PDFNet via text pattern matching (see `-[PTPDFViewCtrl SetUrlExtraction:]`). One of
 * the two first parameters will have a value, the other will be `nil`.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The link annotation, if it exists, that will be handled. If there is not a
 * link annotation, then `nil`.
 *
 * @param linkInfo If it exists, the text that was detected as matching the format of a link.
 * `nil` otherwise.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should handle the link; `NO` if not.
 *
 */
-(BOOL)toolManager:(PTToolManager *)toolManager shouldHandleLinkAnnotation:(nullable PTAnnot *)annotation orLinkInfo:(nullable PTLinkInfo *)linkInfo onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the delegate to control handling of file attachments.
 *
 * @param toolManager the tool manager.
 *
 * @param fileAttachment the file attachment annotation
 *
 * @param pageNumber The page number that the annotation is on.
 */
- (void)toolManager:(PTToolManager *)toolManager handleFileAttachment:(PTFileAttachment *)fileAttachment onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the delegate to control whether to show a menu controller for the given annotation and page number.
 *
 * @param toolManager The tool manager.
 *
 * @param menuController The menu to be shown.
 *
 * @param annotation The annotation.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should show the UIMenuController; `NO` if not.
 *
 */
-(BOOL)toolManager:(PTToolManager *)toolManager shouldShowMenu:(UIMenuController *)menuController forAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Allows the delegate to control whether the tool should select the given annotation on `pageNumber`.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that will be selected.
 *
 * @param pageNumber The page number that the annotation is on.
 *
 * @return `YES` if the tool should continue to select the annotation; `NO` if not.
 *
 */
-(BOOL)toolManager:(PTToolManager *)toolManager shouldSelectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Raised when the tools code selects an annotation.
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was selected.
 *
 * @param pageNumber The page number of the PDF that the annotation was selected on.
 */
-(void)toolManager:(PTToolManager *)toolManager didSelectAnnotation:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Raised when the tools code adds an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was added.
 *
 * @param pageNumber The page number of the PDF that the annotation was added to.
 */
- (void)toolManager:(PTToolManager *)toolManager annotationAdded:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Raised when the tools code modifies an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was modified.
 *
 * @param pageNumber The page number of the PDF that the annotation is on.
 */
- (void)toolManager:(PTToolManager *)toolManager annotationModified:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Raised when the tools code removes an annotation
 *
 * @param toolManager The tool manager.
 *
 * @param annotation The annotation that was removed.
 *
 * @param pageNumber The page number of the PDF that the annotation was removed from.
 */
- (void)toolManager:(PTToolManager *)toolManager annotationRemoved:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

/**
 * Raised when the tools code modifies a form field annotation's data
 *
 * @param annotation The form field annotation that has modified data.
 *
 * @param pageNumber The page number of the PDF that the form field annotation is on.
 */
- (void)toolManager:(PTToolManager *)toolManager formFieldDataModified:(PTAnnot *)annotation onPageNumber:(unsigned long)pageNumber;

#pragma mark - Overriding default gesture behavior
/** @name Overriding default gesture behavior
 */

/**
 * Allows the delegate to handle tap gestures.
 *
 * @param toolManager The Tool manager.
 *
 * @param gestureRecognizer The gesture recognizer that triggered the event.
 *
 * @return `YES` if the delegate has handled the event, `NO` if it should be handled by the tool manager.
 */
- (BOOL)toolManager:(PTToolManager *)toolManager handleTap:(UITapGestureRecognizer *)gestureRecognizer;

/**
 * Allows the delegate to handle double tap gestures.
 *
 * @param toolManager The Tool manager.
 *
 * @param gestureRecognizer The gesture recognizer that triggered the event.
 *
 * @return `YES` if the delegate has handled the event, `NO` if it should be handled by the tool manager.
 */
- (BOOL)toolManager:(PTToolManager *)toolManager handleDoubleTap:(UITapGestureRecognizer *)gestureRecognizer;

/**
 * Allows the delegate to handle long press gestures.
 *
 * @param toolManager The Tool manager.
 *
 * @param gestureRecognizer The gesture recognizer that triggered the event.
 *
 * @return `YES` if the delegate has handled the event, `NO` if it should be handled by the tool manager.
 */
- (BOOL)toolManager:(PTToolManager *)toolManager handleLongPress:(UILongPressGestureRecognizer *)gestureRecognizer;

@end

#pragma mark - Notifications

/**
 * Posted when the tool has changed.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains an entry for the `PTToolManagerPreviousToolUserInfoKey` key when there is a previous tool.
 */
PT_EXPORT const NSNotificationName PTToolManagerToolDidChangeNotification;

/**
 * Posted when an annotation is added.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationAddedNotification;

/**
 * Posted when an annotation is modified.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationModifiedNotification;

/**
 * Posted when an annotation is removed.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationRemovedNotification;

/**
 * Posted when a form field's data is modified, e.g. a text box's text is modified, a checkbox is checked, etc.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains entries for the `PTToolManagerAnnotationUserInfoKey` and `PTToolManagerPageNumberUserInfoKey`
 * keys.
 */
PT_EXPORT const NSNotificationName PTToolManagerFormFieldDataModifiedNotification;

/**
 * Posted when annotation options change.
 *
 * The notification object is the tool manager that posted the notification. The `userInfo` dictionary
 * contains an entry for the `PTToolManagerAnnotationNamesUserInfoKey` key with the changed annotation
 * types.
 */
PT_EXPORT const NSNotificationName PTToolManagerAnnotationOptionsDidChangeNotification;

#pragma mark User Info Keys

/**
 * The key for the `Class` of the previous tool type.
 */
PT_EXPORT NSString * const PTToolManagerPreviousToolUserInfoKey;

/**
 * The key for a `PTAnnot` object.
 */
PT_EXPORT NSString * const PTToolManagerAnnotationUserInfoKey;

/**
 * The key for a `NSNumber` object containing an `int` page number.
 */
PT_EXPORT NSString * const PTToolManagerPageNumberUserInfoKey;

/**
 * The key for an `NSArray` of `PTExtendedAnnotName` constants.
 */
PT_EXPORT NSString * const PTToolManagerAnnotationNamesUserInfoKey;

NS_ASSUME_NONNULL_END
