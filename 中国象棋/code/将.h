#pragma once
#include"chess.h"
class jiang:public virtual chess
{
public:
	jiang(){}
	jiang(bool Color);
	~jiang();
	bool move(Point Position);//���ƶ�����
	void set(bool Color);//Ĭ�Ϲ��캯���Ĳ���

private:
	static int jiang_num1;
	static int jiang_num2;
};

