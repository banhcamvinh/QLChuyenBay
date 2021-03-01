#include "ThoiGian.h"
void ThoiGian::NhapNgayGioKH() {
	Ngay ngayreal;
	_ngay.NhapNgayThangNam();
	ngayreal.SetNgayThangNam(Realday(), Realmonth(), Realyear());
	while (_ngay.SoSanhNgayThangNam(ngayreal) == -1) {
		gotoXY(50, 30); cout << "                                                   ";
		gotoXY(50, 30); TextColor(12); cout << "Thoi gian phai lon hon thoi gian hien tai!"; TextColor(15);
		gotoXY(50, 29); cout << "                                                              ";
		gotoXY(50, 29);
		_ngay.NhapNgayThangNam();
		ngayreal.SetNgayThangNam(Realday(), Realmonth(), Realyear());
	}
	gotoXY(50, 30); cout << "                                                       ";
	gotoXY(50, 30); TextColor(10); cout << "OK!"; TextColor(15);
	if (_ngay.SoSanhNgayThangNam(ngayreal) == 0) {
		_gio.NhapGioPhut();
		Gio gioreal;
		gioreal.SetGioPhut(Realhour(), Realmin());
		while (_gio.SosanhGioPhut(gioreal) == -1||_gio.SosanhGioPhut(gioreal)==0) {
			gotoXY(50, 32); cout << "                                                                      ";
			gotoXY(50, 32); TextColor(12); cout << "Thoi gian phai lon hon thoi gian hien tai! Nhap lai: "; TextColor(15);
			gotoXY(50, 31); cout << "                                                         ";
			_gio.NhapGioPhut();
			gioreal.SetGioPhut(Realhour(), Realmin());
		}
	}
	else {
		_gio.NhapGioPhut();
	}
	gotoXY(50, 32); cout << "                                                ";
	gotoXY(50, 32); TextColor(10); cout << "OK: "; TextColor(15);
}
void ThoiGian::InNgayGioKH() {
	_ngay.InNgayThangNam();
	_gio.InGioPhut();
}
Ngay ThoiGian::GetNgay() {
	return _ngay;
}
Gio ThoiGian::GetGio() {
	return _gio;
}
void ThoiGian::SetNgay(int ngay,int thang,int nam) {
	_ngay.SetNgayThangNam(ngay, thang, nam);
}
void ThoiGian::SetGio(int gio, int phut) {
	_gio.SetGioPhut(gio, phut);
}
