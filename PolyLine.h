#pragma once
#ifndef Lec7_23_PolyLine_H
#define Lec7_23_PolyLine_H
#include "Shape.h"
using namespace std;

class PolyLine :
    public Shape
{
	map<int, int> pixels;
public:
	PolyLine();
	PolyLine(/*const */ map<int, int>&& obj);
	PolyLine( map<int, int>& obj);
	//PolyLine& operator=(const PolyLine& obj);
	virtual void print();
	void copy(vector<Shape*>* here);
	virtual ~PolyLine();
};
#endif // Lec7_23_PolyLine_H