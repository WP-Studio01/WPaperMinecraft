
#pragma once

#include "include.hpp"
#include "controls.hpp"
#include "render.hpp"

namespace Controls {
	class Text: public basic_controls { //�ؼ����ı�
		public:
			std::string Caption;
			short CoordX, CoordY; //����
			short ForgColor, BackColor; //��ɫ
			void Print(); //��Ⱦ����
			void Event(INPUT_RECORD); //���봦����
	};
	void Text::Print() {
		Window::gotoxy(CoordX, CoordY);
		Window::color(ForgColor, BackColor);
		Window::write(this->Caption.c_str());
	}
	void Text::Event(INPUT_RECORD ipt) {

	}
}
