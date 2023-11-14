#include "CurrencyTable.h"

CurrencyTable::CurrencyTable()
{
	Header();
	print(std::cout);
	std::cout << std::endl;
}

CurrencyTable::~CurrencyTable()
{
}

void CurrencyTable::Header()
{
	add_row(header).format()
		.background_color(background_color)
		.font_background_color(font_background_color);
	
}


