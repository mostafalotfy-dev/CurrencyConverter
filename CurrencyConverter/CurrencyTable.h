#pragma once
#include "tabulate/table.hpp"
#include "cpr/cpr.h"
using namespace tabulate;
namespace Tables{
class CurrencyTable :
    public Table
{
protected:
    Row_t header = {
    "Id","Currency Name"
    };
    Color background_color = Color::green;
    Color font_background_color = Color::blue;
public:
    
    CurrencyTable();
    ~CurrencyTable();
    void Header();
    

};

}