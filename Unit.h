#pragma once
#include"Tool.h"
#include"Frame.h"
class Unit
{
private: int pos_x, pos_y;
		 char pic='#';
public:
	Unit(int x,int y);                  //只能是单字符
	~Unit();
	void show();
	int get_x();
	int get_y();
	void set_x(int x);
	void set_y(int y);
};

