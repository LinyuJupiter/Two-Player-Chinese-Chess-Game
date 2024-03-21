#include"��.h"
char xiang::xiang_num1 = '0';//��
char xiang::xiang_num2 = '0';//��
xiang::xiang(bool Color) {
	if (Color) {
		xiang_num1 += 1;
		assert(xiang_num1 - '0' >= 1 && xiang_num1 - '0' <= 2);
		string name = "��";
		name += xiang_num1;
		setname(name);
		setindex(13);
	}
	else {
		xiang_num2 += 1;
		assert(xiang_num2 - '0' >= 1 && xiang_num2  - '0' <= 2);
		string name = "��";
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
		return false;//����ԭ�ز���
	if (Position.getx() < 1 || Position.getx() > 10 || Position.gety() < 1 || Position.gety() > 9)
		return false;//���ܳ�������
	if (getcolor()) {//��
		if (Position.getx() > 5)
			return false;//���ܹ���
		if (
			!((Position.getx() == 1 && Position.gety() == 3)
			|| (Position.getx() == 1 && Position.gety() == 7)
			|| (Position.getx() == 3 && Position.gety() == 1)
			|| (Position.getx() == 3 && Position.gety() == 5)
			|| (Position.getx() == 3 && Position.gety() == 9)
			|| (Position.getx() == 5 && Position.gety() == 3)
			|| (Position.getx() == 5 && Position.gety() == 7))
			)
			return false;//���ܵ���ĸ���ֻ��7��
		if ((Position.getx() == getposition().getx() + 2 && Position.gety() == getposition().gety() + 2)
			|| (Position.getx() == getposition().getx() + 2 && Position.gety() == getposition().gety() - 2)
			|| (Position.getx() == getposition().getx() - 2 && Position.gety() == getposition().gety() + 2)
			|| (Position.getx() == getposition().getx() - 2 && Position.gety() == getposition().gety() - 2)
			)
			return true;//��ֻ��������
		else
			return false;
	}
	else {//��
		if (Position.getx() < 6)
			return false;//���ܹ���
		if (
			!((Position.getx() == 10 && Position.gety() == 3)
			|| (Position.getx() == 10 && Position.gety() == 7)
			|| (Position.getx() == 8 && Position.gety() == 1)
			|| (Position.getx() == 8 && Position.gety() == 5)
			|| (Position.getx() == 8 && Position.gety() == 9)
			|| (Position.getx() == 6 && Position.gety() == 3)
			|| (Position.getx() == 6 && Position.gety() == 7))
			)
			return false;//���ܵ���ĸ���ֻ��7��
		if ((Position.getx() == getposition().getx() + 2 && Position.gety() == getposition().gety() + 2)
			|| (Position.getx() == getposition().getx() + 2 && Position.gety() == getposition().gety() - 2)
			|| (Position.getx() == getposition().getx() - 2 && Position.gety() == getposition().gety() + 2)
			|| (Position.getx() == getposition().getx() - 2 && Position.gety() == getposition().gety() - 2)
			)
			return true;//��ֻ��������
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
		string name = "��";
		name += xiang_num1;
		setname(name);
		setindex(13);
	}
	else {
		xiang_num2 += 1;
		assert(xiang_num2 - '0' >= 1 && xiang_num2 - '0' <= 2);
		string name = "��";
		name += xiang_num2;
		setname(name);
		setindex(6);
	}
	setcolor(Color);
	set_alive(true);
}