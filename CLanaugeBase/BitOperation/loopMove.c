/************/
/* ѭ����λ */
/************/

#include <stdio.h>

int main5()
{
	unsigned char a, b, c;
	int n;

	printf("������Ҫʵ��ѭ�����Ƶ�����: ");
	scanf("%d", &a);
	printf("������Ҫʵ�����Ƶ�λ��: ");
	scanf("%d", &n);

	b = a << (sizeof(char) * 8 - n);
	c = a >> n;
	c = c | b;
	printf("�����: %c\n", c);

	return 0;
}