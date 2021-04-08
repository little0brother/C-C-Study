#include <stdio.h>

#define uint unsigned int
#define uchar unsigned char

uchar  a1[] = { 0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f };
uint  a[] = { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90 };
uint b[8];

int WA = 0;
int WB = 0;
int WC = 0;
int key = 0;
int P0, P2;
uint count;

void delay(uint xms)
{
	uint i, j;
	for (i = xms; i > 0; i--)
		for (j = 110; j > 0; j--);
}

void show()
{
	uchar i;
	for (i = 0; i < 9; i++)
	{
		switch (i)
		{
		case 7:WA = 0; WB = 0; WC = 0; break;
		case 6:WA = 0; WB = 0; WC = 1; break;
		case 5:WA = 0; WB = 1; WC = 0; break;
		case 4:WA = 0; WB = 1; WC = 1; break;
		case 3:WA = 1; WB = 0; WC = 0; break;
		case 2:WA = 1; WB = 0; WC = 1; break;
		case 1:WA = 1; WB = 1; WC = 0; break;
		case 0:WA = 1; WB = 1; WC = 1; break;
		}
		P0 = b[0];
		P2 = b[1];
		delay(100);
	}
}

int main()
{
	while (1)
	{
		key = 1;
		scanf("%d", key);
		count = 0;
		if (key == 0)
		{
			delay(10);
			if (key == 0)
			{
				count++;
				b[1] = a[count / 10];
				b[0] = a[count % 10];
				while (!key);
			}
			show();
		}
	}
}