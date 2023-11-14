#include <string>
#include "json/json.h"
#include "Utils.h"

Json::Value Utils::Utils::parseJson(std::string text)
{
	Json::CharReaderBuilder builder;
	Json::CharReader* reader = builder.newCharReader();
	Json::Value root;
	std::string errors;
	bool parsingSuccessful = reader->parse(text.c_str(), text.c_str() + text.size(), &root, &errors);
	delete reader;
	return root;
}