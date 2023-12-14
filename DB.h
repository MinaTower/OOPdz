#pragma once
#ifndef Lec7_23_DB_H
#define Lec7_23_DB_H

#include "Shape.h"
#include <iostream>
#include<vector>
using namespace std;

class DB
{
	vector<Shape*> ourdata;
public:
	DB();
	DB(const DB& obj);
	DB& operator=(const DB& obj);
	virtual void adding(Shape* obj);
	void print() ;
	~DB();
};
#endif // Lec7_23_DB_H
