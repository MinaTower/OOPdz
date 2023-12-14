#pragma once
#ifndef Lec622_Zemtseva_2_H
#define Lec622_Zemtseva_2_H
#include "Zemtseva_1.h"
class Zemtseva_2 :
    public Zemtseva_1
{
    float* inf2;
public:
    Zemtseva_2();
    Zemtseva_2(float numf);
    void copy(vector<Zemtseva*>& copyhere);
    virtual void changing_inf(int num);
    virtual void print_inf();
    virtual ~Zemtseva_2();
};

#endif //Lec6.22_Zemtseva_2_H