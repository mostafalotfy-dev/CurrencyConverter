#include "HelpTable.h"
using namespace Tables;
HelpTable::HelpTable()
{
	add_row({ "Key","Alias","Description"});
	add_row({ "-h","--help","Show This Messsage" });
	add_row({ "-r","--rates","List Currencies Rates Currenciess" });
	add_row({ "-sC","Show Supported Currencies With Details" });
	add_row({ "-s","Show Supported Sympols" });
		format().background_color(Color::cyan).font_background_color(Color::blue)
		.border_background_color(Color::green);
}
