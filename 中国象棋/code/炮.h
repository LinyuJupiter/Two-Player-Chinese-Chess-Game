#pragma once
#include"chess.h"
class pao:public virtual chess
{
public:
	pao(){}
	pao(bool Color);
	~pao();
	bool move(Point Position);//���ƶ�����
	void set(bool Color);//Ĭ�Ϲ��캯���Ĳ���

private:
	static char pao_num1;
	static char pao_num2;
};

