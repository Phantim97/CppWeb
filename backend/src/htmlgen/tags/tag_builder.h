//
// Created by Timothy Coelho on 7/28/24.
//

#ifndef CPPWEB_TAG_BUILDER_H
#define CPPWEB_TAG_BUILDER_H
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <tuple>
#include <fstream>

struct Tag
{
	std::string name;
	std::string text;
	std::vector<Tag> children;
	std::vector<std::pair<std::string, std::string>> attributes;

	[[nodiscard]] std::string to_string() const
	{
		std::ostringstream os;
		os << "<" << name;

		for (const std::pair<std::string, std::string>& att : attributes)
		{
			os << " " << att.first << "=\"" << att.second << "\"";
		}

		if (children.empty() && text.empty())
		{
			os << "/>\n";
		}
		else
		{
			os << ">\n";

			if (!text.empty())
			{
				os << text << '\n';
			}

			for (const Tag& child : children)
			{
				os << child.to_string();
			}

			os << "</" << name << ">\n";
		}

		return os.str();
	}

	friend std::ostream& operator<<(std::ostream& os, const Tag& tag)
	{
		os << tag.to_string();
		return os;
	}

protected:
public:
	Tag(const std::string &name, const std::string &text) : name(name), text(text) {}
	Tag(const std::string &name, const std::vector<Tag> &children) : name(name), children(children) {}

};
#endif //CPPWEB_TAG_BUILDER_H
