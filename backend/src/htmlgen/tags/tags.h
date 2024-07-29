//
// Created by Timothy Coelho on 7/28/24.
//

#ifndef CPPWEB_TAGS_H
#define CPPWEB_TAGS_H

#include "tag_builder.h"

struct H1 : Tag
{
	H1(const std::string &text) : Tag("h1", text) {}
	H1(std::initializer_list<Tag> children) : Tag("h1", children) {}
};

struct H2 : Tag
{
	H2(const std::string &text) : Tag("h2", text) {}
	H2(std::initializer_list<Tag> children) : Tag("h2", children) {}
};

struct H3 : Tag
{
	H3(const std::string &text) : Tag("h3", text) {}
	H3(std::initializer_list<Tag> children) : Tag("h3", children) {}
};

struct H4 : Tag
{
	H4(const std::string &text) : Tag("h4", text) {}
	H4(std::initializer_list<Tag> children) : Tag("h4", children) {}
};

struct H5 : Tag
{
	H5(const std::string &text) : Tag("h5", text) {}
	H5(std::initializer_list<Tag> children) : Tag("h5", children) {}
};

struct H6 : Tag
{
	H6(const std::string &text) : Tag("h6", text) {}
	H6(std::initializer_list<Tag> children) : Tag("h6", children) {}
};

struct P : Tag
{
	P(const std::string &text) : Tag("p", text) {}
	P(std::initializer_list<Tag> children) : Tag("p", children) {}
};

struct DIV : Tag
{
	DIV() : Tag("div", "") {}
	DIV(std::initializer_list<Tag> children) : Tag("div", children) {}
};

struct IMG : Tag
{
	explicit IMG(const std::string url) : Tag("img", "")
	{
		attributes.emplace_back("src", url);
	}
};

struct BUTTON : Tag
{
	explicit BUTTON(const std::string& button_type, const std::string& button_text) : Tag("button", button_text)
	{
		attributes.emplace_back("type", button_type);
	}
};

struct INPUT : Tag
{
	explicit INPUT(const std::string& input_type, const std::string& input_text) : Tag("button", input_text)
	{
		attributes.emplace_back("type", input_type);
	}
};

struct SPAN : Tag
{
	SPAN(std::initializer_list<Tag> children) : Tag("span", children) {}
};

struct BR : Tag
{
	explicit BR() : Tag("br", ""){};
};

#endif //CPPWEB_TAGS_H
