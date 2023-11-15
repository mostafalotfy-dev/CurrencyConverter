#pragma once
#include "tabulate/table.hpp"
#include "cpr/cpr.h"
#include "json/json.h"
using namespace tabulate;
namespace Tables{
class CurrencyTable :
    public Table
{
protected:
    Row_t header = {
    "CurrencyID"
    };
    Color background_color = Color::green;
    Color font_background_color = Color::blue;
    void Header();
public:
    
    CurrencyTable();
    ~CurrencyTable();
    void Body(Json::Value body);
    
    

};

}