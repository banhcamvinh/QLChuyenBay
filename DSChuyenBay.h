#pragma once
#ifndef _DSChuyenBay
#define _DSChuyenBay
#include "All.h"
#include "ChuyenBay.h" 
#include "DSHanhKhach.h"

class DSChuyenBay
{
public:
	void KhoitaoDSChuyenBay();
	void ThemChuyenBay();
	void InDSChuyenBay();
	bool Larong();
	void Dataout();
	void Datain();
	bool TrungMaCB(ChuyenBay *chuyenbay); 
	bool TrungThoigianCB(ChuyenBay *chuyenbay);
	void HieuChinhNgayGio();
	ChuyenBay* TimChuyenBay(char Sohieu[]);
	bool CoChuyenBay(char Sohieu[]);
	void HuyChuyenBay();
	void HuyTatcaChuyenBay();
	void XoaDSChuyenBay();
	char* ChonChuyenBay();
	void SapxepDSCB();
	char* ChonDiemDen();
	bool HanhKhachDaMuaVe(ThoiGian tgian,HanhKhach* hanhkhach);
	void Datve();
	void Huyve();
	char* ChonChuyenBayHuyVe(char CMND[]);
	void InDS_motchuyenbay();
	void InDS_ngay_x_conve();
private:
	int Soluongchuyenbay;
	ChuyenBay* chuyenbaydau; //ví duj ở 
};


#endif // !_DSChuyenBay

