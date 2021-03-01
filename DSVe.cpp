#include "DSVe.h"

DSVe::DSVe(int soluong) {
	SoluongVe = soluong;
	ve = new string[soluong+1];
	for (int i = 1; i <= soluong; i++)
		ve[i] = "";
}
int DSVe::GetSoluongve() {
	return SoluongVe;
}
int DSVe::Soluongvedamua() {
	int dem = 0;
	for (int i = 1; i <= SoluongVe; i++) {
		if (ve[i] != "")dem++;
	}
	return dem;

}
string* DSVe::GetdsVe() {
	return ve;
}
void DSVe::SetSoluongVe(int soluong) {
	SoluongVe = soluong;
	ve = new string[soluong + 1];
}
void DSVe::Setve(int i,string a) {
	ve[i] = a;
}
void DSVe::SetDSVE(int sl, string* v) {
	SoluongVe = sl;
	ve = v;
}
bool DSVe::CoNguoiMuaVe(char CMND[]) {
	for (int i = 1; i <= SoluongVe; i++) {
		if (strcmp(CMND, Convertstringtochar(ve[i])) == 0)
			return true;
	}
	return false;
}
void DSVe::Huyve(char CMND[]) {
	for (int i = 1; i <= SoluongVe; i++) {
		if (strcmp(CMND, Convertstringtochar(ve[i])) == 0) {
			ve[i] = ""; break;
		}
	}
}