#include <stdio.h>

typedef struct A
{
	int a;
	int b;
	char* p;
}A;

/*
* 1���ṹ�����Ƕ������һ���ṹ����κ����ͱ���
* 2���ṹ��Ƕ�ױ��ṹ����ͨ�����������ԣ�
*	 ���ṹ������ʹ�С�޷�ȷ�������͵ı��ʣ��̶���С�ڴ�����
* 3���ṹ��Ƕ�ױ��ṹ���ָ����������ԣ�
*    ָ����������ʹ�С��ȷ�� 32λ 4�ֽ�    64λ 8�ֽ�
*/
typedef struct B
{
	int a;
	A tmp1; 
	A* p1;

	// struct B tmp2; //err
	struct B* next;	//ok	32λ 4�ֽ�    64λ 8�ֽ�
}B;

int main()
{


	return 0;
}