#include "DSChuyenBay.h"
void DSChuyenBay::KhoitaoDSChuyenBay()
{
	Soluongchuyenbay = 0;
	chuyenbaydau = NULL;
}
bool DSChuyenBay::Larong() {
	return (chuyenbaydau == NULL);
}
bool DSChuyenBay::TrungMaCB(ChuyenBay *chuyenbay) {
	ChuyenBay* tam = chuyenbaydau;
	if (Larong())return false;
	else {
		for(tam;tam!=NULL;tam=tam->GetChuyenBayKe()) {
			if (strcmp(tam->GetMaCB(), chuyenbay->GetMaCB()) == 0)
				return true;
		}
	}
	return false;
}
bool DSChuyenBay::TrungThoigianCB(ChuyenBay *chuyenbay) {
	ChuyenBay* tam = chuyenbaydau;
	if (Larong())return false;
	else {
		for (tam; tam != NULL; tam = tam->GetChuyenBayKe()) {
			if (tam->GetThoiGian().GetNgay().SoSanhNgayThangNam(chuyenbay->GetThoiGian().GetNgay()) == 0 
			&& tam->GetThoiGian().GetGio().SosanhGioPhut(chuyenbay->GetThoiGian().GetGio()) == 0
			&&(tam->GetTrangThai()!=hoan_tat||tam->GetTrangThai()!=huy_chuyen)
			&&tam!=chuyenbay)
				return true;
		}
	}
	return false;
}
void DSChuyenBay::ThemChuyenBay() {
	int luachon = 13;
	while (luachon == 13) {
		clrscr();
		VeKhungThemCB();
		ChuyenBay* chuyenbaymoi = new ChuyenBay();
		chuyenbaymoi->NhapMaCB();
		while (TrungMaCB(chuyenbaymoi)) {
			gotoXY(50, 21); cout << "                                         ";
			gotoXY(50, 21); TextColor(12); cout << "Ma CB da ton tai! Ban hay nhap lai!"; TextColor(15);
			gotoXY(70, 20); cout << "                                 ";
			gotoXY(70, 20);
			chuyenbaymoi->NhapMaCB();
		}
		gotoXY(50, 21); cout << "                                         ";
		gotoXY(50, 21); TextColor(10); cout << "OK!"; TextColor(15);
		chuyenbaymoi->NhapSBD();
		gotoXY(50, 24); cout << "                                         ";
		gotoXY(50, 24); TextColor(10); cout << "OK!"; TextColor(15);
		DSMayBay ds; 
		ds.Datain();
		chuyenbaymoi->NhapSoHieuMB();
		while (!ds.CoSoHieuMB(chuyenbaymoi->GetSoHieuMB())) {
			gotoXY(50, 27); cout << "                                         ";
			gotoXY(50, 27); TextColor(12); cout << "So hieu May Bay khong ton tai moi ban nhap lai"; TextColor(15);
			gotoXY(70, 26); cout << "                                             ";
			gotoXY(70, 26);
			chuyenbaymoi->NhapSoHieuMB();
		}
		gotoXY(50, 27); cout << "                                                       ";
		gotoXY(50, 27); TextColor(10); cout << "OK!"; TextColor(15);
		chuyenbaymoi->NhapThoigian();
		while (TrungThoigianCB(chuyenbaymoi)) {
			gotoXY(50, 32); cout << "                                       ";
			gotoXY(50, 32); TextColor(12); cout << "Thoi gian chuyen bay bi trung!"; TextColor(15);
			gotoXY(50, 31); cout << "                                     ";
			gotoXY(50, 29); cout << "                                                     ";
			gotoXY(50, 30); cout << "                ";
			chuyenbaymoi->NhapThoigian();
		}
		
		chuyenbaymoi->SetVe(ds.Getmaybay(chuyenbaymoi->GetSoHieuMB())->GetSocho());
		chuyenbaymoi->SetTrangThai(con_ve);
		chuyenbaymoi->SetChuyenBayKe(NULL);
		Soluongchuyenbay++;

		if (chuyenbaydau == NULL) {
			chuyenbaydau = chuyenbaymoi;
		}
		else {
			ChuyenBay* tam = chuyenbaydau;
			while (tam->GetChuyenBayKe() != NULL) 
			tam = tam->GetChuyenBayKe();
			tam->SetChuyenBayKe(chuyenbaymoi);
			chuyenbaymoi->SetChuyenBayKe(NULL);
		}
		gotoXY(50, 34); TextColor(10);
		cout << "An Esc de thoat- An Enter de tiep tuc them! "; TextColor(15);
		while (1) {
			if (_kbhit()) {
				luachon = _getch();
				if (luachon == 27) {
					cout << endl; break;
				}
				else if (luachon == 13) {
					cout << endl; break;
				}
			}
		}
	}
}
void DSChuyenBay::Dataout() {
	fstream filechuyenbay;
	filechuyenbay.open("dschuyenbay.txt", ios::out);
	fstream fileve;
	fileve.open("dsve.txt", ios::out);
	if (Soluongchuyenbay != 0) {
		for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe()) {
			filechuyenbay << tam->GetMaCB() << endl;
			filechuyenbay << tam->GetSanBayDen() << endl;
			filechuyenbay << tam->GetThoiGian().GetNgay().GetNgay() << " ";
			filechuyenbay << tam->GetThoiGian().GetNgay().GetThang() << " ";
			filechuyenbay << tam->GetThoiGian().GetNgay().GetNam() << " ";
			filechuyenbay << tam->GetThoiGian().GetGio().GetGio() << " ";
			filechuyenbay << tam->GetThoiGian().GetGio().GetPhut() << endl;
			filechuyenbay << tam->GetTrangThai() << endl;
			filechuyenbay << tam->GetSoHieuMB() << endl;
			fileve << tam->GetVe().GetSoluongve() << " ";
			fileve << tam->GetVe().Soluongvedamua() << endl;
			for (int i = 1; i <= tam->GetVe().GetSoluongve(); i++) {
				if (tam->GetVe().GetdsVe()[i] != "")
					fileve << i <<" "<< tam->GetVe().GetdsVe()[i] << endl;
			}
		}
	}
	cout << "Saved";
	filechuyenbay.close();
	fileve.close();
	cout << "An phim bat ki de thoat";
	_getch();
}
void DSChuyenBay::Datain() {
	Soluongchuyenbay = 0;
	fstream filechuyenbay;
	filechuyenbay.open("dschuyenbay.txt", ios::in);
	if (filechuyenbay.is_open()) {
		char MaCBtam[sizema_max];
		char Diemdentam[size_diemden];
		int Ngaytam, Thangtam, Namtam, Giotam, Phuttam,Trangthaitam;
		char SohieuMBtam[sizesohieu_max];
		if (Filerong(filechuyenbay));
		else {
			fstream fileve;
			fileve.open("dsve.txt", ios::in);
			ChuyenBay* tam = new ChuyenBay;
			while (filechuyenbay.getline(MaCBtam, sizema_max)) {
				tam->SetMaCB(MaCBtam);
				filechuyenbay.getline(Diemdentam, size_diemden);
				tam->SetSanBayDen(Diemdentam);
				filechuyenbay >> Ngaytam;
				filechuyenbay >> Thangtam;
				filechuyenbay >> Namtam;
				filechuyenbay >> Giotam;
				filechuyenbay >> Phuttam;
				filechuyenbay >> Trangthaitam;
				ThoiGian tgiantam;
				tgiantam.SetNgay(Ngaytam, Thangtam, Namtam);
				tgiantam.SetGio(Giotam, Phuttam);
				tam->SetThoiGian(tgiantam);
				TrangThai tt;
				if (Trangthaitam == 0)tt = huy_chuyen;
				else if (Trangthaitam == 1)tt = con_ve;
				else if (Trangthaitam == 2)tt = het_ve;
				else if (Trangthaitam == 3)tt = hoan_tat;
				Ngay ngayhientai;
				ngayhientai.SetNgayThangNam(Realday(), Realmonth(), Realyear());
				Gio giohientai;
				giohientai.SetGioPhut(Realhour(), Realmin());
				if (tam->GetThoiGian().GetNgay().SoSanhNgayThangNam(ngayhientai) == -1) {
					tt = hoan_tat;
				}
				else if (tam->GetThoiGian().GetNgay().SoSanhNgayThangNam(ngayhientai) == 0) {
					if (tam->GetThoiGian().GetGio().SosanhGioPhut(giohientai) == -1)
						tt = hoan_tat;
				}
				tam->SetTrangThai(tt);
				filechuyenbay.ignore();
				filechuyenbay.getline(SohieuMBtam, sizesohieu_max);
				tam->SetSoHieuMB(SohieuMBtam);
				int sove, sovedamua;
				fileve >> sove;
				fileve >> sovedamua;
				tam->SetVe(sove);
				int vitri; string CMNDtam;
				for (int i = 1; i <= sovedamua; i++) {
					fileve >> vitri;
					fileve >> CMNDtam;
					tam->SetDsve(vitri, CMNDtam);
				}
				if (this->chuyenbaydau == NULL)chuyenbaydau = tam;
				else {
					ChuyenBay* temp = chuyenbaydau;
					while (temp->GetChuyenBayKe() != NULL) {
						temp = temp->GetChuyenBayKe();
					}
					temp->SetChuyenBayKe(tam);
					tam->SetChuyenBayKe(NULL);
				}
				Soluongchuyenbay++;
				tam = new ChuyenBay;
			}
		}
	}
	filechuyenbay.close();
}
void DSChuyenBay::InDSChuyenBay() {
	if (chuyenbaydau == NULL)cout << "Danh sach rong" << endl;
	else {
		for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe()) 
			tam->InChuyenBay();
	}
}
ChuyenBay* DSChuyenBay::TimChuyenBay(char MaCB[]) {
	for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe()) {
		if (strcmp(tam->GetMaCB(), MaCB) == 0)return tam;
	}
	return NULL;
}
bool DSChuyenBay::CoChuyenBay(char sohieu[]) {
	int dem = 0;
	for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe()) {
		if (strcmp(tam->GetSoHieuMB(), sohieu) == 0) {
			if (tam->GetTrangThai() == con_ve || tam->GetTrangThai() == het_ve)dem++;
		}
	}
	if (dem != 0)return true;
	else return false;
}
void DSChuyenBay::HieuChinhNgayGio() {
	int luachon = 13;
	while (luachon == 13) {
		clrscr();
		int dem = 0;
		for (ChuyenBay* duyet = chuyenbaydau; duyet != NULL; duyet = duyet->GetChuyenBayKe()) {
			if (duyet->GetTrangThai() == huy_chuyen || duyet->GetTrangThai() == hoan_tat)dem++;
		}
		if (dem == Soluongchuyenbay) {
			VeKhungXoaMB();
			gotoXY(50, 20); TextColor(12);
			cout << "Tat ca cac chuyen bay da huy! an phim bat ki de thoat"; TextColor(15);
			_getch(); break;
		}
		else {
			ChuyenBay* cbtam = new ChuyenBay; ChuyenBay* cansua = new ChuyenBay;
			VeKhungXoaMB();
			do{
				cbtam->NhapMaCB();
				cansua = TimChuyenBay(cbtam->GetMaCB());
				while (cansua == NULL) {
					gotoXY(50, 21); cout << "                                                       ";
					gotoXY(50, 21); TextColor(12);
					cout << "Khong tim thay chuyen bay! moi ban nhap lai"; TextColor(15);
					gotoXY(70, 20); cout << "                             ";
					cbtam->NhapMaCB();
					cansua = TimChuyenBay(cbtam->GetMaCB());
				}
				if (cansua->GetTrangThai() == hoan_tat || cansua->GetTrangThai() == huy_chuyen) {
					gotoXY(50, 21); cout << "                                       ";
					gotoXY(50, 21); TextColor(12);
					cout << "CB da hoan tat(da huy)! khong the chinh sua!nhap lai"; TextColor(15);
					gotoXY(70, 20); cout << "                             ";
				}
			} while (cansua->GetTrangThai() == hoan_tat || cansua->GetTrangThai() == huy_chuyen);
			gotoXY(50, 21); cout << "                                                       ";
			gotoXY(50, 21); TextColor(10);
			cout << "Ok"; TextColor(15);
			gotoXY(0, 0); VeKhungThemCB();
			gotoXY(50, 23); cout << "San bay den: ";
			gotoXY(70, 23); cout << cansua->GetSanBayDen();
			gotoXY(50, 26); cout << "So hieu MB: ";
			gotoXY(70, 26); cout << cansua->GetSoHieuMB();
			cansua->NhapThoigian();
			while (TrungThoigianCB(cansua)) {
				gotoXY(50, 32); cout << "                                       ";
				gotoXY(50, 32); TextColor(12); 
				cout << "Thoi gian chuyen bay bi trung!"; 
				TextColor(15);
				gotoXY(50, 31); cout << "                                     ";
				gotoXY(50, 29); cout << "                                                     ";
				gotoXY(50, 30); cout << "                ";
				cansua->NhapThoigian();
			}
			delete cbtam;
			gotoXY(50, 34); TextColor(10);
			cout << "An Esc de thoat-Enter tiep tuc hieu chinh!"; TextColor(15);
			while (1) {
				if (_kbhit()) {
					luachon = _getch();
					if (luachon == 27) {
						cout << endl;
						break;
					}
					else if (luachon == 13) {
						cout << endl; break;
					}
				}
			}
			gotoXY(0, 0);
		}
	}
}
void DSChuyenBay::HuyChuyenBay() {
	int luachon = 13;	
	while (luachon == 13) {
		clrscr();
		int dem = 0;
		for (ChuyenBay* duyet = chuyenbaydau; duyet != NULL; duyet = duyet->GetChuyenBayKe()) 
			if (duyet->GetTrangThai() == huy_chuyen || duyet->GetTrangThai() == hoan_tat)dem++;
		if (dem == Soluongchuyenbay) {
			gotoXY(0, 0);
			VeKhungXoaMB();
			gotoXY(50, 20);
			cout << "Tat ca chuyen bay da huy! an phim bat ki de thoat" << endl;
			_getch(); break;
		}
		else{
		ChuyenBay* cbtam = new ChuyenBay; ChuyenBay* cansua = new ChuyenBay;
		do {
			gotoXY(0, 0);
			VeKhungXoaMB();
			cbtam->NhapMaCB();
			cansua = TimChuyenBay(cbtam->GetMaCB());
			while (cansua == NULL) {
				gotoXY(50, 21); cout << "                                                       ";
				gotoXY(50, 21); TextColor(12);
				cout << "Khong tim thay chuyen bay! moi ban nhap lai"; TextColor(15);
				gotoXY(70, 20); cout << "                             ";
				cbtam->NhapMaCB();
				cansua = TimChuyenBay(cbtam->GetMaCB());
			}
			if (cansua->GetTrangThai() == hoan_tat || cansua->GetTrangThai() == huy_chuyen){
				gotoXY(50, 21); cout << "                                                       ";
				gotoXY(50, 21); TextColor(12);
				cout << "Chuyen bay da hoan tat hoac da huy!"; TextColor(15);
				gotoXY(70, 20); cout << "                             ";
			}
		} while (cansua->GetTrangThai() == hoan_tat || cansua->GetTrangThai() == huy_chuyen);
		gotoXY(50, 21); cout << "                                                       ";
		gotoXY(50, 21); TextColor(10);
		cout << "OK"; 
		gotoXY(50, 23); cout << "Ban co thuc su muon huy chuyen?";
		gotoXY(50, 24); cout << "Enter: Yes                      Esc:NO";
		char key;
		while (1) {
			if (_kbhit()) {
				key = _getch();
				if (key == 13) {
					cansua->SetTrangThai(huy_chuyen);
					delete cbtam;
					break;
				}
				else if (key == 27) 
					break;
			}
		}
		gotoXY(50, 25);
			cout << "An Esc de thoat- An Enter de tiep tuc huy! ";
			TextColor(15);
			while (1) {
				if (_kbhit()) {
					luachon = _getch();
					if (luachon == 27) {
						cout << endl; break;
					}
					else if (luachon == 13) {
						cout << endl; break;
					}
				}
			}
		}
	}
}
void DSChuyenBay::HuyTatcaChuyenBay() {
	cout << "Ban co that su muon huy tat ca cac chuyen bay khong?" << endl;
	cout << "YES: Enter----NO: Esc" << endl;
	while (1) {
		char key = _getch();
		if (key == 13)break;
		else if (key == 27)return;
	}
	ChuyenBay* tam = chuyenbaydau;
	for (tam; tam != NULL; tam = tam->GetChuyenBayKe()) {
		if (tam->GetTrangThai() == con_ve || tam->GetTrangThai() == het_ve)
			tam->SetTrangThai(huy_chuyen);
	}
	cout << "Tat ca cac chuyen bay da huy thanh cong" << endl;
}
void DSChuyenBay::XoaDSChuyenBay() {
	ChuyenBay *tam;
	while (chuyenbaydau != NULL)
	{
		tam = chuyenbaydau;
		chuyenbaydau = chuyenbaydau->GetChuyenBayKe();
		delete tam;
	}
}
void DSChuyenBay::SapxepDSCB() {
	ChuyenBay* tam=new ChuyenBay;
	for (ChuyenBay* a = chuyenbaydau; a->GetChuyenBayKe() != NULL; a = a->GetChuyenBayKe()) {
		for (ChuyenBay* b = a->GetChuyenBayKe(); b != NULL; b = b->GetChuyenBayKe()) {
			if (_strcmpi(a->GetSanBayDen(),b->GetSanBayDen())>0) {
				tam->CopyInfo(a);
				a->CopyInfo(b);
				b->CopyInfo(tam);
			}
		}
	}
}
char* DSChuyenBay::ChonDiemDen() {
	int dem = 0;
	for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe()) 
		if (tam->GetTrangThai() != con_ve)dem++;
	if (dem == Soluongchuyenbay) {
		cout << "Cac chuyenbay da het ve! an phim bat ki de thoat" << endl;
		_getch();
		return NULL;
	}
	else {
		SapxepDSCB();
		char diemdentam[size_diemden] = ""; int vitriy = 2; int page = 1; int location = 1;
		int chon = NULL;
		char key;dem = 0; ChuyenBay* tam = chuyenbaydau; int count = 0;
		for (tam; tam != NULL; tam = tam->GetChuyenBayKe()) {
			if (tam->GetTrangThai() == con_ve) {
				if (strcmp(diemdentam, tam->GetSanBayDen()) != 0) {
					strcpy(diemdentam, tam->GetSanBayDen());
					count++;
				}
			}
		}
		int pagemax = (count - 1) / 10 + 1;
		tam = chuyenbaydau; strcpy(diemdentam, "");

	
		gotoXY(140, 0); 
		VeKhungHuongDan();

		gotoXY(140, 0); VeKhungChonDiemDen();
		gotoXY(140, 0); cout << "                         ";
		while (1) {
			gotoXY(120, 30); cout <<"Trang: "<< page;
			ShowConsoleCursor(false); 
			dem = 0; tam = chuyenbaydau; vitriy = 2; strcpy(diemdentam, "");
			for (tam; tam != NULL; tam = tam->GetChuyenBayKe()) {
				if (tam->GetTrangThai() == con_ve) {
					if (strcmp(diemdentam, tam->GetSanBayDen()) != 0) {
						strcpy(diemdentam, tam->GetSanBayDen());
						dem++;
					}
				}
				/*if (dem >= ((page - 1) * 10))break;*/
				if (page != 1) {
					if (dem >= ((page - 1) * 10)+1)break;
				}
				else if (dem >= ((page - 1) * 10))break;
			}
			dem = 0; strcpy(diemdentam, "");
			for (tam; tam != NULL; tam = tam->GetChuyenBayKe()) {
				if (tam->GetTrangThai() == con_ve) {
					if (strcmp(diemdentam, tam->GetSanBayDen()) != 0) {
						if (location - 1 == dem)TextColor(10);
						if (chon-1==dem)
							return tam->GetSanBayDen();
						tam->Inthongtindiemden(vitriy); dem++;
						vitriy += 3;
						resetMauMacDinh();
						strcpy(diemdentam, tam->GetSanBayDen());
					}
					if (dem >= 10)break;
				}
			}
			gotoXY(0, 0); cout << location;
			gotoXY(0, 1); cout << count;
				key = _getch(); 
				if (key == 75) {
					if (page == 1)page = pagemax;
					else page--;
					location = 1;
					for (int i = 2; i <= 30; i += 3) {
						for (int j = 1; j <= 50; j++) {
							gotoXY(45 + j, i); cout << " ";
						}
					}
				}
				else if (key == 77) {
					if (page == pagemax)page = 1;
					else page++;
					location = 1;
					for (int i = 2; i <= 30; i += 3) {
						for (int j = 1; j <= 50; j++) {
							gotoXY(45 + j, i); cout << " ";
						}
					}
				}
				else if (key == 72) {
					if (location == 1) {
						if (page == pagemax&&count%10!=0)location =  count%10;
						else location = 10;
					}
					else location--;
				}
				else if (key == 80) {
					if (page == pagemax&&count%10!=0) {
						if (location == count % 10)location = 1;
						else location++;
					}
					else {
						if (location == 10)location = 1;
						else location++;
					}
				}
				else if (key == 13) {
					chon = location;
				}
			
		}
	}
}
char* DSChuyenBay::ChonChuyenBay() {
	int count = 0; char diemdenchon[size_diemden];
	strcpy(diemdenchon, ChonDiemDen());
	clrscr();
	system("color 07");
	for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe())
		if ((tam->GetTrangThai() != con_ve)&&strcmp(diemdenchon,tam->GetSanBayDen())==0)count++;
	int countallcb = 0;
	for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe())
		if (strcmp(tam->GetSanBayDen(),diemdenchon) == 0)countallcb++;
	if(count==countallcb) {
		cout << "Khong con chuyen bay de dat ve! an phim bat ki de thoat" << endl;
		_getch();
		return NULL;
	}
	else {
		count = 0;
		for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe()) {
			if (tam->GetTrangThai() == con_ve && strcmp(diemdenchon, tam->GetSanBayDen()) == 0)
				count++;
		}
		int pagemax = (count - 1) / 10 + 1;
		int page = 1; int location = 1; int vitriy = 2; char key; int dem = 0;
		ChuyenBay* tam = chuyenbaydau; int chon = NULL;
		while (1) {
			gotoXY(140, 0);
			//VeKhungHuongDan(); 

			gotoXY(0, 0); cout << page;
			ShowConsoleCursor(false);
			dem = 0; tam = chuyenbaydau; vitriy = 2;
			for (tam; tam != NULL; tam = tam->GetChuyenBayKe()) {
				if (tam->GetTrangThai() == con_ve && strcmp(diemdenchon, tam->GetSanBayDen()) == 0)
					dem++;
				if (page != 1) {
					if (dem >= ((page - 1) * 10)+1)break;
				}
				else if (dem >= ((page - 1) * 10)) break;
			}
			dem = 0;
			for (tam; tam != NULL; tam = tam->GetChuyenBayKe()) {
				if (tam->GetTrangThai() == con_ve && strcmp(diemdenchon, tam->GetSanBayDen()) == 0) {
					if (location - 1 == dem)TextColor(240);
					if (chon - 1 == dem) {
						return tam->GetMaCB();
					}
					tam->InThongtinCBdedatve(vitriy); dem++;
					vitriy += 2;
					resetMauMacDinh();
					if (dem >= 10)break;
				}
			}
			if (_kbhit()) {
				key = _getch();
				clrscr();
				if (key == 75) {
					if (page == 1)page = pagemax;
					else page--;
					location = 1;
					system("color 07");
				}
				else if (key == 77) {
					if (page == pagemax)page = 1;
					else page++;
					location = 1;
					system("color 07");
				}
				else if (key == 72) {
					if (location == 1) {
						if (page == pagemax && count%10 != 0)location = count % 10;
						else location = 10;
					}
					else location--;
				}
				else if (key == 80) {
					if (page == pagemax&&count%10!=0) {
						if (location == count % 10)location = 1;
						else location++;
					}
					else {
						if (location == 10)location = 1;
						else location++;
					}
				}
				else if (key == 13) {
					chon = location;
				}
			}
		}
	}
}
bool DSChuyenBay::HanhKhachDaMuaVe(ThoiGian tgiancb,HanhKhach* hk) {
	for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe()) {
		if (tam->GetThoiGian().GetNgay().SoSanhNgayThangNam(tgiancb.GetNgay()) == 0 /*&& tam->GetThoiGian().GetGio().SosanhGioPhut(tgiancb.GetGio())==0*/)
		{
			for (int i = 1; i <= tam->GetVe().GetSoluongve(); i++) {
				if (strcmp(Convertstringtochar((tam->GetVe().GetdsVe())[i]), hk->GetCMND()) == 0)
					return true;
			}
		}
	}
}
void DSChuyenBay::Datve() {
	DSHanhKhach dshk;
	dshk.KhoitaoDSHanhKhach();
	dshk.Datain();
	HanhKhach* hkdatve=dshk.Themhanhkhach();
	clrscr();
	char machuyenbaychon[sizema_max];ChuyenBay* chon = chuyenbaydau;
	do
	{
		strcpy(machuyenbaychon, ChonChuyenBay());
		for (chon = chuyenbaydau; chon != NULL; chon = chon->GetChuyenBayKe())
			if (strcmp(chon->GetMaCB(), machuyenbaychon) == 0)break;
		if (HanhKhachDaMuaVe(chon->GetThoiGian(), hkdatve)) {
			system("color 07"); clrscr(); gotoXY(50, 30); TextColor(12);
			cout << "Hanh khach da mua ve trong ngay hom nay! An phim bat ki de chon lai";
			_getch(); TextColor(15);
			gotoXY(50, 30); cout << "                                                                          ";
		}
	} while (HanhKhachDaMuaVe(chon->GetThoiGian(), hkdatve));
	
	int mau;
	int contro = 1;
	int vedamua = chon->GetVe().Soluongvedamua();
	clrscr(); system("color 07");
	int page = 1; int pagemax = (chon->GetVe().GetSoluongve() - 1) / 50 + 1;
	int vitrix = 20; int vitriy = 5; int dem = 0; int demdo = 0;
	int batdau; int ketthuc; char key; int tmp; int sodong=0;
	while (1) {
		sodong = 0; demdo = 0;
		ShowConsoleCursor(false);
		vitrix = 20; vitriy = 5;
		dem = 0;			
		batdau = 50 * (page-1) + 1;
		while ((chon->GetVe().GetdsVe()[contro]) != "")	contro = contro++;
		if (page == pagemax&&chon->GetVe().GetSoluongve()%50!=0)ketthuc = batdau + (chon->GetVe().GetSoluongve() % 50-1);
		else ketthuc = batdau + 49;
		for (int i=batdau; i <= ketthuc; i++) {
			if (i == contro)mau = 46; //vang
			else if (chon->GetVe().GetdsVe()[i] != "") {
				mau = 71;//do
				demdo++;
			}
			else mau = 31;//xanh
			Ghe(vitrix, vitriy, i,mau);
			dem++; vitrix += 10;
			if (dem == 10) {
				vitrix = 20;
				vitriy += 5;
				dem = 0;
			}
			if (dem == 1)sodong++;
		}
		key = _getch();
		tmp = contro;
		//gotoXY(30, 40);
		//cout << "temp" << tmp << " contro: " << contro;
		if (key == 97&&demdo!=(ketthuc-batdau+1)) {
			while (1) {
				if (tmp == batdau) 
					tmp = ketthuc;
				else 
					tmp = tmp - 1;
				if ((chon->GetVe().GetdsVe()[tmp]) == "") {
					contro = tmp;
					break;
				}
			/*	if (vedamua == chon->GetVe().GetSoluongve())break;*/
			}
		}
		else if (key == 100 && demdo != (ketthuc - batdau + 1)) {
			while (1) {
				if (tmp == ketthuc)
					tmp = batdau;
				else
					tmp = tmp + 1;
				if ((chon->GetVe().GetdsVe()[tmp]) == "") {
					contro = tmp;
					break;
				}
				/*if (vedamua == chon->GetVe().GetSoluongve())break;*/
			}
		}
		else if (key == 119 && demdo != (ketthuc - batdau + 1)) {
			int count = 0;
			while (1) {
				if (tmp <= (batdau + 9) && tmp >= batdau) {
					tmp = tmp + (sodong - 1) * 10;
					while (tmp > ketthuc)tmp--;
				}
				else tmp = tmp - 10;
				count++;
				if ((chon->GetVe().GetdsVe()[tmp]) == "") {
					contro = tmp;
					break;
				}
				/*if (count == 5 || vedamua == chon->GetVe().GetSoluongve())break;*/
			}
		}
		else if (key == 115 && demdo != (ketthuc - batdau + 1)) {
			int count = 0;
			while (1) {
				if (tmp <= ketthuc && tmp >= (page-1)*50+(sodong-1)*10+1) {
					tmp= tmp - (sodong - 1) * 10;
				}
				else tmp = tmp + 10;
				count++;
				if ((chon->GetVe().GetdsVe())[tmp] == "") {
					contro = tmp;
					break;
				}
		/*		if (count == 5 || vedamua == chon->GetVe().GetSoluongve())break;*/
			}
		}
		else if (key == 75) {
			if (page == 1)page = pagemax;
			else page--;
			contro = (page - 1) * 50 + 1;
			clrscr();
			system("color 07");
		}
		else if (key == 77) {
			if (page == pagemax)page = 1;
			else page++;
			contro = (page - 1) * 50 + 1;
			clrscr();
			system("color 07");
		}
		else if (key == 13) {
			chon->SetDsve(contro, hkdatve->GetCMND());
			vedamua++;
			if (vedamua == chon->GetVe().GetSoluongve()) {
				chon->SetTrangThai(het_ve);
			}
			break;
		}
	}
	dshk.Dataout();
	Dataout();
}
char* DSChuyenBay::ChonChuyenBayHuyVe(char CMND[]) {
	int demvedamua = 0; char trave[sizema_max]; strcpy(trave,"");
	ChuyenBay* chon = chuyenbaydau;
	for (chon; chon != NULL; chon = chon->GetChuyenBayKe()) {
		if (chon->GetVe().CoNguoiMuaVe(CMND))demvedamua++;
	}
	//em cout ở đây thì trave ra""
	if (demvedamua == 0) return trave; //em tra ve "" ma sao no bao tran? neu nhu ng đó k mua vé
	else {
		int pagemax = (demvedamua - 1) / 10 + 1;
		int page = 1; int location = 1; int vitriy = 2; char key; int dem = 0;
		chon = chuyenbaydau; int luachon = NULL;
		while (1) {
			gotoXY(0, 0); cout << page;
			ShowConsoleCursor(false);
			dem = 0; chon = chuyenbaydau; vitriy = 2;
			for (chon; chon != NULL; chon = chon->GetChuyenBayKe()) {
				if (chon->GetVe().CoNguoiMuaVe(CMND))
					dem++;
				if (page != 1) {
					if (dem >= ((page - 1) * 10)+1)break;
				}
				else if (dem >= ((page - 1) * 10))break;
			}
			dem = 0;
			for (chon; chon != NULL; chon = chon->GetChuyenBayKe()) {
				if (chon->GetVe().CoNguoiMuaVe(CMND)) {
					if (location - 1 == dem)TextColor(240);
					if (luachon - 1 == dem) {
						return chon->GetMaCB();
					}
					chon->InThongtinCBdedatve(vitriy); dem++;
					vitriy += 2;
					resetMauMacDinh();
					if (dem >= 10)break;
				}
			}
			if (_kbhit()) {
				key = _getch();
				clrscr();
				if (key == 75) {
					if (page == 1)page = pagemax;
					else page--;
					location = 1;
					system("color 07");
				}
				else if (key == 77) {
					if (page == pagemax)page = 1;
					else page++;
					location = 1;
					system("color 07");
				}
				else if (key == 72) {
					if (location == 1) {
						if (page == pagemax && demvedamua % 10 != 0)location = demvedamua % 10;
						else location = 10;
					}
					else location--;
				}
				else if (key == 80) {
					if (page == pagemax&& demvedamua%10!=0) {
						if (location == demvedamua % 10)location = 1;
						else location++;
					}
					else {
						if (location == 10)location = 1;
						else location++;
					}
				}
				else if (key == 13) {
					luachon = location;
				}
			}
		}
	}
}
void DSChuyenBay::Huyve() {
	DSHanhKhach dshk;
	dshk.KhoitaoDSHanhKhach();
	dshk.Datain();
	HanhKhach *a = new HanhKhach;
	do
	{
		a = new HanhKhach;
		cout << "Nhap CMND cua ban de huy ve!" << endl;
		a->NhapCMND();
		a = dshk.Cohanhkhach(a);
		if (a == NULL)cout << "Khong co hanh khach moi ban nhap lai" << endl;
	} while (a==NULL);

	char* Macbtam = ChonChuyenBayHuyVe(a->GetCMND());

	//strcpy_s(Macbtam, sizema_max, ChonChuyenBayHuyVe(a->GetCMND())); //error o day sai k ra ""
	if (strcmp(Macbtam,"")==0) {
		cout << "Hanh Khach chua mua ve nao!";//so sánh thông báo là chưa mua mà sao dưới đây cái 
		_getch();
		return;
	}
	else {
		ChuyenBay* chon = TimChuyenBay(Macbtam);
		chon->GetVe().Huyve(a->GetCMND());
		if (chon->GetTrangThai() == het_ve)chon->SetTrangThai(con_ve);
	}
	Dataout();
}

void DSChuyenBay::InDS_motchuyenbay() {
	ChuyenBay* tam = new ChuyenBay;
	do
	{
		tam->NhapMaCB();
		if (TimChuyenBay(tam->GetMaCB()) == NULL);
		cout << "Khong co chuyen bay! nhap lai!";
	} while (TimChuyenBay(tam->GetMaCB()) == NULL);
	tam = TimChuyenBay(tam->GetMaCB());
	clrscr();
	int count = 0;
	for (int i = 1; i <= tam->GetVe().GetSoluongve(); i++) {
		if (strcmp(Convertstringtochar(tam->GetVe().GetdsVe()[i]), "") != 0)count++;
	}
	if (count == 0)cout << "Khong co hanh khach nao thuoc chuyen bay!";
	else {
		DSHanhKhach dshk;
		dshk.KhoitaoDSHanhKhach();
		dshk.Datain();

		char key; int page = 1; int pagemax = (count - 1) / 10 + 1; ; int dem = 0; int vitriy;
		int batdau = 1; int stt = 0;

		while (1) {
			gotoXY(30, 2);
			cout << "DANH SACH HANH KHACH THUOC CHUYEN BAY " << tam->GetMaCB();
			gotoXY(30, 3);
			cout << "Ngay gio khoi hanh: " << tam->GetThoiGian().GetNgay().GetNgay() << "/"
				<< tam->GetThoiGian().GetNgay().GetThang() << "/"
				<< tam->GetThoiGian().GetNgay().GetNam()
				<< "  Noi den: " << tam->GetSanBayDen();
			gotoXY(30, 6); cout << "STT";
			gotoXY(40, 6); cout << "SO VE";
			gotoXY(50, 6); cout << "SO CMND";
			gotoXY(60, 6); cout << "HO TEN";
			gotoXY(100, 6); cout << "PHAI";
			dem = 0; batdau = 1; vitriy = 8;
			for (batdau; batdau <= tam->GetVe().GetSoluongve(); batdau++) {
				if (strcmp(Convertstringtochar(tam->GetVe().GetdsVe()[batdau]), "") != 0)dem++;
				if (page != 1) { if (dem >= ((page - 1) * 10) + 1)break; }
				else if (dem >= ((page - 1) * 10)) {
					break;
				}
			}

			dem = 0; stt = (page - 1) * 10;
			for (batdau; batdau <= tam->GetVe().GetSoluongve(); batdau++) {
				char* chuoitam = Convertstringtochar(tam->GetVe().GetdsVe()[batdau]);
				if (strcmp(chuoitam, "") != 0) {
					gotoXY(30, vitriy);
					cout << stt + 1; stt++;
					gotoXY(40, vitriy);
					cout <<  batdau;
					gotoXY(50, vitriy);
					cout << tam->GetVe().GetdsVe()[batdau];
					HanhKhach* hktam = dshk.Cohanhkhach(Convertstringtochar(tam->GetVe().GetdsVe()[batdau]));
					gotoXY(60, vitriy);
					cout <<  hktam->GetHo() << " " << hktam->GetTen();
					gotoXY(100, vitriy);
					if (hktam->GetPhai() == 0)cout << "Nam";
					else cout << "Nu";
					dem++;
					vitriy += 2;
					if (dem >= 10)break;
				}
			}
			if (_kbhit()) {
				key = _getch();
				clrscr();
				if (key == 75) {
					if (page == 1)page = pagemax;
					else page--;
				}
				else if (key == 77) {
					if (page == pagemax)page = 1;
					else page++;
				}
				else if (key == 27) {
					break;
				}
			}

		}
	}
}
void DSChuyenBay::InDS_ngay_x_conve() {
	Ngay ngaychuyenbay; Ngay ngayreal;
	ngaychuyenbay.NhapNgayThangNam();
	ngayreal.SetNgayThangNam(Realday(), Realmonth(), Realyear());
	while (ngaychuyenbay.SoSanhNgayThangNam(ngayreal) == -1) {
		gotoXY(50, 30); cout << "                                                   ";
		gotoXY(50, 30); TextColor(12); cout << "Thoi gian phai lon hon thoi gian hien tai!"; TextColor(15);
		gotoXY(50, 29); cout << "                                                              ";
		gotoXY(50, 29);
		ngaychuyenbay.NhapNgayThangNam();
		ngayreal.SetNgayThangNam(Realday(), Realmonth(), Realyear());
	}
	gotoXY(50, 30); cout << "                                                       ";
	gotoXY(50, 30); TextColor(10); cout << "OK!"; TextColor(15);
	char diemdenchon[size_diemden];
	strcpy(diemdenchon, ChonDiemDen());

	int count = 0;
	clrscr();
	system("color 07");
	for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe())
		if ((tam->GetTrangThai() != con_ve) && strcmp(diemdenchon, tam->GetSanBayDen()) == 0&&(tam->GetThoiGian().GetNgay().SoSanhNgayThangNam(ngaychuyenbay)==0))count++;
	int countallcb = 0;
	for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe())
		if (strcmp(tam->GetSanBayDen(), diemdenchon) == 0 )countallcb++;
	//cout << count << countallcb; _getch();
	if (count == countallcb) {
		cout << "Cac chuyen bay da het ve! an phim bat ki de thoat" << endl;
		_getch();
		return;
	}
	else {
		count = 0;
		for (ChuyenBay* tam = chuyenbaydau; tam != NULL; tam = tam->GetChuyenBayKe()) {
			if (tam->GetTrangThai() == con_ve && strcmp(diemdenchon, tam->GetSanBayDen()) == 0 && (tam->GetThoiGian().GetNgay().SoSanhNgayThangNam(ngaychuyenbay) == 0))
				count++;
		}
		int pagemax = (count - 1) / 10 + 1;
		int page = 1; int location = 1; int vitriy = 2; char key; int dem = 0;
		ChuyenBay* tam = chuyenbaydau; int chon = NULL;
		while (1) {
			gotoXY(140, 0);
			gotoXY(0, 0); cout << page << endl;
			ShowConsoleCursor(false);
			dem = 0; tam = chuyenbaydau; vitriy = 2;
			for (tam; tam != NULL; tam = tam->GetChuyenBayKe()) {
				/*cout << tam->GetThoiGian().GetNgay().GetNgay() << endl;
				cout << tam->GetThoiGian().GetNgay().GetThang() << endl;
				cout << tam->GetThoiGian().GetNgay().GetNam() <<  endl;
				cout << tam->GetTrangThai() << endl;*/
				if ((tam->GetTrangThai() == con_ve) && (strcmp(diemdenchon, tam->GetSanBayDen()) == 0) && (tam->GetThoiGian().GetNgay().SoSanhNgayThangNam(ngaychuyenbay) == 0))
				{
					gotoXY(0, 0);
					cout << "ok";
					dem++;
				}
				if (page != 1) {
					if (dem >= ((page - 1) * 10) + 1)break;
				}
				else if (dem >= ((page - 1) * 10)) break;
			}
			dem = 0;
			for (tam; tam != NULL; tam = tam->GetChuyenBayKe()) {
				if (tam->GetTrangThai() == con_ve && strcmp(diemdenchon, tam->GetSanBayDen()) == 0 && (tam->GetThoiGian().GetNgay().SoSanhNgayThangNam(ngaychuyenbay) == 0)) {
					tam->InThongtinCBdedatve(vitriy); dem++;
					vitriy += 2;
					if (dem >= 10)break;
				}
			}
			if (_kbhit()) {
				key = _getch();
				clrscr();
				if (key == 75) {
					if (page == 1)page = pagemax;
					else page--;
					system("color 07");
				}
				else if (key == 77) {
					if (page == pagemax)page = 1;
					else page++;
					system("color 07");
				}
			}
		}
	}
}
