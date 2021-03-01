#include "display.h"
void Button(int vitrix, int vitriy, string text, int mau)
 {
	TextColor(mau);
	gotoXY(vitrix, vitriy);
	cout << "----------------------" << endl;
	gotoXY(vitrix, vitriy + 1);
	cout << "|                    |" << endl;
	gotoXY(vitrix, vitriy + 2);
	cout << "----------------------" << endl;
	gotoXY(vitrix + 1, vitriy + 1);
	cout << text;
}
void ThanhMenu(int vitrix, int vitriy, int mau, string title)
 {
	gotoXY(vitrix, vitriy);
	TextColor(mau);
	cout << title;
	resetMauMacDinh();
}
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void Menu1() {
	int key;	
	while (1) {
		ShowConsoleCursor(true);
		Button(30, 20, "   1-Them May Bay", 30);
		Button(60, 20, "   2-Xoa May Bay", 30);
		Button(90, 20, "3-Hieu chinh May Bay", 30);
		Button(120, 20, "  4-Ve Menu chinh", 30);
		Button(75, 30, "   Nhap lua chon: ",62);
		Nhapso(key, 2);
		Beep(La, 200);
		if (key == 1) {
			clrscr();
			system("color 07");
			DSMayBay ds;
			ds.Datain();
			ds.ThemMB();
			gotoXY(50, 32); TextColor(12);
			cout << "Ban co muon luu lai khong??";
			gotoXY(50, 33);
			cout << "--An Enter de luu lai thong tin-Esc de huy";
			char luachon = _getch();
			if (luachon == 13) {
				gotoXY(50, 34); cout << "                           ";
				gotoXY(50, 34);
				ds.Dataout();
			}
			TextColor(15); clrscr();
		}
		else if (key == 2) {
			clrscr();
			system("color 07");
			DSMayBay ds;
			DSChuyenBay* dscb=new DSChuyenBay;
			dscb->KhoitaoDSChuyenBay();
			dscb->Datain();
			ds.Datain();
			ds.XoaMB(dscb);
			gotoXY(50, 24); TextColor(12);
			cout << "Ban co muon luu lai khong??";
			gotoXY(50, 25);
			cout << "--An Enter de luu lai thong tin-Esc de huy";
			char luachon = _getch();
			if (luachon == 13) {
				gotoXY(50, 25); cout << "                                 ";
				gotoXY(50, 25);
				ds.Dataout();
			}
			TextColor(15); clrscr();
		}
		else if (key == 3) {
			clrscr(); system("color 07");
			DSMayBay ds;
			DSChuyenBay* dscb = new DSChuyenBay;
			dscb->KhoitaoDSChuyenBay();
			dscb->Datain();
			ds.Datain();
			ds.HieuChinhMB(dscb);
			gotoXY(50, 32); TextColor(12);
			cout << "Ban co muon luu lai khong??";
			gotoXY(50, 33);
			cout << "--An Enter de luu lai thong tin-Esc de huy";
			char luachon = _getch();
			if (luachon == 13) {
				gotoXY(50, 34); cout << "                           ";
				gotoXY(50, 34);
				ds.Dataout();
			}
			TextColor(15); clrscr();
		}
		else if (key == 4) {
			clrscr();
			break;
		}
	}
}
void Menu2() {
	int key;
	while (1) {
		clrscr();	ShowConsoleCursor(true);
		Button(30, 20, " 1-Lap chuyen bay moi", 30);
		Button(60, 20, "2-Hieu chinh ngay gio", 30);
		Button(90, 20, " 3-Huy Chuyen Bay", 30);
		Button(120, 20, "  4-Ve Menu chinh", 30);
		Button(75, 30, "   Nhap lua chon: ", 62);
		Nhapso(key, 2);
		Beep(La, 200);
		if (key == 1) {
			clrscr();
			system("color 07");
			DSChuyenBay dscb;
			dscb.KhoitaoDSChuyenBay();
			dscb.Datain();
			dscb.ThemChuyenBay();
			gotoXY(50, 36); TextColor(12);
			cout << "Ban co muon luu lai khong??";
			gotoXY(50, 37);
			cout << "--An Enter de luu lai thong tin-Esc de huy";
			char luachon = _getch();
			if (luachon == 13) {
				gotoXY(50, 38); cout << "                           ";
				gotoXY(50, 38);
				dscb.Dataout();
			}
			TextColor(15); clrscr();
		}
		else if (key == 2) {
			clrscr();
			system("color 07"); ShowConsoleCursor(true);
			DSChuyenBay dscb;
			dscb.KhoitaoDSChuyenBay();
			dscb.Datain();
			dscb.HieuChinhNgayGio();
			gotoXY(50, 36); TextColor(12);
			cout << "Ban co muon luu lai khong??";
			gotoXY(50, 37);
			cout << "--An Enter de luu lai thong tin-Esc de huy";
			char luachon = _getch();
			if (luachon == 13) {
				gotoXY(50, 38); cout << "                           ";
				gotoXY(50, 38);
				dscb.Dataout();
			}
			TextColor(15); clrscr();
		}
		else if (key == 3) {
			clrscr();
			system("color 07"); ShowConsoleCursor(true);
			DSChuyenBay dscb;
			dscb.KhoitaoDSChuyenBay();
			dscb.Datain();
			dscb.HuyChuyenBay();
			gotoXY(50, 36); TextColor(12);
			cout << "Ban co muon luu lai khong??";
			gotoXY(50, 37);
			cout << "--An Enter de luu lai thong tin-Esc de huy";
			char luachon = _getch();
			if (luachon == 13) {
				gotoXY(50, 38); cout << "                           ";
				gotoXY(50, 38);
				dscb.Dataout();
			}
			TextColor(15); clrscr();
		}
		else if (key == 4) {
			clrscr();
			break;
		}
	}
}
void Menu3() {
	int key;
	while (1) {
		clrscr(); ShowConsoleCursor(true);
		Button(60, 20, "     1-Dat ve", 30);
		Button(90, 20, "  2-Ve Menu chinh", 30);
		Button(75, 30, "   Nhap lua chon: ", 62);
		Nhapso(key, 2);
		Beep(La, 200);
		if (key == 1) {
			clrscr();
			system("color 07");
			DSChuyenBay dschuyenbay;
			dschuyenbay.KhoitaoDSChuyenBay();
			dschuyenbay.Datain();
			dschuyenbay.Datve();
		}
		else if (key == 2) {
			clrscr();
			break;
		}
	}
}
void Menu4() {
	int key;
	while (1) {
		clrscr(); ShowConsoleCursor(true);
		Button(60, 20, "     1-Huy ve", 30);
		Button(90, 20, "  2-Ve Menu chinh", 30);
		Button(75, 30, "   Nhap lua chon: ", 62);
		Nhapso(key, 2);
		Beep(La, 200);
		if (key == 1) {
			clrscr();
			system("color 07");
			DSChuyenBay dschuyenbay;
			dschuyenbay.KhoitaoDSChuyenBay();
			dschuyenbay.Datain();
			dschuyenbay.Huyve();
		}
		else if (key == 2) {
			clrscr();
			break;
		}
	}
}
void Menu5() {
	ShowConsoleCursor(true);
	clrscr();
	DSChuyenBay dschuyenbay;
	dschuyenbay.KhoitaoDSChuyenBay();
	dschuyenbay.Datain();
	dschuyenbay.InDS_motchuyenbay();
}
void Menu6() {
	ShowConsoleCursor(true);
	clrscr();
	DSChuyenBay dschuyenbay;
	dschuyenbay.KhoitaoDSChuyenBay();
	dschuyenbay.Datain();
	dschuyenbay.InDS_ngay_x_conve();
}
void Menu7() {
	clrscr();
	cout << "Esc-Ve Menu chinh" << endl;
	char key;
	while (1) {
		key = _getch();
		if (key == 27) {
			clrscr();
			break;
		}
	}

}
void Menu8() {
	clrscr();
	cout << "Esc-Ve Menu chinh" << endl;
	char key;
	while (1) {
		key = _getch();
		if (key == 27) {
			clrscr();
			break;
		}
	}
}
void Menu() {
	resizeConsole(1500, 750);
	int vitrix = 65; int vitriy = 30; int mau = 140;
	string str[10];
	str[1] = "1. Cap nhat danh sach cac may bay";
	str[2] = "2. Cap nhat chuyen bay";
	str[3] = "3. Dat ve";
	str[4] = "4. Huy ve";
	str[5] = "5. In danh sach 1 chuyen bay";
	str[6] = "6. In danh sach cac chuyen bay trong ngay X den noi Y";
	str[7] = "7. In danh sach cac ve con trong cua 1 chuyen bay co ma la X";
	str[8] = "8. Thong ke so luot thuc hien chuyen bay cua tung may bay";
	str[9] = "9. Thoat ung dung";
	int vitri = 1;
	ShowConsoleCursor(false);
	while (1) {
		system("color 07");//17 xanh
		gotoXY(0, 5);
		Gioithieu();
		for (int i = 1; i <= 9; i++) {
			if (i == vitri)mau = 240;
			else mau = 15;//31 xanh
			ThanhMenu(vitrix, vitriy + i, mau, str[i]);
		}
		//Xu li key
		char key = _getch();
		Beep(La, 200);
		if (key == 119) {
			if (vitri == 1) {
				vitri = 9;
			}
			else vitri--;
		}
		else if (key == 115) {
			if (vitri == 9)vitri = 1;
			else vitri++;
		}
		else if (key == 13) {
			ClearConsoleToColors(7, 0);
			if (vitri == 1) {
				 Menu1();
			}
			else if (vitri == 2) {
				 Menu2();
			}
			else if (vitri == 3) {
				Menu3();
			}
			else if (vitri == 4) {
				Menu4();
			}
			else if (vitri == 5) {
				Menu5();
			}
			else if (vitri == 6) {
				Menu6();
			}
			else if (vitri == 7) {
				Menu7();
			}
			else if (vitri == 8) {
				Menu8();
			}
			else if (vitri == 9) {
				Beep(La, 100);
				cout << "Ban co thuc su muon thoat!!" << endl;
				cout << "Yes:Enter------No:Esc" << endl;
				bool thoat = false;
				char key;
				while (1) {
					key = _getch();
					if (key == 13) {
						thoat = true;
						break;
					}
					else if (key == 27)break;
				}
				if (thoat) {
					clrscr();
					cout << "Ket thuc chuong trinh" << endl;
					break;
				}
			}
		}
	}
}
void vekhung() {
	char doc = 186; char ngang = 205; 
	for (int i = 0; i < chieurongconsole; i++) {
		gotoXY(i,0);
	    cout << ngang;
		gotoXY(i, chieucaoconsole);
		cout << ngang;
    }
    for (int i = 0; i < chieucaoconsole; i++) {
		gotoXY(0,i);
		cout << doc;
		gotoXY(chieurongconsole, i);
		cout << doc;
    }
	for (int i = 1; i <= chieucaoconsole-1; i++) {
		gotoXY(30, i);
		cout << doc;
	}
	char a = 201;
	gotoXY(0, 0);
	cout << a;
	a = 200;
	gotoXY(0, chieucaoconsole);
	cout << a;
	a = 187;
	gotoXY(chieurongconsole, 0);
	cout << a;
	a = 188;
	gotoXY(chieurongconsole, chieucaoconsole);
	cout << a;
	gotoXY(1, 1);
}