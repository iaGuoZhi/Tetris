#include "Diamond.h"
#include<Windows.h>
#include<conio.h>
Diamond::Diamond()
{
	Frame F;
	grid[F.RIGHT - F.LEFT - 1][F.BUTTOM - F.UP - 1];              //有方块是true，没有是false
	for (int i = 0; i <= F.RIGHT - F.LEFT - 2; ++i)
	{
		for (int j = 0; j <= F.BUTTOM - F.UP - 2; ++j)
		{
			grid[i][j] = false;
		}
	}
	for (int i = 0; i < 13; ++i)
	{
		Speed[i] = 700 - 30 * i;
	}
	for (int i = 13; i < LEVEL; ++i)
	{
		Speed[i] = 300;                                                   //制作速度等级数组
	}
	F.Draw_score(0, 0);
}
Diamond::~Diamond()
{
}
void Diamond::create()
{
	Frame F;
	Tool T;
	int key;
	int base_point;
	int rotate_time=0;
	srand(time(NULL));                                            
	base_point = ( F.RIGHT-F.LEFT) / 2;
	key = rand() % 5;                                             //随机出形状
	rotate_time = rand() % 9;                                     //随机旋转原始形状，已达到丰富的目的
	arrays.clear();                                              //为了降低难度，每个图形出现的比例应该不一样
	switch(key)
	{
	case 0:
		arrays.clear();
		for (int i = 0; i < 4; ++i)
		{
			Unit unit(i + F.LEFT+base_point+1, F.UP + 1);             //****型
			arrays.push_back(unit);
		}
		for (int i = 0; i < rotate_time; ++i)
		{
			rotate();
		}
		break;
	case 1:case 5:case 6:
		arrays.clear();
		for (int i = 0; i < 2; ++i)
		{
			for (int j = 0; j < 2; ++j)
			{
				Unit unit(i + F.LEFT + base_point + 1, F.UP + 1 + j);    //正方形
				arrays.push_back(unit);
			}
		}
		break;
	case 2:case 7:                                                        //枪形
		arrays.clear();
		arrays.push_back(Unit(F.LEFT + base_point + 1, F.UP + 1));
		arrays.push_back(Unit (F.LEFT + base_point+2, F.UP + 1));
		arrays.push_back(Unit (F.LEFT + base_point + 3, F.UP + 1));
		arrays.push_back(Unit(F.LEFT + base_point + 3, F.UP + 2));
		for (int i = 0; i < rotate_time; ++i)
		{
			rotate();
		}
		break;
	case 3:                                                          //梯形
		arrays.clear();
		arrays.push_back(Unit(F.LEFT + base_point + 1, F.UP + 1));
		arrays.push_back(Unit(F.LEFT + base_point+1, F.UP + 2));
		arrays.push_back(Unit(F.LEFT + base_point + 2, F.UP + 2));
		arrays.push_back(Unit(F.LEFT + base_point + 2, F.UP + 3));
		for (int i = 0; i < rotate_time; ++i)
		{
			rotate();
		}
		break;
	case 4: case 8:
		arrays.clear();                                               //城墙形
		arrays.push_back(Unit(F.LEFT + base_point + 1, F.UP + 1));
		arrays.push_back(Unit(F.LEFT + base_point + 2, F.UP + 1));
		arrays.push_back(Unit(F.LEFT + base_point + 3, F.UP + 1));
		arrays.push_back(Unit(F.LEFT + base_point + 2, F.UP + 2));
		for (int i = 0; i < rotate_time; ++i)
		{
			rotate();
		}
		break;
	}                                     
	//应该先将小屏幕清空。
	for (int i = 0; i < F.RIGHT2 - F.RIGHT - 1; ++i)
	{
		for (int j = 0; j < F.MIDDLE1 - F.UP - 1; ++j)
		{
			T.gotoxy(F.RIGHT + 1 + i, F.UP + j + 1);
			cout << " ";
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		Unit unit(F.RIGHT + 7 + arrays[i].get_x() - arrays[0].get_x(), F.UP + 4 + arrays[i].get_y() - arrays[0].get_y());
		unit.show();                                     //按照实际的俄罗斯方块，小屏幕放映的应该是下一个出现的方块形状，这里先将功能简单化
	}                                                 
	for (int i = 0; i < 4; ++i)
	{
		grid[arrays[i].get_x() - 1 - F.LEFT][arrays[i].get_y()-1-F.UP] = true;
	}
}
void Diamond::rotate()
{
	Frame F;
	for (int i = 0; i < 4; ++i)
	{
		grid[arrays[i].get_x() - 1 - F.LEFT][arrays[i].get_y()-F.UP-1] = false;
	}
	for (int i = 1; i <= 3; ++i)
	{
				int gap1 = arrays[i].get_x() - arrays[0].get_x();
				int gap2 = arrays[i].get_y() - arrays[0].get_y();
				arrays[i].set_x(arrays[0].get_x() - gap2);
				arrays[i].set_y(arrays[0].get_y() + gap1);	
	}
	return;
}
void Diamond::show()
{    
	Frame F;
	Tool T;
	for (int i = F.LEFT+1; i < F.RIGHT; ++i)
	{
		for (int j = F.UP + 1; j < F.BUTTOM; ++j)
		{
			if (grid[i - F.LEFT - 1][j - F.UP - 1] == true)
			{
				T.gotoxy(i, j);
				cout << "#";
			}
			else
			{
				T.gotoxy(i, j);
				cout << " ";
			}
		}
	}
	return;
}
void Diamond::move()
{
	Frame F;
	//Sleep(speed);                          暂停会在control函数里实现
	for (int i = 0; i < 4; ++i)
	{
		grid[arrays[i].get_x() - 1 - F.LEFT][arrays[i].get_y()-1-F.UP] = false;
	}
	for (int i = 0; i < 4; ++i)
	{
		arrays[i].set_y(arrays[i].get_y()+1);
	}
	for (int i = 0; i < 4; ++i)
	{
		grid[arrays[i].get_x() - 1 - F.LEFT][arrays[i].get_y()-F.UP-1] = true;
	}                                                          //虽说move后面是shift函数，但是为了保持函数的独立性还是在每个函数里面都写上false、true这部分
	return;
}
void Diamond::shift()
{
	Frame F;
	vector<Unit> array_wait;
	//防止与两侧方块重合
	bool flag = false;
	for (int i = 0; i < 4; ++i)
	{
		array_wait.push_back(arrays[i]);                                      //记录下arrays的原始位置
		grid[arrays[i].get_x() - 1 - F.LEFT][arrays[i].get_y()-F.UP-1] = false;
	}
	while(_kbhit())
	{
		switch (_getch())
		{
		case 97:case 65:case VK_LEFT:                                  //左移
			for (int i = 0; i < 4; ++i)
			{
					int m_x = arrays[i].get_x();
					arrays[i].set_x(m_x - 1);
			}
			break;
		case 100:case 68: case VK_RIGHT:                             //右移
			for (int i = 0; i < 4; ++i)
			{
					int m_x = arrays[i].get_x();
					arrays[i].set_x(m_x + 1);
			}
			break;
		case 82:case 114:                                    //输入字符R（rotate）的大写或者小写，旋转
			rotate();
			break;
		case 83:case 115:
			set_speed(10);                                     //实现速降功能  这个功能做得简单又有用户体验！！！
		default:
			break;
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		if (grid[arrays[i].get_x() - 1 - F.LEFT][arrays[i].get_y() - 1 - F.UP] == true)
			flag = true;
		if (arrays[i].get_x() <= F.LEFT || arrays[i].get_x() >= F.RIGHT)
			flag = true;
	}
	if (flag == true)                                             //如果相撞，则回到原始位置
	{
		arrays.clear();
		for (int i = 0; i < 4; ++i)
		{
			arrays.push_back(array_wait[i]);
		}
	}
	for (int i = 0; i < 4; ++i)
	{
		grid[arrays[i].get_x() - 1 - F.LEFT][arrays[i].get_y()-1-F.UP] = true;
	}
	return;
}
void Diamond::set_speed(int m_speed)
{
	speed = m_speed;
	return;
}
int Diamond::eliminate()
{
	Frame F;
	int level = 0;
	int i;
	for ( i = F.BUTTOM - F.UP - 2; i >= 0; --i)
	{
		bool temp = true;
		for (int j = 0; j < F.RIGHT - F.LEFT - 1; ++j)
		{
			if (grid[j][i] == false)
				temp = false;
		}
		if (temp == true)
		{
			level++;
			for (int k = 0; k < F.RIGHT - F.LEFT - 1; ++k)
			{
				for (int t = i; t > 0; --t)
				{
					grid[k][t] = grid[k][t - 1];
				}
			}
			for (int k = 0; k < F.RIGHT - F.LEFT - 1; ++k)
			{
				grid[k][0] = false;
			}
			i++;                                         //检测刚刚替补的一行
		}
		
		temp = true;
	}
	return level;                
}
bool Diamond::judge_death()
{
	Frame F;
	int temp = 0;
	for (int i = 0; i < F.RIGHT - F.LEFT - 1; ++i)
	{
		if (grid[i][0] == true)
			return true;
	}
	return false;
}
bool Diamond::delay()
{
	bool flag = false;
	Frame F;
	for (int i = 0; i < 4; ++i)
	{
		grid[arrays[i].get_x() - F.LEFT - 1][arrays[i].get_y() - F.UP - 1] = false;
	}
	for (int i = 0; i < 4; ++i)
	{
		if (arrays[i].get_y() == F.BUTTOM -  1)
			flag=true;
		if (grid[arrays[i].get_x()-F.LEFT-1][arrays[i].get_y() + 1-F.UP-1] == true)
			flag = true;
	}
	for (int i = 0; i < 4; ++i)
	{
		grid[arrays[i].get_x() - F.LEFT - 1][arrays[i].get_y() - F.UP - 1] = true;
	}
	return flag;
}
void Diamond::control()
{
	Frame F;
	Tool T;
	while (judge_death()==false)
	{
		create();
	    show();
		int score = 0;
		while(!delay())                                         //判断下面是否有方块，从而停止此次运动
		{
			shift();
			move();
			show();
			Sleep(speed);
		}                                                      //下面有方块停止运动的功能还没有实现
		score = eliminate();
		scoretotal += score;
		level = scoretotal / 4;
		if (level == LEVEL)
		{
			break;
		}
		speed = Speed[level];                        //根据等级改变速度，同时关闭速降功能
		F.Draw_score(scoretotal, level+1);
		Sleep(speed);
	}
	return;
}
int Diamond::get_level()
{
	return level;
}
