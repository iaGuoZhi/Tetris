#include "Unit.h"
#include<string>


Unit::Unit(int x,int y)
{
	pos_x = x;
	pos_y = y;
}


Unit::~Unit()
{
}

void Unit::show()
{
	Tool T;
	T.gotoxy(pos_x, pos_y);
	cout << pic;                                     //俄罗斯方块的组成使用#号
	return;
}

int Unit::get_x()
{
	return pos_x;
}

int Unit::get_y()
{
	return pos_y;
}

void Unit::set_x(int x)
{
	pos_x = x;
}

void Unit::set_y(int y)
{
	pos_y = y;
}
