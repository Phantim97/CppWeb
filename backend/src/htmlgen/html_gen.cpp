//
// Created by Timothy Coelho on 7/28/24.
//

#include "html_gen.h"
#include <fstream>

namespace html
{
	void generate_file(const std::string& file_name, const Tag& body)
	{
		const std::string boiler_plate_begin = "<!DOCTYPE html>\n<html lang=\"en\">\n"
		                                       "  <head>\n"
		                                       "    <meta charset=\"UTF-8\">\n"
		                                       "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n"
		                                       "    <meta http-equiv=\"X-UA-Compatible\" content=\"ie=edge\">\n"
		                                       "    <title>C++ Generated HTML</title>\n"
		                                       "    <link rel=\"stylesheet\" href=\"style.css\">\n"
		                                       "  </head>\n"
		                                       "  <body>";

		const std::string boiler_plate_end = "</body>\n"
		                                     "</html>";

		const std::string full_html = boiler_plate_begin + body.to_string() + boiler_plate_end;

		std::ofstream html_file(file_name);

		if (!html_file)
		{
			std::cerr << "Error opening file for writing: " << file_name << '\n';
			return;
		}

		html_file << full_html;

		if (html_file.fail())
		{
			std::cerr << "Error writing to file: " << file_name << '\n';
			return;
		}

		html_file.close();
		std::cout << "File generated: " << file_name << '\n';
	}
}