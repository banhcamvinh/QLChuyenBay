#include "DSHanhKhach.h"
void DSHanhKhach::KhoitaoDSHanhKhach() {
	hanhkhachgoc = NULL;
	Soluonghanhkhach = 0;
}
HanhKhach* DSHanhKhach::Cohanhkhach(HanhKhach* hanhkhach) {
	HanhKhach *tam = hanhkhachgoc;
	while (tam != NULL && Convert_num(tam->GetCMND())!=Convert_num(hanhkhach->GetCMND())) {
		if (Convert_num(hanhkhach->GetCMND()) < Convert_num(tam->GetCMND()))
			tam = tam->GetHanhkhachtrai();
		else tam = tam->GetHanhkhachphai();
	}
	return tam;
}
HanhKhach* DSHanhKhach::Cohanhkhach(char CMND[]) {
	HanhKhach *tam = hanhkhachgoc;
	while (tam != NULL && Convert_num(tam->GetCMND()) != Convert_num(CMND)) {
		if (Convert_num(CMND) < Convert_num(tam->GetCMND()))
			tam = tam->GetHanhkhachtrai();
		else tam = tam->GetHanhkhachphai();
	}
	return tam;
}
void DSHanhKhach::InsertHK(HanhKhach* &hkroot, char CMND[], char ho[], char ten[], Phai phai) {
	if (hkroot == NULL) {
		hkroot = new HanhKhach;
		hkroot->SetCMND(CMND);
		hkroot->SetHo(ho);
		hkroot->SetTen(ten);
		hkroot->SetPhai(phai);
		hkroot->SetHanhkhachtrai(NULL);
		hkroot->SetHanhkhachphai(NULL);
	}
	else {		
		if (Convert_num(CMND) < Convert_num(hkroot->GetCMND()))
			InsertHK(hkroot->GetHanhkhachtrai(), CMND, ho, ten, phai);
		else if(Convert_num(CMND) > Convert_num(hkroot->GetCMND()))
			InsertHK(hkroot->GetHanhkhachphai(), CMND, ho, ten, phai);
	}
}

HanhKhach* DSHanhKhach::Themhanhkhach() {
		HanhKhach* hanhkhachmoi = new HanhKhach();
		VeKhungXoaMB();
		hanhkhachmoi->NhapCMND();
		char CMNDtam[sizeCMND_max];
		strcpy(CMNDtam, hanhkhachmoi->GetCMND());
		hanhkhachmoi = Cohanhkhach(hanhkhachmoi);
		if (hanhkhachmoi != NULL) {
			gotoXY(0, 0);
			VeKhungThemHK();
			gotoXY(50, 32); TextColor(10);
			cout << "Thong tin hanh khach da co"; TextColor(15);
			gotoXY(50, 20); cout << "             ";
			hanhkhachmoi->In1HK();
			gotoXY(50, 34); TextColor(12);
			cout << "An phim bat ki de tiep tuc dat ve"; TextColor(15);
			_getch();
		}
		else {
			delete hanhkhachmoi;
			hanhkhachmoi = new HanhKhach;
			gotoXY(0, 0);
			VeKhungThemHK();
			gotoXY(50, 32); TextColor(10);
			cout << "Day la KH moi. Nhap thong tin!!"; TextColor(15);
			hanhkhachmoi->SetCMND(CMNDtam);
			gotoXY(50, 21); cout << "                                      ";
			gotoXY(50, 21); TextColor(10); cout << "ok"; TextColor(15);
			hanhkhachmoi->NhapHoTen();
			hanhkhachmoi->NhapPhai();
			gotoXY(50, 30); cout << "                                      ";
			gotoXY(50, 30); TextColor(10); cout << "ok"; TextColor(15);
			InsertHK(hanhkhachgoc, hanhkhachmoi->GetCMND(), hanhkhachmoi->GetHo(), hanhkhachmoi->GetTen(), hanhkhachmoi->GetPhai());
			Soluonghanhkhach++;
			gotoXY(50, 34); TextColor(12);
			cout << "An phim bat ki de tiep tuc dat ve"; TextColor(15);
			_getch();
		}
		return hanhkhachmoi;
}
void DSHanhKhach::Dataout() {
	fstream filehanhkhach;
	filehanhkhach.open("dshanhkhach.txt",ios::out);
	if (Soluonghanhkhach != 0) {
		Xuatfile(hanhkhachgoc, filehanhkhach);
	}
	cout << "Saved" << endl;
	filehanhkhach.close();
	cout << "An phim bat ki de thoat" << endl;
	_getch();
}
void DSHanhKhach::Datain() {
	Soluonghanhkhach = 0;
	fstream filehanhkhach;
	filehanhkhach.open("dshanhkhach.txt", ios::in);
	if (filehanhkhach.is_open()) {
		char CMNDtam[sizeCMND_max];
		char hotam[sizeho_max];
		char tentam[sizeten_max];
		int phaitam; Phai p;
		if (Filerong(filehanhkhach));
		else {
			HanhKhach* tam = new HanhKhach();
			while (filehanhkhach.getline(CMNDtam, sizeCMND_max)) {
				filehanhkhach.getline(hotam, sizeho_max);
				filehanhkhach.getline(tentam, sizeten_max);
				filehanhkhach >> phaitam;
				filehanhkhach.ignore();
				if (phaitam == 0)p = nam;
				else if (phaitam == 1)p = nu;
				InsertHK(hanhkhachgoc, CMNDtam, hotam, tentam, p);
				tam = new HanhKhach;
				Soluonghanhkhach++;
			}
		}
	}
}
void DSHanhKhach::LNR(HanhKhach* root) {
	if (root != NULL)
	{
		LNR(root->GetHanhkhachtrai());
		root->In1HK();
		LNR(root->GetHanhkhachphai());
	}
}
void DSHanhKhach::InDSKH() {
	if (hanhkhachgoc == NULL)cout << "Danh sach rong" << endl;
	else LNR(hanhkhachgoc);
}
void DSHanhKhach::Xuatfile(HanhKhach* root,fstream &file) {
	if (root != NULL)
	{
		Xuatfile(root->GetHanhkhachtrai(),file);
		file << root->GetCMND() << endl;
		file << root->GetHo() << endl;
		file << root->GetTen() << endl;
		file << root->GetPhai() << endl;
		Xuatfile(root->GetHanhkhachphai(),file);
	}
}
