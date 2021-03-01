#include "HanhKhach.h"
HanhKhach::HanhKhach() {
	strcpy(CMND, "");
	strcpy(Ho, "");
	strcpy(Ten, "");
	phai = nam;
	hanhkhachtrai = hanhkhachtrai = NULL;
}
void HanhKhach::NhapCMND() {
	gotoXY(50, 20);
	cout << "Nhap CMND: ";
	gotoXY(70, 20);
	Nhapso(CMND, sizeCMND_max);
}
void HanhKhach::NhapHo(){
	do
	{
		gotoXY(50, 23);
		cout << "Nhap Ho: ";
		Nhap_chu(Ho, sizeho_max);
		if (Kiemtrarong(Ho)) {
			gotoXY(50, 24); cout << "                                           ";
			gotoXY(50, 24); TextColor(12);
			cout << "Khong duoc de trong!! Nhap lai"; TextColor(15);
		}
	} while (Kiemtrarong(Ho));
		Xoakhoangtrang(Ho);
		Upcasedau(Ho);
}
void HanhKhach::NhapTen() {
	do
	{
		gotoXY(50, 26);
		cout << "Nhap Ten: ";
		Nhap_chu(Ten, sizeten_max);
		if (Kiemtrarong(Ten)) { 
			gotoXY(50, 27); cout << "                                           ";
			gotoXY(50, 27); TextColor(12);
			cout << "Khong duoc de trong!! Nhap lai"; TextColor(15);
		}
	} while (Kiemtrarong(Ten));
	Xoakhoangtrang(Ten);
	Upcasedau(Ten);
}
void HanhKhach::NhapHoTen() {
	NhapHo();
	gotoXY(50, 24); cout << "                                      ";
	gotoXY(50, 24); TextColor(10); cout << "ok"; TextColor(15);
	NhapTen();
	gotoXY(50, 27); cout << "                                      ";
	gotoXY(50, 27); TextColor(10); cout << "ok"; TextColor(15);
}
void HanhKhach::NhapPhai() {
	gotoXY(50, 29);
	cout << "Phai: 1-Nam        2-Nu" << endl;
	char key;
	while (1) {
		key = _getch();
		if (key == 49) {
			phai = nam;
			break;
		}
		else if (key == 50) {
			phai = nu;
			break;
		}
	}
}
HanhKhach* & HanhKhach::GetHanhkhachphai() {
	return hanhkhachphai;
}
HanhKhach* & HanhKhach::GetHanhkhachtrai() {
	return hanhkhachtrai;
}
char* HanhKhach::GetCMND() {
	return CMND;
}
void HanhKhach::In1HK() {
	gotoXY(50, 20); cout << "CMND: ";
	gotoXY(70, 20); cout << CMND;
	gotoXY(50, 23); cout << "Ho: ";
	gotoXY(70, 23); cout << Ho;
	gotoXY(50, 26); cout << "Ten: ";
	gotoXY(70, 26); cout << Ten;
	gotoXY(50, 29); cout << "Phai: ";
	gotoXY(70, 29);
	if (phai == 0)cout <<"Nam" << endl;
	else if (phai == 1)cout << "Nu" << endl;
}
void HanhKhach::SetCMND(char cmnd[]) {
	strcpy(CMND, cmnd);
}
void HanhKhach::SetHanhkhachtrai(HanhKhach* hanhkhach) {
	hanhkhachtrai = hanhkhach;
}
void HanhKhach::SetHanhkhachphai(HanhKhach* hanhkhach) {
	hanhkhachphai = hanhkhach;
}
void HanhKhach::SetHo(char ho[]) {
	strcpy(Ho, ho);
}
void HanhKhach::SetTen(char ten[]) {
	strcpy(Ten, ten);
}
void HanhKhach::SetPhai(Phai p) {
	phai = p;
}
char* HanhKhach::GetHo() {
	return Ho;
}
char* HanhKhach::GetTen() {
	return Ten;
}
Phai HanhKhach::GetPhai() {
	return phai;
}
