/*****************/
/* 大小写字母转换 */
/*****************/

#include <stdio.h>

int main1()
{
	char ch, temp;
	printf("please input letter: ");
	ch = getchar();
	temp = getchar();

	while ( !(ch >= 'A' && ch <= 'z') || (ch >= 'Z' && ch <= 'a'))
	{
		printf("Error!\nplease input letter: ");
		ch = getchar();
	}

	if (ch & 32)			// 判断字符二进制第5位是否为 1 
	{
		ch = ch & 223;		// 如果为 1 ，则进行与运算对第5位取反，变大写
	}
	else
	{
		ch = ch | 255;		// 如果不为 1 ，则按位或运算，使第五位变 1 ，变小写
	}

	printf("%c", ch);

	//if (ch >= 97 && ch <= 122)
	//{
	//	ch = ch & 223;
	//}
	//else if (ch <= 90 && ch >= 60)
	//{
	//	ch = ch | 32;
	//}

	return 0;
}