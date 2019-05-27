//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Foundation/Foundation.h>

/**
 * Visibility
 */

#ifdef __cplusplus
    #define PT_EXPORT extern "C"
#else
    #define PT_EXPORT extern
#endif /* __cplusplus */

/**
 * Preprocessor
 */

#define PT_STRINGIFY__(x) # x
#define PT_STRINGIFY(x) PT_STRINGIFY__(x)
#define PT_NS_STRINGIFY(x) @ PT_STRINGIFY(x)

#define PT_PASTE__(x, y) x ## y
#define PT_PASTE(x, y) PT_PASTE__(x, y)

/*
 * Arrays
 */

#define PT_C_ARRAY_SIZE(array) (sizeof(array) / sizeof((array)[0]))

/**
 * Unavailability
 */

// PT_UNAVAILABLE_MSG(msg)

#if __has_attribute(unavailable)
    #if __has_extension(attribute_unavailable_with_message)
        #define PT_UNAVAILABLE_MSG(msg) __attribute__((unavailable(msg)))
    #else
        #define PT_UNAVAILABLE_MSG(msg) __attribute__((unavailable))
    #endif
#else
    #define PT_UNAVAILABLE_MSG(msg)
#endif

// PT_UNAVAILABLE

#define PT_UNAVAILABLE PT_UNAVAILABLE_MSG("")

#define PT_INIT_UNAVAILABLE \
- (instancetype)init PT_UNAVAILABLE; \
+ (instancetype)new PT_UNAVAILABLE;

#define PT_INIT_WITH_FRAME_UNAVAILABLE \
- (instancetype)initWithFrame:(CGRect)frame PT_UNAVAILABLE;

#define PT_INIT_WITH_CODER_UNAVAILABLE \
- (instancetype)initWithCoder:(NSCoder *)coder PT_UNAVAILABLE;

#define PT_INIT_WITH_NIB_NAME_BUNDLE_UNAVAILABLE \
- (instancetype)initWithNibName:(nullable NSString *)nibNameOrNil bundle:(nullable NSBundle *)nibBundleOrNil PT_UNAVAILABLE;

/**
 * Deprecation
 */

#define PT_DEPRECATED_MSG(version, msg) \
DEPRECATED_MSG_ATTRIBUTE("Deprecated in PDFTron for iOS " PT_STRINGIFY(version) ". " msg)

#define PT_DEPRECATED(version) PT_DEPRECATED_MSG(version, "")

/**
 * Constructors and destructors
 */

#define PT_CONSTRUCTOR __attribute__((constructor))

#define PT_CONSTRUCTOR_PRIORITY(priority) __attribute__((constructor(priority)))

#define PT_DESTRUCTOR __attribute__((destructor))

#define PT_DESTRUCTOR_PRIORITY(priority) __attribute__((destructor(priority)))

/**
 * Property key paths
 */

#ifdef DEBUG
    #define PT_PROP_KEY_PATH(object, property) ((void)((object).property), PT_NS_STRINGIFY(property))
#else
    #define PT_PROP_KEY_PATH(object, property) PT_NS_STRINGIFY(property)
#endif /* DEBUG */

/**
 * Logging
 */

#define PT_NSStringFromBOOL(b) ((b) ? @"YES" : @"NO")

#ifdef DEBUG
    #define PTLog(format, ...) NSLog(format, ##__VA_ARGS__)
#else
    #define PTLog(format, ...) (void)0
#endif

#ifdef DEBUG
    #define PrivateLog(format, ...) NSLog(format, ##__VA_ARGS__)
#else
    #define PrivateLog(format, ...) (void)0
#endif
