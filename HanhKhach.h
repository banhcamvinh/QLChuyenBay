#pragma once
#ifndef _HanhKhach
#define _HanhKhach
#define size_ho 10
#define size_ten 30
#include "All.h"
enum Phai{nam,nu};
class HanhKhach
{
public:
	HanhKhach();
	void NhapCMND();
	void NhapHo();
	void NhapTen();
	void NhapHoTen();
	void NhapPhai();
	HanhKhach* & GetHanhkhachtrai();
	HanhKhach* & GetHanhkhachphai();
	char* GetCMND();
	char* GetHo();
	char* GetTen();
	Phai GetPhai();
	void In1HK();
	void SetCMND(char cmnd[]);
	void SetHo(char ho[]);
	void SetTen(char ten[]);
	void SetPhai(Phai phai);
	void SetHanhkhachtrai(HanhKhach* hanhkhach);
	void SetHanhkhachphai(HanhKhach* hanhkhach);
private:
	char CMND[sizeCMND_max];//moi nguoi chi mot
	char Ho[size_ho];
	char Ten[size_ten];
	Phai phai;
	HanhKhach* hanhkhachtrai;
	HanhKhach* hanhkhachphai;
};


#endif // !_HanhKhach

