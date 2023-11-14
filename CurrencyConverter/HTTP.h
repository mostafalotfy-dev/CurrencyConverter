#include "cpr/cpr.h"
#include "json/json.h"
namespace SDK {
	class HTTP
	{
	
	private:
		std::string token = "";
		cpr::Url url_;
		std::string responseText;
		
	public:
		HTTP();
		HTTP(std::string url);
		~HTTP();
		HTTP* setBearer(std::string token);
		HTTP* send() ;
		Json::Value json();
		std::string text();

	};
}

