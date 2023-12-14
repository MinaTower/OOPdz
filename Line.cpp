#include "Line.h"
#include <iostream>
using namespace std;
Line::Line() {};
Line::Line(vector<POINT>&& obj) {
	for (vector<POINT>::iterator it = obj.begin(); it != obj.end(); ++it) {
		pixels.push_back(*it);
	};
};
Line::Line(vector<POINT>& obj) {
	for (vector<POINT>::iterator it = obj.begin(); it != obj.end(); ++it) {
		pixels.push_back(*it);
	};
};
void Line::print() {
	LONG y_min = 900900900, y_max = 0;//rude
	LONG x_min = 900900900, x_max = 0;//rude
	std::cout << "Line" << endl << "coordinates:" << endl;
	for (vector<POINT>::iterator it = pixels.begin(); it != pixels.end(); ++it) {//coords
		std::cout << it->x << " " << it->y << endl;
		x_min = min(x_min, it->x);
		x_max = max(x_max, it->x);
		y_min = min(y_min, it->y);
		y_max = max(y_max, it->y);


	};
	pair<int, int> boarder_x(x_min, x_max);
	pair<int, int> boarder_y(y_min, y_max);
	pair<int, int> center = pair<int, int>((boarder_x.second + boarder_x.first) / 2, (boarder_y.second + boarder_y.first) / 2);//rude
	std::cout << "Center: " << center.first << " " << center.second << endl;//center
	std::cout << "Max and min coordinates: x " << boarder_x.first << " " << boarder_x.second << " y " << boarder_y.first << " " << boarder_y.second << endl << endl;//min max
};
void Line::paint(HDC hdc) {
	for (int iter = 1; iter != pixels.size(); ++iter) {
		MoveToEx(hdc, pixels[iter - 1].x / 5, pixels[iter - 1].y / 5, NULL);//для 17"
		LineTo(hdc, pixels[iter].x / 5, pixels[iter].y / 5);
	};
};
void Line::copy(vector<Shape*>* here) { here->push_back(new Line(pixels)); };

Line::~Line() {};
