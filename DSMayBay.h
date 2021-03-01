#pragma once
#ifndef _DSMayBay
#define _DSMayBay
#include "All.h"
#include "MayBay.h"

class DSChuyenBay; 
class DSMayBay
{
public:
	DSMayBay();
	void Datain();
	void InDS();
	void ThemMB();
	void Dataout();
	int GetSoLuongMB();
	bool TrungsohieuMB(MayBay *mb);
	int TimMB(char SoHieu[]);
	void XoaMB(DSChuyenBay *cb);
	bool CoSoHieuMB(char sohieu[]);
	MayBay* Getmaybay(char SoHieu[]);
	bool MayBayDaTaoChuyenBay(char sohieu[], DSChuyenBay *cb); 
	void HieuChinhMB(DSChuyenBay* cb);
	bool CotheXoaMB(DSChuyenBay* cb);
private:
	int SoLuongMB;
	MayBay* maybay[SLMB_Max];
};


#endif // !_DSMayBay

