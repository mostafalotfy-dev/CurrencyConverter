#pragma once
#include "argh.h"
#include "HTTP.h"
#include "CurrencyTable.h"
#include "HelpTable.h"
namespace App {
	class ConsoleApplication
	{
		const std::string API_KEY = "70a71fdbff0044e6abcb258300dfb55f";
	private:
		argh::parser cmdl;
		SDK::HTTP* request ;
		Tables::CurrencyTable* currency_table = nullptr;

	public:
		ConsoleApplication(int argc ,char * argv[]);
		~ConsoleApplication();
		void listCurrencies();
		void showHelp(bool show);



	};
}
