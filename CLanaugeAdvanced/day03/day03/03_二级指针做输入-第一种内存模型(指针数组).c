#include <stdio.h>

#if(1)
int main(void)
{

	// ÿ�����Ͷ���char *
	char* p0 = "111111";
	char* p1 = "000000";
	char* p2 = "bbbbbb";
	char* p3 = "aaaaaa";

	// ָ�����飬ָ������飬����һ�����飬ÿһ��Ԫ�ض���ָ��char*
	char* p[] = { "111111", "000000", "bbbbbb", "aaaaaa" };
	// p[0] = "111111";

	int n = sizeof(p) / sizeof(p[0]);
	printf("sizeof(p) = %d, sizeof(p[0]) = %d\n", sizeof(p), sizeof(p[0]));

	for (int i = 0; i < n; i++)
	{
		printf("%s\n", p[i]);
	}


	char* q[10] = { "111111", "000000", "bbbbbb", "aaaaaa" };
	printf("sizeof(q) = %d, sizeof(q[0]) = %d\n", sizeof(q), sizeof(q[0]));

	printf("\0");
	return 0;
}
#endif

// ��ָ���������ݽ�������
#if(0)
int main(void)
{
	char* p[] = { "111111", "000000", "bbbbbb", "aaaaaa" };
	char* tmp = NULL;
	int n = sizeof(p) / sizeof(p[0]);
	int i = 0;
	int j = 0;

	printf("����ǰ��\n");
	for (i = 0; i < n; i++)
	{
		printf("%s, ", p[i]);
	}
	printf("\n");

	// ѡ������
	for ( i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(p[i], p[j]) > 0)
			{
				// ������Ϊ������ַ
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

	printf("\n�����\n");
	for (i = 0; i < n; i++)
	{
		printf("%s, ", p[i]);
	}
	printf("\n");

	printf("\n");
	return 0;
}

#endif

// ��װ
#if(0)

// �����Ϊ����ָ�룬���Խ�����Ϊָ������Ԫ�صĵ�ַ
int sort_pointarr(char **p, int n)
{
	if (p == NULL)
	{
		return -1;
	}

	int i = 0;
	int j = 0;
	char* tmp = NULL;

	// ѡ������
	for (i = 0; i < n - 1; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(p[i], p[j]) > 0)
			{
				tmp = p[i];
				p[i] = p[j];
				p[j] = tmp;
			}
		}
	}

	return 0;
}

void print_array(char** p, int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%s, ", p[i]);
	}
	printf("\n");
}

int main(void)
{
	char* p[] = { "111111", "000000", "bbbbbb", "aaaaaa" };
	int n = sizeof(p) / sizeof(p[0]);
	int i = 0;
	int ret = 0;

	printf("����ǰ��\n");
	print_array(p, n);	
	for (int i = 0; i < n; i++)
	{
		printf("p[%d]=%p ", n, p[i]);
	}

	ret = sort_pointarr(p, n);
	if (ret != 0)
	{
		printf("sort_pointarr err: %d", ret);
		return ret;
	}

	printf("\n�����\n");
	print_array(p, n);
	for (int i = 0; i < n; i++)
	{
		printf("p[%d]=%p ", n, p[i]);
	}


	printf("\n");
	return 0;
}

#endif