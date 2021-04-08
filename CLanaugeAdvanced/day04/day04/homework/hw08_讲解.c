// 8. 将字符串数组进行排序
/**
int sort(char** array1, int num1,
    char(*array2)[30], int num2,
    char*** myp3, int* num3);

int  main()
{
    int ret = 0;
    char* p1[] = { "aa", "ccccccc", "bbbbbb" };
    char buf2[10][30] = { "111111", "3333333", "222222" };
    char** p3 = NULL;
    int len1, len2, len3, i = 0;

    len1 = sizeof(p1) / sizeof(*p1);
    len2 = sizeof(buf2) / sizeof(buf2[0]);

    ret = sort(p1, len1, buf2, len2, &p3, &len3);

    return 0;
}
*/

/**
* 功能：
*   1.把指针参数p1的字符串取出来
*   2.把二维数组buf2的字符读取出来
*   3.上面字符串放在p3,p3是在堆区分配的二维内存
*   4.对p3中字符串进行排序，通过strcmp()进行排序
* 
* 参数：
*   p1     : 指针数组首地址, char* p1[] = { "aa", "ccccccc", "bbbbbb" };
*   len1   : p1数组元素个数
*   buf2   : 二维数组首元素地址，char buf2[10][30] = { "111111", "3333333", "222222" };
*   len2   : buf2字符串的行数
*   p3     : 二级指针的地址，需要在函数内分配二维内存，保存p1和buf2的字符串，还需要排序
*   len3   : 保存p3中的字符串个数
* 
*   array1 : 二级指针，第一个需要拼接排序字符串
*   num1   : array1子字符串个数
*   array2 : 数组指针，第二个需要拼接排序字符串
*   num2   : array2子字符串个数
*   myp3   : 用于存储排序后字符串
*   num3   : 排序后子字符串个数
*
*   return :
*       0  : 成功
*     非0  : 失败
*/

#include <stdio.h>
#include <string.h>

int sort(char** array1, int num1, char(*array2)[30], int num2, char*** myp3, int* num3)
{
    if (array1 == NULL || array2 == NULL || myp3 == NULL)
    {
        return -1;
    }

    // 打造一个指针数组，char* tmp[num1 + num2]
    char** tmp = (char**)malloc(sizeof(char*) * (num1 + num2));
    if (tmp == NULL)
    {
        return -2;
    }

    // char *array1[] = { "aa", "ccccccc", "bbbbbb" };
    // char (*array2)[30] = { "111111", "3333333", "222222" };
    // 给每个指针分配内存(指向堆区）
    for (int i = 0; i < num1; i++)
    {
        tmp[i] = (char*)malloc(sizeof(char) * (strlen(array1[i]) + 1)); // 为 '\0' 多申请一个字节的内存空间
        strcpy(tmp[i], array1[i]);
    }

    // 初始条件从num1开始（重要），还有一个变量j
    for (int i = num1, j = 0; i < num1 + num2; i++, j++)
    {
        //array2[j]不是i
        tmp[i] = (char*)malloc(sizeof(char) * (strlen(array2[j]) + 1));
        strcpy(tmp[i], array2[j]);
    }

    // 排序
    int n = num1 + num2;
    char* p = NULL;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(tmp[i], tmp[j]) > 0)     // 升序
            {
                // 交换指针指向
                p = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = p;
            }
        }
    }

    // 间接赋值是指针存在最大意义
    *myp3 = tmp;
    *num3 = num1 + num2;

    return 0;
}

void free_buf(char*** buf, int len)
{
    if (buf == NULL)
    {
        return;
    }

    char** tmp = *buf;
    for (int i = 0; i < len; i++)
    {
        if (tmp[i] != NULL)
        {
            free(tmp[i]);
            tmp[i] = NULL;
        }
    }

    if (tmp != NULL)
    {
        free(tmp);
        *buf = NULL;
    }
}

int main()
{
    int ret = 0;
    char* p1[] = { "aa", "ccccccc", "bbbbbb" };
    char buf2[10][30] = { "111111", "3333333", "222222" };
    char** p3 = NULL;
    int len1, len2, len3, i = 0;

    len1 = sizeof(p1) / sizeof(*p1);
    len2 = sizeof(buf2) / sizeof(buf2[0]);

    ret = sort(p1, len1, buf2, len2, &p3, &len3);
    if (ret != 0)
    {
        printf("sort err : %d\n", ret);
        return ret;
    }

    // 排序前
    for (int i = 0; i < len1; i++)
    {
        printf("%s ", p1[i]);
    }
    for (int i = 0; i < len2; i++)
    {
        printf("%s ", buf2[i]);
    }
    printf("\n");

    // 排序后
    for (int i = 0; i < len3; i++)
    {
        printf("%s ", p3[i]);
    }
    printf("\n");

    // 释放p3所指向内存
    // 在函数内把p3的值赋值为NULL
    free_buf(&p3, len3);

	return 0;
}