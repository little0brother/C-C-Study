#include <stdio.h>

#if(0)
int main(void)
{
	char* p0 = NULL;
	p0 = (char*)malloc(100);
	strcpy(p0, "dfdadf");
	free(p0);

	// 10�� char *, ÿһ��ֵ���ǿ�
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
	// ��̬����һ�����飬ÿ��Ԫ�ض���char *
	//char *ch[10];
	int n = 10;
	// �����ڴ�ʱ ע������ÿ���ڴ��СΪָ�����ͳ���
	char** buf = (char**)malloc(n * sizeof(char*));		// =char *buf[10];
	if (buf == NULL)
	{
		return -1;
	}
	// strcpy(buf[0], "111111"); //err
	char str[30];
	for (int i = 0; i < n; i++)
	{
		// �൱�ڶ��ַ�����������ڶ���[]�ռ䳤��
		buf[i] = (char*)malloc(30 * sizeof(char));

		sprintf(str, "test%d%d", i, i);
		strcpy(buf[i], str);
	}

	for (int i = 0; i < n; i++)
	{
		printf("%s, ", buf[i]);
	}
	printf("\n");

	// �ͷſռ�ʱҪע�⣬���ͷ�Ϊbuf[i]������ڴ�ռ䣬�ͷ���Ϻ��ٶ������n�����ȵ�buf�ͷ�
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

// ��װ
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