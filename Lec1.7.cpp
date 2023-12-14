#include"stdafx.h"
using namespace std;

class Test {
    public:
        Test() {
            cout << "Construct" << endl;
        }
        ~Test() {
            cout << "destruct" << endl;
        }
};

int main()
{
    vector<Test*>v(3);
    for (int i = 0; i < v.size(); i++) {
        v[i] = new Test();
    }
    for (int i = 0; i < v.size(); i++) {
        delete v[i]; v[i] = 0;//
    }
    return 0;
}
