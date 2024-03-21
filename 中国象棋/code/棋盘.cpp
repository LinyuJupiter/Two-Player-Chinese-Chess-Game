#include"棋盘.h"
int Checkerboard::checker = 0;
Checkerboard::Checkerboard()
{
	checker += 1;
	assert(checker <= 1);
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 2; k++)
				checkerboard[i][j][k] = 0;//初始清空棋盘
	allchess.resize(15);
	allchess[0].resize(1);//第0行存放空格
	allchess[1].resize(5);//按照index存放棋子
	allchess[2].resize(1);
	for (int i = 3; i <= 7; i++)
		allchess[i].resize(2);
	allchess[8].resize(5);
	allchess[9].resize(1);
	for (int i = 10; i <= 14; i++)
		allchess[i].resize(2);
	allchess[0][0] = &kongge;//棋子逐一存放
	allchess[1][0] = &zu6;
	allchess[1][1] = &zu7;
	allchess[1][2] = &zu8;
	allchess[1][3] = &zu9;
	allchess[1][4] = &zu10;
	allchess[2][0] = &jiang2;
	allchess[3][0] = &ju3;
	allchess[3][1] = &ju4;
	allchess[4][0] = &shi3;
	allchess[4][1] = &shi4;
	allchess[5][0] = &pao3;
	allchess[5][1] = &pao4;
	allchess[6][0] = &xiang3;
	allchess[6][1] = &xiang4;
	allchess[7][0] = &ma3;
	allchess[7][1] = &ma4;
	allchess[8][0] = &zu1;
	allchess[8][1] = &zu2;
	allchess[8][2] = &zu3;
	allchess[8][3] = &zu4;
	allchess[8][4] = &zu5;
	allchess[9][0] = &jiang1;
	allchess[10][0] = &ju1;
	allchess[10][1] = &ju2;
	allchess[11][0] = &shi1;
	allchess[11][1] = &shi2;
	allchess[12][0] = &pao1;
	allchess[12][1] = &pao2;
	allchess[13][0] = &xiang1;
	allchess[13][1] = &xiang2;
	allchess[14][0] = &ma1;
	allchess[14][1] = &ma2;
	for (int i = 1; i <= 7; i++) //黑棋赋初值
		for (int j = 0; j < allchess[i].getSize(); j++)
			(*allchess[i][j]).set(false);
	for (int i = 8; i <= 14; i++)//红棋赋初值
		for (int j = 0; j < allchess[i].getSize(); j++)
			(*allchess[i][j]).set(true);
}
Checkerboard::~Checkerboard()
{
	checker--;
}
int Checkerboard::getcheckerboard(int i, int j, int k)
{
	assert(0 <= i <= 10);
	assert(0 <= j <= 9);
	assert(0 <= k <= 1);
	return checkerboard[i][j][k];
}
Array<Array<chess*>>* Checkerboard::getallchess()
{
	return &allchess;
}
void Checkerboard::set_checkerboard(int i, int j, int k, int value)
{
	assert(0 <= i <= 10);
	assert(0 <= j <= 9);
	assert(0 <= k <= 1);
	checkerboard[i][j][k] = value;
}
void Checkerboard::initialization()
{
	for (int i = 0; i < 11; i++)
		for (int j = 0; j < 10; j++)
			for (int k = 0; k < 2; k++)
				checkerboard[i][j][k] = 0;//初始清空棋盘
	for (int i = 0; i < allchess.getSize(); i++)
		for (int j = 0; j < allchess[i].getSize(); j++)
			(*allchess[i][j]).set_alive(true);
	//红
	checkerboard[1][1][0] = 10, checkerboard[1][1][1] = 0; (*allchess[10][0]).set_position(1, 1);//俥1
	checkerboard[1][2][0] = 14, checkerboard[1][2][1] = 0; (*allchess[14][0]).set_position(1, 2);//傌1
	checkerboard[1][3][0] = 13, checkerboard[1][3][1] = 0; (*allchess[13][0]).set_position(1, 3);//相1
	checkerboard[1][4][0] = 11, checkerboard[1][4][1] = 0; (*allchess[11][0]).set_position(1, 4);//仕1
	checkerboard[1][5][0] = 9, checkerboard[1][5][1] = 0; (*allchess[9][0]).set_position(1, 5);//帅
	checkerboard[1][6][0] = 11, checkerboard[1][6][1] = 1; (*allchess[11][1]).set_position(1, 6);//仕2
	checkerboard[1][7][0] = 13, checkerboard[1][7][1] = 1; (*allchess[13][1]).set_position(1, 7);//相2
	checkerboard[1][8][0] = 14, checkerboard[1][8][1] = 1; (*allchess[14][1]).set_position(1, 8);//傌2
	checkerboard[1][9][0] = 10, checkerboard[1][9][1] = 1; (*allchess[10][1]).set_position(1, 9);//俥2
	checkerboard[3][2][0] = 12, checkerboard[3][2][1] = 0; (*allchess[12][0]).set_position(3, 2);//炮1
	checkerboard[3][8][0] = 12, checkerboard[3][8][1] = 1; (*allchess[12][1]).set_position(3, 8);//炮2
	checkerboard[4][1][0] = 8, checkerboard[4][1][1] = 0; (*allchess[8][0]).set_position(4, 1);//兵1
	checkerboard[4][3][0] = 8, checkerboard[4][3][1] = 1; (*allchess[8][1]).set_position(4, 3);//兵2
	checkerboard[4][5][0] = 8, checkerboard[4][5][1] = 2; (*allchess[8][2]).set_position(4, 5);//兵3
	checkerboard[4][7][0] = 8, checkerboard[4][7][1] = 3; (*allchess[8][3]).set_position(4, 7);//兵4
	checkerboard[4][9][0] = 8, checkerboard[4][9][1] = 4; (*allchess[8][4]).set_position(4, 9);//兵5
	//黑
	checkerboard[10][1][0] = 3, checkerboard[10][1][1] = 0; (*allchess[3][0]).set_position(10, 1);//車1
	checkerboard[10][2][0] = 7, checkerboard[10][2][1] = 0; (*allchess[7][0]).set_position(10, 2);//馬1
	checkerboard[10][3][0] = 6, checkerboard[10][3][1] = 0; (*allchess[6][0]).set_position(10, 3);//象1
	checkerboard[10][4][0] = 4, checkerboard[10][4][1] = 0; (*allchess[4][0]).set_position(10, 4);//士1
	checkerboard[10][5][0] = 2, checkerboard[10][5][1] = 0; (*allchess[2][0]).set_position(10, 5);//将
	checkerboard[10][6][0] = 4, checkerboard[10][6][1] = 1; (*allchess[4][1]).set_position(10, 6);//士2
	checkerboard[10][7][0] = 6, checkerboard[10][7][1] = 1; (*allchess[6][1]).set_position(10, 7);//象2
	checkerboard[10][8][0] = 7, checkerboard[10][8][1] = 1; (*allchess[7][1]).set_position(10, 8);//馬2
	checkerboard[10][9][0] = 3, checkerboard[10][9][1] = 1; (*allchess[3][1]).set_position(10, 9);//車2
	checkerboard[8][2][0] = 5, checkerboard[8][2][1] = 0; (*allchess[5][0]).set_position(8, 2);//砲1
	checkerboard[8][8][0] = 5, checkerboard[8][8][1] = 1; (*allchess[5][1]).set_position(8, 8);//砲2
	checkerboard[7][1][0] = 1, checkerboard[7][1][1] = 0; (*allchess[1][0]).set_position(7, 1);//卒1
	checkerboard[7][3][0] = 1, checkerboard[7][3][1] = 1; (*allchess[1][1]).set_position(7, 3);//卒2
	checkerboard[7][5][0] = 1, checkerboard[7][5][1] = 2; (*allchess[1][2]).set_position(7, 5);//卒3
	checkerboard[7][7][0] = 1, checkerboard[7][7][1] = 3; (*allchess[1][3]).set_position(7, 7);//卒4
	checkerboard[7][9][0] = 1, checkerboard[7][9][1] = 4; (*allchess[1][4]).set_position(7, 9);//卒5
}
void Checkerboard::shows()
{
	cout << "_______________________________________" << endl;
	for (int i = 1; i <= 10; i++) {
		cout << setw(3) << i;
		for (int j = 1; j <= 9; j++) {
			if (checkerboard[i][j][0] != 0)
				cout << setw(3) << (*allchess[checkerboard[i][j][0]][checkerboard[i][j][1]]).getchessname() << " ";
			else
				cout << "    ";
		}
		cout << endl;
		if (i == 5)
			cout << "   ---楚河---------------------汉界---\n";
		else
			cout << endl;
	}
	cout << setw(4) << "  ";
	for (int j = 1; j <= 9; j++)
		cout << std::left << setw(4) << j;
	cout << endl << endl;
}
bool Checkerboard::initial_walk(bool Color, int INDEX, int nums, int x, int y)
{
	int Index = INDEX;
	if (Color)
		Index += 7;
	Point Position(x, y);
	if (!(*allchess[Index][nums - 1]).isalive()) {
		cout << "error:死亡的棋子不可移动" << endl;
		return false;
	}//死亡的棋子不可移动
	if (!(*allchess[Index][nums - 1]).move(Position)) {
		cout << "error:不符合规则不可移动" << endl;
		return false;
	}//不符合规则不可移动
	if (
		(checkerboard[x][y][0] != 0)
		&& ((*allchess[checkerboard[x][y][0]][checkerboard[x][y][1]]).getcolor() == Color)
		) {//不可以吃自己的棋子
		cout << "error:不可以吃自己的棋子" << endl;
		return false;
	}
	if (INDEX == 7) {//马
		int x_ = (*allchess[Index][nums - 1]).getposition().getx();
		int y_ = (*allchess[Index][nums - 1]).getposition().gety();
		if (x == x_ - 2) {//卡马脚
			if (checkerboard[x_ - 1][y_][0] != 0) {
				cout << "error:卡马脚" << endl;
				return false;
			}
		}
		else if (x == x_ + 2) {
			if (checkerboard[x_ + 1][y_][0] != 0) {
				cout << "error:卡马脚" << endl;
				return false;
			}
		}
		else if (y == y_ - 2) {
			if (checkerboard[x_][y_ - 1][0] != 0) {
				cout << "error:卡马脚" << endl;
				return false;
			}
		}
		else if (y == y_ + 2) {
			if (checkerboard[x_][y_ + 1][0] != 0) {
				cout << "error:卡马脚" << endl;
				return false;
			}
		}
	}
	if (INDEX == 6) {//象
		int x_ = (*allchess[Index][nums - 1]).getposition().getx();
		int y_ = (*allchess[Index][nums - 1]).getposition().gety();
		int tx = (x + x_) / 2;
		int ty = (y + y_) / 2;
		if (checkerboard[tx][ty][0] != 0) {
			cout << "error:卡象脚" << endl;
			return false;
		}//卡象脚
	}
	if (INDEX == 3) {//车
		int x_ = (*allchess[Index][nums - 1]).getposition().getx();
		int y_ = (*allchess[Index][nums - 1]).getposition().gety();
		if (x == x_) {//横着走
			if (y > y_) {//向右走
				for (int i = y_ + 1; i < y; i++)
					if (checkerboard[x_][i][0] != 0) {
						cout << "error:不能穿过棋子" << endl;
						return false;
					}//不能穿过棋子
			}
			if (y < y_) {//向左走
				for (int i = y + 1; i < y_; i++)
					if (checkerboard[x_][i][0] != 0) {
						cout << "error:不能穿过棋子" << endl;
						return false;
					}//不能穿过棋子
			}
		}
		if (y == y_) {//竖着走
			if (x > x_) {//向下走
				for (int i = x_ + 1; i < x; i++)
					if (checkerboard[i][y_][0] != 0) {
						cout << "error:不能穿过棋子" << endl;
						return false;
					}//不能穿过棋子
			}
			if (x < x_) {//向上走
				for (int i = x + 1; i < x_; i++)
					if (checkerboard[i][y_][0] != 0) {
						cout << "error:不能穿过棋子" << endl;
						return false;
					}//不能穿过棋子
			}
		}
	}
	if (INDEX == 5) {//炮
		int x_ = (*allchess[Index][nums - 1]).getposition().getx();
		int y_ = (*allchess[Index][nums - 1]).getposition().gety();
		if (
			(checkerboard[x][y][0] != 0)
			&& ((*allchess[checkerboard[x][y][0]][checkerboard[x][y][1]]).getcolor() != Color)
			) {//炮吃棋子,须隔着炮台
			int num = 0;//中间隔着的棋子数
			if (x == x_) {//横着走
				if (y > y_) {//向右走
					for (int i = y_ + 1; i < y; i++)
						if (checkerboard[x_][i][0] != 0)
							num++;
					if (num != 1) {//炮只能隔一个炮台
						cout << "error:炮只能隔一个炮台" << endl;
						return false;
					}
				}
				if (y < y_) {//向左走
					for (int i = y + 1; i < y_; i++)
						if (checkerboard[x_][i][0] != 0)
							num++;
					if (num != 1) {
						cout << "error:炮只能隔一个炮台" << endl;
						return false;
					}
				}
			}
			if (y == y_) {//竖着走
				if (x > x_) {//向下走
					for (int i = x_ + 1; i < x; i++)
						if (checkerboard[i][y_][0] != 0)
							num++;
					if (num != 1) {
						cout << "error:炮只能隔一个炮台" << endl;
						return false;
					}
				}
				if (x < x_) {//向上走
					for (int i = x + 1; i < x_; i++)
						if (checkerboard[i][y_][0] != 0)
							num++;
					if (num != 1) {
						cout << "error:炮只能隔一个炮台" << endl;
						return false;
					}
				}
			}
		}
		else {
			if (x == x_) {//横着走
				if (y > y_) {//向右走
					for (int i = y_ + 1; i < y; i++)
						if (checkerboard[x_][i][0] != 0) {
							cout << "error:不能穿过棋子" << endl;
							return false;
						}//不能穿过棋子
				}
				if (y < y_) {//向左走
					for (int i = y + 1; i < y_; i++)
						if (checkerboard[x_][i][0] != 0) {
							cout << "error:不能穿过棋子" << endl;
							return false;
						}//不能穿过棋子
				}
			}
			if (y == y_) {//竖着走
				if (x > x_) {//向下走
					for (int i = x_ + 1; i < x; i++)
						if (checkerboard[i][y_][0] != 0) {
							cout << "error:不能穿过棋子" << endl;
							return false;
						}//不能穿过棋子
				}
				if (x < x_) {//向上走
					for (int i = x + 1; i < x_; i++)
						if (checkerboard[i][y_][0] != 0) {
							cout << "error:不能穿过棋子" << endl;
							return false;
						}//不能穿过棋子
				}
			}
		}
	}
	bool feijiang = true;//以下回溯法判断是否飞将
	int x_ = (*allchess[Index][nums - 1]).getposition().getx();//棋子原位置
	int y_ = (*allchess[Index][nums - 1]).getposition().gety();
	int x0 = checkerboard[x][y][0], y0 = checkerboard[x][y][1];
	if (!(x0 == 0 && y0 == 0)) {//若该位置有棋子
		(*allchess[x0][y0]).set_position(0, 1);
	}//将该位置棋子移到（0,1）暂存
	(*allchess[Index][nums - 1]).set_position(x, y);//将棋子移到（x，y）
	checkerboard[x_][y_][0] = checkerboard[x_][y_][1] = 0;
	checkerboard[x][y][0] = Index;
	checkerboard[x][y][1] = nums - 1;
	if ((*allchess[2][0]).getposition().gety() == (*allchess[9][0]).getposition().gety()) {//判断飞将
		int j = (*allchess[2][0]).getposition().gety();
		feijiang = false;
		for (int i = (*allchess[9][0]).getposition().getx() + 1; i < (*allchess[2][0]).getposition().getx(); i++) {
			if (checkerboard[i][j][0] != 0) {
				feijiang = true;
				break;
			}
		}
		if (!feijiang)
			cout << "error:将帅不可见面" << endl;
	}
	if (check(Color)) {
		feijiang = false;
		cout << "error:会导致被将军！" << endl;
	}
	if (!(x0 == 0 && y0 == 0)) {//回溯
		(*allchess[x0][y0]).set_position(x, y);
	}
	(*allchess[Index][nums - 1]).set_position(x_, y_);
	checkerboard[x_][y_][0] = Index;
	checkerboard[x_][y_][1] = nums - 1;
	checkerboard[x][y][0] = x0;
	checkerboard[x][y][1] = y0;
	return feijiang;
}
bool Checkerboard::unitial_walk(bool Color, int INDEX, int nums, int x, int y)
{
	int Index = INDEX;
	if (Color)
		Index += 7;
	Point Position(x, y);
	if (!(*allchess[Index][nums - 1]).isalive()) {
		return false;
	}//死亡的棋子不可移动
	if (!(*allchess[Index][nums - 1]).move(Position)) {
		return false;
	}//不符合规则不可移动
	if (
		(checkerboard[x][y][0] != 0)
		&& ((*allchess[checkerboard[x][y][0]][checkerboard[x][y][1]]).getcolor() == Color)
		) {//不可以吃自己的棋子
		return false;
	}
	if (INDEX == 7) {//马
		int x_ = (*allchess[Index][nums - 1]).getposition().getx();
		int y_ = (*allchess[Index][nums - 1]).getposition().gety();
		if (x == x_ - 2) {//卡马脚
			if (checkerboard[x_ - 1][y_][0] != 0) {
				return false;
			}
		}
		else if (x == x_ + 2) {
			if (checkerboard[x_ + 1][y_][0] != 0) {
				return false;
			}
		}
		else if (y == y_ - 2) {
			if (checkerboard[x_][y_ - 1][0] != 0) {
				return false;
			}
		}
		else if (y == y_ + 2) {
			if (checkerboard[x_][y_ + 1][0] != 0) {
				return false;
			}
		}
	}
	if (INDEX == 6) {//象
		int x_ = (*allchess[Index][nums - 1]).getposition().getx();
		int y_ = (*allchess[Index][nums - 1]).getposition().gety();
		int tx = (x + x_) / 2;
		int ty = (y + y_) / 2;
		if (checkerboard[tx][ty][0] != 0) {
			return false;
		}//卡象脚
	}
	if (INDEX == 3) {//车
		int x_ = (*allchess[Index][nums - 1]).getposition().getx();
		int y_ = (*allchess[Index][nums - 1]).getposition().gety();
		if (x == x_) {//横着走
			if (y > y_) {//向右走
				for (int i = y_ + 1; i < y; i++)
					if (checkerboard[x_][i][0] != 0) {
						return false;
					}//不能穿过棋子
			}
			if (y < y_) {//向左走
				for (int i = y + 1; i < y_; i++)
					if (checkerboard[x_][i][0] != 0) {
						return false;
					}//不能穿过棋子
			}
		}
		if (y == y_) {//竖着走
			if (x > x_) {//向下走
				for (int i = x_ + 1; i < x; i++)
					if (checkerboard[i][y_][0] != 0) {
						return false;
					}//不能穿过棋子
			}
			if (x < x_) {//向上走
				for (int i = x + 1; i < x_; i++)
					if (checkerboard[i][y_][0] != 0) {
						return false;
					}//不能穿过棋子
			}
		}
	}
	if (INDEX == 5) {//炮
		int x_ = (*allchess[Index][nums - 1]).getposition().getx();
		int y_ = (*allchess[Index][nums - 1]).getposition().gety();
		if (
			(checkerboard[x][y][0] != 0)
			&& ((*allchess[checkerboard[x][y][0]][checkerboard[x][y][1]]).getcolor() != Color)
			) {//炮吃棋子,须隔着炮台
			int num = 0;//中间隔着的棋子数
			if (x == x_) {//横着走
				if (y > y_) {//向右走
					for (int i = y_ + 1; i < y; i++)
						if (checkerboard[x_][i][0] != 0)
							num++;
					if (num != 1) {//炮只能隔一个炮台
						return false;
					}
				}
				if (y < y_) {//向左走
					for (int i = y + 1; i < y_; i++)
						if (checkerboard[x_][i][0] != 0)
							num++;
					if (num != 1) {
						return false;
					}
				}
			}
			if (y == y_) {//竖着走
				if (x > x_) {//向下走
					for (int i = x_ + 1; i < x; i++)
						if (checkerboard[i][y_][0] != 0)
							num++;
					if (num != 1) {
						return false;
					}
				}
				if (x < x_) {//向上走
					for (int i = x + 1; i < x_; i++)
						if (checkerboard[i][y_][0] != 0)
							num++;
					if (num != 1) {
						return false;
					}
				}
			}
		}
		else {
			if (x == x_) {//横着走
				if (y > y_) {//向右走
					for (int i = y_ + 1; i < y; i++)
						if (checkerboard[x_][i][0] != 0) {
							return false;
						}//不能穿过棋子
				}
				if (y < y_) {//向左走
					for (int i = y + 1; i < y_; i++)
						if (checkerboard[x_][i][0] != 0) {
							return false;
						}//不能穿过棋子
				}
			}
			if (y == y_) {//竖着走
				if (x > x_) {//向下走
					for (int i = x_ + 1; i < x; i++)
						if (checkerboard[i][y_][0] != 0) {
							return false;
						}//不能穿过棋子
				}
				if (x < x_) {//向上走
					for (int i = x + 1; i < x_; i++)
						if (checkerboard[i][y_][0] != 0) {
							return false;
						}//不能穿过棋子
				}
			}
		}
	}
	bool feijiang = true;//以下回溯法判断是否飞将
	int x_ = (*allchess[Index][nums - 1]).getposition().getx();//棋子原位置
	int y_ = (*allchess[Index][nums - 1]).getposition().gety();
	int x0 = checkerboard[x][y][0], y0 = checkerboard[x][y][1];
	(*allchess[x0][y0]).set_position(0, 1);//将该位置棋子移到（0,1）暂存
	(*allchess[Index][nums - 1]).set_position(x, y);//将棋子移到（x，y）
	checkerboard[x_][y_][0] = checkerboard[x_][y_][1] = 0;
	checkerboard[x][y][0] = Index;
	checkerboard[x][y][1] = nums - 1;
	if ((*allchess[2][0]).getposition().gety() == (*allchess[9][0]).getposition().gety()) {
		int j = (*allchess[2][0]).getposition().gety();
		feijiang = false;
		for (int i = (*allchess[9][0]).getposition().getx() + 1; i < (*allchess[2][0]).getposition().getx(); i++) {
			if (checkerboard[i][j] != 0) {
				feijiang = true;
				break;
			}
		}
	}
	(*allchess[x0][y0]).set_position(x, y);//回溯
	(*allchess[Index][nums - 1]).set_position(x_, y_);
	checkerboard[x_][y_][0] = Index;
	checkerboard[x_][y_][1] = nums - 1;
	checkerboard[x][y][0] = x0;
	checkerboard[x][y][1] = y0;
	return feijiang;
}
int Checkerboard::win()
{
	if (!(*allchess[2][0]).isalive())//黑将死
		return 1;
	else if (!(*allchess[9][0]).isalive())//红将死
		return 2;
	else
		return 0;
}
void Checkerboard::move(bool Color, int INDEX, int nums, int x, int y)
{
	int Index = INDEX;
	if (Color)
		Index += 7;
	Point Position(x, y);
	if (
		(checkerboard[x][y][0] != 0)
		&& ((*allchess[checkerboard[x][y][0]][checkerboard[x][y][1]]).getcolor() != Color)
		) {//吃对方的棋子
		int x_ = (*allchess[Index][nums - 1]).getposition().getx();
		int y_ = (*allchess[Index][nums - 1]).getposition().gety();
		(*allchess[checkerboard[x][y][0]][checkerboard[x][y][1]]).set_alive(false);//对方棋子死亡
		(*allchess[checkerboard[x][y][0]][checkerboard[x][y][1]]).set_position(0, 0);//对方棋子移到原点
		(*allchess[checkerboard[x_][y_][0]][checkerboard[x_][y_][1]]).set_position(x, y);//己方棋子移过去
		checkerboard[x_][y_][0] = checkerboard[x_][y_][1] = 0;
		checkerboard[x][y][0] = Index;
		checkerboard[x][y][1] = nums - 1;
	}
	if (checkerboard[x][y][0] == 0) {//空位
		int x_ = (*allchess[Index][nums - 1]).getposition().getx();
		int y_ = (*allchess[Index][nums - 1]).getposition().gety();
		(*allchess[checkerboard[x_][y_][0]][checkerboard[x_][y_][1]]).set_position(x, y);//己方棋子移过去
		checkerboard[x_][y_][0] = checkerboard[x_][y_][1] = 0;
		checkerboard[x][y][0] = Index;
		checkerboard[x][y][1] = nums - 1;
	}
}
bool Checkerboard::check(bool Color)
{
	if (Color) {//红方被将军
		int x = (*allchess[9][0]).getposition().getx();
		int y = (*allchess[9][0]).getposition().gety();
		for (int i = 1; i <= 7; i++) {
			for (int j = 0; j < allchess[i].getSize(); j++) {
				if ((*allchess[i][j]).isalive())
					if (unitial_walk(false, i, j + 1, x, y))
						return true;
			}
		}
	}
	else {
		int x = (*allchess[2][0]).getposition().getx();
		int y = (*allchess[2][0]).getposition().gety();
		for (int i = 8; i <= 14; i++) {
			for (int j = 0; j < allchess[i].getSize(); j++) {
				if ((*allchess[i][j]).isalive())
					if (unitial_walk(true, i - 7, j + 1, x, y))
						return true;
			}
		}
	}
	return false;
}
bool Checkerboard::walk(bool Color, int INDEX, int nums, int x, int y)
{
	if (!initial_walk(Color, INDEX, nums, x, y))
		return false;
	if (check(Color)) {
		cout << "warning:你正在被将军！" << endl;
		cout << "Are you sure (Y/N):";
		char c;
		cin >> c;
		if (c == 'N')
			return false;
	}
	return true;
}
void Checkerboard::Standard_chess_game()
{
	initialization();
	shows();
	int color = 1;
	string index_rule = "编号如下:\n兵(卒)1\n帅(将)2\n俥(車)3\n仕(士)4\n炮(砲)5\n相(象)6\n傌(馬)7";
	while (true) {
		string line = "1"; int nums = 1, x = 1, y = 1;
		if (color == 1) {
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
			else {
				cin >> nums >> x >> y;
				int index = str_to_int(line);
				if (
					(index < 1 || index>7)
					|| (nums<1 || nums>allchess[index + 7].getSize())
					|| (x < 1 || x>10)
					|| (y < 1 || y>9)
					) {
					cout << "输入错误！" << endl;
					continue;
				}
				if (walk(true, index, nums, x, y)) {
					move(true, index, nums, x, y);
					shows();
					color = -color;
				}
				if (check(false))
					cout << "红方:将军！" << endl;
			}
		}
		else if (color == -1) {
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
			else {
				cin >> nums >> x >> y;
				int index = str_to_int(line);
				if (
					(index < 1 || index>7)
					|| (nums<1 || nums>allchess[index].getSize())
					|| (x < 1 || x>10)
					|| (y < 1 || y>9)
					) {
					cout << "输入错误！" << endl;
					continue;
				}
				if (walk(false, index, nums, x, y)) {
					move(false, index, nums, x, y);
					shows();
					color = -color;
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
