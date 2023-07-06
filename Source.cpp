#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;
int main()
{
	fstream filein;
	string s = "1";
	filein.open("Text.txt", ios::in | ios::out);
	if (!filein.is_open()) cout << "Khong mo duoc file.\n";
	char x[100];
	filein.getline(x, 100);
	cout << x<< endl;
	filein.seekg(1, SEEK_CUR);
	filein.seekg(-1, SEEK_CUR);
	filein << s;
	filein.close();
	return 0;
}