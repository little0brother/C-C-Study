/*****************************************/
/* ���ú���ָ�룬�Ƚ� a �� b �Ĵ�С�����ֵ */
/*****************************************/

#include <stdio.h>

#if(0)
void main3()
{
	int comparemax(int, int);
	int a, b, c;

	scanf("%d %d", &a, &b);

	c = comparemax(a, b);

	printf("a=%d, b=%d, max=%d\n\n", a, b, c);
}
#endif

int comparemax(int a, int b)
{
	int c;
	c = a > b ? a : b;

	return c;
}

#if(1)
void main3()
{
	int comparemax(int, int);
	int (*p)();		// ��������ָ��
	int a, b, c;

	p = comparemax; // ��comparemax()��Ϊ�׵�ַ��ʹpָ��comparemax
	scanf("%d %d", &a, &b);

	c = (*p)(a, b); // ͨ������ָ�����comparemax()����

	printf("a=%d, b=%d, max=%d\n\n", a, b, c);
}
#endif