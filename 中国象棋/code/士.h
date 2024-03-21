#pragma once
#include"chess.h"
class shi:public virtual chess
{
public:
	shi(){}
	shi(bool Color);
	~shi();
	bool move(Point Position);//士移动规则
	void set(bool Color);//默认构造函数的补充

private:
	static char shi_num1;
	static char shi_num2;
};