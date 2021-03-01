#pragma once
#ifndef _Ve
#define _Ve
#include "All.h"
class DSVe
{
public:
	DSVe() { };
	DSVe(int soluong);
	int GetSoluongve();
	int Soluongvedamua();
	string* GetdsVe(); 
	void SetSoluongVe(int soluong);
	void Setve(int i,string a);
	void SetDSVE(int soluong, string* v);
	bool CoNguoiMuaVe(char CMND[]);
	void Huyve(char CMND[]);
private:
	int SoluongVe;
	string* ve;
};
#endif // !_Ve

