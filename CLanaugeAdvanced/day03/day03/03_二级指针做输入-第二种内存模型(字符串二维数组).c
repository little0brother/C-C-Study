#include <stdio.h>

#if(0)
int main(void)
{
	char a0[30] = "2222222";
	char a1[30] = "1111111";
	char a2[30] = "bbbbbbb";
	char a3[30] = "aaaaaaa";

	// 4��a[30]��һά���飬���Ƕ�ά����
	// ÿһ��a[i]�� ����һ��һά����, ÿ�μ�һ��ת30����
	// �����ά���飬��д��һ��[]��ֵ�������Ǳ���Ҫ���г�ʼ��
	char a[4][30] = { "2222222",  "1111111", "bbbbbbb", "aaaaaaa" };
	printf("a: %d, a+1: %d\n", a, a + 1);
	// a[0] = "222222";

	// a:  ���������һ��Ԫ�صĵ�ַ�������е�ַ�������е�ַ��������Ԫ�ص�ַ�����𣬵������ǵ�ֵ��һ���ģ����𣺲�����һ����
	// &a: ������������ĵ�ַ ����ַ��һ����ת���������ַ

	// ������֤
	char b[30];
	printf("&b: %d, &b+1: %d\n", &b, &b + 1);
	printf("b: %d, b+1: %d\n", b, b + 1);

	int n = sizeof(a) / sizeof(a[0]);
	printf("n = %d\n", n);

	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", a[i]);
		printf("%s\n", *(a + i));   // ���е�ַ������Ԫ�ص�ַ��ֵ��һ����
									// a + i = *(a + i)
	}

	printf("\n");
	return 0;
}
#endif

// ��װ
#if(1)
int sort_arr(char p[][30], int n)
{
	if (p == NULL)
	{
		return -1;
	}

	char tmp[30];

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (strcmp(p[i], p[j]) > 0)
			{
				// �����ڴ������
				strcpy(tmp, p[i]);
				strcpy(p[i], p[j]);
				strcpy(p[j], tmp);
			}
		}
	}

	return 0;
}

void print_arr(char p[][30], int n)
{
	printf("p=%d, p+1=%d\n", p, p + 1);
	for (int i = 0; i < n; i++)
	{
		printf("%s ", p[i]);
	}
}

// err
void print_arr1(char **p, int n)
{
	// ������Ϊָ�����ͣ����Բ���Ϊ�ģ���ָ���������30��ͬ�����Բ���ʧ��
	printf("p=%d, p+1=%d\n", p, p + 1);
	for (int i = 0; i < n; i++)
	{
		printf("%s ", p[i]);
	}
	printf("\n");
}

int main(void)
{
	char a[][30] = { "2222222",  "1111111", "bbbbbbb", "aaaaaaa" };
	int len = 0;
	int ret = 0;

	len = sizeof(a) / sizeof(a[0]);

	printf("����ǰ��\n");
	print_arr(a, len);

	ret = sort_arr(&a, len);
	if (ret != 0)
	{
		printf("sort_arr err: %d\n", ret);
		return ret;
	}

	printf("\n\n�����\n");
	print_arr(a, len);

	printf("\n");
	return 0;
}
#endif