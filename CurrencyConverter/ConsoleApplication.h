#pragma once
#include "argh.h"
#include "HTTP.h"
#include "CurrencyTable.h"
#include "HelpTable.h"
namespace App {
	class ConsoleApp
	{
		const std::string API_KEY = "70a71fdbff0044e6abcb258300dfb55f";
	private:
		argh::parser cmdl;
		SDK::HTTP* request ;
		Tables::CurrencyTable* currency_table = nullptr;

	public:
		ConsoleApp(int argc ,char * argv[]);
		~ConsoleApp();
		void rates();
		void showHelp(bool show);
		void showSupported();
		void showSymbols();



	};
}
