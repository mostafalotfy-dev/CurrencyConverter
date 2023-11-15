#include "CurrencyTable.h"
#include <json/value.h>
using namespace Tables;
CurrencyTable::CurrencyTable()
{
	Header();
	
	
	
}

CurrencyTable::~CurrencyTable()
{
}

void Tables::CurrencyTable::Body(Json::Value body)
{
	auto rates = body["rates"].getMemberNames();
	for (auto const data : rates)
	{
		Json::FastWriter writer;
		std::string output = writer.write(data);
		add_row({ output });
		
	}
	print(std::cout);
	
}

void CurrencyTable::Header()
{
	add_row(header).format()
		.background_color(background_color)
		.font_background_color(font_background_color);
	
}


