#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include"mycl.h"
struct Leaks {
    ~Leaks() { _CrtDumpMemoryLeaks(); }
}_l;


int main()
{
    DB db1, db2;
    Zemtseva* a1 = new Zemtseva_1;
    Zemtseva* a2 = new Zemtseva_2;
    Zemtseva* a3 = new Zemtseva_3;
    Zemtseva* b1 = new Zemtseva_1;
    Zemtseva* c1 = new Zemtseva_1;
    Zemtseva* b2 = new Zemtseva_2;
    Zemtseva* c2 = new Zemtseva_2;
    Zemtseva* b3 = new Zemtseva_3;
    Zemtseva* c3 = new Zemtseva_3;
    db1.adding(a1);
    db1.adding(a2);
    db1.adding(a3);
    db2.adding(b1);
    db2.adding(b2);
    db2.adding(b3);
    db2.adding(c1);
    db2.adding(c2);
    db2.adding(c3);

    Zemtseva* a5 = new Zemtseva_1;//db1.print();
    db1.change(a5, 1);
    //Zemtseva* a6 = new Zemtseva_2;//1;
    //db1.adding(a6);
    db2 = db1;
    //a1->change_Zem(7);
    db1.print();
    db2.print();
    return 0;
}
