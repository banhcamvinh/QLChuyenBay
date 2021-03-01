#pragma once
#ifndef _DSHanhKhach
#define _DSHanhKhach
#include "HanhKhach.h"
typedef HanhKhach* HKPTR;
class DSHanhKhach
{
public:
	void KhoitaoDSHanhKhach();
	HanhKhach* Themhanhkhach();
	HanhKhach* Cohanhkhach(HanhKhach* hanhkhach);
	HanhKhach* Cohanhkhach(char CMND[]);
	void InsertHK(HKPTR &hkroot, char CMND[], char ho[], char ten[], Phai phai);
	void Dataout();
	void InDSKH();
	void LNR(HanhKhach* root);
	void Xuatfile(HanhKhach* root,fstream &file);
	void Datain();
	/*void DatVe();*/
private:
	int Soluonghanhkhach;
	HanhKhach* hanhkhachgoc; //cay tim kiem nhi phan
};


#endif // !_DSHanhKhach

