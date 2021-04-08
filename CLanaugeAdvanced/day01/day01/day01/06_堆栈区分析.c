#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 存储在栈区
char* get_str()
{
	/* 此函数运行完毕，str空间自动回收，str的空间内容未知，有可能还保存着之前的内容 有可能是乱码 */

	char str[] = "abcdefgh";	// 存放在堆栈区，因为为数组所以不存在指向关系，只有赋值关系

	return str;
}

// 存储在堆区
char* get_str2()
{
	char* temp = (char*)malloc(100);		// 申请内存空间将temp->申请的内存空间
	if (temp == NULL)
	{
		return NULL;
	}

	strcpy(temp, "adfadffda");			// 将字符串由全局区将内容复制到申请的内存空间中，并进行返回地址操作
	return temp;
}

int main(void)
{
	char buf[128] = { 0 };


	/* 内容存在栈区原理分析 */
	strcpy(buf, get_str());	  // 将get_str中的返回值赋给buf，因为get_str返回的为str数组的指针，
							  //但是str为局部临时变量，运行完毕，内存会进行释放，所以返回地址所存内容不确定
	printf("buf = %s\n");		 // 打印出来为乱码，因为get_str中的str存在堆栈区，为局部变量，运行完毕会自动释放

	char* p = NULL;				// 此过程与上述原理相同
	p = get_str();
	printf("p = %s\n", p);


	/* 内容存储在堆区原理分析 （通过malloc申请内存空间，来确保内存不会自动释放）*/
	char* q = NULL;
	q = get_str2();
	if (p != NULL)
	{
		printf("q = %s\n", q);

		free(q);			// 释放内存空间
		q = NULL;
	}


	printf("\n");
	return 0;
}