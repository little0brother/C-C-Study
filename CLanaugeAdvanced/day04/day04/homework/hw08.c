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
* * 功能：
*   1.把指针参数p1的字符串取出来
*   2.把二维数组buf2的字符读取出来
*   3.上面字符串放在p3,p3是在堆区分配的二维内存
*   4.对p3中字符串进行排序，通过strcmp()进行排序
* 
* * 主函数参数：
*   p1     : 指针数组首地址, char* p1[] = { "aa", "ccccccc", "bbbbbb" };
*   len1   : p1数组元素个数
*   buf2   : 二维数组首元素地址，char buf2[10][30] = { "111111", "3333333", "222222" };
*   len2   : buf2字符串的行数
*   p3     : 二级指针的地址，需要在函数内分配二维内存，保存p1和buf2的字符串，还需要排序
*   len3   : 保存p3中的字符串个数
* 
* * sort参数
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

// 申请内存空间大小固定
int sort(char** array1, int num1, char(*array2)[30], int num2, char*** myp3 /*out*/, int* num3)
{
    if (array1 == NULL || array2 == NULL || myp3 == NULL)
    {
        return -1;
    }

    int ret = 0;
    int i = 0, j = 0;
    char** tmp = NULL;
    int count = 0;

    // 直接对临时变量tmp申请内存 或者根据字符串长度申请合适的内存空间
    ret = getMem(&tmp, num1 + num2);
    if (ret != 0)
    {
        printf("(sort) getMem err: %d\n", ret);
        return ret;
    }

    // 将字符串arry1，arry2复制到 tmp 中
    for (int i = 0; i < num1; i++)
    {
        if (array1[i] != NULL)
        {
            strcpy(tmp[count++], array1[i]);
        }        
    }

    for (int i = 0; i < num2; i++)
    {
        if (array2[i] != NULL)
        {
            strcpy(tmp[count++], array2[i]);
        }
    }

    // 冒泡排序
    char* swit = NULL;
    for (int i = 0; i < num1 + num2; i++)
    {
        for (int j = i + 1; j < num1 + num2; j++)
        {
            if (strcmp(tmp[i], tmp[j]) > 0)
            {
                swit   = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = swit;
            }
        }
    }
  
    *myp3 = tmp;
    *num3 = count;

    return 0;
}

// 根据字符串长度申请合适的内存空间
int sort2(char** array1, int num1, char(*array2)[30], int num2, char*** myp3 /*out*/, int* num3)
{
    if (array1 == NULL || array2 == NULL || myp3 == NULL)
    {
        return -1;
    }

    int ret = 0;
    int i = 0, j = 0;
    char** tmp = NULL;
    int count = 0;

    tmp = (char**)malloc((num1 + num2) * sizeof(char*));

    // 根据字符串长度申请合适的内存空间
    // 将字符串arry1，arry2复制到 tmp 中
    for (int i = 0; i < num1; i++)
    {
        tmp[i] = malloc(strlen(array1[i]) + 1);     // 为末尾 '\0' 申请内存空间
        if (array1[i] != NULL)
        {
            strcpy(tmp[count++], array1[i]);
        }
    }

    for (int i = 0; i < num2; i++)
    {
        tmp[count] = malloc(strlen(array2[i]) + 1);
        if (array2[i] != NULL)
        {
            strcpy(tmp[count++], array2[i]);
        }
    }

    // 冒泡排序
    char* swit = NULL;
    for (int i = 0; i < num1 + num2; i++)
    {
        for (int j = i + 1; j < num1 + num2; j++)
        {
            if (strcmp(tmp[i], tmp[j]) > 0)
            {
                swit = tmp[i];
                tmp[i] = tmp[j];
                tmp[j] = swit;
            }
        }
    }

    *myp3 = tmp;
    *num3 = count;

    return 0;
}

int getMem(char*** buf, int n)
{
    char** tmp = NULL;
    
    tmp = (char**)malloc(n * sizeof(char*));
    if (tmp == NULL)
    {
        return -1;
    }

    for (int i = 0; i < n; i++)
    {
       tmp[i] = (char*)malloc(128 * sizeof(char));
    }

    *buf = tmp;

    return 0;
}

void freeMem(char*** p, int n)
{
    if (p == NULL)
    {
        return;
    }

    char** buf = *p;

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
}

int  main()
{
    int ret = 0;
    char* p1[] = { "aa", "ccccccc", "bbbbbb" };
    char buf2[][30] = { "111111", "3333333", "222222" };
    char** p3 = NULL;
    int len1, len2, len3, i = 0;

    len1 = sizeof(p1) / sizeof(*p1);
    len2 = sizeof(buf2) / sizeof(buf2[0]);

    // 在函数中申请内存, 在主函数中申请内存通过地址传递会导致申请的内存空间没有使用，因为在函数中会通过解引用进行地址传递
    //ret = getMem(&p3, len1 + len2);
    //if (ret != 0)
    //{
    //    printf("getMem err : %d\n", ret);
    //    return ret;
    //}

    ret = sort(p1, len1, buf2, len2, &p3, &len3);
    //ret = sort2(p1, len1, buf2, len2, &p3, &len3);
    if (ret != 0)
    {
        printf("sort err : %d\n", ret);
        return ret;
    }

    for (int i = 0; i < len3; i++)
    {
        printf("%s ", p3[i]);
    }

    // 释放p3在sort()函数中申请的内存
    freeMem(&p3, len3);

    return 0;
}