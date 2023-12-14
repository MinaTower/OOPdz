#pragma once
#ifndef Lec622_Zemtseva_H
#define Lec622_Zemtseva_H
#include<vector>
using namespace std;

class Zemtseva {
public:
	Zemtseva();
	virtual void abst(int num)=0;
	virtual void changing_inf(int num);
	virtual void copy(vector<Zemtseva*>& copyhere);
	virtual void print_inf();
	virtual ~Zemtseva();
};
#endif //Lec6.22_Zemtseva_H