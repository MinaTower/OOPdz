#include"stdafx.h"
using namespace std;
class Reader {
    vector<int> m_v;
    public: 
        Reader() {};
        void read(const char* name);
        void print();
};

void Reader::read(const char* name)
{
    ifstream ifile;
    ifile.open(name);
    int a;
    for (a = 0; a < 6; a++)//6 as arbitrary value
    {
        ifile >> a;
        if (ifile.eof()) break;
        m_v.push_back(a);
    }
};

void Reader::print() 
{
    for (int i = 0; i < m_v.size(); i++)
    {
        cout << m_v[i] << endl;
    }
}

int main()
{
    Reader r;
    r.read("myfile.txt");
    r.print();
    getchar();
    return 0;
}