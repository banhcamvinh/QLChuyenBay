#pragma once
#ifndef _ThoiGian
#define _ThoiGian
#include "All.h"
#include "Ngay.h"
#include "Gio.h"
using namespace std;

class ThoiGian
{
public:
	void NhapNgayGioKH();
	void InNgayGioKH();
	Ngay GetNgay();
	Gio GetGio();
	void SetNgay(int ngay,int thang,int nam);
	void SetGio(int gio,int phut);
private:
	Ngay _ngay;
	Gio _gio;
};
#endif // !_ThoiGian

