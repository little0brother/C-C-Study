#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
src:    ԭ�ַ���
dst:    ���ɵĻ���Ҫ�����ַ���
sub:    ��Ҫ���ҵ����ַ���
new_sub:�ỻ�������ַ���

return : 0 �ɹ�
-1 ʧ��
*/
int replaceSubstr(/* in */char *src, /* out */char** dst,
	/* in */char *sub,  /* in */char *new_sub)
{
	// src = "22abcd11111abcd2222abcdqqqqq"
	// dst = "22dcba11111dcba2222dcbaqqqqq"

	if (src == NULL || dst == NULL || sub == NULL || new_sub == NULL)
	{
		return -1;
	}

	char tmp[512] = { 0 }; //��ʱ����, �ַ�����

	char *start = src; //��¼���ҵ����
	char *p = NULL;	//ƥ���ַ������׵�ַ

	do 
	{
		// src = "22abcd11111abcd2222abcdqqqqq"
		p = strstr(start, sub);
		if (p != NULL)
		{
			int len = p - start;
			if (len > 0)
			{
				//��ƥ���ַ���ǰ����������ӹ�ȥ
				strncat(tmp, start, len);
			}

			strncat(tmp, new_sub, strlen(new_sub)); //׷���滻���´�

			//���Ĳ��ҵ����λ��
			start = p + strlen(sub);
		}
		else
		{
			strcat(tmp, start);

			break;
		}

	} while (*start != 0 );

	char *buf = malloc(strlen(tmp) + 1);
	strcpy(buf, tmp);
	*dst = buf;
	
	return 0;
}

int main()
{
	char *p = "abcd11111abcd2222abcdqqqqq";
	int ret = 0;
	char *buf = NULL;

	ret = replaceSubstr(p, &buf, "abcd", "12345");
	if (ret != 0)
	{
		printf("replaceSubstr err:��%d\n", ret);
		return ret;
	}
	printf("buf = %s\n", buf);


	if (buf != NULL)
	{
		free(buf);
		buf = NULL;
	}

	printf("\n");
	system("pause");
	return 0;
}