#pragma once
#include <iomanip>
#include<sstream>
#include"Array.h"
#include"��.h"
#include"ʿ.h"
#include"��.h"
#include"��.h"
#include"��.h"
#include"��.h"
#include"��.h"
inline int str_to_int(string s)//�ַ���ת��������
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
	void initialization();//���̳�ʼ��,�������ʼ�ְڷ�����
	void shows();//������ʾ
	bool walk(bool Color, int INDEX, int nums, int x, int y);//�ж�����
	void move(bool Color, int INDEX, int nums, int x, int y);//����
	int win();//ʤ�������ж�
	bool check(bool Color);//�����ж�
	void Standard_chess_game();//��ʼһ�ֱ�׼��ս
	int getcheckerboard(int i,int j,int k);
	Array<Array<chess*>>* getallchess();
	void set_checkerboard(int i, int j, int k, int value);

private:
	bool initial_walk(bool Color, int INDEX, int nums, int x, int y);//��ԭ��ĳ����ж�����
	bool unitial_walk(bool Color, int INDEX, int nums, int x, int y);//����ԭ��ĳ����ж�����
	int checkerboard[11][10][2];//����,�±�Ϊ0�Ĳ���
	Array<Array<chess*>> allchess;
	kong kongge; //����32������
	zu zu1, zu2, zu3, zu4, zu5;
	zu zu6, zu7, zu8, zu9, zu10;
	jiang jiang1, jiang2;
	ju ju1, ju2, ju3, ju4;
	shi shi1, shi2, shi3, shi4;
	pao pao1, pao2, pao3, pao4;
	xiang xiang1, xiang2, xiang3, xiang4;
	ma ma1, ma2, ma3, ma4;
	static int checker;//ͳ���������������ó���1��
};
