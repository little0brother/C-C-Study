#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add()
{
	printf("add11111111111\n");
}

void minus()
{
	printf("minus2222222222\n");
}

void multi()
{
	printf("multi3333333333\n");
}

void divide()
{
	printf("divide44444444444\n");
}

void myexit()
{
	exit(0);
}

int main(void)
{
#if 0
	char cmd[100];
	while (1)
	{
		printf("������ָ�");
		scanf("%s", cmd);

		if (strcmp(cmd, "add") == 0)
		{
			add();
		}
		else if (strcmp(cmd, "min") == 0)
		{
			minus();
		}
		else if (strcmp(cmd, "mul") == 0)
		{
			multi();
		}
		else if (strcmp(cmd, "div") == 0)
		{
			divide();
		}
		else if (strcmp(cmd, "exit") == 0)
		{
			myexit();
		}

	}
#endif

	void(*fun1)() = add;
	fun1();

	//����ָ������
	void(*fun[5])() = { add, minus, multi, divide, myexit };
	//ָ������
	char *buf[] = { "add", "min", "mul", "div", "exit" };


	char cmd[100];
	int i = 0;
	while (1)
	{
		printf("������ָ�");
		scanf("%s", cmd);

		for (i = 0; i < 5; i++)
		{
			if (strcmp(cmd, buf[i]) == 0)
			{
				fun[i]();
				break; //����for()
			}
		}

	}


	printf("\n");
	system("pause");
	return 0;
}