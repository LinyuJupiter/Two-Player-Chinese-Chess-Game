#include"马.h"
char ma::ma_num1 = '0';//红
char ma::ma_num2 = '0';//黑
ma::ma(bool Color) {	
	if (Color) {
		ma_num1 += 1;
		assert(ma_num1  - '0' >= 1 && ma_num1  - '0' <= 2);
		string name = "傌";
		name += ma_num1;
		setname(name);
		setindex(14);
	}
	else {
		ma_num2 += 1;
		assert(ma_num2  - '0' >= 1 && ma_num2  - '0' <= 2);
		string name = "馬";
		name += ma_num2;
		setname(name);
		setindex(7);
	}
	setcolor(Color);
	set_alive(true);
}
ma::~ma()
{
	if (getchessname() != "chess") {
		if (getcolor())
			ma_num1 -= 1;
		else
			ma_num2 -= 1;
	}
}
bool ma::move(Point Position)
{
	if (Position == getposition())
		return false;//不能原地不动
	if (Position.getx() < 1 || Position.getx() > 10 || Position.gety() < 1 || Position.gety() > 9)
		return false;//不能超出棋盘
	if (
		(Position.getx() == getposition().getx() + 2 && Position.gety() == getposition().gety() + 1)
		|| (Position.getx() == getposition().getx() + 2 && Position.gety() == getposition().gety() - 1)
		|| (Position.getx() == getposition().getx() - 2 && Position.gety() == getposition().gety() + 1)
		|| (Position.getx() == getposition().getx() - 2 && Position.gety() == getposition().gety() - 1)
		|| (Position.getx() == getposition().getx() + 1 && Position.gety() == getposition().gety() + 2)
		|| (Position.getx() == getposition().getx() + 1 && Position.gety() == getposition().gety() - 2)
		|| (Position.getx() == getposition().getx() - 1 && Position.gety() == getposition().gety() + 2)
		|| (Position.getx() == getposition().getx() - 1 && Position.gety() == getposition().gety() - 2)
		)
		return true;//马走日,只能走八个位置
	return false;
}
void ma::set(bool Color)
{
	if (getchessname() != "chess")
		return;
	if (Color) {
		ma_num1 += 1;
		assert(ma_num1 - '0' >= 1 && ma_num1 - '0' <= 2);
		string name = "傌";
		name += ma_num1;
		setname(name);
		setindex(14);
	}
	else {
		ma_num2 += 1;
		assert(ma_num2 - '0' >= 1 && ma_num2 - '0' <= 2);
		string name = "馬";
		name += ma_num2;
		setname(name);
		setindex(7);
	}
	setcolor(Color);
	set_alive(true);
}