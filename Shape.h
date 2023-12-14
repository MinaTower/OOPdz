#pragma once
#include "framework.h"
#include<vector>
#include <iostream>

using namespace std;

#ifndef Lec7_23_Shape_H
#define Lec7_23_Shape_H
class Shape
{
	vector<POINT> pixels;
public:
	Shape();
	virtual void print() = 0;
	//virtual void adding(int x, int y);
	virtual ~Shape();
	virtual void copy(vector<Shape*>* here);
	virtual void paint(HDC hdc) =0;

};
#endif //Lec7_23_Shape_H