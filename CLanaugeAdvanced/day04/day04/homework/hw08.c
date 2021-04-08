// 8. ���ַ��������������
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
* * ���ܣ�
*   1.��ָ�����p1���ַ���ȡ����
*   2.�Ѷ�ά����buf2���ַ���ȡ����
*   3.�����ַ�������p3,p3���ڶ�������Ķ�ά�ڴ�
*   4.��p3���ַ�����������ͨ��strcmp()��������
* 
* * ������������
*   p1     : ָ�������׵�ַ, char* p1[] = { "aa", "ccccccc", "bbbbbb" };
*   len1   : p1����Ԫ�ظ���
*   buf2   : ��ά������Ԫ�ص�ַ��char buf2[10][30] = { "111111", "3333333", "222222" };
*   len2   : buf2�ַ���������
*   p3     : ����ָ��ĵ�ַ����Ҫ�ں����ڷ����ά�ڴ棬����p1��buf2���ַ���������Ҫ����
*   len3   : ����p3�е��ַ�������
* 
* * sort����
*   array1 : ����ָ�룬��һ����Ҫƴ�������ַ���
*   num1   : array1���ַ�������
*   array2 : ����ָ�룬�ڶ�����Ҫƴ�������ַ���
*   num2   : array2���ַ�������
*   myp3   : ���ڴ洢������ַ���
*   num3   : ��������ַ�������
* 
*   return :
*       0  : �ɹ�
*     ��0  : ʧ��
*/

#include <stdio.h>
#include <string.h>

// �����ڴ�ռ��С�̶�
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

    // ֱ�Ӷ���ʱ����tmp�����ڴ� ���߸����ַ�������������ʵ��ڴ�ռ�
    ret = getMem(&tmp, num1 + num2);
    if (ret != 0)
    {
        printf("(sort) getMem err: %d\n", ret);
        return ret;
    }

    // ���ַ���arry1��arry2���Ƶ� tmp ��
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

    // ð������
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

// �����ַ�������������ʵ��ڴ�ռ�
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

    // �����ַ�������������ʵ��ڴ�ռ�
    // ���ַ���arry1��arry2���Ƶ� tmp ��
    for (int i = 0; i < num1; i++)
    {
        tmp[i] = malloc(strlen(array1[i]) + 1);     // Ϊĩβ '\0' �����ڴ�ռ�
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

    // ð������
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

    // �ں����������ڴ�, ���������������ڴ�ͨ����ַ���ݻᵼ��������ڴ�ռ�û��ʹ�ã���Ϊ�ں����л�ͨ�������ý��е�ַ����
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

    // �ͷ�p3��sort()������������ڴ�
    freeMem(&p3, len3);

    return 0;
}