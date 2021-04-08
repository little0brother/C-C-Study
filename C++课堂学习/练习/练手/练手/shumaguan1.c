#include <stdio.h>
#include <math.h>
#define uint unsigned int
#define uchar unsigned char

uint a[] = { 0xc0, 0xf9, 0xa4, 0xb0, 0x99, 0x92, 0x82, 0xf8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xa1, 0x86, 0x8e, 0xbf, 0xff };


void delay(uint xms)
{
	uint i, j;
	for (i = xms; i > 0; i--)
		for (j = 110; j > 0; j--);
}

void main()
{
	int P0;
	int P1 = 0xff;
	int i;
	int temp, num, x;

	while (1)
	{
		P1 = 0xfe;
		x = 0xfe;
		for (i = 0; i < 4; i++)
		{
			temp = P1;
			temp = temp & 0xf0;
			temp = 0xe0;
			//printf("%x ", P1);
			if (temp != 0xf0)
			{
				//delay(10);
				if (temp != 0xf0)
				{
					//printf("%d", temp);
					switch (temp)
					{
					case 0xe0: num = 4 * i; break;
					case 0xd0: num = 4 * i + 1; break;
					case 0xb0: num = 4 * i + 2; break;
					case 0x70: num = 4 * i + 3; break;
					}
					//printf("%d ", num);
				}
				while (P1 != x);
				//printf("%x ", x);
				x -= pow(2, i);
				P0 = a[num];
				//delay(5);
			}
			P1 -= pow(2, i);
			//printf("%x ", P1);
		}
		//printf("\n");
	}
}