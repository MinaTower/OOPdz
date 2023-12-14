#pragma once
#include<vector>
#include"Zemtseva_1.h"
#include "Zemtseva_2.h"
#include <iostream>

using namespace std;

Zemtseva_2::Zemtseva_2() { Zemtseva_2::inf2 = new float(0.001); };
Zemtseva_2::Zemtseva_2(float numf) { Zemtseva_2::inf2 = new float(numf);};
void Zemtseva_2::copy(vector<Zemtseva*>& copyhere) { copyhere.push_back(new Zemtseva_2(*(Zemtseva_2::inf2))); };
void Zemtseva_2::changing_inf(int num) {};
void Zemtseva_2::print_inf() { cout << *(Zemtseva_2::inf2) << "\t"; };
Zemtseva_2::~Zemtseva_2() { delete Zemtseva_2::inf2; Zemtseva_2::inf2 = nullptr; };