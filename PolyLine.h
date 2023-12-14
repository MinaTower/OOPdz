#pragma once
#ifndef Lec7_23_PolyLine_H
#define Lec7_23_PolyLine_H
#include "Shape.h"
using namespace std;

class PolyLine :
    public Shape
{
	vector<POINT> pixels;
public:
	PolyLine();
	PolyLine(vector<POINT>&& obj);
	PolyLine(vector<POINT>& obj);
	//PolyLine& operator=(const PolyLine& obj);
	virtual void print();
	void copy(vector<Shape*>* here);
	virtual void paint(HDC hdc);
	virtual ~PolyLine();
};
#endif // Lec7_23_PolyLine_H