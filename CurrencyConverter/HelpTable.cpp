#include "HelpTable.h"
using namespace Tables;
HelpTable::HelpTable()
{
	add_row({ "Key","Alias","Description"});
	add_row({ "-h","--help","Show This Messsage" });
	add_row({ "-l","--list","List All Currenciess" });
	format().background_color(Color::cyan).font_background_color(Color::blue);

}
