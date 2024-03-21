#pragma once
#include"chess.h"

class zu:public virtual chess
{
public:
	zu() {}
	zu(bool Color);
	~zu();
	bool move(Point Position);//卒移动规则
	void set(bool Color);//默认构造函数的补充
	
private:
	static char zu_num1;
	static char zu_num2;
};

