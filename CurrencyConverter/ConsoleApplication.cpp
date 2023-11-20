#include "ConsoleApplication.h"
using namespace App;

ConsoleApplication::ConsoleApplication(int argc ,char *argv[]): cmdl(argv)
{
	cmdl.parse(argv);
	request = new SDK::HTTP("https://api.currencyfreaks.com/v2.0/rates/latest?apikey=" + API_KEY);
	currency_table = new Tables::CurrencyTable();
	
	if (argc == 1)
	{
		showHelp(true);
	}
	showHelp(false);
	listCurrencies();
}


ConsoleApplication::~ConsoleApplication()
{
	delete request;
	delete currency_table;
}

void ConsoleApplication::listCurrencies()
{
	
	if (cmdl[{"-l", "--list"}])
	{
		Json::Value r = request->send()->json();
		
		std::cout << std::endl;
		currency_table->rates(r);
		
		currency_table->print(std::cout);
		
		
	}
}


void ConsoleApplication::showHelp(bool show)
{
	if (cmdl[{"-h", "--help"}] || show)
	{
		Tables::HelpTable* table = new  Tables::HelpTable();
		table->print(std::cout);
		std::cout << std::endl;
		delete table;
	}
}
