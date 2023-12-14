#include<iostream>
//#define _CRTDBG_MAP_ALLOC
//#include <crtdbg.h>
using namespace std;
//struct Leaks {
//	~Leaks() { _CrtDumpMemoryLeaks(); }
//}_l;

class Welcome {
private:
	char* m_data;
public:
	Welcome(){
	m_data = new char[14];
	const char* init = "Hello, World!";
	for (int i = 0; i < 14; ++i) {
		m_data[i] = init[i];
	}
	//cout << "Construct" << endl;
	}
	~Welcome() {
		delete[] m_data; m_data = 0;//Как-то просто...
		
		//cout << "Destruct" << endl;
	}
};

int main()
{
	Welcome hi;
	return 0;
}