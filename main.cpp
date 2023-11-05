#include<iostream>
#include<windows.h>
#include"resource.h"
#include "cui/include.hpp"
#include "cui/render.hpp"
#include "cui/input.hpp"
#include "cui/button.hpp"
#include "cui/text.hpp"
#include "cui/textbox.hpp"
using namespace std;
using namespace Controls;
void CreateButton(Button & btn,string id,string text,
	short cx,short cy,short sx,short sy,
	short fc,short bc,short mc
);
int main()
{
	Render::Start(26,100);
	Input::Start();
	Button btn1,btn2;
	CreateButton(btn1,"BTN1","start",35,10,30,1,15,0,7);
	CreateButton(btn2,"BTN2","exit", 35,14,30,1,15,0,7);
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

