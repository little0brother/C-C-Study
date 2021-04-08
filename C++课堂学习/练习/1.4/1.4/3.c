/*------------------------------------------------------
【程序改错】
--------------------------------------------------------

功能：分别统计输入的字符串中各元音字母（即：A、E、i、O、U）
的个数。
注意：字母不分大、小写。
例如：若输入：THis is a boot，则输出应该是：1、0、2、2、0。

------------------------------------------------------*/

#include <conio.h>
#include <stdio.h>

fun(char *s, int num[5])
{
	int k, i = 5;
	for (k = 0; k<i; k++)
		/**********FOUND**********/
		num[k] = 0;
	for (; *s; s++)
	{
		i = -1;
		/**********FOUND**********/
		switch (*s)
		{
		case 'a':
		case 'A':
		{
			i = 0;
			break;
		}
		case 'e':
		case 'E':
		{
			i = 1;
			break;
		}
		case 'i':
		case 'I':
		{
			i = 2;
			break;
		}
		case 'o':
		case 'O':
		{
			i = 3;
			break;
		}
		case 'u':
		case 'U':
		{
			i = 4;
			break;
		}
		}
		/**********FOUND**********/
		if (i >= 0)
			num[i]++;
	}
}

main()
{
	char s1[81]; int num1[5], i;
	printf("\nPlease enter a string: "); gets(s1);
	fun(s1, num1);
	for (i = 0; i < 5; i++)
		printf("%d ", num1[i]);
	printf("\n");
	system("pause");
}
