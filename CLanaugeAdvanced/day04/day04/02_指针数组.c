#include <stdio.h>

// argc: ���εĸ�����������ִ�г���
// argv: ָ�����飬ָ������Ĳ���
int main(int argc, char *argv[])
{
	// ����ָ�룬ָ������

	// ָ�����飬�������飬ÿ��Ԫ�ض���ָ��
	// [] �� * ���ȼ���
	char* a[] = { "aaaaaa", "bbbbbb", "cccccc" };

	printf("argc = %d\n", argc);
	for (int i = 0; i < argc; i++)
	{
		printf("argv = %s\n", argv[i]);
	}

	printf("\n");
	return 0;
}