#pragma once

#include <stdio.h>
#include <stdlib.h>
#define M 5

FILE *fp;
int w = 0;

typedef struct{
	char  name[18];
	float price;
	int   amount;
}   massage;

massage shangpin[M] = { { "ø…¿÷", 3.0, 15 },
						{ "—©±Ã",3.0, 15 },
						{ "¡„∂»", 3.0, 15 },
						{ "‹‘¿Ú√€≤Ë", 2.0, 15 },
						{ "∫„¥Û±˘»™", 4.0, 15 } };
massage goods[M + 5];
	
void Commodity_Purchase();
void Display_Inventory();
void Equipment_Maintenance();
void readfp();
void writefp();
void return_();
void Add_Goods();