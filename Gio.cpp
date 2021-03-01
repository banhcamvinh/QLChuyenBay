#include "Gio.h"
void Gio::NhapGio() {
	gotoXY(50, 31); cout << "Nhap gio: ";
	gotoXY(60, 31);
	Nhapso(gio, 3);
	while (gio < 0 || gio>=24) {
		gotoXY(50, 32); cout << "                                                  ";
		gotoXY(50, 32); 
		TextColor(12); 
		cout << "Nhap gio sai! Nhap lai: "; 
		TextColor(15);
		gotoXY(60, 31); cout << "                             ";
		gotoXY(60, 31);
		Nhapso(gio, 3);
	}
}
void Gio::NhapPhut() {
	gotoXY(70, 31); 
	cout << "Nhap phut: ";
	gotoXY(80, 31);
	Nhapso(phut, 3);
	while (phut < 0 || phut>=60) {
		gotoXY(50, 32); cout << "                                               ";
		gotoXY(50, 32); 
		TextColor(12); 
		cout << "Nhap phut sai! Nhap lai: "; 
		TextColor(15);
		gotoXY(80, 31); cout << "                      ";
		gotoXY(80, 31);
		Nhapso(phut, 3);
	}
}
void Gio::NhapGioPhut() {
	NhapGio();
	gotoXY(50, 32); cout << "                                                        ";
	NhapPhut();
}
void Gio::SetGio(int gio){
	this->gio = gio;
}
void Gio::SetPhut(int phut) {
	this->phut = phut;
}
void Gio::SetGioPhut(int gio, int phut) {
	SetGio(gio);
	SetPhut(phut);

}
int Gio::SosanhGioPhut(Gio a) {
	if (gio < a.gio)return -1;
	else if (gio > a.gio)return 1;
	else if (gio == a.gio) {
		if (phut < a.phut)return -1;
		else if (phut > a.phut)return 1;
		else if (phut == a.phut)return 0;
	}
}
void Gio::InGioPhut() {
	cout << gio << " gio " << phut << " phut";
}
int Gio::GetGio() {
	return gio;
}
int Gio::GetPhut() {
	return phut;
}
