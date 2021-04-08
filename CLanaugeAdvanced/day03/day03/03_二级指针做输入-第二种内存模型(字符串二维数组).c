#include <stdio.h>

#if(0)
int main(void)
{
	char a0[30] = "2222222";
	char a1[30] = "1111111";
	char a2[30] = "bbbbbbb";
	char a3[30] = "aaaaaaa";

	// 4个a[30]的一维数组，就是二维数组
	// 每一个a[i]中 都是一个一维数组, 每次加一跳转30长度
	// 定义二维数组，不写第一个[]的值，条件是必须要进行初始化
	char a[4][30] = { "2222222",  "1111111", "bbbbbbb", "aaaaaaa" };
	printf("a: %d, a+1: %d\n", a, a + 1);
	// a[0] = "222222";

	// a:  代表数组第一个元素的地址，（首行地址），首行地址和首行首元素地址有区别，但是他们的值是一样的（区别：步长不一样）
	// &a: 代表整个数组的地址 给地址加一，调转整个数组地址

	// 步长验证
	char b[30];
	printf("&b: %d, &b+1: %d\n", &b, &b + 1);
	printf("b: %d, b+1: %d\n", b, b + 1);

	int n = sizeof(a) / sizeof(a[0]);
	printf("n = %d\n", n);

	for (int i = 0; i < 4; i++)
	{
		printf("%s\n", a[i]);
		printf("%s\n", *(a + i));   // 首行地址和首行元素地址的值是一样的
									// a + i = *(a + i)
	}

	printf("\n");
	return 0;
}
#endif

// 封装
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
				// 交换内存块内容
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
	// 传进来为指针类型，所以步长为四，与指针参数步长30不同，所以操作失败
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

	printf("排序前：\n");
	print_arr(a, len);

	ret = sort_arr(&a, len);
	if (ret != 0)
	{
		printf("sort_arr err: %d\n", ret);
		return ret;
	}

	printf("\n\n排序后：\n");
	print_arr(a, len);

	printf("\n");
	return 0;
}
#endif