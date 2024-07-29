#include <iostream>
#include <crow.h>
#include <fstream>
#include <unordered_map>
#include "htmlgen/html_gen.h"

const std::unordered_map<std::string, std::string> mime_types = {
		{"html", "text/html"},
		{"js", "application/javascript"},
		{"css", "text/css"},
		{"png", "image/png"},
		{"jpg", "image/jpeg"},
		{"svg", "image/svg+xml"},
		{"wasm", "application/wasm"}
};

std::string get_mime_type(const std::string& path)
{
	const size_t dot_pos = path.rfind('.');
	if (dot_pos != std::string::npos)
	{
		typedef std::unordered_map<std::string, std::string>::const_iterator map_iter;
		std::string extension = path.substr(dot_pos + 1);
		map_iter it = mime_types.find(extension);

		if (it != mime_types.end())
		{
			return it->second;
		}
	}

	return "application/octet-stream";
}

void serve_file(const std::string& full_path, crow::response& res)
{
	std::ifstream in(full_path, std::ios::in | std::ios::binary);
	if (in)
	{
		std::ostringstream contents;
		contents << in.rdbuf();
		in.close();
		res.code = 200;
		res.set_header("Content-Type", get_mime_type(full_path));
		res.write(contents.str());
	}
	else
	{
		res.code = 404;
		res.write("404 Not Found");
	}

	res.end();
}

int main()
{
	crow::SimpleApp app;

	// Route to serve the main index.html for the frontend
	CROW_ROUTE(app, "/")
			([](const crow::request& req, crow::response& res){
				serve_file("../../frontend/dist/index.html", res);
			});

	CROW_ROUTE(app, "/generate-1")
			([](const crow::request& req, crow::response& res){
				std::string path = "../../frontend/dist/generated1.html";
				const Tag full = DIV {H1 {"Test"}, P {"This is a sample"}, BUTTON{ "button", "CLICK HERE"}};
				html::generate_file(path, full);
				serve_file(path, res);
			});

	CROW_ROUTE(app, "/generate-2")
			([](const crow::request& req, crow::response& res){
				std::string path = "../../frontend/dist/generated2.html";
				const Tag full = DIV {H1 {"Another Test"}, P {"Also Generated from C++"}, BUTTON{ "button", "CLICK HERE"}};
				html::generate_file(path, full);
				serve_file(path, res);
			});

	// Serve static files (Generic Pathing)
	CROW_ROUTE(app, "/<path>")
			([](const crow::request& req, crow::response& res, std::string path){
				serve_file("../../frontend/dist/" + path, res);
			});

	app.bindaddr("127.0.0.1").port(18080).multithreaded().run();
}