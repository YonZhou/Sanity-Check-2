//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import "PTTool.h"

#import <UIKit/UIKit.h>
#import <AVKit/AVKit.h>
#import <AVFoundation/AVFoundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * Plays movies that are embedded in PDF files.
 */
@interface PTRichMediaTool : PTTool

/**
 * The movie playing UIViewController that's view is overlayed onto the PDF.
 */
@property (nonatomic, readonly, strong, nullable) AVPlayerViewController* moviePlayer;
 
/**
 * The path to the current movie.
 */
@property (nonatomic, readonly, copy, nullable) NSString* moviePath;

@end

NS_ASSUME_NONNULL_END
