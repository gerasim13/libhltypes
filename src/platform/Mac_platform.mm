/// @file
/// @author  Boris Mikic
/// @author  Kresimir Spes
/// @version 2.2
///
/// @section LICENSE
///
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php

#import <Foundation/Foundation.h>

#include "hplatform.h"
#include "hstring.h"

namespace hltypes
{
	void _platform_print(const String& tag, const String& message, int level)
	{
		if (tag != "")
		{
			NSLog(@"[%s] %s", tag.c_str(), message.c_str());
		}
		else
		{
			NSLog(@"%s", message.c_str());
		}
	}
	
}
