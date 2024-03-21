#pragma once
#include<iostream>
using namespace std;
class Point
{
public:
	Point(int x = 0, int y = 0) { this->x_ = x; this->y_ = y; }
	Point(const Point& a) :x_(a.x_), y_(a.y_) { }
	Point& operator = (const Point& sm) {
		if (this == &sm)
			return *this;
		this->x_ = sm.x_; this->y_ = sm.y_;
		return *this;
	}
	bool operator == (const Point& sm) {
		return (this->x_ == sm.x_ && this->y_ == sm.y_);
	}
	bool operator != (const Point& sm) {
		return (this->x_ != sm.x_ || this->y_ != sm.y_);
	}
	~Point() {}
	int getx() { return x_; }
	int gety() { return y_; }
	void print() { cout << "(" << x_ << "," << y_ << ")" ; }
	
private:
	int x_; int y_;
};




