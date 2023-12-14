#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#pragma once
#include"Shape.h"
#include"Line.h"
#include"PolyLine.h"
#include"DB.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

struct coordinates {
	int x;
	int y;
};
int str_to_int(string&& obj, int ans = 0) {
	for (int i = 0; i < obj.size(); i++) { 
		ans = ans * 10 + (obj[i]-48); 
	};
	return ans;
};

coordinates get_coordinates(coordinates* ans,const string& inf, size_t s_elem, size_t e_elem) {
	string x_s, y_s;
	bool part_flag = false;
	int j;
	for (j = s_elem; j < e_elem; j++) {
		if (inf[j] == ',') { part_flag = true; continue; }
		else if (inf[j] == ';') { break; };
		if (part_flag == false) { x_s += inf[j]; }
		else { y_s += inf[j]; };
	};
	ans->x = str_to_int(move(x_s));
	ans->y = str_to_int(move(y_s));
	return *ans;
};


int main()
{
	DB storage;
	ifstream ifile;
	ifile.open("pixels.hpgl");
	string f_information;
	//cout << ifile.is_open();
	string shape_part;
	ifile >> f_information;
	for (int i = f_information.find("SP1;") + 4; i < (f_information.rfind("SP;")+2); i+=1) {
		shape_part += f_information[i];	
	};
	for (int i = 1 + shape_part.find("PU"); i < shape_part.rfind("SP"); i += 0) {
		shape_part[i - 1] = '-';
		shape_part[i] = '-';
		bool pu_flag = true;
		map<int, int> pu;
		for (i = shape_part.find("PA"); i < min(shape_part.find("PU;"), shape_part.rfind(";SP")); i += 0) {
			shape_part[i] = '-';
			shape_part[i + 1] = '-';
			i += 2;
			int i_end = min(min(shape_part.rfind(";SP"), shape_part.find(";PU")), min(shape_part.find(";PA"), shape_part.find(";PD")));
			coordinates c = get_coordinates(&c, shape_part, i, i_end);
			if (pu_flag == true) {
				pu.clear();
			};
			pu.insert(pair<int, int>(c.x, c.y));
			i = i_end + 1;
			if (i == shape_part.find("PD")) {//
				pu_flag = false;
				shape_part[i] = '-';
				shape_part[i+1] = '-';
				i += 3;
				continue;
			};
		};
		if ((pu_flag == false) && (i == shape_part.find("PU"))) {
			if (pu.size() <= 2) {
				storage.adding(new Line(move(pu))); pu.clear();
			} else {
				storage.adding(new PolyLine(move(pu))); pu.clear();
			};
		};
		//it = shape_part.begin();
		//it += i;
	};


	storage.print();
	ifile.close();

	//DB db1 = storage, db2;
	//db2 = db1;
	//db1.print();
	return 0;
}
