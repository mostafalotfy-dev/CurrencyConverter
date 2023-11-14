#include "cpr/cpr.h"
#include "json/json.h"
namespace SDK {
	class HTTP
	{
	
	private:
		std::string token = "";
		cpr::Url url;
		HTTP();
	public:
		
		HTTP(std::string url);
		~HTTP();
		HTTP* setBearer(std::string token);
		Json::Value send();


	};
}

