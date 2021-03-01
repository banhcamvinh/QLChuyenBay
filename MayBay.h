#pragma once
#ifndef _MayBay
#define _MayBay
#include "All.h"

class MayBay
{
public:
	MayBay();
	void NhapSoHieuMB();
	void NhapLoaiMB();
	void NhapSocho();
	void SetSoHieuMB(char string[]);
	void SetLoaiMB(char string[]);
	void SetSocho(int num);
	void InSoHieuMB();
	void InSocho();
	void InLoaiMB();
	void InMB();
	char* GetSoHieuMB();
	char* GetLoaiMB();
	int GetSocho();
private:
	char SoHieuMB[sizesohieu_max]; //So hieu MB la duy nhat //Khoa
	char LoaiMB[sizeloai_max];
	int Socho; //so cho 
};

#endif // !_MayBay

