#include"将.h"
int jiang::jiang_num1 = 0;//红
int jiang::jiang_num2 = 0;//黑
jiang::jiang(bool Color)
{
	if (Color) {
		jiang_num1 += 1;
		assert(jiang_num1 == 1);
		string name = "帅";
		setname(name);
		setindex(9);
	}
	else {
		jiang_num2 += 1;
		assert(jiang_num2  == 1);
		string name = "将";
		setname(name);
		setindex(2);
	}
	setcolor(Color);
	set_alive(true);
}
jiang::~jiang()
{
	if (getchessname() != "chess") {
		if (getcolor())
			jiang_num1 -= 1;
		else
			jiang_num2 -= 1;
	}
}
inline bool jiang::move(Point Position)
{
	if (Position == getposition())
		return false;//不能原地不动
	if (Position.getx() < 1 || Position.getx() > 10 || Position.gety() < 1 || Position.gety() > 9)
		return false;//不能超出棋盘
	if (getcolor()) {//红
		if (Position.getx() < 1
			|| Position.getx() > 3
			|| Position.gety() < 4
			|| Position.gety() > 6
			)//不能离开九宫格
			return false;
		else if ((Position.getx() == getposition().getx() && Position.gety() == getposition().gety() + 1)
			|| (Position.getx() == getposition().getx() && Position.gety() == getposition().gety() - 1)
			|| (Position.getx() == getposition().getx() + 1 && Position.gety() == getposition().gety())
			|| (Position.getx() == getposition().getx() - 1 && Position.gety() == getposition().gety())
			) //帅只能移动一格
			return true;
		else
			return false;
	}
	else {//黑
		if (Position.getx() < 8
			|| Position.getx() > 10
			|| Position.gety() < 4
			|| Position.gety() > 6
			)//不能离开九宫格
			return false;
		else if ((Position.getx() == getposition().getx() && Position.gety() == getposition().gety() + 1)
			|| (Position.getx() == getposition().getx() && Position.gety() == getposition().gety() - 1)
			|| (Position.getx() == getposition().getx() + 1 && Position.gety() == getposition().gety())
			|| (Position.getx() == getposition().getx() - 1 && Position.gety() == getposition().gety())
			) //将只能移动一格
			return true;
		else
			return false;
	}
	return false;
}
void jiang::set(bool Color)
{
	if (getchessname() != "chess")
		return;
	if (Color) {
		jiang_num1 += 1;
		assert(jiang_num1 == 1);
		string name = "帅";
		setname(name);
		setindex(9);
	}
	else {
		jiang_num2 += 1;
		assert(jiang_num2 == 1);
		string name = "将";
		setname(name);
		setindex(2);
	}
	setcolor(Color);
	set_alive(true);
}