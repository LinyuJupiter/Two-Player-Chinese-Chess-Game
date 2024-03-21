#include"象.h"
char xiang::xiang_num1 = '0';//红
char xiang::xiang_num2 = '0';//黑
xiang::xiang(bool Color) {
	if (Color) {
		xiang_num1 += 1;
		assert(xiang_num1 - '0' >= 1 && xiang_num1 - '0' <= 2);
		string name = "相";
		name += xiang_num1;
		setname(name);
		setindex(13);
	}
	else {
		xiang_num2 += 1;
		assert(xiang_num2 - '0' >= 1 && xiang_num2  - '0' <= 2);
		string name = "象";
		name += xiang_num2;
		setname(name);
		setindex(6);
	}
	setcolor(Color);
	set_alive(true);
}
xiang::~xiang()
{
	if (getchessname() != "chess") {
		if (getcolor())
			xiang_num1 -= 1;
		else
			xiang_num2 -= 1;
	}
}
bool xiang::move(Point Position)
{
	if (Position == getposition())
		return false;//不能原地不动
	if (Position.getx() < 1 || Position.getx() > 10 || Position.gety() < 1 || Position.gety() > 9)
		return false;//不能超出棋盘
	if (getcolor()) {//红
		if (Position.getx() > 5)
			return false;//不能过河
		if (
			!((Position.getx() == 1 && Position.gety() == 3)
			|| (Position.getx() == 1 && Position.gety() == 7)
			|| (Position.getx() == 3 && Position.gety() == 1)
			|| (Position.getx() == 3 && Position.gety() == 5)
			|| (Position.getx() == 3 && Position.gety() == 9)
			|| (Position.getx() == 5 && Position.gety() == 3)
			|| (Position.getx() == 5 && Position.gety() == 7))
			)
			return false;//相能到达的格子只有7个
		if ((Position.getx() == getposition().getx() + 2 && Position.gety() == getposition().gety() + 2)
			|| (Position.getx() == getposition().getx() + 2 && Position.gety() == getposition().gety() - 2)
			|| (Position.getx() == getposition().getx() - 2 && Position.gety() == getposition().gety() + 2)
			|| (Position.getx() == getposition().getx() - 2 && Position.gety() == getposition().gety() - 2)
			)
			return true;//相只能走田字
		else
			return false;
	}
	else {//黑
		if (Position.getx() < 6)
			return false;//不能过河
		if (
			!((Position.getx() == 10 && Position.gety() == 3)
			|| (Position.getx() == 10 && Position.gety() == 7)
			|| (Position.getx() == 8 && Position.gety() == 1)
			|| (Position.getx() == 8 && Position.gety() == 5)
			|| (Position.getx() == 8 && Position.gety() == 9)
			|| (Position.getx() == 6 && Position.gety() == 3)
			|| (Position.getx() == 6 && Position.gety() == 7))
			)
			return false;//象能到达的格子只有7个
		if ((Position.getx() == getposition().getx() + 2 && Position.gety() == getposition().gety() + 2)
			|| (Position.getx() == getposition().getx() + 2 && Position.gety() == getposition().gety() - 2)
			|| (Position.getx() == getposition().getx() - 2 && Position.gety() == getposition().gety() + 2)
			|| (Position.getx() == getposition().getx() - 2 && Position.gety() == getposition().gety() - 2)
			)
			return true;//象只能走田字
		else
			return false;
	}
	return false;
}
void xiang::set(bool Color)
{
	if (getchessname() != "chess")
		return;
	if (Color) {
		xiang_num1 += 1;
		assert(xiang_num1 - '0' >= 1 && xiang_num1 - '0' <= 2);
		string name = "相";
		name += xiang_num1;
		setname(name);
		setindex(13);
	}
	else {
		xiang_num2 += 1;
		assert(xiang_num2 - '0' >= 1 && xiang_num2 - '0' <= 2);
		string name = "象";
		name += xiang_num2;
		setname(name);
		setindex(6);
	}
	setcolor(Color);
	set_alive(true);
}