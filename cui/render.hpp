
#pragma once

#include "include.hpp"
#include "controls.hpp"
#include "window.hpp"
#include <pthread.h>

namespace Render {
	using namespace Controls;
	HANDLE stdbuf = GetStdHandle(STD_OUTPUT_HANDLE);
	void __clrscr() { //�������ڲ�ʹ�ã�
		HANDLE hdout = Render::stdbuf;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(hdout, &csbi);
		DWORD size = csbi.dwSize.X * csbi.dwSize.Y, num = 0;
		COORD pos = {0, 0};
		FillConsoleOutputCharacterA(hdout, ' ', size, pos, &num);
		FillConsoleOutputAttribute(hdout, 255, size, pos, &num );
		SetConsoleCursorPosition(hdout, pos);
	}
	COORD Size;
	void __setsize(SHORT width, SHORT height) {
		HANDLE hStdOutput = Render::stdbuf;
		SMALL_RECT wrt = {0, 0, short(width - 1), short(height - 1)};
		SetConsoleWindowInfo(hStdOutput, TRUE, &wrt);
		COORD coord = {width, height};
		SetConsoleScreenBufferSize(hStdOutput, coord);
	}
	void* __render(void* arg) { //��Ⱦ���̣�˫���壩
		std::map<std::string, basic_controls*>::iterator it;
		HANDLE buf1 = GetStdHandle(STD_OUTPUT_HANDLE);
		HANDLE buf2 = CreateConsoleScreenBuffer(
		                  GENERIC_READ | GENERIC_WRITE,
		                  FILE_SHARE_READ | FILE_SHARE_WRITE,
		                  NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		CONSOLE_CURSOR_INFO CursorInfo;
		GetConsoleCursorInfo(buf1, &CursorInfo);
		CursorInfo.bVisible = false;
		SetConsoleCursorInfo(buf1, &CursorInfo);
		GetConsoleCursorInfo(buf2, &CursorInfo);
		CursorInfo.bVisible = false;
		SetConsoleCursorInfo(buf2, &CursorInfo);
		while (true) {
			//buf1����
			__setsize(Size.Y, Size.X);
			stdbuf = buf1;
			__clrscr();
			for (it = controls.begin(); it != controls.end(); it++) {
				if (it->second != NULL) {
					it->second->Print();
				}
			}
			SetConsoleActiveScreenBuffer(buf1);
			//buf2����
			__setsize(Size.Y, Size.X);
			stdbuf = buf2;
			__clrscr();
			for (it = controls.begin(); it != controls.end(); it++) {
				if (it->second != NULL) {
					it->second->Print();
				} else {
					controls.erase(it);
				}
			}
			SetConsoleActiveScreenBuffer(buf2);
		}
	}
	void Start(short SizeX, short SizeY) { //��ʼ��Ⱦ
		Size.X = SizeX, Size.Y = SizeY;
		pthread_create(NULL, NULL, __render, NULL);
	}
}

namespace Window { //���Զ���Ӧ��������
	void write(const char* str) { //���
		WriteConsoleA(Render::stdbuf, str, strlen(str), NULL, NULL);
	}
	void gotoxy(short x, short y) { //�޸Ĺ��λ��
		COORD coord = {x, y};
		SetConsoleCursorPosition(Render::stdbuf, coord);
	}
	void color(int ForgC, int BackC) { //������ɫ����
		WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
		SetConsoleTextAttribute(Render::stdbuf, wColor);
	}
	void color(int ForgC) { //������ɫ����
		WORD wColor;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		if (GetConsoleScreenBufferInfo(Render::stdbuf, &csbi)) {
			wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
			SetConsoleTextAttribute(Render::stdbuf, wColor);
		}
	}
}
