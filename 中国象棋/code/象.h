#pragma once
#include"chess.h"
class xiang:public virtual chess
{
public:
	xiang(){}
	xiang(bool Color);
	~xiang();
	bool move(Point Position);//���ƶ�����
	void set(bool Color);//Ĭ�Ϲ��캯���Ĳ���

private:
	static char xiang_num1;
	static char xiang_num2;
};
