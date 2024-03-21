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
	string chessname;//������
	bool color;//��ڷ�,trueΪ��,falseΪ��
	int index;//�������ͱ��
	bool alive;//�����Ƿ���
	Point position;//��������
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