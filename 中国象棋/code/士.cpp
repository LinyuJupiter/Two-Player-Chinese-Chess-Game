#include"ʿ.h"
char shi::shi_num1 = '0';//��
char shi::shi_num2 = '0';//��
shi::shi(bool Color) {
	if (Color) {
		shi_num1 += 1; 
		assert(shi_num1  - '0' >= 1 && shi_num1  - '0' <= 2);
		string name = "��";
		name += shi_num1;
		setname(name);
		setindex(11);
	}
	else {
		shi_num2 += 1;
		assert(shi_num2  - '0' >= 1 && shi_num2  - '0' <= 2);
		string name = "ʿ";
		name += shi_num2;
		setname(name);
		setindex(4);
	}
	setcolor(Color);
	set_alive(true);
}
shi::~shi()
{
	if (getchessname() != "chess") {
		if (getcolor())
			shi_num1 -= 1;
		else
			shi_num2 -= 1;
	}
}
bool shi::move(Point Position)
{
	if (Position == getposition())
		return false;//����ԭ�ز���
	if (Position.getx() < 1 || Position.getx() > 10 || Position.gety() < 1 || Position.gety() > 9)
		return false;//���ܳ�������
	if (getcolor()) {//��
		if (Position.getx() < 1
			|| Position.getx() > 3
			|| Position.gety() < 4
			|| Position.gety() > 6
			)//�����뿪�Ź���
			return false;
		else if ((Position.getx() == getposition().getx()+1 && Position.gety() == getposition().gety() + 1)
			|| (Position.getx() == getposition().getx()+1 && Position.gety() == getposition().gety() - 1)
			|| (Position.getx() == getposition().getx() - 1 && Position.gety() == getposition().gety()+1)
			|| (Position.getx() == getposition().getx() - 1 && Position.gety() == getposition().gety()-1)
			) //��ֻ����б��
			return true;
		else
			return false;
	}
	else {//��
		if (Position.getx() < 8
			|| Position.getx() > 10
			|| Position.gety() < 4
			|| Position.gety() > 6
			)//�����뿪�Ź���
			return false;
		else if ((Position.getx() == getposition().getx()+1 && Position.gety() == getposition().gety() + 1)
			|| (Position.getx() == getposition().getx()+1 && Position.gety() == getposition().gety() - 1)
			|| (Position.getx() == getposition().getx() - 1 && Position.gety() == getposition().gety()+1)
			|| (Position.getx() == getposition().getx() - 1 && Position.gety() == getposition().gety()-1)
			) //ʿֻ����б��
			return true;
		else
			return false;
	}
	return false;
}
void shi::set(bool Color)
{
	if (getchessname() != "chess")
		return;
	if (Color) {
		shi_num1 += 1;
		assert(shi_num1 - '0' >= 1 && shi_num1 - '0' <= 2);
		string name = "��";
		name += shi_num1;
		setname(name);
		setindex(11);
	}
	else {
		shi_num2 += 1;
		assert(shi_num2 - '0' >= 1 && shi_num2 - '0' <= 2);
		string name = "ʿ";
		name += shi_num2;
		setname(name);
		setindex(4);
	}
	setcolor(Color);
	set_alive(true);
}