//---------------------------------------------------------------------------------------
// Copyright (c) 2001-2019 by PDFTron Systems Inc. All Rights Reserved.
// Consult legal.txt regarding legal and license information.
//---------------------------------------------------------------------------------------

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 * A model base class that uses all KVC-compliant properties to support encoding and decoding.
 */
@interface PTModel : NSObject <NSCopying>

/**
 * The names of all KVC-compliant properties, exluding those of the `PTModel` class.
 */
@property (nonatomic, class, readonly, copy) NSSet<NSString *> *propertyKeys;

/**
 * The dictionary value of the receiver, using the keys in the `propertyKeys` property.
 */
@property (nonatomic, readonly, copy) NSDictionary<NSString *, id> *dictionaryValue;

/**
 * The names of all KVC-compliant properties for the calling class.
 */
@property (nonatomic, class, readonly, copy) NSSet<NSString *> *localPropertyKeys;

/**
 * A dictionary of property names and classes of all properties with explicit object types.
 */
@property (nonatomic, class, readonly, copy) NSDictionary<NSString *, Class> *propertyClasses;

/**
 * Returns the names of all properties whose class is a subclass of, or identical to, a given class.
 *
 * @param aClass A class object
 *
 * @return the names of all properties whose class is a subclass of, or identical to, `aClass`
 */
+ (NSSet<NSString *> *)propertyKeysForKindOfClass:(Class)aClass;

/**
 * Returns the dictionary value of the receiver, using only the local property keys of the
 * calling class.
 *
 * @return the dictionary value of the receiver
 */
+ (NSDictionary<NSString *,id> *)localDictionaryValueWithModel:(PTModel *)model;

/**
 * Initializes a `PTModel` instance's properties with the values in the given dictionary.
 * The dictionary should only contain keys found in the `propertyKeys` class property.
 *
 * @param dictionary the dictionary value used to set the receiver's properties
 *
 * @return a `PTModel` instance whose properties have been set to the values in the dictionary
 */
- (instancetype)initWithDictionary:(NSDictionary<NSString *, id> *)dictionary;

@end

/**
 * This `PTModel` category adds basic encoding and decoding support.
 */
@interface PTModel (NSCoding) <NSCoding>

@end

NS_ASSUME_NONNULL_END
