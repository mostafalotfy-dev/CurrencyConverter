#include "CurrencyTable.h"
using namespace Tables;

CurrencyTable::CurrencyTable()
{



}

CurrencyTable::~CurrencyTable()
{

}

void CurrencyTable::rates(Json::Value body)
{
	Header();
	auto keys = body.getMemberNames(); // get the keys of the rates


	for (auto& key : keys)
	{

		add_row({ key.c_str(),body[key].asString() });
	}



}
void CurrencyTable::supportedCurrency(Json::Value body)
{
	auto keys = body.getMemberNames();
	add_row({ "Currency Code",
		"Country Code"
		,"Country Name"
		,"Status"
		,"Available From"
		,"Available Until" });
	for (auto& key : keys)
	{
		auto index = body[key];

		add_row({ index["currencyCode"].asString(),
			index["countryCode"].asString(),
			index["countryName"].asString(),
			index["status"].asString(),
			index["availableFrom"].asString(),
			index["availableUntil"].asString()
			});
	}
}

void CurrencyTable::Header()
{
	add_row(header).format()
		.background_color(background_color)
		.font_background_color(font_background_color);

}


