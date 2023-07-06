#include"function.h"

void CreatList(List& l) {
	l.pHead = NULL;
	l.pTail = NULL;
}
Node* CreatNode(SinhVien p) {
	Node* q = new Node;
	q->data = p;
	q->pNext = NULL;
	return q;
}
void AddTail(List& l, Node* q) {
	if (l.pHead == NULL && l.pTail == NULL) {
		l.pTail = l.pHead = q;
	}
	else {
		l.pTail->pNext = q;
		l.pTail = q;
	}
}
void Swap(SinhVien& a, SinhVien& b) {
	SinhVien Temp;
	Temp = a;
	a = b;
	b = Temp;
}
int Returnvalue(List l) {
	int dem(0);
	for (Node* k = l.pHead; k != NULL; k = k->pNext) {
		dem++;
	}
	return dem;
}
void AddOne(List& l, int& n) {
	SinhVien p;
	cout << "Mssv:";
	cin.ignore();
	getline(cin, p.Id);
	cout << "Ho:";
	getline(cin, p.Lname);
	cout << "Ten:";
	getline(cin, p.Fname);
	cout << "Gioi tinh:";
	getline(cin, p.sex);
	cout << "Ngay sinh:";
	getline(cin, p.DayofBirth.Day);
	cout << "Thang:";
	getline(cin, p.DayofBirth.Month);
	cout << "Nam:";
	cin >> p.DayofBirth.Year;
	cout << "Cmnd:";
	cin.ignore();
	getline(cin, p.IdSocial);
	p.No = n++;
	Node* q = CreatNode(p);
	AddTail(l, q);
}
void Inputfile(string x, List l, int n = 0) {
	fstream file;
	int dem(1);
	file.open(x + ".txt", ios_base::out); {
		for (Node* k = l.pHead; k != NULL; k = k->pNext) {
			file << k->data.Id << "," << k->data.Fname << "," << k->data.Lname << "," << k->data.sex << "," << k->data.DayofBirth.Day << "/" << k->data.DayofBirth.Month << "/" << k->data.DayofBirth.Year << "," << k->data.IdSocial << endl;
			if (dem == n)return;
			dem++;
		}
	}
	file.close();
}
void filesvnamnhat(string x, List& l, int& n) {
	fstream file;
	string temp;
	file.open(x + ".txt", ios_base::in); {
		while (!file.eof()) {
			SinhVien f;
			getline(file, f.Id, ',');
			getline(file, f.Fname, ',');
			getline(file, f.Lname, ',');
			getline(file, f.sex, ',');
			getline(file, f.DayofBirth.Day, '/');
			getline(file, f.DayofBirth.Month, '/');
			f.No = n++;
			file >> f.DayofBirth.Year;
			file.seekg(1, SEEK_CUR);
			getline(file, f.IdSocial);
			getline(file, temp);
			Node* p = CreatNode(f);
			AddTail(l, p);
		}
	}
	file.close();
}
void OutPut(SinhVien p) {
	cout << left << setw(15) << p.No << left << setw(15) << p.Id << left << setw(15) << setw(15) << p.Lname << left << setw(15) << p.Fname << left << setw(15) << p.sex << p.DayofBirth.Day << "/" << p.DayofBirth.Month << "/" << left << setw(15) << p.DayofBirth.Year << p.IdSocial << endl;
	cout;
}
void OutPutList(List l) {
	cout << setw(15) << "Thu tu" << setw(17) << "Mssv" << left << setw(15) << "Ho" << left << setw(13) << "Ten" << setw(15) << "Gioi tinh" << left << setw(25) << "Ngay sinh" << "Cmnd" << endl;
	for (Node* k = l.pHead; k != NULL; k = k->pNext) {
		OutPut(k->data);
	}
}
bool Login(string x, login f) {//hàm kiểm tra đăng nhập có thành công không
	login f1;
	ifstream file;
	file.open(x + ".txt", ios_base::in); {
		while (!file.eof()) {
			getline(file, f1.username);
			getline(file, f1.password);
			if (f1.username == f.username && f1.password == f.password)return true;
		}
	}
	file.close();
	return false;
}
void Returnfile(string x, login f[], int n) {//hàm đọc file text
	ifstream file;
	file.open(x + ".txt", ios_base::in); {
		for (int i(0); i < n; i++) {
			getline(file, f[i].username);
			getline(file, f[i].password);
		}
	}
	file.close();
}
void Addfile(string x, login f[], int n) {//ghi nội dung vào file
	ofstream file;
	file.open(x + ".txt", ios_base::out); {
		for (int i(0); i < n; i++)
		{
			file << f[i].username << endl;
			file << f[i].password << endl;
		}
		file.close();
	}
}
int temp(login f[], login f1, int n) {//hàm trả ra vị trí cần thay đổi
	for (int i(0); i < n; i++) {
		if (f1.username == f[i].username)return i;
	}
}
void Information(login f) {//hàm xuất thông tin giáo viên
	information f1;
	string temp, temp1, temp2, temp3;
	ifstream file;
	file.open("thongtincanbo.txt", ios_base::in); {
		while (!file.eof()) {
			getline(file, f1.email, ',');
			getline(file, temp3);
			getline(file, f1.name, ',');
			getline(file, temp);
			getline(file, f1.nationality, ',');
			getline(file, temp1);
			getline(file, f1.address, ',');
			getline(file, temp2);
			if (f.username == f1.email) {
				cout << "\t\tThong Tin" << endl;
				cout << "\tTen:" << f1.name << endl;
				cout << "\tDia chi thu dien tu:" << f1.email << endl;
				cout << "\tQuoc tich:" << f1.nationality << endl;
				cout << "\tDia chi hien tai:" << f1.address << endl;
			}
		}
	}
	file.close();
}
bool CheckValid(string x) {//kiểm tra mật khẩu mới tạo có hợp lệ không
	int dem(0), dem1(0), dem2(0), dem3(0);
	for (int i(0); i <= x.length() - 1; i++) {
		if (x[i] >= 48 && x[i] <= 57)dem++;
		else if (x[i] >= 97 && x[i] <= 122)dem1++;
		else if (x[i] >= 65 && x[i] <= 90)dem2++;
		else dem3++;
	}
	if (dem >= 8 && dem1 > 0 && dem2 > 0 && dem3 > 0)return true;
	return false;
}
int CheckRobot() {//hàm check robot
	srand(time(NULL));
	int sum;
	int x = rand() % 10 + 1;
	int y = rand() % 10 + 1;
	int z = rand() % 3 + 1;
	if (z == 1)
	{
		cout << x << " + " << y << "=";
		sum = x + y;
	}
	else if (z == 2) {
		cout << x << " - " << y << "=";
		sum = x - y;
	}
	else {
		cout << x << " * " << y << "=";
		sum = x * y;
	}
	return sum;
}
void CreatClass(Class* arr, int n, ListClass& l) {
	for (int i(0); i < n; i++) {
		cout << "Nhap vao ten lop hoc:";
		cin >> arr[i].Name;
		CreatList(l.CTT);
		CreatList(l.DTV);
		CreatList(l.CSH);
		CreatList(l.HOH);
		CreatList(l.KCD);
		CreatList(l.KLV);
		CreatList(l.KMT);
		CreatList(l.SHH);
		CreatList(l.THH);
		CreatList(l.VLH);
	}
	fstream file;
	file.open("Lop.txt", ios_base::out); {
		for (int i(0); i < n; i++) {
			file << arr[i].Name << endl;
		}
	}
	file.close();
}
void ResetNo(List& l) {
	int i(1);
	for (Node* k = l.pHead; k != NULL; k = k->pNext) {
		k->data.No = i++;
	}
}
void InputClass(List l, ListClass& lc, Class* arr, int n) {
	Node* q = new Node;
	for (Node* k = l.pHead; k != NULL; k = k->pNext) {
		string x = k->data.Id.substr(2, 2);
		if (x == "10") AddTail(lc.DTV, k);
		else if (x == "11")AddTail(lc.THH, k);
		else if (x == "12")AddTail(lc.CTT, k);
		else if (x == "13")AddTail(lc.VLH, k);
		else if (x == "14")AddTail(lc.HOH, k);
		else if (x == "15")AddTail(lc.SHH, k);
		else if (x == "16")AddTail(lc.KCD, k);
		else if (x == "17")AddTail(lc.KMT, k);
		else if (x == "18")AddTail(lc.CSH, k);
		else if (x == "19")AddTail(lc.KLV, k);
	}
	for (int i(0); i < n; i++) {
		string x = arr[i].Name.substr(2, 3);
		if (x == "CTT")
		{
			Inputfile(arr[i].Name, lc.CTT);
			ResetNo(lc.CTT);
		}
		else if (x == "DTV")
		{
			Inputfile(arr[i].Name, lc.DTV);
			ResetNo(lc.DTV);
		}
		else if (x == "CSH") {
			Inputfile(arr[i].Name, lc.CSH);
			ResetNo(lc.CSH);
		}
		else if (x == "HOH") {
			Inputfile(arr[i].Name, lc.HOH);
			ResetNo(lc.HOH);
		}
		else if (x == "KCD") {
			Inputfile(arr[i].Name, lc.KCD);
			ResetNo(lc.KCD);
		}
		else if (x == "KLV") {
			Inputfile(arr[i].Name, lc.KLV);
			ResetNo(lc.KLV);
		}
		else if (x == "KMT") {
			Inputfile(arr[i].Name, lc.KMT);
			ResetNo(lc.KMT);
		}
		else if (x == "SHH") {
			Inputfile(arr[i].Name, lc.SHH);
			ResetNo(lc.SHH);
		}
		else if (x == "THH") {
			Inputfile(arr[i].Name, lc.THH);
			ResetNo(lc.THH);
		}
		else if (x == "VLH") {
			Inputfile(arr[i].Name, lc.VLH);
			ResetNo(lc.VLH);
		}
	}
}
void OutputClass(Class* arr, int n, ListClass lc) {
	string luachon;
	cout << "\t\t\tDANH SACH CAC LOP" << endl;
	for (int i(0); i < n; i++) {
		cout << "\t\t" << i + 1 << "." << arr[i].Name << endl;
	}
	cout << "\t\t0.Quay lai" << endl;
	do {
		cout << "Moi ban nhap vao lop muon xem danh sach:";
		cin.ignore();
		getline(cin, luachon);
		string x = luachon.substr(1, 3);
		if (x == "CTT")OutPutList(lc.CTT);
		else if (x == "DTV")OutPutList(lc.DTV);
		else if (x == "CSH")OutPutList(lc.CSH);
		else if (x == "HOH")OutPutList(lc.HOH);
		else if (x == "KCD")OutPutList(lc.KCD);
		else if (x == "KLV")OutPutList(lc.KLV);
		else if (x == "KMT")OutPutList(lc.KMT);
		else if (x == "SHH")OutPutList(lc.SHH);
		else if (x == "THH")OutPutList(lc.THH);
		else if (x == "VLH")OutPutList(lc.VLH);
	} while (luachon != "0");
	return;
}
Term CreatTerm() {
	Term t;
	cout << "Nhap vao ten cua khoa hoc:";
	cin.ignore();
	getline(cin, t.Name);
	cout << "Nhap vao id cua khoa hoc:";
	getline(cin, t.Id);
	cout << "Nhap vao ten lop:";
	getline(cin, t.NameClass);
	cout << "Nhap vao ten cua giao vien:";
	getline(cin, t.NameTeacher);
	cout << "Nhap vao ngay hoc trong tuan(thu 2->thu 7):";
	getline(cin, t.DayofWeek);
	cout << "Nhap vao ca hoc S1(07:30), S2(09:30), S2(13:30), S3(13:30), and S4(15:30):";
	getline(cin, t.Session);
	cout << "Nhap vao so tin chi cua mon hoc:";
	cin >> t.Credit;
	cout << "Nhap vao so hoc sinh toi da:";
	cin >> t.MaxStudents;
	return t;
}
List ReturnList(ListClass lc, string luachon) {
	string x = luachon.substr(2, 3);
	if (x == "CTT")return lc.CTT;
	else if (x == "DTV")return lc.DTV;
	else if (x == "CSH")return lc.CSH;
	else if (x == "HOH")return lc.HOH;
	else if (x == "KCD")return lc.KCD;
	else if (x == "KLV")return lc.KLV;
	else if (x == "KMT")return lc.KMT;
	else if (x == "SHH")return lc.SHH;
	else if (x == "THH")return lc.THH;
	else if (x == "VLH")return lc.VLH;
}
void OutputTerm(Term Arr[], int n) {
	cout << "\t\t\t\tTHONG TIN CUA DANH SACH CAC KHOA HOC" << endl;
	cout << setw(13) << "Ten khoa" << setw(13) << "Id khoa" << left << setw(13) << "Ten lop" << left << setw(20) << "Ten giao vien" << setw(13) << "Thu" << left << setw(13) << "Thoi gian" << left << setw(15) << "Tin chi" << "So sinh vien" << endl;
	for (int i(0); i < n; i++) {
		cout << setw(13) << Arr[i].Name << setw(13) << Arr[i].Id << left << setw(13) << Arr[i].NameClass << left << setw(20) << Arr[i].NameTeacher << setw(13) << Arr[i].DayofWeek << left << setw(13) << Arr[i].Session << left << setw(15) << Arr[i].Credit << Arr[i].MaxStudents << endl;
	}
}
void InputFileTerm(Term Arr[], int n) {
	fstream file;
	file.open("Term.txt", ios_base::out); {
		for (int i(0); i < n; i++) {
			file << Arr[i].Id << "," << Arr[i].Name << "," << Arr[i].NameClass << "," << Arr[i].NameTeacher << "," << Arr[i].Credit << "," << Arr[i].MaxStudents << "," << Arr[i].DayofWeek << "," << Arr[i].Session << endl;
		}
	}

}
void ResetTerm(Term Arr[], int n, string x) {
	string luachon;
	string temp;
	int temp1;
	for (int i(0); i < n; i++) {
		if (Arr[i].Name == x) {
			cout << "Moi ban nhap thong tin muon thay doi(Ten,Ten lop,Id,Ten giao vien,Tin chi,Thu,Thoi gian,So sinh vien):";
			getline(cin, luachon);
			if (luachon == "Ten") {
				cout << "Nhap vao ten muon thay doi:";
				getline(cin, temp);
				Arr[i].Name = temp;
			}
			else if (luachon == "Ten lop") {
				cout << "Nhap vao ten muon thay doi:";
				getline(cin, temp);
				Arr[i].NameClass = temp;
			}
			else if (luachon == "Id") {
				cout << "Nhap vao Id muon thay doi:";
				getline(cin, temp);
				Arr[i].Id = temp;
			}
			else if (luachon == "Ten giao vien") {
				cout << "Nhap vao ten muon thay doi:";
				getline(cin, temp);
				Arr[i].NameTeacher = temp;
			}
			else if (luachon == "Tin chi") {
				cout << "Nhap vao so tin chi muon thay doi:";
				cin >> temp1;
				Arr[i].Credit = temp1;
			}
			else if (luachon == "Thu") {
				cout << "Nhap vao thu muon thay doi:";
				getline(cin, temp);
				Arr[i].DayofWeek = temp;
			}
			else if (luachon == "Thoi gian") {
				cout << "Nhap vao ten muon thay doi:";
				getline(cin, temp);
				Arr[i].DayofWeek = temp;
			}
			else if (luachon == "So sinh vien") {
				cout << "Nhap vao so sinh vien muon thay doi:";
				cin >> temp1;
				Arr[i].MaxStudents = temp1;
			}
			return;
		}
		cout << "Ten khong ton tai!!!" << endl;
	}
}
Node* ReturnSameId(List l) {
	string name;
	cout << "Nhap vao Id muon them:";
	getline(cin, name);
	for (Node* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data.Id == name)return k;
	}
}
List CopyList(List Listbegin, List Listend, int n) {
	int dem(1);
	for (Node* k = Listbegin.pHead; k != NULL; k = k->pNext) {
		Node* p = new Node;
		p = CreatNode(k->data);
		AddTail(Listend, p);
		if (dem == n)return Listend;
		dem++;
	}
	return Listend;
}
void DeleteStudentTerm(List& l) {
	string name;
	cout << "Nhap vao Id muon xoa:";
	getline(cin, name);
	Node* j = new Node;
	j = l.pHead;
	for (Node* k = l.pHead; k != NULL; k = k->pNext) {

		if (l.pHead == NULL) {
			cout << "\t\tDANH SACH DA RONG!!!!" << endl;
			return;
		}
		if (k->data.Id == name && k == l.pHead) {
			Node* i = new Node;
			i = l.pHead;
			l.pHead = l.pHead->pNext;
			delete i;
			return;
		}
		else if (k->data.Id == name && k == l.pTail) {
			l.pTail = j;
		}
		else if (k->data.Id == name) {
			j->pNext = k->pNext;
		}
		j = k;
	}
}
void DeleteTerm(string name, List* ArrList, Term* Arr, int& n, int vt) {
	fstream file;
	for (int i(0); i < n - 1; i++) {
		if (i == vt) {
			while (ArrList[i].pHead != NULL) {
				Node* k = new Node;
				k = ArrList[i].pHead;
				ArrList[i].pHead = ArrList[i].pHead->pNext;
			}
			for (int j = i; j < n - 1; j++) {
				if (j != n - 1) {
					Arr[j] = Arr[j + 1];
					ArrList[j] = ArrList[j + 1];
				}
			}
		}
	}
	file.open(name + ".txt", ios_base::out); {
		file << "";
	}
	file.close();
	n--;
}
void InputPasswordStudents(string x, List l) {
	fstream file;
	file.open(x + ".txt", ios_base::out); {
		for (Node* k = l.pHead; k != NULL; k = k->pNext) {
			file << k->data.Id << endl << "00000000Ab#" << endl;
		}
	}
	file.close();
}
void ReturnNameTerm(string* Arr, int& n) {
	fstream file;
	file.open("Term.txt", ios_base::in); {
		for (int i(0); i < 100; i++) {
			string str;
			getline(file, str, ',');
			if (str != "") {
				Arr[n] = str;
				n++;
			}
		}
	}
}
bool CheckTerm(string x, string name) {
	fstream file;
	string str, temp;
	int n(0);
	file.open(x + ".txt", ios_base::in); {
		for (int i(0); i < 1000; i++) {
			getline(file, str, ',');
			if (str.length() >= 8) str = str.substr(str.length() - 8, 8);
			if ((i + n) % 6 == 0) {
				if (str != "" && name == str) {
					return true;

				}
				n++;
			}
			if (temp == str)return false;
			temp = str;
		}
	}file.close();
}
void ScoreTerm(string x, List l, int& dem) {
	string id, str;
	float midterm, final, total, other;
	cout << "Nhap vao Id muon cap nhat diem:";
	getline(cin, id);
	for (Node* k = l.pHead; k != NULL; k = k->pNext) {
		if (k->data.Id == id) {
			cout << "nhap vao diem qua trinh:";
			cin >> other;
			cout << "nhap vao diem giua ki:";
			cin >> midterm;
			cout << "nhap vao diem cuoi ki:";
			cin >> final;
			total = other * 0.2 + midterm * 0.3 + final * 0.5;
			fstream file;
			file.open(x + "score.txt", ios_base::app); {
				if (dem > 0)cout << endl;
				file << k->data.Fname << "" << k->data.Lname << "," << k->data.Id << "," << other << "," << midterm << "," << final << "," << total;
				dem++;
			}
			break;
		}
	}
	return;
}
void ReturnScore(string name, Score Arr[100][100], int row, int& col, List l) {
	fstream file;
	file.open(name + "score.txt", ios_base::in); {
		while (l.pHead != NULL) {
			file.seekg(0, SEEK_SET);
			bool check = false;
			string str, strterm;
			float temp1, temp2, temp3, temp4;
			while (!file.eof()) {
				file.ignore();
				getline(file, strterm, ',');
				getline(file, str, ',');
				file >> temp1;
				file.seekg(1, SEEK_CUR);
				file >> temp2;
				file.seekg(1, SEEK_CUR);
				file >> temp3;
				file.seekg(1, SEEK_CUR);
				file >> temp4;
				if (l.pHead->data.Id == str) {
					Arr[row][col].MidTerm = temp2;
					Arr[row][col].Final = temp3;
					Arr[row][col].Total = temp4;
					Arr[row][col].Other = temp1;
					check = true;
					break;
				}
			}
			if (check == false) {
				Arr[row][col].MidTerm = -1;
				Arr[row][col].Final = -1;
				Arr[row][col].Total = -1;
				Arr[row][col].Other = -1;
			}
			Arr[row][col].FullName = l.pHead->data.Fname + l.pHead->data.Lname;
			Arr[row][col].Id = l.pHead->data.Id;
			Arr[row][col].No = col + 1;
			l.pHead = l.pHead->pNext;
			col++;
		}
	}file.close();
}
void ReturnScoreSV(string name, Score Arr[100][100], int row, int col, string Id) {
	fstream file;
	bool check = false;
	file.open(name + "score.txt", ios_base::in); {
		string str, strterm;
		float temp1, temp2, temp3, temp4;
		while (!file.eof()) {
			getline(file, strterm, ',');
			getline(file, str, ',');
			file >> temp1;
			file.seekg(1, SEEK_CUR);
			file >> temp2;
			file.seekg(1, SEEK_CUR);
			file >> temp3;
			file.seekg(1, SEEK_CUR);
			file >> temp4;
			if (Id == str) {
				Arr[row][col].MidTerm = temp2;
				Arr[row][col].Final = temp3;
				Arr[row][col].Total = temp4;
				Arr[row][col].Other = temp1;
				check = true;
				break;
			}
		}
	}
	file.close();
	if (check == false) {
		Arr[row][col].MidTerm = -1;
		Arr[row][col].Final = -1;
		Arr[row][col].Total = -1;
		Arr[row][col].Other = -1;
	}
	Arr[row][col].Id = Id;
	Arr[row][col].No = col + 1;

}
void OutputScore(Score Arr[100][100], int row, int col) {
	int i = row;
	string x = "Chua nhap";
	cout << "Thu tu" << right << setw(10) << "Ho Ten" << setw(20) << "Mssv" << right << setw(20) << "Diem qua trinh" << right << setw(20) << "Diem giua ki" << setw(20) << "Diem cuoi ki" << right << setw(20) << "Diem tong" << endl;
	for (int j(0); j < col; j++) {
		if (Arr[i][j].Other != -1.0 && Arr[i][j].MidTerm != -1.0 && Arr[i][j].Final != -1.0) {
			cout << setw(5) << right << Arr[i][j].No << setw(15) << right << Arr[i][j].FullName << setw(17) << right << Arr[i][j].Id << setw(10) << right << Arr[i][j].Other << setw(20) << right << Arr[i][j].MidTerm << setw(20) << right << Arr[i][j].Final << setw(23) << right << Arr[i][j].Total << endl;
		}
		else {
			cout << setw(5) << right << Arr[i][j].No << setw(15) << right << Arr[i][j].FullName << setw(17) << right << Arr[i][j].Id << setw(15) << right << x << setw(21) << right << x << setw(20) << right << x << setw(23) << right << x << endl;
		}
	}
}
bool CheckScore(string name, string id, bool check = false) {
	ifstream file;
	string str, temp;
	cout << name << endl;
	file.open(name + ".txt"); {
		if (!file.fail())cout << "ok";
		while (!file.eof()) {
			if (check == true)getline(file, str);
			else if (check == false) {
				getline(file, str, ',');
			}
			if (id == str) {
				return true;
			}
			if (temp == str)return false;
			temp = str;
		}
	}file.close();
}
void menu4(login& f) {
	int luachon, n(300), temp1, dem(0), demmangterm(0);
	Year y;
	login* f1 = new login[n];
	Score ArrScore[10][100];
	Term* ArrTerm = new Term[10];
	login f2, f3, text;
	system("cls");
	do {
		cout << "\t\tTHONG TIN CA NHAN" << endl;
		cout << "\t\t1.Doi mat khau" << endl;
		cout << "\t\t2.Xuat thong tin cac khoa hoc cua sinh vien" << endl;
		cout << "\t\t3.Xuat bang diem cua sinh vien" << endl;
		cout << "\t\t0.Dang xuat" << endl;
		cout << "moi ban nhap vao lua chon:";
		cin >> luachon;
		if (luachon == 1) {
			cout << "vui long nhap vao mat khau cu:" << endl;
			cin.ignore();
			getline(cin, text.password);
			if (text.password == f.password) {
				Returnfile("matkhausinhvien", f1, n);
				temp1 = temp(f1, f, n);
				for (int i(0); i < n; i++) {
					if (f1[i].username == f.username) {
						cout << "\tMAT KHAU CAN IT NHAT 8 KI TU SO,1 KI TU CHU THUONG,1 KI TU CHU HOA VA 1 KI DAC BIET " << endl;
						cout << "mat khau moi la:";
						getline(cin, f2.password);
						cout << "xac nhap lai mat khau:";
						getline(cin, f3.password);
						if (f2.password == f3.password && CheckValid(f2.password) == true) {
							f1[temp1].password = f2.password;
							Addfile("matkhausinhvien", f1, n);
							break;
						}
						else {
							system("cls");
							cout << "\t\tBAN DA NHAP SAI!!!!!\n";
							menu4(f);
						}
					}
				}
			}
			else {
				system("cls");
				cout << "\t\tBAN DA NHAP SAI!!!!!\n";
				menu4(f);
			}
		}
		else if (luachon == 2) {
			int n(0);
			string* Arr = new string[100];
			ReturnNameTerm(Arr, n);
			for (int i(0); i < n; i++) {
				if ((i + dem - 1) % 8 == 0) {
					string x = Arr[i];
					if (CheckTerm(x + ".txt", f.username) == true) {
						if (dem == 0)ArrTerm[demmangterm].Id = Arr[i - 1];
						else ArrTerm[demmangterm].Id = Arr[i - 1].substr(6);
						ArrTerm[demmangterm].Name = Arr[i];
						ArrTerm[demmangterm].NameClass = Arr[i + 1];
						ArrTerm[demmangterm].NameTeacher = Arr[i + 2];
						ArrTerm[demmangterm].Credit = stoi(Arr[i + 3]);
						ArrTerm[demmangterm].MaxStudents = stoi(Arr[i + 4]);
						ArrTerm[demmangterm].DayofWeek = Arr[i + 5];
						ArrTerm[demmangterm].Session = Arr[i + 6].substr(0, 4);
						demmangterm++;
						dem++;
					}
				}
			}
			OutputTerm(ArrTerm, demmangterm);
		}
		else if (luachon == 3) {
			int n(0), row(0), col(0), dem(0);
			string* Arr = new string[100];
			ReturnNameTerm(Arr, n);
			for (int i(0); i < n; i++) {

				if ((i + dem - 1) % 8 == 0) {
					string x = Arr[i];
					ReturnScoreSV(x, ArrScore, row, col, f.username);
					ArrScore[row][col].FullName = x;
					col++;
					dem++;
				}
			}
			int i = 0;
			string x = "Chua nhap";
			cout << "\t\t\t\t\tBANG DIEM CUA SINH VIEN" << endl;
			cout << "Thu tu" << right << setw(20) << "Ten khoa hoc" << setw(20) << "Diem qua trinh" << right << setw(20) << "Diem giua ki" << setw(20) << "Diem cuoi ki" << right << setw(20) << "Diem tong" << endl;
			for (int j(0); j < col; j++) {
				if (ArrScore[i][j].Other != -1.0 && ArrScore[i][j].MidTerm != -1.0 && ArrScore[i][j].Final != -1.0) {
					cout << setw(5) << right << ArrScore[i][j].No << setw(15) << right << ArrScore[i][j].FullName << setw(15) << right << ArrScore[i][j].Other << setw(23) << right << ArrScore[i][j].MidTerm << setw(23) << right << ArrScore[i][j].Final << setw(23) << right << ArrScore[i][j].Total << endl;
				}
				else {
					cout << setw(5) << right << ArrScore[i][j].No << setw(15) << right << ArrScore[i][j].FullName << setw(22) << right << x << setw(21) << right << x << setw(20) << right << x << setw(23) << right << x << endl;
				}
			}
		}
		else if (luachon == 0) {
			system("cls");
			menu();
		}
	} while (luachon != 0);
}
void menu3(List l, Year y, string Year, ListClass lc) {
	int i(0), begin, end, dem(0), value(0), demscore(0);
	Score ArrScoreSencond[10][100];
	Score ArrScore[10][100];
	List* ArrList = new List[10];
	string x, name, addname, termname, nameterm, noterm, deletename, deletenameterm, scoreterm, termscore, namescore, nameclass;
	Node* q = new Node;
	Term t;
	Term* Arr = new Term[10];
	int luachon, temp(0), chon(1);
	fstream file;
	system("cls");
	cout << "\t\t\tNam hoc " << left << setw(20) << Year << "(Hoc ki" << y.YearStudy << ")" << "bat dau va ket thuc vao :" << y.Begin << endl;
	cout << "\t\t1.Tao 1 khoa hoc" << endl;
	cout << "\t\t2.Xuat danh sach cua cac khoa hoc" << endl;
	cout << "\t\t3.Xuat danh sach cua 1 khoa hoc" << endl;
	cout << "\t\t4.Sua doi 1 khoa hoc" << endl;
	cout << "\t\t5.Them 1 hoc sinh vao khoa hoc" << endl;
	cout << "\t\t6.Xoa 1 sinh vien khoi khoa hoc" << endl;
	cout << "\t\t7.Xoa 1 khoa hoc" << endl;
	cout << "\t\t8.Cap nhat diem cho sinh vien trong khoa hoc" << endl;
	cout << "\t\t9.Xuat danh sach diem cua 1 khoa hoc" << endl;
	cout << "\t\t10.Xuat bang diem cua 1 lop hoc" << endl;
	cout << "\t\t0.Quay lai" << endl;
	do {
		cout << "Vui long nhap vao lua chon:";
		cin >> luachon;
		if (luachon == 1) {
			t = CreatTerm();
			Arr[i] = t;
			nameterm = t.Name + ".txt";
			int n(1);
			List tempListbegin, tempListend;
			CreatList(tempListbegin);
			CreatList(tempListend);
			tempListbegin = ReturnList(lc, t.NameClass);
			Inputfile(nameterm, tempListbegin, t.MaxStudents);
			tempListend = CopyList(tempListbegin, tempListend, t.MaxStudents);
			ArrList[i++] = tempListend;
			InputFileTerm(Arr, i);
		}
		else if (luachon == 2)OutputTerm(Arr, i);
		else if (luachon == 3) {
			cout << "\t\t\tCac khoa hoc da khoi tao" << endl;
			for (int j(0); j < i; j++) {
				cout << j + 1 << "." << Arr[j].Name << endl;
			}
			cout << "Nhap vao khoa muon xem danh sach:";
			cin.ignore();
			getline(cin, x);
			for (int j(0); j < i; j++) {
				if (x == Arr[j].Name) {
					OutPutList(ArrList[j]);
					break;
				}
			}
		}
		else if (luachon == 4) {
			cout << "Nhap vao ten khoa muon thay doi:";
			cin.ignore();
			getline(cin, name);
			ResetTerm(Arr, i, name);
			InputFileTerm(Arr, i);
		}
		else if (luachon == 5) {
			Node* p = new Node;
			Node* k = new Node;
			cout << "\t\t\tCac khoa hoc da khoi tao" << endl;
			for (int j(0); j < i; j++) {
				cout << j + 1 << "." << Arr[j].Name << endl;
			}
			cout << "Moi ban nhap vao khoa hoc muon them:";
			cin.ignore();
			getline(cin, addname);
			for (int j(0); j < i; j++) {
				if (addname == Arr[j].Name) {
					if (Arr[j].MaxStudents == Returnvalue(ArrList[j])) {
						cout << "\t\tDANH SACH DA DU SO LUONG!!!!" << endl;
						break;
					}
					k = ReturnSameId(l);
					p = CreatNode(k->data);
					AddTail(ArrList[j], p);
					ResetNo(ArrList[j]);
					Inputfile(addname + ".txt", ArrList[j]);
					break;
				}
			}
		}
		else if (luachon == 6) {
			cout << "\t\t\tCac khoa hoc da khoi tao" << endl;
			for (int j(0); j < i; j++) {
				cout << j + 1 << "." << Arr[j].Name << endl;
			}
			cout << "Moi ban nhap vao khoa hoc muon xoa:";
			cin.ignore();
			getline(cin, deletename);
			for (int j(0); j < i; j++) {
				if (deletename == Arr[j].Name) {
					DeleteStudentTerm(ArrList[j]);
					Inputfile(deletename + ".txt", ArrList[j]);
					ResetNo(ArrList[j]);
					break;
				}
			}
		}
		else if (luachon == 7) {
			cout << "\t\t\tCac khoa hoc da khoi tao" << endl;
			for (int j(0); j < i; j++) {
				cout << j + 1 << "." << Arr[j].Name << endl;
			}
			cout << "Moi ban nhap vao khoa hoc muon xoa:";
			cin.ignore();
			getline(cin, deletenameterm);
			for (int j(0); j < i; j++) {
				if (deletenameterm == Arr[j].Name) {
					deletenameterm = deletenameterm + ".txt";
					DeleteTerm(deletenameterm, ArrList, Arr, i, j);
					InputFileTerm(Arr, i);
					break;
				}
			}
		}
		else if (luachon == 8) {
			cout << "\t\t\tcac khoa hoc da khoi tao" << endl;
			for (int j(0); j < i; j++) {
				cout << j + 1 << "." << Arr[j].Name << endl;
			}
			cout << "moi ban nhap vao khoa hoc muon cap nhat diem:";
			cin.ignore();
			getline(cin, scoreterm);
			for (int j(0); j < i; j++) {
				if (scoreterm == Arr[j].Name) {
					ScoreTerm(scoreterm, ArrList[j], demscore);
					break;
				}
			}
		}
		else if (luachon == 9) {
			cout << "\t\t\tcac khoa hoc da khoi tao" << endl;
			for (int j(0); j < i; j++) {
				cout << j + 1 << "." << Arr[j].Name << endl;
			}
			cout << "moi ban nhap vao khoa hoc muon xem diem:";
			cin.ignore();
			getline(cin, termscore);
			for (int j(0); j < i; j++) {
				int demdiem(0);
				if (termscore == Arr[j].Name) {
					cout << "\t\tBang diem cua sinh vien khoa" << " " << Arr[j].Name << endl;
					ReturnScore(Arr[j].Name, ArrScore, j, demdiem, ArrList[j]);
					OutputScore(ArrScore, j, demdiem);
					break;
				}
			}
		}
		else if (luachon == 10) {
			fstream file;
			int demlop(1);
			string str = " ";
			cout << "\t\tCac lop hoc da khoi tao" << endl;
			file.open("Lop.txt", ios_base::in); {
				while (!file.eof()) {
					getline(file, str, ',');
					cout << demlop << "." << str << endl;
					demlop++;
				}

			}
			cout << "Nhap lop hoc ban muon xem diem:";
			cin.ignore();
			getline(cin, nameclass);
			if (CheckScore("Lop", nameclass, true) == true) {
				cout << "Nhap vao ma so sinh vien ma ban muon xem diem:";
				getline(cin, namescore);
				int n(0), row(0), col(0), dem(0);
				string* ArrName = new string[100];
				ReturnNameTerm(ArrName, n);
				for (int i(0); i < n; i++) {
					string x = ArrName[i];
					if ((i + dem - 1) % 8 == 0 && CheckTerm(x + ".txt", namescore) == true) {
						ReturnScoreSV(x, ArrScoreSencond, row, col, namescore);
						ArrScoreSencond[row][col].FullName = x;
						col++;
						dem++;
					}
				}
				int k = 0;
				string x = "Chua nhap";
				cout << "\t\t\t\t\tBANG DIEM CUA SINH VIEN" << endl;
				cout << "Thu tu" << right << setw(20) << "Ten khoa hoc" << setw(20) << "Diem qua trinh" << right << setw(20) << "Diem giua ki" << setw(20) << "Diem cuoi ki" << right << setw(20) << "Diem tong" << endl;
				for (int j(0); j < col; j++) {
					if (ArrScoreSencond[k][j].Other != -1.0 && ArrScoreSencond[k][j].MidTerm != -1.0 && ArrScoreSencond[k][j].Final != -1.0) {
						cout << setw(5) << right << ArrScoreSencond[k][j].No << setw(15) << right << ArrScoreSencond[k][j].FullName << setw(15) << right << ArrScoreSencond[k][j].Other << setw(23) << right << ArrScoreSencond[k][j].MidTerm << setw(23) << right << ArrScoreSencond[k][j].Final << setw(23) << right << ArrScoreSencond[k][j].Total << endl;
					}
					else {
						cout << setw(5) << right << ArrScoreSencond[k][j].No << setw(15) << right << ArrScoreSencond[k][j].FullName << setw(22) << right << x << setw(21) << right << x << setw(20) << right << x << setw(23) << right << x << endl;
					}
				}
			}
		}
	} while (luachon != 0);
}
void menu2(Year y) {
	List l;
	Year y1;
	string year;
	ListClass lc;
	Class* arr;
	CreatList(l);
	int luachon, n(1), x, dem(0);
	system("cls");
	cout << "\t\t\tNam hoc " << left << setw(20) << y.YearStudy << "bat dau vao :" << y.Begin << endl;
	cout << "\t\t1.Them 1 sinh vien nam nhat " << endl;
	cout << "\t\t2.Them 1 CSV sinh vien nam nhat" << endl;
	cout << "\t\t3.Tao cac lop hoc" << endl;
	cout << "\t\t4.Xuat danh sach sinh vien nam nhat" << endl;
	cout << "\t\t5.Tao 1 hoc ki moi" << endl;
	cout << "\t\t0.Quay lai" << endl;
	do {
		cout << "moi ban nhap vao lua chon:";
		cin >> luachon;
		if (luachon == 1) {
			dem++;
			AddOne(l, n);
			fstream file;
			file.open("sinhviennamnhat.txt", ios_base::app); {
				file << endl << l.pTail->data.Id << "," << l.pTail->data.Fname << "," << l.pTail->data.Lname << "," << l.pTail->data.sex << "," << l.pTail->data.DayofBirth.Day << "/" << l.pTail->data.DayofBirth.Month << "/" << l.pTail->data.DayofBirth.Year << "," << l.pTail->data.IdSocial;
			}
			file.close();
		}
		else if (luachon == 2) {
			filesvnamnhat("sinhviennamnhat", l, n);
			InputPasswordStudents("matkhausinhvien", l);
			dem++;
		}
		else if (luachon == 3) {
			if (dem <= 0) {
				cout << "\t\tDANH SACH CHUA CO SINH VIEN NAO" << endl;
				menu2(y);
			}
			else {
				cout << "Vui long nhap vao so lop hoc can tao:";
				cin >> x;
				arr = new Class[x];
				CreatClass(arr, x, lc);
				InputClass(l, lc, arr, x);
			}
		}
		else if (luachon == 4) OutPutList(l);
		else if (luachon == 5) {
			int value(0);
			List l1;
			CreatList(l1);
			cout << "vui long nhap vao hoc ki ma ban lua chon \n ki 1 (mua thu), ki 2(mua he), ki 3 (mua thu):";
			cin.ignore();
			getline(cin, y1.YearStudy);
			cout << "vui long nhap vao thoi gian bat dau va ket thuc cua hoc ki vua lua chon tren (cach nhau boi dau -):";
			getline(cin, y1.Begin);
			year = y.YearStudy;
			filesvnamnhat("sinhviennamnhat", l1, value);
			menu3(l1, y1, year, lc);
		}
	} while (luachon != 0);
}
void menu1(login& f) {
	int luachon, n(10), temp1;
	Year y;
	login* f1 = new login[n];
	login f2, f3, text;
	cout << "\t\tTHONG TIN CA NHAN" << endl;
	cout << "\t\t1.Ho so ca nhan" << endl;
	cout << "\t\t2.Doi mat khau" << endl;
	cout << "\t\t3.tao 1 nam hoc" << endl;
	cout << "\t\t0.Dang xuat" << endl;
	do {
		cout << "moi ban nhap vao lua chon:";
		cin >> luachon;
		if (luachon == 1) {
			system("cls");
			Information(f);
		}
		else if (luachon == 2) {
			cout << "vui long nhap vao mat khau cu:" << endl;
			cin.ignore();
			getline(cin, text.password);
			if (text.password == f.password) {
				Returnfile("canbo", f1, n);
				temp1 = temp(f1, f, n);
				for (int i(0); i < n; i++) {
					if (f1[i].username == f.username) {
						cout << "\tMAT KHAU CAN IT NHAT 8 KI TU SO,1 KI TU CHU THUONG,1 KI TU CHU HOA VA 1 KI DAC BIET " << endl;
						cout << "mat khau moi la:";
						getline(cin, f2.password);
						cout << "xac nhap lai mat khau:";
						getline(cin, f3.password);
						if (f2.password == f3.password && CheckValid(f2.password) == true) {
							f1[temp1].password = f2.password;
							Addfile("canbo", f1, n);
							break;
						}
						else {
							system("cls");
							cout << "\t\tBAN DA NHAP SAI!!!!!\n";
							menu1(f);
						}
					}
				}
			}
			else {
				system("cls");
				cout << "\t\tBAN DA NHAP SAI!!!!!\n";
				menu1(f);
			}
		}
		else if (luachon == 3) {
			cout << "Vui long nhap vao khoa hoc:";
			cin >> y.YearStudy;
			cout << "Nhap vao ngay bat dau cua khoa hoc(thuong bat dau vao thang 9):";
			cin.ignore();
			cin >> y.Begin;
			system("cls");
			menu2(y);

		}
		else if (luachon == 0) {
			system("cls");
			menu();
		}
	} while (luachon != 0);
}
void menu() {
	int luachon, dem(0), dem2(0), y, y1;
	login f, f1;
	cout << "\t----------LOGIN----------" << endl;
	cout << "\t\t1.Can bo hoc vu" << endl;
	cout << "\t\t2.Sinh vien" << endl;
	cout << "\t\t0.ket thuc!!" << endl;
	cout << "\t------------------------" << endl;
	cout << "moi ban nhap vao lua chon:";
	cin >> luachon;
	cin.ignore();
	if (luachon == 1) {
		bool check = false;
		do {
			system("cls");
			cout << "\t\tVUI LONG NHAP THONG TIN DANG NHAP" << endl;
			cout << "ten dang nhap:";
			getline(cin, f.username);
			cout << "mat khau:";
			getline(cin, f.password);
			int x = CheckRobot();
			cin >> y;
			cin.ignore();
			dem++;
			if (dem == 5) {
				cout << "ban da nhap sai 5 lan" << endl;
				break;
			}
			if (Login("canbo", f) && x == y) {
				check = true;
				cout << "DANG NHAP THANH CONG" << endl;
				system("cls");
				menu1(f);
			}
		} while (check != true);
		menu1(f);
	}
	if (luachon == 2) {
		bool check = false;
		do {
			system("cls");
			cout << "\t\tVUI LONG NHAP THONG TIN DANG NHAP" << endl;
			cout << "ten dang nhap:";
			getline(cin, f1.username);
			cout << "mat khau:";
			getline(cin, f1.password);
			int x = CheckRobot();
			cin >> y1;
			cin.ignore();
			dem2++;
			if (dem2 == 5) {
				cout << "ban da nhap sai 5 lan" << endl;
				break;
			}
			if (Login("matkhausinhvien", f1) == true && x == y1) {
				check = true;
				cout << "DANG NHAP THANH CONG" << endl;
				//system("cls");
			}
		} while (check != true);
		menu4(f1);
	}
}