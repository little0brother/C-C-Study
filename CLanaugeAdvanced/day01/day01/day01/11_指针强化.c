#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* get_mem(int size)
{
    char* p2 = NULL;            //����4���ֽڵ��ڴ� ջ��Ҳ����ʱ��
    p2 = (char*)malloc(size);

    return p2;
}

int main(void)
{
    char buf[100];
    int a = 10;     //����4���ֽڵ��ڴ� ջ��Ҳ����ʱ��
    int* p;         //����4���ֽڵ��ڴ�
    p = &a;

    *p = 20;

    char* mp = get_mem(100);
    strcpy(mp, "ABCDEFG");

    if (mp != NULL)
    {
        free(mp);		// ����ϵͳ��mpԭ��ָ������ݿ��Ա�����ʹ��
        mp = NULL;		// �ͷ��꣬mp����Ұָ�룬���Ǳ���֮ǰ�ĵ�ַ����ø�ֵΪNULL
    }

    return 0;
}