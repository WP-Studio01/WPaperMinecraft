
#pragma once

#include "include.hpp"
#include "controls.hpp"
#include "render.hpp"

namespace Controls {
	class TextBox: public basic_controls { //�ؼ����ı�
		private:
			bool Focus; //�Ƿ��ڽ�����
			clock_t StartTime;
		public:
			TextBox();
			std::string Text; //�ı�
			short CoordX, CoordY, Length; //���꣬��󳤶�
			short ForgColor, BackColor; //��ɫ
			void Print(); //��Ⱦ����
			void Event(INPUT_RECORD); //���봦����
	};
	TextBox::TextBox() {
		Focus = false;
		Text = "";
		StartTime = clock();
	}
	void TextBox::Print() {
		Window::gotoxy(CoordX, CoordY);
		Window::color(ForgColor, BackColor);
		std::string tmp = Text;
		if (Focus == true) {
			if ((clock() - StartTime) / 100 % 10 >= 0 && (clock() - StartTime) / 100 % 10 < 5) {
				tmp += "|";
			} else {
				tmp += " ";
			}
		}
		if (tmp.length() - Length > 0 && tmp.length() - Length < tmp.length()) {
			tmp = tmp.substr(tmp.length() - Length);
			int sum = 0;
			for (int i = 0; i < tmp.size(); i++) {
				if (tmp[i] < 0 || tmp[i] >= 128) {
					sum++;
				} else {
					break;
				}
			}
			if (sum % 2 == 1) {
				tmp.erase(0, 1);
			}
		}
		while (tmp.length() < Length) {
			tmp += " ";
		}
		Window::write(tmp.c_str());
	}
	void TextBox::Event(INPUT_RECORD ipt) {
		if (ipt.EventType == MOUSE_EVENT) {
			COORD c = ipt.Event.MouseEvent.dwMousePosition;
			switch (ipt.Event.MouseEvent.dwButtonState) {
				case FROM_LEFT_1ST_BUTTON_PRESSED:
					if (c.X >= CoordX && c.X < CoordX + Length && c.Y >= CoordY && c.Y < CoordY + 1) {
						Focus = true;
					} else {
						Focus = false;
					}
					break;
				case RIGHTMOST_BUTTON_PRESSED:
					if (c.X >= CoordX && c.X < CoordX + Length && c.Y >= CoordY && c.Y < CoordY + 1) {
						Focus = true;
					} else {
						Focus = false;
					}
					break;
			}
		}
		if (ipt.EventType == KEY_EVENT && Focus == true) {
			if (ipt.Event.KeyEvent.bKeyDown == true && ipt.Event.KeyEvent.wRepeatCount == 1) {
				char key = ipt.Event.KeyEvent.uChar.AsciiChar;
				if (key == VK_BACK) {
					if (Text.length() > 0) {
						if (Text[Text.length() - 1] < 0 || Text[Text.length() - 1] >= 128) {
							Text.erase(Text.size() - 2);
						} else {
							Text.erase(Text.size() - 1);
						}
					}
				} else {
					if (isprint(key)) {
						Text += key;
					} else if (key < 0 || key >= 128) {
						Text += key;
					}
				}
			}
		}
	}
}
