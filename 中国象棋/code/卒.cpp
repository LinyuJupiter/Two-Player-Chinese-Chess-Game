#include"��.h"
char zu::zu_num1 = '0';//��
char zu::zu_num2 = '0';//��
zu::zu(bool Color) {
	if (Color) {
		zu_num1 += 1;
		assert(zu_num1 - '0' >= 1 && zu_num1- '0' <= 5);
		string name = "��";
		name += zu_num1;
		setname(name);
		setindex(8);
	}
	else {
		zu_num2 += 1;
		assert(zu_num2 - '0' >= 1 && zu_num2 - '0' <= 5);
		string name = "��";
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
		return false;//����ԭ�ز���
	if (Position.getx() < 1 || Position.getx() > 10 || Position.gety() < 1 || Position.gety() > 9)
		return false;//���ܳ�������
	if (getcolor()) {//��
		if (
			Position.getx() <= 4//����ʼλ����4��
			|| Position.getx() > getposition().getx() + 1//����ǰֻ���ƶ�1��
			|| Position.getx() < getposition().getx()//�����ܺ���
			)
			return false;
		if (getposition().getx() <= 5) {//δ����
			if (Position.gety() != getposition().gety()) {
				return false;//�ƶ�����λ�����ƶ�ǰ��ͬ���ƶ�ʧ��;
			}
			else {
				if (Position.getx() != getposition().getx() + 1)
					return false;//���ܲ���ǰ�ƶ�
				else 
					return true;//��ǰ�ƶ�һ��
				
			}
		}
		else {//�ѹ���
			if ((Position.gety() == getposition().gety() + 1
				|| Position.gety() == getposition().gety() - 1)
				&& (Position.getx() == getposition().getx())
				)//�����ƶ�һ��
				return true;			
			else if (Position.gety() == getposition().gety() && Position.getx() == getposition().getx() + 1) //��ǰ�ƶ�һ��
				return true;
			else
				return false;
		}
	}
	else {//��
		if (
			Position.getx() >= 7//���ʼλ����7��
			|| Position.getx() < getposition().getx() - 1//����ǰֻ���ƶ�1��
			|| Position.getx() > getposition().getx()//�䲻�ܺ���
			)
			return false;
		if (getposition().getx() >= 6) {//δ����
			if (Position.gety() != getposition().gety()) {
				return false;//�ƶ�����λ�����ƶ�ǰ��ͬ���ƶ�ʧ��;
			}
			else {
				if (Position.getx() != getposition().getx() - 1)
					return false;//���ܲ���ǰ�ƶ�
				else 
					return true;//��ǰ�ƶ�һ��
			}
		}
		else {//�ѹ���
			if ((Position.gety() == getposition().gety() + 1
				|| Position.gety() == getposition().gety() - 1)
				&& (Position.getx() == getposition().getx())
				) //�����ƶ�һ��
				return true;
			else if (Position.gety() == getposition().gety() && Position.getx() == getposition().getx() - 1) //��ǰ�ƶ�һ��
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
		string name = "��";
		name += zu_num1;
		setname(name);
		setindex(8);
	}
	else {
		zu_num2 += 1;
		assert(zu_num2 - '0' >= 1 && zu_num2 - '0' <= 5);
		string name = "��";
		name += zu_num2;
		setname(name);
		setindex(1);
	}
	setcolor(Color);
	set_alive(true);
}