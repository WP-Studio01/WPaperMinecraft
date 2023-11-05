
#pragma once

#include "include.hpp"
#include "controls.hpp"
#include "render.hpp"

namespace Controls {
	class Text: public basic_controls { //控件：文本
		public:
			std::string Caption;
			short CoordX, CoordY; //坐标
			short ForgColor, BackColor; //颜色
			void Print(); //渲染函数
			void Event(INPUT_RECORD); //输入处理函数
	};
	void Text::Print() {
		Window::gotoxy(CoordX, CoordY);
		Window::color(ForgColor, BackColor);
		Window::write(this->Caption.c_str());
	}
	void Text::Event(INPUT_RECORD ipt) {

	}
}
