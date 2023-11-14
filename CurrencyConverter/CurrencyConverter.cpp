#include "HTTP.h"
#include <iostream>
int main()
{
	SDK::HTTP http = SDK::HTTP::HTTP("http://echo.jsontest.com/key/value/one/two");
	std::cout<< http.send();

}
