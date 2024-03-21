#pragma once
#include"chess.h"
class pao:public virtual chess
{
public:
	pao(){}
	pao(bool Color);
	~pao();
	bool move(Point Position);//炮移动规则
	void set(bool Color);//默认构造函数的补充

private:
	static char pao_num1;
	static char pao_num2;
};

