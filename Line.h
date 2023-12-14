#pragma once
#ifndef Lec7_23_Line_H
#define Lec7_23_Line_H
#include "Shape.h"
#include <iostream>
using namespace std;


class Line :
    public Shape
{
	vector<POINT> pixels;
public:
	Line();
	Line(vector<POINT>&& obj);
	Line(vector<POINT>& obj);
	void copy(vector<Shape*>* here);
	virtual void print();
	virtual void paint(HDC hdc);
	virtual ~Line();
};
#endif // Lec7_23_Line_H here.push_back(new Sa) 