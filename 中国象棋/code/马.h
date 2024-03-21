#pragma once
#include"chess.h"
class ma:public virtual chess
{
public:
	ma(){}
	ma(bool Color);
	~ma();
	bool move(Point Position);//马移动规则
	void set(bool Color);//默认构造函数的补充

private:
	static char ma_num1;
	static char ma_num2;
};
