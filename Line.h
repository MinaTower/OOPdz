#pragma once
#ifndef Lec7_23_Line_H
#define Lec7_23_Line_H
#include "Shape.h"
#include <iostream>
using namespace std;


class Line :
    public Shape
{
	map<int, int> pixels;
public:
	Line();
	Line(/*const */ map<int, int>&& obj);
	Line(map<int, int>& obj);
	void copy(vector<Shape*>* here);
	virtual void print();
	virtual ~Line();
};
#endif // Lec7_23_Line_H here.push_back(new Sa) 