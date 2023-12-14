#include <iostream>
#include <list>
#include<iterator>
using namespace std;

struct Wrong_element_exeptinon { /*int elem = 0;*/ };

int random_value_generator() {//to the template?
    static int necto = 0;
    necto += 1;
    return (necto % 100);
}
class DB;
class Zemtseva {
public:
    int inf0 = (random_value_generator());
    int indicate = 0;
    Zemtseva() {};
    Zemtseva(int a) {};
    virtual void change_Zem(int a) = 0;
    //virtual bool should_be_copied() { return true; };
    virtual void print() { cout << inf0; };
    virtual void copy(list<Zemtseva*>* way) { /*way->push_back(new Zemtseva_1(a)); */};
    virtual ~Zemtseva() {};
};

class Zemtseva_1 : public Zemtseva {
    list<int*>* inf11 = new list<int*>;
    char inf12[10] = "something";
    void change_Zem(int a = 16) { (*inf11).push_back(&a); };//реализовано?
public:
    Zemtseva_1() { indicate = 1; };
    Zemtseva_1(int a) {inf0 = a; indicate = 1;};
    virtual void copy(list<Zemtseva*>* way) {
        way->push_back(new Zemtseva_1(inf0));
    };

    void print() {
        for (list<int*>::iterator it = (*inf11).begin(); it != (*inf11).end(); ++it) {
            cout << **it << " ";
        };
        cout << inf12 << " ";
        //cout << inf13;
    };
    ~Zemtseva_1() { delete inf11; };
    //Zemtseva_1(const Zemtseva_1& obj_for_copy) {};
    //virtual bool should_be_copied() { return true; };
};

class Zemtseva_2 : public Zemtseva_1 {
    float* inf2 = new float(random_value_generator());
public:
    Zemtseva_2() { indicate = 2; };
    virtual void copy(list<Zemtseva*>* way) {};
    //virtual Zemtseva* copy(int a) { throw Wrong_element_exeptinon();};
    //virtual bool should_be_copied() { return false; };//Zemtseva* copy() { return new Zemtseva_2(*this); };
    void print() {
        cout << *inf2 << '\t';
    };
    ~Zemtseva_2() { delete inf2; };
};

class Zemtseva_3 : public Zemtseva_2 {
    double* inf3 = new double(19.03);
public:
    Zemtseva_3() { indicate = 3; };
    virtual void copy(list<Zemtseva*>* way) {};    //virtual Zemtseva* copy(int a) { throw Wrong_element_exeptinon();};
    //virtual bool should_be_copied() { return false; };//Zemtseva* copy() { return new Zemtseva_3(*this); };
    void print() {
        cout << *inf3 << '\t';
    };
    ~Zemtseva_3() { delete inf3; };
};

class DB {
private:
    list<Zemtseva*> ourdata;
public:
    void adding(Zemtseva* obj) {
        ourdata.push_back(obj);
    }
    void change(Zemtseva* obj, int num) {
        if (ourdata.size() >= num) {
            int counter = 0;
            for (list<Zemtseva*>::iterator it = ourdata.begin(); it != ourdata.end(); ++it) {
                if (counter == num) {//if? можно менять первый~
                    ourdata.insert(it, obj);
                    delete (*it);
                    ourdata.erase(it);
                    break;
                }
                counter += 1;
            };
        };
    }
    DB& operator=(DB& obj) {
        if ((*this).ourdata.size() > 0) {
            for (list<Zemtseva*>::iterator it = ourdata.begin(); it != ourdata.end(); ++it) {
                delete (*it);
            }
            this->ourdata.clear();
        };
        for (list<Zemtseva*>::iterator it = (obj.ourdata).begin(); it != obj.ourdata.end(); ++it) {
            (*it)->copy(&ourdata);
        }
        return *this;
    };
    void print() {
        for (list<Zemtseva*>::iterator it = ourdata.begin(); it != ourdata.end(); ++it) {
            (*it)->print();
            cout << '\t';
        }
        cout << endl;
    };
    ~DB() {
        for (list<Zemtseva*>::iterator it = ourdata.begin(); it != ourdata.end(); ++it) {
            delete* (it);
        };
    }
};

//inline void Zemtseva_1::copy(DB* way, int a) { way->adding(new Zemtseva(a)); };