
#include "argh.h"
#include "HTTP.h"
#include "CurrencyTable.h"
#include "HelpTable.h"

using namespace SDK;
using namespace argh;
using namespace Tables;
namespace App {
	class ConsoleApp
	{
		
	private:
		const std::string API_KEY = "70a71fdbff0044e6abcb258300dfb55f";
		parser cmdl ;
		HTTP* request = nullptr;
		CurrencyTable* currency_table = nullptr;

	public:
		ConsoleApp(int argc ,char*  argv[]) ;
		~ConsoleApp();
		void listCurrencyRates();
		void showHelp(bool show);
		void supportedCurrencies();



	};
}
