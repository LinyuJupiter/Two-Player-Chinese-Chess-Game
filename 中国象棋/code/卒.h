#pragma once
#include"chess.h"

class zu:public virtual chess
{
public:
	zu() {}
	zu(bool Color);
	~zu();
	bool move(Point Position);//���ƶ�����
	void set(bool Color);//Ĭ�Ϲ��캯���Ĳ���
	
private:
	static char zu_num1;
	static char zu_num2;
};

