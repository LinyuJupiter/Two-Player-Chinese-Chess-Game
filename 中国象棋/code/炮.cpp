#include"��.h"
char pao::pao_num1 = '0';//��
char pao::pao_num2 = '0';//��
pao::pao(bool Color) {
	if (Color) {
		pao_num1 += 1;
		assert(pao_num1 - '0' >= 1 && pao_num1 - '0' <= 2);
		string name = "��";
		name += pao_num1;
		setname(name);
		setindex(12);
	}
	else {
		pao_num2 += 1;
		assert(pao_num2  - '0' >= 1 && pao_num2  - '0' <= 2);
		string name = "�h";
		name += pao_num2;
		setname(name);
		setindex(5);
	}
	setcolor(Color);
	set_alive(true);
}
pao::~pao()
{
	if (getchessname() != "chess") {
		if (getcolor())
			pao_num1 -= 1;
		else
			pao_num2 -= 1;
	}
}
bool pao::move(Point Position)
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
void pao::set(bool Color)
{
	if (getchessname() != "chess")
		return;
	if (Color) {
		pao_num1 += 1;
		assert(pao_num1 - '0' >= 1 && pao_num1 - '0' <= 2);
		string name = "��";
		name += pao_num1;
		setname(name);
		setindex(12);
	}
	else {
		pao_num2 += 1;
		assert(pao_num2 - '0' >= 1 && pao_num2 - '0' <= 2);
		string name = "�h";
		name += pao_num2;
		setname(name);
		setindex(5);
	}
	setcolor(Color);
	set_alive(true);
}