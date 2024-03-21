#include"车.h"
char ju::ju_num1 = '0';//红
char ju::ju_num2 = '0';//黑
ju::ju(bool Color) {
	if (Color) {
		ju_num1 += 1;
		assert(ju_num1  - '0' >= 1 && ju_num1 - '0' <= 2);
		string name = "俥";
		name += ju_num1;
		setname(name);
		setindex(10);
	}
	else {
		ju_num2 += 1;
		assert(ju_num2  - '0' >= 1 && ju_num2  - '0' <= 2);
		string name = "車";
		name += ju_num2;
		setname(name);
		setindex(3);
	}
	setcolor(Color);
	set_alive(true);
}
ju::~ju()
{
	if (getchessname() != "chess") {
		if (getcolor())
			ju_num1 -= 1;
		else
			ju_num2 -= 1;
	}
}
bool ju::move(Point Position)
{
	if (Position == getposition())
		return false;//不能原地不动
	if (Position.getx() < 1 || Position.getx() > 10 || Position.gety() < 1 || Position.gety() > 9)
		return false;//不能超出棋盘
	if (Position.getx() == getposition().getx() || Position.gety() == getposition().gety())
		return true;//只能走直线
	else
		return false;
	return false;
}
void ju::set(bool Color)
{
	if (getchessname() != "chess")
		return;
	if (Color) {
		ju_num1 += 1;
		assert(ju_num1 - '0' >= 1 && ju_num1 - '0' <= 2);
		string name = "俥";
		name += ju_num1;
		setname(name);
		setindex(10);
	}
	else {
		ju_num2 += 1;
		assert(ju_num2 - '0' >= 1 && ju_num2 - '0' <= 2);
		string name = "車";
		name += ju_num2;
		setname(name);
		setindex(3);
	}
	setcolor(Color);
	set_alive(true);
}