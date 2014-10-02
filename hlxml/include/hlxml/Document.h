/// @file
/// @version 3.0
/// 
/// @section LICENSE
/// 
/// This program is free software; you can redistribute it and/or modify it under
/// the terms of the BSD license: http://opensource.org/licenses/BSD-3-Clause
/// 
/// @section DESCRIPTION
/// 
/// Represents an XML document.

#ifndef HLXML_DOCUMENT_H
#define HLXML_DOCUMENT_H

#include <hltypes/hltypesUtil.h>
#include <hltypes/hstring.h>
#include <hltypes/hmap.h>

#include "hlxmlExport.h"

class TiXmlDocument;
class TiXmlNode;

namespace hlxml
{
	extern hstr logTag;

	class Node;
	
	/// @brief Represents an XML document.
	class hlxmlExport Document
	{
	public:
		friend class Node;

		/// @brief Constructor
		/// @param[in] filename Filename where to read from.
		Document(chstr filename);
		/// @brief Destructor
		~Document();

		HL_DEFINE_GET(hstr, filename, Filename);

		/// @brief Gets the root Node of the Document.
		/// @param[in] type Optional type check.
		/// @note Throws an exception if type is not an empty String and the root Node is not of that type.
		Node* root(chstr type = "");

	protected:
		/// @brief The TinyXML document.
		TiXmlDocument* document;
		/// @brief Filename of the Document.
		hstr filename;
		/// @brief The root Node of the Document.
		Node* rootNode;
		/// @brief A list of all TinyXML nodes and their associated Nodes.
		hmap<TiXmlNode*, Node*> nodes;

		/// @brief Gets the Node associated with the TinyXML node.
		/// @param[in] node The TinyXML node.
		/// @return The Node associated with the TinyXML node.
		Node* _node(TiXmlNode* node);

	};
}

#endif
