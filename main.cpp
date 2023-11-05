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
int main()
{
	Render::Start(26,100);
	Input::Start();
	Button btn1;
	btn1.Name="BTN1";
	btn1.CoordX=30,btn1.CoordY=10;
	btn1.SizeX=40,btn1.SizeY=1;
	btn1.ForgColor=15,btn1.BackColor=0;
	btn1.MouseColor=7;
	btn1.Caption="Start";
	btn1.Join();
	while(1)
	{
	}
	return 0;
}
