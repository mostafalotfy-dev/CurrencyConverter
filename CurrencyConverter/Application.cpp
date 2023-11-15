#include "Application.h"
using namespace App;

Application::Application(int argc ,char *argv[]): cmdl(argv)
{
	cmdl.parse(argv);
	request = new SDK::HTTP("https://api.currencyfreaks.com/v2.0/rates/latest?apikey=" + API_KEY);
	
	if (argc == 1)
	{
		showHelp(true);
	}
	showHelp(false);
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
		currency_table.print(std::cout);
		std::cout << std::endl;
	}
}


void Application::showHelp(bool show)
{
	if (cmdl[{"-h", "--help"}] || show)
	{
		Tables::HelpTable table =  Tables::HelpTable();
		table.print(std::cout);
		std::cout << std::endl;
	}
}
