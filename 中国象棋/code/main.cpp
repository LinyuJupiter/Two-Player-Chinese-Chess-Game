#include<iostream>
#include"Array.h"
#include<string>
#include<vector>
#include<sstream>
#include"�ɶ�����.h"
using namespace std;

vector<string> getstr(string lines) {//��ȡ�ַ����е���
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
		cout << "��ӭ�����й�������Ϸ����ѡ���ȡһ���о�(Y)��ʼ����Ϸ(N):";
		char c;
		cin >> c;
		if (c == 'Y') {
			string file = "../��׼����ļ�.txt";
			cout << "������о��ļ�Ŀ¼:";
			cin >> file;
			Readable_Checkerboard ches(file);
			cout << "�Զ����ս" << endl;
			ches.miniature_chess_game();
			cout << "�Ƿ������Ϸ(Y/N)";
			char b;
			cin >> b;
			if (b == 'N')
				color = 0;
		}
		else if (c == 'N') {
			Readable_Checkerboard ches;
			cout << "��׼��ֶ�ս" << endl;
			ches.Standard_chess_game();
			cout << "�Ƿ������Ϸ(Y/N)";
			char b;
			cin >> b;
			if (b == 'N')
				color = 0;
		}
		else
			color = 0;
	}
	cout << "��л����ʹ�ã��ټ���" << endl;
	cout << "���������ַ��˳�";
	char c;
	cin >> c;
	return 0;
}