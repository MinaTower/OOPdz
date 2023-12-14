#include <iostream>
#include <vector>
#include <fstream>//extra
#include <string>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>

class Zemtseva {
public:
	Zemtseva() {};
	virtual ~Zemtseva() {};
	virtual Zemtseva* copy() { return new Zemtseva(*this);};
};

class Zemtseva_1 : public Zemtseva {
public://?
	int* inf1;
	Zemtseva_1() { inf1 = new int(3); };
	virtual ~Zemtseva_1() { delete inf1; inf1 = 0;};
	virtual Zemtseva* copy() { return new Zemtseva_1(*this); };
	Zemtseva_1(const Zemtseva_1& obj_for_copy) : inf1(new int) { *inf1 = *obj_for_copy.inf1; }
};

class Zemtseva_2 : public Zemtseva_1 {
public://?
	int* inf1;
	Zemtseva_2() { inf1 = new int(10); };
	virtual ~Zemtseva_2() { 
		delete inf1; inf1 = 0;};
	virtual Zemtseva* copy() { return new Zemtseva_2(*this); };
	Zemtseva_2(const Zemtseva_2& obj_for_copy) : inf1(new int()) {*inf1 = *(obj_for_copy.inf1);};
	};