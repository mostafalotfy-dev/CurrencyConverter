#include "ConsoleApplication.h"
using namespace App;
using namespace SDK;

ConsoleApp::ConsoleApp(int argc, char* argv[]) 
{
	cmdl.parse(argv);
	request = new  HTTP("https://api.currencyfreaks.com/v2.0/rates/latest?apikey=" + API_KEY);
	currency_table = new CurrencyTable();

	if (argc == 1)
	{
		showHelp(true);
	}
	showHelp(false);
	listCurrencyRates();
	supportedCurrencies();
	
}


ConsoleApp::~ConsoleApp()
{
	delete request;
	delete currency_table;
}

void ConsoleApp::listCurrencyRates()
{

	if (cmdl[{"-r", "--rates"}])
	{
		Json::Value r = request->send()->json();

		std::cout << std::endl;
		currency_table->rates(r["rates"]);

		currency_table->print(std::cout);


	}
}


void ConsoleApp::showHelp(bool show)
{
	if (cmdl[{"-h", "--help"}] || show)
	{
		HelpTable* table = new  Tables::HelpTable();
		table->print(std::cout);
		std::cout << std::endl;
		delete table;
	}
}

void App::ConsoleApp::supportedCurrencies()
{
	if (cmdl[{"-sC", "--supportedCurrencies"}])
	{
		
		request = new HTTP("https://api.currencyfreaks.com/v2.0/supported-currencies");
		Json::Value response = request->send()->json();
		currency_table->supportedCurrency(response["supportedCurrenciesMap"]);
		currency_table->print(std::cout);

	}
}
