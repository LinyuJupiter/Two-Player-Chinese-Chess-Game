#pragma once
#include"chess.h"
class xiang:public virtual chess
{
public:
	xiang(){}
	xiang(bool Color);
	~xiang();
	bool move(Point Position);//象移动规则
	void set(bool Color);//默认构造函数的补充

private:
	static char xiang_num1;
	static char xiang_num2;
};
