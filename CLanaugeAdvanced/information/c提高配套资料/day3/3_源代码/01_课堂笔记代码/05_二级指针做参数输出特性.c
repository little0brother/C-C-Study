#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getMem(char *p)
{
	p = (char *)malloc(sizeof(char)* 100);
	if (p == NULL)
	{
		return -1;
	}
	strcpy(p, "abdakg");
	printf("p = %s\n", p);

	return 0;
}

int getMem2(char **p)
{
	if (p == NULL)
	{
		return -1;
	}

	char *tmp = (char *)malloc(100);
	if (tmp == NULL)
	{
		return -2;
	}

	strcpy(tmp, "ALGKJDLSJGLKDSJ");

	*p = tmp;

	return 0;
}

int main(void)
{
	char *p = NULL;
	int ret = 0;

	ret = getMem2(&p);
	if (ret != 0)
	{
		printf("getMem err: %d\n", ret);
		return ret;
	}

	printf("p = %s\n", p);

	if (p != NULL)
	{
		free(p);
		p = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}