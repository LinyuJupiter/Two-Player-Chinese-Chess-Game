#pragma once
#include"chess.h"
class ma:public virtual chess
{
public:
	ma(){}
	ma(bool Color);
	~ma();
	bool move(Point Position);//���ƶ�����
	void set(bool Color);//Ĭ�Ϲ��캯���Ĳ���

private:
	static char ma_num1;
	static char ma_num2;
};
