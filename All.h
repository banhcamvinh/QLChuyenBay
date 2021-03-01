#pragma once
#ifndef _All
#define _All
#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <time.h>
#include <iostream>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <iomanip>

#define enter 13
#define sizeCMND_max 13
#define sizesohieu_max 15
#define sizeloai_max 40
#define sizema_max 15
#define size_diemden 30
#define sokitucho 6
#define sochotoithieu 20
#define SLMB_Max 300
#define sizeho_max 10
#define sizeten_max 30
enum TrangThai { huy_chuyen=0, con_ve=1, het_ve=2, hoan_tat=3 };
using namespace std;
void ClearConsoleToColors(int ForgC, int BackC);
void clrscr();
void gotoXY(int column, int line);
void TextColor(int color);
bool ktraphimmuiten();
void Nhap_loc(char a[], int dolon);
void Nhap_chu(char a[], int dolon);
void Nhapso(char a[], int dolon);
bool Kiemtrarong(char name[]);
bool Kiemtrarong(string a);
void Xoakhoangtrang(char name[]);
void Xoakhoangtrang(string &a);
int Convert_num(char string[], int sl);
int Convert_num(char string[]);
void Nhapso(int &so, int size);
void Upcase(char string[]);
void Upcasedau(char string[]);
char Laychudau(char string[]);
bool Filerong(fstream &file);
char* Convertstringtochar(string a);
void ShowConsoleCursor(bool showFlag);
void resetMauMacDinh();
bool LaNamNhuan(int nam);
void Realtime();
int Realday();
int Realmonth();
int Realyear();
int Realhour();
int Realmin();




void VeKhungThemMB();
void VeKhungXoaMB();
void VeKhungThemCB();
void VeKhungThemHK();
void VeKhungHuongDan();
void VeKhungChonDiemDen();
void MuaVe();
void Ghe(int vitrix,int vitriy,int soghe,int mau);
void Gioithieu();


#endif // !_All

