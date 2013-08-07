//
//  MEDEdgeInsets.h
//  Archimedes
//
//  Created by Indragie Karunaratne on 8/6/2013.
//  Copyright (c) 2013 GitHub. All rights reserved.
//

#import <Foundation/Foundation.h>

#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
#import <UIKit/UIKit.h>
typedef UIEdgeInsets MEDEdgeInsets;
#elif TARGET_OS_MAC
#import <AppKit/AppKit.h>
typedef NSEdgeInsets MEDEdgeInsets;
#endif

// `MEDEdgeInsets` structure with all members set to 0.
extern MEDEdgeInsets const MEDEdgeInsetsZero;

// Returns an MEDEgeInsets struct with the given edge insets.
MEDEdgeInsets MEDEdgeInsetsMake(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right);

// Returns whether the two given `MEDEdgeInsets` are equal.
BOOL MEDEdgeInsetsEqualToEdgeInsets(MEDEdgeInsets insets1, MEDEdgeInsets insets2);

// Returns a rectangle adjusted by incrementing the origin and decrementing the size
// of the given rect by applying the given insets.
//
// The behaviour of this function differs between Mac and iOS in that the Y origin of
// the rect is incremented using the `top` member on iOS and the `bottom` member on Mac
// due to the default flippedness of drawing contexts on each platform.
CGRect MEDEdgeInsetsInsetRect(CGRect rect, MEDEdgeInsets insets);

// Returns a string formatted to contain data from an `MEDEdgeInsets` structure.
//
// This string can be passed into `MEDEdgeInsetsFromString()` to recreate the original
// `MEDEdgeInsets` structure.
NSString * NSStringFromMEDEdgeInsets(MEDEdgeInsets insets);

// Returns an `MEDEdgeInsets` structure corresponding to data in the given string
// or `MEDEdgeInsetsZero` if the string is not formatted appropriately.
//
// The string format is “{top, left, bottom, right}”, where each member of the
// `MEDEdgeInsets` structure is separated with a comma. This function should generally
// only be used to convert strings that were previously created using the
// `NSStringFromMEDEdgeInsets()` function.
MEDEdgeInsets MEDEdgeInsetsFromString(NSString *string);
