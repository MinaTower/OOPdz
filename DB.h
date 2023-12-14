#pragma once
#ifndef Lec622_DB_H
#define Lec622_DB_H
class DB
{
	vector<Zemtseva*> ourdata;
public:
	DB();
	DB(const DB& obj);
	void adding(Zemtseva* elem);
	void changing(int num);
	void print();
	DB& operator=(const DB& obj);
	~DB();
};
#endif //Lec6.22_DB_H