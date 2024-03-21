#include"chess.h"

chess::chess() {
	chessname = "chess";
	color = true;
	index = 0;
	alive = true;
}
chess::chess(string Chessname, bool Color, Point Position) :chessname(Chessname), color(Color), position(Position) {
	assert(position.getx() > 0 && position.getx() < 10);
	assert(position.gety() > 0 && position.gety() < 11);
	index = 0;
	alive = true;
}
inline chess::chess(chess& a) {
	chessname = a.chessname;
	color = a.color;
	index = a.index;
	alive = a.alive;
	position = a.position;
}
void chess::set_position(int x,int y)
{
	assert((x > 0 && x < 11)||(x==0&&y==0) || (x == 0 && y == 1));
	assert((y > 0 && y < 10)||(x==0&&y==0) || (x == 0 && y == 1));
	Point Position(x, y);
	position = Position;
}
string chess::getchessname()
{
	return chessname;
}
bool chess::getcolor()
{
	return color;
}
int chess::getindex()
{
	return index;
}
Point chess::getposition()
{
	return position;
}
void chess::setcolor(bool Color)
{
	this->color = Color;
}
void chess::setname(string name)
{
	this->chessname = name;
}
bool chess::isalive()
{
	return alive;
}
void chess::set_alive(bool Alive)
{
	this->alive = Alive;
}
void chess::setindex(int Index)
{
	this->index = Index;
}
chess& chess::operator=(const chess& sm)
{
	if (&sm == this)
		return *this;
	else {
		setname(sm.chessname);
		this->color = sm.color;
		this->index = sm.color;
		this->alive = sm.alive;
		this->position = sm.position;
		return *this;
	}
}
bool chess::operator==(const chess& sm)
{
	if (this == &sm)
		return true;
	else {
		if (chessname == sm.chessname &&
			color == sm.color &&
			index == sm.color &&
			alive == sm.alive &&
			position == sm.position)
			return true;
		else
			return false;
	}
}
bool chess::operator!=(const chess& sm)
{
	if (this == &sm)
		return false;
	else {
		if (this->chessname == sm.chessname &&
			this->color == sm.color &&
			this->index == sm.color &&
			this->alive == sm.alive &&
			this->position == sm.position)
			return false;
		else
			return true;
	}
}