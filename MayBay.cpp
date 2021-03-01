#include "MayBay.h"
MayBay::MayBay() {
	strcpy(this->SoHieuMB, "");
	strcpy(this->LoaiMB, "");
	this->Socho = 0;
}
void MayBay::NhapSoHieuMB() {
	gotoXY(50, 20);
	cout << "Nhap so hieu MB: ";
	gotoXY(70, 20);
	Nhap_loc(SoHieuMB, sizesohieu_max);
	while (Kiemtrarong(SoHieuMB))
	{	
		gotoXY(50, 21);
		TextColor(12);
		cout << "Khong duoc de trong moi ban nhap lai!!";
		TextColor(15);
		gotoXY(70, 20);
		Nhap_loc(SoHieuMB, sizesohieu_max);
	}
	Xoakhoangtrang(SoHieuMB);
	Upcase(SoHieuMB);
}
void MayBay::NhapSocho() {
	gotoXY(50, 26);
	cout << "Nhap So cho: ";
	gotoXY(70, 26);
	Nhapso(Socho, sokitucho);
	while (Socho < sochotoithieu) {
		gotoXY(50, 27);
		TextColor(12);
		cout << "So cho phai >=20!! Moi ban nhap lai!: ";
		gotoXY(70, 26);
		TextColor(15);
		cout << "              ";
		gotoXY(70, 26);
		Nhapso(Socho, sokitucho);
	}
}
void MayBay::NhapLoaiMB() {
	gotoXY(50, 23);
	cout << "Nhap loai MB: ";
	gotoXY(70, 23);
	Nhap_loc(LoaiMB, sizeloai_max);
	while (Kiemtrarong(LoaiMB)) {
		gotoXY(50, 24);
		TextColor(12);
		cout << "Khong dc de trong moi ban nhap lai: ";
		gotoXY(70, 23);
		TextColor(15);
		Nhap_loc(LoaiMB, sizeloai_max);
	}
	Xoakhoangtrang(LoaiMB);
	Upcase(LoaiMB);
}
void MayBay::InSoHieuMB() {
	cout << "So hieu: " << SoHieuMB << endl;
}
void MayBay::InSocho() {
	cout << "So cho: " << Socho << endl;
}
void MayBay::InLoaiMB() {
	cout << "Loai MB: " << LoaiMB << endl;
}
void MayBay::InMB() {
	this->InSoHieuMB();
	this->InLoaiMB();
	this->InSocho();
}
void MayBay::SetSoHieuMB(char string[]) {
	strcpy(SoHieuMB, string);
}
void MayBay::SetSocho(int num) {
	Socho = num;
}
void MayBay::SetLoaiMB(char string[]) {
	strcpy(LoaiMB, string);
}
char* MayBay::GetSoHieuMB() {
	return SoHieuMB;
}
char* MayBay::GetLoaiMB() {
	return LoaiMB;
}
int MayBay::GetSocho() {
	return Socho;
}
