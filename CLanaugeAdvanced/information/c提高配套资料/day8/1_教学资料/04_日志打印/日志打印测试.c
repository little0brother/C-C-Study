#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "itcastlog.h"

int main(void)
{
	//C�����Դ���
	// __FILE__: �������߶���2���»��ߣ���ǰ__FILE__���ڵ��ļ��� %s
	// __LINE__: ��ǰ__LINE__���ڵ��У� %d

	printf("file = %s\nline = %d\n", __FILE__, __LINE__);

	int a = 10;
	ITCAST_LOG(__FILE__, __LINE__, 1, -100, "debug = %d\n", a);

	ITCAST_LOG(__FILE__, __LINE__, 4, -1, "err = %d\n", 250);
	
	printf("\n");
	system("pause");
	return 0;
}