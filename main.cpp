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
int main()
{
	Render::Start(26,100);
	Input::Start();
	while(1)
	{
	}
	return 0;
}
