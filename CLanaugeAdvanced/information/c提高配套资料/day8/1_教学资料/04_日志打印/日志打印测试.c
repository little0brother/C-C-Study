#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itcastlog.h"

int main(void)
{
	//C语言自带宏
	// __FILE__: 左右两边都有2个下划线，当前__FILE__所在的文件， %s
	// __LINE__: 当前__LINE__所在的行， %d

	printf("file = %s\nline = %d\n", __FILE__, __LINE__);

	int a = 10;
	ITCAST_LOG(__FILE__, __LINE__, 1, -100, "debug = %d\n", a);

	ITCAST_LOG(__FILE__, __LINE__, 4, -1, "err = %d\n", 250);
	
	printf("\n");
	system("pause");
	return 0;
}