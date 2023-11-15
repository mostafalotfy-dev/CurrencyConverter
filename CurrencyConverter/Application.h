#pragma once
#include "argh.h"
#include "HTTP.h"
#include "CurrencyTable.h"
#include "HelpTable.h"
namespace App {
	class Application
	{
		const std::string API_KEY = "70a71fdbff0044e6abcb258300dfb55f";
	private:
		argh::parser cmdl;
		SDK::HTTP* request ;
		Tables::CurrencyTable currency_table;

	public:
		Application(char * argv[]);
		~Application();
		void listCurrencies();
		void showHelp();



	};
}
