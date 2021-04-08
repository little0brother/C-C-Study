#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
4. ��ֵ�ԣ���key = value�����ַ������ڿ����о���ʹ��
Ҫ��1�����Լ�����һ���ӿڣ�ʵ�ָ���key��ȡ.
Ҫ��2����д����������
Ҫ��3����ֵ���м������n��ո���ȥ���ո�

ע�⣺��ֵ���ַ�����ʽ�������£�
"key1 = value1"
"key2 =       value2"
"key3  = value3"
"key4        = value4"
"key5   =   "
"key6   ="

int getKeyByValue(char *keyvaluebuf,  char *keybuf,  char *valuebuf, int * valuebuflen);
*/

int trimSpace(char *inbuf, char *outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}
	
	char *p = inbuf;
	int begin = 0;
	int end = strlen(p) - 1;
	int n = 0;

	if (end < 0){
		return -2;
	}

	//���������ƶ��������ǰ�ַ�Ϊ�գ�����û�н���
	while (p[begin] == ' ' && p[begin] != 0)
	{
		begin++; //λ�ô����ƶ�һλ
	}

	//���������ƶ��������ǰ�ַ�Ϊ��
	while (p[end] == ' ' && end > 0)
	{
		end--; //�����ƶ�
	}

	if (end == 0)
	{
		return -2;
	}

	n = end - begin + 1; //�ǿ�Ԫ�ظ���

	strncpy(outbuf, p + begin, n);
	outbuf[n] = 0;

	return 0;
}

int getKeyByValue(char *keyvaluebuf, char *keybuf, char *valuebuf, int * valuebuflen)
{
	/*
	keyvaluebuf = "key4 =    value4"
	keybuf = "key4"
	*/
	if (keybuf == NULL || keyvaluebuf == NULL
		|| valuebuf == NULL || valuebuflen == NULL)
	{
		return -1;
	}
	char *p = NULL;
	int ret = 0;

	//����ƥ���ֵ
	//"key4 =    value4"��key4,�ҵ������׵�ַ
	p = strstr(keyvaluebuf, keybuf);
	if (p == NULL)
	{
		return -2;
	}

	//����ҵ��������������λ�ã�������key4��
	//p = " =    value4"
	// "key4 =    value4" ->  " =    value4"
	p = p + strlen(keybuf);

	//�鵽=
	p = strstr(p, "=");
	if (p == NULL)
	{
		return -3;
	}

	//����ҵ��������������λ�ã�������=��
	//p = "    value4"
	// " =    value4" -> "    value4"
	p = p + strlen("=");

	//ȡ�ǿ��ַ�
	ret = trimSpace(p, valuebuf);
	if (ret != 0)
	{
		printf("trimSpace err:%d\n", ret);
		return ret;
	}

	//��ȡ���ȣ�ͨ��*��Ӹ�ֵ
	*valuebuflen = strlen(valuebuf);

	return 0;
}

int main(void)
{

	char *keyVal = "key4 =           ";
	char *key = "key4";
	char value[100] = {0};
	int len = 0;
	int ret = 0;

	ret = getKeyByValue(keyVal, key, value, &len);
	if(ret != 0)
	{
		printf("getKeyByValue err :%d\n", ret);
		system("pause");
		return ret;
	}
	printf("val:%s\n", value);
	printf("len:%d\n", len);



#if 0
	char *p = "      abcddsgadsgefg      ";
	char buf[100] = { 0 };

	int ret = 0;
	ret = trimSpace(p, buf);
	if (ret != 0)
	{
		printf("trimSpace err :%d\n", ret);
		//system("pause");
		return ret;
	}

	printf("buf = %s\n", buf);
#endif

	printf("\n");
	system("pause");
	return 0;
}