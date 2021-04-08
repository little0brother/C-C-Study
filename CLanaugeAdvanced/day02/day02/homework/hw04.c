/************************************************************************************************
*  ��ֵ�ԣ���key = value�����ַ������ڿ����о���ʹ��
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

	int main(void)
	{
		//...
		getKeyByValude("key1 =   valude1", "key1", buf, &len);
		//...

		return 0;
	}
*************************************************************************************************/

/*
* getKeyByValue();
*   ����: ������ֵ������Ӧ��ֵ
*   ����:
*		keyvaluebuf: ��ֵ��
*		keybuf     : ��Ҫ��ѯ�ļ�����
*		valuebuf   : ���ڴ�ż�����Ӧֵ���ַ���
*		valuebuflen: ������Ӧֵ���ַ����ĳ���
*   ����ֵ: 
*		�ɹ�: 0
*		ʧ��: ��0
*/

/*
* trimSpace();
	���ܻ�ȡ�ǿ��ַ���
	������
		inbuf:  ԭʼ�ַ���buf�׵�ַ
		outbuf: �ǿ��ַ���buf�׵�ַ
	����֮��
		�ɹ���0
		ʧ�ܣ���0
*/

#include <stdio.h>
#include <ctype.h>

int getKeyByValue(char* keyvaluebuf, char* keybuf, char* valuebuf, int* valuebuflen);

#if(1)
// ȥ���ǿ��ַ���
int trimSpace(char* inbuf, char* outbuf)
{
	if (inbuf == NULL || outbuf == NULL)
	{
		return -1;
	}

	char* p = inbuf;
	char* buf = outbuf;

	// �����ַ���vlaue������յ�
	int begin = 0;
	int end = strlen(inbuf) - 1;
	int n = 0;

	// ��Ϊ��ֵ���м���пո�����Ҫȥ���ո�
	while ( isspace(inbuf[begin]) && (inbuf[begin] != NULL))
	{
		begin++;
	}

	while (isspace(inbuf[end]) && end > 0)
	{
		end--;
	}

	// ����ַ���Ϊ0 ��ô�ַ���������
	if (end == 0)
	{
		return -2;
	}


	// ��¼�ַ�������
	n = end - begin + 1;

	// ���ַ���������vbuf����ͨ���βη�����������
	strncpy(outbuf, inbuf + begin, n);

	return 0;
}

// ���Ҽ����Ե�ֵ������ȥ���Ⱥ�
int getKeyByValue(char* keyvaluebuf, char* keybuf, char* valuebuf, int* valuebuflen)
{
	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)
	{
		return  -1;
	}

	char* kvbuf = keyvaluebuf;
	char* kbuf  = keybuf;
	char* vbuf  = valuebuf;


	// ���Ҽ�ֵ������ת���󷽼�������
	// kbbuf = "= value"
	// "key4 = vluue " -> " =   value "
	kvbuf = strstr(kvbuf, kbuf);
	if (kvbuf == 0)
	{
		return -2;
	}
	kvbuf += sizeof(kbuf);

	//  �鵽 = 
	// ���� = �������ò���λ��
	//  " =   value " -> "   value  "
	kvbuf = strstr(kvbuf, "=");
	if (kvbuf == 0)
	{
		return -3;
	}
	kvbuf += sizeof("=");

	// ȡ���ǿ��ַ���
	int ret = 0;
	ret = trimSpace(kvbuf, vbuf);
	if (ret != 0)
	{
		printf("trimSpace err:%d\n", ret);
		return -4;
	}

	// ��ȡ����,ͨ��*��Ӹ�ֵ
	*valuebuflen = strlen(vbuf);

	return 0;
}
#endif

int main(void)
{
	char* keyvaluebuf = "key1 =         ";
	char* key         = "key1";
	char  value[100]  = { 0 };

	int valuelen = 0;
	int ret         = 0;

	ret = getKeyByValue(keyvaluebuf, key, value, &valuelen);
	if (ret != 0)
	{
		printf("getKeyByValue err:%d\n", ret);
		return ret;
	}

	printf("val = %s\nvaluebuflen = %d\n", value, valuelen);

	printf("\n");
	return 0;
}

#if(0)
// ������������ͬ�����ų��ո��Լ���=��ʱ����ѭ���ж������
int getKeyByValue(char* keyvaluebuf, char* keybuf, char* valuebuf, int* valuebuflen)
{
	if (keyvaluebuf == NULL || keybuf == NULL || valuebuf == NULL || valuebuflen == NULL)
	{
		return  -1;
	}

	char* kvbuf = keyvaluebuf;
	char* kbuf = keybuf;
	char* vbuf = valuebuf;

	// ���Ҽ�ֵ������ת���󷽼�������
	// kbbuf = "= value"
	// "key4 = vluue " -> " =   value "
	kvbuf = strstr(kvbuf, kbuf);
	if (kvbuf == 0)
	{
		return -2;
	}
	kvbuf += sizeof(kbuf);

	// �����ַ���vlaue������յ�
	int begin = 0;
	int end = strlen(kvbuf) - 1;

	// �ո�Ҫ�õ����� '='
	// ��Ϊ��ֵ���м���пո�͵Ⱥţ�����Ҫȥ���ո�͵Ⱥ�
	while ( (isspace(kvbuf[begin]) || kvbuf[begin] == '=') && (kvbuf[begin] != NULL))
	{
		begin++;
	}

	while (isspace(kvbuf[end]) && end > 0)
	{
		end--;
	}

	// ��¼�ַ�������
	*valuebuflen = end - begin + 1;
	if (*valuebuflen <= 0)
	{
		return -5;
	}

	// ���ַ���������vbuf����ͨ���βη�����������
	strncpy(vbuf, kvbuf + begin, *valuebuflen);

	return 0;
}
#endif