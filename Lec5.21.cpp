#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include<fstream>
#include<string>
#include<vector>
#include<iostream>
using namespace std;
struct Leaks {
	~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;


class Word {
protected:
	string str = "";
public:
	Word() {};
	virtual ~Word() {};
	virtual void copyU(vector<Word*>* data) {};
	virtual string print() { return str; }
	virtual void change(string st) {};
};

class Lowercase : public Word {
public:
	Lowercase() {};
	Lowercase(string s) { str = s; };
	virtual ~Lowercase() {};
	virtual void copyU(vector<Word*>* data) {};
	virtual string print() { return str; }
	//virtual void change(string st) {str = st;};
};

class Uppercase : public Word {
public:
	Uppercase() {};
	Uppercase(string s){ str = s; };
	virtual ~Uppercase() {};
	void set_str(string s) { str = s; };
	virtual void copyU(vector<Word*>* data) { data->push_back(new Uppercase(str)); };
	virtual string print() { return str; }
	//virtual void change(string st) { str = st; };

};

class DB {
public:
	vector<Word*> ourdata;
	//void change(string s) { ourdata[0]->change(s); };///Проверку регистра на такие штуки
	void adding(string* st) {
		Word* m;
		if (isupper((*st)[0])) {
			//wcout << (*st)[0]<< endl;
			m = new Uppercase(*st);
			ourdata.emplace_back(m);
		}
		else {
			m = new Lowercase(*st);
			ourdata.emplace_back(m);
		}
	};

	DB() {};
	DB(const DB& obj) {
		for (int i = 0; i < obj.ourdata.size(); i++) {
			obj.ourdata[i]->copyU(&(ourdata));
		};
	};
	DB& operator=(const DB& obj) {
		for (int i = 0; i < ourdata.size(); i++) {
			delete ourdata[i];
		};
		ourdata.clear();
		for (int i = 0; i < obj.ourdata.size(); i++) {
			obj.ourdata[i]->copyU(&(ourdata));
		};
		return *this;
	};
	~DB() {
		//cout << ourdata[2]->print() << endl;//
		for (int i = 0; i < ourdata.size(); i++) {
			delete ourdata[i];
		};
	};
};

int main()
{
	setlocale(LC_ALL, "Russian");
	//FILE ifile = *_wfopen("Article.txt", "r, ccs=UTF-16LE");
	ifstream ifile;
	ifile.open("Article.txt");
	//cout << ifile.is_open();

	DB db1;
	string s0;
	while (!ifile.eof()) {
		ifile >> s0;
		db1.adding(&s0);
	};
	ifile.close();

	DB db2 = db1;
	//db1.change("Uerr");//"Несовместное" владение
	DB db3;
	db3 = db1;

	ofstream ofile;
	ofile.open("Uppers.txt");
	//cout << ofile.is_open();
	for (int i = 0; i < db2.ourdata.size(); i++) {
		ofile << db2.ourdata[i]->print()<< endl;
	};
	ofile.close();
	return 0;
};