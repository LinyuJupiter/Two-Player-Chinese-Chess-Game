#pragma once
#include"chess.h"
class shi:public virtual chess
{
public:
	shi(){}
	shi(bool Color);
	~shi();
	bool move(Point Position);//ʿ�ƶ�����
	void set(bool Color);//Ĭ�Ϲ��캯���Ĳ���

private:
	static char shi_num1;
	static char shi_num2;
};