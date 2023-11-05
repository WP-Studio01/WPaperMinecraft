#include"resource.h"
#include "cui/include.hpp"
#include "cui/render.hpp"
#include "cui/input.hpp"
#include "cui/button.hpp"
#include "cui/text.hpp"
#include "cui/textbox.hpp"
#define alert(str) MessageBox(NULL,str,"alert",MB_OK)
using namespace std;
using namespace Controls;
void CreateButton(Button & btn,string id,string text,
	short cx,short cy,short sx,short sy,
	short fc,short bc,short mc
);
void BTN1LeftClick();
void BTN1RightClick();
void BTN2LeftClick();
void BTN2RightClick();
INT_PTR CALLBACK LoginDialogProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
int main()
{
	Render::Start(26,100);
	Input::Start();
	Button btn1,btn2;
	CreateButton(btn1,"BTN1","start",35,10,30,1,15,0,7);
	btn1.LeftClicked=BTN1LeftClick;
	btn1.RightClicked=BTN1RightClick;
	CreateButton(btn2,"BTN2","exit", 35,14,30,1,15,0,7);
	btn2.LeftClicked=BTN2LeftClick;
	btn2.RightClicked=BTN2RightClick;
	btn1.Join();
	btn2.Join();
	while(1)
	{
	}
	return 0;
}
void CreateButton(Button & btn,string id,string text,
	short cx,short cy,short sx,short sy,
	short fc,short bc,short mc
)
{
	btn.Name=id;
	btn.CoordX=cx,btn.CoordY=cy;
	btn.SizeX=sx,btn.SizeY=sy;
	btn.ForgColor=fc,btn.BackColor=bc;
	btn.MouseColor=mc;
	btn.Caption=text;
}
void BTN1LeftClick()
{
	DialogBoxA(NULL,MAKEINTRESOURCE(IDD_DLG1),GetConsoleWindow(),LoginDialogProc);
}
void BTN2LeftClick()
{
	exit(0);
}
void BTN1RightClick()
{
	alert("No Right Click");
}
void BTN2RightClick()
{
	alert("No Right Click");
}
INT_PTR CALLBACK LoginDialogProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch(msg)
	{
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
	}
	return DefWindowProc(hwnd,msg,wParam,lParam);
}

