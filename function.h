#pragma once
#include"Header.h"
struct login {
	string username;
	string password;
};
struct information {
	string name;
	string email;
	string nationality;
	string address;
};
struct Year {
	string YearStudy;
	string Begin;
};
struct Birthday {
	string Day;
	string Month;
	int Year;
};
struct SinhVien {
	int No;
	string Id;
	string Fname;
	string Lname;
	string sex;
	Birthday DayofBirth;
	string IdSocial;
};
struct Node {
	SinhVien data;
	Node* pNext;
};
struct Class {
	string Name;
};
struct List {
	Node* pHead;
	Node* pTail;
};
struct ListClass {
	List DTV;
	List THH;
	List CTT;
	List VLH;
	List HOH;
	List SHH;
	List KCD;
	List KMT;
	List CSH;
	List KLV;
};
struct Term {
	string Id;
	string Name;
	string NameClass;
	string NameTeacher;
	string DayofWeek;
	string Session;
	int Credit;
	int MaxStudents;
};
struct Score {
	string Id;
	string FullName;
	int No;
	float Other;
	float MidTerm;
	float Final;
	float Total;
};
void CreatList(List& l);
Node* CreatNode(SinhVien p);
void AddTail(List& l, Node* q);
void Swap(SinhVien& a, SinhVien& b);
int Returnvalue(List l);
void AddOne(List& l, int& n);
void Inputfile(string x, List l, int n );
void filesvnamnhat(string x, List& l, int& n);
void OutPut(SinhVien p);
void OutPutList(List l);
bool Login(string x, login f);
void Returnfile(string x, login f[], int n);
void Addfile(string x, login f[], int n);
int temp(login f[], login f1, int n);
void Information(login f);
bool CheckValid(string x);
int CheckRobot();
void CreatClass(Class* arr, int n, ListClass& l);
void ResetNo(List& l);
void InputClass(List l, ListClass& lc, Class* arr, int n);
void OutputClass(Class* arr, int n, ListClass lc);
Term CreatTerm();
List ReturnList(ListClass lc, string luachon);
void OutputTerm(Term Arr[], int n);
void InputFileTerm(Term Arr[], int n);
void ResetTerm(Term Arr[], int n, string x);
Node* ReturnSameId(List l);
List CopyList(List Listbegin, List Listend, int n);
void DeleteStudentTerm(List& l);
void DeleteTerm(string name, List* ArrList, Term* Arr, int& n, int vt);
void InputPasswordStudents(string x, List l);
void ReturnNameTerm(string* Arr, int& n);
bool CheckTerm(string x, string name);
void ScoreTerm(string x, List l, int& dem);
void ReturnScore(string name, Score Arr[100][100], int row, int& col, List l);
void ReturnScoreSV(string name, Score Arr[100][100], int row, int col, string Id);
void OutputScore(Score Arr[100][100], int row, int col);
bool CheckScore(string name, string id, bool check );
void menu4(login& f);
void menu3(List l, Year y, string Year, ListClass lc);
void menu2(Year y);
void menu1(login& f);
void menu();