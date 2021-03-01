#pragma once
#ifndef _ChuyenBay
#define _ChuyenBay
#include "All.h"
#include "ThoiGian.h"
#include "DSMayBay.h" 
#include "DSVe.h"

class ChuyenBay
{
public:
	void NhapMaCB();
	void NhapSBD();
	void NhapSoHieuMB();
	void NhapThoigian();
	ChuyenBay();
    void TaoChuyenBay();
	ChuyenBay* GetChuyenBayKe();
	void SetChuyenBayKe(ChuyenBay* chuyenbay);
	void InChuyenBay();
	char* GetMaCB();
	char* GetSanBayDen();
	ThoiGian GetThoiGian();
	char* GetSoHieuMB();
	TrangThai GetTrangThai();
	DSVe GetVe();
	void SetMaCB(char macb[]);
	void SetSanBayDen(char sanbayden[]);
	void SetThoiGian(ThoiGian thoigian);
	void SetTrangThai(TrangThai trangthai);
	void SetSoHieuMB(char sohieu[]);
	void SetDsve(int i,string a);
	void SetVe(int soluong);
	void SetChuyenbayke(ChuyenBay* chuyenke);
	void SetDSVe(int sl, string* v);
	void Inthongtindiemden(int vitriy);
	void InThongtinCBdedatve(int vitriy);
	void CopyInfo(ChuyenBay *a);
private:
	char MaCB[sizema_max];
	char SanBayDen[size_diemden];
	ThoiGian thoigian;
	TrangThai trangthai;
	char SoHieuMB[sizesohieu_max];
	DSVe dsve;
	ChuyenBay* chuyenbayke;
};


#endif // !_ChuyenBay
