#pragma once
#include"Zemtseva.h"
#include"Zemtseva_1.h"
#include"Zemtseva_2.h"
#include "DB.h"
#include<vector>
#include <iostream>

DB::DB() {};
DB::DB(const DB& obj) {
	if (obj.ourdata != this->ourdata) {
		for (int i = 0; i < DB::ourdata.size(); i++) {
			delete DB::ourdata[i]; DB::ourdata[i] = NULL;
		};
		DB::ourdata.clear();
		for (int i = 0; i < obj.DB::ourdata.size(); i++) {
			(obj.DB::ourdata[i])->copy(DB::ourdata);
		};
	};
};
void DB::adding(Zemtseva* elem) { ourdata.push_back(elem); };
void DB::changing(int num) {
	for (int i = 0; i < ourdata.size(); i++) {
		ourdata[i]->changing_inf(num);
	};
};
DB& DB::operator=(const DB& obj) {
	if (obj.ourdata != this->ourdata) {
		for (int i = 0; i < DB::ourdata.size(); i++) {
			delete DB::ourdata[i]; DB::ourdata[i] = NULL;
		};
		DB::ourdata.clear();
		for (int i = 0; i < obj.DB::ourdata.size(); i++) {
			(obj.DB::ourdata[i])->copy(DB::ourdata);
		};
	};
	return *this;
};
void DB::print() {
	for (int i = 0; i < DB::ourdata.size(); i++) {
		DB::ourdata[i]->print_inf();
	};
	cout << endl;
};
DB::~DB() {
	for (int i = 0; i < DB::ourdata.size(); i++) {
		delete DB::ourdata[i]; DB::ourdata[i] = NULL;
	};
};