#pragma once
#include"chess.h"
class jiang:public virtual chess
{
public:
	jiang(){}
	jiang(bool Color);
	~jiang();
	bool move(Point Position);//将移动规则
	void set(bool Color);//默认构造函数的补充

private:
	static int jiang_num1;
	static int jiang_num2;
};

