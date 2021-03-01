#include "Ngay.h"
int Ngay::GetNgay() {
	return day;
}
int Ngay::GetThang() {
	return month;
}
int Ngay::GetNam() {
	return year;
}
void Ngay::NhapNgay() {
	gotoXY(50, 29);
	cout << "Nhap ngay: ";
	Nhapso(day, 3);
}
void Ngay::NhapThang() {
	gotoXY(70, 29);
	cout << "thang: ";
	Nhapso(month, 3);
}
void Ngay::NhapNam() {
	gotoXY(90, 29);
	cout << "nam: ";
	Nhapso(year, 5);
}
bool Ngay::CheckNgayThangNam() {
	int Ngay_trong_thang[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month <= 0 || month > 12 || year < 1)return 0;
	else {
		if (LaNamNhuan(year))
			Ngay_trong_thang[2] = 29;
		if (day > Ngay_trong_thang[month] || day <= 0)
			return 0;
	}
	return true;
}
void Ngay::NhapNgayThangNam() {
	NhapNgay();
	NhapThang();
	NhapNam();
	while (!this->CheckNgayThangNam()) {
		gotoXY(50, 30); cout << "                                           ";
		gotoXY(50, 30); TextColor(12); cout << "Ngay thang nam khong dung!"; TextColor(15);
		gotoXY(50, 29); cout << "                                                              ";
		gotoXY(50, 29);
		NhapNgay();
		NhapThang();
		NhapNam();
	}
}
int Ngay::SoSanhNgayThangNam(Ngay ngay) {
	if (this->year < ngay.year)return -1;
	else if (this->year > ngay.year)return 1;
	else if (this->year == ngay.year) {
		if (this->month < ngay.month)return -1;
		else if (this->month > ngay.month)return 1;
		else if (this->month == ngay.month) {
			if (this->day < ngay.day)return -1;
			else if(this->day > ngay.day)return 1;
			else if (this->day == ngay.day)return 0;
		}
	}
}
void Ngay::SetNgay(int ngay){
	this->day = ngay;
}
void Ngay::SetThang(int thang){
	this->month = thang;
}
void Ngay::SetNam(int nam){
	this->year = nam;
}
void Ngay::SetNgayThangNam(int ngay, int thang, int nam) {
	this->SetNgay(ngay);
	this->SetThang(thang);
	this->SetNam(nam);
}
void Ngay::InNgayThangNam() {
	cout << day << "/" << month << "/" << year << " ";
}