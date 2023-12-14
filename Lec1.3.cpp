#include"stdafx.h"
using namespace std;

int main()
{
    ofstream of;
    of.open("myfile.txt");
    for (int i = 0; i < 11; i++)
    {
        of << i << endl;
    };

    ifstream ifile;
    ifile.open("myfile.txt");
    string s0, s1;
    for (int i = 0; i < 10; i++) {
        ifile >> s0;
        if (ifile.eof()) { break; }
        s1 += s0 +"\n";
    } 
    cout << s1;
    return 0;
}