#pragma once
#include"chess.h"
class ju:public virtual chess
{
public:
	ju(){}
	ju(bool Color);
	~ju();
	bool move(Point Position);//���ƶ�����
	void set(bool Color);//Ĭ�Ϲ��캯���Ĳ���

private:
	static char ju_num1;
	static char ju_num2;
};
