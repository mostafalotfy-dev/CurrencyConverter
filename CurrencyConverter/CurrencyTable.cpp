#include "CurrencyTable.h"

using namespace Tables;
CurrencyTable::CurrencyTable()
{
	Header();


}

CurrencyTable::~CurrencyTable()
{

}

void Tables::CurrencyTable::rates(Json::Value body)
{
	auto rate_members = body["rates"].getMemberNames(); // get the keys of the rates

	Json::Value rates = body["rates"];
	for (auto& data : rate_members)
	{
		
		add_row({ data.c_str(),rates[data].asString()});
	}

	

}

void CurrencyTable::Header()
{
	add_row(header).format()
		.background_color(background_color)
		.font_background_color(font_background_color);

}


