#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include<cmath>
//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
using namespace std;
//struct Leaks {
//	~Leaks() { _CrtDumpMemoryLeaks(); }
//}_l;

class Shape {
public:
	Shape() {}
	virtual ~Shape() {}
	virtual double Perimeter() { return 0; };
};

class Square : public Shape {
	double side;
public:
	Square(double a){ side = a; };//what about checking?
	~ Square() {};
	double Perimeter() { return (4 * side); };
};

class Circle : public Shape {
	double radius;
public:
	Circle(double a){ radius = a; };//what about checking?
	~Circle() {};
	double Perimeter() { return (2*radius*M_PI); };
};

int main()
{
	vector<Shape*> v;
	for (int i = 0; i < 5; i++) {
		if (!(i % 2)) {
			Shape* s = new Square(double(i)+1.2);
			v.push_back(s);
		}
		else {
			Shape* s = new Circle(double(i));
			v.push_back(s);
		}
	}

	for (int i = 0; i < v.size(); i++) {
		cout << v[i]->Perimeter() << endl;
	}
	for (int i = 0; i < v.size(); i++) {
		delete v[i]; v[i] = 0;
	}
	return 0;
}
