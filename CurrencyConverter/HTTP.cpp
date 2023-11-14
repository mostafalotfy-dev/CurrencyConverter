#include "HTTP.h"
#include "Utils.h"
SDK::HTTP::HTTP(std::string url)
{
	this->url = cpr::Url{ url };
}
SDK::HTTP::~HTTP() {

}

Json::Value SDK::HTTP::send() {

	
	cpr::Response response = cpr::Get(url, cpr::Header{ {"Authentication",token} });
	
	std::string text = response.text;
	return Utils::Utils::parseJson(text);
	
}
SDK::HTTP* SDK::HTTP::setBearer(std::string token)
{
	this->token = "apitoken: " + token;
	return this;
}
