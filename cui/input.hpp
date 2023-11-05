
#pragma once

#include "include.hpp"
#include "controls.hpp"

namespace Input {
	using namespace Controls;
	void* __input(void* arg) {
		HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
		DWORD mode;
		GetConsoleMode(hStdin, &mode);
		mode &= ~ENABLE_QUICK_EDIT_MODE;
		mode &= ~ENABLE_INSERT_MODE;
		SetConsoleMode(hStdin, mode);
		std::map<std::string, basic_controls*>::iterator it;
		while (true) {
			INPUT_RECORD m;
			ReadConsoleInputA(GetStdHandle(STD_INPUT_HANDLE), &m, 1, &mode);
			for (it = controls.begin(); it != controls.end(); it++) {
				if (it->second != NULL) {
					it->second->Event(m);
				}
			}
		}
	}
	void Start() {
		pthread_create(NULL, NULL, __input, NULL);
	}
}
