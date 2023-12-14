#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#pragma once
#include"Zemtseva.h"
#include"Zemtseva_1.h"
#include"Zemtseva_2.h"
#include "DB.h"
#include<vector>
using namespace std;

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

void change(DB& data, int num) { data.changing(num); };//changes _1 only!

int main()
{
	Zemtseva_1* a1 = new Zemtseva_1();
	Zemtseva_1* a2 = new Zemtseva_1();
	Zemtseva_1* b1 = new Zemtseva_2();
	Zemtseva_1* b2 = new Zemtseva_2();
	DB* db1 = new DB();
	db1->adding(a1);
	db1->adding(a2);
	db1->adding(b1);
	db1->adding(b2);

	change(*db1, 55);

	DB db2(*db1), db3;
	delete db1;
	db3 = db2;
	db3 = db3;
	db3.print();

	return 0;
};