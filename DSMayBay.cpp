#include "DSMayBay.h"
#include "DSChuyenBay.h"

DSMayBay::DSMayBay() {
	SoLuongMB = 0;
}
bool DSMayBay::TrungsohieuMB(MayBay *mb) {
	for (int i = 0; i < SoLuongMB; i++) {
		if (strcmp(mb->GetSoHieuMB(), maybay[i]->GetSoHieuMB()) == 0)
			return true;
	}
	return false;
}
int DSMayBay::GetSoLuongMB() {
	return SoLuongMB;
}
void DSMayBay::Datain() {
	SoLuongMB = 0;
	fstream filemaybay;
	filemaybay.open("dsmaybay.txt", ios::in);
	if (filemaybay.is_open()) {
		int i = 0;
		char sohieutam[sizesohieu_max];
		char loaitam[sizeloai_max];
		int sochotam;
		if (Filerong(filemaybay))return;
		else {
			maybay[i] = new MayBay;
			while (filemaybay.getline(sohieutam, sizesohieu_max)) {
				maybay[i]->SetSoHieuMB(sohieutam);
				filemaybay.getline(loaitam, sizeloai_max);
				maybay[i]->SetLoaiMB(loaitam);
				filemaybay >> sochotam;
				maybay[i]->SetSocho(sochotam);
				filemaybay.ignore();
				i++; SoLuongMB++;
				if (i != SLMB_Max)
					maybay[i] = new MayBay;
			}
		}
	}
	else cout << "Chua mo dc file" << endl;
	filemaybay.close();
}
void DSMayBay::InDS() {
	if (SoLuongMB == 0)cout << "Danh sach rong!" << endl;
	for (int i = 0; i < SoLuongMB; i++) {
		cout << "May bay thu " << i + 1 << ": " << endl;
		maybay[i]->InMB();
	}
}
void DSMayBay::Dataout() {
	fstream filemaybay;
	filemaybay.open("dsmaybay.txt", ios::out);
	if (SoLuongMB != 0) {
		for (int i = 0; i < SoLuongMB; i++) {
			filemaybay << maybay[i]->GetSoHieuMB() << endl;
			filemaybay << maybay[i]->GetLoaiMB() << endl;
			filemaybay << maybay[i]->GetSocho() << endl;
		}
	}
	cout << "Saved ";
	filemaybay.close();
	cout << "An phim bat ki de thoat";
	_getch();
}
void DSMayBay::ThemMB() {
	int vitri = SoLuongMB; char luachon = 13;
	while (SoLuongMB<SLMB_Max &&luachon==13) {
		clrscr();
		VeKhungThemMB();
		maybay[vitri] = new MayBay;
		maybay[vitri]->NhapSoHieuMB();
		while (TrungsohieuMB(maybay[vitri])) {
			clrscr();
			VeKhungThemMB();
			TextColor(12);
			gotoXY(50, 21);
			cout << "So hieu da co! moi ban nhap lai!";
			TextColor(15);
			maybay[vitri]->NhapSoHieuMB();
		}
		gotoXY(50, 21); cout << "                                       ";
		gotoXY(50, 21); TextColor(10); cout << "ok"; TextColor(15);
		maybay[vitri]->NhapLoaiMB();
		gotoXY(50, 24); cout << "                                    ";
		gotoXY(50, 24); TextColor(10); cout << "ok"; TextColor(15);
		maybay[vitri]->NhapSocho();
		gotoXY(50, 27); cout << "                                      ";
		gotoXY(50, 27); TextColor(10); cout << "ok";
		SoLuongMB++;
		vitri++;
		gotoXY(50, 29);
		cout << "An Esc de thoat- An Enter de tiep tuc them! ";
		while (1) {
			if (_kbhit()) {
				luachon = _getch();
				if (luachon == 27) {
					cout << endl; break;
				}
				else if (luachon == 13) {
					cout << endl; break;
				}
			}
		}
		 TextColor(15);
	}
	if (SoLuongMB == SLMB_Max) {
		clrscr();
		gotoXY(0, 0);
		VeKhungThemMB();
		gotoXY(50, 20);
		cout << "Danh sach day khong them dcc nua!!";
		gotoXY(50, 21);
		cout << "An phim bat ki de thoat";
		_getch();
	}
}
int DSMayBay::TimMB(char SoHieu[]) {
	for (int i = 0; i < SoLuongMB; i++) {
		if (strcmp(SoHieu, maybay[i]->GetSoHieuMB()) == 0) 
			return i;
	}
	return -1;
}
bool DSMayBay::MayBayDaTaoChuyenBay(char sohieu[], DSChuyenBay* cb) {
	cb->KhoitaoDSChuyenBay();
	cb->Datain();
	if (cb->CoChuyenBay(sohieu)) {
		cb->XoaDSChuyenBay();
		return true;
	}
	else {
		cb->XoaDSChuyenBay();
		return false;
	}
}
bool DSMayBay::CotheXoaMB(DSChuyenBay* cb) {
	int dem = 0;
	for (int i = 0; i < SoLuongMB; i++) {
		if (MayBayDaTaoChuyenBay(maybay[i]->GetSoHieuMB(), cb))
			dem++;
	}
	if (dem == SoLuongMB)return false;
	else return true;
}
void DSMayBay::XoaMB(DSChuyenBay* cb) {
	int luachon = 13;
	while(luachon==13&&SoLuongMB!=0&&CotheXoaMB(cb)){
		MayBay* tam = new MayBay;
		VeKhungXoaMB();
		do{
			do{
				tam->NhapSoHieuMB();
				if (TimMB(tam->GetSoHieuMB()) == -1) {
					gotoXY(50, 20); cout << "                                              ";
					gotoXY(50, 21); cout << "                                                 ";
					gotoXY(50, 21); TextColor(12);
					cout << "Khong tim thay May Bay! Nhap lai!" << endl;
					TextColor(15);
				}
			} while (TimMB(tam->GetSoHieuMB()) == -1);
			if (MayBayDaTaoChuyenBay(tam->GetSoHieuMB(), cb)) {
				gotoXY(50, 20); cout << "                                             ";
				gotoXY(50, 21); cout << "                                             ";
				gotoXY(50, 21); TextColor(12);
				cout << "May bay da tao chuyen bay ban khong the xoa!" << endl;
				TextColor(15);
			}
		} while (MayBayDaTaoChuyenBay(tam->GetSoHieuMB(), cb));
		gotoXY(50, 21); cout << "                                              ";
		gotoXY(50, 21); TextColor(10); cout << "ok"; TextColor(15);
		int i = TimMB(tam->GetSoHieuMB());
		MayBay* tmp = maybay[i];
		for (i; i < SoLuongMB - 1; i++) 
			maybay[i] = maybay[i + 1];
		SoLuongMB--;
		delete tmp; delete tam;
		gotoXY(50, 20); cout << "                                             ";
		gotoXY(50, 21); cout << "                                             ";
		gotoXY(50, 20); TextColor(10); cout << "Deleted";
		gotoXY(50, 21); TextColor(12); cout << "An Enter de tiep tuc xoa- Esc de thoat";
		TextColor(15);
		while (1) {
			char key = _getch();
			if (key == 13) {
				luachon = 13; break;
			}
			else if (key == 27) {
				luachon = 27; break;
			}
		}
		gotoXY(50, 21); cout << "                                             ";
		gotoXY(0, 0);
	}
	gotoXY(50, 20); cout << "                                             ";
	gotoXY(50, 20); TextColor(12);
	if(SoLuongMB==0) cout << "Danh sach may bay rong khong the xoa" << endl;
	else if (!CotheXoaMB(cb)) cout << "Khong con may bay co the xoa" << endl;
	TextColor(15);
}
bool DSMayBay::CoSoHieuMB(char sohieu[]) {
	for (int i = 0; i < SoLuongMB; i++) {
		if (strcmp(sohieu, maybay[i]->GetSoHieuMB()) == 0)
			return true;
	}
	return false;
}
MayBay* DSMayBay::Getmaybay(char SoHieu[]) {
	return maybay[TimMB(SoHieu)];
}
void DSMayBay::HieuChinhMB(DSChuyenBay* cb) {
	char key; int luachon = 13;
	MayBay* tam = new MayBay;
	while (luachon == 13 && SoLuongMB != 0 && CotheXoaMB(cb)) {
		clrscr();
		VeKhungXoaMB();
		do {
			do {
				tam->NhapSoHieuMB();
				if (TimMB(tam->GetSoHieuMB()) == -1) {
					gotoXY(50, 20); cout << "                                                          ";
					gotoXY(50, 21); cout << "                                                          ";
					gotoXY(50, 21); TextColor(12);
					cout << "Khong tim thay May Bay! Nhap lai!" << endl;
					TextColor(15);
				}
			} while (TimMB(tam->GetSoHieuMB()) == -1);
			if (MayBayDaTaoChuyenBay(tam->GetSoHieuMB(), cb)) {
				gotoXY(50, 20); cout << "                                             ";
				gotoXY(50, 21); cout << "                                             ";
				gotoXY(50, 21); TextColor(12);
				cout << "May bay da tao chuyen bay ban khong the hieu chinh!" << endl;
				TextColor(15);
			}
		} while (MayBayDaTaoChuyenBay(tam->GetSoHieuMB(), cb));
		gotoXY(50, 21); cout << "                                                     ";
		gotoXY(50, 21); TextColor(10); cout << "OK"; TextColor(15);
		int i = TimMB(tam->GetSoHieuMB());
		gotoXY(50, 23);
		cout << "Ban muon chinh sua?";
		gotoXY(50, 24);
		cout << "1-So Hieu";
		cout << "        2-Loai          ";
		cout << "3-So cho";
		gotoXY(50, 25);
		cout << "Moi ban chon bang cach an phim 1 2 3";
		while (1) {
			key = _getch();
			clrscr();
			VeKhungThemMB();
			if (key == 49) {
				gotoXY(50, 23); cout << "Loai MB: ";
				gotoXY(70, 23); cout << maybay[i]->GetLoaiMB();
				gotoXY(50, 26); cout << "So Cho: ";
				gotoXY(70, 26); cout << maybay[i]->GetSocho();
				int sochotam = 0; char loaitam[sizeloai_max] = "";
				MayBay *tam2 = new MayBay;
				tam2->SetLoaiMB(maybay[i]->GetLoaiMB());
				tam2->SetSocho(maybay[i]->GetSocho());
				gotoXY(50, 20); cout << "                                             ";
				tam2->NhapSoHieuMB();
				while (TrungsohieuMB(tam2)) {
					gotoXY(50, 21); cout << "                                             ";
					gotoXY(50, 21); TextColor(12); cout << "So hieu da co! moi ban nhap lai!";
					gotoXY(50, 20); cout << "                                             ";
					TextColor(15);
					tam2->NhapSoHieuMB();
				}
				gotoXY(50, 21); cout << "                                             ";
				gotoXY(50, 21); TextColor(10); cout << "OK";
				maybay[i] = tam2; break;
			}
			else if (key == 50) {
				gotoXY(50, 20); cout << "So Hieu MB: ";
				gotoXY(70, 20); cout << maybay[i]->GetSoHieuMB();
				gotoXY(50, 26); cout << "So Cho: ";
				gotoXY(70, 26); cout << maybay[i]->GetSocho();
				maybay[i]->NhapLoaiMB();
				gotoXY(50, 24); cout << "                                                  ";
				gotoXY(50, 24); TextColor(10); cout << "OK"; TextColor(15);
				break;
			}
			else if (key == 51) {
				gotoXY(50, 20); cout << "So Hieu MB: ";
				gotoXY(70, 20); cout << maybay[i]->GetSoHieuMB();
				gotoXY(50, 23); cout << "Loai MB: ";
				gotoXY(70, 23); cout << maybay[i]->GetLoaiMB();
				maybay[i]->NhapSocho();
				gotoXY(50, 27); cout << "                                                 ";
				gotoXY(50, 27); TextColor(10); cout << "OK"; TextColor(15);
				break;
			}
		}
		gotoXY(50, 29); TextColor(12);
		cout << "An Enter de tiep tuc hieu chinh- ESC de thoat"; TextColor(15);
		while (1) {
			key = _getch();
			if (key == 13) {
				luachon = 13; break;
			}
			else if (key == 27) {
				luachon = 27; break;
			}
		}
		gotoXY(0, 0);
	}
	if (SoLuongMB == 0) cout << "Danh sach may bay rong khong the hieu chinh" << endl;
	else if (!CotheXoaMB(cb)) cout << "Khong con may bay de hieu chinh" << endl;
}