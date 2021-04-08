/****************************/
/* 结构体与共用体函数调用入口 */
/****************************/

#include <stdio.h>

int main()
{
	// 结构体定义用法举例
	//main1();

	// 得票统计程序
	//main2();

	// 数组指针
	//main3();

	// 结构指针变量做函数的参数
	//main4();

	// 动态存储分配和链表
	//main5();

	// 共用体union
	main6();


	// 测试
	//main100();

	return 0;
}



// 注释函数段 功能:删除指定字符串的中字符
#if(0)
void scanf_str(char ch[80])
{
	gets_s(ch, 80);
}

// 删除字符串中的指定字符
void delete_ch(char ch[80], char c)
{
	int i, j;
	for (i = j = 0; ch[i] != '\0'; i++)
		if (ch[i] != c)
			ch[j++] = ch[i];

	ch[j] = '\0';
}

void printf_ch(char ch[80])
{
	printf("%s", ch);
}

int main()
{
	char str[20];
	char c;
	
	scanf_str(str);
	c = getchar();
	delete_ch(str, c);
	printf_ch(str);

	return 0;
}
#endif


#if(0)
/** 打印1-5阶乘 **/

#include <stdio.h>

int f(int a)
{
	static int f = 1;

	f = f * a;

	return f;
}

int main()
{
	int i;
	for (int i = 1; i <= 5; i++)
		printf("%d! = %d\n", i, f(i));
	
	return 0;
}
#endif