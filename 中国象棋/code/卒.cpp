#include"卒.h"
char zu::zu_num1 = '0';//红
char zu::zu_num2 = '0';//黑
zu::zu(bool Color) {
	if (Color) {
		zu_num1 += 1;
		assert(zu_num1 - '0' >= 1 && zu_num1- '0' <= 5);
		string name = "兵";
		name += zu_num1;
		setname(name);
		setindex(8);
	}
	else {
		zu_num2 += 1;
		assert(zu_num2 - '0' >= 1 && zu_num2 - '0' <= 5);
		string name = "卒";
		name += zu_num2;
		setname(name);
		setindex(1);
	}
	setcolor(Color);
	set_alive(true);
}
zu::~zu()
{
	if (getchessname() != "chess") {
		if (getcolor()) {
			zu_num1 -= 1;	
		}
		else {		
			zu_num2 -= 1;
		}
	}
}
inline bool zu::move(Point Position)
{
	if (Position == getposition())
		return false;//不能原地不动
	if (Position.getx() < 1 || Position.getx() > 10 || Position.gety() < 1 || Position.gety() > 9)
		return false;//不能超出棋盘
	if (getcolor()) {//红
		if (
			Position.getx() <= 4//兵初始位置在4行
			|| Position.getx() > getposition().getx() + 1//兵向前只能移动1格
			|| Position.getx() < getposition().getx()//兵不能后退
			)
			return false;
		if (getposition().getx() <= 5) {//未过河
			if (Position.gety() != getposition().gety()) {
				return false;//移动后列位置与移动前不同，移动失败;
			}
			else {
				if (Position.getx() != getposition().getx() + 1)
					return false;//不能不向前移动
				else 
					return true;//向前移动一格
				
			}
		}
		else {//已过河
			if ((Position.gety() == getposition().gety() + 1
				|| Position.gety() == getposition().gety() - 1)
				&& (Position.getx() == getposition().getx())
				)//左右移动一格
				return true;			
			else if (Position.gety() == getposition().gety() && Position.getx() == getposition().getx() + 1) //向前移动一格
				return true;
			else
				return false;
		}
	}
	else {//黑
		if (
			Position.getx() >= 7//卒初始位置在7行
			|| Position.getx() < getposition().getx() - 1//卒向前只能移动1格
			|| Position.getx() > getposition().getx()//卒不能后退
			)
			return false;
		if (getposition().getx() >= 6) {//未过河
			if (Position.gety() != getposition().gety()) {
				return false;//移动后列位置与移动前不同，移动失败;
			}
			else {
				if (Position.getx() != getposition().getx() - 1)
					return false;//不能不向前移动
				else 
					return true;//向前移动一格
			}
		}
		else {//已过河
			if ((Position.gety() == getposition().gety() + 1
				|| Position.gety() == getposition().gety() - 1)
				&& (Position.getx() == getposition().getx())
				) //左右移动一格
				return true;
			else if (Position.gety() == getposition().gety() && Position.getx() == getposition().getx() - 1) //向前移动一格
				return true;
			else
				return false;
		}
	}
	return false;
}
void zu::set(bool Color)
{
	if (getchessname() != "chess")
		return;
	if (Color) {
		zu_num1 += 1;
		assert(zu_num1 - '0' >= 1 && zu_num1 - '0' <= 5);
		string name = "兵";
		name += zu_num1;
		setname(name);
		setindex(8);
	}
	else {
		zu_num2 += 1;
		assert(zu_num2 - '0' >= 1 && zu_num2 - '0' <= 5);
		string name = "卒";
		name += zu_num2;
		setname(name);
		setindex(1);
	}
	setcolor(Color);
	set_alive(true);
}