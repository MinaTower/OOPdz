#include"stdafx.h"
using namespace std;

int main()
{
	ifstream ifile;
	ifile.open("myfile.txt");
	int a;
	vector<int> v;
	for (a = 0; a < 15; a++)//15 as arbitrary value
	{
		ifile >> a;
		if (ifile.eof()) break;
		v.push_back(a);
	}
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	return 0;
}