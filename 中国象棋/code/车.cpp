#include"��.h"
char ju::ju_num1 = '0';//��
char ju::ju_num2 = '0';//��
ju::ju(bool Color) {
	if (Color) {
		ju_num1 += 1;
		assert(ju_num1  - '0' >= 1 && ju_num1 - '0' <= 2);
		string name = "�e";
		name += ju_num1;
		setname(name);
		setindex(10);
	}
	else {
		ju_num2 += 1;
		assert(ju_num2  - '0' >= 1 && ju_num2  - '0' <= 2);
		string name = "܇";
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
		return false;//����ԭ�ز���
	if (Position.getx() < 1 || Position.getx() > 10 || Position.gety() < 1 || Position.gety() > 9)
		return false;//���ܳ�������
	if (Position.getx() == getposition().getx() || Position.gety() == getposition().gety())
		return true;//ֻ����ֱ��
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
		string name = "�e";
		name += ju_num1;
		setname(name);
		setindex(10);
	}
	else {
		ju_num2 += 1;
		assert(ju_num2 - '0' >= 1 && ju_num2 - '0' <= 2);
		string name = "܇";
		name += ju_num2;
		setname(name);
		setindex(3);
	}
	setcolor(Color);
	set_alive(true);
}