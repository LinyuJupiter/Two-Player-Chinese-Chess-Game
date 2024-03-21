#pragma once
#include"����.h"
#include <iostream>
#include <vector>        //�ṩ����ͷ�ļ�
#include <algorithm>     // �㷨ͷ�ļ����ṩ������
#include <fstream>       //�ṩ�ļ�ͷ�ļ�
#include <iomanip>       //C++������ȿ�����Ҫ
class Readable_Checkerboard:public virtual Checkerboard
{
public:
	Readable_Checkerboard();
	Readable_Checkerboard(const string filename);//��ȡ·���о�
	void preservation();//����о�
	void Standard_chess_game();//��ʼһ�ֱ�׼��ս
	void miniature_chess_game();//��ʼһ�ֲоֶ�ս

private:
	static int times;
	bool color;//���ַ�
};
int Readable_Checkerboard::times = 1;
Readable_Checkerboard::Readable_Checkerboard() { color = true; }
inline Readable_Checkerboard::Readable_Checkerboard(const string filename)
{
	color = true;
	for (int i = 1; i <= 14; i++)
		for (int j = 0; j < (*getallchess())[i].getSize(); j++)
			(*(*getallchess())[i][j]).set_alive(false);//ȫ������
	ifstream file(filename);
	string lines;
	int line = 1;
	while (getline(file, lines))
	{
		if (lines.length() == 2) {
			if (lines == "��")
				color = true;
			else if (lines == "��")
				color = false;
			else {
				cout << "�ļ���ʽ����" << endl;
				cout << "����������׼������..." << endl;
				initialization();
				file.close();
				return;
			}
		}
		else {
			for (int i = 0; i < lines.length(); i += 2) {
				int pos = 0; string a = lines.substr(i, 2);
				if (a == "**")pos = 0;
				else if (a == "��")pos = 1;
				else if (a == "��")pos = 2;
				else if (a == "܇")pos = 3;
				else if (a == "ʿ")pos = 4;
				else if (a == "�h")pos = 5;
				else if (a == "��")pos = 6;
				else if (a == "�R")pos = 7;
				else if (a == "��")pos = 8;
				else if (a == "˧")pos = 9;
				else if (a == "�e")pos = 10;
				else if (a == "��")pos = 11;
				else if (a == "��")pos = 12;
				else if (a == "��")pos = 13;
				else if (a == "��")pos = 14;
				else { 
					cout << "�ļ���ʽ����" << endl;
					cout << "����������׼������..." << endl;
					initialization();
					file.close();
					return; 
				}
				set_checkerboard(line, i / 2 + 1, 0, pos);
				if (pos != 0) {
					for (int j = 0; j <= (*getallchess())[pos].getSize(); j++) {
						if (j == (*getallchess())[pos].getSize()) {
							cout << "error:" << a << ":�������࣡" << endl;
							cout << "����������׼������..." << endl;
							initialization();
							file.close();
							return;
						}
						if ((*(*getallchess())[pos][j]).isalive())
							continue;
						else {
							set_checkerboard(line, i / 2 + 1, 1, j);
							(*(*getallchess())[pos][j]).set_alive(true);
							(*(*getallchess())[pos][j]).set_position(line, i / 2 + 1);
							break;
						}
					}
				}
			}
			line++;
		}
	}
	for (int i = 1; i <= 10; i++) {//��֤��ȡ�������Ƿ����
		for (int j = 1; j <= 9; j++) {
			int index_ = getcheckerboard(i, j, 0);
			int nums_ = getcheckerboard(i, j, 1);
			if (index_ == 2) {//��
				if (i < 8 || j < 4 || j>6) {
					cout << "��:λ�ô���" << endl;
					cout << "����������׼������..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 9) {//˧
				if (i > 3 || j < 4 || j>6) {
					cout << "˧:λ�ô���" << endl;
					cout << "����������׼������..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 4) {//ʿ
				if (!((i == 10 && j == 4)
					|| (i == 10 && j == 6)
					|| (i == 9 && j == 5)
					|| (i == 8 && j == 4)
					|| (i == 8 && j == 6))) {
					cout << "ʿ:λ�ô���" << endl;
					cout << "����������׼������..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 11) {//��
				if (!((i == 1 && j == 4)
					|| (i == 1 && j == 6)
					|| (i == 2 && j == 5)
					|| (i == 3 && j == 4)
					|| (i == 3 && j == 6))) {
					cout << "��:λ�ô���" << endl;
					cout << "����������׼������..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 6) {//��
				if (!((i == 10 && j == 3) 
					|| (i == 10 && j == 7)
					|| (i == 8 && j == 1) 
					|| (i == 8 && j == 5) 
					|| (i == 8 && j == 9)
					|| (i == 6 && j == 3)
					|| (i == 6 && j == 7))) {
					cout << "��:λ�ô���" << endl;
					cout << "����������׼������..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 13) {//��
				if (!((i == 1 && j == 3)
					|| (i == 1 && j == 7)
					|| (i == 3 && j == 1)
					|| (i == 3 && j == 5)
					|| (i == 3 && j == 9)
					|| (i == 5 && j == 3)
					|| (i == 5 && j == 7))) {
					cout << "��:λ�ô���" << endl;
					cout << "����������׼������..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 1) {//��
				if (i>7) {
					cout << "��:λ�ô���" << endl;
					cout << "����������׼������..." << endl;
					initialization();
					file.close();
					return;
				}
				if (i == 7) {
					if ((j != 1 )||( j != 3 )||( j != 5) ||( j != 7 )||( j != 9)) {
						cout << "��:λ�ô���" << endl;
						cout << "����������׼������..." << endl;
						initialization();
						file.close();
						return;
					}
					for (int k = 0; k < (*getallchess())[index_].getSize(); k++) {
						if (k == nums_)continue;
						if (!((*(*getallchess())[index_][k]).isalive()))break;
						if ((*(*getallchess())[index_][k]).getposition().getx() == 6
							&& (*(*getallchess())[index_][k]).getposition().gety() == j) {
							cout << "��:λ�ô���" << endl;
							cout << "����������׼������..." << endl;
							initialization();
							file.close();
							return;
						}
					}
					
				}
			}
			if (index_ == 8) {//��
				if (i < 4) {
					cout << "��:λ�ô���" << endl;
					cout << "����������׼������..." << endl;
					initialization();
					file.close();
					return;
				}
				if (i == 4) {
					if ((j != 1) || (j != 3) || (j != 5) || (j != 7) || (j != 9)) {
						cout << "��:λ�ô���" << endl;
						cout << "����������׼������..." << endl;
						initialization();
						file.close();
						return;
					}
					for (int k = 0; k < (*getallchess())[index_].getSize(); k++) {
						if (k == nums_)continue;
						if (!((*(*getallchess())[index_][k]).isalive()))break;
						if ((*(*getallchess())[index_][k]).getposition().getx() == 5
							&& (*(*getallchess())[index_][k]).getposition().gety() == j) {
							cout << "��:λ�ô���" << endl;
							cout << "����������׼������..." << endl;
							initialization();
							file.close();
							return;
						}
					}
				}
			}
		}
	}
	file.close();
}
inline void Readable_Checkerboard::preservation()
{
	int count = 0, n = times; string nums = ""; char num;
	while (n != 0)
	{
		int k = n % 10;
		num = k + '0';
		n /= 10;
		nums += num;
	}
	reverse(nums.begin(), nums.end());
	string file = "./images/����о�"; nums += ".txt"; file += nums;
	ofstream mycout(file);
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			switch (getcheckerboard(i,j,0))
			{
			case 0:mycout << "**"; break;
			case 1:mycout << "��"; break;
			case 2:mycout << "��"; break;
			case 3:mycout << "܇"; break;
			case 4:mycout << "ʿ"; break;
			case 5:mycout << "�h"; break;
			case 6:mycout << "��"; break;
			case 7:mycout << "�R"; break;
			case 8:mycout << "��"; break;
			case 9:mycout << "˧"; break;
			case 10:mycout << "�e"; break;
			case 11:mycout << "��"; break;
			case 12:mycout << "��"; break;
			case 13:mycout << "��"; break;
			case 14:mycout << "��"; break;
			default:
				break;
			}
		}
		mycout << endl;
	}
	if (color)
		mycout << "��" << endl;
	else
		mycout << "��" << endl;
	mycout.close();
	times++;
	cout << "�ļ��ѱ��浽" << file << endl;
}
inline void Readable_Checkerboard::Standard_chess_game()
{
	initialization();
	color = true;
	miniature_chess_game();
}
inline void Readable_Checkerboard::miniature_chess_game()
{
	shows();
	int colors = 1;
	if (!color)
		colors = -colors;
	string index_rule = "�������:\n��(��)1\n˧(��)2\n�e(܇)3\n��(ʿ)4\n��(�h)5\n��(��)6\n��(�R)7";
	while (true) {
		string line = "1"; int nums = 1, x = 1, y = 1;
		if (colors == 1) {
			cout << "�췽:";
			cin >> line;
			if (line == "index") {
				cout << index_rule << endl;
				cout << "���������ַ�����";
				char c;
				cin >> c;
				shows();
				continue;
			}
			else if (line == "0") {
				cout << "�췽Ͷ�����ڷ�ʤ����" << endl;
				break;
			}
			else if (line == "save") {
				preservation();
				continue;
			}
			else {
				cin >> nums >> x >> y;
				int index = str_to_int(line);
				if (
					(index < 1 || index>7)
					|| (nums<1 || nums>(*getallchess())[index+7].getSize())
					|| (x < 1 || x>10)
					|| (y < 1 || y>9)
					) {
					cout << "�������" << endl;
					continue;
				}
				if (walk(true, index, nums, x, y)) {
					move(true, index, nums, x, y);
					shows();
					colors = -colors;
					color = false;
				}
				if (check(false))
					cout << "�췽:������" << endl;
			}
		}
		else if (colors == -1) {
			cout << "�ڷ�:";
			cin >> line;
			if (line == "index") {
				cout << index_rule << endl;
				cout << "���������ַ�����";
				char c;
				cin >> c;
				shows();
				continue;
			}
			else if (line == "0") {
				cout << "�ڷ�Ͷ�����췽ʤ����" << endl;
				break;
			}
			else if (line == "save") {
				preservation();
				continue;
			}
			else {
				cin >> nums >> x >> y;
				int index = str_to_int(line);
				if (
					(index < 1 || index>7)
					|| (nums<1 || nums>(*getallchess())[index].getSize())
					|| (x < 1 || x>10)
					|| (y < 1 || y>9)
					) {
					cout << "�������" << endl;
					continue;
				}
				if (walk(false, index, nums, x, y)) {
					move(false, index, nums, x, y);
					shows();
					colors = -colors;
					color = true;
				}
				if (check(true))
					cout << "�ڷ�:������" << endl;
			}
		}
		if (win() == 1) {
			cout << "�췽ʤ��" << endl;
			break;
		}
		else if (win() == 2) {
			cout << "�ڷ�ʤ��" << endl;
			break;
		}
	}
}