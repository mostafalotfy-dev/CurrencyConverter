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
		
		std::cout << data << "\t\t" << rates[data] << "\t\t" << std::endl;
	}

	

}

void CurrencyTable::Header()
{
	add_row(header).format()
		.background_color(background_color)
		.font_background_color(font_background_color);

}


