#pragma once
#ifndef Lec7_23_Lines_interpritator_H
#define Lec7_23_Lines_interpritator_H

#include "Shape.h"
#include "Line.h"
#include "PolyLine.h"
#include "DB.h"
#include<vector>
using namespace std;

class Lines_interpritator
{
    DB storage;
    //vector<vector<pair<int, int>>> painting_inf;
public:
    Lines_interpritator();
    ~Lines_interpritator();
    void set_lines(string& shape_part);
    //vector<POINT> get_paint_inf();
};
#endif // Lec7_23_Lines_interpritator_H

