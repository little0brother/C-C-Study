/*
	ͨ���ݹ�ʵ�֣�1+2+����+100���ۼ�
*/
#include <stdio.h>

int add(int n)
{
	if (n == 1)
		return 1;
	else
		return  n + add(n - 1);
}

int main()
{
	printf("%d", add(100));

	return 0;
}