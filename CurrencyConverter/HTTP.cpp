#include "HTTP.h"
#include "Utils.h"
SDK::HTTP::HTTP()
{
}
SDK::HTTP::HTTP(std::string url)
{
	url_ = cpr::Url{ url };
}
SDK::HTTP::~HTTP()
{
	
}

SDK::HTTP* SDK::HTTP::send()  {

	
	cpr::Response response = cpr::Get(url_, cpr::Header{ {"Authentication",token} });
	
	responseText = response.text;
	return this;
	
}
Json::Value SDK::HTTP::json()
{
	return Utils::Utils::parseJson(responseText);
}
std::string SDK::HTTP::text()
{
	return responseText;
}
SDK::HTTP* SDK::HTTP::setBearer(std::string token)
{
	this->token = "apitoken: " + token;
	return this;
}
