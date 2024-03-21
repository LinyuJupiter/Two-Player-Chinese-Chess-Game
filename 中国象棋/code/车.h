#pragma once
#include"chess.h"
class ju:public virtual chess
{
public:
	ju(){}
	ju(bool Color);
	~ju();
	bool move(Point Position);//车移动规则
	void set(bool Color);//默认构造函数的补充

private:
	static char ju_num1;
	static char ju_num2;
};
