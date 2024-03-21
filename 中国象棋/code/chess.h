#pragma once
#include"Point.h"
#include"Array.h"
#include<string>
#include<cassert>
using namespace std;

class chess
{
public:
	chess();
	chess(string Chessname,bool Color,Point Position);
	chess(chess& a);
	virtual ~chess(){}
	string getchessname();
	bool getcolor();
	int getindex();
	Point getposition();
	bool isalive();
	void setname(string name);
	void setcolor(bool Color);
	void set_position(int x,int y);
	void set_alive(bool Alive);
	void setindex(int Index);
	chess& operator = (const chess& sm);
	bool operator == (const chess& sm);
	bool operator != (const chess& sm);
	virtual bool move(Point Position) = 0;
	virtual void set(bool Color) = 0;
	
private:
	string chessname;//棋子名
	bool color;//红黑方,true为红,false为黑
	int index;//棋子类型编号
	bool alive;//棋子是否存活
	Point position;//棋子坐标
};
class kong:public virtual chess
{
public:
	kong() { 
		setname("name");
	}
	bool move(Point Position) { return false; }
	void set(bool Color) { return; }
};