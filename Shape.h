#pragma once
#include <iostream>
#include<map>
#include<vector>

using namespace std;


#ifndef Lec7_23_Shape_H
#define Lec7_23_Shape_H
class Shape
{
	map<int, int> pixels;
public:
	Shape();

	virtual void print() = 0;
	virtual void adding(int x, int y);
	virtual ~Shape();
	virtual void copy(vector<Shape*>* here);
};
#endif //Lec7_23_Shape_H