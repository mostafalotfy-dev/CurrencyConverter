#include "Application.h"
using namespace App;
Application::Application()
{
	request = SDK::HTTP::HTTP("");
	request.setBearer("");
	
}

void Application::listCurrencies()
{
	if (cmdl[{"-l", "--list"}])
	{
		request.send()->json();
	}
}

void Application::showHelp()
{
}
