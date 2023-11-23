#include "HTTP.h"
#include "Utils.h"
#include <iostream>
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

SDK::HTTP* SDK::HTTP::send() {

	cpr::Response response = cpr::Get(url_, cpr::Header{ {"Authentication",token} }, cpr::ProgressCallback([&](cpr::cpr_off_t downloadTotal, cpr::cpr_off_t downloadNow, cpr::cpr_off_t uploadTotal,cpr::cpr_off_t uploadNow, intptr_t userdata) -> bool
		{
			std::cout << "Loading... " << downloadNow << " / " << downloadTotal << " bytes." << std::endl;
			return true;
		}));


	

	responseText = response.text;
	return this;
	
}
Json::Value SDK::HTTP::json() const 
{
	return Utils::Utils::parseJson(responseText);
}
std::string SDK::HTTP::text()
{
	if (responseText.empty())
	{
		throw "Empty Response.";
	}
	return responseText;
}
SDK::HTTP* SDK::HTTP::setBearer(std::string token)
{
	this->token = "apitoken: " + token;
	return this;
}
