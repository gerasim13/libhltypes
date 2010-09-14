/************************************************************************************\
* This source file is part of the High Level C++ types library                       *
* For latest info, see http://libhltypes.sourceforge.net/                            *
**************************************************************************************
* Copyright (c) 2010 Kresimir Spes, Boris Mikic, Domagoj Cerjan                      *
*                                                                                    *
* This program is free software; you can redistribute it and/or modify it under      *
* the terms of the BSD license: http://www.opensource.org/licenses/bsd-license.php   *
\************************************************************************************/
#ifndef _HLTYPES_HCONFIGFILE
#define _HLTYPES_HCONFIGFILE

#include <map>

#include "hltypesExport.h"
#include "hstring.h"
#include "hmap.h"

namespace hltypes
{
	class hltypesExport configfile
	{
		hstr filename;
		hmap<hstr, hstr> entries;
	public:
		configfile(chstr filename);
		configfile();
		~configfile();
		
		void read(chstr filename);
		
		chstr operator[](const char* var);
		chstr operator[](chstr var);
		void set(chstr key, chstr value);
		
		hmap<hstr, hstr>& _getInternalMap() { return this->entries; }
	};
}

typedef hltypes::configfile hcfgfile;

#endif

