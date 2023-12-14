#include "Shape.h"
#include"DB.h"
#include <iostream>
#include<vector>
using namespace std;

DB::DB() {};
DB::DB(const DB& obj) {
	for (int i = 0; i < obj.ourdata.size(); i++) {
		obj.ourdata[i]->copy(&ourdata);
	};
};
DB& DB::operator=(const DB& obj) {
	if (obj.ourdata != this->ourdata) {
		for (int g = 0; g < ourdata.size(); g++) {
			delete ourdata[g];
		};
		ourdata.clear();
		for (int i = 0; i < obj.ourdata.size(); i++) {
			obj.ourdata[i]->copy(&ourdata);
		};
	};
	return *this;
};

void DB::adding(Shape* obj) { ourdata.push_back(obj); };
void DB::print() { for (int g = 0; g < ourdata.size(); g++) { ourdata[g]->print(); } };
DB::~DB() { for (int g = 0; g < ourdata.size(); g++) { delete ourdata[g]; } };