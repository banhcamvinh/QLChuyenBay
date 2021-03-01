#pragma once
#ifndef _Display
#define _Display
#include "All.h"
#include "MayBay.h"
#include "DSMayBay.h"
#include "ChuyenBay.h"
#include "DSChuyenBay.h"
#include "HanhKhach.h"
#include "DSHanhKhach.h"
#include "DSVe.h"
#define chieucaoconsole 30
#define chieurongconsole 80
#define Do 440
#define Re 493
#define Mi 554
#define Fa 587
#define Sol 659
#define La 739
#define Si 830
//DSChuyenBay *cb = new DSChuyenBay;

void ThanhMenu(int vitrix, int vitriy, int mau, string title);
void Menu();
void Menu1();
void Menu2();
void Menu3();
void Menu4();
void Menu5();
void Menu6();
void Menu7();
void Menu8();
void vekhung();
void resizeConsole(int width, int height);
void Button(int vitrix, int vitriy, string text, int mau);
#endif // !_Display

