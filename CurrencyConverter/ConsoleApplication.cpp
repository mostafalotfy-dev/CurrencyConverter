#include "ConsoleApplication.h"
using namespace App;

ConsoleApp::ConsoleApp(int argc ,char *argv[]): cmdl(argv)
{
	cmdl.parse(argv);
	request = new SDK::HTTP("https://api.currencyfreaks.com/v2.0/rates/latest?apikey=" + API_KEY);
	currency_table = new Tables::CurrencyTable();
	
	if (argc == 1)
	{
		showHelp(true);
	}
	showHelp(false);
	rates();
	showSupported();
	showSymbols();
}



ConsoleApp::~ConsoleApp()
{
	delete request;
	delete currency_table;
}

void ConsoleApp::rates()
{
	
	if (cmdl[{"-r", "--rates"}])
	{
		Json::Value r = request->send()->json();
		
		std::cout << std::endl;
		currency_table->rates(r);
		currency_table->print(std::cout);
		std::cout << std::endl;
		
		
	}
}


void ConsoleApp::showHelp(bool show)
{
	if (cmdl[{"-h", "--help"}] || show)
	{
		Tables::HelpTable* table = new  Tables::HelpTable();
		table->print(std::cout);
		std::cout << std::endl;
		delete table;
	}
}

void App::ConsoleApp::showSupported()
{
	if (cmdl[{ "-sC", "--supported" }])
	{
		request = new SDK::HTTP("https://api.currencyfreaks.com/v2.0/supported-currencies");
		Json::Value json = request->send()->json();
		currency_table = new Tables::CurrencyTable();

		currency_table->supportedCurrency(json);
		currency_table->print(std::cout);
		std::cout << std::endl;
	}
}

void App::ConsoleApp::showSymbols()
{
	if (cmdl[{"-s", "--symbols"}])
	{
		request = new SDK::HTTP("https://api.currencyfreaks.com/v2.0/currency-symbols");
		Json::Value json = request->send()->json();
		currency_table = new Tables::CurrencyTable();
		currency_table->symbols(json);
		currency_table->print(std::cout);
	}
}

