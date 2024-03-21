#include<iostream>
#include"Array.h"
#include<string>
#include<vector>
#include<sstream>
#include"可读棋盘.h"
using namespace std;

vector<string> getstr(string lines) {//提取字符串中单词
	vector<string>thisline;
	int pos = 0;
	for (int i = 0; i < lines.length(); i++) {
		if (i == lines.length() - 1) {
			thisline.push_back(lines.substr(pos, i - pos + 1));
		}
		if (lines[i] != 32)continue;
		else if (lines[i] == 32) {
			thisline.push_back(lines.substr(pos, i - pos));
			pos = i + 1;
		}
	}
	return thisline;
}

int main() {
	int color = 1;
	while (color == 1) {
		cout << "欢迎进入中国象棋游戏，请选择读取一个残局(Y)或开始新游戏(N):";
		char c;
		cin >> c;
		if (c == 'Y') {
			string file = "../标准棋局文件.txt";
			cout << "请输入残局文件目录:";
			cin >> file;
			Readable_Checkerboard ches(file);
			cout << "自定义对战" << endl;
			ches.miniature_chess_game();
			cout << "是否继续游戏(Y/N)";
			char b;
			cin >> b;
			if (b == 'N')
				color = 0;
		}
		else if (c == 'N') {
			Readable_Checkerboard ches;
			cout << "标准棋局对战" << endl;
			ches.Standard_chess_game();
			cout << "是否继续游戏(Y/N)";
			char b;
			cin >> b;
			if (b == 'N')
				color = 0;
		}
		else
			color = 0;
	}
	cout << "感谢您的使用，再见！" << endl;
	cout << "输入任意字符退出";
	char c;
	cin >> c;
	return 0;
}