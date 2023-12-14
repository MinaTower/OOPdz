#pragma once
#ifndef Lec622_Zemtseva_1_H
#define Lec622_Zemtseva_1_H

#include "Zemtseva.h"
class Zemtseva_1 :
    public Zemtseva
{
    int* inf1;
public:
    Zemtseva_1();
    Zemtseva_1(int numi);
    virtual void abst(int num);
    virtual void changing_inf(int num);
    void copy(vector<Zemtseva*>& copyhere);
    virtual void print_inf();
    virtual ~Zemtseva_1();
};

#endif //Lec6.22_Zemtseva_1_H