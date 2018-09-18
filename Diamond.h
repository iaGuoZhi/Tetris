#pragma once
#include"Frame.h"
#include<vector>
#include"Unit.h"
#include<ctime>
#include<cstdlib>
class Diamond
{
private:
	static const int LEVEL = 15;
	bool grid[17][19];
		vector<Unit> arrays;
		int Speed[LEVEL];
		int speed=700;
		int level = 0, scoretotal = 0;
public:
	Diamond();
	~Diamond();
	void create();
	void rotate();
	void show();
	void move();
	void shift();
	void set_speed(int m_speed);
	void control();
	int get_level();
	bool test();                // what function?
	int eliminate();
	bool judge_death();
	bool delay();
};

