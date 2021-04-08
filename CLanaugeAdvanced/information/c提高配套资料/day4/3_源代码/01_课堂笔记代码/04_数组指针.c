#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//argc: �������ĸ�����������ִ�г���
//argv��ָ�����飬ָ������Ĳ���
int main01(int argc, char *argv[])
{
	//����ָ�룬ָ������

	//ָ�����飬�������飬ÿ��Ԫ�ض���ָ��
	//[] �� * ���ȼ���
	char *a[] = { "aaaaaaa", "bbbbbbbbbb", "ccccccc" };
	int i = 0;

	printf("argc = %d\n", argc);

	for (i = 0; i < argc; i++)
	{
		printf("%s\n", argv[i]);
	}


	printf("\n");
	system("pause");
	return 0;
}

int main02(void)
{
	//����ָ�룬����ָ�룬ָ��һ�������ָ��
	//����ָ�룬ָ��һά������������飬��������Ԫ�ص�ַ
	//��������ָ�����

	int a[10] = { 0 };
	int i = 0;

	//1���ȶ����������ͣ��������Ͷ���ָ�����
	typedef int A[10]; //A��������, [10]������
	A *p = NULL; //p����ָ�����ͱ���
	//p = a; //a������Ԫ�ص�ַ�� a �� &a һ��������Ҳ�ǵ���&a������
	p = &a; //&a�������������׵�ַ

	printf("p:%d, p+1:%d\n", p, p + 1);

	for (i = 0; i < 10; i++)
	{
		//a[]
		// p = &a;
		// *p = *&a -> a
		(*p)[i] = i + 1;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", (*p)[i] );
	}
	printf("\n");



	printf("\n");
	system("pause");
	return 0;
}

int main03(void)
{
	int a[10] = { 0 };
	int i = 0;

	//2���ȶ�������ָ�����ͣ��������Ͷ������
	//��ָ������д�������ƣ�����()
	//() �� []���ȼ�һ������������
	//()��ָ�룬����һ��ָ�룬 []
	//ָ�������ָ�룬����typedef����������һ������ָ������
	typedef int(*P)[10];
	P q; //����ָ�����
	q = &a;

	for (i = 0; i < 10; i++)
	{
		(*q)[i] = 2*i + 1;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", (*q)[i]);
	}
	printf("\n");


	printf("\n");
	system("pause");
	return 0;
}

void fun(void * a)
{
	printf("%d\n", (int)a);
}

int main(void)
{
	int t = 10;
	fun((void *)t);


	int a[10] = { 0 };
	//a[11] = 10;

	int i = 0;

	//2��ֱ�Ӷ�������ָ�����
	//��ָ������д�������ƣ�����()
	//() �� []���ȼ�һ������������
	//()��ָ�룬����һ��ָ�룬 []
	//ָ�������ָ�룬 û��typedef����������һ������ָ�����
	int(*q)[10]; //q����ָ�����
	q = &a; //qָ��a����

	for (i = 0; i < 10; i++)
	{
		(*q)[i] = 3 * i + 1;
	}

	for (i = 0; i < 10; i++)
	{
		printf("%d ", (*q)[i]);
	}
	printf("\n");

	

	printf("\n");
	system("pause");
	return 0;
}
