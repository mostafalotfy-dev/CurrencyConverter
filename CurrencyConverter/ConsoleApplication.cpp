#include "ConsoleApplication.h"
using namespace App;

ConsoleApplication::ConsoleApplication(int argc ,char *argv[]): cmdl(argv)
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


App::ConsoleApplication::~ConsoleApplication()
{
	delete request;
}

void ConsoleApplication::listCurrencies()
{
	
	if (cmdl[{"-l", "--list"}])
	{
		Json::Value r = request->send()->json();
	
		currency_table.Body(r);
		currency_table.print(std::cout);
		std::cout << std::endl;
	}
}


void ConsoleApplication::showHelp(bool show)
{
	if (cmdl[{"-h", "--help"}] || show)
	{
		Tables::HelpTable table =  Tables::HelpTable();
		table.print(std::cout);
		std::cout << std::endl;
	}
}
