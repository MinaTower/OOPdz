#include<vector>
#pragma once
#include"Zemtseva.h"
#include "Zemtseva_1.h"
#include "Zemtseva_2.h"
#include <iostream>


using namespace std;

Zemtseva_1::Zemtseva_1() {Zemtseva_1::inf1 = new int(33);};
Zemtseva_1::Zemtseva_1(int numi) { Zemtseva_1::inf1 = new int(numi);};
void Zemtseva_1::abst(int num) {};//
void Zemtseva_1::changing_inf(int num) { *(Zemtseva_1::inf1) = num; };
void Zemtseva_1::copy(vector<Zemtseva*>& copyhere) { copyhere.push_back(new Zemtseva_1(*inf1)); };
void Zemtseva_1::print_inf() { cout << *(Zemtseva_1::inf1) << "\t"; };
Zemtseva_1::~Zemtseva_1() { delete Zemtseva_1::inf1;   Zemtseva_1::inf1 = nullptr; };