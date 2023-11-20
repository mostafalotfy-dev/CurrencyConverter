#pragma once
#include "tabulate/table.hpp"
#include "cpr/cpr.h"
#include "json/json.h"
#include <json/value.h>
using namespace tabulate;
namespace Tables
{
class CurrencyTable :
    public Table
{
protected:
    Row_t header = {
    "CurrencyID","Currency Value"
    };
    Color background_color = Color::white;
    Color font_background_color = Color::none;
    void Header();
public:
    CurrencyTable();
    ~CurrencyTable();
    void rates(Json::Value body);
 
};

}