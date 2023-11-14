#pragma once
#include "argh.h"
#include "HTTP.h"
#include "CurrencyTable.h"
namespace App {
	class Application
	{
	private:
		argh::parser cmdl;
		SDK::HTTP request;
		Tables::CurrencyTable currency_table;

	public:
		Application();
		void listCurrencies();
		void showHelp();



	};
}
