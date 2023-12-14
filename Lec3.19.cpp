#include <iostream>
#include"lecture3.h"
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
using namespace std;
struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;

class DB {
    vector<Zemtseva*>ourdata;
public:
    DB& operator=(const DB& obj) {
        if ((*this).ourdata.size() > 0) {//если перезаполняем(такого сейчас нет)
            for (int i = 0; i < (*this).ourdata.size(); i++) {
                delete (this->ourdata)[i];
            }
            this->ourdata.clear();
        };
        for (int i = 0; i < obj.ourdata.size(); i++) {
            Zemtseva* m = obj.ourdata[i]->copy();
            this->ourdata.push_back(m);
        }
        return *this;
    };
    DB() {};
    DB(DB& obj){
        for (int i = 0; i < obj.ourdata.size(); i++) {
            Zemtseva* m = obj.ourdata[i]->copy();
            this->ourdata.push_back(m);
        };
    };
    ~DB() {
        for (int i = 0; i < ourdata.size(); i++) {
                delete ourdata[i]; ourdata[i] = 0;
            };
        };
    void create(DB* dat);
};

void DB::create(DB* dat)
{
    dat->ourdata.push_back(new Zemtseva_1());
    dat->ourdata.push_back(new Zemtseva_1());
    dat->ourdata.push_back(new Zemtseva_2());
    dat->ourdata.push_back(new Zemtseva_2());
};

int main()
{
    DB db1, db3;
    db1.create(&db1);
    DB db2;
    db2 = db1;
    db3 = db2;
    DB db4 = db2;
    return 0;
}
