#pragma once
#include <string>
#include "json/json.h"
namespace Utils {
	class Utils {
	public:
		static Json::Value parseJson(std::string text);
	};
}