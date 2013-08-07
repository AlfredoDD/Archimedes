//
//  MEDEdgeInsets.m
//  Archimedes
//
//  Created by Indragie Karunaratne on 8/6/2013.
//  Copyright (c) 2013 GitHub. All rights reserved.
//

#import "MEDEdgeInsets.h"

MEDEdgeInsets MEDEdgeInsetsMake(CGFloat top, CGFloat left, CGFloat bottom, CGFloat right) {
	return (MEDEdgeInsets){top, left, bottom, right};
}

BOOL MEDEdgeInsetsEqualToEdgeInsets(MEDEdgeInsets insets1, MEDEdgeInsets insets2) {
	return (fabs(insets1.top - insets2.top) < 0.1) &&
		   (fabs(insets1.left - insets2.left) < 0.1) &&
		   (fabs(insets1.bottom - insets2.bottom) < 0.1) &&
		   (fabs(insets1.right - insets2.right) < 0.1);
}

CGRect MEDEdgeInsetsInsetRect(CGRect rect, MEDEdgeInsets insets) {
	rect.origin.x += insets.left;
#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
	rect.origin.y += insets.top;
#elif TARGET_OS_MAC
	rect.origin.y += insets.bottom;
#endif
	rect.size.height -= (insets.top + insets.bottom);
	rect.size.width -= (insets.left + insets.right);
	return rect;
	
}

NSString * NSStringFromMEDEdgeInsets(MEDEdgeInsets insets) {
	return [NSString stringWithFormat:@"{%g, %g, %g, %g}", insets.top, insets.left, insets.bottom, insets.right];
}

MEDEdgeInsets MEDEdgeInsetsFromString(NSString *string) {
	MEDEdgeInsets insets = MEDEdgeInsetsZero;
	if (string) {
#ifdef __IPHONE_OS_VERSION_MIN_REQUIRED
		sscanf(string.UTF8String, "{%g, %g, %g, %g}", &insets.top, &insets.left, &insets.bottom, &insets.right);
#elif TARGET_OS_MAC
		sscanf(string.UTF8String, "{%lg, %lg, %lg, %lg}", &insets.top, &insets.left, &insets.bottom, &insets.right);
#endif
	}
	return insets;
}