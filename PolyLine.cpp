#include "PolyLine.h"
#include <iostream>
using namespace std;
PolyLine::PolyLine() {};
PolyLine::PolyLine(/*const */ map<int, int>&& obj) {
	for (map<int, int>::iterator it = obj.begin(); it != obj.end(); ++it) {
		pixels.insert(pair<int, int>(it->first, it->second));
	};
};
PolyLine::PolyLine(map<int, int>& obj) {
	for (map<int, int>::iterator it = obj.begin(); it != obj.end(); ++it) {
		pixels.insert(pair<int, int>(it->first, it->second));
	};
};
//PolyLine& operator=(const PolyLine& obj) {
//	if (obj.pixels != pixels) {
//		for (map<int, int>::iterator it = obj->begin(); it != obj.end(); ++it) {
//			pixels.insert(pair<int, int>(it->first, it->second));
//		};
//	};
//	return *this;
//};

void PolyLine::print() {
	int y_min = 900900900, y_max = 0;//rude
	std::cout << "PolyLine" << endl << "Coordinates:" << endl;
	for (map<int, int>::iterator it = pixels.begin(); it != pixels.end(); ++it) {//coords
		std::cout << it->first << " " << it->second << endl;
		y_min = min(y_min, it->second);
		y_max = max(y_max, it->second);

	};
	pair<int, int> boarder_x = pair<int, int>(pixels.begin()->first, pixels.rbegin()->first);
	pair<int, int> boarder_y = pair<int, int>(y_min, y_max);
	pair<int, int> center = pair<int, int>((boarder_x.second + boarder_x.first) / 2, (boarder_y.second + boarder_y.first) / 2);//rude
	std::cout << "Center: " << center.first << " " << center.second << endl;
	std::cout << "Max and min coordinates: x " << boarder_x.first << " " << boarder_x.second << " y " << boarder_y.first << " " << boarder_y.second << endl << endl;
};
void PolyLine::copy(vector<Shape*>* here) { here->push_back(new PolyLine(pixels)); };
PolyLine::~PolyLine() {};
