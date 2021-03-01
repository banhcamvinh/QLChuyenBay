#pragma once
#ifndef _Ngay
#define _Ngay
#include "All.h"

class Ngay
{
public:
	void NhapNgay();
	void NhapThang();
	void NhapNam();
	void NhapNgayThangNam();
	int GetNgay();
	int GetThang();
	int GetNam();
	void SetNgay(int ngay);
	void SetThang(int thang);
	void SetNam(int nam);
	bool CheckNgayThangNam();
	void SetNgayThangNam(int ngay, int thang, int nam);
	int SoSanhNgayThangNam(Ngay ngay);
	void InNgayThangNam();
private:
	int day;
	int month;
	int year;
};


#endif // !_Ngay

