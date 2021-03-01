#include"All.h"
void ClearConsoleToColors(int ForgC, int BackC)
{
	WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
	//Get the handle to the current output buffer...
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//This is used to reset the carat/cursor to the top left.
	COORD coord = { 0, 0 };
	//A return value... indicating how many chars were written
	//not used but we need to capture this since it will be
	//written anyway (passing NULL causes an access violation).
	DWORD count;
	//This is a structure containing all of the console info
	// it is used here to find the size of the console.
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	//Here we will set the current color
	SetConsoleTextAttribute(hStdOut, wColor);
	if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
	{
		//This fills the buffer with a given character (in this case 32=space).
		FillConsoleOutputCharacter(hStdOut, (TCHAR)32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
		//This will set our cursor position for the next print statement.
		SetConsoleCursorPosition(hStdOut, coord);
	}
}
void ShowConsoleCursor(bool showFlag)				//xóa phần dư nhấp nháy con trỏ.
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO     cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
void gotoXY(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void Gioithieu() {
	fstream file;
	file.open("ba.txt");
	int i = 0;
	while (!file.eof()) {
		char chuoi[150];
		file.getline(chuoi, 150);
		cout << chuoi << endl;
	}
	file.close();
}
void resetMauMacDinh() {
	TextColor(15);
}
void clrscr()
{
	CONSOLE_SCREEN_BUFFER_INFO  csbiInfo;
	HANDLE  hConsoleOut;
	COORD   Home = { 0,0 };
	DWORD   dummy;

	hConsoleOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hConsoleOut, &csbiInfo);

	FillConsoleOutputCharacter(hConsoleOut, ' ', csbiInfo.dwSize.X * csbiInfo.dwSize.Y, Home, &dummy);
	csbiInfo.dwCursorPosition.X = 0;
	csbiInfo.dwCursorPosition.Y = 0;
	SetConsoleCursorPosition(hConsoleOut, csbiInfo.dwCursorPosition);
} 
bool ktraphimmuiten() {
	bool isKeyUp = GetKeyState(VK_UP) & 0x8000;
	bool isKeyDown = GetKeyState(VK_DOWN) & 0x8000;
	bool isKeyRight = GetKeyState(VK_RIGHT) & 0x8000;
	bool isKeyLeft = GetKeyState(VK_LEFT) & 0x8000;
	if (isKeyDown || isKeyLeft || isKeyRight || isKeyUp)
		return true;
	else return false;
}
// Nhap chu va so k cho ki tu dac biet
void Nhap_loc(char a[], int dolon) {
	char* tam = new char[dolon];
	int i = 0; char key; int dem = 0;
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (dem < dolon-1 )
			{
				 if (((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || (key == 32) || (key >= 48 && key <= 57))&&!ktraphimmuiten()) //anphabet
				{
					tam[i] = key;
					cout << tam[i];
					i++; dem++;
				}
				else if (key == 13)  //thoát khi gặp enter
				{
					if (dem != 0) {
						cout << endl;
						tam[i] = '\0';
						break;
					}
				}
				else if (key == 8) //xử lí xóa bằng backspace
				{
					if (i != 0)
					{
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
			else                         //xử lí tối đa kí tự
			{
				if (key == 13) {
					cout << endl;
					tam[i] = '\0';
					break;
				}
				else if (key == 8)
				{
					if (i != 0)
					{
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
		}
	}
	for (int j = 0; j < strlen(tam)+1; j++)
		a[j] = tam[j];
}
void Nhap_chu(char a[], int dolon) {
	char* tam = new char[dolon];
	int i = 0; char key; int dem = 0;
	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			if (dem < dolon - 1)
			{
				if (((key >= 65 && key <= 90) || (key >= 97 && key <= 122) || (key == 32)) && !ktraphimmuiten()) //anphabet
				{
					tam[i] = key;
					cout << tam[i];
					i++; dem++;
				}
				else if (key == 13)  //thoát khi gặp enter
				{
					if (dem != 0) {
						cout << endl;
						tam[i] = '\0';
						break;
					}
				}
				else if (key == 8) //xử lí xóa bằng backspace
				{
					if (i != 0)
					{
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
			else                         //xử lí tối đa kí tự
			{
				if (key == 13) {
					cout << endl;
					tam[i] = '\0';
					break;
				}
				else if (key == 8)
				{
					if (i != 0)
					{
						cout << "\b" << " " << "\b";
						i--; dem--;
						tam[i] = '\0';
					}
				}
			}
		}
	}
	for (int j = 0; j < strlen(tam) + 1; j++)
		a[j] = tam[j];
}
bool Kiemtrarong(char name[])
{
	int i = 0;
	while (name[i] == ' ')i++;
	if (strlen(name) == i)
	{
		return 1;
	}
	else return 0;
}
bool Kiemtrarong(string a) {
	int i = 0;
	while (a[i] == ' ')i++;
	if (a.length() == i)
	{
		return 1;
	}
	else return 0;
}
void Xoakhoangtrang(char name[])
{
	//xoa 2 kc ke nhau
	int n = strlen(name);
	for (int i = 0; i < n; i++)
	{
		if (name[i] == name[i + 1] && name[i] == ' ')
		{
			for (int j = i + 1; j < n; j++)
				name[j] = name[j + 1];
			n--;i--;
		}
	}
	name[n] = '\0';
	//xoa dau
	int i = 0;
	if (name[i] == ' ') 
		for (i; i < strlen(name); i++)name[i] = name[i + 1];
	//xóa cuối;
	int j = strlen(name) - 1;
	if (name[j] == ' ')name[j] = '\0';
}
//string chua lm dc
void Xoakhoangtrang(string &a) {
	int n = a.length();
	for (int i = 0; i < n; i++)
	{
		if (a[i] == a[i + 1] && a[i] == ' ')
		{
			for (int j = i + 1; j < n; j++)
			{
				a[j] = a[j + 1];
			}
			n--; i--;
		}
	}
	a[n] = '\0';

	////xoa dau
	//int i = 0;
	//if (a[i] == ' ') {
	//	for (i; i < a.length(); i++)a[i] = a[i + 1];
	//}
	////xóa cuối;
	//int j = a.length() - 1;
	//if (a[j] == ' ')a[j] = '\0';
}
int Convert_num(char chuoi[], int sl)   
{
	int i = 0;
	int kq = 0; int t = 1;
	for (int i = 0; i < sl; i++)
	{
		kq = kq + (((int)(chuoi[sl - i - 1]) - 48) * t);
		t = t * 10;
	}
	return kq;
}
int Convert_num(char chuoi[]) {
	int i = 0;
	int kq = 0; int t = 1;
	for (int i = 0; i<strlen(chuoi); i++)
	{
		kq = kq + (((int)(chuoi[strlen(chuoi) - i - 1]) - 48) * t);
		t = t * 10;
	}
	return kq;
}
void Nhapso(char a[], int size) {
	char *ID = new char[size];
	int i = 0; char key; int dem = 0;
	while (1)
	{
		key = _getch();
		if (dem < size - 1)
		{
			if (key >= 48 && key <= 57)  //0-9
			{
				ID[i] = key;
				cout << ID[i];
				i++; dem++;
			}
			else if (key == 13)  //thoát khi gặp enter
			{
				if (dem != 0) {
					cout << endl;
					ID[i] = '\0';
					break;
				}
			}
			else if (key == 8) //xử lí xóa bằng backspace
			{
				if (i != 0)
				{
					cout << "\b" << " " << "\b";
					i--; dem--;
					ID[i] = '\0';
				}
			}
		}
		else                         //xử lí tối đa 9 kí tự
		{
			if (key == 13)
			{
				if (dem != 0) {
					cout << endl;
					ID[i] = '\0';
					break;
				}
			}
			else if (key == 8)
			{
				if (i != 0)
				{
					cout << "\b" << " " << "\b";
					i--; dem--;
					ID[i] = '\0';
				}
			}
		}
	}
	for (int j = 0; j < strlen(ID) + 1; j++)
		a[j] = ID[j];
}
void Nhapso(int &so, int size)
{
	char *ID = new char[size];
	int i = 0; char key; int dem = 0;
	while (1)
	{
		key = _getch();
		if (dem < size-1)
		{
			if (key >= 48 && key <= 57)  //0-9
			{
				ID[i] = key;
				cout << ID[i];
				i++; dem++;
			}
			else if (key == 13)  //thoát khi gặp enter
			{
				if (dem != 0) {
					cout << endl;
					ID[i] = '\0';
					break;
				}
			}
			else if (key == 8) //xử lí xóa bằng backspace
			{
				if (i != 0)
				{
					cout << "\b" << " " << "\b";
					i--; dem--;
					ID[i] = '\0';
				}
			}
		}
		else                         //xử lí tối đa 9 kí tự
		{
			if (key == 13)
			{
				if (dem != 0) {
					cout << endl;
					ID[i] = '\0';
					break;
				}
			}
			else if (key == 8)
			{
				if (i != 0)
				{
					cout << "\b" << " " << "\b";
					i--; dem--;
					ID[i] = '\0';
				}
			}
		}
	}
	so = Convert_num(ID, dem);
	delete ID;
}
void Upcase(char string[]) {
	int i = 0;
	for (i; i < strlen(string); i++) {
		if (string[i] >= 97 && string[i] <= 122) {
			string[i] = string[i] - 32;
		}
	}
}
void Upcasedau(char string[]) {
	string[0] = string[0] - 32;
}
char Laychudau(char string[]) {
	return string[0];
}
bool Filerong(fstream &file) {
		if (!file.is_open()) {
			cout << "File chua dc mo" << endl;
			return false;
		}
		else {
			file.seekp(0, ios::end);
			size_t size = file.tellg();
			file.seekp(0, ios::beg);
			if (size == 0)
				return true;
			else
				return false;
		}
	}
bool LaNamNhuan(int nam) {
	if (nam % 400 == 0 || (nam % 4 == 0 && nam % 100 != 0))
		return 1;
	else return 0;
}
char* Convertstringtochar(string a) {
	int size = a.length()+1;
	char* tam = new char[size];
	for (int i = 0; i < size; i++) {
		tam[i] = a[i];
	}
	tam[size] = '\0';
	return tam;
}
void Realtime()
{
	time_t hientai = time(NULL);
	tm *tg = localtime(&hientai);
	cout << tg->tm_hour << " Gio" << endl;
	cout << tg->tm_min << " Phut" << endl;
	cout << tg->tm_sec << " Giay" << endl;
	cout << "Ngay: " << tg->tm_mday << endl;
	cout << "Thang: " << 1 + tg->tm_mon << endl;
	cout << "Nam: " << 1900 + tg->tm_year << endl;
}
int Realday() {
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return tg->tm_mday;
}
int Realmonth(){
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return 1+tg->tm_mon;
}
int Realyear() {
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return 1900+tg->tm_year;
}
int Realhour() {
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return tg->tm_hour;
}
int Realmin() {
	time_t hientai = time(0);
	tm *tg = localtime(&hientai);
	return tg->tm_min;
}






void Ghe(int vitrix,int vitriy,int soghe,int mau) {
	TextColor(mau);
	gotoXY(vitrix, vitriy);
	cout << "-------" << endl;
	gotoXY(vitrix, vitriy + 1);
	cout << "|     |" << endl;
	gotoXY(vitrix, vitriy + 2);
	cout << "-------" << endl;
	gotoXY(vitrix + 1, vitriy + 1);
	//TextColor(30);
	cout << soghe;
}
void MuaVe() {
	bool chuamua[152];
	for (int i = 1; i <= 151; i++)
		chuamua[i] = true;
	int mau;
	int contro = 1;
	int vemua = 0;
	clrscr(); int page = 1; int pagemax = 4; int vitrix = 0; int vitriy = 0; int dem = 0;
	int batdau; int ketthuc; char key; int tmp;
	while (1) {
		ShowConsoleCursor(false);
		vitrix = 0; vitriy = 0;
		dem = 0;			
		batdau = 50 * (page-1) + 1;
		while (chuamua[contro] == false)/*if (contro > page * 50)break;*/
		contro = contro++;
		if (page == pagemax)ketthuc = batdau + (151 % 50-1);
		else ketthuc = batdau + 49;
		for (int i=batdau; i <= ketthuc; i++) {
			if (i == contro)mau = 46;
			else if (chuamua[i] == false)mau = 71;
			else mau = 31;
			Ghe(vitrix, vitriy, i,mau);
			dem++; vitrix += 10;
			if (dem == 10) {
				vitrix = 0;
				vitriy += 5;
				dem = 0;
			}
		}
			key = _getch();
			tmp = contro;
			if (key == 97) {
				while (1) {
					if (tmp == 1) {
						tmp = tmp + 49;
					}
					else {
						tmp = tmp - 1;
					}
					if (chuamua[tmp] == true) {
						contro = tmp;
						break;
					}
					if (vemua == 50)break;
				}
			}
			else if (key == 119) {
				int count = 0;
				while (1) {
					if (tmp <= 10 && tmp >= 1)tmp = tmp + 40;
					else tmp = tmp - 10;
					count++;
					if (chuamua[tmp] == true) {
						contro = tmp;
						break;
					}
					if (count == 5||vemua==50)break;
				}
			}
			else if (key == 100) {
				while (1) {
					if (tmp == 50) {
						tmp = tmp - 49;
					}
					else {
						tmp = tmp + 1;
					}
					if (chuamua[tmp] == true) {
						contro = tmp;
						break;
					}
					if (vemua == 50)break;
				}
			}
			else if (key == 115) {
				int count = 0;
				while (1) {
					if (tmp <= 50 && tmp >= 41)tmp = tmp - 40;
					else tmp = tmp + 10;
					count++;
					if (chuamua[tmp] == true) {
						contro = tmp;
						break;
					}
					if (count == 5||vemua==50)break;
				}
			}
			else if (key == 75) {
				if (page == 1)page = pagemax;
				else page--;
				contro=(page - 1) * 50 + 1;
				clrscr();
				system("color 07");
			}
			else if (key == 77) {
				if (page == pagemax)page = 1;
				else page++;
				contro = (page - 1) * 50 + 1;
				clrscr();
				system("color 07");
			}
			else if (key == 13) {
				chuamua[contro] = false;
				vemua++;
			}
			if (vemua == 150) {
				cout << "HET ve" << endl;
				break;
			}
	}
	
}
void VeKhungThemMB() {
	char ngang = 205; char doc = 186;
	system("chcp 437");
	gotoXY(0, 0); cout << "                     ";
	for (int i = 19; i <= 30; i++) {
		gotoXY(39, i);
		cout << doc;
		gotoXY(80+39, i);
		cout << doc;
	/*	gotoXY(68, i);
		cout << doc;*/
	}
	for (int i = 1; i < 80; i++) {
		gotoXY(39 + i, 19);
		cout << ngang;
		gotoXY(39 + i, 30);
		cout << ngang;
		gotoXY(39 + i, 22);
		cout << ngang;
		gotoXY(39 + i, 25);
		cout << ngang;
		gotoXY(39 + i, 28);
		cout << ngang;
	}
	char a = 201;
	gotoXY(39, 19);
	cout << a;
	a = 200;
	gotoXY(39,30 );
	cout << a;
	a = 187;
	gotoXY(39 + 80, 19);
	cout << a;
	a = 188;
	gotoXY(39 + 80, 30);
	cout << a;
}
void VeKhungXoaMB() {
	char ngang = 205; char doc = 186;
	system("chcp 437");
	gotoXY(0, 0); cout << "                     ";
	for (int i = 1; i < 80; i++) {
		gotoXY(39 + i, 19);
		cout << ngang;
		gotoXY(39 + i, 22);
		cout << ngang;
	}
	for (int i = 19; i <= 22; i++) {
		gotoXY(39, i);
		cout << doc;
		gotoXY(80 + 39, i);
		cout << doc;
	}
	char a = 201;
	gotoXY(39, 19);
	cout << a;
	a = 200;
	gotoXY(39, 22);
	cout << a;
	a = 187;
	gotoXY(39 + 80, 19);
	cout << a;
	a = 188;
	gotoXY(39 + 80, 22);
	cout << a;
}
void VeKhungThemCB() {
	char ngang = 205; char doc = 186;
	system("chcp 437");
	gotoXY(0, 0); cout << "                     ";
	for (int i = 1; i < 80; i++) {
		gotoXY(39 + i, 19);
		cout << ngang;
		gotoXY(39 + i, 33);
		cout << ngang;
		gotoXY(39 + i, 35);
		cout << ngang;
		gotoXY(39 + i, 22);
		cout << ngang;
		gotoXY(39 + i, 25);
		cout << ngang;
		gotoXY(39 + i, 28);
		cout << ngang;
	}
	for (int i = 19; i <= 35; i++) {
		gotoXY(39, i);
		cout << doc;
		gotoXY(80 + 39, i);
		cout << doc;
	}
	char a = 201;
	gotoXY(39, 19);
	cout << a;
	a = 200;
	gotoXY(39, 35);
	cout << a;
	a = 187;
	gotoXY(39 + 80, 19);
	cout << a;
	a = 188;
	gotoXY(39 + 80, 35);
	cout << a;
}
void VeKhungThemHK() {
	char ngang = 205; char doc = 186;
	system("chcp 437");
	gotoXY(0, 0); cout << "                     ";
	for (int i = 1; i < 80; i++) {
		gotoXY(39 + i, 19);
		cout << ngang;
		gotoXY(39 + i, 31);
		cout << ngang;
		gotoXY(39 + i, 33);
		cout << ngang;
		gotoXY(39 + i, 22);
		cout << ngang;
		gotoXY(39 + i, 25);
		cout << ngang;
		gotoXY(39 + i, 28);
		cout << ngang;
	}
	for (int i = 19; i <= 33; i++) {
		gotoXY(39, i);
		cout << doc;
		gotoXY(80 + 39, i);
		cout << doc;
	}
	char a = 201;
	gotoXY(39, 19);
	cout << a;
	a = 200;
	gotoXY(39, 33);
	cout << a;
	a = 187;
	gotoXY(39 + 80, 19);
	cout << a;
	a = 188;
	gotoXY(39 + 80, 33);
	cout << a;
}
void VeKhungHuongDan() {
	char ngang = 205; char doc = 186;
	system("chcp 437");
	for (int i = 1; i < 30; i++) {
		gotoXY(130 + i, 5);
		cout << ngang;
		gotoXY(130 + i, 10);
		cout << ngang;
	}
	for (int i = 5; i <= 10; i++) {
		gotoXY(130, i);
		cout << doc;
		gotoXY(160, i);
		cout << doc;
	}
	char a = 201;
	gotoXY(130, 5);
	cout << a;
	a = 200;
	gotoXY(130, 10);
	cout << a;
	a = 187;
	gotoXY(160, 5);
	cout << a;
	a = 188;
	gotoXY(160, 10);
	cout << a;
	TextColor(10);
	gotoXY(132, 6); cout << "Up arrow:"; gotoXY(147, 6); cout << "Len";
	gotoXY(132, 7); cout << "Down arrow:"; gotoXY(147, 7); cout << "Xuong";
	gotoXY(132, 8); cout << "Left arrow:"; gotoXY(147, 8); cout << "Trang truoc";
	gotoXY(132, 9); cout << "Right arrow:"; gotoXY(147, 9); cout << "Trang sau";
	TextColor(15);
}
void VeKhungChonDiemDen() {
	char ngang = 205; char doc = 186;
	system("chcp 437");
	cout << "                   ";
	for (int i = 0; i <= 61; i++) {
		gotoXY(44 + i, 1);
		cout << ngang;
		gotoXY(44 + i, 30);
		cout << ngang;
	}
	for (int i = 1; i <= 30; i++) {
		gotoXY(44, i);
		cout << doc;
		gotoXY(105, i);
		cout << doc;
	}
	char a = 201;
	gotoXY(44, 1);
	cout << a;
	a = 200;
	gotoXY(44, 30);
	cout << a;
	a = 187;
	gotoXY(105, 1);
	cout << a;
	a = 188;
	gotoXY(105, 30);
	cout << a;
}
