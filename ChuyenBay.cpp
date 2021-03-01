#include "ChuyenBay.h"
ChuyenBay::ChuyenBay() {
	strcpy(MaCB, "");
	strcpy(SanBayDen, "");
	strcpy(SoHieuMB, "");
	thoigian.SetNgay(1,1,1);
	thoigian.SetGio(0, 0);
	dsve = DSVe(0);
	trangthai = con_ve;
	chuyenbayke = NULL;
}
void ChuyenBay::NhapMaCB() {
	gotoXY(50, 20);
	cout << "Nhap ma CB: ";
	gotoXY(70, 20);
	Nhap_loc(MaCB, sizema_max);
	while (Kiemtrarong(MaCB))
	{
		gotoXY(50, 21); cout << "                                               ";
		gotoXY(50, 21); TextColor(12); cout << "Khong duoc de trong moi ban nhap lai! "; 
		TextColor(15);
		gotoXY(70, 20); cout << "                                 ";
		gotoXY(70, 20);
		Nhap_loc(MaCB,sizema_max);
	}
	Xoakhoangtrang(MaCB);
	Upcase(MaCB);
}
void ChuyenBay::NhapSBD() {
	gotoXY(50, 23);
	cout << "Nhap san bay den: ";
	gotoXY(70, 23);
	Nhap_loc(SanBayDen, size_diemden);
	while (Kiemtrarong(SanBayDen))
	{
		gotoXY(50, 24); cout << "                                                        ";
		gotoXY(50, 24); TextColor(12); 
		cout << "Khong duoc de trong moi ban nhap lai! "; 
		TextColor(15);
		gotoXY(70, 23); cout << "                                 ";
		gotoXY(70, 23);
		Nhap_loc(SanBayDen, size_diemden);
	}
	Xoakhoangtrang(SanBayDen);
	Upcase(SanBayDen);
}
void ChuyenBay::NhapSoHieuMB() {
	gotoXY(50, 26);
	cout << "Nhap so hieu MB: ";
	gotoXY(70, 26);
	Nhap_loc(SoHieuMB,sizesohieu_max);
	while (Kiemtrarong(SoHieuMB)) {
		gotoXY(50, 27); cout << "                                              ";
		gotoXY(50, 27); TextColor(12); 
		cout << "Khong duoc de trong moi ban nhap lai! "; 
		TextColor(15);
		gotoXY(70, 26); cout << "                                 ";
		gotoXY(70, 26);
		Nhap_loc(SoHieuMB, sizesohieu_max);
	}
	Xoakhoangtrang(SoHieuMB);
	Upcase(SoHieuMB);
}
void ChuyenBay::NhapThoigian() {
	thoigian.NhapNgayGioKH();
}
ChuyenBay* ChuyenBay::GetChuyenBayKe() {
	return chuyenbayke;
}
void ChuyenBay::SetChuyenBayKe(ChuyenBay* chuyenbay) {
	chuyenbayke = chuyenbay;
}
void ChuyenBay::InChuyenBay() {
	cout << "Ma chuyen bay: " << MaCB << endl;
	cout << "San bay den: " << SanBayDen << endl;
	cout << "So hieu MB: " << SoHieuMB << endl;
	cout << "Thoi Gian Chuyen Bay" << endl;
	thoigian.InNgayGioKH();
	cout << "Trang thai: ";
	if (trangthai == 1)cout << "Con ve" << endl;
	else if (trangthai == 0)cout << "Huy chuyen" << endl;
	else if (trangthai == 2)cout << "Het ve" << endl;
	else if (trangthai == 3)cout << "Hoan tat" << endl;
	cout << "Danh sach ve:" << endl;
	for (int i = 1; i <= dsve.GetSoluongve(); i++) {
		cout << "Ve " << i << " :" << dsve.GetdsVe()[i]<< endl;
	}
}
char* ChuyenBay::GetMaCB() {
	return MaCB;
}
char* ChuyenBay::GetSanBayDen() {
	return SanBayDen;
}
ThoiGian ChuyenBay::GetThoiGian() {
	return thoigian;
}
char* ChuyenBay::GetSoHieuMB() {
	return SoHieuMB;
}
TrangThai ChuyenBay::GetTrangThai() {
	return trangthai;
}
DSVe ChuyenBay::GetVe() {
	return dsve;
}
void ChuyenBay::SetMaCB(char macb[]) {
	strcpy(MaCB, macb);
}
void ChuyenBay::SetSanBayDen(char sanbay[]) {
	strcpy(SanBayDen, sanbay);
}
void ChuyenBay::SetThoiGian(ThoiGian tgian) {
	thoigian.SetGio(tgian.GetGio().GetGio(),tgian.GetGio().GetPhut());
	thoigian.SetNgay(tgian.GetNgay().GetNgay(), tgian.GetNgay().GetThang(), tgian.GetNgay().GetNam());
}
void ChuyenBay::SetTrangThai(TrangThai tt) {
	trangthai = tt;
}
void ChuyenBay::SetSoHieuMB(char sohieu[]) {
	strcpy(SoHieuMB, sohieu);
}
void ChuyenBay::SetDsve(int i, string a) {
	dsve.Setve(i, a);
}
void ChuyenBay::SetVe(int soluong) {
	dsve.SetSoluongVe(soluong);
}
void ChuyenBay::SetDSVe(int sl, string* v) {
	dsve.SetDSVE(sl, v);
}
void ChuyenBay::CopyInfo(ChuyenBay *a) {
	this->SetMaCB(a->GetMaCB());
	this->SetSoHieuMB(a->GetSoHieuMB());
	this->SetSanBayDen(a->GetSanBayDen());
	this->SetThoiGian(a->GetThoiGian());
	this->SetTrangThai(a->GetTrangThai());
	this->SetDSVe(a->GetVe().GetSoluongve(), a->GetVe().GetdsVe());
}

void ChuyenBay::Inthongtindiemden(int vitriy) {
	gotoXY(45, vitriy);
	cout << setw(20) << "Diem den";
	cout << setw(30) << SanBayDen;
	cout << setw(10) << "";
}
void ChuyenBay::InThongtinCBdedatve(int vitriy) {
	gotoXY(20, vitriy);
	cout <<setw(20)<< MaCB;
	cout << setw(15)<< SoHieuMB;
	cout << setw(30)<<SanBayDen;
	cout << setw(20); thoigian.InNgayGioKH();
}
