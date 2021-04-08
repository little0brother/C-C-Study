/*****************************/
/* ��ָ������ָ������������ **/
/* ��ƺ���process���ڵ���ʱ��*/
/* ÿ��ʵ�ֲ�ͬ����(���ƶ�̬) */
/****************************/

/* ��������������һ�ε���processʱ�ҳ����ߣ� �ڶ����ҳ�С�ߣ����������*/

#include <stdio.h>

int main4()
{
	int compare2max(int, int);
	int compare2min(int, int);
	int add(int, int);

	// ����ֱ�ߺ����ĺ���ָ�룬int(*fun)()���ݴ��뺯�������жϵ�����һ������
	void process(int, int, int(*fun)());

	int a, b;

	printf("Enter a and b:");
	scanf("%d %d", &a, &b);
	
	printf("max = ");
	process(a, b, compare2max);		// ��compare2maxΪָ�봫��process�����У�ͨ��ָ���жϵ�����һ������

	printf("min = ");
	process(a, b, compare2min);

	printf("sum = ");
	process(a, b, add);

	return 0;
}

int compare2max(int a, int b)
{
	int c;
	return c = a > b ? a : b;
}

int compare2min(int a, int b)
{
	int c;
	return c = a < b ? a : b;
}

int add(int a, int b)
{
	int sum;
	return sum = a + b;
}

void process(int a, int b, int(*fun)())
{
	// ͨ������Ĳ���ȷ������ָ�룬 ���ú�������
	printf("%d\n", (*fun)(a, b));
}