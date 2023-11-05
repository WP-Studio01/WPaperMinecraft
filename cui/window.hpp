
#pragma once

#include "include.hpp"

namespace Window {
	void SetTitle(std::string str) {
		SetConsoleTitleA(str.c_str());
	}
}
