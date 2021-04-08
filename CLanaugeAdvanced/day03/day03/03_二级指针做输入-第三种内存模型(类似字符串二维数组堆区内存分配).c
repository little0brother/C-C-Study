#include <stdio.h>

#if(0)
int main(void)
{
	char* p0 = NULL;
	p0 = (char*)malloc(100);
	strcpy(p0, "dfdadf");
	free(p0);

	// 10个 char *, 每一个值都是空
	char* p[10] = { 0 };
	for (int i = 0; i < 10; i++)
	{
		p[i] = malloc(100);
		strcpy(p[i], "abcdefg");
	}
	free(p);

	int a[10];
	int* q = (int*)malloc(10 * sizeof(int));	// =q[10]
	free(q);



/********************************************************************************************/
	// 动态分配一个数组，每个元素都是char *
	//char *ch[10];
	int n = 10;
	// 申请内存时 注意申请每块内存大小为指针类型长度
	char** buf = (char**)malloc(n * sizeof(char*));		// =char *buf[10];
	if (buf == NULL)
	{
		return -1;
	}
	// strcpy(buf[0], "111111"); //err
	char str[30];
	for (int i = 0; i < n; i++)
	{
		// 相当于对字符串数组申请第二个[]空间长度
		buf[i] = (char*)malloc(30 * sizeof(char));

		sprintf(str, "test%d%d", i, i);
		strcpy(buf[i], str);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s, ", buf[i]);
	}
	printf("\n");

	// 释放空间时要注意，先释放为buf[i]申请的内存空间，释放完毕后再对申请的n个长度的buf释放
	for (int i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}
	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
/********************************************************************************************/

	printf("\n");
	return 0;
}
#endif

// 封装
#if(1)

char** getMem_buf(int n)
{
	char** buf  = (char**)malloc(n * sizeof(char*));
	if (buf == NULL)
	{
		return NULL;
	}

	char tmp[30];
	for (int i = 0; i < n; i++)
	{
		buf[i] = (char*)malloc(30 * sizeof(char));

		sprintf(tmp, "test%d%d", i, i);
		strcpy(buf[i], tmp);
	}

	return buf;
}

void print_buf(char** buf, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%s, ", buf[i]);
	}
	printf("\n");
}

void free_buf(char** buf, int n)
{
	if (buf == NULL)
	{
		return -1;
	}

	int i = 0;
	for (i = 0; i < n; i++)
	{
		free(buf[i]);
		buf[i] = NULL;
	}

	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}
}

int main(void)
{
	char** buf = NULL;
	int n = 10;

	buf = getMem_buf(n);
	if (buf == NULL)
	{
		printf("getMem_buf err:");
		return -1;
	}

	print_buf(buf, n);

	free_buf(buf, n);
	buf = NULL;

	printf("\n");
	return 0;
}
#endif