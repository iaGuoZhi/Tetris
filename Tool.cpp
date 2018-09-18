#include "Tool.h"
#include<Windows.h>


Tool::Tool()
{
}


Tool::~Tool()
{
}

void Tool::gotoxy(int x, int y)
{
	COORD coor;
	coor.X = x;
	coor.Y = y;
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(handle, coor);
}