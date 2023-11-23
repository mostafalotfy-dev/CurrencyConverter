#include "HelpTable.h"
using namespace Tables;
HelpTable::HelpTable()
{
	add_row({ "Key","Alias","Description"});
	add_row({ "-h","--help","Show This Message" });
	add_row({ "-r","--rates","List All Currencies rate" });
	format().background_color(Color::cyan).font_background_color(Color::blue)
		.border_background_color(Color::green);

}
