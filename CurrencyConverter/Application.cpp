#include "Application.h"
using namespace App;

Application::Application(char *argv[]): cmdl(argv)
{
	cmdl.parse(argv);
	request = new SDK::HTTP("https://api.currencyfreaks.com/v2.0/rates/latest?apikey=" + API_KEY);
	listCurrencies();
}


App::Application::~Application()
{
	delete request;
}

void Application::listCurrencies()
{
	
	if (cmdl[{"-l", "--list"}])
	{
		Json::Value r = request->send()->json();
	
		currency_table.Body(r);
	}
}


void Application::showHelp()
{
	if (cmdl[{"-h", "--help"}] )
	{

	}
}
