//
// Created by Timothy Coelho on 7/28/24.
//

#ifndef CPPWEB_HTML_GEN_H
#define CPPWEB_HTML_GEN_H
#include "tags/tag_builder.h"
#include "tags/tags.h"

namespace html
{
	void generate_file(const std::string& file_name, const Tag& body);
}
#endif //CPPWEB_HTML_GEN_H
