#include "CurrencyTable.h"

using namespace Tables;
CurrencyTable::CurrencyTable()
{
	


}

CurrencyTable::~CurrencyTable()
{

}

void Tables::CurrencyTable::rates(Json::Value body)
{
	Header();
	auto rate_members = body["rates"].getMemberNames(); // get the keys of the rates

	Json::Value rates = body["rates"];
	for (auto& data : rate_members)
	{
		
		add_row({ data.c_str(),rates[data].asString()});
	}

	

}

void Tables::CurrencyTable::supportedCurrency(Json::Value json)
{
	add_row({
		"Currency Code",
		"Currency Name",
		"Country Code",
		"Country Name",
		"Status",
		"Available From",
		"Available Until"
		});
	Json::Value supportedCurrencyMap = json["supportedCurrenciesMap"];
	auto keys = json["supportedCurrenciesMap"].getMemberNames();
	
	for (auto& key : keys)
	{
		auto supportedCurrency = supportedCurrencyMap[key];
		add_row({ supportedCurrency["currencyCode"].asString(),
				supportedCurrency["currencyName"].asString(),
			supportedCurrency["countryCode"].asString(),
			supportedCurrency["countryName"].asString(),
			supportedCurrency["status"].asString(),
			supportedCurrency["availableFrom"].asString(),
			supportedCurrency["availableUntil"].asString()
				});
	}
}

void Tables::CurrencyTable::symbols(Json::Value json)
{
	add_row({
		"Symbol"
		});
	auto keys = json["currencySymbols"];
	for (auto & key : keys)
	{
		add_row({ key.asString() });
	}
}


void CurrencyTable::Header()
{
	add_row(header).format()
		.background_color(background_color)
		.font_background_color(font_background_color);

}


