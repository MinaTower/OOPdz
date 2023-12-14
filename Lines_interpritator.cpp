#include "Lines_interpritator.h"
#include "Shape.h"
#include "Line.h"
#include "PolyLine.h"
#include "DB.h"
#include<vector>
using namespace std;





void Lines_interpritator::set_lines(string& shape_part) {
    for (int i = 1 + shape_part.find("PU"); i < shape_part.rfind("SP"); i += 0) {
        shape_part[i - 1] = '-';
        shape_part[i] = '-';
        bool pu_flag = true;
        vector<POINT> pu;
        vector<pair<int, int>> painting_inf_part;
        pair<int, int> previous;
        for (i = shape_part.find("PA"); i < min(shape_part.find("PU;"), shape_part.rfind(";SP")); i += 0) {
            shape_part[i] = '-';
            shape_part[i + 1] = '-';
            i += 2;
            int i_end = min(min(shape_part.rfind(";SP"), shape_part.find(";PU")), min(shape_part.find(";PA"), shape_part.find(";PD")));
            POINT c = get_POINT(&c, shape_part, i, i_end);
            if (pu_flag == true) {
                pu.clear();
            };
            pu.push_back(move(c));
            //painting_inf_part.push_back(pair<int, int>(c.x, c.y));
            i = i_end + 1;
            if (i == shape_part.find("PD")) {//
                pu_flag = false;
                shape_part[i] = '-';
                shape_part[i + 1] = '-';
                i += 3;
                continue;
            };
        };
        if ((pu_flag == false) && (i == shape_part.find("PU"))) {
            if (pu.size() <= 2) {
                storage.adding(new Line(move(pu))); pu.clear();
                painting_inf.push_back(painting_inf_part); painting_inf_part.clear();
            }
            else {
                storage.adding(new PolyLine(move(pu))); pu.clear();
                painting_inf.push_back(painting_inf_part); painting_inf_part.clear();
            };
        };
    };
};
//vector<POINT> Lines_interpritator::get_paint_inf() { return painting_inf; };
Lines_interpritator::~Lines_interpritator() {
};
