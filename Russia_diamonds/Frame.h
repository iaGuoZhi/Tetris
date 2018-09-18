#pragma once
#include<iostream>
#include<string>
using namespace std;
#include"Tool.h"
class Frame
{
public:
	const int UP = 5;
	const int BUTTOM = 20;
	const int LEFT = 18 ;
	const int RIGHT = 30;
	const int RIGHT2 = 46;
	const int RIGHT3 = 63;
	const int MIDDLE1 = 12;
	const int MIDDLE2 = 17;
	Frame();
	~Frame();
	
	void Draw_border();
	void Draw_message(string name);
	void Draw_score(int score,int level);
};

