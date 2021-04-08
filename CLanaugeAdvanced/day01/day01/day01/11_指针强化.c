#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* get_mem(int size)
{
    char* p2 = NULL;            //分配4个字节的内存 栈区也叫临时区
    p2 = (char*)malloc(size);

    return p2;
}

int main(void)
{
    char buf[100];
    int a = 10;     //分配4个字节的内存 栈区也叫临时区
    int* p;         //分配4个字节的内存
    p = &a;

    *p = 20;

    char* mp = get_mem(100);
    strcpy(mp, "ABCDEFG");

    if (mp != NULL)
    {
        free(mp);		// 告诉系统，mp原来指向的内容可以被别人使用
        mp = NULL;		// 释放完，mp就是野指针，还是保存之前的地址，最好赋值为NULL
    }

    return 0;
}