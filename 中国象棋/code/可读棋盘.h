#pragma once
#include"棋盘.h"
#include <iostream>
#include <vector>        //提供向量头文件
#include <algorithm>     // 算法头文件，提供迭代器
#include <fstream>       //提供文件头文件
#include <iomanip>       //C++输出精度控制需要
class Readable_Checkerboard:public virtual Checkerboard
{
public:
	Readable_Checkerboard();
	Readable_Checkerboard(const string filename);//读取路径残局
	void preservation();//保存残局
	void Standard_chess_game();//开始一局标准对战
	void miniature_chess_game();//开始一局残局对战

private:
	static int times;
	bool color;//先手方
};
int Readable_Checkerboard::times = 1;
Readable_Checkerboard::Readable_Checkerboard() { color = true; }
inline Readable_Checkerboard::Readable_Checkerboard(const string filename)
{
	color = true;
	for (int i = 1; i <= 14; i++)
		for (int j = 0; j < (*getallchess())[i].getSize(); j++)
			(*(*getallchess())[i][j]).set_alive(false);//全部置死
	ifstream file(filename);
	string lines;
	int line = 1;
	while (getline(file, lines))
	{
		if (lines.length() == 2) {
			if (lines == "红")
				color = true;
			else if (lines == "黑")
				color = false;
			else {
				cout << "文件格式错误！" << endl;
				cout << "重新启动标准化棋盘..." << endl;
				initialization();
				file.close();
				return;
			}
		}
		else {
			for (int i = 0; i < lines.length(); i += 2) {
				int pos = 0; string a = lines.substr(i, 2);
				if (a == "**")pos = 0;
				else if (a == "卒")pos = 1;
				else if (a == "将")pos = 2;
				else if (a == "車")pos = 3;
				else if (a == "士")pos = 4;
				else if (a == "砲")pos = 5;
				else if (a == "象")pos = 6;
				else if (a == "馬")pos = 7;
				else if (a == "兵")pos = 8;
				else if (a == "帅")pos = 9;
				else if (a == "俥")pos = 10;
				else if (a == "仕")pos = 11;
				else if (a == "炮")pos = 12;
				else if (a == "相")pos = 13;
				else if (a == "傌")pos = 14;
				else { 
					cout << "文件格式错误！" << endl;
					cout << "重新启动标准化棋盘..." << endl;
					initialization();
					file.close();
					return; 
				}
				set_checkerboard(line, i / 2 + 1, 0, pos);
				if (pos != 0) {
					for (int j = 0; j <= (*getallchess())[pos].getSize(); j++) {
						if (j == (*getallchess())[pos].getSize()) {
							cout << "error:" << a << ":数量过多！" << endl;
							cout << "重新启动标准化棋盘..." << endl;
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
	for (int i = 1; i <= 10; i++) {//验证读取的棋盘是否合理
		for (int j = 1; j <= 9; j++) {
			int index_ = getcheckerboard(i, j, 0);
			int nums_ = getcheckerboard(i, j, 1);
			if (index_ == 2) {//将
				if (i < 8 || j < 4 || j>6) {
					cout << "将:位置错误！" << endl;
					cout << "重新启动标准化棋盘..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 9) {//帅
				if (i > 3 || j < 4 || j>6) {
					cout << "帅:位置错误！" << endl;
					cout << "重新启动标准化棋盘..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 4) {//士
				if (!((i == 10 && j == 4)
					|| (i == 10 && j == 6)
					|| (i == 9 && j == 5)
					|| (i == 8 && j == 4)
					|| (i == 8 && j == 6))) {
					cout << "士:位置错误！" << endl;
					cout << "重新启动标准化棋盘..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 11) {//仕
				if (!((i == 1 && j == 4)
					|| (i == 1 && j == 6)
					|| (i == 2 && j == 5)
					|| (i == 3 && j == 4)
					|| (i == 3 && j == 6))) {
					cout << "仕:位置错误！" << endl;
					cout << "重新启动标准化棋盘..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 6) {//象
				if (!((i == 10 && j == 3) 
					|| (i == 10 && j == 7)
					|| (i == 8 && j == 1) 
					|| (i == 8 && j == 5) 
					|| (i == 8 && j == 9)
					|| (i == 6 && j == 3)
					|| (i == 6 && j == 7))) {
					cout << "象:位置错误！" << endl;
					cout << "重新启动标准化棋盘..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 13) {//相
				if (!((i == 1 && j == 3)
					|| (i == 1 && j == 7)
					|| (i == 3 && j == 1)
					|| (i == 3 && j == 5)
					|| (i == 3 && j == 9)
					|| (i == 5 && j == 3)
					|| (i == 5 && j == 7))) {
					cout << "相:位置错误！" << endl;
					cout << "重新启动标准化棋盘..." << endl;
					initialization();
					file.close();
					return;
				}
			}
			if (index_ == 1) {//卒
				if (i>7) {
					cout << "卒:位置错误！" << endl;
					cout << "重新启动标准化棋盘..." << endl;
					initialization();
					file.close();
					return;
				}
				if (i == 7) {
					if ((j != 1 )||( j != 3 )||( j != 5) ||( j != 7 )||( j != 9)) {
						cout << "卒:位置错误！" << endl;
						cout << "重新启动标准化棋盘..." << endl;
						initialization();
						file.close();
						return;
					}
					for (int k = 0; k < (*getallchess())[index_].getSize(); k++) {
						if (k == nums_)continue;
						if (!((*(*getallchess())[index_][k]).isalive()))break;
						if ((*(*getallchess())[index_][k]).getposition().getx() == 6
							&& (*(*getallchess())[index_][k]).getposition().gety() == j) {
							cout << "卒:位置错误！" << endl;
							cout << "重新启动标准化棋盘..." << endl;
							initialization();
							file.close();
							return;
						}
					}
					
				}
			}
			if (index_ == 8) {//兵
				if (i < 4) {
					cout << "兵:位置错误！" << endl;
					cout << "重新启动标准化棋盘..." << endl;
					initialization();
					file.close();
					return;
				}
				if (i == 4) {
					if ((j != 1) || (j != 3) || (j != 5) || (j != 7) || (j != 9)) {
						cout << "兵:位置错误！" << endl;
						cout << "重新启动标准化棋盘..." << endl;
						initialization();
						file.close();
						return;
					}
					for (int k = 0; k < (*getallchess())[index_].getSize(); k++) {
						if (k == nums_)continue;
						if (!((*(*getallchess())[index_][k]).isalive()))break;
						if ((*(*getallchess())[index_][k]).getposition().getx() == 5
							&& (*(*getallchess())[index_][k]).getposition().gety() == j) {
							cout << "兵:位置错误！" << endl;
							cout << "重新启动标准化棋盘..." << endl;
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
	string file = "./images/输出残局"; nums += ".txt"; file += nums;
	ofstream mycout(file);
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 9; j++) {
			switch (getcheckerboard(i,j,0))
			{
			case 0:mycout << "**"; break;
			case 1:mycout << "卒"; break;
			case 2:mycout << "将"; break;
			case 3:mycout << "車"; break;
			case 4:mycout << "士"; break;
			case 5:mycout << "砲"; break;
			case 6:mycout << "象"; break;
			case 7:mycout << "馬"; break;
			case 8:mycout << "兵"; break;
			case 9:mycout << "帅"; break;
			case 10:mycout << "俥"; break;
			case 11:mycout << "仕"; break;
			case 12:mycout << "炮"; break;
			case 13:mycout << "相"; break;
			case 14:mycout << "傌"; break;
			default:
				break;
			}
		}
		mycout << endl;
	}
	if (color)
		mycout << "红" << endl;
	else
		mycout << "黑" << endl;
	mycout.close();
	times++;
	cout << "文件已保存到" << file << endl;
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
	string index_rule = "编号如下:\n兵(卒)1\n帅(将)2\n俥(車)3\n仕(士)4\n炮(砲)5\n相(象)6\n傌(馬)7";
	while (true) {
		string line = "1"; int nums = 1, x = 1, y = 1;
		if (colors == 1) {
			cout << "红方:";
			cin >> line;
			if (line == "index") {
				cout << index_rule << endl;
				cout << "输入任意字符继续";
				char c;
				cin >> c;
				shows();
				continue;
			}
			else if (line == "0") {
				cout << "红方投降，黑方胜利！" << endl;
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
					cout << "输入错误！" << endl;
					continue;
				}
				if (walk(true, index, nums, x, y)) {
					move(true, index, nums, x, y);
					shows();
					colors = -colors;
					color = false;
				}
				if (check(false))
					cout << "红方:将军！" << endl;
			}
		}
		else if (colors == -1) {
			cout << "黑方:";
			cin >> line;
			if (line == "index") {
				cout << index_rule << endl;
				cout << "输入任意字符继续";
				char c;
				cin >> c;
				shows();
				continue;
			}
			else if (line == "0") {
				cout << "黑方投降，红方胜利！" << endl;
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
					cout << "输入错误！" << endl;
					continue;
				}
				if (walk(false, index, nums, x, y)) {
					move(false, index, nums, x, y);
					shows();
					colors = -colors;
					color = true;
				}
				if (check(true))
					cout << "黑方:将军！" << endl;
			}
		}
		if (win() == 1) {
			cout << "红方胜利" << endl;
			break;
		}
		else if (win() == 2) {
			cout << "黑方胜利" << endl;
			break;
		}
	}
}