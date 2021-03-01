#pragma once
#ifndef _Gio
#define _Gio
#include "All.h"
class Gio
{
public:
	void NhapGio();
	void NhapPhut();
	void NhapGioPhut();
	void SetGio(int gio);
	void SetPhut(int phut);
	void SetGioPhut(int gio, int phut);
	int SosanhGioPhut(Gio a);
	void InGioPhut();
	int GetGio();
	int GetPhut();
private:
	int gio;
	int phut;
};


#endif // !_Gio

