// stdafx.cpp : 只包括标准包含文件的源文件
// plan_vs_paln.pch 将作为预编译标头
// stdafx.obj 将包含预编译类型信息

#include "stdafx.h"

// TODO: 在 STDAFX.H 中引用任何所需的附加头文件，
//而不是在此文件中引用

void DrawMessage(CDC*pDC, int width, int height);
void FireoutIf();
void shotmove();
void Enemyshot();
void Enemyplaneout();
void Shot();
void TransparentBitmap(HDC hdc, HBITMAP hBitmap, short xStart, short yStart, short xadd, short yadd, COLORREF cTransparentColor);

COLORREF cTransparentColor;
CBitmap enemydead;
CBitmap bmenemyshot;
CBitmap enemy;
CBitmap bmshot;
CBitmap plane;
short numplane;
int back[15][12];
int xStart, yStart;
CBitmap bmfire;
CPoint pointfire;

