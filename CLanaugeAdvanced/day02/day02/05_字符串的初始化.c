#include <stdio.h>

/*
* c语言没有字符串类型，通过字符数据模拟
* C语言字符串，以字符 '\0', 数字 0 结束
*/

#if(0)
int main()
{
	// 不指定长度，没有 0 结束符，有多少个元素就有多长
	char buf[] = { 'a', 'b', 'c' };
	printf("buf=%s\n", buf);

	// 指定长度，后面没有赋值的元素自动补 0 
	char buf1[100] = { 'a', 'b', 'c' };
	printf("buf1=%s\n", buf1);

	// 所有元素赋值为 0
	char buf2[100] = { 0 };

	//char buf3[2] = { '1', '2', '3' };	// 数组越界


	// 字符‘0’，与数字0，acsii值不同，代表含义也不同
	char buf4[50] = { '1', 'a', 'b', '0', '7' };
	printf("buf4 = %s\n", buf4);

	char buf5[50] = { '1', 'a', 'b', 0, '7' };
	printf("buf5 = %s\n", buf5);

	char buf6[50] = { '1', 'a', 'b', '\0', '7' };
	printf("buf6 = %s\n", buf6);


	// 使用字符串初始化，常用
	char buf7[] = "fadfa dasfddasfdas";
	// strlen(); 测字符串长度，不包含数字0，字符'\0'
	// sizeof(); 测数组长度，包括数字0，字符'\0'
	printf("strlen = %d, sizeof = %d\n", strlen(buf7), sizeof(buf7));

	char buf8[100] = "fadfa dasfddasfdas";
	printf("strlen = %d, sizeof = %d\n", strlen(buf8), sizeof(buf8));


	printf("test:");
	// 转义字符
	char str[] = "\0129";	//  '\012'='\n'
	printf("%s\n", str);

	printf("\n");
	return 0;
}
#endif

int main()
{
	/*
	* 数组访问方式
	* 1.[]方式
	* 2.指针方式
	*/
	char buf[] = "hgdsauifasdojfd";
	int n = strlen(buf);

	// 1.[]方式
	for (int i = 0; i < n; i++)
	{
		printf("%c", buf[i]);
	}
	printf("\n");

	// 2.指针方式
	char* p = NULL;
	p = buf; // 数组名字为数组元素首地址
	for (int i = 0; i < n; i++)
	{
		printf("%c", p[i]);
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("%c", *(p + i));
	}
	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("%c", *(buf + i));
	}
	printf("\n");

	// buf和p完全等价吗？
	// p++;
	// buf++;
	// buf只是一个常量，不能修改
	
	// 数组在创建时，长度已经确认，如果shuzu可以修改，应为数组长度固定，
	// 如果修改数组，那么数组所指的地址空间就会变化，当系统自动释放内存时，会导致释放本不该释放的位置


	printf("\n");
	return 0;
}