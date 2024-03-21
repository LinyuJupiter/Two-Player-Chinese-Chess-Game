#pragma once
#include <iomanip>
#include<sstream>
#include"Array.h"
#include"卒.h"
#include"士.h"
#include"将.h"
#include"炮.h"
#include"象.h"
#include"车.h"
#include"马.h"
inline int str_to_int(string s)//字符串转化成整数
{
	int a;
	string res = s;
	stringstream ss;
	ss << res;
	ss >> a;
	return a;
}

class Checkerboard
{
public:
	Checkerboard();
	virtual ~Checkerboard();
	void initialization();//棋盘初始化,按象棋初始局摆放棋子
	void shows();//棋盘显示
	bool walk(bool Color, int INDEX, int nums, int x, int y);//判断落子
	void move(bool Color, int INDEX, int nums, int x, int y);//落子
	int win();//胜利条件判断
	bool check(bool Color);//将军判断
	void Standard_chess_game();//开始一局标准对战
	int getcheckerboard(int i,int j,int k);
	Array<Array<chess*>>* getallchess();
	void set_checkerboard(int i, int j, int k, int value);

private:
	bool initial_walk(bool Color, int INDEX, int nums, int x, int y);//带原因的初步判断落子
	bool unitial_walk(bool Color, int INDEX, int nums, int x, int y);//不带原因的初步判断落子
	int checkerboard[11][10][2];//棋盘,下标为0的不用
	Array<Array<chess*>> allchess;
	kong kongge; //定义32个棋子
	zu zu1, zu2, zu3, zu4, zu5;
	zu zu6, zu7, zu8, zu9, zu10;
	jiang jiang1, jiang2;
	ju ju1, ju2, ju3, ju4;
	shi shi1, shi2, shi3, shi4;
	pao pao1, pao2, pao3, pao4;
	xiang xiang1, xiang2, xiang3, xiang4;
	ma ma1, ma2, ma3, ma4;
	static int checker;//统计棋盘总数，不得超过1个
};
