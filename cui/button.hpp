
#pragma once

#include "include.hpp"
#include "controls.hpp"
#include "render.hpp"

namespace Controls {
	class Button: public basic_controls { //控件：按钮
		private:
			bool MouseIn;
		public:
			Button();
			std::string Caption;
			short CoordX, CoordY; //坐标
			short ForgColor, BackColor, MouseColor; //颜色
			short SizeX, SizeY; //大小
			void Print(); //渲染函数
			void Event(INPUT_RECORD); //输入处理函数
			void (*LeftClicked)(); //被左键单击处理函数
			void (*RightClicked)(); //被左键单击处理函数
	};
	Button::Button() { //初始化
		MouseIn = false;
		this->LeftClicked = NULL;
		this->RightClicked = NULL;
	}
	void Button::Print() {
		Window::gotoxy(CoordX, CoordY);
		if (MouseIn == false) {
			Window::color(ForgColor, BackColor);
		} else {
			Window::color(ForgColor, MouseColor);
		}
		for (int i = 0; i < SizeY; i++) {
			Window::gotoxy(CoordX, CoordY + i);
			for (int j = 0; j < SizeX; j++) {
				Window::write(" ");
			}
		}
		Window::gotoxy(CoordX + (SizeX - this->Caption.size()) / 2, CoordY + SizeY / 2);
		Window::write(this->Caption.c_str());
	}
	void Button::Event(INPUT_RECORD ipt) {
		if (ipt.EventType == MOUSE_EVENT) {
			COORD c = ipt.Event.MouseEvent.dwMousePosition;
			if (c.X >= CoordX && c.X < CoordX + SizeX && c.Y >= CoordY && c.Y < CoordY + SizeY) {
				MouseIn = true;
				switch (ipt.Event.MouseEvent.dwButtonState) {
					case FROM_LEFT_1ST_BUTTON_PRESSED:
						if (this->LeftClicked != NULL) {
							this->LeftClicked();
						}
						break;
					case RIGHTMOST_BUTTON_PRESSED:
						if (this->RightClicked != NULL) {
							this->RightClicked();
						}
						break;
				}
			} else {
				MouseIn = false;
			}
		}
	}
}
